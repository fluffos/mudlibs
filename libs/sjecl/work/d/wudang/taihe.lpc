// /area/jiangbei/wudang/taihe.c 大岳太和宫
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"大岳太和宫"NOR);
        set("long", @LONG
大岳太和宫建在众峰拱托、直插云霄的武当最高峰——天柱峰的绝顶上。
武当山特殊的地貌形成的众峰拱托、八方朝拜的景观也神奇地渲染出皇权的至
高无上。大岳太和宫是武当山的最高胜境，无论是道人信士，还是香客游人，
只有登上顶峰，走进太和宫，才是真正意义上的到了武当山。
LONG
        );

        set("exits", ([
                "west" : __DIR__"jindian",
                "northdown" : __DIR__"hldong",
        ]));

        set("no_clean_up", 0);

        set("objects",([
               __DIR__"npc/daotong" : 1,
        ]));

        set("outdoors", "武当");

        setup();
}
