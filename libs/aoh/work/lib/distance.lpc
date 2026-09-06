//---------------------------------------------------------------------------
// /lib/distance
//
// Some handy functions for the handling of distances
// (c) Softbyte@OSB 10nov97
//
// [Softbyte] 11nov97     : Creation
//---------------------------------------------------------------------------

#include <properties.h>
#include <math.h>

/**
  @author Softbyte
  @version V1.0
*/
/** @synopsis
       #include <math.h>
       L_DISTANCE->fun()
              or
       L_MATH->fun()
*/
/**
  @description
    Some handy functions for the handling of distances

*/
/** @bugs Not known
*/
/** @see /lib/math
*/


//************************************************************************
//                   Interal functions
//************************************************************************

//************************************************************************
//                   Distance functions
//************************************************************************
/**
  @function
   Either checks wether the coordinates are ok or reads out or if
   the argument is an object reads its coordinates and checks them
   @param int *|object c=Coordinate array or room object
   @return  0: Faulty coordiantes, ({x,y,z})= Coordinate array
*/
int *VerifyCoordinates(mixed c)
{
  mixed coords;
  string err;
  // wrong usage
  if (!c) return 0;

  if (objectp(c))
  {
    coords=({mixed})c->Query(P_COORDINATES);
	if (!coords || !pointerp(coords) )
	{
	  err= "/lib/distance::VerifyCoordinates failed as "+object_name(c)+
		" does not define coordinates properly.\n";
	  raise_error(err);
	}
  }
  else coords=c;

  // wrong usage
  if (!pointerp(coords)) return 0;
  if (sizeof(coords)!=3) return 0;
  return coords;
}

/**
  @function
   Calculates the distance between two given coordinates which are
   either directly given or are read from the given room objects
   @param c1,c2: int array of coordiantes ({x,y,z})
   @param c1,c2: room object whose coordinates are taken
   @return    Distance between the two points as a 2D projection,
              i.e. without considering the z-Coordinate
*/
int dist2D(mixed c1,mixed c2)
{
  float dist;
  float f1,f2;
  c1=VerifyCoordinates(c1);
  c2=VerifyCoordinates(c2);

  // An error occured
  if (!c1 || !c2) return 0;
  f1=(float)(c1[0]-c2[0]);
  f2=(float)(c1[1]-c2[1]);

  dist=f1*f1+f2*f2;
  return (int)sqrt(dist);
}
/**
  @function
   Calculates the distance between two given coordinates which are
   either directly given or are read from the given room objects
  @param c1,c2: int array of coordiantes ({x,y,z})
  @param c1,c2: room object whose coordinates are taken
  @return Distance between the two points in full 3D
*/
int dist(mixed c1,mixed c2)
{
  float dist;
  float f1,f2,f3;
  c1=VerifyCoordinates(c1);
  c2=VerifyCoordinates(c2);

  // An error occured
  if (!c1 || !c2) return 0;

  f1=(float)(c1[0]-c2[0]);
  f2=(float)(c1[1]-c2[1]);
  f3=(float)(c1[2]-c2[2]);
  dist=f1*f1+f2*f2+f3*f3;
  return (int)sqrt(dist);
}
