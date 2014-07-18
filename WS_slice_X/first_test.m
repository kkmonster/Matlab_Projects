   clear all ;
   clc
   
   
    syms x_real_frame  ;
        
    l1 = 1
    l2 = 1

    thata1 = 75 ; 
    r = 1 ;

    y_real_frame  = 0.5   ;
    x0_real_frame = 0   ;  % radian of base
    z             = 0   ;

    
%% find edge of x in real frame
    
    a = x0_real_frame
    b = fn_x_rank(thata1,l1,l2)  % delta
    
    clear x_real_frame
   
%% find z 
clear zs xs z ss
syms z 
zs = [];
xs = [];
     index_1 = 1 ;
     index_2 = 1 ;
     for xx          = 0 : 1 : 180
         
         x_real_frame  =  a + b*cosd(xx)   ;
         
         % trans....   axis    
         x_arm_frame = ((x_real_frame - x0_real_frame)*cosd(thata1) - y_real_frame*sind(thata1));
         y_arm_frame = ((x_real_frame - x0_real_frame)*sind(thata1) + y_real_frame*cosd(thata1));
            
            
            
            
%                 if (xx == 0) || (xx == 180)
%                    
%                     zs(:,index_1)   = [0]        ;
%                     xs(index_1)   = x_real_frame        ;
%                     
%                 else

                    ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x_arm_frame^4 - 2*l1^2*y_arm_frame^2 + ...
                                2*l2^2*y_arm_frame^2 + y_arm_frame^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y_arm_frame^2*z^2 +...
                                z^4 + x_arm_frame^2*(-2*l1^2 - 2*l2^2 + 2*y_arm_frame^2 + 2*z^2) == 0 ,'real',true )  ;
                            
                    ss          = vpa(ss,4); 
                    
                    ss          = sort(ss,1,'descend');
                    ss          = double(ss)      ;
                    
                    if ((size(ss) > [2  1])*[1; 0])
                   
                        zs_minus(index_2) = ss(2)        ;
                        xs_minus(index_2) = x_real_frame ;
                        index_2 = index_2 + 1 ;
                    end

                    zs(index_1)   = ss(1)    ;
                    xs(index_1)   = x_real_frame      ;
                    
%                 end
            index_1 = index_1 + 1 ;
     end
        xs = [   fliplr(xs)  xs] ;
        ys(1:362) = y_real_frame ;
        zs = [ -(fliplr(zs)) zs] ;
        
        xs_minus = [   fliplr(xs_minus)  xs_minus ] ;
        ys(1:size(xs_minus)) = y_real_frame ;
        zs_minus = [ -(fliplr(zs_minus)) zs_minus ] ;



