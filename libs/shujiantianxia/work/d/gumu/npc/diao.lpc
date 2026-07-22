// By River@sj 99.5.24 

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("神雕", ({ "shen diao", "shen", "diao"}) );
	set("long", @LONG
眼前赫然是一头大雕，那雕身形甚巨，比人还高，形貌丑陋之极，全身羽毛疏
疏落落，似是被人拔去了一大半似的，毛色黄黑，显得甚是肮脏，模样与桃花
岛上的双雕倒也有五分相似，丑俊却是天差地远。这丑雕钓嘴弯曲，头顶生著
个血红的大肉瘤，世上鸟类千万，从未见过如此古拙雄奇的猛禽。但见这雕迈
著大步来去，双腿奇粗，有时伸出羽翼，却又甚短，不知如何飞翔，只是高视
阔步，自有一番威武气概。
LONG
    );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 100);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 44);
	set("int", 38);
	set("con", 42);
	set("dex", 44);

	set("max_qi", 3400);
	set("max_jing", 3000);
	set("neili", 3400);
	set("max_neili", 3400);
	set("combat_exp", 1800000);
	set("eff_jingli", 3000);

	set("limbs", ({ "身体", "羽翼", "嘴尖", "爪子" }));
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 350);
	set_temp("apply/defense", 350);
	set_temp("apply/damage", 300);
	set_temp("apply/armor", 200);

	set("dan_count", 2);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"神雕突然仰起头来，高鸣三声，声音微带嘶哑，但激越苍凉，气势甚豪。\n",
		"神雕转头向著你，柔声低呼，又伸出翅膀在你肩头轻拍几下。\n",
	}));
}

void reset()
{
        set("dan_count", 2);
}

void init()
{
	object me, ob, where, ob0;
	::init();
	ob = this_player();
	me = this_object();
	where = environment(me);
	if (interactive(ob = this_player())
	 && !is_fighting()         
	 && query("dan_count") > 0
	 && random(10) > 7
	 && file_name(where) == query("startroom")){
		remove_call_out("greeting");
		call_out("greeting", 0, ob, me, where, ob0);
	}
}

void greeting(object ob,object me,object where,object ob0)
{
	tell_object(ob,HIR"\n突有一股腥臭之气，显有大蛇之类毒物来到邻近。\n"NOR,);
	add("dan_count", -1);
	ob0 = new( __DIR__"dumang");
	ob0->move(where);
	message_vision(HIR"\n一条怪蟒突然窜了出来，气势凶凶。\n"NOR,me);
	message_vision(HIW"\n神雕昂起头来，哇哇哇连叫三声，似向敌人挑战。\n\n"NOR,me);
	ob->add_busy(random(2));
	me->fight_ob(ob0);
	ob0->kill_me(me);
}

void unconcious()
{
        message_vision("\n$N悲鸣数声，足步迅捷异常，行走疾如奔马往深谷中走去。\n", this_object());
        destruct(this_object());
}

void die()
{
        message_vision("\n$N悲鸣数声，足步迅捷异常，行走疾如奔马往深谷中走去。\n", this_object());
        destruct(this_object());
}
