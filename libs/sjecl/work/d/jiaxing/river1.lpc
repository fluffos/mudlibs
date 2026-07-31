#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", GRN "柳树林" NOR);
        set("long", @LONG
江南水乡之地到处河泊纵横，这片柳树林便生在一条小河旁，柳条随风飘
摆，宛如仙子起舞。时不时还有一两只林中鸟兽从你身前跑过，当真是个好地
方。前面小河拦路，无法再行。
LONG); 
        set("no_sleep_room", 1);
        set("objects", ([
        	CLASS_D("baituo") + "/guairen" : 1,                   
        ]));       
        set("exits", ([
              "west" : __DIR__"river",
        ]));
        set("outdoors", "嘉兴");
        setup(); 
}
