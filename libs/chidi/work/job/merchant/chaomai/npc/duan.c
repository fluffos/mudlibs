// zeus.c

#include <ansi.h>

inherit BHNPC;

void create()
{
        set_name(HIC"袖子"NOR, ({ "duanxiu"}) );
        set("title", HIG"商行的帐房先生"NOR);
        set("gender", "男性" );
        set("age", 18);
        set("long",
               "这个当然是胡子的手下，现在正在将江湖的地基修改，可以算是胡子的得力助手吧。\n");
        set("attitude", "friendly");
        set("rank_info/respect", "帐房先生");
        setup();
}

void relay_emote(object me,string arg)
{
        command(arg+" "+me->query("id"));
}

