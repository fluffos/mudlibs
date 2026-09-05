#include <ansi.h>

inherit NPC;


void heal();
void create()
{
        set_name("俞岱岩", ({ "yu daiyan", "yu" }));
       set("nickname", RED "武当三侠" NOR);
        set("long",
                "他就是张三丰的三弟子俞岱岩。\n"
                "他今年四十五岁，中等身材，气度潇洒。\n"
                "虽在武当七侠中排名第三，功夫不凡。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 180000);
        set("score", 100000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 90);
        set_skill("taiji-shengong", 70);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 90);
           set_skill("cuff", 90);
        set_skill("taiji-quan", 60);
	set_skill("move", 90);
        set_skill("parry", 110);
        set_skill("sword", 110);
        set_skill("taiji-jian", 80);
        set_skill("taoism", 80);
        set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
             map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}



void init()
{

        object me;
       

        ::init();

       if(interactive(me=this_player())&&!is_fighting() ) 
       {
            remove_call_out("greeting");
            call_out("greeting",3,me);
            return;
       }
 }
 void greeting(object me)
  {
    if(!me||environment(me)!=environment() ) return;
     command("say 全真教今日如此昌盛,我武当派特派我来向全真学习");
     command("smile");
 }            

void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
		command("enforce 50");
                return;
        }

        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}
