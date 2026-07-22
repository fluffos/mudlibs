// bing.c 士兵

#include <ansi.h>
inherit NPC;
#include "name.h";

void create()
{
    string name,m1,m2,m3,m4;
    int i;
    i=random(4);
m1=names[i][random(sizeof(names[i]))];	
m2=names[0][random(sizeof(names[0]))];
m3=names[1][random(sizeof(names[1]))];
m4=names[2][random(sizeof(names[2]))];

switch (random(3)){
	case 0:  
        name = m1+m2; 
 	break;
	case 1: 
        name = m1+m2+m3; 
	break;
	case 2:
        name = m1+m2+m3+m4 ;  
	break;
	} 
	set_name(name, ({ "shi bing", "bing" }));
	set("age", random(10)+20);
	set("gender", "男性");
	set("long", "都是土生土长的本地人，是吐蕃国的子弟兵，专职皇城内外的治安。\n");
	set("attitude", "peaceful");
        set("title",HIY"吐蕃猛虎营士兵"NOR);

	set("str", 25);
	set("dex", 20);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("unique", 10);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		name+"喝道：那来的小贼，活得不耐烦了？竟在这里闹事！\n",
		name+"叫道：快围住了他！别让他跑了！\n",
	}));
	setup();
	carry_object(BINGQI_D("juchidao"))->wield();
	carry_object(ARMOR_D("pidun"))->wear();
	carry_object(ARMOR_D("pixue"))->wear();
	carry_object(ARMOR_D("pijia"))->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	if (!is_killing(me->query("id")))
		me->add_condition("killer", 15);
	kill_ob(me);
	return 1;
}
