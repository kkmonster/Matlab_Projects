
    syms z ;
        
    l1 = arm(1,i) ;
    l2 = arm(2,i) ; 
    
    a = -((l2 + l1)^2-z^2)^0.5    ;
    b = -((l2 - l1)^2-z^2)^0.5    ;
%% find la
   

   
   
            index = 1 ;
        for xx          = 0 : 1 : 180
            
         
         % trans....   axis    
         x_arm_frame = (x_real_frame - x0_real_flame)*cosd(thata1) - y_real_frame*sind(thata1);
         r_arm_frame = (x_real_frame - x0_real_flame)*sind(thata1) + y_real_frame*cosd(thata1);
            
            
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
        


        xs = double(xs)   ;
        ys = double(ys)   ;

