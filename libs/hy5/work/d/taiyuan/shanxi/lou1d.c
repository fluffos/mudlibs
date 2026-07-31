inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "以逸待劳"); 
    set("long", @long
困敌之势，不以战；损刚益柔。敌之害大，就势取
利，刚决柔也。敌志乱萃，不虞，坤下兑上之象，利其
不自主而取之。
long 
    ); 
    set("exits", ([ 
    	"north" : __DIR__"lou1e", 
    	"west" : __DIR__"lou1c",
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