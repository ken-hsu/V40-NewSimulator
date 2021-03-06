%   A = 
%              Theta   U,w(1)   U,w(2)        q
%    Theta         0        0        0        1
%    U,w(1)   -9.797        0        0   -1.307
%    U,w(2)  -0.5134        0        0    24.93
%    q             0        0        0        0
A = [ 0        0        0        1
 -9.787        0        0   -1.233
-0.5103        0        0    26.15
        0        0        0        0];
     % d_ca  V40AeroDynam
   B = [ 0         0
-0.01156         0.025
 -0.03931         0
 0.3226         0];
C = [1       0       0       0
       0       0       0       1
       0       1       0       0
     0       0       1       0];
 D = zeros(size(C,1),2);
 
 
 x0 = 0;
 z0 = -200;
 pitchTheta0 = 0.0521;
 u0 = 26.152;
 w0 = 1.231;
 Vair0 = sqrt(u0^2 + w0^2);
 alpha0 = 0.0471;
 q0 = 0;
 Thrust = 39.9;
