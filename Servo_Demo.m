%% Initialization
clc
clear
close all

%% Solving the q_1,q_2,q_3

%% Arduino code
if ~isempty(instrfind)
    fclose(instrfind);
    delete(instrfind);
end
a = arduino('/dev/ttyS99', 'Uno')

%%
for i=1:4
    eval(['s',num2str(i),'= servo(a,[''D',num2str(i+1),''']);'])
end

%%

for i = 1:4
    eval(['s = s',num2str(i),';']);
    p = readPosition(s)
    writePosition(s, 0.5);
end

t=0;
dt= 0.01;
traj = 0;
while(1)
    traj = 0.5*sin(5*t)+0.5;
    for i = 1:4
        eval(['s = s',num2str(i),';']);
        p = readPosition(s)
        writePosition(s, traj);
    end
    t = t + dt;
    pause(0.01);
end