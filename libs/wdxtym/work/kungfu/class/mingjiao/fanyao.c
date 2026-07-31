// FanYao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
	set_name("范遥", ({ "fan yao", "fan", "yao" }));
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
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

        set("max_qi", 3500);
        set("max_jing", 150000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 1500);
        set("combat_exp", 100000000);
        set("score", 800000);

        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("cuff", 220);
        set_skill("hand", 220);
        set_skill("claw", 220);
        set_skill("strike", 220);
        set_skill("literate", 150);

        set_skill("shenghuo-xinfa", 220);
        set_skill("lingxu-bu", 220);
        set_skill("shenghuo-quan", 220);
        set_skill("guangming-zhang", 220);
        set_skill("liehuo-jian", 220);
        set_skill("nianhua-zhi", 220);
        set_skill("sanhua-zhang", 220);
        set_skill("fengyun-shou", 220);
        set_skill("longzhua-gong", 220);
        set_skill("buddhism", 340);
        set_skill("martial-cognize", 220);

        map_skill("force", "shenghuo-xinfa");
        map_skill("dodge", "lingxu-bu");
        map_skill("strike", "guangming-zhang");
        map_skill("sword", "liehuo-jian");
        map_skill("parry", "liehuo-jian");
        map_skill("cuff", "shenghuo-quan");

        prepare_skill("cuff", "shenghuo-quan");
        prepare_skill("strike", "guangming-zhang");
        set_temp("apply/attack", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 150);
	   
	set("inquiry", ([
		"光明圣火阵"  : (: ask_me :),
		"明教圣火阵"  : (: ask_me :),
		"圣火阵"      : (: ask_me :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: prepare_skill("finger", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );
	create_family("明教", 34, "光明右使");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "fanyao.h"
