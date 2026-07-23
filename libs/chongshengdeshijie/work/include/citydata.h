/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : /include/citydata.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define CITY_ROOT				"/city/"
#define CITY_PATH(city)				CITY_ROOT+(string)city+"/"
#define CITY_INFO(city)				CITY_PATH(city)+"info"
#define CITY_NUM(city, num)			CITY_PATH(city)+(string)num+"/"
#define CITY_NUM_DATA(city, num)		CITY_NUM(city, num)+"data"
#define CITY_NUM_MAP(city, num)			CITY_NUM(city, num)+"map"
#define CITY_NUM_ROOM(city, num)		CITY_NUM(city, num)+"room/"
#define CITY_NUM_ESTATE(city, num)		CITY_NUM(city, num)+"estate"

#define CITY_ROOM_MODULE(city, num, x, y, roomtype)		CITY_NUM_ROOM(city, num)+(string)x+"_"+(string)y+"_"+(string)roomtype
