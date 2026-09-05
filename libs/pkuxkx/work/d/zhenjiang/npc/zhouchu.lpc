
#include <title.h>              
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_zuoren();
void create()
{
	set_name("周处", ({ "zhou chu","chu","zhou"}));
        
	set("long",
	"他就是十里八乡，远近闻名的少年小恶霸——周处了。\n"
         );
	
	set("gender", "男性");
	
	set("age", 15);
	set("attitude", "friendly");
    set("shen_type", -1);
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
            "name" : "人称小霸王周处就是我了。",
			"三害" : "我们这里，城北的猛虎，城西的蛟龙合称二害。",
            "quest" : (: ask_quest :),
            "除三害" : (: ask_quest :),
            "做人的道理" : (: ask_zuoren :),
            
       	]) );    
        setup();
        carry_object("/clone/cloth/cloth")->wear();
	

}

int ask_zuoren()
{
    object ob=this_object();
    object me=this_player();

    if (me->query("statistics/newbie_target/zc_finish"))
    {
        command("say 嗯，我以后会这样做的。");
        return 1;
    }
    if (me->query_temp("zc/step3")!=3)
    {
        command("say 做人？还是我来教教你吧！");
        fight_ob(me);
        return 1;
    }
    else
    {
        message_vision("$N向$n讲解做人的道理，$n认真地听着，不时提出疑问。\n",me,ob);
        me->delete_temp("zc");
        me->set("statistics/newbie_target/zc_finish",1);
        me->delete("statistics/newbie_target/zc_step");
        me->add("combat_exp",5000);
        CHANNEL_D->do_channel(ob, "rw", HIC + me->query("name")+HIC+"完成了除三害的任务。");
        tell_object(me,HIC+"完成除三害的Quest，你获得了五千点经验！\n"+NOR);
        if (me->query("combat_exp")<200000&&!random(5))
        {
            me->set("statistics/newbie_target/gift_reward","int");
        }

        me->set("title",HIC+"降龙伏虎"+NOR);
        me->set_title(({TITLE_QUEST1,TITLE_QUEST2,TITLE_QUEST3,TITLE_QUEST4,TITLE_QUEST5,TITLE_QUEST6,TITLE_QUEST7,TITLE_QUEST8,TITLE_QUEST9,TITLE_QUEST10}), HIC+"降龙伏虎"+NOR);
        tell_object(me,HIC+"你获得了『降龙伏虎』的称号！\n"+NOR);
        return 1;
    }
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
        command("say 三害？没有的事！");
        return 1;
    }
    if (me->query("statistics/newbie_target/zc_finish"))
    {
        command("say 呵呵，多亏了你，我才有今天啊！\n");
		return 1;
    }
    else
    {
        if (!me->query("statistics/newbie_target/zc_step"))
        {
            command("say 城北山林深处的猛虎经常伤人，我却脱不开身，你去帮我把它干掉。\n");
            me->delete_temp("zc");
            me->set_temp("zc/step1",1);
		    return 1;
        }
        else if (me->query("statistics/newbie_target/zc_step")==1)
        {
            command("say 城西有蛟龙吃人，我却脱不开身，你去帮我把它干掉。\n");
            me->delete_temp("zc");
            me->set_temp("zc/step2",1);
		    return 1;
        }
        else if (me->query("statistics/newbie_target/zc_step")==2)
        {
            command("say 城里的人都很怕我，为此我很苦恼，你能帮帮我吗？\n");
            me->delete_temp("zc");
            me->set_temp("zc/step3",1);
            tell_object(me,"你突然想到：陆机、陆云正在县城府衙做客，也许你可以请他们指点周处。\n");
		    return 1;
        }
        else
        {
            command("say 唉。\n");
		    return 1;
        }
		return 1;
    }
}

int dest(object item,object me)
{
    int exp=1+random(500);
    if (item)
    {
        destruct(item);
    }
    me->add("combat_exp",exp);
    tell_object(me,HIW+sprintf("之前的大战让你获益匪浅。\n你的经验增加了%d点。\n",exp)+NOR);
    return 1;
}


int accept_object(object me, object item)
{
    object ob=this_object();
    if (this_object()->is_busy() || this_object()->is_fighting())
    {
        tell_object(me,this_object()->query("name")+"正忙着呢！\n");
        return 1;
    }
	if( item->query("owner")==me->query("id")&&item->query("zhouchu")==1&&!me->query("statistics/newbie_target/zc_give_bonus1"))
	{
        me->add_busy(1);
        ob->add_busy(1);
        call_out("dest",1,item,me);
        command("say 你竟然抢先于我，打死了猛虎？嘿嘿，真不错啊。");
        me->delete("zc");
        me->set("statistics/newbie_target/zc_step",1);
		me->set("statistics/newbie_target/zc_give_bonus1",1);
        return 1;
    }
    if( item->query("owner")==me->query("id")&&item->query("zhouchu")==2&&!me->query("statistics/newbie_target/zc_give_bonus2"))
	{
        me->add_busy(1);
        ob->add_busy(1);
        call_out("dest",1,item,me);
        command("say 你竟然抢先于我，打死了蛟龙？嘿嘿，真不简单啊。");
        me->delete("zc");
        me->set("statistics/newbie_target/zc_step",2);
		me->set("statistics/newbie_target/zc_give_bonus2",1);
        return 1;
    }
    else
    {
        return notify_fail(ob->query("name")+"道：妈妈说，好孩子不拿别人的东西。\n");
    }
	return 1;
}