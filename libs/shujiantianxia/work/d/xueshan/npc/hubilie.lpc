// hubilie.c 忽必烈
// by iceland

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("忽必烈", ({ "hu bilie", "hubilie" ,"hu" }));
        set("long",@LONG
他长得脸色白皙，相貌儒雅，科头布服，行止极似书生，眉目之间却透出一
股英气。很难想到原来他是威镇漠北的成吉思汗之孙，皇子拖雷第四子。
LONG
        );
        set("title", HIY "蒙古王子" NOR);
        set("gender", "男性");
        set("age", 26);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("combat_exp", 150000);
	set("unique", 1);

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense",60);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 60);


        setup();
        carry_object( MISC_D("cloth"))->wear();

        add_money("gold",1);
}

void unconcious()
{
        command("say 给我报仇！");
        ::unconcious();
}

void kill_ob(object me)
{
        command("chat 抓刺客！");
        command("chat* sneer "+me->query("id"));
        me->set_temp("cike",1);
        ::kill_ob(me);
}

void init()
{
        object ob = this_player();

	::init();
	if (!ob || !visible(ob) || !present(ob, environment())) return;
        command("look " + ob->query("id"));
	command("say 这位" + RANK_D->query_respect(ob)+"风尘仆仆，是从哪里来呀？\n");
}
