// NPC : /d/wudang/npc/yezhu.c 野猪

inherit NPC;
void create()
{
        set_name("野猪", ({ "ye zhu","zhu" }) );
        set("race", "野兽");
        set("age", 6);
        set("con", 100);
        set("str", 100);
        set("long", "一只眼睛血红的野猪。\n");
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 250000);
	 set_temp("apply/attack", 30);
	 set_temp("apply/defense", 50);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        setup();
}

void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
        ob = new(FOOD_D("yzhurou"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
