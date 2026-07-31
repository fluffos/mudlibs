inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "假道代虢"); 
    set("long", @long
存其形，完其势；友不疑，敌不动。巽而止蛊。乘其阴乱，
利其弱而无主。随，以向晦入宴息。两大之间，敌胁以从，我
假以势。困，有言不信。
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"lou3g", 
    	"south" : __DIR__"lou3e",
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