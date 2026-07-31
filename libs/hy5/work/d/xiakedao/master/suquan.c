// suquan.c 苏荃

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("苏荃", ({ "su-quan", "su" }));
	set("title",  "神龙教教主夫人" );
	set("long", "一个千娇百媚、明艳不可方物的少妇。\n");
	set("gender", "女性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 200);
	set_skill("hunyuan-yiqi", 150);
	set_skill("shenlong-xinfa", 200);
        set_skill("dodge", 180);
	set_skill("yixingbu", 160);
        set_skill("unarmed", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("parry", 150);
        set_skill("staff", 200);
	set_skill("shedao-qigong", 180);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say 横剑纯为守势，膝前膝前更不可解。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="hong-antong")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

