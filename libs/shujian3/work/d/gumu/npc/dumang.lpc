// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
	set_name("毒蟒", ({ "du mang", "mang" }));
	set("race", "野兽");
	set("age", 20);
        set("long", "一条庞大无比, 色彩斑斓的巨蟒。浑身发出阵阵强烈的腥臭味。\n");
	set("attitude", "aggressive");
	set("str", 70);
	set("con", 50);
	set("max_qi", 800);
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 200000);

	set_temp("apply/attack", 150);
	set_temp("apply/armor", 150);
	setup();
}
 
void die()
{
	int i;
	object ob;
	object me = query_temp("last_damage_from");
	object *inv;

	inv = deep_inventory(me);
	i = sizeof(inv);
	message_vision("\n$N抽搐了几下，身体缩在一起，死了。\n", this_object());
	while (i--)
	if( inv[i]->query("drug") || !userp(me)){
		destruct(this_object());
		return notify_fail("");
	}
	ob = new(MEDICINE_D("neili/gshedan"));
	ob->set("owner", me->query("id"));
	message_vision("\n$N弯腰拾起了一颗$n。\n",me, ob);
	log_file("quest/neili",sprintf("%-18s杀死毒蟒，得到%s。\n",
		me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
	ob->move(me);
	destruct(this_object());
}
