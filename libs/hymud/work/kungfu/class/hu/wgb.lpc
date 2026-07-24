// hongmao.c
// Last Modifyed by Ahda on Jan. 4 2002
#include <ansi.h>
inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("罗刹兵", ({ "luosha gui", "gui"}));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long","入侵我天朝罗刹兵。他手上端着一支火枪，枪口还冒着青烟。\n");
	set("combat_exp", 25000);
	set("shen_type", 1);
	set("attitude", "peaceful");
set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 14000);
	set("max_neili", 14000);
	set("max_neili", 14000);
	set("jiali", 100);
	set("combat_exp", 2500000);
	set("score", 400000);
set("no_get",1);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("huagong-dafa", 300);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 300);
	set_skill("dodge", 200);
	set_skill("zhaixinggong", 300);
	set_skill("strike", 200);
	set_skill("chousui-zhang", 300);
	set_skill("claw", 200);
	set_skill("sanyin-wugongzhao", 300);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("poison", 300);
	set_skill("tianshan-zhang", 300);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.zhushen" :),
                (: perform_action, "strike.zhaohuo" :),                
                (: perform_action, "strike.biyan" :),
                (: perform_action, "staff.jinxian" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.huoqiu" :),
                (: perform_action, "staff.tianshan " :),
        }) );
	set_temp("apply/attack", 130);
	set_temp("apply/defense", 130);
	set_temp("apply/armor", 1300);
	set_temp("apply/damage", 1300);

	setup();
	carry_object("/d/taiwan/npc/obj/huoqiang")->wield();
	carry_object("/d/taiwan/npc/obj/xifu")->wield();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( environment(ob) != environment() ) return;
	if (userp(ob))
{
	say("红毛鬼抬手就是一枪：砰！枪口一团火焰喷出。\n");
	ob->receive_damage("qi",150+random(3000));
	ob->receive_wound("qi",150+random(3000));
kill_ob(ob);
}
}

