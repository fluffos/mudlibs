// FanYao.c
// pal 1997.05.09

#include "ansi.h"

inherit BHNPC;
inherit F_MASTER;

string ask_me();

void create()
{
    set_name("范遥", ({"fan yao","fan","yao",}));
	set("long",
        "他是一位带发修行的头陀，身穿白布长袍。\n"
        "他的脸上七七八八的全是伤疤，简直看不出本来面目了。\n"
	);

	set("title",HIG "明教" HIR "光明右使" NOR);
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 5000000);
	set("score", 800000);

	set_skill("force", 250);
	set_skill("hunyuan-yiqi", 280);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 230);
	set_skill("unarmed", 270);
	set_skill("strike", 260);
	set_skill("unarmed", 200);
	set_skill("unarmed", 220);
	set_skill("parry", 210);
	set_skill("nianhua-zhi", 280);
	set_skill("sanhua-zhang", 280);
	set_skill("fengyun-shou", 210);
	set_skill("longzhua-gong", 210);
	set_skill("buddhism", 300);
	set_skill("literate", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("unarmed", "fengyun-shou");
	map_skill("unarmed", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	set("inquiry", ([
        "光明圣火阵"     : (: ask_me :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: prepare_skill("unarmed", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}
/*
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}
*/
#include "fanyao.h"
