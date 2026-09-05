//created by icer for yideng task
//whuan 加入master功能
//yideng dashi

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <title.h>

int ask_jianqi(); //询问剑气
int ask_cure();
int ask_ying();

void create()
{
        set_name("一灯大师", ({ "yideng dashi","dashi","yideng" }));
        set("long", "他身穿粗布僧袍，两道长长的白眉从眼角垂了下来，面目慈祥，眉间隐含愁苦，\n
但一番雍容华贵的神色，却是一望而知。\n");
        set("gender", "男性");
        set("rank_info/respect", "大师");
        set("title",HIR"南  僧"NOR);
        set("age", 78);
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("no_get",1);
        set("shen_type", 500000);

	      set_skill("finger", 400);            
	      set_skill("force", 400);             
	      set_skill("strike", 400);            
	      set_skill("dodge", 400);             
	      set_skill("parry", 400);             
	      set_skill("sword", 400);             
	      set_skill("cuff", 400);              
	      set_skill("literate", 380);     
	      set_skill("buddhism", 450);      
	      set_skill("sun-finger", 400);        
	      set_skill("duanjia-jian",300);       
	      set_skill("duanshi-shenfa",400);     
	      set_skill("duanjia-xinfa",400);    
	      set_skill("qingyan-zhang", 400);     
	      set_skill("jinyu-quan", 400);        
	      map_skill("cuff","jinyu-quan");      
	      map_skill("sword","sun-finger");     
	      map_skill("dodge","duanshi-shenfa"); 
	      map_skill("parry", "duanjia-jian");  
	      map_skill("force","duanjia-xinfa");
	      map_skill("strike","qingyan-zhang"); 
	      map_skill("finger","sun-finger");    
	      prepare_skill("finger","sun-finger");
        set("combat_exp", 10000000);

	      set("attitude", "peaceful");
	      set("class", "bonze");
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("inquiry", ([
	         "治伤" : (: ask_cure :),
	         "瑛姑" : (: ask_ying :),
	         "剑气纵横" : (: ask_jianqi :),	
        ]) );
	      set("yiyangzhi/sword",1);              
	      create_family("大理段家", 10 , "传人");
        setup();
        carry_object("/d/shaolin/obj/cloth")->wear();
}

int check()
{
	object room;
	
	room = environment(this_object());
        if (base_name(room) == "/d/yideng/yideng/shiwu")
		return 1;
	return 0;
}

int ask_cure()
{
	if (!check())
		return notify_fail("一灯大师不打算给你疗伤。\n");
	if (this_player()->query("task_duan1")||this_player()->query("task_duan2"))
	return notify_fail("一灯大师不打算给你疗伤。\n");
	command("say 好吧，我就来给你治好伤。\n");
	write("一灯使出一阳指功夫，给你治好了伤。\n");
	this_player()->set("eff_qi",this_player()->query("max_qi",1));
	this_player()->set_temp("marks/段1",1);
	return 1;
}

int ask_ying()
{
	object me;
	me = this_player();
	
	if (!check())
		return 1;
	if (me->query("task_duan3"))
	{
		command("say 多谢施主成全，瑛姑现在很好。\n");
		return 1;
	}
	if (me->query("task_duan2"))
	{
		command("say 多谢施主！\n");
		command("say 以前郭靖黄蓉曾来此与我研讨九阴真经，我就将它传与你，作为报答吧！\n");
		write("一灯大师向你详细讲述了九阴真经的内容。\n");
		write("你的根骨增加了！！\n");
		write("你的悟性增加了！！\n");
		me->add("con",3);
                me->add("xiantian/con/yideng",3);
		me->add("int",5);
                me->add("xiantian/int/yideng",5);
		me->delete("task_duan2");
		me->set("task_duan3",1);
                me->delete("task_duan1");
		return 1;
	}
	if (!me->query_temp("marks/段1"))
	return notify_fail("一灯大师欲言又止，神色凄凉。\n");
	command("sigh");
	command("say 我很对她不起，如果你能让她原谅我，我将感激不尽。如果你见到她，\n
请告诉她我已经出家了，法号一灯。\n");
	command("say 从后山可以直接下山。如果你完成了到我这里来可以从瀑布那里\n
直接走捷径(jiejing)。\n");
	this_player()->set("task_duan1",1);
	return 1;
}
int accept_object(object me, object ob)
{
	if (!check())
		return 1;
	if (me->query("task_duan3"))
	{
		return notify_fail("一灯大师惊诧地望着你：瑛姑不是已经原谅我了吗？怎么又给我这个指环？\n");
	}
        if ((ob->query("id")=="zhi huan") && (me->query_temp("marks/killed_qiu",1)))
	{
		write("一灯大师接过指环，说道：多谢这位施主。如果施主方便，我想\n
跟施主研讨一下九阴真经如何？\n");
		write("一灯大师传授予你九阴真经的易筋锻骨篇。\n
你的根骨增加了！！\n");
		me->add("con",3);
                me->add("xiantian/con/yideng2",3);
		me->delete("task_duan1");
		me->set("task_duan3",1);
		return 1;
	}
}

void attempt_apprentice(object ob)
{
	mapping fam;
	string name,new_name;
	if (!mapp(fam=ob->query("family"))
		|| fam["family_name"] !="大理段家") {
		command("say "+RANK_D->query_respect(ob)+"还是先在段家做做别的事再来找我吧。");
		return;
	}
  
  if ((int)ob->query("betrayer")>=1){
  	command("say 大理岂可将绝技传给不忠之人。");
  	command("say 你去吧。");
  	return;
  }  	
  
	if ((int)ob->query_skill("duanjia-xinfa",1)<200) {
		command("say 我们段家的内功是天南一绝，你还要多下下功夫。");
		return;
	}

	if ((int)ob->query("score",1)<1500) {
		command("say 从你身上看不到你的忠诚，你得为大理做点什么。");
		return;
	}
  
	command("recruit " + ob->query("id"));
  if(ob->query("gender")=="男性")
  {    
	  ob->set("title", HIR"大理"+HIY"家臣"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, HIR"大理"+HIY"家臣"NOR);
	}
	else
	{
		ob->set("title", HIR"大理"+HIM"郡主"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, HIR"大理"+HIM"郡主"NOR);
	}
  
  ob->restore_face(FACE_ORIGIN);
  name=ob->query("name");
  if (name[0..0]!="段") 
  	new_name = "段" + name[0..3];
  else 
  	new_name=name[0..5];
    
  ob->set("name", new_name);
  ob->set_face( FACE_FACT, ob->query("name") );
  		
  ob->save();  
  return;
}

int ask_jianqi()
{
	object me=this_player();
	//要通过一灯task
	mapping myfam;
  myfam = (mapping)me->query("family");
        
  if (myfam && myfam["family_name"] != "大理王府"){
    command("ah "+(string)me->query("id"));
    command("say "+ RANK_D->query_respect(me) +"这话从何说起？n");
    return 1;
  }
  
  if (myfam["master_id"] !="yideng dashi"){
    command("say 剑气纵横的绝招我只传授给我的弟子。");
    return 1;	
  }
      
  command("nod");
  command("say 好吧，我就传授你这一招。");
  me->set("yiyangzhi/jianqi",1);
  tell_object(me,"你学会了这一招。\n");
	return 1;
}
