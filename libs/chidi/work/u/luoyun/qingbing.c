//qingbing.c 亲兵

#include <ansi.h>
inherit BHNPC;

void create()
{
   set_name(HIW"亲兵"NOR, ({ "qing bing", "qing", "bing" }));
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他手握钢刀，目视前方，真是威风凛凛。\n");
        set("combat_exp", 85000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

        set_skill("unarmed", 900);
        set_skill("force", 900);
        set_skill("blade", 900);
        set_skill("force", 800);
        set_skill("blade", 1000);
        set_skill("dodge", 900);
        set_skill("parry", 900);
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);

	set("neili", 400000); 
	set("max_neili", 400000);
	set("jiali", 1000);
	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	add_money("silver", random(15));
}

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

