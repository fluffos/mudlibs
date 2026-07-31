// /d/wudang/gudao1.c  古道

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"古道"NOR);
        set("long", @LONG
你走在一条人迹不至的古道上，四周野草过顶，路径时隐时现，你正低头
辨认时，忽感到脖子一凉，啊! 从树上掉下条毒蛇，正好落在你身上，
一条腥红的舌头正对着你一深一吐，好不吓人。
LONG                           
        );
        set("exits", ([
                "eastup" : __DIR__"gudao2",
                "westdown" : __DIR__"shanlu",
        ]));

        set("objects",([
                __DIR__"npc/dushe" : 1,

        ]));

        setup();
        replace_program(ROOM);

}

