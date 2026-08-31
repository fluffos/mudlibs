//
// Direction table for mobs on the way home
// Coded by Silver Sun 05-07-1995 9:46:33 am
//

// 
// this is file to be included in every mob leader
// here is a table of direction which way mob should go back to orc city
//

// the algotritm for picking next room on the way is similar like 
// in nosave tables for routing in comp nets
// if you know stupid Floyds algoritm then know it is like one
// column from the routing table since the target room is just on

// home room is /players/silver/rooms/goal file

#define OOM "players/silver/MOB/rooms/"
string _get_next_room_on_the_way_home( string RoomFile )
 {
   switch( RoomFile )
   {
    // this is dir table for test area
    case OOM+"tr1":  return ROOM+"goal";       
    case OOM+"tr2":  return ROOM+"tr1";   	
    case OOM+"tr3":  return ROOM+"tr2";   	
    case OOM+"tr4":  return ROOM+"tr1";   	
    case OOM+"tr5":  return ROOM+"tr5";   	
    case OOM+"tr6":  return ROOM+"tr3";   	
    case OOM+"tr7":  return ROOM+"tr1";   	
    case OOM+"tr8":  return ROOM+"tr7";   	
    case OOM+"tr9":  return ROOM+"tr8";   	
    case OOM+"tr10":  return ROOM+"tr4";   	
    case OOM+"tr11":  return ROOM+"tr10";   	
    case OOM+"tr12":  return ROOM+"tr6";   	
    case OOM+"tr13":  return ROOM+"tr12";   	
    case OOM+"goal":  return "we_are_home";
    
	default: return ROOM+"goal";
   }
 }
// END OF FILE
