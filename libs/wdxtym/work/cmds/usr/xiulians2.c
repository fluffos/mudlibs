// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	mapping my;
	my = me->query_entire_dbase();
	
	if(!arg)
	{
		str =ZJOBLONG+HBWHT "◎""───────"HIC"修仙境界"HBWHT"────────" "◎" NOR"\n";
		str+="目前修炼境界："HIM+my["wudao"]+NOR"\n";
		str +=ZJOBACTS2+ZJMENUF(1,1,10,30);
		str += HBWHT"◎""───────"HIR"炼气境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -a"ZJSEP;
		str += HBWHT"◎""───────"HIR"炼气境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -b"ZJSEP;
		str += HBWHT"◎""───────"HIR"炼气境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -c"ZJSEP;
		str += HBWHT"◎""───────"HIR"炼气境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -d"ZJSEP;
		str += HBWHT"◎""───────"HIR"炼气境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -e"ZJSEP;

		str += HBWHT"◎""───────"HIR"筑基境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -f"ZJSEP;
		str += HBWHT"◎""───────"HIR"筑基境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -g"ZJSEP;
		str += HBWHT"◎""───────"HIR"筑基境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -h"ZJSEP;
		str += HBWHT"◎""───────"HIR"筑基境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -i"ZJSEP;
		str += HBWHT"◎""───────"HIR"筑基境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -j"ZJSEP;

		str += HBWHT"◎""───────"HIR"金丹境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -k"ZJSEP;
		str += HBWHT"◎""───────"HIR"金丹境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -l"ZJSEP;
		str += HBWHT"◎""───────"HIR"金丹境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -m"ZJSEP;
		str += HBWHT"◎""───────"HIR"金丹境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -n"ZJSEP;
		str += HBWHT"◎""───────"HIR"金丹境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -o"ZJSEP;

		str += HBWHT"◎""───────"HIR"元婴境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -p"ZJSEP;
		str += HBWHT"◎""───────"HIR"元婴境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -q"ZJSEP;
		str += HBWHT"◎""───────"HIR"元婴境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -r"ZJSEP;
		str += HBWHT"◎""───────"HIR"元婴境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -s"ZJSEP;
		str += HBWHT"◎""───────"HIR"元婴境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -t"ZJSEP;

		str += HBWHT"◎""───────"HIR"出窍境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -u"ZJSEP;
		str += HBWHT"◎""───────"HIR"出窍境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -v"ZJSEP;
		str += HBWHT"◎""───────"HIR"出窍境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -w"ZJSEP;
		str += HBWHT"◎""───────"HIR"出窍境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -x"ZJSEP;
		str += HBWHT"◎""───────"HIR"出窍境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -y"ZJSEP;

		str += HBWHT"◎""───────"HIR"分神境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -z"ZJSEP;
		str += HBWHT"◎""───────"HIR"分神境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -1"ZJSEP;
		str += HBWHT"◎""───────"HIR"分神境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -2"ZJSEP;
		str += HBWHT"◎""───────"HIR"分神境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -3"ZJSEP;
		str += HBWHT"◎""───────"HIR"分神境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -4"ZJSEP;

		str += HBWHT"◎""───────"HIR"合体境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -5"ZJSEP;
		str += HBWHT"◎""───────"HIR"合体境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -6"ZJSEP;
		str += HBWHT"◎""───────"HIR"合体境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -7"ZJSEP;
		str += HBWHT"◎""───────"HIR"合体境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -8"ZJSEP;
		str += HBWHT"◎""───────"HIR"合体境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -9"ZJSEP;

		str += HBWHT"◎""───────"HIR"大乘境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -10"ZJSEP;
		str += HBWHT"◎""───────"HIR"大乘境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -11"ZJSEP;
		str += HBWHT"◎""───────"HIR"大乘境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -12"ZJSEP;
		str += HBWHT"◎""───────"HIR"大乘境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -13"ZJSEP;
		str += HBWHT"◎""───────"HIR"大乘境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -14"ZJSEP;

		str += HBWHT"◎""───────"HIR"渡劫境·入门"HBWHT"────────"  "◎"NOR":xiulians1 -15"ZJSEP;
		str += HBWHT"◎""───────"HIR"渡劫境·初期"HBWHT"────────"  "◎"NOR":xiulians1 -16"ZJSEP;
		str += HBWHT"◎""───────"HIR"渡劫境·中期"HBWHT"────────"  "◎"NOR":xiulians1 -17"ZJSEP;
		str += HBWHT"◎""───────"HIR"渡劫境·后期"HBWHT"────────"  "◎"NOR":xiulians1 -18"ZJSEP;
		str += HBWHT"◎""───────"HIR"渡劫境·圆满"HBWHT"────────"  "◎"NOR":xiulians1 -19"ZJSEP;

		message("vision", str+"\n", me);
		return 1;
	}
	else if(arg=="-a"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/a"))
			return notify_fail("你已经成功突破了炼气境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->add("jingjie",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("jingjie/a",1);
			me->set("wudao","炼气境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破炼气境·入门，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-b"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/b"))
			return notify_fail("你已经成功突破了炼气境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/a"))
			return notify_fail("你境界未到炼气境·入门，还想染指炼气境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/b",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","炼气境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破炼气境·初期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-c"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/c"))
			return notify_fail("你已经成功突破了炼气境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/b"))
			return notify_fail("你境界未到炼气境·初期，还想染指炼气境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/c",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","炼气境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破炼气境·中期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-d"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/d"))
			return notify_fail("你已经成功突破了炼气境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/c"))
			return notify_fail("你境界未到炼气境·中期，还想染指炼气境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/d",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","炼气境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破炼气境·后期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-e"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/e"))
			return notify_fail("你已经成功突破了炼气境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/d"))
			return notify_fail("你境界未到炼气境·后期，还想染指炼气境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/e",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","炼气境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破炼气境·圆满，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-f"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/f"))
			return notify_fail("你已经成功突破了筑基境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/e"))
			return notify_fail("你境界未到炼气境·圆满，还想染指筑基境·入门？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("jingjie/f",1);
			me->set("wudao","筑基境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破筑基境·入门，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-g"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/g"))
			return notify_fail("你已经成功突破了筑基境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/f"))
			return notify_fail("你境界未到筑基境·入门，还想染指筑基境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/f",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","筑基境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破筑基境·初期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-h"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/h"))
			return notify_fail("你已经成功突破了筑基境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/f"))
			return notify_fail("你境界未到筑基境·初期，还想染指筑基境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/h",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","筑基境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破筑基境·中期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-i"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/i"))
			return notify_fail("你已经成功突破了筑基境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/h"))
			return notify_fail("你境界未到筑基境·中期，还想染指筑基境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/i",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","筑基境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破筑基境·后期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-j"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/j"))
			return notify_fail("你已经成功突破了筑基境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/i"))
			return notify_fail("你境界未到筑基境·后期，还想染指筑基境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/j",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","筑基境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破筑基境·圆满，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;

	}
	else if(arg=="-k"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/k"))
			return notify_fail("你已经成功突破了金丹境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/j"))
			return notify_fail("你境界未到筑基境·圆满，还想染指金丹境·入门？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("jingjie/k",1);
			me->set("wudao","金丹境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破金丹境·入门，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-l"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/l"))
			return notify_fail("你已经成功突破了金丹境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/k"))
			return notify_fail("你境界未到金丹境·入门，还想染指金丹境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/l",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","金丹境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破金丹境·初期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-m"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/m"))
			return notify_fail("你已经成功突破了金丹境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/l"))
			return notify_fail("你境界未到金丹境·初期，还想染指金丹境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/m",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","金丹境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破金丹境·中期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-n"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/n"))
			return notify_fail("你已经成功突破了金丹境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/m"))
			return notify_fail("你境界未到金丹境·中期，还想染指金丹境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/n",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","金丹境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破金丹境·后期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-o"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/o"))
			return notify_fail("你已经成功突破了金丹境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/n"))
			return notify_fail("你境界未到金丹境·后期，还想染指金丹境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/o",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","金丹境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破金丹境·圆满，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;

	}
	else if(arg=="-p"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/p"))
			return notify_fail("你已经成功突破了元婴境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/o"))
			return notify_fail("你境界未到金丹境·圆满，还想染指元婴境·入门？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("jingjie/p",1);
			me->set("wudao","元婴境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破元婴境·入门，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-q"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/q"))
			return notify_fail("你已经成功突破了元婴境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/p"))
			return notify_fail("你境界未到元婴境·入门，还想染指元婴境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/q",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","元婴境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破元婴境·初期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-r"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/r"))
			return notify_fail("你已经成功突破了元婴境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/q"))
			return notify_fail("你境界未到元婴境·初期，还想染指元婴境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/r",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","元婴境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破元婴境·中期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-s"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/s"))
			return notify_fail("你已经成功突破了元婴境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/r"))
			return notify_fail("你境界未到元婴境·中期，还想染指元婴境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/s",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","元婴境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破元婴境·后期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-t"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/t"))
			return notify_fail("你已经成功突破了元婴境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/s"))
			return notify_fail("你境界未到元婴境·后期，还想染指元婴境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/t",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","元婴境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破元婴境·圆满，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-u"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/u"))
			return notify_fail("你已经成功突破了出窍境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/t"))
			return notify_fail("你境界未到元婴境·圆满，还想染指出窍境·入门？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("jingjie/u",1);
			me->set("wudao","出窍境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破出窍境·入门，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-v"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/v"))
			return notify_fail("你已经成功突破了出窍境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/u"))
			return notify_fail("你境界未到出窍境·入门，还想染指出窍境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/v",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","出窍境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破出窍境·初期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-w"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/w"))
			return notify_fail("你已经成功突破了出窍境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/v"))
			return notify_fail("你境界未到出窍境·初期，还想染指出窍境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/w",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","出窍境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破出窍境·中期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-x"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/x"))
			return notify_fail("你已经成功突破了出窍境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/w"))
			return notify_fail("你境界未到出窍境·中期，还想染指出窍境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/x",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","出窍境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破出窍境·后期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-y"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/y"))
			return notify_fail("你已经成功突破了出窍境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/x"))
			return notify_fail("你境界未到出窍境·后期，还想染指出窍境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/y",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","出窍境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破出窍境·圆满，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;

	}
	else if(arg=="-z"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/z"))
			return notify_fail("你已经成功突破了分神境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/y"))
			return notify_fail("你境界未到出窍境·圆满，还想染指分神境·入门？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("jingjie/z",1);
			me->set("wudao","分神境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破分神境·入门，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-1"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/1"))
			return notify_fail("你已经成功突破了分神境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/z"))
			return notify_fail("你境界未到分神境·入门，还想染指分神境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/1",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","分神境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破分神境·初期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-2"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/2"))
			return notify_fail("你已经成功突破了分神境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/1"))
			return notify_fail("你境界未到分神境·初期，还想染指分神境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/2",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","分神境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破分神境·中期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-3"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/3"))
			return notify_fail("你已经成功突破了分神境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/2"))
			return notify_fail("你境界未到分神境·中期，还想染指分神境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/3",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","分神境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破分神境·后期，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-4"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/4"))
			return notify_fail("你已经成功突破了分神境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/3"))
			return notify_fail("你境界未到分神境·后期，还想染指分神境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/4",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","分神境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破分神境·圆满，获得了暴击,抗暴,护甲,破甲四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-5"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/5"))
			return notify_fail("你已经成功突破了合体境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/4"))
			return notify_fail("你境界未到分神境·入门，还想染指合体境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("jingjie/5",1);
			me->set("wudao","合体境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破合体境·入门，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-6"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/6"))
			return notify_fail("你已经成功突破了合体境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/5"))
			return notify_fail("你境界未到合体境·入门，还想染指合体境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/6",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","合体境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破合体境·初期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-7"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/7"))
			return notify_fail("你已经成功突破了合体境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/6"))
			return notify_fail("你境界未到合体境·初期，还想染指合体境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/7",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","合体境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破合体境·中期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-8"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/8"))
			return notify_fail("你已经成功突破了合体境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/7"))
			return notify_fail("你境界未到合体境·中期，还想染指合体境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/8",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","合体境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破合体境·后期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-9"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/9"))
			return notify_fail("你已经成功突破了合体境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/8"))
			return notify_fail("你境界未到合体境·后期，还想染指合体境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/9",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","合体境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破合体境·圆满，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-10"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/10"))
			return notify_fail("你已经成功突破了大乘境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/9"))
			return notify_fail("你境界未到合体境·圆满，还想染指大乘境·入门？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("jingjie/10",1);
			me->set("wudao","大乘境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破大乘境·入门，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-11"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/11"))
			return notify_fail("你已经成功突破了大乘境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/10"))
			return notify_fail("你境界未到大乘境·入门，还想染指大乘境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/11",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","大乘境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破大乘境·初期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-12"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/12"))
			return notify_fail("你已经成功突破了大乘境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/11"))
			return notify_fail("你境界未到大乘境·初期，还想染指大乘境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/12",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","大乘境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破大乘境·中期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-13"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/13"))
			return notify_fail("你已经成功突破了大乘境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/12"))
			return notify_fail("你境界未到大乘境·中期，还想染指大乘境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/13",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","大乘境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破大乘境·后期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-14"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/14"))
			return notify_fail("你已经成功突破了大乘境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/13"))
			return notify_fail("你境界未到大乘境·后期，还想染指大乘境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/14",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","大乘境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破大乘境·圆满，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;

	}
	else if(arg=="-15"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/15"))
			return notify_fail("你已经成功突破了渡劫境·入门。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if ((int)me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/14"))
			return notify_fail("你境界未到大乘境·圆满，还想染指渡劫境·入门？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("jingjie/15",1);
			me->set("wudao","渡劫境·入门");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破渡劫境·入门，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-16"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/16"))
			return notify_fail("你已经成功突破了渡劫境·初期。\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/15"))
			return notify_fail("你境界未到渡劫境·入门，还想染指渡劫境·初期？？！\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/16",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","渡劫境·初期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破渡劫境·初期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-17"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/17"))
			return notify_fail("你已经成功突破了渡劫境·中期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");
		if (!me->query("jingjie/16"))
			return notify_fail("你境界未到渡劫境·初期，还想染指渡劫境·中期？？！。\n");	
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/17",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","渡劫境·中期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破渡劫境·中期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-18"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/18"))
			return notify_fail("你已经成功突破了渡劫境·后期。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");		
		if (!me->query("jingjie/17"))
			return notify_fail("你境界未到渡劫境·中期，还想染指渡劫境·后期？？！。\n");			
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/18",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","渡劫境·后期");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破渡劫境·后期，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-19"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("你目前不满足突破条件！\n");
		if (me->query("jingjie/19"))
			return notify_fail("你已经成功突破了渡劫境·圆满。\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("在这里修炼？死了咋办？\n");	
		if (! where->query("sleep_room"))
			return notify_fail("你得找一个能够休息的地方闭关修行。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("你的潜能不够，无法修炼仙道境界。\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("你的灵石不够，无法修炼仙道境界。\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("你现在的气太少了，无法静心闭关。\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("你现在的精太少了，无法静心闭关。\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("你现在的内力太少了，无法静心闭关。\n");				
		if (!me->query("jingjie/18"))
			return notify_fail("你境界未到渡劫境·后期，还想染指渡劫境·圆满？？！。\n");
			message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/19",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","渡劫境·圆满");
			message("channel:chat",HBWHT"天道"HIY"："+me->query("name")+"历经千辛万苦，终于突破渡劫境·圆满，获得了削弱绝招,沉默攻击,化解伤害,化解忙乱四项属性各+5点的奖励，当真是可喜可贺！！\n"NOR,users());			
	return 1;
	}
	else if(arg=="-suoxiang"){
			object where;

	return 1;	
	}
	else if(arg=="-guanjue"){
		    
	return 1;	
	}
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: uplv [-s]

这个指令让你消耗修为提升等级。

HELP
    );
    return 1;
}
