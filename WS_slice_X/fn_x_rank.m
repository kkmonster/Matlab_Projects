function [ x_rank ] = fn_x_rank( y,r,thata,l1,l2 )
% clc 
% clear all

% y= 0
% r= 0
% thata=270
% l1= 1
% l2= 1

% find x rank for slice along z-y plane 
% y distant along y axis from origin to origin
% r radias of base
% 1 lower with eff
% 2 upper with motor

%% move thata into 0 - 360
while (thata >= 360)
  thata = thata- 360 ; 
end

%% find origin of motor

% 1st circle (near(0,0))
x_origin_1 = (r-l2)*cosd(thata);
y_origin_1 = (r-l2)*sind(thata);

% 2nd circle (far(0,0))
x_origin_2 = (r+l2)*cosd(thata);
y_origin_2 = (r+l2)*sind(thata);

%% equation & bounary
% 1st circle
% l1^2-(x1-x_origin_1)^2-(y1-y_origin_1)^2 == 0

% 2nd circle
% l1^2-(x2-x_origin_2)^2-(y2-y_origin_2)^2 == 0

% 1st ramp
% x2-y*tand(thata)+l1/sind(thata) == 0
% (r-l2)*cosd(thata)-l1*sind(thata)
% (r+l2)*cosd(thata)-l1*sind(thata)

% 2nd ramp
% x2-y*tand(thata)-l1/sind(thata) == 0  
% (r-l2)*cosd(thata)+l1*sind(thata)
% (r+l2)*cosd(thata)+l1*sind(thata)


%% find x for each equation
clear x_circle_1 x_circle_2 x_ramp_1 x_ramp_2
syms  xc1 xc2 xr1 xr2

% 1st circle
    x_circle_1 = solve(l1^2-(xc1-x_origin_1)^2-(y-y_origin_1)^2 == 0,'real',true ) ;
    x_circle_1 = double(x_circle_1); % convert
% 2nd circle
    x_circle_2 = solve(l1^2-(xc2-x_origin_2)^2-(y-y_origin_2)^2 == 0,'real',true ) ;
    x_circle_2 = double(x_circle_2); % convert

if thata == 0 || thata == 180
    x_ramp_1 = NaN ;
    x_ramp_limit_min_1 = NaN ;
    x_ramp_limit_max_1 = NaN ;
    
    x_ramp_2 = NaN ;
    x_ramp_limit_min_2 = NaN ;
    x_ramp_limit_max_2 = NaN ;
     
elseif thata == 90 || thata == 270
    x_ramp_1 = solve(xr1+l1 == 0,'real',true ) ;
    x_ramp_limit_min_1 = x_ramp_1 ;
    x_ramp_limit_max_1 = x_ramp_1 ;
    
    x_ramp_2 = solve(xr2-l1 == 0,'real',true ) ;
    x_ramp_limit_min_2 = x_ramp_2 ;
    x_ramp_limit_max_2 = x_ramp_2 ;
    
else
    x_ramp_1 = solve(xr1-y*tand(thata)+l1/sind(thata) == 0,'real',true ) ;
    x_ramp_limit_min_1 = x_origin_1 - l1*sind(thata) ;
    x_ramp_limit_max_1 = x_origin_2 - l1*sind(thata) ;
   
    x_ramp_2 = solve(xr2-y*tand(thata)-l1/sind(thata) == 0,'real',true ); 
    x_ramp_limit_min_2 = x_origin_1 + l1*sind(thata) ;
    x_ramp_limit_max_2 = x_origin_2 + l1*sind(thata) ;
    
end    
    
% 1st ramp
    x_ramp_1 = double(x_ramp_1) ; % convert
    
% 2nd ramp
    x_ramp_2 = double(x_ramp_2) ; % convert


%% compare the conditions
    
    sum_circle = [x_circle_1'  x_circle_2'];
    x_limit_1  = min(sum_circle)  ;
    x_limit_2  = max(sum_circle)  ;
    
    if (thata ~= 90 && thata ~= 270 )          % condition depending on y axis

        if (x_ramp_1 >= x_ramp_limit_min_1)&&(x_ramp_1 <= x_ramp_limit_max_1)
            x_limit_1 = x_ramp_1 ;
        end

        if (x_ramp_2 >= x_ramp_limit_min_2)&&(x_ramp_2 <= x_ramp_limit_max_2)
            x_limit_2 = x_ramp_2 ;
        end   
    
    else 
        
       	if (abs(y) >= y_origin_1*sind(thata))&&(abs(y) <= y_origin_2*sind(thata))
        x_limit_1 = x_ramp_1 ;
        x_limit_2 = x_ramp_2 ;
        
        end   
    
    end    
    
  x_rank = [ x_limit_1 x_limit_2];
  
  if size(x_rank) == [0,0] 
      x_rank = [0, 0]
    
  end

end

