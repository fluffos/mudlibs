#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("萧之羽", ({ "xiao zhiyu", "xiao" }) );
        set("long",
                "太湖水军统领，负责太湖水军的日常调度和训练。\n");
	set("nickname", CYN"五湖龙王"NOR);
        set("attitude", "heroism");
	set("student_title","官员");
	create_family("朝廷",6,"官员");
	set("title", "太湖水师统领");
	set("vendetta_mark", "authority");
	set("age", 43);
	set("str", 50);
	set("int", 30);
	set("cor", 30);
	set("spi", 30);
	set("agi", 30);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("max_sen", 1000);
	set("kee", 1000);
	set("gin", 1000);
	set("sen", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 20);
        set("score", 90000);
	set_temp("apply/attack", 130);
	set_temp("apply/defense", 130);
	set_temp("apply/move", 130);

        set("combat_exp", 3500000);
        set_skill("unarmed", 200);

	set_skill("force",180);
        set_skill("parry", 120);
        set_skill("dodge", 110);
        setup();

        carry_object("/clone/weapon/tiejia")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

