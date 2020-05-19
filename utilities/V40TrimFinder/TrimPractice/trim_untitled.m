mdl = 'untitled';
open_system(mdl);
u0 = 10;
w0 = 0;
vair0 = sqrt(u0^2 + w0^2);
pitchTheta0 = 1;
alpha0 = atan2(w0,u0);
in1 = 0.996;
in2 = -11;
in3 = 0;
z0 = -200;
opspec = operspec(mdl)

opspec.States(1).Known = [0; 1];
opspec.States(1).SteadyState = [0; 1];
opspec.States(1).x = [0; z0];

% phi theta psi: phi_dot, theta_dot, psi_dot = 0. But we want to know the
% equilibrium point of theta.
% opspec.States(2).Known = 1;
opspec.States(2).SteadyState = 1; % no rotation
% opspec.States(2).x = pitch0;

%ub,vb,wb: ub_dot vb_dot wb_dot = 0. we want to know ub.
opspec.States(3).Known = [1; 1];
opspec.States(3).SteadyState = [1; 1];
opspec.States(3).x = [22; 2];

%pqr: p_dot q_dot r_dot = 0. pqr = 0
% opspec.States(4).Known = [1; 1; 1];
opspec.States(4).SteadyState = 1;
% opspec.States(4).x = [0; 0; 0];


%% input
%Fx
opspec.Inputs(1).Known = 0;
opspec.Inputs(1).Max = 20;
opspec.Inputs(1).Min = -20;
% opspec.Inputs(1).Known = 1;
% opspec.Inputs(1).u = 0;

%Fz
% opspec.Inputs(2).Known = 0;
opspec.Inputs(2).Max = 40;
opspec.Inputs(2).Min = -40;
% opspec.Inputs(2).Known = 1;
% opspec.Inputs(2).u = 9.81;


% opt = findopOptions('DisplayReport',true);

[op,opreport] = findop(mdl,opspec);

u0 = 22;
w0 = 2;
vair0 = sqrt(u0^2 + w0^2);
pitchTheta0 = 0.0907;
alpha0 = atan2(w0,u0);
in1 = 0.996;
in2 = -11;
in3 = 0;
%%
A = [  0        0        0        1
 -10.95        0        0       -2
 -0.9963        0        0       22
       0        0        0        0];
B =  [ 0             0             0
1             0             0
 0             1             0
 0             0             1];
C =[1       0       0       0
0       0       0       1
0       1       0       0
 0       0       1       0];
D = zeros(4,3);