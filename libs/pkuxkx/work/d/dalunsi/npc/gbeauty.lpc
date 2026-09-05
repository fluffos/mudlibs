// beauty	美女

inherit NPC;


#include <ansi.h>

string ask_laozu();

string * name1 = ({ "王","张","李","薛","齐","任","黄","郭","欧阳","南宫"}); 
string * name2 = ({ "格格", "公主","小姐","姑娘","夫人","郡主" }); 

void create()
{
	string name = name1[random(sizeof(name1))] + name2[random(sizeof(name2))];
	set_name(name, ({ "beauty" }));
	set("gender", "女性");
	set("age", 15 + random(15));
	set("long", "这是位有闭月羞花之貌的绝色美女，在保镖的保护下悠闲的游山玩水。\n");
	set("combat_exp", 10000);
	set("meitude", "peaceful");
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
		"laozu": 	(: ask_laozu :),
		"血刀老祖":	(: ask_laozu :),
		"老祖"	:	(: ask_laozu :),
       ]));
	setup();
  carry_object("/d/huashan/obj/greenrobe")->wear();
	add_money("silver", random(5));
       
	this_object()->start_call_out( (: call_other, this_object(), "display", this_object() :), 60);
	this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 780);
}       

void init()
{
	object ob;
        
	::init();
        
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	command("emote 面露娇羞之色，悄悄的低下头去。");
}

void dest()
{
       command("emote 慢慢离开了。");
	destruct(this_object());
}

void display()
{
	object me = this_object();

	if(!objectp(me->query("place"))) return;  // means BUG!!!	
	me->move(me->query("place"));
       command("emote 带这保镖慢慢的走了过来。");
}

void kill_ob(object ob)
{
	command("fear");
	command("help!");
	command("emote 尖叫着逃走了。");
	destruct(this_object());
}

int accept_fight(object me)
{
	command("fear");
	command("shake");
	return 0;       
}

string ask_laozu()
{
	if( this_player()->query("xs/girl_ob") == this_object() )
		return "啊！！！杀人啦！！！";
	else
		return "嗯？他是谁呀？";
}
