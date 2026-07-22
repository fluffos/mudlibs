// wujiang.c 武将

inherit NPC;
#include <ansi.h>
#include "name.h" ;

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
	set_name(name, ({ "wu jiang", "wu", "jiang" ,"wujing"}));
	set("gender", "男性");
        set("title",HIY"吐蕃猛虎营大将"NOR);
	set("age", random(10) + 30);
	set("str", 30);
	set("dex", 16);
	set("long", "长得虎背熊腰，昂首挺胸这么一站，看得出是久经战阵的吐蕃骁将。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("unique", 3);

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", random(50)+30);
	set_temp("apply/defense", random(50)+30);
	set_temp("apply/armor", random(50)+30);
	set_temp("apply/damage", random(30)+30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object(BINGQI_D("dujiaotongren"))->wield();
	carry_object(ARMOR_D("hutoujia"))->wear();
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
