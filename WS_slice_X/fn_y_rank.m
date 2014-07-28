function [ y_rank ] = fn_y_rank( r,thata,l1,l2 )
% find y rank before find x rank for slice along z-y plane 
% thata angle of ecilce
% r radias of base
% 1 lower with eff
% 2 upper with motor
%% move thata into 0 - 360

while (thata >= 360)
  thata = thata- 360 ; 
end

%% find y rank
    origin = [r *cosd(thata);r*sind(thata)];
    if thata == 0 || thata == 180
        y_rank = [origin(2)-(l1) , origin(2)+(l1)];
    else
        y_rank = [origin(2)-(l1*sign(sind(thata))+l2*sind(thata)) , origin(2)+(l1*sign(sind(thata))+l2*sind(thata))];
    end
end

