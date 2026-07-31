// sheep.c

inherit NPC;

void create()
{
        set_name("小羊羔", ({ "sheep" }) );
        set("race", "野兽");
        set("age", 3);
	set("max_kee", 600);
        set("long", "一只全身雪白的的绵羊。\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 25000);

        setup();
}
