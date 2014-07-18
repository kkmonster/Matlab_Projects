function [ x_rank ] = fn_x_rank( thata,l1,l2 )
%find x rank for slice along z-y plane 
%1 lower with eff
% 2 upper with motor
%% degree 2 radian 

thata = thata*pi/180 ;

%% find step of discontinus fn
thata_step = atan2(abs(l2),abs(l1));

%% mapping thata into 0 to 90 degree
while thata > pi/2
  thata = thata- pi/2 ; 
end

%%
if   thata == 0
    
    x = l1 + l2 ;

elseif thata < thata_step 
    
    beta = asin(l2/l1*sin(thata));
    gramma = pi - thata - beta ;
    x = l1 / sin(thata) * sin(gramma) ;

else
    
    x = l2 / sin(thata);   

end

x_rank = x ;

end

