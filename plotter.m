clear all
close all

Array=dlmread('output.csv');
t = Array(:, 1);
x = Array(:, 2);
u = Array(:, 3);
v = Array(:, 4);

Array2=dlmread('input.txt')
N = Array2(2)

figure(1) %graph of u against x
title('u against t');
plot (t(1:N:end),u(1:N:end), 'r'); hold on; %take every Nth element, starting from the first
plot (t(11:N:end),u(11:N:end), 'g'); hold on; % same as above, except starting from the eleventh
plot (t(21:N:end),u(21:N:end), 'b'); hold on;
plot (t(31:N:end),u(31:N:end), 'm'); hold on;
plot (t(41:N:end),u(41:N:end), 'y'); hold on;

legend('t = 0.6','t = 1.1','t = 1.5','t = 2.00','t = 2.5');


figure(2) %graph of u against x
title('v against t');
plot (t(1:N:end),v(1:N:end), 'r'); hold on; %take every Nth element, starting from the first
plot (t(11:N:end),v(11:N:end), 'g'); hold on; % same as above, except starting from the eleventh
plot (t(21:N:end),v(21:N:end), 'b'); hold on;
plot (t(31:N:end),v(31:N:end), 'm'); hold on;
plot (t(41:N:end),v(41:N:end), 'y'); hold on;

legend('t = 0.6','t = 1.1','t = 1.5','t = 2.00','t = 2.5');

%figure(2) %graph of u against t
%title('u');
%plot (t(1:40:end), u(1:40:end), 'r'); hold on;
%plot (t(11:40:end),u(11:40:end), 'g'); hold on;
%plot (t(21:40:end),u(21:40:end), 'b'); hold on;
%plot (t(31:40:end),u(31:40:end), 'm'); hold on;

%legend('x=0','x=1.28','x=2.56','x=3.84');

%{

figure (3) % Animate line
fig = animatedline;
set(gca,'XLim', [0 5])
legend('u(x)');
for k = 1:20
    clearpoints(fig)
    tvec = t(1:20);
    uvec = u(1+20*k:20+20*k);
    addpoints(fig,tvec,uvec);
    drawnow limitrate
    pause(0.1);
end

figure (4) % Animate line
fig = animatedline;
set(gca,'XLim', [0 5])
legend('v(x)');
for k = 1:20
    clearpoints(fig)
    tvec = t(1:20);
    vvec = v(1+20*k:20+20*k);
    addpoints(fig,tvec,vvec);
    drawnow limitrate
    pause(0.1);
end

disp('End of script')

%}