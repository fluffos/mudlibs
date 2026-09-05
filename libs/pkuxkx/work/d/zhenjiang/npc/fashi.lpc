//made by goodtaste
// data: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();

void create()
{
	set_name("海法法师", ({ "haifa fashi","haifa","fashi"}));
        
	set("long",
	"他是一个得道的高僧，今年已经七十多岁了。\n"
         );
	
	set("gender", "男性");
	
	set("age", 73);
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
	
    set("inquiry", ([
			"quest" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
            
       	]) );    
        setup();
        carry_object("/d/shaolin/npc/obj/hui-cloth")->wear();
	

}



int ask_quest()
{
    object ob=this_object();
    object me=this_player();
   
    if (me->query("jiangnanquest/step5"))
    {
        command("say 好久没见到南昌的老白了！\n");
		return 1;
    }
    else
    {
        if (me->query("jiangnanquest/step4") && time()-me->query("jiangnanquest/conntime")>1440)
        {
            command("say 最近江南受了水灾，虽然藩库里粮食极多，但是藩司却不愿意开仓救人，每天都要死很多人。\n");
            me->set_temp("jn/step5a",1);
		    return 1;
        }
        else
        {
            command("say 佛云：不可说，不可说。\n");
		    return 1;
        }
		return 1;
    }
}

int dest(object midai,object me)
{
    int exp=random(500);
    if (midai)
    {
        destruct(midai);
    }
    me->delete("jn");
    me->add("combat_exp",exp);
    tell_object(me,this_object()->query("name")+"道：善哉，善哉，江南的百姓有救了。\n");
    tell_object(me,HIW+sprintf("法师指点了你一些武学上的障碍。\n你的经验增加了%d点。\n",exp)+NOR);
    me->set("jiangnanquest/step5",1);
    return 1;
}


int accept_object(object me, object midai)
{
    
    if (this_object()->is_busy() || this_object()->is_fighting())
    {
        tell_object(me,this_object()->query("name")+"正忙着呢！\n");
        return 1;
    }
	if( midai->query("id") != "da mi")
	return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    if( !midai->query("jiangnan"))
	return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
	if (!me->query_temp("jn/step5d"))
    return notify_fail(this_object()->query("name")+"道：这是你找来的吗？固然这里很缺米，你不能抢东西啊！\n");
    
    me->add_busy(1);
    this_object()->add_busy(1);
    
    
	call_out("dest",1,midai,me);
	return 1;
}