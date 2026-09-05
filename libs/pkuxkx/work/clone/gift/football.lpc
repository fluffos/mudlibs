// football.c	庆祝中国出线专用足球
// created by icer
#include <ansi.h>

inherit ITEM;

int do_kick(string arg);
int do_kickback(object me);
int do_kickother(object me, object ppl);
int do_kick1(object me,int i);
int do_kick2(object me);

string *news = ({
	"日本首相小泉纯一狼在做演讲时被一个突然飞来的足球砸中，倒地不醒，已经送入医院抢救。\n" ,
	"日本自卫队的一艘欲派往海外的军舰突然起火爆炸，目击人称当时一个足球大小的火球从东方\n沿海飞来，正中舰身，军舰随即爆炸沉没。\n" ,
	"朝鲜政府发言人谴责韩国向其领土发射了一枚球型炸弹，引起一场巨大的爆炸。\n" ,
	"韩国女星金喜善拍片时被一个足球击中脸部，在场人士称事件发生两分钟后金喜善的\n脸部可与猪头相比。\n" ,
	"东京铁塔的一脚被一只天外飞来的足球击毁，摇摇欲坠，铁塔周围居民已经紧急疏散。\n日本政府称这是一次针对日本自卫队将派赴海外的恐怖主义行动。\n" ,
	"韩国现正流行一种足球病毒，此病毒发作时一只足球会从屏幕上呼啸而过，上面隐约有\n『Made in China』字样。\n" ,
	"位于瑞士洛桑的国际奥委会总部的奥运五环标志中代表亚洲的一环忽然被一只不知何处\n而来的足球所代替，而原先的一环以被砸得不知所踪。\n" ,
	"美国一架侦察机在阿富汗进行侦察任务时突然发生故障，紧急迫降于巴基斯坦。经检查发现\n其左侧翼不知被什么武器砸出了一个足球大小的漏洞。塔利班政权否认进行了这次袭击。\n" ,
	"阿富汗塔利班政权最近俘虏了一名美国侦察兵。据参加战斗的士兵称他们听到一声惨叫，随后\n发现附近有一个美国兵昏迷不醒，旁边不知哪来一个足球还在滚动。\n" ,
});

	
void create()
{
	set_weight(80);
	set_name("足球", ({"football","ball"}));
	set("long", "这是一只德国世界杯指定用球！\n下面隐约还有『Made in China，出口转内销』的字样。\n");
	set("unit", "个");
}

void init()
{
	add_action("do_kick","kick");
}

int do_kickback(object me)
{
	if (objectp(me))
	{
		write("你正在等得发呆，忽见半空中一个小黑点急速变大，没等你反应过来，\n足球已经砸到了你的脸上，你感觉眼前一黑，重重摔在了地上。\n");
		me->unconcious();
		tell_room(environment(me),"你听到一阵呼啸，然后是『砰』、『咣当』两声，\n" + me->name() + "的脸被一只足球砸得跟猪头一样，昏倒在地。\n",me);
		this_object()->move(me);
	}
	return 1;
}

int do_kickother(object me,object ppl)
{
	if (objectp(me) && objectp(ppl))
	{
		write("你看到没了足球的踪影，正在懊悔，却听得不知何处传来『哎哟』一声惨叫，接着有人高声\n叫骂『这是谁这么乱扔东西啊！？』，你一听不好，赶紧溜了。\n");
		tell_object(ppl,"你忽然觉得脑后一阵疼痛，大叫一声『哎哟』！晕倒在地。\n");
		tell_room(environment(ppl),"你忽然看到一只足球飞了过来，急忙躲开。球不偏不倚，正好砸在" + ppl->name() + "的后脑勺上，\n" + ppl->name() + "惨叫一声，昏倒在地。\n",ppl);
		this_object()->move(ppl);
		ppl->unconcious();
		message( "channel:" + "chat",HIM + "【新闻】" +  ppl->name() + "被一只飞来足球击中后脑勺，造成轻微脑震荡，口吐白沫，昏到在地。\n" + NOR, users() );
		message( "channel:" + "rumor", HIM + "【谣言】某人：是" + me->name() + "干的！我亲眼看见的！\n" + NOR,users());
	}
	return 1;
}

int do_kick1(object me,int i)
{
	if (objectp(me))
	{
		if (i == 1)
		{
			message( "channel:" + "chat",HIM + "【新闻】06年德国世界杯结束后，冠军队所有队员都在比赛用球上签下了自己的名字。\n但是这只足球5分钟后被不知哪里飞来的足球撞得失踪了！\n" + NOR, users() );
                	message( "channel:" + "rumor", HIM + "【谣言】某人：是" + me->name() + "干的！我亲眼看见的！\n" + NOR,users());
			this_object()->set("long","这只足球是世界杯决赛的比赛用球，上面有全体冠军队队员的签名，非常宝贵。\n");
		}
		else
		{
			message( "channel:" + "chat",HIM + "【新闻】世界各国纷纷报道发现一球状不明飞行物从其领空快速穿越，具体这个物体是什么还不清楚。\n" + NOR, users() );
                	message( "channel:" + "rumor", HIM + "【谣言】某人：是" + me->name() + "干的！我亲眼看见的！\n" + NOR,users());
			this_object()->set("long","这只足球上盖满了世界各国的海关印章，原来是周游过世界的。应该比较值钱！\n");
		}
		this_object()->set("value",100000);
		write("你忽然发现刚踢出去的球又自己飞回来了！不禁欣喜若狂！\n");
		tell_room(environment(me),"你看到" + me->name() + "忽然象捡了宝一样手舞足蹈，做痴呆状。\n",me);
		this_object()->move(me);
	}
	else	
		destruct(this_object());
	return 1;
	
}

int do_kick2(object me)
{
	if (objectp(me))
	{
		message( "channel:" + "chat",HIM + "【新闻】" + news[random(sizeof(news))] + NOR, users() );
                message( "channel:" + "rumor", HIM + "【谣言】某人：是" + me->name() + "干的！我亲眼看见的！\n" + NOR,users());
                write("你忽然感觉一阵心虚，偷偷看了别人几眼，还好，没人认出你来。\n");
		tell_room(environment(me),"你看到" + me->name() + "鬼鬼祟祟向四处张望，看到没人注意它，又装得若无其事的样子。\n",me);
	}
	destruct(this_object());
	return 1;
}

int do_kick(string arg)
{
	int chance;
	object shoes;
	object me = this_player();
	object ppl;
	
	if (arg != "football" && arg != "ball")
		return 0;
	if (me->query("kaizhan/football") == 3)
	{
		if (objectp(shoes = present("shoes",me)))
		{
			write("你抬腿狠狠向足球踢去，不料脚下一滑，踢了个空，你的鞋子却象一颗炮弹一样\n飞得不知去向。\n");
			tell_room(environment(me),"你听到『扑通』一声，回头一看，" + me->name() + "不知为何狠狠地摔了个狗啃泥，趴在地上爬不起来。\n",me);
			destruct(shoes);
			return 1;
		}
		else
		{
			write("你抬腿狠狠向足球踢去，不料脚下一滑，踢了个空，再听『咯嚓』一声，你感到\n一阵钻心的疼痛，眼前天旋地转，倒在地上。\n");
			tell_room(environment(me),"你听到『咯嚓』、『扑通』一阵乱响，回头一看，" + me->name() + "抱着腿躺在地上疼得死去活来，涕泪横流。\n",me);
			me->receive_wound("qi",me->query("eff_qi")-1);
			me->receive_damage("qi",me->query("qi")-1);
			return 1;
		}
	}	
	me->add("kaizhan/football",1);		
	
	if (random(100) >= 80)
	{
		ppl = users()[random(sizeof(users()))];

		if (ppl == me)
		{
			write("你将足球高高抛起，待球落下，抬脚怒射，『砰』的一声，球见高不见远，笔直向上飞去......你惊讶得张大了嘴巴。\n");
			tell_room(environment(me),"你听到『砰』的一声巨响，转头一看，" + me->name() + "站在那里望着天空，张着大嘴傻傻地不知道在想什么。\n",me);
			this_object()->move("/clone/misc/void");
                	message( "channel:" + "chat",HIM + "【新闻】美国国防部宣称美国的间谍卫星被一不明物体击毁，目前还没有任何组织宣布对这起事件负责。\n" + NOR, users() );
                	message( "channel:" + "rumor", HIM + "【谣言】某人：是" + me->name() + "干的！我亲眼看见的！\n" + NOR,users());
                	call_out("do_kickback",3,me);
		}
		else 
		{
			write("你将足球高高抛起，待球落下，抬脚怒射，『砰』的一声，球急速飞向天边，闪了一闪就不见了！\n");
			tell_room(environment(me),"你听到『砰』的一声巨响，身边有什么东西『嗖』地一下飞了过去，你定睛一看，\n天边似乎有什么东西闪了一下，不见了。\n",me);
			this_object()->move("/clone/misc/void");
			call_out("do_kickother",3,me,ppl);
		}		
		return 1;
	}
	chance = random(me->query_str() + me->query_dex());
	if (chance <= 20)
	{
		message_vision("$N使尽吃奶的力气，狠狠将球踢了出去，球轻飘飘地飞过墙头，不见了。\n",me);
		this_object()->move("/clone/misc/void");
		call_out("do_kick1",3,me,1);
	}
	else if (chance >= 60)
		{
			message_vision("$N气运右腿，轻轻一弹，『砰』的一声，足球如同离弦之箭，一眨眼就不见了！\n",me);
			this_object()->move("/clone/misc/void");
			call_out("do_kick1",3,me,2);
		}
		else
		{
			write("你运足了气，大吼一声，『砰』的一声把球远远地开了出去！足球嗖地飞过地平线，不见了！\n");
			tell_room(environment(me),"你忽然听到一声嚎叫，吓了一跳，回头一看，" + me->name() + "站在那里呼呼直喘，不知在发什么神经。\n",me);
			this_object()->move("clone/misc/void");
			call_out("do_kick2",3,me);
		}
	return 1;
}