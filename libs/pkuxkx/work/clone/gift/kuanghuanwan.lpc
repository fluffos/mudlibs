//kuanghuanwanzi 狂欢丸子(加狂欢时间)
//Made By yhzzyahoo@nx
//2016-2.-16
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("狂欢丸子",({"kuanghuan wanzi","wanzi"}));
		set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
		//set("dur_time",86400);//持续时间
        set("long","据说是溢出黑作坊制作的丸子,看上去黑黝黝的,闻起来臭熏熏的,令人作呕,你敢(eat)它?\n");
        set("unit","个");
		set("product_time",time());
       setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
    object me = this_player();
	object ob = this_object();
	int i,j;
    if (!arg)  return notify_fail("你要吃什么？\n");
    if((arg=="kuanghuan wanzi") || (arg=="wanzi")) 
    {
		if (time() - ob->query("product_time") > 86400)
		{
			return notify_fail("这种变质的东西你也吃，想死吗？\n");
		}
      //  if ( (int)me->query("zhongqiu/gift_yuebing" ) > 0 ) return notify_fail("你已经吃过月饼了，难道你想吃成肥猪吗？\n");
	  if (ob->query("owner") != me->query("id"))
	  {
           return notify_fail("不是你的药丸子你也敢吃,不怕被毒死啊!\n");
	  }
        if(me->query("mud_age")<360000)
                return notify_fail("起码要在这个mud中呆足100个小时才可以食用这种药丸!\n");
        if(me->query("combat_exp")<1000000)
                return notify_fail("经验1000000以上才可以食用如此霸道的丸子!\n");
		if (time()<me->query("double_reward"))
		{
           return notify_fail("你身上有狂欢效果,这种丸子对你一点作用都没有!\n");
		}
        message_vision(HIG"\n$N一口吞下了看起来能要人命的丸子,呃,真恶心！\n"NOR,me);

		me->set("tianmuQuests/dashigu/dashi_eat",time()+172800);
		tell_object(me,HIG+"你服下了一个狂欢丸子，觉得灵台清明，正是修行的好时候，狂欢状态将持续一天。\n"+NOR);
		me->set("doublereward",time()); //赋值到系统狂欢变量1
		me->set("double_reward",time()+86400);  //赋值到系统狂欢变量2
	//	me->set("double_reward",time()+ob->query(dur_time));  //赋值到系统狂欢变量2
        destruct(ob);
     }
     return 1;
}
