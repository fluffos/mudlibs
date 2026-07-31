inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "树上开花"); 
    set("long", @long
假之以便，唆之使前，断其援应，陷之死地。遇毒，位不当也。借
局布势，力小势大。鸿渐于陆，其羽可用为仪也。乘隙插足，扼其主机，
渐之进也。
long 
    ); 
    set("exits", ([ 
    	"north" : __DIR__"lou4e", 
    	//"south" : __DIR__"midao",
    	"west" : __DIR__"lou4c",
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