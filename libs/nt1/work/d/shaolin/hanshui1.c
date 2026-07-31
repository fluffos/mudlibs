#include <ansi.h>
#include <room.h>
inherit RIVER;

void create()
{
        set("short", "汉水南岸");
        set("long", @LONG
面前是一条波涛翻滚的大江(river)。浊流滚滚，万舟竞发。两岸渡
船来来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸边，几个破萝支
一块木板，板上摆满了活蹦乱跳的汉江鲤鱼。过去不远，是有名的老河口。
LONG );
        set("arrive_room", "/d/shaolin/hanshui2");
        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

        set("objects", ([
        ]));

        set("outdoors", "nanyang");
        setup();
        replace_program(RIVER);
}

