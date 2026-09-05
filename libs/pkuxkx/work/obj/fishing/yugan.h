//Zine 钓鱼

#include <ansi.h>
#include <fishing.h>

void init()
{
	add_action("do_gua","gua");
	add_action("do_diao","diao");
}
int do_gua(string arg)
{
	object ob,me,yuer;
	me=this_player();
    ob=this_object();
	if(!arg)
	{
		tell_object(me,"你要挂什么？\n");
		return 1;
	}
    if (!present(arg,me))
    {
        tell_object(me,"你要挂的东西不在你身上。\n");
        return 1;
    }
    yuer=present(arg,me);
    if (!yuer->query("is_yuer_for_fishing"))
    {
        tell_object(me,"你只能把鱼饵挂在鱼竿上。\n");
        return 1;
    }
	if(me->query_temp("murong/yuer"))
	{
		tell_object(me,"你的鱼钩上已经有了一个鱼饵了，不能再挂了！\n");
		return 1;
	}
    tell_object(me,"你小心的把鱼饵挂到鱼钩上。\n");
    if (!userp(me))
    {
        message_vision("$N小心的把鱼饵挂到鱼钩上。\n",me);
    }
	me->set_temp("murong/yuer",1);
    ob->add("assist_fishing",(int)ob->query("assist_fishing")+(int)yuer->query("assist_fishing"));
	destruct(yuer);
    return 1;
}
int do_diao(string arg)
{
	object me=this_player();
    object room=environment(me);
	int t;
	
	if(!arg)
	{
		tell_object(me,"你钓什么啊！\n");
		return 1;
	}
    if (!room->query("couldfish"))  //用地点的记号判断是否可钓
	{
		tell_object(me,"钓什么钓，也不看看什么地方？\n");
		return 1;
	}
	if(arg!="fish" && arg!="yu" && arg!="鱼")
	{
		tell_object(me,"你想钓什么你说清楚啊！\n");
		return 1;
	}
	if(!(me->query_temp("murong/yuer")))
	{
		tell_object(me,"你还没把鱼饵挂在鱼钩上哪！\n");
		return 1;
	}
	if((me->query("jing"))<20)
	{
		tell_object(me,"你太累了，歇会再钓吧！\n");
		return 1;
	}
	if(me->is_busy())
	{
		tell_object(me,"你还忙着那，等会再钓吧！\n");
		return 1;
	}
    if (me->query("combat_exp")>=5000) //for 10大主流门派，新手判断
    {
        me->set("newbiediaoyu",1);
    }
    me->set_temp("murong/diaoyu_place",environment(me));
    me->set_temp("murong/diaoyu_init_time",time());
        tell_object(me,"你把鱼钩扔到水中，紧张的看着鱼漂的浮动。\n");
        if (!userp(me))
    {
        message_vision("$N把鱼钩扔到水中，紧张的看着鱼漂的浮动。\n",me);
    }
	call_out("end_diaoyu",5,me);
	return 1;
}
int end_diaoyu(object me)
{
	object ob;
	object yuer = this_object();
    int cd,bonus;
	if (!objectp(me)) return 1;
    if (!environment(me)) return 1;
    if (environment(me)!=me->query_temp("murong/diaoyu_place"))
    {
        tell_object(me,"因为乱动，你的鱼儿早跑了。\n");
        return 1;
    }
	if(me->is_busy())
	{
		tell_object(me,"因为你三心二意，鱼儿跑掉了。\n");
		return 1;
	}
    cd=(int)me->query_skill("discern",1);
    cd=59-random(15)-cd/20;
    if (cd<30)
    {
        cd=30;
    }
    if (time()-(int)me->query_temp("murong/diaoyu_init_time")<cd&&random(500))
    {
        tell_object(me,"鱼漂一上一下，你紧张的手心都出汗了！\n");
		call_out("end_diaoyu",5,me);
		return 1;
    }
	else
	{
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
		me->set_temp("murong/yuer",0);
		bonus=yuer->gene_fish();
		call_out("reward",0,me,bonus);
        return 1;
	}
}
int reward(object me,int bonus)
{
    string family;
    string *familys=({"丐帮","全真派","天龙寺","古墓派","日月神教","桃花岛","峨嵋派","明教","华山派","少林派","武当派","星宿派"});
    int a,b;
    family=me->query("family/family_name");
	
	if (!me) return 1; 
    if (me->query_skill("fishing",1)<30 && !random(3)&& !me->query("iamafisher"))
    {
        me->improve_skill("fishing", 1+random(bonus));
        tell_object(me,"你在实践中对钓鱼之术有了些提高。\n");
    }
    if (me->query_skill("discern",1)<20 && !random(4) && !me->query("iamafisher"))
    {
        me->improve_skill("discern", 1+random(bonus));
        tell_object(me,"你在实践中对辨位之术有了些提高。\n");
    }
    if (me->query("iamafisher") && random(2))
    {
        if (random(2))
        {
            me->improve_skill("fishing", 1+random(bonus));
            tell_object(me,"你在实践中对钓鱼之术有了些提高。\n");
        }
        if (random(2))
        {
            me->improve_skill("discern", 1+random(bonus));
            tell_object(me,"你在实践中对辨位之术有了些提高。\n");
        }
    }
    if (me->query("jtg/start"))
    {
        if (base_name(environment(me))!=base_name(me->query_temp("jtg/where")))
        {
            tell_object(me,HIM"这里似乎不是姜太公要你去修行的所在。\n"NOR);
        }
        if (base_name(environment(me))==base_name(me->query_temp("jtg/where")))
        {
            me->add_temp("jtg/count",1);
        }
        
    }
    if (member_array(family,familys)!=-1)
    {
        tell_object(me,"你想起之前师门给你的教诲，暗自为消磨光阴而感到后悔。\n");
        return 1;
    }
    if(me->query("age")>=18 && !me->query("iamafisher"))//渔夫可以永久掉小鱼
	{
        tell_object(me, "你老大不小的人了，钓鱼是可以怡情，但对你也没有其他什么帮助了。\n");
		return 1;
	}
	if((me->query("combat_exp"))<10000)
	{
		a=10+random(10);
		b=a/5;
		me->add("combat_exp",a);
                me->add("exp/diaoyu",a);
		me->add("potential",b);
                me->add("pot/diaoyu",b);
		me->receive_damage("jing", b);
		tell_object(me,"你的经验增加了" + chinese_number(a) + "点。\n");
		tell_object(me,"你的潜能增加了" + chinese_number(b) + "点。\n");
	}
	else if((me->query("combat_exp"))<50000)
	{
		a=20+random(20);
		b=a/8;
		me->add("combat_exp",a);
                me->add("exp/diaoyu",a);
		me->add("potential",b);
                me->add("pot/diaoyu",b);
		me->receive_damage("jing", b);
		tell_object(me,"你的经验增加了" + chinese_number(a) + "点。\n");
		tell_object(me,"你的潜能增加了" + chinese_number(b) + "点。\n");
	}
	else
	{
        if (!me->query("iamafisher"))  //渔夫就不需要通知了，by Zine
        {
            tell_object(me,"你已经有足够的资本出去闯荡了，不用再浪费时间在钓鱼上了！\n");
        }
	}

	return 1;
}






