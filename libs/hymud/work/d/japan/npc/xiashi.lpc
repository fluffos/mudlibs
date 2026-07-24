//xiashi
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("侠士", ({ "xiashi","man","xia"}));
	set("gender", "男性");
	set("age", 40);
	set("long", "一个出来闯荡江湖的侠士，看上去已是饱经风霜的老江湖了\n");

 	set("str" ,40);
	set("combat_exp", 3000);
	set("mingwang",1);
	set("attitude", "peaceful");
	

        set("chat_chance", 10);
        set("chat_msg", ({
	HIR"[B侠士剑眉一扬，说道：江湖上行的就是一个义字。\n"NOR,
	HIY"侠士抚剑长叹道：所谓人在江湖，身不由己啊！\n"NOR,
	HIG"侠士自言自语：江湖险恶，一切都要自己处处小心 \n"NOR,
	}));
	set_skill("literate" ,30);
	set_skill("parry" ,20);
	set_skill("unarmed", 20);
	set_skill("dodge", 30);
	set_temp("apply/attack", 15);
	set_temp("apply/defense",30);
	setup();
    carry_object("/clone/misc/cloth")->wear();
carry_object("/clone/weapon/gangjian")->wield();
        add_money("silver",20); 
}
