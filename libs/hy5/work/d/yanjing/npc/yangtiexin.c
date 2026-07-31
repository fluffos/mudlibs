#include <ansi.h>

inherit NPC;
int ask_job2();
void create()
{
	set_name("杨铁心",({"yang tiexin","yang"}));
   set("gender","男性");
   set("mingwang",5000);
   set("combat_exp",60000);
   
set("age",45);
   set("qi",6000);
   set("max_qi",6000);
set("food",2500);
set("water",2500);
   set("neili",5000);
   set("max_neili",5000);
   set("force_factor",10);
set("pubmaster",1);
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("club",280);
   set_skill("yangjia-qiang",320);
        map_skill("club", "yangjia-qiang");
        set("inquiry", ([
        "比武招亲" : (:ask_job2:) ,
         ]) );
   setup();
   add_money("silver",10);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tiespear")->wield();
}
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeh"))      
		who->set_temp("learn_timeh", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("yangjia-qiang",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("yangjia-qiang",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("yangjia-qiang",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeh",i);

      message_vision("杨铁心对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeh") <= 0) return 0;
else         
ob->add_temp("learn_timeh",-1);
return 1;
}


int ask_job2()
{

        object me = this_player();
        object ob,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        who=me;
        if(((int)me->query("jinyong/book5")!=1))
           {
                      message_vision("$N对着$n说道。比武招亲还没有开始。\n", this_object(), me);
	                      return 1;
            }

        if(!me->query_temp("book521"))
           {
                      message_vision("$N对着$n说道。梅超风听说在赵王府 能帮我除了这个魔头不?\n", this_object(), me);
	                      return 1;
            }    

        if(!me->query_temp("book522"))
           {
                      me->set_temp("book5222",1);
                      message_vision("$N对着$n说道。能帮我教出我的妻子包惜弱吗?\n", this_object(), me);
	                      return 1;
            }    

      if(!query("iskillok"))
      {
      message_vision("突然金国小王爷完颜康从周转杀了过来 说道：比武招亲，我赢定了。!\n",this_object(),who);	
      	fang = load_object(__DIR__"wanyankang");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
return 1;
      }	



                    
        if(!me->query_temp("book524"))
           {
                      message_vision("$N对着$n说道。你打赢完颜康了吗?\n", this_object(), me);
	                      return 1;
            } 
if((int)me->query("jinyong/book5")!=2)
{
message_vision("$N说道：多谢多次相助，只是梅超风逃走了，还在为害江湖！\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",2);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+9000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}		
                return 1;
                           
}