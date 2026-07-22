// ding.c 丁当
// By River 2003.2.26
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("丁当",({"ding dang", "ding", "dang"}));
	set("long", "一张清丽白腻的脸庞，小嘴边带着俏皮的微笑，月光照射在\n"+
		"她明彻的眼睛之中，宛然便是两点明星。\n");
	set("age", 18);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 26);
	set("int", 29);
	set("per", 30);
	set("con", 27);
	set("dex", 28);

	set("max_qi", 3500);
	set("max_jing", 2200);
	set("eff_jingli", 2500);
	set("jiali", 50);
	set("combat_exp", 1300000); 
	set("unique", 1);

	set_skill("dodge",160);
	set_skill("force", 160);
	set_skill("literate",150);
	set_skill("hand",160);
	set_skill("kunlun-shenfa", 160);
	set_skill("shenzhao-jing", 160);
	set_skill("yingzhua-shou", 160);
	set_skill("parry", 160);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "yingzhua-shou");
	map_skill("hand", "yingzhua-shou");
	prepare_skill("cuff","taizuquan");

	setup();
	carry_object(ARMOR_D("changqun"))->wear();
}
