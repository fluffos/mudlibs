// zine中原有的，江南也有
#include <ansi.h>
inherit NPC;
#include "/d/city/npc/smith.h"
void create()
{
        set_name("伙计", ({ "huo ji" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "这是临安府打铁铺的一个伙计，负责买卖兵器。\n");
       set("no_accpet", 1);
		set("boss_id","becool");
		set("boss_name","虫二");

	set_skill("unarmed", 300);
	set_skill("blade", 400);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set("forging",350);
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 200);
	set("inquiry", ([
                "name" : (: ask_here :),
                "锻造" : (: ask_forge :),
                "forge" : (: ask_forge :),
                "定价" : (: ask_adjust :),
                "adjust" : (: ask_adjust :),
                "生意" : (: ask_business :),
                "business" : (: ask_business :),
                "收购" : (: ask_buy :),
                "buy" : (: ask_buy :),
        ]));
        setup();
		carry_object("clone/cloth/cloth")->wear();
}
