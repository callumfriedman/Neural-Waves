clear all
close all

Array=dlmread('output.csv');
t = Array(:, 1);
x = Array(:, 2);
y = Array(:, 3);
u = Array(:, 4);

figure(1) %graph of y against t
title('y against t');
plot (t(1:40:end),y(1:40:end), 'r'); hold on; %take every 40th element, starting from the first
plot (t(11:40:end),y(11:40:end), 'g'); hold on; % same as above, except starting from the eleventh
plot (t(21:40:end),y(21:40:end), 'b'); hold on;
plot (t(31:40:end),y(31:40:end), 'm'); hold on;

legend('x=0','x=1.28','x=2.56','x=3.84');

figure(2) %graph of u against t
title('u');
plot (t(1:40:end), u(1:40:end), 'r'); hold on;
plot (t(11:40:end),u(11:40:end), 'g'); hold on;
plot (t(21:40:end),u(21:40:end), 'b'); hold on;
plot (t(31:40:end),u(31:40:end), 'm'); hold on;

legend('x=0','x=1.28','x=2.56','x=3.84');

figure (3) % Animate line
fig = animatedline;
set(gca,'XLim', [0 5])
legend('y(x)');
for k = 1:40
    clearpoints(fig)
    xvec = x(1:40);
    yvec = y(1+40*k:40+40*k);
    addpoints(fig,xvec,yvec);
    drawnow limitrate
    pause(0.5);
end

figure (4) % Animate line
fig = animatedline;
set(gca,'XLim', [0 5])
legend('u(x)');
for k = 1:40
    clearpoints(fig)
    xvec = x(1:40);
    yvec = u(1+40*k:40+40*k);
    addpoints(fig,xvec,yvec);
    drawnow limitrate
    pause(0.5);
end

disp('End of script')