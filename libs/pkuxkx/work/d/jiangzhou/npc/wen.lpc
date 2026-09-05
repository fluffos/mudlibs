//By Zine
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
#include "/d/song/obj/askmap.h"
void create()
{
	set_name("温峤", ({ "wen"}));
        
	set("long",
	"他是原来本地的刺史，现在已经退休了。\n"
         );
	
	set("gender", "男性");
	
	set("age", 70);
	set("attitude", "peaceful");
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
	set("combat_exp", 650000+random(100000));
	set("loc","江州");
    set("inquiry", ([
			"闹鬼" : (: ask_quest :),
            "帮助" : (: ask_quest :),
            "help" : (: ask_quest :),
           
       	]) );    
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	

}



int ask_quest()
{
    object ob=this_object();
    object me=this_player();
   
    if (!me->query_temp("jn/step7b"))
    {
        command("sigh");
        command("say 一言难尽啊！");
		return 1;
    }
    else
    {
        tell_object(me,ob->query("name")+"似乎很犹豫。\n");
        command("say 既然你是韩前辈请来的，想必能为我排忧解难。\n");
        me->delete_temp("jn/step7b");
        me->set_temp("jn/step7c",1);
        command("whisper "+ me->query("id")+ " 我也觉得有点荒谬，但却是实实在在的。八角亭里夜里闹鬼！\n" );
        command("whisper "+ me->query("id")+ " 城内的和尚道士都来过，一个人也没用！\n" );
        command("whisper "+ me->query("id")+ " 如果你能帮我探一探(tan)，我将无比感激。\n" );
        command("whisper "+ me->query("id")+ " 对了，只有夜间这些鬼魅才会出现，城里的杂货铺有桃木剑卖，也许你会需要。\n" );
		return 1;
    }
}

int dest(object hua,object me)
{
    int exp=random(700);
    if (hua)
    {
        destruct(hua);
    }
    command("say 原来是这么一回事，子曾经曰：子不语怪力乱神，果然很有道理。\n");
    command("say 你太厉害了。\n");
    command("say 我这没什么事了，你去韩前辈哪里再看看？\n");
    me->delete_temp("jn/step7d");
    me->set("jiangnanquest/step7",1);
    me->add("combat_exp",exp);
    tell_object(me,HIW+sprintf("经历驱鬼事件之后，你的经验增加了%d点。\n",exp)+NOR);
    return 1;
}


int accept_object(object me, object hua)
{
    
    if (this_object()->is_busy() || this_object()->is_fighting())
    {
        tell_object(me,this_object()->query("name")+"正忙着呢！\n");
        return 1;
    }
	if( hua->query("id") != "po midai")
	return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    if( hua->query("owner") != me->query("id"))
	return notify_fail(this_object()->query("name")+"道：这是你找到的吗？\n");
	if (!me->query_temp("jn/step7d"))
    return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    
    me->add_busy(1);
    this_object()->add_busy(1);
    
    
	call_out("dest",1,hua,me);
	return 1;
}