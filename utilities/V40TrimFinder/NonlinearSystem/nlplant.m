function test=nlplant(ft)
global k1 k2
x0 = [-1 2]/10;
k1=1;
k2=0;
[T,x]=ode23('plant', [0 20], x0); % linear
k2=-2;
[T1,x1]=ode23('plant', [0 20], x0);%nonlinear
figure(1);clf;
subplot(211)
plot(T,x(:,1),T1,x1(:,1),'-');
legend('Linear','Nonlinear')
ylabel('X','FontSize',ft)
xlabel('Time','FontSize',ft)
subplot(212)
plot(T,x(:,2),T1,x1(:,2),'-');
legend('Linear','Nonlinear')
ylabel('V','FontSize',ft)
xlabel('Time','FontSize',ft)
text(4,0.3,['k 2=',num2str(k2)],'FontSize',ft)
return


