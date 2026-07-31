inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "暗渡陈仓"); 
    set("long", @long
诳也，非诳也，实其所诳也。少阴、太阴、太阳。示之以动，
利其静而有主，“益动而巽”。阳乖序乱，明以待逆。暴戾恣睢，
其势自毙。顺以动豫，豫顺以动。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou1i", 
    	"north" : __DIR__"lou1g",
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
        set("coor/z",101);
        setup(); 
                //create_door("out", "石门", "enter", DOOR_CLOSED); 

} 