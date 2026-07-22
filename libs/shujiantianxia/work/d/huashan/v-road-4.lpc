// Room: /d/huashan/v-road-4.c
// Date: Look 99/03/25
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "峭壁");
        set("long", @LONG
由于这里实在是太陡峭，你无法立足。玉女峰高高的在上面，思过崖时隐
时现。
LONG    );
        set("outdoors", "华山");
        setup();
}

int init()
{
        call_out("go_down",2,this_player());
}

int go_down(object me)
{
        me->move(__DIR__"v-road-3");
	tell_object(me, "你站在峭壁上看到一片郁郁葱葱的灌木丛，在灌木丛后好象有一堵篱笆墙。\n");
        tell_object(me, HIR"你还没站稳又滑了下来。\n"NOR);
        message("vision", "只见" + me->query("name") + "从上面滑了下来。\n", environment(me), me);
        return 1;
}