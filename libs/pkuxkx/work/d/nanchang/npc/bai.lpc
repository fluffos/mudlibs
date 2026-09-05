// 白振 Zine Dec 9 2010

inherit NPC;
#include <ansi.h>

int ask_job();
int ask_hand();
int ask_me();
int ask_rest();
int ask_quest();
int ask_done();
void create()
{
        set_name("老白",({ "lao bai", "bai", "laobai" }) );
        set("gender", "男性" );
        set("age", 40+random(20));
        set("long", "他是一位和气的老大爷，对人总是乐呵呵的。\n");
		set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
		set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 50000);
        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "你就喊我老白好了。",
            "here" : "这里就是南昌城啊！",
			"help" : (: ask_job :),
            "帮助" : (: ask_job :),
			"大擒拿手" : (: ask_hand :),
			"hand" : (: ask_hand :),
			"baizhen" : (: ask_me :),
			"白振" : (: ask_me :),
			"休息" : (: ask_rest :),
            "rest" : (: ask_rest :),
            "复命" : (: ask_done :),
            "done" : (: ask_done :),
            "quest" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
            
       	]) );
        set_skill("parry",250);
        set_skill("dodge", 250);
        set_skill("force",250);
        set_skill("literate",250);
        set_skill("qinna-shou",250);
        set_skill("hand",250);
        set_skill("bixue-xinfa",250);
        set_skill("longfeng-xiang",250);
        

        map_skill("parry","qinna-shou");
        map_skill("force","bixue-xinfa");
        map_skill("dodge","longfeng-xiang");
        map_skill("hand","qinna-shou");

        
        prepare_skill("hand","qinna-shou");
        setup();
        add_money("silver", 20+random(8)*10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
    object me=this_player();
    int exp=random(600);
    if (me->query_temp("jn/step6c")&&me->query("zhuangquest"))
    {
        me->set("jiangnanquest/step6",1);
        me->delete_temp("jn");
        me->add("combat_exp",exp);
        tell_object(me,HIW+sprintf("南昌的历练后你越发熟悉这个江湖。\n你的经验增加了%d点。\n",exp)+NOR);
        tell_object(me,"你去找江州的韩员外吧，他好像在找人帮他！\n");
    }
}

int ask_done()
{
    object me=this_player();
    if (!me->query_temp("jn/step6b"))
    {
        command("say 复命？搬砖头搞那么正是干嘛？\n");
        return 1;
    }
    else
    {
        command("say 我果然没有看错你，现在壮族山寨有只猛虎为害，你能去除掉它吗？\n");
        command("say 有什么不懂去问问长老，去壮族山寨可能需要司南，在南昌去老林的路上有卖的。\n");
        me->delete_temp("jn/step6b");
        me->set_temp("jn/step6c",1);
        return 1;
    }
}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
   
    if (me->query("jiangnanquest/step6"))
    {
        command("say 你去找江州的韩员外吧，他好像在找人帮他！\n");
		return 1;
    }
    else
    {
        if (me->query("jiangnanquest/step5"))
        {
            command("say 我这些砖头都要搬到北门外的，你能帮我吗？\n");
            me->set("jntemp",me->query("ncjob"));
            me->set_temp("jn/step6a",1);
		    return 1;
        }
        else
        {
            command("say 江南八镇就是建康府、镇江、南昌、江州、昆明、成都、岳阳和苗疆。\n");
		    return 1;
        }
		return 1;
    }
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    if (me->query("combat_exp")<50000 || me->query("age")<16)
	{
		command("say 你太小了，恐怕不够力帮我搬东西啊！");
		return 1;
	}
    if (me->query("jiangnan/randomskill"))
    {
        command("say 这里不需要人了，多谢啊！");
		return 1;
    }
    else
    {
        command("say 既然你愿意，那就帮我把这些砖块搬到北门外，堆(dui)起来吧。");
        me->set_temp("ncjob/permit",1);
        return 1;
    }
}

int changeback()
{
    object ob=this_object();
    ob->delete("title");
    ob->set("name","老白");
    ob->delete_temp("ncjob/finish");
    return 1;
}

int ask_me()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("ncjob/bai"))
    {
        command("say 你又来消遣老白啦？乡里乡亲的，谁还不认识谁啊？");
        return 1;
    }
    else
    {
        message_vision("老白神情一振：看来你是知道了？\n",me);
        message_vision("老白道：不错，老夫就是白振，洗手归隐多年了。\n",me);
        ob->set("title",HIY+"金爪"+HIW+"铁钩"+NOR);
        ob->set("name","白振");
        remove_call_out("changeback");
        call_out("changeback",120);
        ob->set_temp("ncjob/finish",1);
        me->set_temp("ncjob/finish",1);
        return 1;
    }
}

int ask_hand()
{
    object me=this_player();
    object ob=this_object();
    if (!ob->query_temp("ncjob/finish")||!me->query_temp("ncjob/finish"))
    {
        command("say 鸡爪我吃过不少，大擒拿手就没听说过。");
        return 1;
    }
    else
    {
        command("say 我们也算有缘，我就把早年一些功夫传授于你吧。");
        me->set_skill("qinna-shou",10);
        tell_object(me,HIC"你学会了大擒拿手！\n"NOR);
        me->improve_skill("hand",1);
        me->delete("ncjob");
        me->delete_temp("ncjob");
        command("say 大擒拿手招招料敌先机，也算武林中一门绝艺，你要勤加练习。");
        me->set("jiangnan/randomskill",1);
        return 1;
    }
}

int ask_rest()
{
    object me=this_player();
    if (!me->query_temp("ncjob/permit"))
    {
        command("say 又来消遣老白，你根本就没帮我嘛。");
        return 1;
    }
    else
    {
        command("say 好吧，那就休息一会好了。");
        me->delete_temp("ncjob");
        return 1;
    }
}