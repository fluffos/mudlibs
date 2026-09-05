//wang.c
//made by hacky
//王重阳
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include "/new_quest/qzhengpai.h"
#include "/new_quest/quest.h"
string ask_for_leave();
string ask_for_leave2();

#include <no1master.h>

void consider();
void heal();
void create()
{
	int err;
	set_name("王重阳",({"wang chongyang","wang"}));
	set("nickname",HIR"中神通"NOR);
	set("long",@LONG
他就是全真教的开山祖师，武林中号称中神通的王重阳，
他身材消瘦，精神矍铄，飘飘然仿佛神仙中人，
LONG
		);
    set("title",HIB"全真派"NOR+YEL"开山祖师"NOR);
    set("gender","男性");
    set("age",80);
    set("attitude","friendly");
    set("shen_type",1);
    set("str",50);
    set("int",50);
    set("con",50);
    set("dex",50);
      set("per",80);
    set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: consider() :)
	}) );
    set("chat_chance",100);
    set("chat_msg",({
		(:heal:),
    }));
    set("max_qi",25000);
    set("max_jing",25000);
	set("max_neili",25000);
	set("neili",25000);
    set("jiali",510);
    set("combat_exp",20000000);
	
    set_skill("parry",350);
    set_skill("dodge",300);
    set_skill("cuff",400);
    set_skill("force",350);
    set_skill("xiantian-gong",430);
    set_skill("literate",220);
    set_skill("daoxue-xinfa",300);
    set_skill("quanzhen-jian",380);
    set_skill("finger",400);
    set_skill("yiyang-zhi",400);
    set_skill("jinyan-gong",380);
    set_skill("yangxin-quan",300);
    set_skill("kongming-quan",400);
    set_skill("sword",300);
	
    map_skill("force","xiantian-gong");
    map_skill("dodge","jinyan-gong");
    map_skill("finger","yiyang-zhi");
    map_skill("sword","quanzhen-jian");
    map_skill("parry","yiyang-zhi");
    map_skill("cuff","kongming-quan");
    prepare_skill("finger","yiyang-zhi");
    set_temp("apply/armor", 600);
    set_temp("apply/damage", 450);
	
	set("inquiry", ([
        "quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
        "还俗" : (: ask_for_leave :),
        "脱离教派" : (: ask_for_leave2 :),
		]));
	
	
    setup();

	setup_no1master();

    create_family("全真派",1,"开山祖师");
    set("class","taoist");
	
    carry_object(__DIR__"obj/robe")->wear();
    carry_object(__DIR__"obj/gangjian")->wield();
	
    
}

void init()
{
        add_action("do_leave",  "leave");
        ::init();
}		

string ask_for_leave()
{
	object me;

	me = this_player();
  
  if ( me->query("gender")!= "男性" )
    return "只有男性弟子才能还俗。";
  
	if( (string)me->query("class")!="taoist" )
		return "你并非三清弟子，何故跟贫道开这等玩笑？";

	if( (string)me->query("family/family_name") != "全真派")
		return "你非我全真弟子，还俗的事情贫道作不得主。";

	me->set_temp("pending/leave_quanzhen", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我全真而去，就请下决心(leave)吧！";
}

string ask_for_leave2()
{
	object me;

	me = this_player();
  
  if ( me->query("gender")== "男性" )
    return "男性弟子还是先去还俗吧。";

	if( (string)me->query("family/family_name") != "全真派")
		return "你非我全真弟子，脱离门派的事情贫道作不得主。";

	me->set_temp("pending/leave_quanzhen", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我全真而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_quanzhen") != 1)
		return 0;
	message_vision("$N对$n说道：「从此你就不再是我全真门下了，请好自为之！」\n",this_object(),me);
	tell_object(me,HIR "你决定叛出全真门下！\n" NOR);
	me->delete_temp("pending/leave_quanzhen");
  me->expell_family("全真派");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}

void attempt_apprentice (object ob)
{ 
	int exp;      
	object obj;
	
	if((string)ob->query("family/family_name")!="全真派")
	{
		command("say " + RANK_D->query_respect(ob) + "若想入我重阳宫，可先拜尹志平。\n");  
		return;
    }
	if((int)ob->query("score")<1500)
	{
		command ("say 你自问是否对本门尽力了?");
		return;
	}
	if((int)ob->query("shen")<50000)
	{
		command("say 学武之人，德义为先，希望" + RANK_D->query_respect(ob) + "多做些善事，\n");
		return;
	}
	if((int)ob->query_skill("xiantian-gong",1)<60)
	{
		command("say " + RANK_D->query_respect(ob) + "还应在先天功上多下些功夫!\n");
		return;
    }
	if((int)ob->query("betrayer")>=1)
	{
		command("say 学武之人最忌背信弃义，你多次判师，我怎么能够收你!\n");
		return;
    }
	if((int)ob->query("combat_exp")<100000)
    {
		command("say 你再练几年吧!");
		return;
    }
	
	command("say 好吧，我就收下你吧.\n");
	command("recruit " + ob->query("id"));
	command("say 我也没有什么好给你的，\n");
	command("say 这里有一吧长剑，我将它刻上你的名字送与你吧,\n");
	command ("say 希望你能用这把剑惩恶扬善.\n");
    
    message_vision("王重阳气沉丹田，指锋急转，抽出自己的佩剑，刻上了你的名字\n",this_player());
    message_vision("王重阳给你一把刻有你名字的长剑\n",this_player());
	obj = new(__DIR__"obj/jian");
	obj->move(this_player());
	
	exp = (int) ob->query("combat_exp");
	if( exp<=150000) 
		ob->set("title",HIB"全真派"NOR+RED"散仙"NOR);
	else if (exp<=1000000)
		ob->set("title" ,HIB"全真派"NOR+RED"人仙"NOR);
	else if (exp<=4500000)
		ob->set("title",HIB"全真派"NOR+RED"地仙"NOR);
	else
		ob->set("title",HIB"全真派"NOR+RED"天仙"NOR);        
//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, ob->query("title"));
}

void consider()
{
	object *enemy,target;
	enemy = query_enemy() - ({ 0 });
	target = enemy[random(sizeof(enemy))];
	switch( random(2) )
	{
	case 0:
		command("unwield jian");
                command("perform finger.fuxue " + target->query("id"));
		command("wield jian");
		break;
	case 1:
		command("unwield jian");
                command("perform finger.yizhi " +target->query("id"));
		command("wield jian");
		break;
	}
}
void heal()                                             
{                                                       
	object ob=this_player();                        
	
	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{                                               
		command("exert heal");                  
		command("enforce 30");                 
		return;                                 
	}                                               
	
	if (ob->query("qi") < ob->query("eff_qi"))      
	{                                               
		command("exert recover");               
		return;                                 
	}                                               
	
	if (ob->query("jing") < ob->query("eff_jing"))  
	{	command("exert regenerate");            
	
	return;
	}                                         
}                                                       

#include "/kungfu/class/masterdie.h"