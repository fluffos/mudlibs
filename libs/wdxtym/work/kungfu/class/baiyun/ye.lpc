// dongfang.c
//Updated by y111

#include <ansi.h>


inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

string ask_book();
mixed ask_pfm();

void create()
{
	set_name(RED"叶孤城"NOR, ({ "ye gucheng", "ye","gucheng" }) );
    set("nickname", HIY "剑神" NOR);
    set("gender", "男性");
    set("shen_type", 1);
    set("age", 33);
    set("long",
        "他就是剑神叶孤城，白云城城主。
\n");
    set("attitude", "peaceful");

    set("per", 21+random(100));
    set("str", 21+random(100));
    set("int", 30+random(100));
    set("con", 26+random(100));
    set("dex", 30+random(100));
	//自动PFM
	set("auto_perform", 1);

    set("inquiry", ([
        "夜孤城"   : "呵呵 \n",
        "白云城" : "百云孤城\n",
    ]));


    set("qi", 900000);
    set("max_qi", 900000);
    set("jing", 1000000);
    set("max_jing", 1000000);
    set("neili", 450000);
    set("max_neili", 450000);
    set("jiali", 4000);

    set("combat_exp", 25000000);
    set("score", 0);

	
	
	 
	 
    set_skill("parry", 2000);
    set_skill("dodge", 2000);
    set_skill("force", 2000);
    set_skill("literate", 2200);
	set_skill("sword", 2000);
	set_skill("unarmed",2000);
	set_skill("changquan",2000);
	set_skill("feixian-steps",2000);
	set_skill("feixian-sword",2000);
	set_skill("feixian-jian",2000);
	set_skill("jingyiforce",2000);
	set_skill("jingyi-shengong",2000);
    map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-jian");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
	
	
	

	
	
    create_family("白云城", 1, "城主");

    set("master_ob",5);
    
	setup();
     carry_object("/clone/weapon/gangjian")->wield();
    //carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
    carry_object("/d/heimuya/obj/yuxiao");
}

 

void attempt_apprentice(object ob)
{
     
     if((string)ob->query("family/master_name") == "叶孤城")
     {
          command("say 我越看你越不顺眼，快给我滚！");
          return;
     }
     if ((int)ob->query("combat_exp") < 600000)
     {
          command("say 就你这点微末功夫，还是先跟我徒弟多练练吧！");
          return;
     }

     /*if((int)ob->query_skill("feixian-steps", 1) < 50)
     {
          command("say 本门的内功轻身功法你还没练好，还要多下苦功才行！");
          return;
     }*/

     command("xixi");
     command("recruit " + ob->query("id")); 
     command("say 好！好！我白云城又多了一大助力。！");
     ob->set("title", HIR "白云亲传" NOR);
}

