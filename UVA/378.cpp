#pragma GCC optimize ("O3")

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wall"

#pragma GCC diagnostic ignored "-Wextra"

#pragma GCC diagnostic ignored "-Wconversion"

#include<bits/stdc++.h>

#include<complex>

using namespace std;

const double EPS=1e-8;

const int OO=0x3f3f3f3f;

typedef complex<double> point;

#define X real()

#define Y imag()

#define vec(a,b) ((b)-(a))

#define cp(a,b)  ((conj(a) * (b)).imag())

#define dp(a,b)  ((conj(a)*(b)).real())

#define length(v) 	((double)hypot((v).Y, (v).X))

#define lengthSqr(v) 	(dp(v, v))

#define same(a,b) 	(lengthSqr(vec(a, b)) < EPS)

int llintersection(point& a,point& b,point& c,point& d,point& ret){

    double d1=cp(c-a,b-a),d2=cp(d-a,b-a);

    if(fabs(d1)<=EPS&&fabs(d2)<=EPS)return OO;

    ret=(d1*d-d2*c)/(d1-d2);

    return (fabs(d1-d2)>EPS);


}

int main(){

    point a,b,c,d,ret;  int f,n;

    double x,y;
    
    scanf("%d",&n);

    puts("INTERSECTING LINES OUTPUT");

    while(n--){

        scanf("%lf %lf",&x,&y);     a=point(x,y);
    
    scanf("%lf %lf",&x,&y);     b=point(x,y);

        scanf("%lf %lf",&x,&y);     c=point(x,y);

        scanf("%lf %lf",&x,&y);     d=point(x,y);
        
	f=llintersection(a,b,c,d,ret);
        
	(!f)?puts("NONE"):(f==OO)?puts("LINE"):printf("POINT %0.2lf %0.2lf\n",ret.X,ret.Y);

    }

    puts("END OF OUTPUT");

}
