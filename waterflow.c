clear all;
close all;
clc;

%% Motor

J = 4.1284E-6; % roph adraneias
b = 2.6077E-6; % stathera tribhs kinhthra
K = 0.02; % stathera
% allazontas tis times R,L mporoume na allaksoume thn statherothta tou
% susthmatos
R = 4; % hlektrikh antistash
L = 3.2E-3; % phnio
s = tf('s');
Tf_Motor = K/(s*((J*s+b)*(L*s+R)+K^2)) % sunarthsh metaforas Motor
t = 0:0.001:0.2; % ana xrono 't' pernoume mia timh gia thn dhmiourgia tou diagrammatos
sys_cl = feedback(Tf_Motor,1);
step(sys_cl,t,'r')

%% Water Tank

bV = 0.001; %eisodos nerou
out = 0.01; %eksodos nerou
r = 0.15;
% h stathera 'r' orizei to poso grgora h arga tha ginei h eksomalinsei tou shmatos
A = pi*r^2; % embadon bashs deksamenhs
Tf_water_tank = tf([0,out],[1,(bV/A)]) % sunarthsh metaforas Water Tank

%% Total system model response

OpenLoop = Tf_water_tank * Tf_Motor
ClosedLoop = feedback(OpenLoop, K)
figure
step(ClosedLoop,'g')
