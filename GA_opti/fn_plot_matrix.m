function [] = fn_plot_matrix( xp, yp ,zp )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
index=size(xp) ;
index = index(1);
while index 

    plot3(xp(index,:),yp(index,:),zp(index,:))
    axis equal;
    hold on;
    index = index-1;
    
end

