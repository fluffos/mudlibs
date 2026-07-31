inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "借尸还魂"); 
    set("long", @long
待天以困之，用人以诱之，往蹇来连。有用者，不可借；不能用
者，求借。借不能用者而用之，匪我求童蒙，童蒙求我。微隙在所必
乘；微利在所必得。少阴，少阳。
long 
    ); 
    set("exits", ([ 
    	"north" : __DIR__"lou2f", 
    	"south" : __DIR__"lou2d",
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