/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : i2d.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define MUD                     0
#define STREAM                  1
#define DATAGRAM                2
#define STREAM_BINARY           3
#define DATAGRAM_BINARY         4
//-----------------------------------------------
#define I2D_MUD_SERVER 		({"203.71.88.240",4004})
#define MUDLIST_UPDATE_INTERVAL 600
#define REFRESH_INCOMING_TIME   3*60*60
//----------------------位元運算用-------------------------
#define GB_CODE 	1
#define ANTI_AD 	2
#define IGNORED 	4
#define SHUTDOWN 	8
#define ONLINE 		16
#define DISCONNECT 	32
#define ENCODE_CONFIRM	64


//___________________________________________________
// 下面兩行是 luky 制定
#define MUD_LOCATION                    "Taiwan"
#define MUD_GROUP                       "台灣泥巴聯盟"
