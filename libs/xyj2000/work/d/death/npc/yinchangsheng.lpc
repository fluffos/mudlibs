// cracked by vikee 2/09/2002   vikee@263.net
// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("阴长生", ({ "yin changsheng", "yin", "changsheng" }));
        set("long","阴长生本是个落弟秀才，后在丰都山修练成仙，御封「阴王」。\n");
        set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "寂灭司主");
	set("nickname", "阴王");
        set("combat_exp", 800000);
  set("daoxing", 400000);

        set("max_gin", 1400);
        set("max_kee", 1400);
        set("max_sen", 1400);
	set("class", "youling");
	set("force", 2500);
	set("max_force", 1500);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 2500);
	set("mana_factor", 100);

	set_skill("literate", 100);
	set_skill("ghost-steps", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
	set_skill("parry", 120);
	set_skill("spells", 120);
	set_skill("gouhunshu", 80);
	set_skill("jinghun-zhang", 120);
	set_skill("force", 120);
	set_skill("tonsillit", 80);
	set_skill("sword", 120);
	set_skill("zhuihun-sword", 120);
	
	map_skill("sword", "zhuihun-sword");
	map_skill("parry", "zhuihun-sword");
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
        set("chat_msg_combat", ({
//                (: exert_function, "powerup" :),
                (: exert_function, "sheqi" :),
                (: cast_spell, "gouhun" :),
        }) );


        set("nkgain", 400);

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


create_family("阎罗地府", 2, "你好");

        setup();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	carry_object("/d/obj/cloth/choupao")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
       command("recruit " + me->query("id") );
        me->set("class", "youling");
	return;
}
/*
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
		ob->set("title", "地府招魂司阴兵");
}

*/

