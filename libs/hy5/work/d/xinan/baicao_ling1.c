#include <room.h>
inherit ROOM;


void create()
{
        set("short", "百草岭");
        set("long", @LONG
百草岭上气候温暖，终年云雾缭绕，向南的山坡上又生满了高大的树木，即
使山外晴空万里，这里也还是见不到太阳，背阴的山谷里阴冷幽暗，沟底溪水潺
潺，水边长满了不知名的花草，据说其中有许多珍贵的药材。草丛里经常有毒蛇
出没，叫人胆战心惊。
LONG
        );
        set("exits", ([
                "southdown"     : __DIR__"shandao0",
                "north"         : __DIR__"baicao_ling2",
        ]));
        set("search_things",([
            "山谷" : __DIR__"obj/heshouwu" ,
                                  ])
       );

        setup();



}
