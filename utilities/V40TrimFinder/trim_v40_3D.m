clear all
clear varibales
close all
% clc

load('V40_CFD.mat')

rho = 1.213;        % 1.293 Kg/m3
g = 9.79;           % m/s2
%% 飞机参数
mass0 = 43;           % Kg
% Ix = 10.1154;       % kg*m2 v24数据
% Iy = 6.9543;        % kg*m2
% Iz = 10.7149;       % kg*m2
% Ixz = 0;            % kg*m2
Iv = [13.1154, 0, 0; 0, 9.9543, 0; 0, 0, 15.7149];
% x_CG = 1.38-0.043;%1.232; %质心位置（距头部）压心位置1.38
x_CG = 1.38-0.043;%1.232; %质心位置（距头部）压心位置1.38

y_CG = 0;
z_CG = 0;
%% 6DoF方程初始参数
% There are 3 frames, wind frame, NED(inertia) frame, and body frame.
% Related airspeed in wind frame x
Vair0 = 25; % m/s

% angle of attack and side slip angle. Note beta is negative rotation along
% body z axis. Body frame compare to the wind frame
alpha0 =3/180*pi;   % rad
beta0 = 0/180*pi;   % rad

% NED position
x0 = 0;             % m
y0 = 0;             % m
z0 = -200;          % m

% ground speed in body. Calculate in 2 ways
Vg = eul2rotm([-beta0,alpha0,0])'*[Vair0 0 0]';
u0 = Vg(1);
v0 = Vg(2);
w0 = Vg(3);
% u0 = Vair0*cos(beta0)*cos(alpha0);             % m/s
% v0 = Vair0*sin(beta0);                          % m/s
% w0 = Vair0*cos(beta0)*sin(alpha0);             % m/s

% Euler angle. Body frame compare to the NED frame
roll0 = 0;           % rad
pitch0 = alpha0;% 4/180*pi;    % rad
yaw0 = 0;           % rad

% angular velocity. The rotation of the body frame refer to the NED frame
% and transform(project) to the body frame.
p0 = 0;             % rad/s
q0 = 0;             % rad/s
r0 = 0;             % rad/s
Thrust = 64.7;
simuInput = 35.7;
%% 载入模型 查看状态量信息
mdl = 'V40AeroDynamics_edit_3D';
open_system(mdl);
opspec = operspec(mdl)
%% F = 0 T = 0 configuration
%xe ye ze
% opspec.States(1).Known = [1; 1];
opspec.States(1).SteadyState = [0; 0];
% opspec.States(1).x = [x0; z0];

% phi theta psi: phi_dot, theta_dot, psi_dot = 0. But we want to know the
% equilibrium point of theta.
% opspec.States(2).Known = 1;
opspec.States(2).SteadyState = 1; % no rotation
% opspec.States(2).x = pitch0;

%ub,vb,wb: ub_dot vb_dot wb_dot = 0. we want to know ub.
opspec.States(3).Known = [1; 1];
opspec.States(3).SteadyState = [1; 1];
opspec.States(3).x = [u0; w0];

%pqr: p_dot q_dot r_dot = 0. pqr = 0
% opspec.States(4).Known = [1; 1; 1];
opspec.States(4).SteadyState = 1;
% opspec.States(4).x = [0; 0; 0];


%% input
%dea 副翼
% opspec.Inputs(1).Known = 1;
% opspec.Inputs(1).u = 0;

%dca 鸭翼
% opspec.Inputs(2).Known = 1;
% opspec.Inputs(2).u = -0.6;

%dr 方向舵
% opspec.Inputs(3).Known = 1;
% opspec.Inputs(3).u = 0;

%Thrust 推浆
% opspec.Inputs(4).Known = 1;
% opspec.Inputs(4).Max = 45;


op = findop(mdl,opspec);