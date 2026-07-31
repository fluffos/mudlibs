#include <ansi.h>
inherit NPC;



void create()
{
    set_name("金兵", ({ "jinbing", "bing" }));
    set("gender", "男性" );//性别与上面对应
        set("long",
"一个全身披挂的金兵。\n");
        //set("attitude", "aggressive");
        //set("vendetta/authority",1);
	set("nickname",HIC"金国士兵"NOR);
  set("force_factor",2+random(190));
  set("max_qi",1300+random(390));
  set("max_jing",1300+random(390));
  set("max_sen",1300+random(390));
  set("max_neili",1300+random(390));
  set("eff_neili",1300+random(390));
  set("neili",1300+random(390));
  set("max_mana",300+random(390));
        set("per", 1);
        set("age", 22);
        set("shen", -1000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 100000+random(3150000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.fanzhuan" :),
                (: perform_action, "club.huimaqiang" :),
                (: random_move :),
         }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "金兵喝道：杀啊的！！\n",
                "金兵笑道：这次一定要消灭南蛮!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 10+random(300));
        set_skill("club", 10+random(300));
        set_skill("parry", 10+random(300));
        set_skill("dodge", 10+random(300));
        set_skill("zhong-qiang", 10+random(300));
        
	map_skill("club", "zhong-qiang");
	map_skill("parry", "zhong-qiang");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20);

        setup();

	carry_object("/d/city/obj/tiejia")->wear();
        carry_object("/clone/weapon/changqiang")->wield();
	add_money("silver", random(50));
}
