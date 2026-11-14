#define HOME(x) "/d/gebirge/dusty/"+x
#define OBJEKT(x) ("/d/gebirge/dusty/zwerge/obj/")+x
#define XX(x) if (!is_clone(this_object())) return   
#define ROOM(x) ("/d/gebirge/dusty/zwerge/room/")+x
#define WEG(x) ("/d/gebirge/dusty/weg/")+x
#define OBJ(x) ("/d/gebirge/dusty/zwerge/obj/")+x
#define MON(x) HOME("mon/")+x
#define NPC(x) ("/d/gebirge/dusty/zwerge/mon/")+x
#define ARMOUR(x) ("/d/gebirge/dusty/zwerge/armour/")+x
#define LOGFILE "/d/gebirge/dusty/zwerge/log/dusty.log"
#define LOGF LOGFILE
#define PL this_player()
// #define WLOG(x) write_file(LOGF,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
// #define WLOG(x) write("");
// #define FLOG(y,x) write_file(y,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));

#define TK(x) if(find_player("dusty"))tell_object(find_player("dusty"),x)

#define bs( x ) break_string( x, 78 )

#include <moredef.h>
#include <defines.h>
