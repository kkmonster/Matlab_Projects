function [ xs, ys, xm, ym ] = fn_case3_z_lessthan_l1minusl2 (arm, z, i)
% Summary of this function goes here
% Detailed explanation goes here
%%
    clear y ;
    syms y ;
    
    l1 = arm(1,i) ;
    l2 = arm(2,i) ; 
    
    a = -((l1+l2)^2-z^2)^0.5    ;
    b = 0   ;

            index1 = 1 ;
            index2 = 1 ;
        for xx          = 0 : 1 : 180
            
            x  =    a*cosd(xx) ;
            
                if (xx == 0) || (xx == 180)
                   
                    ys(index1)   = 0        ;
                    xs(index1)   = x        ;
                    
                else

                    ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x^4 - 2*l1^2*y^2 + ...
                                2*l2^2*y^2 + y^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y^2*z^2 +...
                                z^4 + x^2*(-2*l1^2 - 2*l2^2 + 2*y^2 + 2*z^2) == 0 ,'real',true )  ;
                    ss          = vpa(ss,4); 
                    ss          = sort(ss,1,'descend');

                    ys(index1)   = ss(1)  ;
                    xs(index1)   = x      ;
                                      
                    siz = size(ss);
                    siz = siz(1) ;
                    
                    if  (siz > 2)
                        
                        ym(index2) = ss(2)  ;
                        xm(index2) = x      ;
                        index2 = index2 + 1 ;
                    end
                end
            index1 = index1 + 1 ;
        end

        ym = [ym -(fliplr(ym))];
        xm = [xm  (fliplr(xm))];
        
        ys = [ ys -(fliplr(ys))] ;
        xs = [ xs  (fliplr(xs))] ;
        


        xs = double(xs)     ;
        ys = double(ys)     ;
        xm = double(xm)     ;
        ym = double(ym)     ;

        [xs, ys] = polybool('subtraction',xs ,ys ,xm ,ym );
end
