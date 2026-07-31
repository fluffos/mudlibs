inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "李代桃僵"); 
    set("long", @long
势必有损，损阴以益阳。信而安之，阴以图之，备而
后动，勿使有变。刚中柔外也。疑以叩实，察而后动；复
者，阴之媒也。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou2c", 
    	"north" : __DIR__"lou2a",
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