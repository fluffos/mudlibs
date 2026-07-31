// buck.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(YEL"梅花雌鹿"NOR, ({ "meihua cilu", "doe", "lu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只温驯的梅花雌鹿，正在低头吃草。\n");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "鹿头", "鹿身", "前腿", "后腿", "臀部" }) );
        set("verbs", ({ "hoof" }) );

        set("combat_exp", 2000);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 10);

        setup();
}
