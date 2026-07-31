inherit NPC;
#include <ansi.h>
int ask_job2();
void create()
{
   set_name("童年郭靖",({"guo jing"}));
   set("gender","男性");
   set("long","郭靖出生在蒙古,随江南六怪学艺!\n");
   set("shen",50000);
   set("combat_exp",100000);
   
set("age",17);
   set("qi",1900);
   set("max_qi",1900);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
	set_skill("club", 40);
	set_skill("zhongping-qiang", 40);
   set_skill("whip",80);
   set_skill("sword",80);
   set_skill("blade",80);
        set("inquiry", ([
        "母亲" : (:ask_job2:) ,
         ]) );
   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/jindao")->wield();
}


int ask_job2()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        if(((int)me->query("jinyong/book5")>1))
           {
                      message_vision("$N对着$n说道。谢谢你送我母亲回来。\n", this_object(), me);
	                      return 1;
            }

        if(!me->query_temp("book511"))
           {
                      message_vision("$N对着$n说道。你是谁啊？你见过大汗了吗?\n", this_object(), me);
	                      return 1;
            }    

        if(me->query_temp("book512"))
           {
                      message_vision("$N对着$n说道。我母亲接回来了吗?\n", this_object(), me);
	                      return 1;
            }                      

                command("thank " + me->query("id"));
                command("say " + RANK_D->query_respect(me) + " 我母亲被段天德抓到牛家村去了。");
                command("say " + RANK_D->query_respect(me) + " 能否帮我教教我母亲回到郭家茅屋? \n" NOR);
                me->set_temp("book512", 1);
                me->set("quest/quest_type", "护送");
                me->set("quest/quest", "郭母");
                me->set("task_time", time() + 580);
                me->apply_condition("menpai_busy",22);
                ob = new(__DIR__"liping",1);
                ob->move("/d/jiaxing/guojia");
                ob->set("combat_exp", me->query("combat_exp"));
                return 1;
                           
}