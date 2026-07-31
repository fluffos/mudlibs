// xiaogang.c  萧刚

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
//inherit F_DEALER;

void create()

{
	int jibie;
	jibie = 1500;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("萧刚", ({ "xiao gang", "gang" }));
        set("nickname", HIY "虎" NOR);
        set("long",       "萧刚是萧家四组中武功最好的一个弟子,他年约30，整个人站在那里安安稳稳,让人觉得十分靠。\n"
                "他所负责的虎组,是浣花剑派的机动力量,属下弟子也是全能型的人物。\n");
        set("gender", "男性");
        set("age", 29);
        set("attitude", "peaceful");
        
        set("no_get",1);
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 100000);
        set("max_jing", 75000);
        set("neili", 700000);
        set("max_neili", 2000);
        set("jiali", 1000);
        set("combat_exp", 40000000);
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
          carry_object("/d/huanhua/obj/ccloth")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() > 24) {
        message_vision(HIY"萧刚拍了拍$N的肩膀，满意地看着笑了笑!\n"NOR,ob);
              command("say 好吧！我就收下你做我的弟子了。");
                command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
                ob->set("title","浣花剑派虎组弟子");
        return ;
            }
       else
               message_vision(HIC"萧刚盯着$N看了老半天，叹了口气道:你的身体条件不适合学我的功夫!\n"NOR,ob);
               return ;
}