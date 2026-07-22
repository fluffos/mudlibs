// tangfeng@SJ 2004
// /d/gb/npc/dizi.c
// /shaolin/npc/dizi.c

//inherit NPC;
inherit FIGHTER;
#include <ansi.h>

#define QUESTDIR3 "quest/天龙八部/萧峰身世篇/"
#define QUESTDIR4 "quest/天龙八部/大辽救援篇/"
#define QUESTDIR5 "quest/天龙八部/复兴天下篇/"

string *str_menpai = ({ "wd","hs","ss","gm","tz","dls","sld","xx","mj","thd","kl"});	
#include "/d/city/npc/skills_pfm.h";
void create()
{
	set_name("弟子", ({ "di zi", "dizi"}));
	set("long", "一位某门派弟子。\n");
	set("gender", "男性");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);

        set("str", 20);
	set("int", 20);
        set("con", 20);
	set("dex", 20);

	set("max_qi", 30000);
	set("max_jing", 6000);
	set("eff_jingli",6000);
	set("neili", 40000);
	set("max_neili", 30000);
	set("jiali", 200);
	set("combat_exp", 5000000+random(8000000));
	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
}
void init()
{
    object me,ob;  
    string good_skills;
    int i;     
    ::init();
    ob = this_object();
    if(ob->query("setok")) return;
	  if(!ob->query("party"))	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	 
	  if(ob->query("party")=="sl") 	set_name("护法弟子", ({ "shaolin dizi", "hufa dizi","dizi"}));
	  else if(ob->query("party")=="gb")	set_name("丐帮弟子", ({ "gaibang dizi","dizi"}));
    else	set_name("无名弟子", ({ "wuming dizi", "dizi"}));
    ob->copy_menpai(({ob->query("party")}),random(2),random(2),50+random(50));  //复制npc的门派武功                                              
	  ob->copy_state();				//根据门派更新npc 的一些状态
		if (ob->query("f_skill2")) 
				good_skills=to_chinese(ob->query("f_skill"))+"和"+to_chinese(ob->query("f_skill2"));
		else	
				good_skills=to_chinese(ob->query("f_skill"));
   	ob->set("long",HIW+ob->query("family/family_name")+"高手，成名绝技："+good_skills+"。"NOR);
    if(!ob->query("fight_id"))
    {
		  ob->set_skills_level(350+random(200));
    	return;
    }
    me = present(ob->query("fight_id"),environment(ob));
	  if(!me) 
	  {
		  ob->set_skills_level(350+random(200));
    	return;
    }
    ob->set("setok",1);

	  i=me->query("max_pot");
	  if(i<350) i=350;
	  i=i-100;	
    ob->set_skills_level(i-random(50)+random(50));
	  ob->set("max_neili",me->query("max_neili"));
  	ob->set("max_jingli",me->query("max_jingli"));
    ob->set("max_qi",me->query("max_qi")*(3+random(3))/4);
  	ob->set("max_jing",me->query("max_jing"));
		ob->set("neili",query("max_neili")*3/2);
		ob->set("jingli",query("max_jingli")*3/2);
		ob->set("eff_jingli",query("max_jingli")*3/2);
		ob->set("qi",query("max_qi"));
		ob->set("eff_qi",query("max_qi"));
		ob->set("jing",query("max_jing")*3/2);
		ob->set("eff_jing",query("max_jing")*3/2);
    ob->set("jiali",50+random(30));
    ob->set("combat_exp",me->query("combat_exp"));
 		ob->set_skill("literate",ob->query("int")*10); 	 											//full literate

 		if(ob->query("teamleader")) message_vision(HIC"\n$N对$n点了点头道：阵法二十秒钟之内启动。\n" NOR, ob,me);
	  if(ob->query("party")=="sl") 	ob->set_skill("fumoquan-zhen",200);
    else if(ob->query("party")=="gb")	ob->set_skill("dagou-zhen",200);
    else	ob->set_skill("wuxing-zhen",200);
    ob->remove_all_killer();
    remove_call_out("kill");
    remove_call_out("check");
    
    call_out("check",19,ob,me);
    call_out("kill",20,me);
}
void check(object ob, object me) 
{
	 int ret =  ::checking(ob,me);
	 if(!ret) return;
   if(!ob) return;
	 remove_call_out("check");
	 call_out("check", 1, ob, me);

   command("lineup with dizi 1");
   command("lineup with dizi 2");
   command("lineup with dizi 3");
   command("lineup with dizi 4");
   command("lineup with dizi 5");
	 if(ob->query("party")=="sl") 	command("lineup form fumoquan-zhen");  
   else if(ob->query("party")=="gb")	command("lineup form dagou-zhen"); 
   else	command("lineup form wuxing-zhen");   
   command("lineup with dizi 1");
   command("lineup with dizi 2");
   command("lineup with dizi 3");
   command("lineup with dizi 4");
   command("lineup with dizi 5");  
   if(ob->query("party")=="sl") 	command("yun jingang");
   if(ob->query("party")=="gb")   command("yun huntian");   
     
   if(!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0  ){
	   remove_call_out("check");
  	 if(ob->query("party")=="sl")
  	 {
  	 	 	me->delete_temp(QUESTDIR4+"shaolinzhen");
  	 	 	me->delete_temp(QUESTDIR5+"shaolinzhen");		
  	 }
     if(ob->query("party")=="gb")	
     {
     	  me->delete_temp(QUESTDIR4+"dagouzhen");	
   	    me->delete_temp(QUESTDIR5+"dagouzhen");	
   	 }
  	 me->set("qi",100);		
  	 me->set("jing",100);
	   me->set("jingli",100);
     tell_room(environment(ob), HIG+""+ob->name()+"一言不发，慢慢地消失在角落里。\n"NOR);
	   destruct(ob);
	   return;
	}                  
   if( !me
    || me->is_ghost()
     ||me->query("eff_qi")<me->query("max_qi")/15
   ||me->query("qi")<me->query("max_qi")/20
    || environment(me)!=environment(ob)){
    	 remove_call_out("check");
     if(me && environment(me)==environment(ob)&& !random(3))  tell_room(environment(ob), HIW+"\n"+ob->name()+"微笑地对着"+me->name()+"道：“下次努力啊。”\n"NOR);
    else tell_room(environment(ob), HIY+""+ob->name()+"一言不发，慢慢地消失在角落里。\n"NOR);
    
     if(me &&  ob->query("party")=="sl")
  	 {
  	 	 	me->delete_temp(QUESTDIR4+"shaolinzhen");
  	 	 	me->delete_temp(QUESTDIR5+"shaolinzhen");            
  	 }
     if( me && ob->query("party")=="gb")	
     {
     	  me->delete_temp(QUESTDIR4+"dagouzhen");	
		  me->delete_temp(QUESTDIR5+"dagouzhen");	
   	 }
     destruct(ob);
     return;
   }
}

void kill(object me)
{
	if(!me) return;
   this_object()->kill_ob(me);
   me->kill_ob(this_object());
}
void die()
{
	object *player;
	object me,ob=this_object();
	int i,p=0;
	player = all_inventory(environment(ob));
	message_vision("\n\n", ob);
	if(random(2))command("why");
	else command("disapp "+ob->query("id"));
	if(ob->query("fight_id"))
	{
          if(me=present(ob->query("fight_id"),environment(ob)))
		{
			for (i = 0; i < sizeof(player); i++) {
				if (!living(player[i]) || player[i] == me|| player[i] == ob) continue;
				if( player[i]->query("id")=="shaolin dizi"||player[i]->query("id")=="gaibang dizi") p++;
			}         	  	
		  	if(p==0) 
			{
				if(ob->query("party")=="sl") 
				{
					if(me->query(QUESTDIR3+"good")) me->set_temp(QUESTDIR4+"shaolinzhen",1);
					else if(me->query(QUESTDIR3+"bad")) me->set_temp(QUESTDIR5+"shaolinzhen",1);
					message_vision(HIC"\n$N扬声道：恭喜$n闯过这少林大阵，果然是"+me->query("family/master_name")+"座下"+me->query("family/family_name")+"高手，确实武功了得。\n" NOR, ob,me);
					log_file("quest/TLBB", sprintf("%s(%s)少林阵闯阵成功。经验：%d。\n", me->name(1),me->query("id"), me->query("combat_exp")) );                  
				}
				if(ob->query("party")=="gb") 
				{
					if(me->query(QUESTDIR3+"good")) me->set_temp(QUESTDIR4+"dagouzhen",1);
					else if(me->query(QUESTDIR3+"bad")) me->set_temp(QUESTDIR5+"dagouzhen",1);	
					message_vision(HIC"\n$N扬声道：恭喜$n闯过这打狗阵，果然是"+me->query("family/master_name")+"座下"+me->query("family/family_name")+"高手，确实武功了得。\n" NOR, ob,me);
					log_file("quest/TLBB", sprintf("%s(%s)打狗阵闯阵成功。经验：%d。\n", me->name(1),me->query("id"), me->query("combat_exp")) );                  
				}		
			}

		}
	}
	if(random(2)) message_vision(HIG"$N点了点头，缓缓消失在角落里。\n\n" NOR, ob);
	else message_vision(HIG"$N慢慢地退了出去。\n\n" NOR, ob);
	destruct(ob);
}
void unconcious()
{
  die();
}
