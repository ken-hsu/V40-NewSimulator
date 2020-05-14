close all
set(0, 'DefaultAxesFontSize', 12, 'DefaultAxesFontWeight','demi')
set(0, 'DefaultTextFontSize', 12, 'DefaultTextFontWeight','demi')
set(0,'DefaultAxesFontName','arial')
set(0,'DefaultAxesFontSize',12)
set(0,'DefaultTextFontName','arial')
set(gcf,'DefaultLineLineWidth',2);
set(gcf,'DefaultlineMarkerSize',10)
global k1 k2 eqp
%%
% ft = 14;
% x0 = [-1 2]/10;
% k1=1;
% k2=0;
% [T,x]=ode23('plant', [0 20], x0); % linear
% k2=-2;
% [T1,x1]=ode23('plant', [0 20], x0);%nonlinear
% figure(1);clf;
% subplot(211)
% plot(T,x(:,1),T1,x1(:,1),'-');
% legend('Linear','Nonlinear')
% ylabel('X','FontSize',ft)
% xlabel('Time','FontSize',ft)
% subplot(212)
% plot(T,x(:,2),T1,x1(:,2),'-');
% legend('Linear','Nonlinear')
% ylabel('V','FontSize',ft)
% xlabel('Time','FontSize',ft)
% text(4,0.3,['k 2=',num2str(k2)],'FontSize',ft)
% % nlplant(14)
% print -f1 -dpng -r300 nlplant.png
%%
k1=-1;k2=0.5;
% call plant.m
x0 = [sqrt(-k1/k2) 0]; % [y y_dot]
[T,x]=ode23('plant',[0:0.001:30], x0);
% figure(1);
% subplot(211);
% plot(T,x(:,1));ylabel('y');xlabel('Time');grid
% subplot(212);
% plot(T,x(:,2));ylabel('dy/dt');xlabel('Time');grid
% figure(2);plot(x(:,1),x(:,2));grid
% hold on;plot(x0(1),0,'rx','MarkerSize',20);hold off;
% xlabel('y');ylabel('dy/dt')
% axis([1.2 1.7 -0.25 .25]);axis('square')

eqp = x0(1);
[T2,x2]=ode23('sys2',[0:0.001:30], x0);
plot(T,x(:,2),'*')
hold on;
plot(T,x2(:,2),'o')