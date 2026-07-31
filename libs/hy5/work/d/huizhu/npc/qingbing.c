// qingbing.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("绿营清兵", ({ "qing bing","bing" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这是位手执长枪的绿营清兵，满脸凶狠。\n");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

 set("max_qi",3000+random(1690));
  set("max_jing",3000+random(1890));
   set("max_neili",3000+random(1890));
set("neili",5000);
        set("per", 25);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.fanzhuan" :),
                (: perform_action, "club.huimaqiang" :),
        }) );


        set_skill("unarmed", 180+random(180));
        set_skill("club", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("zhong-qiang", 280+random(380));
        set_skill("force", 280+random(380));
        set_skill("taiji-shengong", 280+random(380));
        set_skill("unarmed", 280+random(380));
        set_skill("taiji-quan", 280+random(380));

        map_skill("unarmed", "taiji-quan");
        map_skill("force", "taiji-shengong");
	map_skill("club", "zhong-qiang");
	map_skill("parry", "taiji-quan");
        set_temp("apply/attack", 100);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 850);
        set_temp("apply/damage", 850);

	setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/junfu")->wear();
	add_money("silver", 10);
}
