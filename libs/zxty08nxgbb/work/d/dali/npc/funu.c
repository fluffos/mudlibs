// girl.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("良家妇女", ({ "funu" }) );
        set("gender", "女性" );
        set("title", HIR "饱受摧残" NOR);
        set("age", 18);
        set("long",
                "一个饱受摧残的良家妇女\n");
        set("attitude", "friendly");
        set("per",30);
        setup();
        carry_object(__DIR__"obj/nocloth")->wear();
}

/*
void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
*/
