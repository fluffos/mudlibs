//by tangfeng@SJ

#include <ansi.h>
//inherit NPC;
inherit FIGHTER;
#define QUESTDIR2 "quest/雪山飞狐/复仇篇/"

string *str_menpai = ({ "gm","tz","dls","mj","kl"});	
#include "/d/city/npc/skills_pfm.h";

void create()
{
  set_name("黑衣人", ({ "heiyi ren", "ren" }));
	set("gender", "男性");
	set("long", "这人身穿黑色紧装，面上蒙着一块黑布，只露出一双眼睛，精光四射。\n");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("per", 25);
	set("shen_type", -1);
	set("unique", 1);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("strike", 300);
	set_skill("cuff",300); 
	set_skill("taxue-wuhen",300);
	set_skill("zhentian-quan",300);
	set_skill("kunlun-zhang",300);
	set_skill("xuantian-wuji",300);
	
	map_skill("force","xuantian-wuji");
	map_skill("cuff","zhentian-quan");
	map_skill("strike","kunlun-zhang");
	map_skill("dodge","taxue-wuhen");
	map_skill("parry","zhentian-quan");
	
  prepare_skill("cuff", "zhentian-quan");
  prepare_skill("strike", "kunlun-zhang");
  
	set("combat_exp", 2000000);
	set("max_qi", 30000);
	set("max_jing", 3000);
	set("max_neili", 5000);
	set("eff_jingli",3000);
	set("qi",30000);
	set("jing",3000);
	set("jingli",3000);
	set("neili", 5000);

  setup();  
	if (!random(3))
	   add_money("gold", random(5)+1);
  carry_object("/d/dali/obj/blackcloth")->wear();

}
void init()
{
    object me, ob;  
    int i;    
    ::init();

    ob = this_object();
    if(!ob->query("kill_id")) return;
	  me=find_player(ob->query("kill_id"));  
   	if(!me) return;
	  if(environment(me)!=environment(ob)) return;
    if(ob->query("setok")) return;
    ob->set("setok",1);
	  if(ob->query("type_speical"))	ob->set("party",ob->query("type_speical"));  
    else 	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	  
	  ob->copy_menpai(({ob->query("party")}),1,random(2),20+random(80));	//复制npc的门派武功，				
		ob->copy_state();				//根据门派更新npc 的一些状态
	  i=me->query("max_pot");
	  if(i<350) i=350;
	  i=i-100;	
		ob->set_skills_level(i-random(100)+random(50));
	  if(ob->query("type_speical"))	ob->set("combat_exp",me->query("combat_exp"));
    else 	ob->set("combat_exp",me->query("combat_exp")*2/3); 
	  ob->set("max_neili",me->query("max_neili"));
  	ob->set("max_jingli",me->query("max_jingli"));
  	ob->set("max_qi",me->query("max_qi")*3/2);
  	ob->set("max_jing",me->query("max_jing"));
		ob->set("neili",query("max_neili")*3/2);
		ob->set("jingli",query("max_jingli")*3/2);
		ob->set("eff_jingli",query("max_jingli")*3/2);
		ob->set("qi",query("max_qi"));
		ob->set("eff_qi",query("max_qi"));
		ob->set("jing",query("max_jing")*3/2);
		ob->set("eff_jing",query("max_jing")*3/2);
		ob->set_skill("wuxing-zhen",290);
		remove_call_out("zhen");
		call_out("zhen",1,ob);
		remove_call_out("dest");
		call_out("dest", 600,ob);
		remove_call_out("do_kill");
		call_out("do_kill",2, me);
}

void zhen(object ob) 
{
   if( !ob ) return;                   
   command("lineup with ren 1");
   command("lineup with ren 2");
   command("lineup with ren 3");
   command("lineup with ren 4");
   command("lineup with ren 5");
	 command("lineup form wuxing-zhen");   
   command("lineup with ren 1");
   command("lineup with ren 2");
   command("lineup with ren 3");
   command("lineup with ren 4");
   command("lineup with ren 5");
   call_out("zhen",1,ob);
}
int do_kill(object me)
{
	object ob = this_object();
	if(!me) return 0;
	remove_call_out("checking");
	call_out("checking", 2, me, ob);
	::do_kill(me);
}

//检查，quest过程不允许死亡
int checking(object me, object ob)
{
	int ret =  ::checking(me,ob);
	if(!ret) return 0;
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
  if(!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0  ){
		remove_call_out("checking");
		tell_room(environment(me), HIB"\n"+me->name()+"眼看就是不敌，突然一股劲风袭来，黑衣人不由手上一松，"+me->name()+"顺势闯出苗家庄。\n"NOR);
		me->move("/d/lanzhou/lanzhou");
		tell_room(environment(me), HIB"\n一个身影突然飞来，待你仔细看来，原来是"+me->name()+"，只见"+me->name()+"突然一顿，竟然昏倒在地。\n"NOR);
		me->delete(QUESTDIR2+"start");
		me->delete_temp(QUESTDIR2+"answer");
		me->delete_temp(QUESTDIR2+"kill");
		me->delete_temp(QUESTDIR2+"kill_heyiren");
		me->delete_temp(QUESTDIR2+"have_kill");
		me->set("qi",100);																			//防止玩家意外死亡
		                                                        //dls没有毒的
	  me->set("quest/雪山飞狐/time",time());
	  me->set("quest/雪山飞狐/combat_exp",me->query("combat_exp"));
		me->set("jing",100);
		me->set("jingli",100);
        log_file("quest/FEIHU", sprintf("%s纪录：%s(%s)雪山飞狐复仇失败。经验%d。\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
    tell_room(environment(ob), ob->name()+"哼了一声：“什么人也敢管本大爷的事！不过，苗老贼果然厉害，兄弟们走！”\n");
		destruct(ob);
		return 1;
	}
 if( !me || me->is_ghost()||me->query("eff_qi")<me->query("max_qi")/15||me->query("qi")<me->query("max_qi")/20  || environment(me)!=environment(ob)){
		remove_call_out("checking");
		remove_call_out("do_lost");
                call_out("do_lost",0);
		return 1;
	}
   if(!me->is_fighting(ob)){remove_call_out("do_kill");  call_out("do_kill",1,me);}
}
void do_lost()
{
	object me,ob;
	ob = this_object();
	if(!ob) return;
	me=present(ob->query("kill_id"),environment(ob));
	if(!me) me = find_player(ob->query("kill_id"));
	if(me)
	{
		me->delete(QUESTDIR2+"start");
		me->delete_temp(QUESTDIR2+"answer");
		me->delete_temp(QUESTDIR2+"kill");
		me->delete_temp(QUESTDIR2+"have_kill");
		me->delete_temp(QUESTDIR2+"kill_heyiren");
		me->set("quest/雪山飞狐/time",time());
		me->set("quest/雪山飞狐/combat_exp",me->query("combat_exp"));
        log_file("quest/FEIHU", sprintf("%s纪录：%s(%s)雪山飞狐复仇失败。经验%d。\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
	}
  tell_room(environment(ob), ob->name()+"哼了一声：“什么人也敢管本大爷的事！不过，苗老贼果然厉害，兄弟们走！”\n");
	destruct(ob);
}

void dest(object ob)
{
  if(!ob) return;
  tell_room(environment(ob), HIR+"\n"+ob->name()+"哼了一声，点子厉害，我们撤~~~~~~~\n"NOR);
	destruct(ob);
}
void die()
{
	object me,ob=this_object();
	
	if(ob->query("kill_id") )
	{
	  	me=present(ob->query("kill_id"),environment(ob));
		if(!me) me = find_player(ob->query("kill_id"));
	  	if(!me) return 0;
      if(me->query_temp(QUESTDIR2+"answer")) 
      {	
	  	if(!me->query_temp(QUESTDIR2+"kill"))
	  	{
	  	  me->add_temp(QUESTDIR2+"kill_heyiren",1);
	  	  if(me->query_temp(QUESTDIR2+"kill_heyiren")==2)
	  	  {
	  	    me->set_temp(QUESTDIR2+"kill",1);
	  	    me->set_temp(QUESTDIR2+"have_kill",1);
	  	    me->delete_temp(QUESTDIR2+"kill_heyiren");
	  	  }
	  	}
	    }
  }
	command("disapp");
	::die();
}

