// 钓鱼的祖师爷 姜太公 By Zine
               
#include <ansi.h> 
inherit NPC; 
int ask_fish();
int ask_job();
int ask_done();
void create()
{
	set_name("姜太公", ({ "jiang taigong","taigong","jiang"}));
        
	set("long",
	"他是一个有着大智慧的人，在这里垂钓已经过了千年。\n"
         );
	set("title",HIC"愿者上钩"NOR);
	set("gender", "男性");
	
	set("age", 2010);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
    set("uni_target",1);
    set("no_get",1);
	set("max_qi", 1000000);
    set("qi", 1000000);
    set("max_jing", 1000000);
    set("jing", 1000000);
    set("max_jingli", 1000000);
    set("jingli", 1000000);
    set("neili", 900000);
	set("max_neili", 900000);
	set("jiali", 500);
    set_skill("hand", 5000);
	set_skill("parry",5000);
	set_skill("dodge", 5000);
	set_skill("force",5000);
	set_skill("literate",5000);
    set_skill("fishing",5000);
	set("combat_exp", 650000+random(100000000));
	
    set("inquiry", ([
			"diaoyu" : (: ask_fish :),
            "钓鱼" : (: ask_fish :),
            "job" : (: ask_job :),
            "修行" : (: ask_job :),
            "done" : (: ask_done :),
            "完成" : (: ask_done :),
            "钓鱼之术" : "钓鱼之术是钓鱼的基础，也是通向高阶修行的基石。",
            "辨位之术" : "辨位之术是根据当地的水文，从细微出观察是否能有大鱼的关键。",
            "识机之术" : "识机之术是进入高阶之后必备，时机往往稍纵即逝，错过了就没有了。",
       	]) );    
        setup();
        carry_object(__DIR__"obj/j-cloth")->wear();
        carry_object(__DIR__"obj/diaogan")->wield();
	

}

void init()
{
        add_action("do_confirm", "confirm");
}

int bonus(object me)
{
    command("ah");
    if (me->query_temp("jtg/lv1"))
    {
        me->delete_temp("jtg");
        me->delete("jtg/start");
        tell_object(me,"姜太公道：不错，不错。\n");
        tell_object(me,"姜太公指点了你一些钓鱼之术和辨位之术。\n");
        if (me->query_skill("fishing",1)<50)
        {
            me->improve_skill("fishing", 50+random(100));
        }
        if (me->query_skill("discern",1)<50)
        {
            me->improve_skill("discern", 60+random(120));
        }
        return 1;
    }
}

int ask_done()
{
    object ob=this_object();
    object me=this_player();
    if (!me->query("jtg/start"))
    {
        command("ah");
        tell_object(me,"姜太公道：我给你任务了吗？\n");
        return 1;
    }
    if (time()-(int)me->query("jtg/time") > 600)
    {
        command("shake");
        tell_object(me,"姜太公道：你也太慢了吧？\n");
        return 1;
    }
    if (me->query_temp("jtg/lv1"))
    {
        if (me->query_temp("jtg/number")==me->query_temp("jtg/count"))
        {
            bonus(me);
            return 1;
        }
        else
        {
            command("say 你好像弄错了我要你掉的条数。");
            if (me->query_temp("jtg/number") > me->query_temp("jtg/count"))
            {
                command("say 太少啦。");
            }
            else if (me->query_temp("jtg/number") < me->query_temp("jtg/count"))
            {
                command("say 太多啦。");
            }
            else
            {
                command("say 我其实是不识数的。");
            }
            return 1;
        }
    }
    else
    {
        command("shake");
        tell_object(me,"姜太公道：你的任务完成了吗？\n");
        return 1;
    }

}

int ask_job()
{
    object ob=this_object();
    object me=this_player();
    int busy;
    object where,target;
    int n=5+random(15);
    
    if (!me->query("iamafisher"))
    {
        command("shake");
        tell_object(me,"似乎只有渔夫才能从姜太公这里获得修行的指导。\n");
        return 1;
    }
    if (me->query("jtg/start"))
    {
        command("say 你上个任务还没完成呢。");
        return 1;
    }
    busy=me->query_skill("fishing",1);
    if (busy<60)
    {
        busy=60;
    }
    if (time()-me->query("jtg/time")<busy)
    {
        command("say 你上个任务太辛苦了，作为隐士，就不要那么急功近利。");
        return 1;
    }
    else
    {
        if (me->query_skill("fishing",1)<50 || me->query_skill("discern",1)<50)
        {
            while (!objectp(where) || base_name(where) == "/adm/daemons/taskd" || !where->query("couldfish"))
            {
                where = TASK_D->random_place();
            }
            me->set("jtg/start",1);
            me->set("jtg/time",time());
            me->set_temp("jtg/where",where);
            me->set_temp("jtg/number",n);
            me->set_temp("jtg/lv1",1);
            tell_object(me,HIW"姜太公说道：我听说在"+where->query("short")+"有一些大鱼，你去钓"+chinese_number(n)+"条，锻炼一下。\n" NOR);
            return 1;
        }
        if (me->query_skill("fishing",1)<100 || me->query_skill("discern",1)<100)
        {
            while (!objectp(where) || base_name(where) == "/adm/daemons/taskd" )
            {
                where = TASK_D->random_place();
                target = new(__DIR__"target");
                target->set("owner",me->query("id"));
                target->move(where);
                me->set("jtg/start",1);
                me->set("jtg/time",time());
                me->set_temp("jtg/where",where);
                me->set_temp("jtg/lv2",1);
                tell_object(me,HIW"姜太公说道：我听说在"+TASK_D->place_belong(where)+"有一名叫"+target->query("name")+"的人，你去和他请教一下，也许会有所助益。\n" NOR);
                return 1;
            }
        }
    }

}

int do_confirm()
{
    object me=this_player();
    if (!me->query_temp("姜太公"))
    {
        return 0;
    }
    else
    {
        message_vision("$N从今天起，决定退隐田园，做一个渔夫，不再理会江湖诸事。\n",me);
        CHANNEL_D->do_channel(this_object(), "jh", "从今日起"+me->query("name")+"决定退隐田园，做一个渔夫，不再理会江湖诸事。");
        me->delete_temp("姜太公");
        me->set("iamafisher",1);
        return 1;
    }
}

int ask_fish()
{
    object ob=this_object();
    object me=this_player();
    mapping skl;
    string *sname;
	int i,skill=100;
    skl = me->query_skills();
    if (me->query("iamafisher"))
    {
        command("say 如果老夫老眼不花，你就是个渔夫啊。\n");
        return 1;
    }
    if (me->query("family") || me->query("chushi/last_family"))
    {
        command("say 老夫已经看淡了江湖中的打打杀杀。你还是回你的门派继续修行吧。\n");
        return 1;
    }
	
    if (!skl)
    {
        command("say 你什么都不会啊，至少把钓鱼之术磨练到一定程度再来吧。\n");
        return 1;
    }
    
    else
    {
        sname  = sort_array( keys(skl), (: strcmp :) );
	    for(i=0; i<sizeof(skl); i++)
        {
		    if (skl[sname[i]] >= 1000 && SKILL_D(sname[i])->type() != "knowledge") //只有知识类技能可以保留，不许学其他职业技能。By Zine
			{
                command("say 你的技能也太驳杂了些，尤其有些武学之道可能会影响你，钓鱼就是讲究一个平心静气。\n");
                return 1;
            }
        }
        
    
        if (me->query_skill("fishing",1)<10)
        {
            command("say 我来考考你的悟性，把钓鱼之术磨练到一定程度再来吧。\n");
            return 1;
        }
        else
        {
            command("say 你真的愿意随老夫过这样淡泊的日子？江湖中的一切荣耀将于你烟消云散。\n");
            me->set_temp("姜太公",1);
            tell_object(me,HIW"如果你愿意，请用Confirm命令确认一下。\n"NOR);
            return 1;
        }
    }
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}