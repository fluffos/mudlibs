inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "密室"); 
    set("long", @long
门后有几十级石阶，通向地底，下面是山腹，还没有走下去已看到
了一片珠光宝气！山腹是空的，方圆数十丈堆着扎扎的红樱枪，一捆捆
的鬼头刀，还有一箱箱的黄金珠宝。恐怕普通人这生中，都从来也没有
看见过这么多的刀枪和珠宝。
long 
    ); 
    set("exits", ([ 
    	//"east" : __DIR__"midao", 
    	//"south" : __DIR__"midao",
    	//"west" : __DIR__"midao",
    	"enter" : __DIR__"alou5",
        ])); 
                set("objects", ([
                __DIR__"npc/wang1": 1,
                __DIR__"npc/wang2": 1,
                __DIR__"npc/wang3": 1,
                __DIR__"npc/wang4": 1,
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC",1);
        set("valid_startroom",1);
    set("indoors","shanxi"); 
set("coor/x",-400);
        set("coor/y",-250);
        set("coor/z",99);
        setup(); 
                create_door("enter", "石门", "out", DOOR_CLOSED); 

} 