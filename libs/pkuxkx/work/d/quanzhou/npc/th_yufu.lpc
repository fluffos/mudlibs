//girl.c
//by hehe
//2003.3.21
#include <ansi.h>
inherit NPC;
int ask_boat();

void create()
{
	  set_name("钓鱼老翁", ({ "diaoyu laoweng", "laoweng"}));
    set("gender", "男性");
    set("age", 68);

    set("long", "一个满脸沧桑的钓鱼老翁。\n");
    set("attitude", "friendly");
    set("combat_exp", 1000);
    set("shen_type", 1);
    set_skill("unarmed", 20);
    set_skill("dodge", 20);
    set_skill("parry", 20);
	  set_temp("apply/attack", 10);
    set_temp("apply/defense", 10);
    set("inquiry", ([
       "姑苏慕容" : "姑苏慕容我就不清楚了，不过湖中央有一个大庄园。",
       "借船" : (: ask_boat :),
    ]) );

    setup();

}

int ask_boat()
{
    object me=this_player(),boat;
    if ( me->query("balance")<100 ) 
    {
    	tell_object(me, "没钱你借啥船啊？\n");
    	return 1;
    }
    
    if ( !(boat=find_object("/d/murong/boat") ) )
    {
    	boat=load_object("/d/murong/boat");
    	if ( !objectp(boat) )
    	{
    		tell_object(me, "没有合适的渔船。\n");
    		return 1;
    	}
    	
    	if ( boat->query("in_use") )
    	{
    		tell_object(me, "渔船已经被人借走了！\n");
    		return 1;
    	}
    }
    
    me->add("balance",-100);
    tell_object(me, "你借走了老翁的钓鱼船，将船慢慢地划向湖中央。\n");
    me->move(boat);
    if ( boat->use_boat(me) )
      boat->set("in_use",1);
    return 1;
}
