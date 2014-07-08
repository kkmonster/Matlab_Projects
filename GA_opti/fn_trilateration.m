function [ po ] = fn_trilateration(arm, thata ,r)
%       รับอินพุทเป็น ตำแหน่งจุดศูนย์กลาง และรัศมีของทรงกลม 3 ลูกเเพื่อ
%       หาจุดตัดกัน
%   Detailed explanation goes here


for n=1:3
    
    r_max(n)     = arm(1,n)+ arm(2,n) ;
    origin(n,:) = [r *cosd(thata(n));r*sind(thata(n)); 0];
      
end

l1=r_max(1) ;
l2=r_max(2) ;
l3=r_max(3) ;
p1=origin(1,:) ; 
p2=origin(2,:) ;
p3=origin(3,:) ;

a1 = p1-p1 ;
a2 = p2-p1 ;
a3 = p3-p1 ;


thata1=-atand(a2(3)/a2(1)) ;
Ro1=[   cosd(thata1)    0   sind(thata1) ;...
        0               1   0 ;...
        -sind(thata1)   0   cosd(thata1) ] ;

a1 = a1*Ro1 ;
a2 = a2*Ro1 ;
a3 = a3*Ro1 ;

thata2=atand(a2(2)/a2(1)) ;
Ro2=[   cosd(thata2)    -sind(thata2)   0 ;...
        sind(thata2)    cosd(thata2)    0 ;...
        0               0               1 ] ;

a1 = a1*Ro2 ;
a2 = a2*Ro2 ;
a3 = a3*Ro2 ;

thata3=atand(a3(3)/a3(2)) ;
Ro3=[   1   0               0 ;...
        0   cosd(thata3)    -sind(thata3) ;...
        0   sind(thata3)    cosd(thata3) ] ;

a1 = a1*Ro3 ;
a2 = a2*Ro3 ;
a3 = a3*Ro3 ;


x = (l1^2-l2^2+a2(1)^2)/(2*a2(1)) ;

y = (l1^2-l3^2+a3(1)^2+a3(2)^2)/(2*a3(2)) - (a3(1))/(a3(2))* x ;

z = (l1^2-x^2-y^2)^0.5 ;

intersect = [x y z]*Ro3'*Ro2'*Ro1'+ p1 ;

po = intersect';
end

