%% This script is used for read the waypoint from QGC generated plan.
% read plan from file
fileID = fopen('/home/ken/Documents/xxxx.plan');
C = textscan(fileID, '%s','Delimiter',',');
co = 0;
for i = 1:size(C{1},1)
if (C{1}{i} == num2str(0))
co = co +1;
end
end
numOfWaypoint = co/3 +1;
LLA = zeros(3,numOfWaypoint-1);
for i = 1:numOfWaypoint-1
LLA(1,i) = str2double(C{1}{29+(i-1)*19})*pi/180;
LLA(2,i) = str2double(C{1}{30+(i-1)*19})*pi/180;
LLA(3,i) = str2double(C{1}{31+(i-1)*19});
end