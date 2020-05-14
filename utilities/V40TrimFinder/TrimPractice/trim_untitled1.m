clc;
clear all;
%% Another model
Href = 10;
a = 2;
A = 20;
b = 5;
mdl2 = 'watertank2';
open_system(mdl2);
opspec = operspec(mdl2)

% The transfer function G = 1/(S+1), The system is X = X' + u, u is we want to know.
opspec.States(1).SteadyState = 1; % X' = 0
opspec.States(1).Known = 1;% X is knowm
opspec.States(1).x = 20;% X = 10

op = findop(mdl2,opspec);