clear all
clc



% Determine workspace of Delta Robot by Gossilin's method
% define Paramiter of Delta Robot 
% defind size of base & end-effect(e_eff) **base >= e_eff**
base  =      50  ;
e_eff =      0   ;

r = base-e_eff   ;


% sizes of   arms =    [ l11  l21  l31 ]   1 lower with eff
%                      [ l12  l22  l32 ]   2 upper with motor
l11 =    40         ;
l12 =    50         ;

l21 =    40         ;
l22 =    50         ;

l31 =    40         ;
l32 =    50         ;

% angle of Actuator Counter Clockwise
thata1 =    0      ;
thata2 =    120    ;
thata3 =    240    ;

% for thata3=120 :30:240

% memory in Matrix form
arm = [l11, l21, l31; l12, l22, l32 ]; 
thata = [thata1, thata2, thata3];

%%
% define rank of height : z 
for i = 1 : 3

    zRank(i) = ((arm(2,i) + arm(1,i))^2-r^2)^0.5;
    
 end    
 
zstep_size=(min(zRank))/20;  %% define resolution

%%


indexz = 1 ;
for z = 0 : zstep_size : min(zRank) 

indexz    
    
i=1;
if arm(1,i) > arm(2,i)
   if z <= (arm(1,i) - arm(2,i))
       [xs, ys] = fn_case3_z_lessthan_l1minusl2 (arm, z, i);
   else
       [xs, ys] = fn_case4_z_morethan_l1minusl2 (arm, z, i);
   end    
else
   if z <= (arm(2,i) - arm(1,i))
       [xs, ys] = fn_case1_z_lessthan_l2minusl1 (arm, z, i);
   else
       [xs, ys] = fn_case2_z_morethan_l2minusl1 (arm, z, i);
   end
end

ellip1 = [ xs; ys ]   ;
%%

i=2;
if arm(1,i) > arm(2,i)
   if z <= (arm(1,i) - arm(2,i))
       [xs, ys] = fn_case3_z_lessthan_l1minusl2 (arm, z, i);
   else
       [xs, ys] = fn_case4_z_morethan_l1minusl2 (arm, z, i);
   end    
else
   if z <= (arm(2,i) - arm(1,i))
       [xs, ys] = fn_case1_z_lessthan_l2minusl1 (arm, z, i);
   else
       [xs, ys] = fn_case2_z_morethan_l2minusl1 (arm, z, i);
   end
end

ellip2 = [ xs; ys ]   ;
%%

i=3;
if arm(1,i) > arm(2,i)
   if z <= (arm(1,i) - arm(2,i))
       [xs, ys] = fn_case3_z_lessthan_l1minusl2 (arm, z, i);
   else
       [xs, ys] = fn_case4_z_morethan_l1minusl2 (arm, z, i);
   end    
else
   if z <= (arm(2,i) - arm(1,i))
       [xs, ys] = fn_case1_z_lessthan_l2minusl1 (arm, z, i);
   else
       [xs, ys] = fn_case2_z_morethan_l2minusl1 (arm, z, i);
   end
end

ellip3 = [ xs; ys ]   ;
%%



%% Shift the origin ellip1 ellip2 & ellip3

ss = size(ellip1);
parfor i=1 : ss(2)    
ellip1(:,i) = ellip1(:,i) + [r ; 0] ;
end

ss = size(ellip2);
parfor i=1 : ss(2)    
ellip2(:,i) = ellip2(:,i) + [r ; 0] ;
end

ss = size(ellip3);
parfor i=1 : ss(2)    
ellip3(:,i) = ellip3(:,i) + [r ; 0] ;    
end

  
%% rotate ellip1 ellip2 & ellip3 to thata1 thata2 & thata3 
ss = size(ellip1);
R1=[cosd(thata1) -sind(thata1) ; sind(thata1) cosd(thata1) ];
parfor i=1 : ss(2)    
ellip1(:,i) = R1 * ellip1(:,i) ;
end

ss = size(ellip2);
R2=[cosd(thata2) -sind(thata2) ; sind(thata2) cosd(thata2) ];
parfor i=1 : ss(2)    
ellip2(:,i) = R2 * ellip2(:,i) ;
end

ss = size(ellip3);
R3=[cosd(thata3) -sind(thata3) ; sind(thata3) cosd(thata3) ];
parfor i=1 : ss(2)    
ellip3(:,i) = R3 * ellip3(:,i) ;    
end


%% Intersection & area

  [xin, yin] = polybool('intersection', ellip1(1,:),  ellip1(2,:),  ellip2(1,:), ellip2(2,:)) ;
  [xin, yin] = polybool('intersection', xin, yin,  ellip3(1,:), ellip3(2,:)) ;

  area  = polyarea(xin, yin) ;
  
  %% split matrix if have NaN number
  
  if isnan(area)
  aa = find((isnan(xin)));
  ss = size(xin) ;
  aa = [0 aa (ss(2)+1)];
  ss = size(aa) ;
  for k = 1:1:(ss(2)-1)
      area(k) = polyarea(xin((aa(k)+1):(aa(k+1)-1)), yin(:,(aa(k)+1):(aa(k+1)-1))) ;
  end
  area=sum(area) ;
  end
  ss = size(xin) ;
  if ss(2)>0
    for index = 1: 1 : ss(2)
    zin(index) = z ;
    end
  else
      zin = [];
  end
  
 
  
%% show datas

figure(1)
 axis equal, hold on
% plot3(x1, y1, z1, ':c')
% plot3(x2, y2, z2, ':m')
% plot3(x3, y3, z3, ':g')
% 
%   if (arm(1,1) > arm(2,1))&&(z < (arm(1,1) - arm(2,1)))
%   plot3(xx1, yy1, zz1, ':c')    
%   end
%   
%   if (arm(1,2) > arm(2,2))&&(z < (arm(1,2) - arm(2,2)))
%   plot3(xx2, yy2, zz2, ':m')      
%   end
%     
%   if (arm(1,3) > arm(2,3))&&(z < (arm(1,3) - arm(2,3)))
%   plot3(xx3, yy3, zz3, ':g')        
%   end


plot3(xin, yin, zin, 'b')


if area > 0
    
else 
    area=0;
end

sumarea(indexz) = area;

indexz = indexz + 1 ;





%% Reset data 


clear ellip1 ellip2 ellip3 xin yin zin ...
      x1 x2 x3 y1 y2 y3 z1 z2 z3 ...
      xx1 xx2 xx3 yy1 yy2 yy3 zz1 zz2 zz3;
end
%% save data
volume = sum(sumarea)*zstep_size 

