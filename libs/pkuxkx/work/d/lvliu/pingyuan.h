#include <ansi.h>
#include <room.h>
inherit ROOM;

int valid_leave(object me, string dir)
{
	int i, t, c;
	if (!objectp(me) || !userp(me)) return ::valid_leave(me, dir);
	if (me->query_temp("lvliu/xianjing"))
	{
		me->set_temp("no_move", 1);
		return notify_fail(HIY"你还被陷阱卡着呢，动不了！\n"NOR);
	}
	t = (int)me->query_temp("lvliu/pass");
	c = 60;
	if (t>0)
	{
		for (i=1;i<=t;i++)
		{
			c += (100-c)/2;
		}
	}
	if (random(100)>c)
	{
		me->add_temp("lvliu/pass", 1);
		message_vision(HIY"$N一边走着，一边四处张望，忽然一不留神，脚下一软，啊……糟糕，有陷阱！\n"NOR, me);
		message_vision(HIR"$N被陷阱卡住了，动弹不得！快，喊个人来帮把手！\n"NOR, me);
		message("vision", HIM"如果你愿意帮"+me->query("name")+HIM"的忙，可以试试拉(la)一把。\n或者……试试落井下石，再推(tui)上一下？\n"NOR, environment(me), ({ me }));
		me->add_temp("lvliu/move_exp", 5); // 经历磨难到庄门的有额外奖赏
		me->set_temp("lvliu/xianjing", 3+random(3));
		me->set_temp("no_move", 1);
		me->start_busy(5);
		return notify_fail(HIM"你也可以试试自己挣扎(zhengzha)一下看能不能挣脱出来。\n"NOR);
	}
	return ::valid_leave(me, dir);
}

int do_zhengzha()
{
	object me=this_player();
	if (!me->query_temp("lvliu/xianjing") || !me->query_temp("no_move")) return 0;
	if (me->is_busy())
		return notify_fail("你现在正忙呢。\n");
	if (random(me->query_kar())>random(15))
	{
		message_vision(HIC"$N"HIC"死命用力地挣扎，试图从陷阱里挣脱出来，似乎有那么一点效果！\n"NOR, me);
		me->add_temp("lvliu/xianjing", -1-random(3));
		me->start_busy(2);
		if ((int)me->query_temp("lvliu/xianjing")<=0)
		{
			me->delete_temp("lvliu/xianjing");
			me->delete_temp("no_move");
			message_vision( HIW"成功了！$N"HIW"成功地从陷阱中挣脱出来，抹了一把额头的冷汗，哈哈笑了起来。\n"NOR, me);
		}
	}
	else
	{
		message_vision(HIY"$N"HIY"死命用力地挣扎，试图从陷阱里挣脱出来，结果越挣扎陷得越深了！\n"NOR, me);
		me->add_temp("lvliu/xianjing", 1+random(3));
		me->start_busy(2);
		if ((int)me->query_temp("lvliu/xianjing")>=10)
		{
			me->delete_temp("lvliu/xianjing");
			me->delete_temp("no_move");
			message_vision(HIR"忽然$N"HIR"脚下一空，“啊”地惊叫了一声，整个人掉了下去！\n"NOR, me);
			me->move(__DIR__"xianjing");
			message_vision(HIR"“噗通”一声，$N"HIR"掉了下来，屁股先着地，哎呦哎呦哼唧了半天都没爬起来！\n"NOR, me);
			me->start_busy(5);
		}
	}
	me->add_temp("lvliu/move_exp", 1); // 经历磨难到庄门的有额外奖赏
	return 1;
}

int do_la(string arg)
{
	object ob;
	object me=this_player();
	if (!arg) return notify_fail("你要拉谁呢？\n");
	if (me->is_busy())
		return notify_fail("你现在正忙呢。\n");
	ob = present(arg, environment(me));
	if (!objectp(ob) || !userp(ob)) return notify_fail("这里没有这样的人需要你拉一把。\n");
	if (!ob->query_temp("lvliu/xianjing")) return notify_fail("人家啥事没有，你就别操那个闲心了。\n");
	message_vision(HIC"$N"HIC"伸手过去，试图把$n"HIC"从陷阱里拉出来，似乎有那么一点效果！\n"NOR, me, ob);
	me->start_busy(3);
	ob->add_temp("lvliu/xianjing", -1);
	if ((int)ob->query_temp("lvliu/xianjing")<=0)
	{
		ob->delete_temp("lvliu/xianjing");
		ob->delete_temp("no_move");
		message_vision( HIW"成功了！$N"HIW"成功地把$n"HIW"从陷阱中拉了出来，两人都哈哈大笑了起来。\n"NOR, me, ob);
	}
	return 1;
}

int do_tui(string arg)
{
	object ob;
	object me=this_player();
	if (!arg) {
		if (!me->query_temp("lvliu/xianjing"))
			return notify_fail("你要对谁下黑手呢？\n");
		message_vision(HIY"$N"HIY"咬咬牙，用力在地上一推，使劲往下一墩，整个人往陷阱里掉下去……\n"NOR, me);
		me->delete_temp("lvliu/xianjing");
		me->delete_temp("no_move");
		me->move(__DIR__"xianjing");
		message_vision(HIR"“噗通”一声，$N"HIR"掉了下来，屁股先着的地，哎呦哎呦哼唧了半天都没爬起来！\n"NOR, me);
		me->start_busy(5);
		return 1;
	}
	if (me->is_busy())
		return notify_fail("你现在正忙呢。\n");
	ob = present(arg, environment(me));
	if (!objectp(ob) || !userp(ob)) return notify_fail("这里没有这样的人让你下黑手……\n");
	if (!ob->query_temp("lvliu/xianjing")) return notify_fail("人家啥事没有，你还是去别惹事生非了。\n");
	tell_object(me, HIM"你左看看右看看，见没人注意，就蹑手蹑脚地走到"+ob->query("name")+"身后，伸手用力一推！\n"NOR);
	message_vision(HIM"$N"HIM"背后忽然一股大力传来，一下掉进了陷阱里，只听见一阵大吼声传上来：“混～蛋～谁～暗～算～我～”\n"NOR, ob);
	ob->delete_temp("lvliu/xianjing");
	ob->delete_temp("no_move");
	ob->move(__DIR__"xianjing");
	message_vision(HIR"“噗通”一声，$N"HIR"掉了下来，屁股先着的地，哎呦哎呦哼唧了半天都没爬起来！\n"NOR, ob);
	ob->start_busy(5);
	return 1;
}

void create_pingyun_room()
{
	set("short", HIY"花园"NOR);
	set("long",HIC"这是绿柳山庄的花园。\n"NOR);
	set("outdoors", "lvliu");
	set("exits", ([
	]));
	set("no_clean_up", 1);
}

void init()
{
	add_action("do_zhengzha", "zhengzha");
	add_action("do_la", "la");
	add_action("do_tui", "tui");
}

void reset_object()
{
	int i;
	object *ob;
	ob = all_inventory(this_object());
	if (sizeof(ob)>0)
	{
		for(i=0; i<sizeof(ob); i++) {
			if (objectp(ob[i]) && !userp(ob[i]))
			{
				ob[i]->move(0);
				destruct(ob[i]);
			}
		}
	}
}

void reset_name()
{
	string* color = ({ HIR, RED, HIY, YEL, HIB, BLU, HIG, HIC, CYN, MAG, HIM, HIW, WHT });
	string* short_name = ({ "山石", "山坡", "瀑布", "花海", "老树", "花丛", "杨树", "残枝", "荷塘", "崖壁", "山谷", "山谷", "溪边", "竹林" });
	string* long_name = ({
"这里是一处山石，它们的形状与在平原或半山望上来大不相同，十
分层叠、杂乱，雄伟而奇特。往上仰望，山就是天，天也是山，前后左
右尽是山，好像你的鼻子都可随时触到山。凝神细听，似乎还有叮叮咚
咚的流水声。\n",

"整个山坡都是苍翠欲滴的浓绿，没来得散尽的雾气像淡雅丝绸，一
缕缕地缠在它的腰间，阳光把每片叶子上的雨滴，都变成了五彩的珍珠
。坡上的花也开了，这儿一丛，那儿一簇，一种淡淡的香气扑鼻而来。
正所谓「日映岚光轻锁翠，雨收黛色冷含青」，真是难得一见的美丽景
致。\n",
		
"一条长白瀑布劈面飞来，涛声阵阵，烟水悠悠。瀑布边是一陡峭小
路，环绕着一池碧水，云遮雾绕。风吹过来，把水吹成轻雾洒在脸上，
凉丝丝的。有几道水流匆匆地往下冲，撞在岩石上，水花四溅，如飞珠
碎玉般晶莹可爱。\n",
	  
"红艳艳的花，在一片嫩绿中绽放。一阵风吹过，吹落了花瓣铺成地
毯，吹红了野花更加娇艳。洁白的栀子花，飘出沁人心脾的馨香。到处
是花，像彩色的海洋，像彩绒的地毯，连绵不断，广阔无尽。鸟啼人不
见，花落树犹香。\n",
		
"一棵威严的百年老树顶着擎天华盖，昂然挺立。树叶黑郁繁茂，透
不出一丝阳光，树干骨骼突出，粗大的根茎像巨大的鹰爪箍住大地。千
千万万条气根，从树干上流苏般地垂挂下来，向四方伸展。\n",
		
"金黄的花朵一团团、一簇簇，开满枝头。仔细一看，花瓣只有米粒
这么大。那五片柔嫩的花瓣就像是用玉石精心雕刻出来的一样，那么小
巧玲珑！花香沁人心脾，令人情不自禁地陶醉在其中，使所有疲劳都烟
消云散。\n",
		
"这棵大杨树约有五层楼高，盛夏时节，远远望去像冲天燃烧的绿色
的火苗。阳光直射的那那些叶子十分青翠，好像谁在叶子上撒上了一大
把金星，闪闪发光。背对阳光的叶子，呈深绿色，仿佛经历了无数沧桑。
绿色而高大的树冠把蓝天衬托得格外明亮，一阵风儿吹来，树梢轻轻摆
动，像对人们愉快地致意。\n",
		
"一棵被闪电削去了大部分的断裂了的树干耸立在眼前，参差不齐的
残枝凌乱地伸向空中。煤炭般漆黑的树干上有许多白点，萎缩的树皮脱
离了树干，在冷风中瑟瑟发抖。\n",
		
"这是一大片荷塘，那荷叶大的似磨盘，有的舒展似伞。荷叶上的水
珠，有的像情人的泪珠，有的分散成细小的碎珠，在荷叶上滚来滚去，
闪烁着斑斓的光彩。远远望去，在周围翠绿的群山映衬下，那一团团的
荷花如胭如染，令人如入仙境。\n",
		
"一座危峰兀立在眼前，怪石嶙峋，崖壁陡似斧削，山石如断，隔老
远望去也让人心惊肉跳，似乎一失脚即刻就会从崖上跌下去，摔得粉身
碎骨。那裸露的岩壁峭石，与崖上绿的树、崖下绿的草相映成趣。一条
涧壑藤萝密，四面原堤草色新。\n",
		
"走在那幽静的山谷小道上，耳边有着动听的昆虫鸣声，阳光被树叶
遮得严严实实，一路上可以清楚得听见泉水丁冬，看见那清澈见底的小
溪。山谷里绿树成阴，树多得像一片绿色的海洋。大树的叶子又绿又密，
像撑开的一把把大大的绿伞。\n",
	  
"鸟儿的歌声充斥在山谷间，唤醒郁郁苍苍的树，风拂过，沙啦啦地
响，带着山野中自然的、青草与薄荷味道的空气，与蓝天白云相交映，
形成一幅美丽到不用加任何修饰的画卷。\n",
		
"你来到了一条小溪边，溪水清澈见底，可以看见小鱼们在水中栖戏。
小溪的四周全是树，一棵棵高大挺拔，像一个个士兵保护着美丽的小溪
，小溪边有一片绿油油的草地，散发着淡淡的泥土芳香，让人不由自主
地想要坐下去休憩片刻。\n",
		
"你走入了一片翠竹林，呼吸着带有竹叶清香的空气，好一个神清气
爽，似如轻舟荡漾在翠竹掩映的海中。风湿漉漉地吹着，飘荡着新鲜的
竹绿气息，深幽绝尘空气飘香，仿佛人世间的喧哗浮躁、名利烦恼统统
都被淹没。\n",
	});
	int i;
	i = random(sizeof(short_name));
	set("short", color[random(sizeof(color))] + short_name[i] + NOR);
	set("long", long_name[i]);
}