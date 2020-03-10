% author ken NY
clear;
clc;

load('V40_CFD.mat')

rho = 1.213;        % 1.293 Kg/m3
g = 9.80665;          % m/s2
dt = 0.0025;

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

lat0 = 30.811101;
lon0 = 121.355226;
h0 = 200.0;
%舵面时常
t_dea = 0.02;
t_dca = 0.02;
t_dr  = 0.02;
%% 6DoF方程初始参数
Vair0 = 25;         % m/s

alpha0 =4.5/180*pi;  % rad
beta0 = 0;          % rad

x0 = 0;             % m
y0 = 0;             % m
z0 = -h0;          % m


thrust_trim = 45.0;
d_ca_trim = 2.7;
u0 = Vair0*cos(beta0)*cos(alpha0);             % m/s
v0 = Vair0*sin(beta0);                          % m/s
w0 = Vair0*cos(beta0)*sin(alpha0);             % m/s

roll0 = 0;           % rad
pitch0 = alpha0;    % rad
yaw0 = 0;           % rad

p0 = 0;             % rad/s
q0 = 0;             % rad/s
r0 = 0;             % rad/s


R2D = 180.0/pi;
D2R = 1.0/R2D;

%% define TECS parameters
hgt_error_gain = 0.05;
hgt_gain_ff= 0.15;
speed_error_gain = 0.02;


max_climb_rate = 2.5;%允许最大爬升速度
min_sink_rate  = 2.0;%允许下降速度
max_sink_rate = 5.0;%允许最大下降速度

throttle_time_constant =5.0;
throttle_cruise = 0.65;%巡航油门
THR_Ki = 0.1;
THR_Kd = 0.5; 

pitch_speed_weight = 1.0;
SKE_weighting = pitch_speed_weight;
SPE_weighting = 2.0 - SKE_weighting;
Pitch_Ki = 0.1;
Pitch_Kd = 0;
pitch_time_constant = 3.5;

STE_rate_max = max_climb_rate*g;
STE_rate_min = -min_sink_rate*g;

STE_to_throttle = 1.0/(throttle_time_constant * (STE_rate_max - STE_rate_min));

pitch_sp_limit = 25.0*D2R;
%% define FW_ATT_Ctrl parameters
%roll
FW_R_TC = 0.4;
FW_R_RMAX = 70*D2R;   % rad/s

FW_RR_FF = 0.6;
FW_RR_P = 0.7;
FW_RR_I = 0.01;
FW_RR_IMAX = 0.2;
%pitch
FW_P_TC = 0.45;      % s
FW_P_RMAX_POS = 60*D2R;   % rad/s

FW_PR_FF = 0.4;
FW_PR_P = 2.2;
FW_PR_I = 0.5;
FW_PR_IMAX = 0.4;%积分器限幅
% K_ff = 1.7;
% K_p = 0.7;
% K_i = 0.05;
%yaw
FW_YR_FF = 0.3;
FW_YR_P = 0.05;
FW_YR_I = 0.00;
FW_YR_IMAX = 0.2;
%% define L1 parameters
% CONSTANTS_ONE_G = 9.80665;
D2R = pi/180.0;
FW_L1_DAMPING = 0.8;
FW_L1_PERIOD = 25.0;
L1_ratio = 1.0/pi*FW_L1_DAMPING*FW_L1_PERIOD;
K_L1 = 4.0*FW_L1_DAMPING*FW_L1_DAMPING;
roll_lim_rad = 30.0*D2R;