function  [dx] = sys2(t, x)
global k1 k2 eqp
    A = [0 1;-k1-3*k2*(eqp)^2 0];
    dx = A*x;
end