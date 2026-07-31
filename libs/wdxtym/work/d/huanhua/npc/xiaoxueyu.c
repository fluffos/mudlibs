// xiaoxueyu.c  萧雪鱼

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

//inherit F_DEALER;

void create()
{
	int jibie;
	jibie = 1500;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("萧雪鱼", ({ "xiao xueyu", "xueyu" }));
        set("nickname", HIG "凤" NOR);
        set("long", 
                "萧雪鱼是萧西楼的小女儿,平时深受她那几个哥哥的疼爱,是个聪明伶俐的姑娘。\n"
                "萧雪鱼负责凤组,她的手下全是浣花剑派的女弟子.\n");
        
        set("gender", "女性");
        set("age", 21);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 50000);
        set("max_jing", 15000);    
        set("neili", 100000);
        set("max_neili", 2000);
        set("jiali", 500);
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

        create_family("浣花剑派", 3, "女弟子");
        set("chat_chance_combat", 40);
        setup();

           carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/cloth/cloth")->wear();

}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="女性")
   {
                message_vision("萧雪鱼歪着头想了想, 说道：“好吧, 我就收下你了。”\n",ob);
                 command("recruit " + ob->query("id"));
                if((string)ob->query("class") != "swordsmanr")
                 ob->set("class", "swordsman");
       return;
}
   else
      {
                message_vision("萧雪鱼笑嘻嘻地说道：“我看你是找错了人吧?”\n",ob);
       return;}
}
