#ifndef __OVERLAND_H__
#define __OVERLAND_H__

#define WORLD "p/service/creative/overland/overland"
#define OVERLAND_ROOM "p/service/creative/overland/genOverlandRoom"

#define LOC_WORLD( x )  x[0]
#define LOC_PLAIN( x )  x[1]
#define LOC_MAP( x )    x[2]
#define LOC_VIEW_X( x ) x[2]
#define LOC_VIEW_Y( x ) x[3]  


#define OLVIEW_RADIUS 7
#define OLVIEW_SIZE   (2*OLVIEW_RADIUS+1)

#define OLVIEW_PLAINS             5
#define OLVIEW_POSITION( x )      x[0] //location of the view
#define OLVIEW_LOWER_PLAIN( x )   x[1] //plain seen if current plain is transparent
#define OLVIEW_PLAIN( x )         x[2] //the plain the location is on
#define OLVIEW_VISIBLE_PLAIN( x ) x[3] //what you might see
#define OLVIEW_ZONES( x )         x[4] // the plain that containes the visible zones

#define ROOM_DATA_VCOLOR( x )        x[0]
#define ROOM_DATA_VCHAR( x )         x[1]
#define ROOM_DATA_BLOCKING( x )      x[2]
#define ROOM_DATA_HCOLOR( x )        x[3]
#define ROOM_DATA_HCHAR( x )         x[4]
#define ROOM_DATA_ROOMTYPE( x )      x[5]
#define ROOM_DATA_ROOMLANDSCAPE( x ) x[6]
#define ROOM_DATA_FPNEEDED( x )      x[7]
#define ROOM_DATA_DESCRIPTION( x )   x[8]
#define ROOM_DATA_CANENTER( x )      x[9]
#define ROOM_DATA_BLOCKMESSAGE( x )  x[10]
#define ROOM_DATA_FLAGS( x )         x[11]

#define ZONE_DATA_LOCATION 0
#define ZONE_DATA_POSX     1
#define ZONE_DATA_POSY     2
#define ZONE_DATA_TYPE     3
#define ZONE_DATA_COLOUR   4
#define ZONE_DATA_CHAR     5
#define ZONE_DATA_FLAGS    6
#define ZONE_DATA_ENTRYS   7

#define PROFILE(x) _ec_=get_eval_cost(); x; _ec_-=get_eval_cost(); write("eval cost: "+_ec_-3+"\n");

#define DEBUG(x) if ( find_player("creative") ) tell_object( find_player("creative"), sprintf("OL: %O\n", x ));

#define COLOUR_INFO(x) x

#endif


