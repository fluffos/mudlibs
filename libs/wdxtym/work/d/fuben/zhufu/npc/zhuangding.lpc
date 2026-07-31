// tufei.c

inherit NPC;
//#include <fb_skill.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name("家丁", ({ "jia ding", "jiading" }) );
	set("gender", "男性");
	set("age", 30);
	set("long", "他是朱府的家丁，满怀警惕的盯着靠近大门的陌生人。\n");

	set("combat_exp", 100000+random(300000));
	set("twtnpc",1);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_basic();
	setup();
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();
	
	if (userp(me)) {
		command("say 此乃朱府，还不快滚！\n");
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 30);
		if (!random(3))
			ob->do_clone(me, 30);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}
