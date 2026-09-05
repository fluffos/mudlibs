
#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"神木王鼎"NOR, ({ "shenmu wangding", "wangding", "ding" }) );
	set_weight(4000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
        set("long", "一只六寸来高的小小木鼎，呈深黄颜色。木鼎彤琢甚是精细，
木质坚润似似玉，木理之中隐隐约约的泛出红丝。若是在鼎中
燃烧(burn)香料，片刻间便能诱引毒虫到来。待毒虫钻入鼎内，
你可以查看(chakan)、倒掉毒虫(dao)或是炼毒(liandu)。\n\n");
 		set("unit","个");
		set("no_sell",1);
        set("no_beg",1);
        set("no_give",1);
        set("no_get",1);
        set("no_store",1);
		set("no_steal",1);
        set("no_pawn", 1);
		set("value",0);
		set("usage_times", 2000);	
	}
        setup();
}

void init()
{
        add_action("do_burn", "burn");
        add_action("do_chakan", "chakan");
        add_action("do_open", "dao");
        add_action("do_liandu", "liandu");
}

int do_open(string arg)
{
	object ob = this_object();
	if (this_player()->is_busy())
		return notify_fail("你正忙着呢，先把手上的事情忙完了再说吧。\n");
	if (!ob->query("worm") || !ob->query("worm_name"))
		return notify_fail("你打开神木王鼎往外瞎挥了挥，可是鼎里空空如也，啥都没有！\n");
	tell_object(this_player(), HIY"你打开神木王鼎的盖子，把鼎中一只"+ob->query("worm_name")+HIY"倒掉。\n"NOR);
	ob->delete("worm");
	ob->delete("worm_name");
	return 1;
}

int do_chakan(string arg)
{
	object ob = this_object();
	if (!ob->query("worm") || !ob->query("worm_name"))
		return notify_fail("你的神木王鼎空空如也，里面啥也没有！\n");
	tell_object(this_player(), "一只"+ob->query("worm_name")+"正静静地趴在你的木鼎里。\n你可以开始炼毒(liandu)了，如果不要它就开鼎倒掉(dao)。\n");
	return 1;
}

int do_burn(string arg)
{
	object me = this_player();
	object ob = this_object();
	object here = environment(me);
	if (me->is_busy())
		return notify_fail("你正忙着呢，先把手上的事情忙完了再说吧。\n");
	if (ob->query("worm") && ob->query("worm_name"))
		return notify_fail("神木王鼎里已经有毒虫了，点燃香料会把它烧成灰的！\n");
	if (me!= environment(ob))
		return notify_fail("不把神木王鼎拿起来怎么点燃香料？\n");
	if (ob->query("owner") != me->query("id"))
		return notify_fail("这个神木王鼎不是你找回来的，你不懂得如何使用！\n");
	if (!here->query("use_shenmu_ding"))
		return notify_fail("这里地形不对，燃烧再多香料也引不来毒虫，还是另外找个合适的地方吧。\n");	
	tell_object(me, HIY"你掏出几块香料，从每一块香上捏了少许放入神木王鼎，打着火烧了起来，然后合上鼎盖，静静地等待……\n\n"NOR);	
	me->start_busy(5);
	remove_call_out("burn_in_ding");
	call_out("burn_in_ding", 4, me);
	return 1;
}

void burn_in_ding(object me)
{
	string* color = ({ HIR, RED, HIY, YEL, HIB, BLU, HIG, HIC, CYN, MAG, HIM, WHT });
	object ob = this_object();
	object here = environment(me);
	string worm;
	me->start_busy(0);
	if (!objectp(ob) || me!= environment(ob))
	{
		tell_object(me, HIM"坏了，你怀里的神木王鼎不见了！\n"NOR);
		return;
	}
	ob->add("usage_times", -1);
	if (!here->query("use_shenmu_ding"))
	{
		tell_object(me, HIM"看起来这里地形不对，难怪啥毒虫也没吸引来。\n"NOR);
		return;
	}
	if ((int)ob->query("usage_times")<=0)
	{
		tell_object(me, HIR"你的神木王鼎中忽然火光迸发，香料越烧越旺，把宝鼎烧成了灰烬！\n\n"NOR);
		destruct(ob);
		return;
	}
	switch (random(11))
	{
	  case 0:
	  case 1: 
	  case 2: ob->set("worm", 1); worm = color[random(sizeof(color))] +"蜘蛛"NOR; break;
	  case 3: 
	  case 4: 
	  case 5: ob->set("worm", 2); worm = color[random(sizeof(color))] +"蝎子"NOR; break;
	  case 6:
	  case 7: 
	  case 8: ob->set("worm", 3); worm = color[random(sizeof(color))] +"蜈蚣"NOR; break;
	  case 9: 
	  default: ob->set("worm", 4); worm = HIW"冰蚕"NOR;
	}
	ob->set("worm_name", worm);
	tell_object(me, HIR"一只"+worm+HIR"闻到你的木鼎中发出的香气，径身游向木鼎，从鼎下的孔中钻了进去，便不再出来。\n\n"NOR);
}

int do_liandu(string arg)
{
	object ob = this_object();
	object me = this_player();
	if (!ob->query("worm") || !ob->query("worm_name"))
		return notify_fail("你的神木王鼎里啥都没有，拿什么炼毒？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢，先把手上的事情忙完了再说吧。\n");
	if (!environment(me)->query("use_shenmu_ding"))
		return notify_fail("这里地形不对，不适合在这里炼毒。\n");
	if (me->query("shen")>-10000)
		return notify_fail("你还不够阴狠毒辣，看到神木王鼎里的毒虫都有些害怕，哪敢用它来炼毒？\n");
	if (me->query_skill("force",1)<100*((int)ob->query("worm")-1))
		return notify_fail("你的内功修为不够，还无法抵御剧毒，用神木王鼎炼毒会有生命危险！\n");
    if ((int)me->query("max_neili") < 1000*((int)ob->query("worm")-1))
        return notify_fail("你的内力太弱，还无法抵御剧毒，用神木王鼎炼毒会有生命危险！\n");
	if (me->query_skill("poison",1)<100)
		return notify_fail("你的毒技修为不够，还不懂得如何驾驭剧毒，用神木王鼎炼毒会有生命危险！\n");
	if (me->query_skill("poison",1)<100*(int)ob->query("worm"))
		return notify_fail("你的毒技修为不够，还无法驾驭"+ob->query("worm_name")+"这样的大毒物，还是先找一些小毒虫来练练手吧！\n");
	me->start_busy(20);
	if (ob->query("worm")==4)
	{
		tell_object(me, YEL"你双足一挺，倒转身子，脑袋从胯下钻出，左手抓足，右手伸入瓮中。\n"NOR);
		tell_object(me, HIC"突然你的食指尖上微微一痒，一股寒气优似冰箭，循着手臂，迅速无伦的射入胸膛。\n"
			+HIW"你急忙运功引导那道寒气，顺着脉络自指而臂，又自胸腹而至头顶，细线所到之处奇寒彻骨。\n"NOR);
        call_out("checkst2",3,me);
	}
	else
	{
		tell_object(me, YEL"你盖上了神木王鼎的鼎盖，过得片刻，鼎中的毒虫化成一滴滴的黑血，沿着木鼎的孔滴了下来。\n"
			+MAG"你脸现喜色，忙伸掌将血液接住，盘膝运功，将血液都吸入掌内。\n"NOR, me);
		ob->delete("worm_name");
        call_out("checkst1",3,me);
	}
	return 1;
}

int checkst1(object me)
{
    
    string* desc=({"毒液在你体内徘徊，久久不能凝聚。\n","你潜运内力，试图融合毒液。\n","你的内力和毒液开始慢慢融合。\n","毒液被你吸收入体内，到处乱窜。\n",});
    string* color=({RED,YEL,BLU,GRN,CYN,HIM,WHT});
	object here=environment(me);
	object ob=this_object();
	int poison=me->query_skill("poison",1);
	int exp;
    if (me->query_temp("liandutimes")>10+random(10))
    {
		me->start_busy(0);
		if (!here->query("use_shenmu_ding"))
        {
            tell_object(me,"你忽然察觉四周地形不对，继续炼毒恐有危险，赶紧停止了炼毒。\n");
			ob->delete("worm");
			ob->delete("worm_name");
            return 1;
        }
		exp = 600 + poison * ((int)me->query("int")+(int)me->query("con")) * (int)me->query_temp("liandutimes")/150;
		switch ((int)ob->query("worm"))
		{
			case 3: exp /= 2; if (poison>500) exp/=100; break;
			case 2: exp = exp*2/5; if (poison>350) exp/=100; break;
			default: exp /= 3; if (poison>200) exp/=100; 
		}
		if (exp<10) exp=10;
        me->improve_skill("poison", exp);
		ob->delete("worm");
        tell_object(me, RED"你只觉得毒液在体内行走一周天后，完全与你的内力融合。\n"NOR"你对基本毒技的领会又加深了一些！\n");
        me->set_temp("liandutimes",0);
        return 1;         
    }
    else
    {
        if (!here->query("use_shenmu_ding"))
        {
			me->start_busy(0);
            tell_object(me,"你忽然察觉四周地形不对，继续炼毒恐有危险，赶紧停止了炼毒。\n");
			ob->delete("worm");
			ob->delete("worm_name");
            return 1;
        }
        tell_object(me,color[random(sizeof(color))]+desc[random(sizeof(desc))]+NOR);
        me->add_temp("liandutimes",1);
        me->add_busy(2);
        call_out("checkst1",2,me);
        return 1;
    }
}

int checkst2(object me)
{
    
    string* desc=({"你隐隐觉得有一条极冷的冰线，在四肢百骸中行走，有如冰蚕在身体内爬行一般。\n",
		"你潜运内力，依循不同姿式引导冰线在各处经脉中游走，体内一时急凉、一时急暖，说不出的古怪。\n",
		"冰蚕咬着你的食指，一条冰线从冰蚕之口流入你的身体，在体内兜了个圈子，又流回冰蚕口中。\n",
		"只见冰蚕身上有丝丝热气冒出，而你的衣服、手脚上，却都蒙上了一层薄薄的白霜。\n",});
    int exp;
	object here=environment(me);
    if (me->query_temp("liandutimes")>10+random(10))
    {
		me->start_busy(0);
		if (!here->query("use_shenmu_ding"))
        {
            tell_object(me,"你忽然察觉四周地形不对，继续炼毒恐有危险，赶紧停止了炼毒。\n");
            return 1;
        }
		exp = 800 + me->query_skill("poison",1) * ((int)me->query("int")+(int)me->query("con")) * (int)me->query_temp("liandutimes")/300;
        me->improve_skill("poison", exp*2/3+random(exp)/3);
        me->improve_skill("bingcan-duzhang", exp*2/3+random(exp)/3);
        tell_object(me, RED"你只觉得冰线在体内行走一周天后，完全与你的内力融为一体。\n"NOR"你对冰蚕之毒的领会又加深了一些！\n");
        me->set_temp("liandutimes",0);
		if (!random(3))
		{
			tell_object(me, HIY"嗒的一声轻响，冰蚕从你的手指上掉了下来，跌在地上，肚腹朝天，再也不动了……\n"NOR);
			this_object()->delete("worm");
			this_object()->delete("worm_name");
		}
        return 1;
    }
    else
    {
        if (!here->query("use_shenmu_ding"))
        {
			me->start_busy(0);
            tell_object(me,"你忽然察觉四周地形不对，继续炼毒恐有危险，赶紧停止了炼毒。\n");
			this_object()->delete("worm");
			this_object()->delete("worm_name");
            return 1;
        }
        tell_object(me,HIW+desc[random(sizeof(desc))]+NOR);
        me->add_temp("liandutimes",1);
        me->add_busy(2);
        call_out("checkst2",2,me);
        return 1;
    }
}