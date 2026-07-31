// Object: /d/xiangyang/obj/shuipiao.c  药王庄水瓢
// Date: Feb . 3 2002 by Pound

#include <ansi.h>
#include <localtime.h>

inherit ITEM;
string long_desc();
string* use_phrase = ({"将", "把", });
string* use_name = ({"水瓢中的", "瓢中的", "水瓢里的", "瓢里的", "", });
string* use_what = ({"水", "清水", });
string* use_arj = ({"随随便便的", "轻轻松松的", "小心翼翼的", "随便的", "轻松的", "", "马马虎虎的", "马虎的", });
string* use_action = ({"向", "往", });
string* use_where = ({"前", "后", "左", "右", "上", "下", });
string* action_arj = ({"一洒", "洒", "浇", "一浇", });

void create()
{
	set_name("水瓢", ({"shui piao", "shuipiao", "piao"}));
	set_weight(100);
	if (clonep())
	    set_default_object(__FILE__);
	else
	{
	    set("long", "这是一个用来舀水浇花的特制水瓢。\n");
	    set("unit", "个");
	    set("material", "wood");
	    set("value", 0);
	    set("no_give", 1);
	    set("no_steal", 1);
	    set("no_drop", 1);
	}
}

int init()
{
	add_action("do_yao", "yao");
	add_action("do_yao", "舀");
	add_action("do_sa", "sa");
	add_action("do_sa", "洒");
	add_action("do_sa", "jiao");
	add_action("do_sa", "浇");
}

int do_yao(string arg)
{
	object ob1, ob2, me;
	string what, target;

	me = this_player();
	if (! arg)
	    return notify_fail("你要舀什么？\n");
	if (! objectp(ob1 = present("shui piao", me)))
	    return notify_fail("你没有水瓢，怎么舀水？\n");

	if (sscanf(arg, "%s from %s", what, target) == 2)
	{
	    if (what != "shui" && what != "water" && what != "水") 
		return notify_fail("你要舀什么？\n");
	    if (! objectp(ob2 = present(target, environment(me)))) 
		return notify_fail("你要从哪里舀水？\n");
	    if (me->is_busy())
		return notify_fail("等你忙完再舀东西！\n");
	    if (! ob2->query("yaowang") && (! wizardp(me)))
		return notify_fail("你最好还是用药王庄特制的木桶。\n");
// 避免游戏中有其他巫师做的水桶，产生混乱。
	    if (ob2->query("water_level") <= 0)
		return notify_fail("木桶里已经没水了。\n");

	    if (ob1->query("filled")) // 处理已经有水的水瓢
	    {
		message_vision("$N把水瓢里的水倒进水桶，搅了几下，重新舀了一瓢水。\n", me);
		ob1->set("water_level", ob2->query("water_level"));
		me->start_busy(1 + random(2));
		me->receive_damage("jing", (22 + random(3)));
		ob2->set("long", (: long_desc :));
		return 1;
	    }

	    message_vision("$N从水桶中舀了一瓢水。\n", me);
	    ob1->set("filled", 1);
	    ob2->add("water_level", -1);
	    ob1->set("water_level", ob2->query("water_level"));
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (16 + random(3)));
	    ob2->set("long", (: long_desc :)); // 此处必须要重新设置一下水桶的参数。
	    return 1;
	}
	else
	{   
// 如果桶被弄走了，可以到茅舍外的小溪旁舀水。
	    if (arg != "shui" && arg != "water") 
		return notify_fail("你要舀什么？\n");
	    if (environment(me) != find_object("/d/xiangyang/xibian")) 
		return notify_fail("这里能舀到浇花用的水？\n");
	    if (me->is_busy()) 
		return notify_fail("等你忙完再舀东西！\n");

	    message_vision("$N走近溪边，弯下腰，从清澈的溪水中舀了一瓢水。\n", me);
	    ob1->set("filled", 1);
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(3)));
	    return 1;
	}
}

int do_sa(string arg)
{
	mixed *local;
	int totaltime, water_time, curent_time, seeded, hour, day, month;
	object room, ob, me, obnew, pound;
	string msg;

	ob = this_object();
	me = this_player();
	room = find_object("/d/xiangyang/huafang.c");
	local = localtime(time());

	hour = 100;
	day = 10000;
	month = 1000000;
	curent_time = (local[LT_MON] + 1) * month + local[LT_MDAY] * day + local[LT_HOUR] * hour + local[LT_MIN];
// 例如11月23日下午3点21，得到的curent_time就是11231521

// 没有水瓢、瓢里没有水、忙时的判断
	if (! objectp(ob = present("shui piao", me)))
	    return notify_fail("你没有水瓢，怎么洒水？\n");
	if (! arg || (arg != "shui" && arg != "water"))
	    return notify_fail("你要洒什么？\n");
	if (me->is_busy()) 
	    return notify_fail("等你忙完再洒东西！\n");
	if (! ob->query("filled")) 
	    return notify_fail("瓢里没水！\n");

// 如果不是在花房浇水的后果
	if (environment(me) != room)
	{
	    message_vision("$N随随便便的把水洒在地上。\n", me);
	    ob->delete("filled");
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(5)));
	    return 1;
	}

// 没有播种种子的后果，播种的标记放在种子上了。
	if (! me->query("yaowang/seeded"))
	{
	    message_vision("$N把水瓢里的水浇到了窗口的花盆里。\n", me);   
	    ob->delete("filled");
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(5)));
	    tell_object(me, "你突然记起还没有把新种子种下，看来这瓢水白浇了。\n");
	    return 1;
	}

	water_time = me->query("yaowang/seeded");
// 设置water_time为上次干活的时间，干活可以是播种和浇水。
// 设置water为总浇水的次数，用于控制总的种植时间和阶段描述，
// 每次浇水需要间隔5-10分钟，water为30次，则总的培植时间为现实中的3-5小时。
	if (! me->query("yaowang/water"))
	{
// 第一次浇花，只所以单独列出来，是因为从播种到浇花，玩家可能需要更多些的摸索和适应的时间。
	    message_vision("$N小心翼翼地把花盆放到窗前。\n", me);   
//	    ob->delete("filled");
//	    me->start_busy(1+random(2));
//	    me->receive_damage("jing", (20 + random(5)));
//	    me->set("yaowang/water", 1);
//	    me->set("yaowang/seeded", curent_time);
//	    return 1;
	}

	if (me->query("yaowang/water") && water_time + 5 > curent_time) // 浇完一次后5分钟才可以再浇。
	{
	    me->start_busy(2 + random(3));
	    return notify_fail("不是才刚灌溉过么，这么一直浇会把花淹死的！\n");
	}
	if (me->query("yaowang/water") && water_time + 10 < curent_time)// 10分钟内不浇水培植失败。
	{
	    tell_object(me, "糟糕，很久没给七心海棠浇水，培植失败。:(\n");
	    me->delete("yaowang/water");
	    me->delete("yaowang/seeded");
	    me->add("yaowang/fail", 1);
	    return 1;
	}

	message_vision("$N" + use_phrase[random(sizeof(use_phrase))] + use_name[random(sizeof(use_name))] +
			      use_what[random(sizeof(use_what))] + use_arj[random(sizeof(use_arj))] +
			      use_action[random(sizeof(use_action))] + use_where[random(sizeof(use_where))] +
			      action_arj[random(sizeof(action_arj))] + "。\n", me);
	ob->delete("filled");
	me->add("yaowang/water", 1);
	totaltime = me->query("yaowang/water");
	me->start_busy(3 + random(3));
	me->receive_damage("jing", (60 + random(60)));
	me->set("yaowang/seeded", curent_time);

// 三十次浇花，每次都对花的感受是不一样的。
	switch (me->query("yaowang/water"))
	{
		case 1:
			msg = "刚开始浇花，你感觉还有些新鲜感，也不觉得累。";
			break;
		case 2:
			msg = "你默默地祈祷着，希望种子能快些发芽。";
			break;
		case 3:
			me->receive_damage("qi", 100);
			msg = "种子还没有发芽，你等得有些心急了。";
			break;
		case 4:
			me->receive_damage("qi", 10);
			msg = "哇噻！种子终于发芽了，你高兴地跳了起来。";
			break;
		case 5:
		case 6:
			msg = "花盆里的嫩芽在一点点长高，你心里充满了喜悦。";
			break;
		case 7:
		case 8:
		case 9:
			me->receive_damage("qi", 50);
			msg = "七心海棠的茎也在一节节增长，现在已经有" + totaltime + "节了。";
			break;
		case 11:
		case 12:
			me->receive_damage("qi", 30);
			msg = "七心海棠又生出些许嫩叶，色泽艳丽、株形优美，烂漫如锦。";
			break;
		case 13:
			msg = "七心海棠叶子是椭圆形的，表面绿色而有光泽。";
			break;
		case 14:
			me->receive_damage("qi", 20);
			msg = "七心海棠的叶子叶柄细长，基部有两个披针形托叶。";
			break;
		case 15:
			msg = "你突然发现阳光照射久了海棠叶子就会变红，避光良久又会变成淡绿。甚是有趣！";
			break;
		case 17:
			me->receive_damage("qi", 30);
			msg = "呀！七心海棠看上去是要开花了。";
			break;
		case 19:
			me->receive_damage("qi", 20);
			msg = "只见这七心海棠红色的花蕾含苞待放，惹人怜爱。";
			break;
		case 20:
		case 21:
			msg = "七心海棠花蕾逐渐开放，颜色也渐渐变成粉红色。";
			break;
		case 23:
		case 28:
			me->receive_damage("qi", 30);
			msg = "细观七心海棠花，只觉不仅色、香迷人，更有一派怡然自乐的神韵。";
			break;
		case 24:
		case 25:
			msg = "七心海棠花瓣对边相等，金黄色的花蕊，像菊花一样，小巧玲珑。";
			break;
		case 27:
			msg = "这海棠艳美高雅，真是\"猩红鹦绿极天巧，叠萼重跗眩朝日。\"";
			break;
		case 29:
			me->receive_damage("qi", 50);
			msg = "月朦胧，鸟朦胧，帘卷海棠红。谁会想到这妩媚而嫣润的海棠会是绝世珍品药材。";
			break;
		case 30:
			me->receive_damage("qi", 60);
			msg = "看上去七心海棠已经培植成功，赶快收起来(get)制炼成药物吧。";
			break;
		default:
			msg = "为了能把七心海棠培植成功，就不能怕浇花枯燥辛苦。";
			break;
	}

	msg += "\n";
	tell_object(me, HIY + msg + NOR + "\n");
	if (totaltime > 30)// 这种情况正常情况下不会出现，加此CODE是防患于未然，避免进入死循环。
	{
	    tell_object(me, "糟糕，由于你的操作失误，七心海棠培植失败。:(\n");
	    me->delete("yaowang/water");
	    me->delete("yaowang/seeded");
	    me->add("yaowang/fail", 1);
	    return 1;
	}
	if (totaltime == 30) // 浇花30次后，培植成功。
	{
	    me->delete("yaowang/water");
	    me->delete("yaowang/seeded");
	    obnew = new("/clone/herb/haitang");
	    obnew->move(room);
	    me->add("yaowang/qxhtget", 1);
	    me->set("yaowang/qxht/have", 1);
	}
	return 1;
}

string long_desc()
{
	string descrp;
	object ob;
	ob = this_object();

// 用于设置舀水后水桶的Long描述。
	descrp = HIY "这是一副特制的水桶。" NOR;
	if (ob->query("water_level") == 0)
	    descrp += HIC "桶里面一滴水都没有。"NOR"\n";
	else if (ob->query("water_level") <= 1)
		descrp += HIC "里面有一点点水。"NOR"\n";
	else if (ob->query("water_level") <= 3)
		descrp += HIC "里面有半桶水。"NOR"\n";
	else if (ob->query("water_level") <= 4)
		descrp += HIC "里面的水快满了。"NOR"\n";
	else
	    descrp += HIC "里面装满了水。"NOR"\n";
	return descrp;
}
