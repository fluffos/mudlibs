#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
void create()
{
   set_name("包惜弱",({"bao xiruo"}));
   set("gender","女性");
   set("long","现在的王妃,当年临安牛家村的扬家嫂子!\n");
   set("mingwang",6000);
   set("combat_exp",6000);
   set("title","王妃");
set("str",30);   
set("per",30);
set("age",38);
   set("jing",5800);
   set("max_jing",5800);
set("env/wimpy", 40);
   set("qi",5800);
   set("max_qi",5800);
set("food",550);
set("water",550);
   set("neili",3000);
   set("max_neili",3000);

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("club",130);
   set_skill("literate",120);
   set("inquiry",([
   "扬铁心":"铁心,你知道?可惜他过世快十八年了!\n",
   "扬康":"这几天不知怎的,老爱往后院跑!\n",
   "铁枪":"是我丈夫遗留下来的,可不能给你.\n",
        "逃离" : (:ask_huijia:) ,
        "到了" : (:ask_daojia:) ,
  ]));
   setup();
   add_money("silver",6);
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/haltspear");
}
void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("book5222") )
	this_player()->start_busy(1);

}



string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(!me->query_temp("book5222") )
return "我不需要护送。\n";
if((int)me->query("jinyong/book5")>=2)
return "我不需要护送。。\n";
me->set_temp("lingsong",1);
set_leader(me);
ob->set_leader(me);
ob->set("lingsong",10);
return "多谢大侠相送小妇人去见我那可怜的夫君.\n";
}

string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp;
	int i;
	object fang,who,where;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);

if(me->query_temp("book5222") == 0 )
return "我不需要护送。\n";
if(me->query_temp("lingsong") == 0 )
return "我不需要护送。。\n";



 if( environment(ob)->query("short")=="比武招亲")
         {


    

          set_leader(0);
          write("终于到铁心身边了.\n");


             me->set_temp("book522",1);
             me->set_temp("book5222",0);
             me->set_temp("lingsong",0);
             me->apply_condition("menggu_song",0);
        call_out("leavet",1);
	  
           return "多谢相送. \n";  
      }
        else {
                return "还没到呢!你想不管了吗?\n";
        }
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用guard！\n");
        return 1;
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	