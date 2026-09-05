//Made By:pingpang
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(BLU"归云庄"NOR+RED"武士"NOR,({"wu shi","wu","shi"}));
	set("long",@LONG
他是归云庄的守护武士，十分威武。\n
他们都是经过陆庄主亲自训练过的人，个个武艺高强。
LONG);
	set("age",30);
	set("gender","男性");
	set("attitude","heroism");
	set("title",HIC"风云战士"NOR);
	set("max_qi",800);
	set("max_jing",600);
	set("neili",600);
	set("max_neili",600);
	set("combat_exp",80000+random(20000));
	set("jiali",30);
	set_skill("force",70);
	set_skill("dodge",70);
	set_skill("parry",70);
	set_skill("unarmed",80);
	set_skill("sword",80);
	set("shen_type",1);set("score",200);setup();
	carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
	object ob=this_player();
	if((string)ob->query("family/family_name")=="桃花岛")
		command("hi "+ob->query("id"));
	else
		command("look "+ob->query("id"));
}
