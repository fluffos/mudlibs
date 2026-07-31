
#include <ansi.h>
inherit NPC;

string ask_liwu();

void create()
{
        set_name("花伯", ({ "hua bo","hua" }) );
 // set("title", HIM "导师「人见人爱」" NOR);
	set("gender", "男性" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "这是一个精干的老者，看起来有八十多岁，他是老村长的徒弟，
如果你要出村，可以找他（ask hua about 出村）。
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 1500);
	set_skill("blade", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);
	set("inquiry" , ([
             "out" : (: ask_liwu :),
             "出村" : (: ask_liwu :),
	]));

	setup();
	carry_object("clone/cloth/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}


}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

			say( HIG"花伯对你说道：这位小兄弟，如果要出村输入"+HIR+"ask hua about 出村\n"NOR);


}


string ask_liwu()
{
  object me=this_player();
  int exp_bound,qn_bound,neili;

  if(!me->query_temp("isout"))
  {
   return "先去找老村长打个招呼吧 ask lao about 出村!";
  }
 me->move("/d/city/kedian");
  return "请选择想去哪里！";
}
