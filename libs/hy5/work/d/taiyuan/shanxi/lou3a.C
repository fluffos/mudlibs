inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "釜底抽薪"); 
    set("long", @long
不敌其力，而消其势，兑下乾上之象。频更其阵，抽其
劲旅，待其自败，而后乘之，曳其轮也。小敌困之。剥，
不利有攸往。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou3b", 
    	//"south" : __DIR__"midao",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                //__DIR__"npc/huoxiu": 1,
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",102);
        setup(); 
                //create_door("out", "石门", "enter", DOOR_CLOSED); 

} 