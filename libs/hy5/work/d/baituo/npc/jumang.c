inherit NPC;
void create()
{
    set_name("巨蟒", ({ "ju mang", "mang" }) );
	set("race", "野兽");
	set("age", 70);
    set("long", "一条五丈来长的蟒！！！\n");
    set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "尾巴", "躯干" }) );
	set("verbs", ({ "bite" }) );
        set("str", 190);
        set("con", 190);
	set("combat_exp", 350000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 300);
	setup();
}

