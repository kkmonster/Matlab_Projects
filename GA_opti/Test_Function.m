clc ;
clear all ;
xxx = [];
yyy = [];

%% Test function
% sizes of   arms =    [ l11  l21  l31 ]   1 lower with eff
%                      [ l12  l22  l32 ]   2 upper with motor
ss ;

l11 =    10        ;
l12 =    20         ;

l21 =    10        ;
l22 =    20         ;

l31 =    10       ;
l32 =    20         ;

% memory in Matrix form
arm = [l11, l21, l31; l12, l22, l32 ]; 
%%/////////////////////////////////////////////////////////////////////

i=1;
ss ;

index_z = 1 ;

    for z= 0 : 1 :10
       
       
    syms y ;
        
    l1 = 10;
    l2 = 20 ; 
    
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
                xs(index)   = x        ;
                  
                end
            index = index + 1 ;
        end

        
        
        
        ys = [ -(fliplr(ys)) ys] ;
        xs = [   fliplr(xs)  xs] ;

          ys = double(ys)   ;
          xs = double(xs)	;

        xxx(index_z,:)=xs ;
        yyy(index_z,:)=ys ;
        
        
        for (n = 1 : 1 : 362)
           zs(n) = z   ; 
        end
        
        zzz(index_z,:) = zs  ;
        index_z = index_z+1  ;
 
        clear zs ys xs ;
        
        plot_matrix(xxx,yyy,zzz)
    end
    


%% End