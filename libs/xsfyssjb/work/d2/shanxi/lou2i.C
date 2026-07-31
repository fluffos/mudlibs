inherit ROOM;
#include <room.h>
#include <ansi.h>
void create() 
{ 
    set("short", HIR"擒贼擒王"NOR); 
    set("long", @long
逼则反兵；走则减势。紧随勿迫。累其气力，消其斗志，散而后擒，
兵不血刃。需，有孚，光。类以诱之，击蒙也。摧其坚，夺其魁，以解其
体。龙战于野，其道穷也。
long 
    ); 
    set("exits", ([ 
    	"up" : __DIR__"lou3a", 
    	"north" : __DIR__"lou2h",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                "questnpc_1/luxiaojia": 1,
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
        set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 
                //create_door("out", "石门", "enter", DOOR_CLOSED); 

} 