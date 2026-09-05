//made by goodtaste
// data: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_done();

void create()
{
	set_name("老汉", ({ "lao han","han","man"}));
        
	set("long",
	"他是一个老汉，今年七十多岁，每天的工作清洗建康府的十三座城门。\n"
         );
	set("title",RED"<生病中>"NOR);
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
            "清洗" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
            "完成" : (: ask_done :),
            "done" : (: ask_done :),
            
       	]) );    
        setup();
        carry_object("/clone/armor/cloth")->wear();
	

}

int bonus(object me)
{
    int exp;
    if (!me->query_temp("jn/step8a"))
    {
        return 1;
    }
    else
    {
        exp=random(100)*(int)me->query_temp("jn/step8a");
        me->add("combat_exp",exp);
        me->delete_temp("jn");
        tell_object(me,this_object()->query("name")+"道：清凉寺的老和尚正有事找你呢。\n");
        tell_object(me,HIW+sprintf("老汉苦难的人生经历给你上了一堂课。\n你的经验增加了%d点。\n",exp)+NOR);
        tell_object(me,HIC"江南的历练已经完成，建康府的大门向你敞开！\n"NOR);
        return 1;
    }
}

int ask_done()
{
    object me=this_player();
    if (me->query_temp("jn/step8a")>=8)
    {
        command("say 实在太感激不尽了！\n");
        command("cry");
        me->set("jiangnanquest/step8",1);
        call_out("bonus",2,me);
        return 1;
    }
    else
    {
        if (me->query_temp("jn/step8a"))
        {
            command("say 说好帮我清洗八座城门的，怎么说话不算数啊。\n");
            return 1;
        }
        else
        {
            command("?");
            return 1;
        }
    }
}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
   
    if (me->query("jiangnanquest/step8"))
    {
        command("say 多谢你帮我干活，保住了我的生计。\n");
		return 1;
    }
    else
    {
        if (me->query("jiangnanquest/step7") && !me->query_temp("jn/step8a"))
        {
            command("say 老汉我，就靠清洗(qingxi)城门糊口了，如果你能帮我清洗建康府的至少八座城门，我一定永远记得你的大恩大德。\n");
            me->set_temp("jn/step8a",1);
		    return 1;
        }
        else
        {
            command("say 就让我病死吧，早死少受罪。\n");
		    return 1;
        }
		return 1;
    }
}

