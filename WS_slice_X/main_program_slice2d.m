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

% angle of Actuator Counter Clockwise from x axis
 
thata1 =    75     ;
thata2 =    120    ;
thata3 =    240    ;

% for thata3 = 120 : 30 : 240
% memory in Matrix form

arm   = [l11, l21, l31; l12, l22, l32 ] ; 

thatas = [thata1, thata2, thata3]        ;

%% 1st arm
thata = thata1 ;
l1 = l11;
l2 = l12;

%% find y rank 

y_limmit = fn_y_rank( r,thata,l1,l1 )
y_limmit_min = y_limmit(1)
y_limmit_max = y_limmit(2)

for y_data = y_limmit_min : (y_limmit_max-y_limmit_min)/15 :y_limmit_max
    %% find x rank
    x_limmit = fn_x_rank( y_data,r,thata,l1,l2 )
    x_limmit_min = x_limmit(1)
    x_limmit_max = x_limmit(2)
    
    
    index_1=1;
    index_2=1;
    for x_data = x_limmit_min :(x_limmit_max-x_limmit_min)/15:x_limmit_max
        x_data
        y_data
        z_data = fn_solve( l1, l2, x_data, y_data, r, thata )

        zs(index_1)   = z_data(1)    
       	xs(index_1)   = x_data      ;
        index_1 = index_1 + 1 ;
        
        if (size(z_data) == [4,1])
            zm(index_2) = z_data(2)	
            xm(index_2) = x_data ;
           	index_2 = index_2 + 1 ;
        end
    end
end
intersec_point = fn_trilateration(arm, thata, r) ;
max_z = intersec_point(3) ;
zstep_size=(max_z)/15;  %% define resolution



i =1 ;
z =0 ;

[ xs, ys, xm, ym ] = fn_case3_z_lessthan_l1minusl2 (arm, z, i)