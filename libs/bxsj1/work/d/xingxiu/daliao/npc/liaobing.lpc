// tangfeng@SJ 2004
// /d/xingxiu/daliao/npc/liaobing.c
//inherit NPC;
inherit FIGHTER;
#include <ansi.h>
#define QUESTDIR "quest/天龙八部/"
#define QUESTDIR3 "quest/天龙八部/萧峰身世篇/"
#define QUESTDIR4 "quest/天龙八部/大辽救援篇/"
#define QUESTDIR5 "quest/天龙八部/复兴天下篇/"

string *str_menpai = ({ "wd","hs","gm","gb","tz","mj","sl","thd","kl"});    
//基本上都是无毒的门牌
#include "/d/city/npc/skills_pfm.h";
int checking(object me, object ob);

void create()
{
	set_name("辽兵", ({ "liao bing", "bing"}));
	set("long", "辽兵高手。\n");
	set("gender", "男性");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);

	set("str", 28);
	set("int", 20);
	set("con", 25);
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
	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	 
    ob->copy_menpai(({ob->query("party")}),random(2),random(2),60+random(40));  //复制npc的门派武功，     
	ob->copy_state();				//根据门派更新npc 的一些状态
	if (ob->query("f_skill2")) 
		good_skills=to_chinese(ob->query("f_skill"))+"和"+to_chinese(ob->query("f_skill2"));
	else	
		good_skills=to_chinese(ob->query("f_skill"));
	ob->set("long",HIW+"辽兵的精英高手，从装束和武功上看，似乎与"+ob->query("family/family_name")+"有关，小心他的绝技："+good_skills+"。"NOR);
	if(!ob->query("fight_id")||!(me= present(ob->query("fight_id"),environment(ob))))
	{
		ob->set_skills_level(350+random(200));
		return;
	}
    
	ob->set("setok",1);
	i=me->query("max_pot");
	if(i<350) i=350;
	i=i-100;	
	ob->set_skills_level(i-random(50)+random(25));
	ob->set("max_neili",me->query("max_neili"));
	ob->set("max_qi",me->query("max_qi")*(4+random(3))/4);
	ob->set("neili",query("max_neili")*3/2);
	ob->set("jingli",query("max_jingli")*3/2);
	ob->set("eff_jingli",query("max_jingli")*3/2);
	ob->set("qi",query("max_qi"));
	ob->set("eff_qi",query("max_qi"));
	ob->set("eff_jing",query("max_jing")*3/2);
	ob->set("jing",query("max_jing")*3/2);
	ob->set("jiali",50+random(80));
	ob->set("combat_exp",me->query("combat_exp")*(1+random(3))/3);
	ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
	ob->set_skill("wuxing-zhen",200);
	tell_room(environment(ob), HIR+"\n"+ob->name()+"嘶声大叫：“有人劫营~~~~~~~~~~~~~~~~”\n"NOR);
	remove_call_out("kill");
	remove_call_out("check");
	call_out("checking",3,me,ob);
	call_out("kill",3,me);
}
void kill(object me)
{
	if(!me) return;
	if(random(2)) message_vision(HIR"$n对着$N冷笑道：竟敢私闯我大辽大营！\n" NOR, me,this_object());
	else message_vision(HIR"$n一边向$N冲过去，一边喊：有人劫营，小心戒备！\n" NOR, me,this_object());
	if(!this_object()->is_fight()) this_object()->kill_ob(me);
}
void die()
{
	object me,obj,ob=this_object();
        if(ob->query("fight_id")
               && (me=present(ob->query("fight_id"),environment(ob))))
	{
		if(me->query(QUESTDIR4+"start")) 	me->set_temp(QUESTDIR4+"kill",1);
		if(!random(10)||me->query("eff_qi")<me->query("max_qi")/10)
		{            
			message_vision(HIR"\n突然$N发现从$n身上掉下一个东西，你伸手捡了起来。\n" NOR, me,ob);
			obj=new("/clone/medicine/renshen-guo");
			if(random(2)) 
			{
				obj->set("long", "这是一棵千年首乌，形状宛如人体，传说千年方出一棵。\n");
				obj->set_name(HIG"千年何首乌" NOR, ({"qiannian heshouwu","heshouwu","he shouqu","shouqu"}));
				if(!present("qiannian heshouwu",me))     obj->move(me);
				else message_vision(HIB"$N发现你身上已经有一个了，顺手把"NOR+obj->name()+HIR"丢了。\n" NOR, me);
			}
			else if(random(2))
			{
				obj->set("long", "这是一颗紫红晶亮的大补丸。此丹乃武林珍药，提高功力，灵效无比。\n");
				obj->set_name(HIB"大补丸" NOR, ({"dabu wan","wan","dabu"}));
				if(!present("dabu wan",me))     obj->move(me);
				else message_vision(HIB"$N发现你身上已经有一个了，顺手把"NOR+obj->name()+HIR"丢了。\n" NOR, me);
			}
			else 
			{
				if(!present("renshen guo",me))     obj->move(me);
				else message_vision(HIB"$N发现你身上已经有一个了，顺手把"NOR+obj->name()+HIR"丢了。\n" NOR, me);
			}
		}
	}
	::die();
}
int checking(object me, object ob)
{
    int ret =  ::checking(me,ob);
    //me=this_palyer(),ob=this_object()
   if(!ret) return 0;
   if( !ob ) return 0;
   remove_call_out("checking");
   call_out("checking", 1, me, ob);

   command("lineup with liao bing 1");
   command("lineup with liao bing 2");
   command("lineup with liao bing 3");
   command("lineup with liao bing 4");
   command("lineup with liao bing 5");
   command("lineup form wuxing-zhen");   
   command("lineup with liao bing 1");
   command("lineup with liao bing 2");
   command("lineup with liao bing 3");
   command("lineup with liao bing 4");
   command("lineup with liao bing 5");
   
   if(!me
	  || me->is_ghost()
	  || me->query("eff_qi")<me->query("max_qi")/15
	  || me->query("qi")<me->query("max_qi")/20
	  || environment(me)!=environment(ob)
	  || (!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0))
   {
	 remove_call_out("checking");
	 if(me)
	 {        
		 me->set("qi",100);		
		 me->delete_temp("quest/天龙八部"); 
		 me->delete_temp("quest/busy");//任务冲突标志取消
		 me->set("quest/天龙八部/time",time());
		 me->set("quest/天龙八部/combat_exp",me->query("combat_exp"));
		 me->set("jing",100);
		 me->set("jingli",100);
		 if(environment(me)==environment(ob))
		 {
			 tell_room(environment(ob), HIC+"\n"+ob->name()+"一叫踢向"+me->name()+"“这点本事也来劫营？！”\n"NOR);
			 me->move("/d/xingxiu/daliao/shulin");
			 tell_room(environment(me), HIC"\n一个人影飞了过来，原来是"+me->name()+"。\n"NOR);
		 }
		 log_file("quest/TLBB", sprintf("%s纪录：%s(%s)大辽营救篇失败。经验%d。\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
	 }
	 destruct(ob);
	 return 1;
   }
   if(!me->is_fighting(ob)){
	   remove_call_out("kill");  
	   call_out("kill",1,me);
   }
}

void unconcious()
{
  die();
}
