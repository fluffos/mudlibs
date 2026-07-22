// tingtang.c 厅堂
// 2001.9.27 update by Lklv

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "厅堂");
        set("long", @LONG
这是这废园里一间快倒塌的厅堂，说是厅堂，倒不如说是草棚子。门口的
两个柱子已经歪歪斜斜，用一些细木桩支撑着。墙上到处都是烟熏火燎的黑乎
乎痕迹。墙角堆着几块大石头，旁边有口水缸。一个烂席子铺在了地当中，上
面放着几个凉馒头。
LONG);
        set("resource/water", 1);
	set("drink_msg","$N趴在水缸边喝了一口凉水。\n");
        set("sleep_room",1);
        set("no_fight", 1);

        set("exits", ([
                "out" : __DIR__"feiyuan",
        ]));

        set("objects", ([
                FOOD_D("mantou") : 4
        ]));

        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object me = this_player();
        object ob;

        if (arg && (ob = present(arg)) && ob->id("man tou")){
                if ( !wizardp(me) && (present("man tou", me) || me->query("family/family_name")!="丐帮"
                 || me->query("food") > me->query("str")*10 )){
                        write("角落里有个老叫化哼了一声，你不由的缩回了手。\n");
                        return 1;
                }
        }
        return 0;
}