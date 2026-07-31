inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "远交近攻"); 
    set("long", @long
大凌小者，警以诱之。刚中而应，行险而顺。形禁势格，利从
近取，害以远隔。上火下泽。宁伪作不知不为，不伪作假知妄为。
静不露机，云雪屯也。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou3h", 
    	//"south" : __DIR__"midao",
    	"west" : __DIR__"lou3f",
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