//snowtu Rewrite 2006

#include <ansi.h>
inherit NPC;

int have_fu;
string give_fu(object who);
int do_yes(string arg);

void create()
{
	set_name("风婆",({"feng po","feng shen","po"}));
	set("gender", "女性");
	set("age", 35);
	set("long", "    \n天宫中负责起风的天神，想要刮风下雨时，没有她\n的帮助是不行的。\n");
	set("attitude", "heroism");
	set("class", "xian");
	set_level(151);
	set("daoxing", 2200000);	
	set("force_factor", 20);
	set("mana_factor",130);
	set_skill("dodge", 1480);
	set_skill("moondance", 1380);
	set_skill("unarmed", 1500);
	set_skill("baihua-zhang", 1470);
	set_skill("parry", 1500);
	map_skill("dodge", "moondance");
	map_skill("unarmed", "baihua-zhang");
	map_skill("parry", "baihua-zhang");
	set_skill("spells",1500);
	set_skill("force",1500);
	set("inquiry", ([
  		"下雨"   : "想求雨，光我一个人可不够。",
  		"rain"   : "想求雨，光我一个人可不够。",
  		"起风"   : (: give_fu :),
  		"刮风"   : (: give_fu :),
  		"wind"   : (: give_fu :),
  		"name"   : "我就是负责起风的风神。",
  		"here"   : "这就是天宫呀。",
	]));
   	set_temp("armor_level",50);
   	set_temp("weapon_level",50);
	setup();
	carry_object(0,"cloth",random(5))->wear();
	carry_object(0,"shoes",random(5))->wear();
	add_money("silver", 10);
}

void init()
{
	have_fu=1;
	add_action("do_yao", "yao");
}

string give_fu(object who)
{
	who=this_player();
	if ( who->query_level()<40 )
    		return "看来你还不懂怎么呼风唤雨，再好好修炼修炼吧。\n";
	else    
	{
        	who->set_temp("need_fengfu", 1);
        	return "我有张灵符，用它可以起风，你想要吗(yao)？\n";
        }
}

int do_yao(string arg)
{
	object me=this_object();
	object who=this_player();
	object fu;
	if ( who->query_temp("need_fengfu") ) 
        {
        	message_vision("$N答道：想要！\n", who);
        	if (have_fu==1)    
                {
                	message_vision("风婆说道：好吧！你来试试看这玩意灵不灵。\n", who);
                	fu = new ("/d/dntg/sky/obj/fenglingfu");
                	if ( fu && fu ->move(who) )
                        {
                        	message_vision ("$N交给$n一张风灵符。\n",me,who);
                        	have_fu=0;
                        }
                }
        	else    message_vision("风婆说道：哎呀，实在不好意思，我刚把它给别人了，你等会儿在来要吧。\n", who);
        	return 1;
        }
}