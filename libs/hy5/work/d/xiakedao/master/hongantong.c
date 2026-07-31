// hong.c 洪安通

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("洪安通", ({ "hong-antong", "hong" }));
	set("title",  "神龙教教主" );
        set("nickname", HIR "永享仙福" NOR);
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。\n");
	set("gender", "男性");
	set("age", 50);
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
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say 夫人所说甚是有理，但这句似更含深意。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="su-quan")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        command("say 横剑似指剑行之势。。。");
        return;
}

