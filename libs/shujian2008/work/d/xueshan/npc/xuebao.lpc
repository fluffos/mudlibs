// xuebao.c 雪豹
// by iceland
inherit NPC;

void create()
{
	set_name("雪豹", ({ "xue bao","xuebao","bao" }) );
	set("long","一只饥饿的雪豹，浑身上下雪白毛皮中杂着些黄花纹，散发着柔软的光泽。\n");
	set("race", "野兽");
	set("age", 5);

	set("eff_jing", 500);
	set("max_jing",500);
	set("max_qi", 1500);

	set("str", 40);
	set("dex", 40);
	set("con", 25);
	set("int", 20);
	set("unique", 2);

	set("limbs", ({ "头部", "身体", "前腿","后腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw"}) );
        set("attitude","aggressive");
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 20);

	set("combat_exp", 260000);
        set("chat_chance", 1);
	set("chat_msg", ({
(: this_object(), "random_move" :),
"雪豹前腿扒在地上，喉咙里发出低沉的咆哮。\n",
"雪豹冲你裂了裂嘴，长长的牙齿在冷风中闪着寒光。\n",
}) );
        setup();
}
void die()
{
	object ob;
	message_vision("$N嘴角流出了一缕鲜血，腿脚抽搐了几下，死了。\n", this_object());
	ob = new(ARMOR_D("baopi"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
