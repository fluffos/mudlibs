// YinTianZheng.c
// pal 1997.05.09


#include "fawang.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("殷天镇", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
	"他是一位身材魁梧的秃老者，身穿一件白色长袍。\n"
	"他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。\n"
	);
							  
	set("title",HIG "明教" HIW "白眉鹰王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

        set("max_qi", 5500);
        set("qi", 5500);
        set("jing", 15000);
        set("max_jing", 15000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 1500);
        set("combat_exp", 9000000);
        set("score", 1000000);

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("finger",180);
        set_skill("cuff", 180);
        set_skill("strike", 180);
        set_skill("claw", 220);
        set_skill("literate", 120);

        set_skill("shenghuo-xinfa", 180);
        set_skill("shenghuo-bu", 180);
        set_skill("shenghuo-quan", 180);
        set_skill("guangming-zhang", 180);
        set_skill("liehuo-jian", 180);
        set_skill("sougu-yingzhua", 220);
        set_skill("yinfeng-dao", 220);
        set_skill("tougu-zhen", 220);
        set_skill("martial-cognize", 200);

        map_skill("force", "shenghuo-xinfa");
        map_skill("dodge", "shenghuo-bu");
        map_skill("strike", "guangming-zhang");
        map_skill("sword", "liehuo-jian");
        map_skill("claw", "sougu-yingzhua");
		map_skill("parry", "yinfeng-dao");
		map_skill("finger", "tougu-zhen");
        map_skill("cuff", "pili-quan");
		map_skill("strike", "yinfeng-dao");

        prepare_skill("strike", "yinfeng-dao");
        prepare_skill("finger", "tougu-zhen");
	set_temp("apply/attack", 120);
	set_temp("apply/damage", 120);
	set_temp("apply/unarmed_damage", 120);
	set_temp("apply/armor", 120);
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: command("perform strike.jue") :),
                (: command("perform finger.feng") :),
        }) );
	create_family("明教", 35, "护法法王");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

