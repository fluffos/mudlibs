inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "苦肉之计"); 
    set("long", @long
人不自害，受害必真；假真真假，间以得行。童蒙之吉，顺以巽也。
将多兵众，不可以敌，使其自累，以杀其势。在师中吉，承天宠也。全师
避敌。左次无咎，未失常也。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou4c", 
    	"north" : __DIR__"lou4a",
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