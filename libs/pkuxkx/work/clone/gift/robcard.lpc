#include <ansi.h>

inherit ITEM;


void init()
{
      add_action("do_rob","rob");
}

void create()
{
    set_name( HIR"抢夺卡"NOR , ({ "robber card","card" }) );
    set("unit","张");
    set("long", HIW"这是一张泛着"HIR"血红色"HIW"的"HIR"抢夺卡"HIW"，你可以用它来抢
某人的全部现金(rob money from sb)，也可以抢一些经验(rob exp from sb)，
抢夺方获得经验不超过双方经验较低者的1/20，被抢方损失为抢夺方所得的2倍。
也可以抢一些潜能(rob pot from sb)，抢夺方获得潜能不超过双方潜能较低者的
1/10，被抢方损失为抢夺方所得的2倍。
当然如果你风格高尚，不愿抢劫，可以抢自己(rob myself)，这样会有随机大小
的随机属性的提高。
抢夺卡每人只限对自己用一次，对他人用一次，15岁以上才能用，想好了再用哦～～
有效期至：2008年1月31日\n"NOR);

    set("value",0);
    setup();
}

int do_rob(string arg)
{
    object me,target;
    object* inv;
    string robtype,robtarget,strmessage,strrumor;
    int robdata,i;
    
    me = this_player();
    if (!arg || ((arg != "myself") && (sscanf(arg,"%s from %s",robtype,robtarget)!=2)))
         return notify_fail("抢夺卡使用方法：rob type from sb，具体请参考look robber card。\n");
    if (me->query("age") == 14)
	    return notify_fail("你还太小，不要学坏！\n");
        if(time() > 1201786111)
    	return notify_fail("对不起，抢夺卡的有效期已过，请等待巫师下一次充值。\n");
    if (arg == "myself")
    {
	    if (me->query("gift/200551") == 1)
	         return notify_fail("抢夺卡对自己只能用一次！\n");
    	i = random(10);
    	switch (i){
    		case 0:
    			robtype = "max_jingli";
    			strmessage = "最大精力";
    			robdata = random(500);
    			break;
    		case 1:
    			robtype = "max_neili";
    			strmessage = "最大内力";
    			robdata = random(500);
    			break;
    		case 2: 
    			robtype = "potential";
    			strmessage = "潜能";
    			robdata = random(1000);
    			break;
    		case 3:
    			robtype = "combat_exp";
    			strmessage = "经验";
    			robdata = random(5000);
    			break;
    		case 4:
    			robtype = "score";
    			strmessage = "师门忠诚";
    			robdata = random(500);
    			break;
    		case 5:
    			robtype = "balance";
    			strmessage = "存款";
    			robdata = random(5000000);
    			break;
    		case 6:
    			robtype = "per";
    			strmessage = "容貌";
    			robdata = random(10);
    			break;
    		case 7:
    			robtype = "str";
    			strmessage = "膂力";
    			robdata = random(2);
    			break;
    		case 8:
    			robtype = "kar";
    			strmessage = "福缘";
    			robdata = random(1);
    			break;
    		case 9:
    			robtype = "int";
    			strmessage = "悟性";
    			robdata = random(1);
    			break;
    	}
    	robdata++;
    	tell_object(me,"你被授予" + HIW + "武林道德风尚奖" + NOR + "：" + strmessage + "增加" + robdata + "！\n");
	shout(me->name() + "被授予" + HIW + "武林道德风尚奖" + NOR + "：" + strmessage + "增加" + robdata + "！\n");
    	me->add(robtype,robdata);
    	me->set("gift/200551",1);
    	destruct(this_object());
    	return 1;
    }
    if (robtype != "money" && robtype != "exp" && robtype != "pot")
    	return notify_fail("你到底要抢什么东西？\n");
    if (!(target=present(robtarget,environment(me))))
    	return notify_fail("你附近没有" + robtarget + "这个人。\n");
    if (!userp(target))
    	return notify_fail("你只能对玩家使用抢夺卡。\n");
    if (wizardp(target))
    	return notify_fail("你不能抢巫师的东西！\n");
    if (me->query("gift/2005512") == 1)
        return notify_fail("抢夺卡对别人只能使用一次！\n");
    if (robtype == "money")
    {
    	strmessage = "$N掏出一张抢夺卡朝$n一晃，吓得$n目瞪口呆，$N趁机打劫$n。\n";
    	message_vision(strmessage,me,target);
    	strmessage = "$N共抢了";
	strrumor = "";
    	inv = deep_inventory(target);
    	for (i=sizeof(inv)-1;i>=0;i--)
    	{
    		if (inv[i]->query("id") == "gold" || inv[i]->query("id") == "silver" || inv[i]->query("id") == "coin" || inv[i]->query("id") == "thousand-cash")
    		{
    			strmessage += inv[i]->short();
			strrumor += inv[i]->short();
    			inv[i]->move(me);
    		}
    	}
    	if (strmessage == "$N共抢了") 
    		strmessage = "但$N在$n身上翻了个遍一个大子也没发现，$N恼羞成怒，把$n狠k一顿，悻悻地走了。\n";
    	else strmessage += "。\n";
	strrumor += "。";
    	message_vision(strmessage,me,target);
    }
    if (robtype == "exp")
    {
    	robdata = (me->query("combat_exp")<target->query("combat_exp"))?me->query("combat_exp"):target->query("combat_exp");
    	if (robdata < 10000)
    		return notify_fail("你一共也抢不到1000点经验，不值得浪费一张抢夺卡。\n");
    	strmessage = "$N掏出一张抢夺卡朝$n一晃，喊道『打劫打劫！男的靠左站，女的靠右站，同性恋站中间！』$n吓得目瞪口呆，一步也挪不动，乖乖站在了中间。\n";
    	message_vision(strmessage,me,target);
    	strmessage = "$N一脸怪笑地走近$n，上下其手，大肆轻薄......（以下省去2930字）\n";
    	message_vision(strmessage,me,target);
    	strmessage = "$N从$n身上摸走了" + robdata/20 + "点经验！" + "$n气得两眼发黑，又掉了" + robdata/20 + "点经验！！\n";
    	me->add("combat_exp",robdata/20);
    	target->add("combat_exp",0-robdata/10);
    	message_vision(strmessage,me,target);
	strrumor = robdata/20 + "点经验。\n";
    }
    if (robtype == "pot")
    {
    	robdata = ((me->query("potential")-me->query("learned_points"))<(target->query("combat_exp")-target->query("learned_points")))?(me->query("potential")-me->query("learned_points")):(target->query("combat_exp")-target->query("learned_points"));
    	if (robdata < 100)
    		return notify_fail("你一共也抢不到10点潜能，不值得浪费一张抢夺卡。\n");
    	strmessage = "$N掏出一张抢夺卡朝$n一晃，喊道『打劫打劫！男的靠左站，女的靠右站，同性恋站中间！』$n吓得目瞪口呆，一步也挪不动，乖乖站在了中间。\n";
    	message_vision(strmessage,me,target);
    	strmessage = "$N一脸怪笑地走近$n，上下其手，大肆轻薄......（以下省去2930字）\n";
    	message_vision(strmessage,me,target);
    	strmessage = "$N从$n身上摸走了" + robdata/10 + "点潜能！" + "$n气得两眼发黑，又掉了" + robdata/10 + "点潜能！！\n";
    	me->add("potential",robdata/10);
    	target->add("potential",0-robdata/5);
    	message_vision(strmessage,me,target);
	strrumor = robdata/10 + "点潜能。\n";
    }
    me->set("gift/2005512",1);
    CHANNEL_D->do_channel(me,"rumor","听说" + target->name() + "光天化日之下被" + me->name() + "劫财劫色啊～～");
    strrumor = "这趟买卖赚了" + strrumor;
    if (strrumor == "这趟买卖赚了。")
    {
	    CHANNEL_D->do_channel(me,"rumor","唉！赔了！这穷鬼怎么一分钱都不带！");
	    CHANNEL_D->do_channel(me,"rumor*","poor");
    }
    else{
	    CHANNEL_D->do_channel(me,"rumor",strrumor);
	    CHANNEL_D->do_channel(me,"rumor*","heihei");
	 }
	    destruct(this_object());
    return 1;

}
