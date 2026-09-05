//玉骢马
#include <ansi.h>
inherit NPC_TRAINEE;

void create()
{
        set_name(MAG"紫骝马"NOR, ({"ziliu ma", "ma", "ziliu"}));
	set("race", "马类");
        set_max_encumbrance(50000);
        set("long", "这是一匹紫骝宝马，日行千里，夜行八百。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，一摆头向旁边走去！");
	set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
	set("msg_trained","$n低鸣一声，走到$N身边挨挨擦擦，显得十分高兴！");
	set("ride_msg","神采奕奕地骑");
	set("wildness", 20);
	set("combat_exp", 2000);

	set("max_qi", 6000);
	set("qi", 6000);
        set("chat_chance", 5);
        set("chat_msg", ({
                MAG"紫骝马"NOR"「吁嘘嘘」一阵嘶鸣，不停地踢着脚掌。\n",
                MAG"紫骝马"NOR"的长尾巴很不老实地不停地甩来甩去。\n",
        }) );

        setup();
}