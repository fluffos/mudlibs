
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
void create()
{
	set_name("陆云", ({ "lu yun","lu","yun"}));
        
	set("long",
	"他是东吴名士-陆云。\n"
         );
	
	set("gender", "男性");
	
	set("age", 40);
	set("attitude", "friendly");
    set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
    set("qi", 1000);
    set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 100000);
	
    set("inquiry", ([
            "教导周处" : (: ask_quest :),
            "teach" : (: ask_quest :),
           
            
       	]) );    
        setup();
        carry_object("/clone/cloth/cloth")->wear();
	

}

void unconcious()
{
    die();
}

void die()
{
    this_object()->fullme();
}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("statistics/newbie_target/selected")!=2)
    {
        command("say 什么意思？");
        return 1;
    }
    if (!me->query_temp("zc/step3"))
    {
        command("say 小子，不简单啊，自己还顾不过来，先考虑别人了\n");
		return 1;
    }
    else
    {
        if (me->query_temp("zc/step3")==1)
        {
            command("say 其实，还需如此如此，这般这般，别的不懂的地方去问陆机吧。\n");
            me->delete_temp("zc");
            me->set_temp("zc/step3_from",2);
            me->set_temp("zc/step3",2);
		    return 1;
        }
        else if (me->query_temp("zc/step3")==2)
        {
            if (me->query_temp("zc/step3_from")==2)
            {
                command("say 其实，还需如此如此，这般这般，别的不懂的地方去问陆机吧。\n");
		        return 1;
            }
            command("say 其实，还需如此如此，这般这般，你回去告诉周处『做人的道理』吧。\n");
            me->delete_temp("zc");
            me->set_temp("zc/step3",3);
		    return 1;
        }
        else if (me->query_temp("zc/step3")==3)
        {
            command("say 你不是已经明白了吗？快回去告诉周处『做人的道理』吧。\n");
		    return 1;
        }
        else
        {
            command("say 唉，这孩子！\n");
		    return 1;
        }
		return 1;
    }
}

