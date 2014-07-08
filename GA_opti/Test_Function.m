
clc 
clear all





arm   = [2, 1, 2; 1, 1, 1 ]; 

thata = [0, 120, 240];


%  function [ po ] = fn_trilateration(arm, thata)
%       รับอินพุทเป็น ตำแหน่งจุดศูนย์กลาง และรัศมีของทรงกลม 3 ลูกเเพื่อ
%       หาจุดตัดกัน
%   Detailed explanation goes here


for n=1:3
    
    r_max(n)     = arm(1,n)+ arm(2,n) ;
    origin(n,:) = [r_max(n) *cosd(thata(n)); r_max(n) *sind(thata(n)); 0];
      
end

l1=r_max(1) ;
l2=r_max(2) ;
l3=r_max(3) ;
p1=origin(1,:) ; 
p2=origin(2,:) ;
p3=origin(3,:) ;

a1 = p1-p1 
a2 = p2-p1 
a3 = p3-p1 


thata1=-atand(a2(3)/a2(1)) ;
Ro1=[   cosd(thata1)    0   sind(thata1) ;...
        0               1   0 ;...
        -sind(thata1)   0   cosd(thata1) ] ;

a1 = a1*Ro1 
a2 = a2*Ro1 
a3 = a3*Ro1 

thata2=atand(a2(2)/a2(1)) ;
Ro2=[   cosd(thata2)    -sind(thata2)   0 ;...
        sind(thata2)    cosd(thata2)    0 ;...
        0               0               1 ] ;

a1 = a1*Ro2 
a2 = a2*Ro2 
a3 = a3*Ro2 

thata3=atand(a3(3)/a3(2)) ;
Ro3=[   1   0               0 ;...
        0   cosd(thata3)    -sind(thata3) ;...
        0   sind(thata3)    cosd(thata3) ] ;

a1 = a1*Ro3 
a2 = a2*Ro3 
a3 = a3*Ro3 


x = (l1^2-l2^2+a2(1)^2)/(2*a2(1)) ;

y = (l1^2-l3^2+a3(1)^2+a3(2)^2)/(2*a3(2)) - (a3(1))/(a3(2))* x ;

z = (l1^2-x^2-y^2)^0.5 ;

intersect = [x y z]*Ro3'*Ro2'*Ro1'+ p1 ;

po = intersect'








% end

























% clc ;
% clear all ;
% xxx = [];
% yyy = [];
% 
% %% Test function
% % sizes of   arms =    [ l11  l21  l31 ]   1 lower with eff
% %                      [ l12  l22  l32 ]   2 upper with motor
% ss ;
% 
% l11 =    10        ;
% l12 =    20         ;
% 
% l21 =    10        ;
% l22 =    20         ;
% 
% l31 =    10       ;
% l32 =    20         ;
% 
% % memory in Matrix form
% arm = [l11, l21, l31; l12, l22, l32 ]; 
% %%/////////////////////////////////////////////////////////////////////
% 
% i=1;
% ss ;
% 
% index_z = 1 ;
% 
%     for z= 0 : 1 :10
%        
%        
%     syms y ;
%         
%     l1 = 10;
%     l2 = 20 ; 
%     
%     a = -((l2 + l1)^2-z^2)^0.5    ;
%     b = -((l2 - l1)^2-z^2)^0.5    ;
%    
%         index = 1 ;
%         for xx          = 0 : 1 : 180
%             
%             x  =(a+b)/2 + (a-b)/2*cosd(xx);
%             
%                 if (xx == 0) || (xx == 180)
%                    
%                     ys(index)   = 0        ;
%                     xs(index)   = x        ;
%                     
%                 else
% 
%                     ss          = solve(l1^4 - 2*l1^2*l2^2 + l2^4 + x^4 - 2*l1^2*y^2 + ...
%                                 2*l2^2*y^2 + y^4 - 2*l1^2*z^2 - 2*l2^2*z^2 + 2*y^2*z^2 +...
%                                 z^4 + x^2*(-2*l1^2 - 2*l2^2 + 2*y^2 + 2*z^2) == 0 ,'real',true )  ;
%                     ss          = vpa(ss,4); 
%                     ss          = sort(ss,1,'descend');
% 
%                     ys(index)   = ss(1)  ;
%                     xs(index)   = x      ;
%                   
%                 end
%             index = index + 1 ;
%         end
% 
%         ys = [ -(fliplr(ys)) ys] ;
%         xs = [   fliplr(xs)  xs] ;
%         
%         parfor (n = 1 : 1 : 362)
%         	zs(n) = z   ; 
%         end
% 
%         xs = double(xs)   ;
%         ys = double(ys)   ;
%         zs = double(zs)   ;
% 
%         
%         
% 
%         
%         zzz(index_z,:) = zs  ;
%         index_z = index_z+1  ;
%  
%         clear zs ys xs ;
%         
%         plot_matrix(xxx,yyy,zzz)
%     end
%     
% 
% 
% %% End