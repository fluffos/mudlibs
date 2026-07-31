#include <ansi.h>
inherit NPC;

void create()
{
        set_name(BLU"大蟒蛇"NOR, ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只有着巨大三角形脑袋的蛇，身体粗壮。\n");
        set("attitude", "peaceful");

		set("can_speak",0);

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 3000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 6);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()))
        call_out("kill_ob", 1, ob); 
}
void die()
{
        object ob;
        message_vision("$N痛苦地挣扎了几下！$N死了。\n", this_object());
        destruct(this_object());
}


mixed hit_ob(object me, object ob, int damage_bonus, int factor)
{
		ob->apply_condition("snake_poison", random(20) + 10 +
			ob->query_condition("snake_poison"));
	
}