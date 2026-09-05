// Room: /d/beijing/tianshui.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"甜水井胡同"NOR);
        set("long",
CYN"这条胡同虽不起眼，但因为胡同里有一口甜水井而得名。北京城中
水井都出苦水，甜水井极少。紫禁城里用水都要每天去玉泉山运回，这
几口不多的甜水井就对北京城普通百姓尤为重要。\n"NOR
        );
        set("outdoors", "京城");

        set("exits", ([
                "west" : __DIR__"qianmen1",
//                "east" : __DIR__"kedian",
                "north": __DIR__"picai",
        ]));
        set("objects", ([
                 __DIR__"npc/modaode":1,
        ]));
//	set("cost", 2);
        setup();
        replace_program(ROOM);
}

