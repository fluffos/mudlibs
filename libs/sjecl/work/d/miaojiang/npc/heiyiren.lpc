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
  set("title", "黑衣人");
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
          ob->copy_menpai(({ob->query("party")}),1,random(2),100);    //复制npc的门派武功，                           
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
    command("follow "+me->query("id"));
     ob->kill_ob(me);
     me->kill_ob(ob);
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
