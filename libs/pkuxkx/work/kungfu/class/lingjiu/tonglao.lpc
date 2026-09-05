// /NPC tonglao.c
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
void heal();
int auto_perform();

void create()
{
	set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "她就是"+HIC"「灵鹫宫」"NOR+"的开山祖师.\n"+
	    "乍一看似乎是个十七八岁的女子,可神情却是老气横秋.\n"+
	    "她双目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");
	set("title", HIC"灵鹫宫主人"NOR);
	set("gender", "女性");
	set("per", 20);
	set("age", 96);
	set("nickname", HIR "天上地下，唯我独尊" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 35);
	set("int", 45);
	set("con", 50);
	set("dex", 50);

	set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 14000);
	set("max_jing", 14000);
	set("neili", 17000);
	set("max_neili", 17000);
	set("jiali", 300);

	set("combat_exp", 14000000);
	set("score", 200000);
	set_skill("force", 350);
 	set_skill("literate", 250);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("hand",350);
        set_skill("beiming-shengong",120);
	set_skill("strike", 350);
        set_skill("sword",350);

	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
        set_skill("changhen-jian",280);
	set_skill("yueying-wubu",350);
	set_skill("tianyu-qijian",350);
	set_skill("bahuang-gong", 350);
	set_skill("xiaowuxiang-gong", 250);
	set_skill("throwing",300);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("throwing", "liuyang-zhang");
       map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
       map_skill("sword","tianyu-qijian");

	prepare_skill("throwing","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	create_family("灵鹫宫",1,"主人");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_perform :),
	            }) );
        set("chat_chance",100);
        set("chat_msg",({
	        (: heal :),
        }));	
	set("shen_type",-1);
set("score",10000);
    set_temp("apply/armor", 400);
    set_temp("apply/damage", 350);

setup();
	carry_object("/clone/weapon/jian")->wield();
       carry_object("/d/lingjiu/obj/doupeng")->wear();
         carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
}
void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="女性")
           {
 		command("say 你找死啊!");
		return;
	   }

	if (ob->query("betrayer")>0)
	{
	   command("say 本宫最忌欺师灭祖之事，你曾经判师，我不能收你！");
	   return;	
	}
	if (ob->query("score")<1500)
	{
	   command("say 你自问是否对本门尽力了?");
	   return;	
	}
	if (ob->query("family/family_name") != "灵鹫宫")
	{   
		command("say 我们灵鹫宫拜师要从副首领拜起，" + RANK_D->query_respect(ob) + "先去拜副首领吧！\n");
	   return;
	}

   if ((int)ob->query_skill("bahuang-gong", 1) < 150) 
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	   }
   if (ob->query_con() < 35) 
      	   {
		command("say 本门功法极为难练,你的根骨似乎不够.");
		return;
	   }
  if (!ob->query_temp("lingjiu/kill_ding"))
 {
	   command("say 丁春秋阴险狡诈，害死了我师弟无涯子，你去把他杀了，回来我一定收你。");
	ob->set_temp("lingjiu/kill_ding",1);
return;
}
if (!ob->query_temp("lingjiu/killer"))
{
	   command("say 你还没有杀掉丁春秋，师弟的大仇未报，我不还不能收你。");
return;
}

 	  command("recruit " + ob->query("id"));
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
	command("recruit " + ob->query("id"));
	return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
	        ob->set("title",MAG "灵鹫宫" NOR + HIG +"总管" NOR); 
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
        return;
}

void heal()                                             
{                                                       
	object ob=this_player();                        
	                                                
	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{                                               
		command("exert heal");                  
		command("enforce 200");                 
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

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	command("exert powerup");

	if ( !objectp(target) ) return 0;

	if (me->query("qi") < me->query("eff_qi"))      
 	command("exert recover"); 
 	if (me->query("jing") < me->query("eff_jing"))  
	command("exert regenerate");    
             
	if ( !target->is_busy() && objectp(target->query_temp("weapon")) && me->query("neili")>300) 
	{
         switch( random(3) )
           {
            case 0:
            command("unwield jian");
            command("perform hand.tanmei " + target->query("id"));
            command("wield jian");
            break;
            case 1:
            command("unwield jian");
            command("perform hand.duo " + target->query("id"));
            command("wield jian");
            break;
            case 2:
            command("wield jian");
            command("perform sword.fenfei " + target->query("id"));
            break;
             }
	}
	else if (objectp(present("jiudai", me)))
	{
         switch( random(4) )
        {
            case 0:
            command("wield jian");
            command("perform sword.fenfei " + target->query("id"));
             break;
            case 1:
            command("unwield jian");
            command("perform strike.lianzhong " + target->query("id"));
            command("wield jian");
            break;
            case 2:
            command("unwield jian");
            command("perform strike.zhong " +target->query("id"));
            command("wield jian");
             break;
            case 3:
            command("unwield jian");
            command("perform hand.tanmei " +target->query("id"));
            command("wield jian");
             break;            
	 }
	}

	return 1;
}

#include "/kungfu/class/masterdie.h"