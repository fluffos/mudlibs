// benguan.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("本观", ({ "ben guan","guan"}) );
	set("gender", "男性" );
	set("long", "一个枯黄精瘦的僧人，他是本因方丈的师兄。\n");
	set("title", "天龙寺第十七代僧人");
	set("class", "bonze");
	set("age", 47);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 12500);
	set("max_qi", 12500);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 100);
	set("combat_exp", 1800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("sword", 120);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 120);
        set_skill("sun-finger", 100);
	set_skill("duanjia-sword", 120);
	set_skill("six-finger", 250);
	set_skill("buddhism", 100);
	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
	set("book_give", 1);
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("unarmed", "six-finger");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
(: perform_action, "unarmed.liumaijingshen" :),
	(: perform_action, "unarmed.qi" :),
		(: perform_action, "unarmed.zongheng" :),
                  (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
	create_family("大理段家",17,"高僧");
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 280);
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}
#include "ben.h"
