//by enter xiaoya

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "北城门");
        set("long",
"这是北城门，因为是"HIM"成都"NOR"的门面之一，因此修建的特别\n"
"雄伟,而且成都是一个法制之都,治安良好,进城之前最好看\n"
"看白纸黑字的"HIW"官府告示"NOR"(gaoshi)东北方就是大巴山了，一条\n"
"崎岖的小山路在山里蜿蜒而上。\n"
        );

        set("exits", ([
                "north" : __DIR__"dadao5",
                "south" : __DIR__"beijie1",
        ]));
        set("item_desc",([
            "gaoshi" : "如果你遵纪守法,那么你在成都将过的很愉快,\n
否则你将受到严厉的处罚----连吃十顿麻辣火\n
锅! 成都安抚使--叶青。\n)",
             ]));
        set("objects", ([
                "/d/city/npc/wujiang" : 2,
                "/d/city/npc/bing" : 3,
        ]));


        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


