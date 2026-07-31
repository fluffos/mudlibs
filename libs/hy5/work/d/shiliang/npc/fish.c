// animal: eat_fish.c
// Jay 3/18/96

inherit NPC;

void create()
{
	set_name("噬人鱼", ({ "fish", "yu" }) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 3);
	set("long", "这是一只身形并不很大的鱼，浑身覆满绚丽的鳞片，\n"
	    "一口锋利的牙齿，正虎视耽耽的看着你\n");
	set("attitude", "aggressive");
        set("max_qi",1000);
	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "头部", "身体", "腹部", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 1000000);
	set("neili", 300);
	set("max_neili", 300);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	
//	set_temp("apply/attack", 45);
//	set_temp("apply/damage", 60);
//	set_temp("armor", 53);
	setup();
}

//void die()
//{
//	object ob;
//	message_vision("$N口中吐出一颗夜明珠，肚皮往上一翻，$N死了。\n", this_object());
//	ob = new("d/npc/m_weapon/tan/item/zhenzhu");
//	ob->move(environment(this_object()));
//	destruct(this_object());
//}
