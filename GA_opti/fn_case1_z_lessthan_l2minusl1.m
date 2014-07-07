function [ xs, ys, zs] = fn_case1_z_lessthan_l2minusl1 (arm, z, i)
% Summary of this function goes here
%   Detailed explanation goes here
%%
    syms y ;
        
    l1 = arm(1,i) ;
    l2 = arm(2,i) ; 
    
    a = -((l2 + l1)^2-z^2)^0.5    ;
    b = -((l2 - l1)^2-z^2)^0.5    ;
   
            index = 1 ;
        for xx          = 0 : 1 : 180
            
            x  =(a+b)/2 + (a-b)/2*cosd(xx);
            
                if (xx == 0) || (xx == 180)
                   
                    ys(index)   = 0        ;
                    xs(index)   = x        ;
                    
                else

                    ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x^4 - 2*l1^2*y^2 + ...
                                2*l2^2*y^2 + y^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y^2*z^2 +...
                                z^4 + x^2*(-2*l1^2 - 2*l2^2 + 2*y^2 + 2*z^2) == 0 ,'real',true )  ;
                    ss          = vpa(ss,4); 
                    ss          = sort(ss,1,'descend');

                    ys(index)   = ss(1)  ;
                    xs(index)   = x      ;
                  
                end
            index = index + 1 ;
        end

        ys = [ -(fliplr(ys)) ys] ;
        xs = [   fliplr(xs)  xs] ;
        
        for (n = 1 : 1 : 362)
        	zs(n) = z   ; 
        end

        xs = double(xs)   ;
        ys = double(ys)   ;
        zs = double(zs)   ;
    
%         index = 1   ;
%         for xx          = 0 : 1 : 180
%             x           =(a+b)/2 + (a-b)/2*cosd(xx);
%             ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x^4 - 2*l1^2*y^2 + ...
%                         2*l2^2*y^2 + y^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y^2*z^2 +...
%                         z^4 + x^2*(-2*l1^2 - 2*l2^2 + 2*y^2 + 2*z^2) == 0 ,'real',true )  ;
%             ss          = vpa(ss,4); 
%             ss          = sort(ss,1,'descend');
%             if size(ss)== 1
%             ys(index)   = ss(1,1)    ;
%             xs(index)   = x        ;
%             end
%             
%             index = index + 1 ;
%         end
% 
%         ys = [ -(fliplr(ys)) ys] ;
%         xs = [   fliplr(xs)  xs] ;
% 
%           ys = double(ys)   ;
%           xs = double(xs)	;
end

