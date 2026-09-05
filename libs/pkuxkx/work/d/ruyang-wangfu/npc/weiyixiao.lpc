//weiyixiao.c -- 青翼蝠王-韦一笑
//Zone: 汝阳王府
//Create by ddid
//2009-6-18

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("韦一笑", ({ "wei yixiao", "wei", "yixiao", "fuwang" }));
	set("long", 
						"他生得削腮尖嘴，脸上灰扑扑的无半点血色。\n一件青色的大斗篷把他的身体完全裹住了。\n");

	set("gender", "男性");
	set("age", 45);

	set("nickname", CYN "青翼蝠王" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("shen_type", -1);
  set("shen", 10000);
	set("attitude", "peaceful");	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 35);
	set("per", 18);

	set("combat_exp", 1000000);
			set_skill("unarmed", 300);
			set_skill("force", 300);
			set_skill("parry", 300);
			set_skill("dodge", 300);
			set_skill("sword", 300);
			set_skill("blade", 300);
			set_temp("apply/attack", 200);
			set_temp("apply/defense", 200);
			set_temp("apply/armor", 200);
			set_temp("apply/damage", 200);

			set("neili", 6000); 
			set("max_neili", 6000);
			set("jiali", 300);

	setup();
	
	carry_object(__DIR__"obj/qingse-doupeng")->wear();
}
