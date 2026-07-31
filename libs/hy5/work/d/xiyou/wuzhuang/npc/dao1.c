
// lestat 2001


#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
            set_name("上清道人",({"shangqing"}));
                set("title", MAG"上清道人"NOR);
//        set("gender","男性");
//        set("age", 60);
        set("str", 40);
        set("cor", 30);
                set("con", 30);
                set("cps", 30);
                set("spi", 30);
                set("int", 30);
//        set_temp("apply/damage", 125);
//        set_temp("apply/armor", 500);
            set_skill("unarmed", 100);
       
   set("combat_exp", 1000000);
   create_family("五庄观", 2, "弟子");

   setup();
   initlvl((200+random(280)),15);
   carry_object("/d/obj/cloth/baguapao")->wear();
   carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void copy_status(object me,object ob)
{
  
   me->set("max_qi",ob->query("max_qi"));
   me->set("eff_qi",ob->query("eff_qi"));
   me->set("qi",ob->query("qi"));

   me->set("max_jing",ob->query("max_jing"));
   me->set("eff_jing",ob->query("eff_jing"));
   me->set("jing",ob->query("jing"));

   me->set("max_jing",ob->query("max_jing"));
   me->set("eff_jing",ob->query("eff_jing"));
   me->set("jing",ob->query("jing"));

   me->set("max_neili",ob->query("max_neili"));
   me->set("neili",ob->query("neili"));
   me->set("force_factor",ob->query("force_factor"));

   me->set("max_neili",ob->query("max_neili"));
   me->set("neili",ob->query("neili"));
   me->set("mana_factor",ob->query("mana_factor"));
   me->set("combat_exp",ob->query("combat_exp"));

}

void die()
{
        message("vision",
                MAG "但听一声钟响，上清"+ name() + "身子一晃，化成一股紫气冲天而去。\n" NOR,environment(),
                this_object() );
        destruct(this_object());
}

int heal_up()
{
           if( environment() && (!is_fighting())  ) 
                   {
                call_out("die", 1);
                return 1;
               }
  
   add("time", 1);
        return ::heal_up() + 1;
}

void invocation(object who)
{
   int i;
   object me,*enemy;

   me=this_object();
   message("vision",
     MAG +who->query("name")+"唱道:

         『混元初判道如先，常有常无得自然；紫气东来三万里，函关初度五千年。』

         只听得正东上一声钟响，顿时眼前出现一位"+who->query("name")+"！\n" NOR,
     environment(),this_object());
   copy_status(me,who);
   enemy=who->query_enemy();
   i=sizeof(enemy);
   while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
   set("leader", (string)who->query("id"));
        set_leader(who);
}




