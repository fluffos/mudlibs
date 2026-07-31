//NPC /d/henshan/npc/tian.c
#include <ansi.h>
inherit NPC;

void create()
{
	seteuid(getuid());
	set_name("田伯光", ({ "tian boguang", "tian" }));
        set("title","采花淫贼");
        set("nickname",HIY"千里采花我独行"NOR);
        set("long", 
                "他就是江湖第一淫贼。\n"
                "一个身材中等的壮年男子，眉梢眼角处处留出淫亵之意，不时朝你瞟过几眼。\n");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);

        set("per", 23);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("pubmaster",1);
	set("qi", 20000);
	set("max_qi", 20000);
	set("jing", 20000);
	set("max_jing", 20000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 10);

	set("combat_exp", 3500000);
	set("score", 40000);

	set_skill("blade", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("force", 220);
	set_skill("lingxu-bu", 220);
	set_skill("touch", 220);
	set_skill("kuangfeng-blade", 220);
         
	map_skill("cuff", "touch");
	map_skill("unarmed", "touch");
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "blade.kuang" :),
		
	      }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"田伯光笑道：尼姑也没关系嘛，蓄起头发，两个月就是小美人了。\n",
                "田伯光叹道：“自从惹了不戒那秃驴，日子真是难过，东躲西藏，不知何日可以再。\n",
                "田伯光仰首望望天，：“谁能帮我找个妞就好了。\n",
                 "田伯光垂头丧气地说：“也不知道丽春院近来又有了什么新货色。\n",
                 "田伯光忽然精神一振：“前几天路过山下小村，那个叫翠翠的长的可真他妈的不赖。\n",
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
