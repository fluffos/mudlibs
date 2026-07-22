#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "仙人松");
        set("long", @LONG
这是地方叫仙人松，只见陡峭的山壁上斜斜的长着一株高大的松树
长势奇特，不拘一格，在雾霭之中时隐时现，因此而得名，你向远
处望去，只见雾气一团团的随风飘过，对面树根下的大石头在风的
吹动下也仿佛左右晃动！
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
           "northup" :__DIR__"shijianshi",
             "southdown" :__DIR__"wangyuetai",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
}
int do_break(string arg)
{
        int n;
        object weapon,me=this_player();
        if (arg != "stone") return 0;
        message_vision(CYN
"$N走到大石前，运气双掌，猛地击向大石！\n"NOR,me);

        if (me->query("force") < 100)
        {
               message_vision(CYN
"结果只听一声闷哼，$N被大石的反弹力震得呲牙咧嘴,一屁股坐到地上....\n"NOR,me);
               me->set("neili",0);
               me->unconcious();
               return 1;
        }
        message_vision(CYN
"$N只听一声轰响，大石被击碎了，下面露出了一个大洞！\n"NOR,me);
        set("exits/enter",__DIR__"midao");
        me->add("neili",-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
}

void close(object room)
{
    message("vision","崖上忽然掉下来一块大石头，将洞口封了个严严实实。\n", room);
    room->delete("exits/enter");
}

