// /d/dali/changting
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "十里长亭" NOR );
        set("long", @LONG
一座小亭子，专为人们送别亲人时休息而用，一般送客也就
到此为止。史有称十里相送，即由此而来。这里有一个小贩在为
人们卖些米酒，食物。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"dxiaolu1", 
                "west"  :"d/dali/road1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
