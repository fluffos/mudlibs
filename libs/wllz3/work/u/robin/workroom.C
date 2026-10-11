// workroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "【昆虫窝】");
        set("long", @LONG
这是大树顶上的一个昆虫窝。这里就是大名～顶～啊～顶【虫虫】的
家。这里没有床，因为虫虫喜欢站着......。其实人类很难了解昆虫的世
界。你来到这里～该不是想当这里的“$HIY$虫窝$NOR$”女主人吧？？？
LONG

);
        set("exits",([
                "bmw"    :"/u/bmw/workroom",
                "mindy"  :"/u/mindy/workroom",
                "zoys"   :"/u/zoys/workroom",
                "robert" :"/u/robert/workroom",
                "down"   :"/d/wizard/wizard_room",
        ]));
        setup();
        replace_program(ROOM);
}