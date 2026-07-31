#include <ansi.h>
inherit NPC;

string ask_huijia();
string ask_daojia();

void create()
{
   set_name("李萍",({"li ping"}));
   set("long","郭靖的母亲,流落在蒙古!\n");
   set("score",5000);
   set("combat_exp",160000);
set("str",30);   
set("per",30);
set("age",43);
        set("attitude", "friendly");
        set("gender", "女性");
        set("age", 12);
	set("no_get", 1);
   set("jing",5800);
   set("max_jing",5800);
set("env/wimpy", 40);
set("no_get",1);
   set("qi",5800);
   set("max_qi",5800);
set("food",550);
set("water",550);
   set("neili",3000);
   set("max_neili",3000);
   //set("force_factor",10);
        set("inquiry", ([
        "逃难" : (:ask_huijia:) ,
        "到了" : (:ask_daojia:) ,
         ]) );
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("whip",120);

   setup();
   add_money("silver",1);
carry_object(__DIR__"obj/cloth")->wear();
}


void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("book512") )
	this_player()->start_busy(1);
if (ob->query("lingsong") == 0 )
{
        remove_call_out("leave");
        call_out("leave",240);
}
}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "郭靖的母亲见无人来接应,自己离开了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(!me->query_temp("book512") )
return "我不需要护送。\n";
if((int)me->query("jinyong/book5")>=1)
return "我不需要护送。。\n";


      if(!query("iskillok"))
      {
      message_vision("突然从周围杀进了几个金国奸细 说道：陪我去见完颜王爷吧!\n",this_object(),who);	
      	fang = load_object(__DIR__"duantiande");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
return "先对付敌人吧 \n";
      }	

        fang = present("duan tiande",where);
	if(fang)
	{
		who->start_busy(3);
return "先对付敌人吧 \n";
	}





me->apply_condition("menggu_song",35);
me->set_temp("lingsong",1);
set_leader(me);
ob->set_leader(me);
ob->set("lingsong",10);
return "多谢大侠相送小妇人去蒙古见我那儿子.\n";
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

if(me->query_temp("book512") == 0 )
return "我不需要护送。。。。\n";
if(me->query_temp("lingsong") == 0 )
return "我不需要护送。。。。\n";



 if( environment(ob)->query("short")=="郭家茅屋")
         {


    

          set_leader(0);
          write("终于到家了，多谢相送.\n");

  	if(!me->query("jinyong/book5"))
	{
		
 	//i = 100+random(200);
	//me->set("jinyong/book5",1);
	//me->add("combat_exp",i+10);
	//me->add("potential",i);
	//me->add("mpgx",10);
	//me->add("expmax",2);

	//tell_object (me,"你获得了"+chinese_number(i+10)+"点经验"+
	//           chinese_number(i)+"点潜能.\n");

		
         }		
             me->set_temp("book513",1);  
             me->set_temp("book512",0);
             me->set_temp("lingsong",0);
             me->apply_condition("menggu_song",0);
        call_out("leavet",1);
	  
           return "听说梅超风这个妖妇在附近山上做怪，能去帮帮大师父，除了这个妖妇不? \n";  
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