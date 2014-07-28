% test case3 in z slice Title
% Summary of example objective

clear all
clc

% Determine workspace of Delta Robot by Gossilin's method
% define Paramiter of Delta Robot 
% defind size of base & end-effect(e_eff) **base >= e_eff**


base  =      30  ;
e_eff =      0   ;

r = base-e_eff   ;


% sizes of   arms =    [ l11  l21  l31 ]   1 lower with eff
%                      [ l12  l22  l32 ]   2 upper with motor

l11 =    40         ;
l12 =    30         ;

l21 =    40         ;
l22 =    30         ;

l31 =    40         ;
l32 =    30         ;

% angle of Actuator Counter Clockwise
thata1 =    0      ;
thata2 =    120    ;
thata3 =    240    ;

% for thata3 = 120 : 30 : 240

% memory in Matrix form

arm   = [l11, l21, l31; l12, l22, l32 ] ; 

thata = [thata1, thata2, thata3]        ;

%% fine maximum hight point of workspaces

intersec_point = fn_trilateration(arm, thata, r) ;
max_z = intersec_point(3) ;
zstep_size=(max_z)/15;  %% define resolution



i =1 ;
z =0 ;

[ xs, ys, xm, ym ] = fn_case3_z_lessthan_l1minusl2 (arm, z, i)