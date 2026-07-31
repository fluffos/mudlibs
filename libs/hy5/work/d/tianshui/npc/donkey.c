// donkey.c

inherit NPC;

void create()
{
        set_name("毛驴", ({"donkey"}));
        set("race", "野兽");
        set("age", 10);
        set("combat_exp", 10000);
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite"}));

	set("ride",1);

        set("ride_msg", "$N慢腾腾的爬上毛驴。");
	set("unride_msg","$N从驴背上跳下来。");

        set("ride/dodge", 1);
        set_temp("apply/attack", 20);
        set_temp("apply/armor", 40);

        setup();
}