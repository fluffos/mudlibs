// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("署长", ({ "shu zhang", "shu","zhang" }) );
        set("long",
                "神户城中最高的官，有至高无上的权力\n");
	set("nickname", RED"警备署"NOR);
        set("attitude", "heroism");
	set("student_title","官员");
	set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("agi",25);
	set("int",30);
        set("chat_chance_combat", 50);
 
        set("combat_exp", 10000);
	set_temp("apply/damage",100);
        set_skill("unarmed", 200);
	set_skill("sword",100);
	set_skill("force",80);
        set_skill("parry", 120);
        set_skill("dodge", 110);
	setup();
//        carry_object(__DIR__"obj/wushidao")->wield();
//        carry_object(__DIR__"obj/wushidao")->wield();
}

