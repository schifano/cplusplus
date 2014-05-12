#ifndef _GPSLOCATION_H_
#define _GPSLOCATION_H_

#include <cmath>

class GPSLocation
{

 public:
  GPSLocation() { latitude = longitude = 0.0f;}
  inline void setLatitude(float l) { latitude = l;}
  inline void setLongitude(float l) { longitude = l;}
  inline float getLatitude() const { return latitude;}
  inline float getLongitude() const { return longitude;}

  inline float getDistance(const GPSLocation& loc) const
  {
    //computes the distance between two latitudes and longitudes using haversine's formula
    float degToRadians = 3.14159/180;
    float dlat = (latitude -loc.getLatitude())*degToRadians;
    float dlong = (longitude - loc.getLongitude())*degToRadians;

    float a = sin(0.5*dlat)*sin(0.5*dlat)+cos(latitude*degToRadians)*cos(loc.getLatitude()*degToRadians)*sin(0.5*dlong)*sin(0.5*dlong);
    float c = 2*atan2(sqrt(a),sqrt(1-a));
    float d = 6371 * c/1.6; //miles
    return d;
  }
    
 private:
  float latitude;
  float longitude;
};

#endif
