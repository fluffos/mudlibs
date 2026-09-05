//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "土路");
        set("long", @LONG
这是一条土路，往西是应天府。往北远远可以望见长江。东北面通向镇江
府，东南通向苏州府。
LONG
        );

        set("exits", ([
               "southwest" : __DIR__"guandaosd2",
               "westup" : __DIR__"tulue1",
               "southeast" : __DIR__"tulue3",
               "northeast" : __DIR__"tulune1",
               "northup" : __DIR__"zhongshan",
        ]));

        set("outdoors", "yingtianfu");
        setup();
        
}
