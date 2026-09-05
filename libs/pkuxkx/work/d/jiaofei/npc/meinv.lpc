//Created by whuan@pkuxkx
//投名状任务之美女
inherit NPC;
#include <ansi.h>

string * name1 = ({ "王","张","李","薛","齐","任","黄","郭","欧阳","南宫","白","陈"}); 
string * name2 = ({ "格格", "公主","小姐","姑娘","夫人","郡主"}); 

void destme();
int do_rob(string arg);
void create()
{
	string name = HIY+name1[random(sizeof(name1))] +HIG+ name2[random(sizeof(name2))]+NOR;
	set_name(name, ({ "beauty girl","meinv" }));
	set("gender", "女性");
	set("age", 15 + random(15));
	set("long", "这是位有闭月羞花之貌的绝色美女，在保镖的保护下悠闲的游山玩水。\n");
	set("combat_exp", 10000);
	set("attitude", "peaceful");
	set("per", 99);
	set("str", 10);
	set("int", 30);
	set("con", 30);
	set("dex", 50);
	set("shen",100);
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("inquiry", ([
       ]));
	setup();    
  carry_object("/d/gumu/npc/obj/white")->wear();
	add_money("silver", random(5));
}

void destme()
{
  remove_call_out("dest");
  call_out("dest",780);
  return; 	
}

void init()
{
	object ob;
        
	::init();
  add_action("do_rob","rob");
  add_action("do_rob","hit");
  add_action("do_none","steal"); 
  add_action("do_none","beg"); 
  add_action("do_none","attack");           
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

int do_rob(string arg)
{
	object me=this_object();
	object ob=this_player();
	object bg;
	if(arg !="beauty girl" && arg!="meinv")
	{
		return 0;
	}
	if (me->query("master")!=ob->query("id"))
	{
			tell_object(ob,"请不要唐突佳人！\n");
			return 1;
	}
	//以下程序召唤出保镖
	if(me->query("bgnum")>0 && !present("bao biao",environment(me)))
	{
		message_vision("$n跳上前去，对着$N色迷迷的笑了起来：这次看你往哪儿跑！\n",me,ob);			
		message_vision("$N喊了几声，却发现没什么回应，不禁又羞又急，竟然晕了过去！\n",me,ob);
		me->set("owner",ob->query("id"));
		me->unconcious();
    }		
	else
	{
		message_vision("$n跳上前去，对着$N色迷迷的笑了起来：打劫啦！打劫啦！"
		+RANK_D->query_self_rude(ob)+"今天来劫个色！\n",me,ob);	
		message_vision("$N大声尖叫道：来人啦！救命啊！\n",me,ob);		
		message_vision("只见斜刺里冲出一位保镖，对着$n发起了攻击。\n",me,ob);
		me->add("bgnum",1);
		bg=new(__DIR__"bodyguard");
		bg->do_copy(ob);
		bg->move(environment(ob));
		bg->kill_ob(ob);
		bg->checking(bg,ob);
		if(me->query("bgnum") == 1)
		{
		    //被攻击后准备离开。
		    destme();
		}
    }
	return 1;
}	

int do_none()
{
	tell_object(this_player(),"请不要唐突佳人！\n");
	return 1;
}	


void greeting(object ob)
{
	if(living(this_object()))
	tell_object(ob,this_object()->query("name")+"面露娇羞之色，悄悄的低下头去。\n");
}

void dest()
{
  message_vision("$N慢慢离开了。\n",this_object());
	destruct(this_object());
}

void kill_ob(object ob)
{
	command("fear");
	command("help!");
	message_vision("$N尖叫着逃走了。\n",this_object());
	destruct(this_object());
}

int accept_fight(object me)
{
	command("fear");
	command("shake");
	return 0;       
}