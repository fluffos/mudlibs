// yaopu.c

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"药铺"NOR);
        set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。药铺老板坐在茶几旁，独自喝着茶。一名小伙计站在柜台
后招呼着顾客。
LONG
        );
        set("item_desc", ([
                "guanggao" : "本店出售以下药品：
金创药：\t五十两白银
其他神药与老板面议。\n",
        ]));

        set("objects", ([
                __DIR__"npc/laoban" : 1,
                __DIR__"npc/huoji" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"cj3",
        ]));

        setup();
}


