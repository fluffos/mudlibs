// zhu.c 朱熹
// CLEANSWORD 1996/2/2

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("夫子", ({ "fu zi", "fuzi", "zi"}));
	set("long", "夫子是扬州城最有学问的人，学生中不少人在朝中为官。\n");
	set("gender", "男性");
	set("age", 55);
	set_skill("literate", 200);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);

	set("combat_exp", 10000);
	set("shen_type", 1);
  
	setup();
    carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob)
{
     return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 1000) 
        {
           message_vision("夫子道：“无欢说了，现在推行免费义务教育，免收一切学费”。\n", who);        
        }       
        return 0;
}
