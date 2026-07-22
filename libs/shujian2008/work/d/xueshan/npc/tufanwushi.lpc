// tufanwushi.c 吐蕃武士
// by iceland

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

	set_name(name, ({"tufan wushi","tufanwushi","wushi","wu shi","shi"}));
	set("long",@LONG
他是吐蕃国的武士，高鼻鹰目，毛发卷曲，面貌生得和中原人士大不相同，
膀阔腰圆，看来气力不小，举手投足间现出一股彪悍之气。
LONG
	);

	set("gender", "男性");
	set("attitude", "heroism");
	set("title" , HIY"吐蕃国武士"NOR);
	set("age", random(10)+25);
	set("shen_type", -1);
	set("str", random(10)+20);
	set("int", random(10)+20);
	set("con", random(10)+20);
	set("dex", random(10)+20);
	set("max_qi", random(300)+600);
	set("eff_jing", 300);
	set("max_jing",300);
	set("neili", 550);
	set("max_neili", 550);
	set("combat_exp", random(50000)+50000);
	set("score", 5000);
	set("unique", 8);

	set_skill("force", random(30)+60);
	set_skill("dodge", random(30)+60);
	set_skill("unarmed", random(30)+60);
	set_skill("parry", random(30)+60);
        set_skill("blade",random(30)+60);

	setup();

        carry_object(BINGQI_D("xinyuedao"))->wield();
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