// shijian.c 侍剑

inherit NPC;
#include <ansi.h>

void create()
{
	object ob;
	set_name("侍剑",({"shi jian", "shi", "jian"}));
	set("long", "这个少女身穿鹅黄短袄，面庞略作圆形，眼睛睁得大大地，\n"+
		"神色间多了一份温柔，却也妩媚可喜。");
	set("gender", "女性");
	set("age", 16);
	set("per", 28);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);	

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 1);
	set("combat_exp", 1000);
	set("score", 50000);

	set_skill("unarmed",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	set_skill("force", 20);
	set_skill("sword", 20);

	setup();
	ob = new(ARMOR_D("cloth"));
	ob->set("name", HIY"鹅黄短袄"NOR);
	ob->move(this_object());
	ob->wear();
}
