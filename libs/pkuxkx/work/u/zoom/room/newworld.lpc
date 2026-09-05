// The whole new world
// by freecv @ 2004.4.13

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIR"乾坤袋内部"NOR);
    set("long",@LONG
这里是乾坤袋内部
LONG
    );
    set("exits",([]));
    setup();
}

void init()
{
        add_action("do_none","goto");
        add_action("do_none","home");
        add_action("do_none","ls");
        add_action("do_none","more");
        add_action("do_none","cat");
        add_action("do_none","call");
        add_action("do_none","cd");
        add_action("do_none","edit");
        add_action("do_none","pwd");
        add_action("do_none","dest");
        add_action("do_none","clone");
}

int do_none()
{
        message_vision("很可惜，你现在什么都做不了，还是乖乖呆在袋子里吧\n",this_player());
        return 1;
}

