//bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "府南河畔");
        set("long",
""HIW"你信步来到了府南河畔，这里便是被称为成都母亲河的"HIC"府南河"NOR"\n"
""HIW"，两岸垂柳，随风飘动，绿草如茵，彩蝶纷飞。河水清澈见底，鱼\n"
"儿游来游去，河的对岸有群洗衣妇人，一边辛勤地劳作，一边大声\n"
"地聊天，欢声笑语在河的这边都可以听见。远处还有个老渔翁独自\n"
"垂钓。看到这里，你也仿佛入画了。东北面有个小亭。"NOR"\n"
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "southeast" : __DIR__"funanhe3",
                "northwest" : __DIR__"funanhe1",
                "northeast" : __DIR__"xiaoting",
            ]));
        setup();
        replace_program(ROOM);       
}


