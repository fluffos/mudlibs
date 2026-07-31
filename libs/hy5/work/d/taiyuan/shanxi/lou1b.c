inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "围魏救赵"); 
    set("long", @long
备周则意怠；常见则不疑。阴在阳之内，不在阳之对。太阳，
太阴。共敌不如分敌，敌阳不如敌阴。敌已明，友未定，引友杀
敌，不自出力，以《损》推演。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou1c", 
    	"north" : __DIR__"lou1a",
        ])); 
                set("objects", ([
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
	set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 

} 
int valid_leave(object me, string dir)
{       
        if (dir == "south" && me->query_temp("青衣楼/lou1a"))
        {
        me->delete_temp("青衣楼/lou1a");      
        }
   return 1;
}   
