% Instance UAV means define (assign) the start up situation including:
% 1. UAV location
% 2. waypoint

%% 1. UAV location
lat0 = 30.811101;
lon0 = 121.355226;
h0 = 200.0;

x0 = 0;             % m
y0 = 0;             % m
z0 = -h0;          % m
%% 2. waypoint
sim('V40.slx')