#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIB "$N说道：喂！新来的，你叫什么名字？\n\n" NOR,
        HIB "$N用奇异的眼光盯着$n，好像要看穿$n的一切似的。\n\n" NOR,
        HIB "$N「哼」的一声，从袖中掏出一本像帐册的东西翻看着。\n\n" NOR,
        HIB "$N合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
        HIB "$N叹道：罢了罢了，你走吧。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了$n。\n\n" NOR,
});

void create()
{
        string *first_name = ({ "秦广","初江","宋帝","仵官","阎罗","平等","泰山","都市","卞城","转轮" }); 

        set_name(first_name[random(sizeof(first_name))]+"王", ({ "ming wang", "ming", "wang" }) );
        set("title",  BLU"十殿冥王之"NOR );
	set("long", "你看不清他的面目，只觉得他身上不带任何喜怒哀乐。\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"一阵阴森的鬼气吹来，吹得殿上的冥灯不住地闪烁着。\n",
"忽然，一阵厉鬼的惨叫从远出传来，听得你毛骨悚然，不住颤抖。\n",
        }) );
        set("age", 3000);
        set("combat_exp", 200000);
        set("max_jing", 1000);
        set("max_qi", 1000);
        setup();
}

#include "death.h";
