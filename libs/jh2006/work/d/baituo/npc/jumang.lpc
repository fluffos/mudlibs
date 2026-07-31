inherit NPC;
void create()
{
    set_name("巨蟒", ({ "ju mang", "mang" }) );
	set("race", "野兽");
	set("age", 70);
    	set("long", "一条五丈来长的蟒！！！\n");
    	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "尾巴", "躯干" }) );
	set("verbs", ({ "sweep", "twist", "bite" }) );
        set("str", 190);
        set("max_qi", 20000);
        set("con", 190);
	set("combat_exp", 600000);
	set_temp("apply/attack", 300);
	set_temp("apply/defense", 400);
	set_temp("apply/damage", 400);
	set_temp("apply/armor", 500);
	setup();
}

void die()
{
	object ob;
    	message_vision("$N垂死挣扎了几下就不动了。\n", this_object());
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
