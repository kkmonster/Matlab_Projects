   clear all ;
   clc
   
   
    syms x_real_frame  ;
        
    l1 = 1
    l2 = 1

    thata1 = 45 ; 
    

    y_real_frame  = 0   ;
    x0_real_frame = 0   ;
    z             = 0   ;

    
%% find edge of x in real frame
    syms x_real_frame ;

	ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + ((x_real_frame - x0_real_frame)*cosd(thata1) - y_real_frame*sind(thata1))^4 - 2*l1^2*((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1))^2 + ...
                        2*l2^2*((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1))^2 + ((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1))^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1))^2*z^2 +...
                        z^4 + ((x_real_frame - x0_real_frame)*cosd(thata1) - y_real_frame*sind(thata1))^2*(-2*l1^2 - 2*l2^2 + 2*((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1))^2 + 2*z^2) == 0 ,'real',true )  
    
    ss = double(ss);
    
    a = (max(ss)+ min(ss))/2  % mean
    b = (max(ss)- min(ss))/2  % delta
    
    clear x_real_frame
   
%% find z 
syms z

     index = 1 ;
     for xx          = 0 : 1 : 180
         
         x_real_frame  =  a + b*cosd(xx)   ;
         
         % trans....   axis    
         x_arm_frame = ((x_real_frame - x0_real_frame)*cosd(thata1) - y_real_frame*sind(thata1));
         y_arm_frame = ((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1));
            
            
            
            
                if (xx == 0) || (xx == 180)
                   
                    zs(index)   = 0        ;
                    xs(index)   = x_real_frame        ;
                    
                else

                    ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x_arm_frame^4 - 2*l1^2*y_arm_frame^2 + ...
                                2*l2^2*y_arm_frame^2 + y_arm_frame^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y_arm_frame^2*z^2 +...
                                z^4 + x_arm_frame^2*(-2*l1^2 - 2*l2^2 + 2*y_arm_frame^2 + 2*z^2) == 0 ,'real',true )  ;
                            
                    ss          = vpa(ss,4); 
                    ss          = sort(ss,1,'descend')

                    zs(index)   = double(ss(1))     ;
                    xs(index)   = x_real_frame      ;
                    
                end
            index = index + 1 ;
     end
        xs = [   fliplr(xs)  xs] ;
        ys(1:362) = y_real_frame ;
        zs = [ -(fliplr(zs)) zs] ;
        
        



