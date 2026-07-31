inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "反间之计"); 
    set("long", @long
兵强者，攻其将；将智者，伐其情。将弱兵颓，其势自萎。利用御
寇，顺相保也。虚者虚之，疑中生疑；刚柔之际，奇而复奇。疑中之疑。
比之自内，不自失也。
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"lou4g", 
    	"south" : __DIR__"lou4e",
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