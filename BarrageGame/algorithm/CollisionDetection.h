#pragma once
#include <math.h>
double Distance(double x1, double y1, double x2, double y2);
bool RsPointOnCircle(int px, int py, int cx,int cy ,int cr);
bool RsPointOnRectangle(int px, int py, int lx, int ly, int width, int height);
bool RsLineOnCircle(int px1, int py1, int px2, int py2, int cx, int cy, int cr);
bool RsRectangleOnCircle(int lx, int ly,int width,int height, int cx, int cy, int cr);
//bool RsPointOnRectangle(int x1, int y1, int lx, int ly, int width, int height);