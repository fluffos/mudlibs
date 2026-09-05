#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","地道");
        set("long",@LONG 
这里墙壁上点着一盏油灯，发出淡黄色光芒，置身之所似是个地道。
地道高度突然缩小，必须弓身而行，越向前行，弯腰越低。空气更加潮
湿，脚下的泥土也隐隐有些湿意，你仿佛在地底下。
   南边的墙上有一个开关，你似乎可以去按(push)它。
LONG
        );

        set("exits", ([
		"northdown" : __DIR__"andao2",
        ]));
        setup();

}
void init()
{
    add_action("do_push","push");       
}
int do_push()
{
        message_vision(HIG"$N用力按了一下开关，墙壁缓缓开启。$N侧身进门，按了一下开关，墙壁吭的一声关上了。\n"NOR,this_player());
        this_player()->move(__DIR__"neitang");

        return 1;
}

