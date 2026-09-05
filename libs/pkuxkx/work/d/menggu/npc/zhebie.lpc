// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
#include "checking.h"
inherit NPC;

void create()
{
	set_name("哲别", ({"zhe bie", "zhe", "bie"}));
	set("title", WHT"神箭手"NOR);
	set("long", 
            HIR"他是草原上的第一神箭手哲别。\n"NOR);
	set("gender", "男性");
	set("age", 40);
    set("combat_exp", 150000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
    set("no_get",1);
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth3")->wear();
	
    call_out("check",2);
}
	
void die()
{
    this_object()->fullme();
    return;
}
void init()
{
    object me=this_player();
    object ob=this_object();
    if (me->query_temp("shediao/meetzhebie2")&&living(ob))
    {
        message_vision("$N和$n向东遥望，见远处尘土飞扬，人马不计其数，正向这里奔来。\n",ob,me);
        command("say 好兄弟，有弓箭吗？");
        tell_object(me,"郭靖家里似乎有一把小弓箭，赶紧去找一下。\n");
        me->delete_temp("shediao/meetzhebie2");
        me->set_temp("shediao/meetzhebie3",1);
        return;
    }
}
int start_1(object me)
{
    command("say 水，水……给我水。");
	tell_object(me,"你突然想到郭靖家大水缸里可以取些水来给这个人饮用。\n");
    return 1;
}

int start_2(object me)
{
    if (!me||base_name(environment(me))!="/d/menggu/menggubao5")
    {
        return 1;
    }
    message_vision("$N哈哈一笑，栽下马来。\n",this_object());
    me->set_temp("shediao/meetzhebie2",1);
    this_object()->unconcious();
    return 1;
}
int end_2(object me)
{
	object place;
	if (me)
	{
		tell_object(me,"临走时，哲别答应收你为徒，传你武功箭法。\n并约好在铁木真金帐相见。\n");
	}
	place=load_object("/d/menggu/menggubao5");
	place->delete("using");
	destruct(this_object());
	return 1;
}
int ending(object me,object tmz)
{
    object shuchi,bo;
    object ob=this_object();
    if (!me)
    {
        return 1;
    }
    if (base_name(environment(me))!="/d/menggu/menggubao5")
    {
        tell_object(me,"你吓得乱跑开去，不知到了哪里。\n");
        return 1;
    }
    if (me->query_temp("shediao/meetzhebie7"))
    {
        command("halt");
        message_vision(HIC+"$N被铁木真所折服倾倒，投其麾下。\n众人缓缓离去。\n"+NOR,ob);
        me->delete_temp("shediao");
        me->set("shediaoquest/zhebie",1);
        
        
        shuchi=this_object()->query("shuchi");
        destruct(shuchi);
        tmz->leave();
		call_out("end_2",2,me);
        return 1;
    }

}

int start_5(object me)
{
    object ob=this_object();
    object tmz;
    if (!me)
    {
        return 1;
    }
    if (base_name(environment(me))!="/d/menggu/menggubao5")
    {
        tell_object(me,"你吓得乱跑开去，不知到了哪里。\n");
        return 1;
    }
    ob->move("/d/menggu/menggubao5");
    message_vision(HIW"$N从草堆里钻了出来。\n"NOR,ob);
    command("say 可惜我不能死在英雄好汉手里。");
    if (me->query_temp("shediao/meetzhebie6"))
    {
        me->delete_temp("shediao/meetzhebie6");
        tmz=new(__DIR__"tmz");
        tmz->set("owner",me->query("id"));
        tmz->move("/d/menggu/menggubao5");
		tmz->visit();
        me->delete_temp("shediao/meetzhebie6");
        me->set_temp("shediao/meetzhebie7",time());
        call_out("ending",8,me,tmz);
        return 1;
    }
}

int start_4(object me)
{
    object shuchi=new(__DIR__"shuchi");
    if (!me)
    {
        return 1;
    }
    if (base_name(environment(me))!="/d/menggu/menggubao5")
    {
        tell_object(me,"你吓得乱跑开去。\n");
        return 1;
    }
    
    shuchi->move(environment(me));
    message_vision("$N走了过来。\n",shuchi);
    shuchi->set("owner",me->query("id"));
    this_object()->set("shuchi",shuchi);
    if (me->query_temp("shediao/meetzhebie5"))
    {
        message_vision("来人狠狠地抽打$N，企图逼迫$N说出哲别的下落。\n",me);
        me->delete_temp("shediao/meetzhebie5");
        me->set_temp("shediao/meetzhebie6",1);
        call_out("start_5",3,me);
        return 1;
    }
}

int start_3(object me)
{
    if (!me)
    {
        return 1;
    }
    if (base_name(environment(me))!="/d/menggu/menggubao5")
    {
        tell_object(me,"哲别被人抓走了，你遗憾地叹了口气。\n");
        return 1;
    }
    message_vision("追兵越来越近，这时已见旗帜晃动。你指了指旁边的草堆。\n",me);
    message_vision("$N明白了你的意思，赶紧躲了进去。\n",this_object());
    this_object()->move("/d/city/hideroom");
    if (me->query_temp("shediao/meetzhebie4"))
    {
        me->delete_temp("shediao/meetzhebie4");
        me->set_temp("shediao/meetzhebie5",1);
        me->start_busy(3);
        call_out("start_4",3,me);
    }
    return 1;
}

int accept_object(object me,object item)
{
    object ob=this_object();
    if (item->query("id")=="xiao gongjian"&&item->query("owner")==me->query("id")&&!me->query_temp("shediao/meetzhebie4"))
    {
        message_vision("$N接过$n的"+ob->query("name")+"，哈哈一笑，随即眉头一皱：我和别人打架，要大的。\n",ob,me);
        message_vision("$N摇了摇头。\n",me);
        me->set_temp("shediao/meetzhebie4",1);
        me->start_busy(4);
        call_out("start_3",4,me);
        return 1;
    }
    if (item->query("id")=="yipiao shui"&&me->query_temp("shediao/meetzhebie")&&me->query("shediaoquest/dmfy"))
    {
        message_vision("$N接过$n手中的水，牛饮开来。\n",ob,me);
        me->delete_temp("shediao/meetzhebie");
        me->start_busy(2+random(2));
        call_out("start_2",2,me);
        return 1;
    }
    return notify_fail("你这是何意？\n");
}