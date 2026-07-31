inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "密室"); 
    set("long", @long
门后面又是条甬道，甬道的尽头是个空旷的山窟。空气里充满了芬
芳醇厚的酒香，中间一个红泥小火炉，火并不大，却恰好能使得这阴森
寒冷的山窟，变得温暖起来。
long 
    ); 
    set("exits", ([ 
    	"up" : __DIR__"lou1a", 
    	//"south" : __DIR__"midao",
    	//"west" : __DIR__"midao",
    	"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                //__DIR__"npc/huoxiu": 1,
                
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC",1);
        set("indoors","shanxi"); 
        set("coor/x",-400);
        set("coor/y",-220);
        set("coor/z",99);
        setup(); 
                create_door("out", "石门", "enter", DOOR_CLOSED); 

} 