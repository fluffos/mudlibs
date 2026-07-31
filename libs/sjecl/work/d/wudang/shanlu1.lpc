// /d/wudang/shanlu1.c 山路
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"山路"NOR);
        set("long", @LONG
你走在登山的路径上，路的左破边是山壁，右边钉有大铁链，外边是一大
山谷，谷里长满了山竹。山风一过，翠波起伏，美不胜收!
LONG
        );
        set("exits", ([
                "westup" : __DIR__"yuxu",
                "northdown" :__DIR__"wdbolin",
        ]));
        set("outdoors","武当");
        setup();
}
