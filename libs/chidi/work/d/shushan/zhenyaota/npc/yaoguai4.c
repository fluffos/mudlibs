//yaoguai.c by yushu@SHXY 2001.1
inherit BHNPC;
#include <ansi.h>
void create()
{
       set_name("Ñı¹Ö", ({"yao guai", "guai"}));
       set("long", "ÕòÑıËşÀï±»¹Ø×ÅµÄÑı¹Ö¡£\n");
       set("age", 32);
       set("attitude", "aggressive");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 1500000+random(100000));
         set("max_jingli",2000 );
         set("max_neili",2000 );
         set("neili",2000 );
         set("jingli",2000 );
         set("jiali",2000 );
       set("max_qi", 3000+random(2000));
       set("max_jing", 3000+random(2000));
       set("neili", 4000);
       set("max_neili", 4000);
       set("jiali", 100+random(50));
         set_skill("shushan-force", 150+random(60));
      set_skill("songhe-sword", 150+random(60));
       set_skill("dodge", 150+random(60));
       set_skill("literate", 150+random(60));
       set_skill("sword", 150+random(60));
       set_skill("force", 150+random(60));
       set_skill("parry", 150+random(60));
       set_skill("xiaoyaoyou", 150+random(60));
       map_skill("dodge", "xiaoyaoyou");
          map_skill("parry", "songhe-sword");
          map_skill("sword", "songhe-sword");
       map_skill("force", "shushan-force");
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
       }) );
       setup();
         carry_object("/clone/weapon/gangjian")->wield();
}
void die()
{
     object ob;
     ob = query_temp("last_damage_from");
     ob->add("combat_exp",10000);
     ob->add("potential",10000);
     message("system",HIC"¡¼"HIW"ÕòÑıËş´«Ñ¶"HIC"¡½"HIY+ob->query("name")+HIG"É±ËÀ[1;37mÕòÑıËş[1;32mÀïµÄÑı¹Ö£¬ÊÜµ½½±Àø£¡[2;37;0m\n"NOR,users());    
     tell_object (ob,"ÄãÓ®µÃÁË"+chinese_number(10000)+"µãÎäÑ§"+
                               "+chinese_number(1*0000)+"µãÇ±ÄÜ£¡\n");

        ::die();
}
