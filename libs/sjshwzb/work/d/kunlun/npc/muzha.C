//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("金吒", ({"jin zha","zha"}));
       set("long","昆仑派第三代弟子。\n");
       set("title", HIG"昆仑山玉虚洞第三代弟子"NOR);
       set("gender", "男性");
       set("age", 17);
       set("class", "kunlun");
       set("attitude", "friendly");
       set("rank_info/respect", "仙人");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("sen", 1000);
       set("kee", 1000);
       set("max_gin", 1000);
       set("max_force", 1000);
       set("max_mana", 1000);
       set("mana", 1000);
       set("force", 1000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 800000);
       set("daoxing", 1200000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 120);
       set_skill("literate", 120);
       set_skill("dodge", 120);
       set_skill("force", 120);
       set_skill("parry", 120);
       set_skill("sword", 120);
       set_skill("spells", 120);
       set_skill("xuanzong-force", 120);
       set_skill("wugou-jian", 120);
       set_skill("lingyunbu", 120);
       set_skill("yuxu-spells", 120);
       set_skill("kaitian-zhang", 120);
       map_skill("sword", "wugou-jian");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("dodge", "lingyunbu");
       map_skill("force", "xuanzong-force");
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "jinding-zhang");
       create_family("昆仑山玉虚洞", 3, "弟子");

setup();

           carry_object("/obj/cloth")->wear();
           carry_object("/d/obj/weapon/sword/changjian")->wield();
        
}

void attempt_apprentice(object ob)

   {
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) + "多加努力，把我们昆仑派发扬光大。\n");
        command("recruit " + ob->query("id") );
        message("system", HIY"昆仑派又多了一个弟子  "+this_player()->name()+HIW"
                     昆仑派的势力加强了。\n"NOR,users());
        ob->set("title", HIM"昆仑派入门弟子"NOR);
        ob->set("class","kunlun" );


   return;
}


