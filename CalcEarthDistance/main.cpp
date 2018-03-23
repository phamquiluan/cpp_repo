#include <iostream>
#include <math.h>
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0
using namespace std;

/// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * pi / 180);
}

///  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

double distanceEarth(double lon1d, double lat1d, double lon2d, double lat2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r)* v * v));
}

int main(){
	cout << "1-2: " << 1000 * distanceEarth(-122.38491, 37.75196, -122.38488,37.75201) << endl;
    cout << "1-3: " << 1000 * distanceEarth(-122.38491, 37.75196, -122.38489,37.75198) << endl;
    cout << "1-4: " << 1000 * distanceEarth(-122.38491, 37.75196, -122.38487,37.75201) << endl;
    cout << "2-3: " << 1000 * distanceEarth(-122.38488, 37.75201, -122.38489,37.75198) << endl;
    cout << "2-4: " << 1000 * distanceEarth(-122.38488, 37.75201, -122.38487,37.75201) << endl;
    cout << "3-4: " << 1000 * distanceEarth(-122.38489, 37.75198, -122.38487,37.75201) << endl;

	
	return 0;
}
