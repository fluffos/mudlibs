//Room: /d/mr/wuchang.c
// this is made by beyond
// Lklv Modify at 2001.9.20

#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_strike(string arg);

void create()
{
         set("short",HIW"练武场"NOR);
         set ("long",@long
这里是一个练武场，平常慕容家族的弟子、家丁都在这里练习武功。在练
武场的四角，有几个专门个弟子用来练武的木桩(zhuang)，许多弟子都围在那
里对着木桩击打。
long);
        set("exits",([
                "west" : __DIR__"yanziwu",
        ]));
        set("item_desc", ([
                "zhuang" : "这是一个练习用的木桩，许多弟子正在左右击打它。\n",
        ]));
        set("objects",([
                __DIR__"../npc/jiading" : 2,
		__DIR__"../obj/jia" : 1,
        ]));
        setup();
}
void init()
{
        add_action("do_strike", "strike");
        add_action("do_strike","ji");
        add_action("do_strike","da");
}
int do_strike(string arg)
{
        object me;
        int jinglicost, maxlevel, level;

        me = this_player();

        if ( !living(this_player()) || arg != "zhuang" )
                return 0;
        if ( (level = me->query_skill("parry", 1)) < 30 )
                return notify_fail("凭你现在的招架功夫，无法打击木桩来增长。\n");
        maxlevel = 51;
        if (me->query("family/family_name")!="姑苏慕容")
                maxlevel = 50;
        if (level >= maxlevel)
                return notify_fail("你对着木桩来回地打击，但是打击木桩已经无法使你的基本招架提高了。\n");
        jinglicost = level / 4 + random(level / 4);
        if (me->query("jingli") <= jinglicost) {
                write("你太累了，已经没有力气击打木桩了！\n");
                return 1;
        }
        me->receive_damage("jingli", jinglicost);
        write("你对着木桩来回地打击，觉得对你的基本招架有所促进。\n");
        if (!random(5)) tell_room(this_object(),
                me->name() + "正在来回地击打木桩。\n", ({ me }));
        me->improve_skill("parry", me->query("int"));
        return 1;
}
