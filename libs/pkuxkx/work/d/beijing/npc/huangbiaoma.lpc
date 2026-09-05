//玉骢马
#include <ansi.h>
inherit NPC_TRAINEE;

void create()
{
        set_name(HIY"黄骠马"NOR, ({"huangbiao ma", "ma", "huangbiao"}));
	set("race", "马类");
        set_max_encumbrance(50000);
        set("long", "这是一匹黄骠骏马，全身金黄，没有一丝杂毛。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，一摆头向旁边走去！");
	set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
	set("msg_trained","$n低鸣一声，走到$N身边挨挨擦擦，显得十分高兴！");
	set("ride_msg","神采奕奕地骑");
	set("wildness", 20);
	set("combat_exp", 2000);

	set("max_qi", 6000);
	set("qi", 6000);
        set("chat_chance", 4);
        set("chat_msg", ({
                HIY"黄骠马"NOR"低下头来，「奚奚嗦嗦」地嚼着干草。\n",
                HIY"黄骠马"NOR"抬头看了看你，继续埋下头吃它的夜草。\n",
        }) );

        setup();
}