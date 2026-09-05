//Cracked by Roath
// lt_snake.c 两头蛇 ( ??? )
// by maco

#include <ansi.h>

inherit NPC;
#include "/d/baituo/npc/snake2.h"
int auto_perform_double();

void create()
{
	int poison = 10;
	set_name("两头蛇", ({ "liangtou she", "she", "snake" }) );
	set("race", "蛇类");
	set("age", 100);
	set("long", "这条蛇花纹斑斓，颈子两边分岔，竟然有两个头，极是狰狞。\n据说看到两头蛇的人，一定会死。\n");
	set("attitude", "aggressive");

	set_weight(poison*600 + 9000);
	set("str", 30 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );

	set("max_jing", 4000+random(5000));
	set("max_qi", 4000+random(5000));
	set("max_jingli", 9000);
	set("jingli", 9000);
	set("max_neili", 4000);
	set("neili", 4000);

	set("limbs", ({ "左颈", "右颈", "身体", "七寸", "尾巴" }) );

	set("combat_exp", 1200000);

	set_temp("apply/attack", 700);
	set_temp("apply/damage", 250);
	set_temp("apply/dodge", 200);
	set_temp("apply/armor", 300);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: auto_perform_double :),
	}));

	set("snake_poison", 60 + poison*40 +random(61));
	set("bt_snake", 1);

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( me->query("snake_poison") > 0 && !victim->query("snake_poison"))
		F_POISON->poison_attack(me,victim,"snake_poison", 10 + me->query("snake_poison")/5 +
		victim->query_condition("snake_poison") );
}

#include "snake_perform.h"
