inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "借刀杀人"); 
    set("long", @long
备周则意怠；常见则不疑。阴在阳之内，不在阳之对。太阳，
太阴。共敌不如分敌，敌阳不如敌阴。敌已明，友未定，引友杀
敌，不自出力，以《损》推演。
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"lou1d", 
    	"north" : __DIR__"lou1b",
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