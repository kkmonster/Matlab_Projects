function [ xs, ys] = fn_case3_z_lessthan_l1minusl2 (arm, z, i)
% Summary of this function goes here
%   Detailed explanation goes here
%%
    syms y ;
    
    l1 = arm(1,i) ;
    l2 = arm(2,i) ; 
    
    a = -((l1+l2)^2-z^2)^0.5    ;
    b = 0   ;

        index = 1   ;
    	index_2 = 1 ;
        for xx          = 0 : 1 : 90         
            x           = a*cosd(xx) ;
            ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x^4 - 2*l1^2*y^2 + ...
                        2*l2^2*y^2 + y^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y^2*z^2 +...
                        z^4 + x^2*(-2*l1^2 - 2*l2^2 + 2*y^2 + 2*z^2) == 0, 'Real', true )  ;
            ss          = vpa(ss,4);  
            ss          = sort(ss,1,'descend');
            y1(index)   = ss(1);
            x1(index)   = x  ;

                if ss(2) > 0
                    y2(index_2)   = ss(2) ;
                    x2(index_2)   = x     ;
                    index_2     = index_2 + 1 ;
                end
            
            index = index + 1 ;
            
        end
        

          ys = [y1  fliplr(y2) -y2 -fliplr(y1)] ;
          xs = [x1  fliplr(x2)  x2  fliplr(x1)] ;  

          ys = double(ys)   ;
          xs = double(xs)	;
end

