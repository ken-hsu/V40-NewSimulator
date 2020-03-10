clear varibales
close all
clc

load('V40_CFD.mat')

rho = 1.213;        % 1.293 Kg/m3
g = 9.79;           % m/s2
%% 飞机参数
mass0 = 45;           % Kg
% Ix = 10.1154;       % kg*m2 v24数据
% Iy = 6.9543;        % kg*m2
% Iz = 10.7149;       % kg*m2
% Ixz = 0;            % kg*m2
Iv = [13.1154, 0, 0; 0, 9.9543, 0; 0, 0, 15.7149];
x_CG = 1.38-0.043;%1.232; %质心位置（距头部）压心位置1.38
y_CG = 0;
z_CG = 0;
%% 6DoF方程初始参数
Vair0 = 27;         % m/s

alpha0 =0.0/180*pi;  % rad
beta0 = 0;          % rad

x0 = 0;             % m
y0 = 0;             % m
z0 = -200;          % m

u0 = Vair0*cos(beta0)*cos(alpha0);             % m/s
v0 = Vair0*sin(beta0);                          % m/s
w0 = Vair0*cos(beta0)*sin(alpha0);             % m/s

roll0 = 0;           % rad
pitch0 = 0.0/180*pi;    % rad
yaw0 = 0;           % rad

p0 = 0;             % rad/s
q0 = 0;             % rad/s
r0 = 0;             % rad/s
%% 载入模型 查看状态量信息
mdl = 'V40AeroDynamics';
open_system(mdl);
opspec = operspec(mdl)

% roll0,pitch0,yaw0
opspec.States(1).Known = [0; 0; 0];
opspec.States(1).SteadyState = [0; 0; 0];
opspec.States(1).x = [roll0;pitch0;yaw0];
%pqr
opspec.States(2).Known = [0; 0; 0];
opspec.States(2).SteadyState = [1; 1; 1];
opspec.States(2).x = [0; 0; 0];
%uvw
opspec.States(3).Known = [0; 0; 0];
opspec.States(3).SteadyState = [0; 1; 1];
opspec.States(3).x = [u0; v0; w0];
% opspec.States(3).min = [20; -10; -10.0];
%xe ye ze
opspec.States(4).Known = [0; 0; 0];
opspec.States(4).SteadyState = [0; 0; 0];
opspec.States(4).x = [x0; y0; z0];

% inputs
opspec.Inputs(1).Known = 1; %dea 副翼
opspec.Inputs(1).u = 0;

opspec.Inputs(2).Known = 0;%dca 鸭翼
opspec.Inputs(2).u = 0.5;

opspec.Inputs(3).Known = 1;%dr 方向舵
opspec.Inputs(3).u = 0;

opspec.Inputs(4).Known = 0;%Thrust 推浆
opspec.Inputs(4).u = 30;


op = findop(mdl,opspec);