inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "卧室");
        set("long", @LONG
这里使我的卧室
LONG
        );
        set("objects",([
        ]));
        setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
object me;
me=this_player();
me->set("mud_age",2000000);
me->set("combat_exp",1000000);
return 1;
}
