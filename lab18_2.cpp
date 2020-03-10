//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	double x1,y1,w1,h1;
	double x2,y2,w2,h2;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> x1 >> y1 >> w1 >> h1 ;
	Rect R1 = {x1,y1,w1,h1};
	cout << "Please input Rect 2 (x y w h): ";
	cin >> x2 >> y2 >> w2 >> h2 ;
	Rect R2 = {x2,y2,w2,h2} ;
	cout << "Overlap area = ";
	cout << overlap(&R1,&R2);
	return 0;
}

double overlap(Rect *R1,Rect *R2){
    double Wmax,Wmin,Hmax,Hmin,Woverlap,Hoverlap;
	if(R1->x < R2->x){
		Wmax = R2->x;
	}else{
		Wmax = R1->x;
	}
	if(R1->x+R1->w < R2->x+R2->w){
		Wmin = R1->x+R1->w;
	}else{
		Wmin = R2->x+R2->w;
	}
	if(R1->y-R1->h < R2->y-R2->h){
		Hmax = R2->y-R2->h;
	}else{
		Hmax = R1->y-R1->h;
	}
	if(R1->y < R2->y){
		Hmin = R1->y;
	}else{
		Hmin = R2->y;
	}
	if(Wmin > Wmax){
		Woverlap = Wmin - Wmax;
	}else{
		Woverlap = 0;
	}
	if(Hmin > Hmax){
		Hoverlap = Hmin - Hmax;
	}else{
		Hoverlap = 0;
	}
    return Woverlap*Hoverlap;
}
