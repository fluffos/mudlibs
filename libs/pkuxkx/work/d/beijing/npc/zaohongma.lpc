//枣红马
#include <ansi.h>
inherit NPC_TRAINEE;

void create()
{
        set_name(RED"枣红马"NOR, ({"zaohong ma", "ma", "zaohong"}));
	set("race", "马类");
        set_max_encumbrance(50000);
        set("long", "一匹骏马，全身火红，无一根杂毛。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，一摆头向旁边走去！");
	set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
	set("msg_trained","$n低鸣一声，走到$N身边挨挨擦擦，显得十分高兴！");
	set("ride_msg","神采奕奕地骑");
	set("wildness", 20);
	set("combat_exp", 2000);

	set("max_qi", 6000);
	set("qi", 6000);
        set("chat_chance", 3);
        set("chat_msg", ({
                RED"枣红马"NOR"抖抖长毛，扬颈「吁嘘嘘」一阵嘶鸣。\n",
                RED"枣红马"NOR"扯了扯缰绳，然后不耐地在地上刨着蹄子。\n",
        }) );

        setup();
}