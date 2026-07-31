// xiaoren.c  萧韧

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	int jibie;
	jibie = 1500;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("萧韧", ({ "xiao ren", "ren" }));
        set("nickname", HIR "鹰" NOR);
        set("long", 
                "这是个年约3０的青年，消瘦的身材,一双机敏的眼睛不停地扫视着左右。\n"
                "他所负责的鹰组,担负着浣花剑派的侦察工作。\n");
        set("gender", "男性");
        set("age", 29);
        set("attitude", "peaceful");
        create_family("浣花剑派", 3, "弟子");
        set("chat_chance_combat", 40);
        set("no_get",1);
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 50000);
        set("max_qi", 50000);
        set("max_jing", 50000);
        set("neili", 300000);
        set("max_neili", 2000);
        set("jiali", 1000);
        set("combat_exp", 14000000);
        set("score", 30000);

        set_skill("force", 500+jibie/3+random(jibie/5));
        set_skill("unarmed",500+jibie/3+random(jibie/5));
        set_skill("dodge", 500+jibie/3+random(jibie/5));
        set_skill("parry",500+jibie/3+random(jibie/5));
        set_skill("sword", 500+jibie/3+random(jibie/5));
        set_skill("literate", 500+jibie/3+random(jibie/5));
        set_skill("strike",500+jibie/3+random(jibie/5));

        set_skill("huanhua-jian",500+jibie/3+random(jibie/5));
        set_skill("tiexian-quan",500+jibie/3+random(jibie/5));
        set_skill("guiyuan-dafa",500+jibie/3+random(jibie/5));
        set_skill("feihua-wuping",500+jibie/3+random(jibie/5));

         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");

         create_family("浣花剑派", 3, "弟子");
        set("chat_chance_combat", 40);
        setup();

     carry_object("/clone/weapon/changjian")->wield();
     carry_object("d/huanhua/obj/ccloth")->wear();    
     }

void attempt_apprentice(object ob)
     {
        if ((int)ob->query_dex() > 24) 
         {
        message_vision(HIY"萧韧拍了拍$N的肩膀，满意地看着笑了笑!\n"NOR,ob);
              command("say 好吧！我就收下你做我的弟子了。");
                command("recruit " + ob->query("id"));

                //if( (string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
                ob->set("title","浣花剑派鹰组弟子");
        return ;
            }
       else
               message_vision(HIC"萧韧盯着$N看了老半天，叹了口气道:你的身体条件不适合学我的功夫!\n"NOR,ob);
               return ;

}