
function [xdot] = plant(t,x)
% plant.m
global k1 k2

xdot(1) = x(2);

xdot(2) = -k1*x(1)-k2*(x(1))^3;

xdot = xdot';
