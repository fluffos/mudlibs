#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("叶亭", ({ "ye ting", "ye" }) );
        set("long",
                "赤壁水军统领，负责赤壁水军的日常调度和训练。\n");
	set("nickname", YEL"海底捞月"NOR);
        set("attitude", "heroism");
	set("student_title","官员");
	create_family("朝廷",6,"官员");
	set("title", "赤壁水师统领");
	set("vendetta_mark", "authority");
	set("str", 30);
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
	set_skill("dagger",250);
	set_skill("force",180);
        set_skill("parry", 120);
        set_skill("dodge", 110);
        setup();

        carry_object("/clone/weapon/tiejia")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}



