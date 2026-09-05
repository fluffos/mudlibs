//by hehe
//2003.3.21
//MODIFIED BY ZINE 2010
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("鱼饵", ({"yuer","er"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else
	{
		set("unit", "个");
        set("long","这是个钓鱼用的鱼饵。需要先(gua)在鱼钩上才能钓鱼。\n");
                set("value", 2);
        set("material", "steel");
    }
}
void init()
{
	add_action("do_gua","gua");
	add_action("do_diao","diao");
}
int do_gua(string arg)
{
	object me;
    string family;
    string *familys=({"丐帮","全真派","天龙寺","古墓派","日月神教","桃花岛","峨嵋派","明教","华山派","少林派","武当派","星宿派"});
	me=this_player();
    family=me->query("family/family_name");
	if(!arg)
	{
		message_vision("你要挂什么？\n",me);
		return 1;
	}
	if((string)arg!="yuer")
	{
		tell_object(me,"你要挂什么?\n",me);
		return 1;
	}
    if (member_array(family,familys)!=-1)
    {
        tell_object(me,"你想起之前师门给你的教诲，决定不在这里消磨光阴了。\n");
        return 1;
    }
	if(me->query("age")>=18 && !me->query("iamafisher"))//渔夫可以永久掉小鱼
	{
        tell_object(me, "你老大不小的人了，别在这里耗时间钓鱼了！\n");
		return 1;
	}
	if(!(present("yugou",me)))
	{
		tell_object(me,"你没有鱼钩啊，搞什么鬼啊！\n");
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
		tell_object(me,"你还忙着那，等会再钓吧!\n");
		return 1;
	}
    if (me->query("combat_exp")>=5000) //for 10大主流门派，新手判断
    {
        me->set("newbiediaoyu",1);
    }
	t=5 + random(5) * 5;
	me->start_busy(t);
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
	if (!objectp(me)) return 1;
    if (!environment(me)) return 1;
    if (me->is_ghost()) return 1;

	if(me->is_busy())
	{
		tell_object(me,"鱼漂一上一下，你紧张的手心都出汗了！\n");
		call_out("end_diaoyu",5,me);
		return 1;
	}
	else
	{
                switch(random(10)) {
                        case 0 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N一提杆，钓到了一条"+ HIR "大鲤鱼"NOR +"，恭喜，恭喜。 \n\n",me);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->set("name",HIR "大鲤鱼"NOR);
		ob->move(me);
		call_out("reward",0,me);
                           break;
                        case 1 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N猛一提杆，钓到了"+ CYN "一个破草帽"NOR +"，晦气，晦气。  \n",me);
                             message_vision(HIW "$N看着破草帽不由的发呆了。  \n\n" NOR,me);
		me->set_temp("murong/yuer",0);
                             me->receive_damage("jing",10);
		destruct(yuer);
                           break;
                        case 2 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N鱼漂晃动，$N心里一急，猛的一提杆，$N钓到了"+ RED "一件红色的肚兜。 \n"NOR,me);
                             message_vision(HIB "$N连声叫到：晦气，晦气。 \n\n" NOR,me);
		me->set_temp("murong/yuer",0);
                             me->receive_damage("jing",10);
		destruct(yuer);
                           break;
                        case 3 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N一提杆，钓到了一条"+ HIC "鲶鱼"NOR +"，恭喜，恭喜。 \n\n",me);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->set("name",HIC "鲶鱼"NOR);
		ob->move(me);
		call_out("reward",0,me);
                           break;
                        case 4 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N一提杆，钓到了一条"+ HIG "鲑鱼"NOR +"，恭喜，恭喜。 \n\n",me);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->set("name",HIG "鲑鱼"NOR);
		ob->move(me);
		call_out("reward",0,me);
                           break;
                        case 5 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N一提杆，钓到了一条草鱼，恭喜，恭喜。 \n\n",me);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->set("name","草鱼");
		ob->move(me);
		call_out("reward",0,me);
                           break;
                        case 6 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N一提杆，钓到了一条"+ HIB "鲟鱼"NOR +"，恭喜，恭喜。 \n\n",me);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->set("name",HIB "鲟鱼"NOR);
		ob->move(me);
		call_out("reward",0,me);
                           break;
                        case 7 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N猛一提杆，钓到了"+ WHT "一个废旧的睡袋"NOR +"，晦气，晦气。 \n",me);
                             message_vision(HIY"$N看着废旧的睡袋，眼睛立刻红了。 \n\n"NOR,me);
		me->set_temp("murong/yuer",0);
                             me->receive_damage("jing",10);
		destruct(yuer);
                           break;
                        case 8 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N猛的一提杆，扯的太急了，线断了，鱼跑了，可惜，可惜。 \n",me);
                             message_vision(HIC "$N不由的在心里大骂:ダドパ。 \n\n" NOR,me);
		me->set_temp("murong/yuer",0);
                             me->receive_damage("jing",10);
		destruct(yuer);
                           break;
                        case 9 :
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
                             message_vision("$N一提杆，钓到了一条"+ HIM "娃娃鱼"NOR +"，恭喜，恭喜。 \n\n",me);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->set("name",HIM "娃娃鱼"NOR);
		ob->move(me);
		call_out("reward",0,me);
                           break;
                                 }
	return 1;
	}
}
int reward(object me)
{
	object ob = this_object();
	int a,b;
	if (!me) return 1; 
    if (me->query_skill("fishing",1)<15 && !me->query("family")&& random(3)==0 && !me->query("iamafisher")&& wizardp(me))
    {
        me->improve_skill("fishing", 1+random(2));
        tell_object(me,"你在实践中对钓鱼之术有了些提高。\n");
    }
    if (me->query_skill("fishing",1)<15 && !me->query("family")&& random(3)==0 && !me->query("iamafisher"))
    {
        me->improve_skill("discern", 1+random(2));
        tell_object(me,"你在实践中对辨位之术有了些提高。\n");
    }
    if (!me->query("family") && !me->query("chushi/last_family") && me->query("iamafisher") && random(2))
    {
        me->improve_skill("fishing", 1+random(2));
        tell_object(me,"你在实践中对钓鱼之术有了些提高。\n");
        me->improve_skill("discern", 1+random(2));
        tell_object(me,"你在实践中对辨位之术有了些提高。\n");
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
    
	if((me->query("combat_exp"))<10000)
	{
// 提高钓鱼的收益 by lordstar@20171014
		a=100+random(100);
		b=a;
		b/= (3+random(3));
		me->add("combat_exp",a);
                me->add("exp/diaoyu",a);
		me->add("potential",b);
                me->add("pot/diaoyu",b);
		me->receive_damage("jing", 10);
//		me->improve_skill("sword",a);
		tell_object(me,"你的经验增加了" + chinese_number(a) + "点。\n");
		tell_object(me,"你的潜能增加了" + chinese_number(b) + "点。\n");
	}
	else if((me->query("combat_exp"))<50000)
	{
		a=150+random(150);
		b=a;
		b/= (4+random(4));
		me->add("combat_exp",a);
                me->add("exp/diaoyu",a);
		me->add("potential",b);
                me->add("pot/diaoyu",b);
		me->receive_damage("jing", 15);
//		me->improve_skill("sword",a);
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

	destruct(ob);
	return 1;
}






