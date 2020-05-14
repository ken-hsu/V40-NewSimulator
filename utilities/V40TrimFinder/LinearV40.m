%   A = 
%              Theta   U,w(1)   U,w(2)        q
%    Theta         0        0        0        1
%    U,w(1)   -9.797        0        0   -1.307
%    U,w(2)  -0.5134        0        0    24.93
%    q             0        0        0        0
A = [   0        0        0        1
    -9.772        0   0.3323   -1.308
    -0.8573  -0.3323        0    24.97
    0        0        0        0];
     % d_ca  V40AeroDynam
B =     [0             0
        -0.009639       0.02326
        -0.02856             0
        0.2563             0];
C = [1       0       0       0
       0       0       0       1
       0       1       0       0
     0       0       1       0];
 D = zeros(size(C,1),2);
 
 x0 = 0.0261;
 z0 = -200;
 alpha0 = 0.217;
 u0 = 25;
 w0 = 1.31;
 q0 = -4.95e-23;
 Thrust = 154;
 simuInput = 35.7;