inherit NPC;
void create()
{
        set_name("白兔", ({ "bai tu", "tu" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只雪白的小白兔，可爱之致。\n");
        set("attitude", "peaceful");
        set("str", 15);
        set("cor", 16);
        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" ,"claw"}) );
        set("combat_exp", 200);
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
        set_temp("apply/defence",5);
        set("shen_type",1);set("score",200);setup();
}
 
void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
	ob = new("/d/guiyunzhuang/npc/turou");
        ob->move(environment());
	destruct(this_object());
}
