// by cool 98.6.1
// 改编者caiji@SJ 8/24/2000
// River@SJ

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include "skill.h";

string *color_title = ({YEL+"玄武杀手"+NOR, HIR+"朱雀杀手"+NOR,HIW+"白虎杀手"+NOR, HIC+"青龙杀手"+NOR});
string *k_weapon = ({"sword","blade","staff","whip","gun",});

void create()
{
	object cloth;
	mapping name;
	int i;

	i = random(4);

	name = RNAME_D->get_random_name(i);

	set_name(name["name"], name["id"]);
	set("title", color_title[random(sizeof(color_title))]);
	set("gender", (i==0?"女性":"男性"));
	set("long", "这人身穿黑色紧装，面上蒙着一块黑布，只露出一双眼睛，精光四射。\n");
	set("age", random(10)+24);
	set("str", 15+random(10));
	set("int",15+random(10));
	set("con",15+random(10));
	set("dex",15+random(10));
	set("combat_exp", 100000);
	set("no_quest", 1);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("max_qi",1200);
	set("max_jing",1200);
	set("neili",1000);
	set("max_neili",1000);
	set("score", 100);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	setup();
	add_money("silver", random(50)+50);

	cloth = new(ARMOR_D("cloth"));
	cloth->set("name","黑色紧装");
	cloth->set("apply/armor", 40);
	cloth->move(this_object());
	cloth->wear();
}

#include "shashou.h";
