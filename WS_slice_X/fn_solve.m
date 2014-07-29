function [ ss ] = fn_solve( l1, l2, x_real_frame, y_real_frame, r, thata )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
        clear z
        syms z
        x_arm_frame = ((x_real_frame - r)*cosd(thata) - y_real_frame*sind(thata));

        y_arm_frame = ((x_real_frame - r)*sind(thata) + y_real_frame*cosd(thata));

       	ss          =   solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x_arm_frame^4 - 2*l1^2*y_arm_frame^2 + ...
                        2*l2^2*y_arm_frame^2 + y_arm_frame^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y_arm_frame^2*z^2 +...
                        z^4 + x_arm_frame^2*(-2*l1^2 - 2*l2^2 + 2*y_arm_frame^2 + 2*z^2) == 0 ,'real',true )  ;
                            
      	ss          = vpa(ss,4)             ; 
      	ss          = sort(ss,1,'descend')  ;
        ss          = double(ss)            ;
        
        if size(ss) == [0 0]
            ss = [0 0]
        end
end

