#include <ansi.h>
inherit NPC;
void create()
{
    set_name(HIW"丹顶鹤"NOR, ({ "danding he", "he", "danding" }) );
        set("race", "野兽");
	set("age", 170);
    set("long", "一只罕见的丹顶鹤，通身雪白，头上的赤顶却是红光闪闪。
却见它左脚被一条铁链拴住，铁链的另一头梆在一块大石上。\n");
    set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "翅膀", "颈部" }) );
	set("verbs", ({ "poke", "claw" }) );
        set("str", 30);
        set("dex", 80);
        set("con", 50);
        set("max_neili", 50);
	set("combat_exp", 150000);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 150);
        set_temp("apply/dodge", 250);
	set_temp("apply/damage", 150);
	set_temp("apply/armor", 100);
	setup();
}

void die()
{
	object ob;
    message_vision("$N凄惨地鸣叫了几声，扑动了几下就不动了。\n", this_object());
	ob = new("/d/baituo/obj/hdh");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
