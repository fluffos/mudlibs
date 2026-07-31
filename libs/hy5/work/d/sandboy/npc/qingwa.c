// yetu.c 野兔

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIB"青蛙"NOR, ({ "frog", "qingwa", "wa" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "生长在茂密草丛中青蛙,浅绿色的身体上
有着杂黄色的线条。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "舌头" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);

	set("chat_chance", 20);
	set("chat_msg", ({
		(:random_move:),
              HIB"青蛙"NOR+"鼓起白白的肚子,呱呱地喊了两声.\n",
              HIB"青蛙"NOR+"伸出长长的舌头,快速地一沾,把草叶上的一只飞蛾吞入肚中.\n",
              HIB"青蛙"NOR+"呆呆地一动不动,过了会儿,眨了下眼.\n",
              HIB"青蛙"NOR+"用力一蹬,在空中划出一个优美的弧形,跳入旁边的水坑.\n",
	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}
