//bye enter

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",HIY "春熙路" NOR);
        set("long", 
""HIW"这里便是成都著名的商业中心，街上行人来来往往，两\n"
"旁店铺林立，热闹非凡，东面有个大酒楼，金色的锦旗迎风\n"
"飘扬，只见上书四个大字格外醒目"+BLINK HIR"“银杏酒楼”"NOR""HIW"。西面看起"NOR"\n"
""HIW"来是个茶馆，一个个衣着光鲜的人从那里进进出出。"NOR"\n"
      );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "south" : __DIR__"chunxilu2",
                "north" : __DIR__"chunxilu",
                "east" : __DIR__"jiulou1",
                "west" : __DIR__"chaguan",
            ]));

        setup();
        replace_program(ROOM);       
}



