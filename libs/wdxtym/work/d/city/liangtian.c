// xiaohuayuan.c

#include <ansi.h>
#include <localtime.h>
inherit ROOM;

void create()
{
	set("short","土地良田");
	set("long", @LONG
这里是一块良田，肥沃土壤十分适合各种种植作物的生长。
LONG
	);

	set("exits", ([ 
		//"west"  : __DIR__"liaotian",
		"down" : __DIR__"beidajie1",
		//"east" : __DIR__"liaotian",
	]));
	set("objects",([ 
		__DIR__"npc/jiuzhong" : 1,
	])); 
	
	set("no_fight", 1);
	set("zhong",1);	
	setup();
}
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""GRN"", ""HIC"", ""HIW"", ""HIR"", ""CYN"",""WHT"",""HIM""});
mapping shuzi=([
		"yumi zhong-b": 5,
		"xiaomai zhong-b": 5,
		"putao zhong-b": 2,
		"nuomi zhong-b": 3,
		"lvdou zhong-b": 4,
		"lihua zhong-b": 4,
		"gaoliang zhong-b": 2,
		"dami zhong-b": 3,							
	]);
	

mapping wenzi=([
		"yumi zhong-b": ([1:"在老农的指点下你对玉米种进行浸泡催芽，慢慢地种子长出了白色的小芽。",
 											2 :"你选择了一处疏松肥沃排水性较好的向阳土坡，然后对土地进行深耕深翻。",
 											3 :"你在地里挖出一个个小坑，然后小心地把玉米种点进坑里，并浇水回埋。",
 		 									4 :"你辛勤地对玉米进行浇水、施肥、除草。眼看玉米苗一天一天变得高大起来。",
 		 									5 :"在玉米开花结果期间，不能够缺水，你按照老农的指点为玉米按时浇水。",
 		 									6 :"金黄的玉米棒子颗粒饱满，你高高兴兴地在田里掰玉米。",//成功
 		 									7 :"修为欠缺，玉米长势虽好但籽粒干瘪，看来稼穑不易，还需继续改进！",//失败	
]),				
			
		"xiaomai zhong-b": ([1:"在老农的指点下你对小麦种进行浸泡防止虫害。",
 											2 :"你对土地进行深耕平整，然后犁出浅沟，把麦种撒进沟里，并进行掩埋。",
 											3 :"你耐心地等待着，慢慢地麦苗破土而出，整块麦地看上去呈淡淡的青色。",
 		 									4 :"你按照老农的指导对麦地进行浇水、施肥、除草、除虫。",
 		 									5 :"麦子经历了抽穗，麦穗青青，麦芒如针，再过段时间，麦子就要成熟了。",
 		 									6 :"你挥舞着镰刀收割麦穗，然后用碾子碾麦，随风扬场，收获麦子！",//成功
 		 									7 :"付出未必就有回报，小麦长势虽好但籽粒干瘪，看来技术还需加强！",//失败	
]),				
		"putao zhong-b":([1:"在老农的指点下你选择了一处土质肥沃的地方进行挖坑，准备扦插葡萄藤。",
 											2 :"你在葡萄坑里施肥浇水，然后把葡萄藤小心翼翼地插在坑里并进行掩埋。",
 											3 :"你在周围用竹竿搭了长架，期待随后的葡萄藤能爬满架子。",
 		 									4 :"葡萄藤慢慢抽芽，爬架，很快就布满了整个架子。",
 		 									5 :"你继续进行浇水、施肥、捉虫等常规工作。",
 		 									6 :"青藤上挂满了成串的葡萄。紫色的葡萄晶莹剔透，让人垂涎欲滴。",//成功
 		 									7 :"青藤虽然枝繁叶茂，但是葡萄却结的很小。看来种植也是一门大学问啊！",//失败	
]),				
		"nuomi zhong-b": ([1:"在老农的指点下你将大块土壤进行分散和压碎，然后进行精耕并整平土壤。",
 											2 :"你将浸泡后的种子放入布袋中，放在阴凉处，进行催芽。",
 											3 :"你将发芽后的种子均匀播种在苗床上，然后覆土，浇足水，等待出苗。",
 		 									4 :"幼苗被你小心地以合理的间隔和间距插入稻田，间隔有序，不宽不密。",
 		 									5 :"你对幼苗进行施肥、除虫，幼苗分蘖、抽穗，正在茁壮成长。",
 		 									6 :"金灿灿的稻穗颗粒饱满，你收割，扬场，忙的不亦乐乎！",//成功
 		 									7 :"修为欠缺，导致出现不少秕谷。看来不少努力就可以了，还需要一定的方法。",//失败	
]),				
		"lvdou zhong-b": ([1:"你将绿豆种摊在席子晾晒，然后使种皮稍有破损，增加其吸水能力。",
 											2 :"你土地进行深耕深翻平整，然后起出几条行并把浸泡后的绿豆种撒播其中。",
 											3 :"慢慢地绿豆苗破土而出。你松了一口气，还担心掩埋过深，怕它们拱不出来呢！",
 		 									4 :"你辛勤地对豆苗进行浇水、施肥、除草。眼看豆苗一天一天变得挺拔起来。",
 		 									5 :"在按照老农的指点继续按时浇水、施肥、除草。天可怜见，希望有个好收成。",
 		 									6 :"绿色的豆荚颗粒饱满，天道酬勤，古人诚不我欺啊！",//成功
 		 									7 :"修为欠缺，绿豆长势虽好但豆荚干瘪，看来还需要向老农多多学习才行！",//失败	
]),				
		"lihua zhong-b":([1:"你选了一处阳坡排水光照良好的地方，对土地进行疏松整理，并施足底肥。",
 											2 :"你将梨树苗放入坑里，然后分层压入细土，并在四周筑小土埂，再浇水。",
 											3 :"梨树苗渐渐长成了小树苗，你常规管理进行浇水、施肥、除虫。",
 		 									4 :"你认真研究梨树种植心得，小树苗变得更高更大了。",
 		 									5 :"你按照老农的指点为梨树修剪枝丫，除去过于枝丫。",
 		 									6 :"梨树终于开花了，一树洁白的繁花，你忙不迭地进行采摘。",//成功
 		 									7 :"梨树虽然开花了，但稀稀疏疏，不成样子。哎！浪费了一颗好苗!",//失败	
]),				
		"gaoliang zhong-b": ([1:"在老农的指点下你对高粱种进行浸泡催芽，慢慢地种子长出了白色的小芽。",
 											2 :"你选择了一处疏松肥沃排水性较好的向阳土坡，然后对土地进行深耕深翻。",
 											3 :"你在地里挖出一个个小坑，然后小心地把高粱种点进坑里，并浇水回埋。",
 		 									4 :"你辛勤地对高粱地进行浇水、施肥、除草。眼看高粱苗一天一天变得高大起来。",
 		 									5 :"在高粱开花结果期间，不能够缺水，你按照老农的指点为高粱按时浇水。",
 		 									6 :"红红的高粱穗子颗粒饱满，你高高兴兴地在田里收割高粱。",//成功
 		 									7 :"修为欠缺，高粱长势虽好但籽粒干瘪，看来稼穑不易，还需继续改进！",//失败	
]),				
		"dami zhong-b": ([1:"在老农的指点下你将大块土壤进行分散和压碎，然后进行精耕并整平土壤。",
 											2 :"你将浸泡后的种子放入布袋中，放在阴凉处，进行催芽。",
 											3 :"你将发芽后的种子均匀播种在苗床上，然后覆土，浇足水，等待出苗。",
 		 									4 :"幼苗被你小心地以合理的间隔和间距插入稻田，间隔有序，不宽不密。",
 		 									5 :"你对幼苗进行施肥、除虫，幼苗分蘖、抽穗，正在茁壮成长。",
 		 									6 :"金灿灿的稻穗颗粒饱满，你收割，扬场，忙的不亦乐乎！",//成功
 		 									7 :"修为欠缺，导致出现不少秕谷。看来不少努力就可以了，还需要一定的方法。",//失败	
]),										
	]);

string* use_phrase = ({"将", "把", });
string* use_name = ({"水瓢中的", "瓢中的", "水瓢里的", "瓢里的", "", });
string* use_what = ({"水", "清水", });
string* use_arj = ({"随随便便的", "轻轻松松的", "小心翼翼的", "随便的", "轻松的", "", "马马虎虎的", "马虎的", });
string* use_action = ({"向", "往", });
string* use_where = ({"前", "后", "左", "右", "上", "下", });
string* action_arj = ({"一洒", "洒", "浇", "一浇", });


string getwq(object me, string id);
int getsld(object me, string id);

void init()
{
	//if (interactive(this_player()) && environment() == this_player())
	//{
		add_action("do_zhuwuqi","lzdy");
		add_action("do_tzlz","tzlz");
		add_action("do_zhong", "zhonght");//种桃
		add_action("do_jiao", "jiaoht");//浇桃
	//}
}

int do_zhong()
{
	object ob1, me;

	me = this_player();
		
		 if (me->is_busy()) 
		 	{
		tell_object(me,"等你忙完再种桃吧。\n");
			return 1;
			}
	   // if (environment(me) != find_object("/d/xiangyang/xibian")) 
		//return notify_fail("这里能舀到浇花用的水？\n");
		
			if (!ob1 = present("tao zhong-b", this_player()))
			{
			tell_object(me,"有了桃核，你才能种桃。\n");
			return 1;
			}
			if (! environment(me)->query("zhong")){
			tell_object(me,"只有在良田里才能种桃。\n");
			return 1;
			}
	
	    tell_object(me,"你四处张望了一下，选了一处好地。弯下腰，从把桃核种在地里。\n");
	    me->set("monkey/zhong",time());
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(3)));
	    ob1->add_amount(-1);
	    return 1;
}

int do_jiao()
{
	mixed *local;
	int totaltime, water_time, curent_time, seeded, hour, day, month;
	object room, ob, me, obnew, pound;
	string msg;

	ob = this_object();
	me = this_player();
	room = find_object("/d/city/liangtian");
	local = localtime(time());

	hour = 100;
	day = 10000;
	month = 1000000;
	curent_time = (local[LT_MON] + 1) * month + local[LT_MDAY] * day + local[LT_HOUR] * hour + local[LT_MIN];
// 例如11月23日下午3点21，得到的curent_time就是11231521

// 没有水瓢、瓢里没有水、忙时的判断
	//if (! objectp(ob = present("shui piao", me)))
	  //  return notify_fail("你没有水瓢，怎么洒水？\n");
	//if (! arg || (arg != "shui" && arg != "water"))
	  //  return notify_fail("你要洒什么？\n");
	if (me->is_busy()) 
	    return notify_fail("等你忙完再洒水吧！\n");
	//if (! ob->query("filled")) 
	  //  return notify_fail("瓢里没水！\n");

// 如果不是在花房浇水的后果
	if (environment(me) != room)
	{
	    message_vision("$N随随便便的把水洒在地上。\n", me);
	    //ob->delete("filled");
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(5)));
	    return 1;
	}

// 没有播种种子的后果，播种的标记放在种子上了。
	if (! me->query("monkey/zhong"))
	{
	    message_vision("$N舀了一瓢水，四处看看没什么可浇的，就顺手把水浇到了老农的脚上。\n", me);   
	    //ob->delete("filled");
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(5)));
	    tell_object(me, "老农大怒劈手夺下水瓢，顺手给你一巴掌，说：“没有种桃，你浇什么水？”\n");
	    return 1;
	}

	water_time = me->query("monkey/seeded");
// 设置water_time为上次干活的时间，干活可以是播种和浇水。
// 设置water为总浇水的次数，用于控制总的种植时间和阶段描述，
// 每次浇水需要间隔5-10分钟，water为30次，则总的培植时间为现实中的3-5小时。
	if (! me->query("monkey/water"))
	{
// 第一次浇花，只所以单独列出来，是因为从播种到浇花，玩家可能需要更多些的摸索和适应的时间。
	    message_vision("$N小心翼翼地看了看桃核埋下的位置。\n", me);   
//	    ob->delete("filled");
//	    me->start_busy(1+random(2));
//	    me->receive_damage("jing", (20 + random(5)));
//	    me->set("monkey/water", 1);
//	    me->set("monkey/seeded", curent_time);
//	    return 1;
	}

	//if (me->query("monkey/water") && water_time + 5 > curent_time) // 浇完一次后5分钟才可以再浇。
	if (me->query("monkey/water") && water_time + 1 > curent_time) // 浇完一次后1分钟才可以再浇。

	{
	    me->start_busy(2 + random(3));
	    return notify_fail("不是才刚灌溉过么，这么一直浇会把桃树淹死的！\n");
	}
	//if (me->query("monkey/water") && water_time + 10 < curent_time)// 10分钟内不浇水培植失败。
	if (me->query("monkey/water") && water_time + 15 < curent_time)// 15分钟内不浇水培植失败。

	{
	    tell_object(me, "糟糕，很久没给桃树浇水，培植失败。:(\n");
	    me->delete("monkey/water");
	    me->delete("monkey/seeded");
	    me->add("monkey/fail", 1);
	    return 1;
	}

	message_vision("$N" + use_phrase[random(sizeof(use_phrase))] + use_name[random(sizeof(use_name))] +
			      use_what[random(sizeof(use_what))] + use_arj[random(sizeof(use_arj))] +
			      use_action[random(sizeof(use_action))] + use_where[random(sizeof(use_where))] +
			      action_arj[random(sizeof(action_arj))] + "。\n", me);
	//ob->delete("filled");
	me->add("monkey/water", 1);
	totaltime = me->query("monkey/water");
	me->start_busy(3 + random(3));
	me->receive_damage("jing", (60 + random(60)));
	me->set("monkey/seeded", curent_time);

// 三十次浇花，每次都对花的感受是不一样的。
	switch (me->query("monkey/water"))
	{
		case 1:
			msg = "刚开始浇水，你感觉还有些新鲜感，也不觉得累。";
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
			msg = "哇！种子终于发芽了，你高兴地跳了起来。";
			break;
		case 5:
		case 6:
			msg = "桃树嫩芽在一点点长高，你心里充满了喜悦。";
			break;
		case 7:
		case 8:
		case 9:
			me->receive_damage("qi", 50);
			msg = "桃树苗在一点点长高，现在已经有" + chinese_number(totaltime/2) + "尺高了。";
			break;
		case 11:
		case 12:
			me->receive_damage("qi", 30);
			msg = "桃树又生出些许嫩叶，色泽艳丽、株形优美。";
			break;
		case 13:
			msg = "桃树叶子表面绿色而有光泽。";
			break;
		case 14:
			me->receive_damage("qi", 20);
			msg = "桃树的叶子更加茂盛了。";
			break;
		case 15:
			msg = "你突然发现桃树已经开花了。";
			break;
		case 17:
			me->receive_damage("qi", 30);
			msg = "呀！桃树上的花呈粉红色，非常好看。";
			break;
		case 19:
			me->receive_damage("qi", 20);
			msg = "只见这桃树粉红色的花蕾含苞待放，惹人怜爱。";
			break;
		case 20:
		case 21:
			msg = "桃树花蕾渐渐退去，一个一个的小桃子挂满枝头。";
			break;
		case 23:
		case 28:
			me->receive_damage("qi", 30);
			msg = "细观桃树，桃子在一天一天变大。";
			break;
		case 24:
		case 25:
			msg = "桃子把枝丫都压弯了。";
			break;
		case 27:
			msg = "鲜红的桃子看上去非常饱满，表面布满了绒毛。\"";
			break;
		case 29:
			me->receive_damage("qi", 50);
			msg = "看样子已经很成熟了，在过段时间就可以收获了。";
			break;
		case 30:
			me->receive_damage("qi", 60);
			msg = "看上去桃子已经培植成功，赶快收起来换猴儿酒吧。";
			break;
		default:
			msg = "为了能把桃子培植成功，就不能怕浇水枯燥辛苦。";
			break;
	}

	msg += "\n";
	tell_object(me, (order[random(11)])+ msg + NOR + "\n");
	if (totaltime > 30)// 这种情况正常情况下不会出现，加此CODE是防患于未然，避免进入死循环。
	{
	    tell_object(me, "糟糕，由于你的操作失误，桃子培植失败。:(\n");
	    me->delete("monkey/water");
	    me->delete("monkey/seeded");
	    me->add("monkey/fail", 1);
	    return 1;
	}
	if (totaltime == 30) // 浇花30次后，培植成功。
	{
	    me->delete("monkey/water");
	    me->delete("monkey/seeded");
	    me->delete("monkey/zhong");
	    
	    
	    if(me->query("kar")*2>random(100))
	    {	
	     	obnew = new("/clone/wine/yuanliao/monkey5");
	    	obnew->set_amount(1);
	    	obnew->move(me);
	     	tell_object(me,HIG"你收获了一枚"HIR"仙桃"HIG"。\n"NOR);
	     
	     	obnew = new("/clone/wine/yuanliao/monkey");
	    	obnew->set_amount(4);
	    	obnew->move(me);
	    	tell_object(me,HIG"你收获了四枚"RED"鲜桃"HIG"。\n"NOR);	     
	  	}
	  	else
	  	{
	  	 	obnew = new("/clone/wine/yuanliao/monkey");
	    	obnew->set_amount(5);
	    	obnew->move(me);
	    	tell_object(me,HIG"你收获了五枚"RED"鲜桃"HIG"。\n"NOR);	    	
	  	}
	  		
	    //me->add("monkey/qxhtget", 1);
	    //me->set("monkey/qxht/have", 1);
	}
	return 1;
}

int do_tzlz(){
	object me = this_player();
	
	tell_object(me,HIR"即将停止种植。\n"NOR);
	me->delete_temp("dzz");
//	me->delete_temp("zhong");
	return 1;
}

int do_zhuwuqi(string arg){
	object me = this_player();
	string pops;
	string wq,xh,cl;
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能进行种植。\n");
		return ;
	}
	
	if(sscanf(arg,"%s %s %s", wq, xh, cl) == 3){
		if(wq == "dao"){
			set_temp("wuqi","1");
		}else{
			tell_object(me,"种植类型参数错误。\n");
			return 1;
		}
		
		if(xh == "1"){
			set_temp("xh",1);
		}else if(xh == "2"){
			set_temp("xh",2);
		}else{
			tell_object(me,"种植方式类型参数错误。\n");
			delete_temp("wuqi");
			return 1;			
		}
		
		if(cl == "1"){
			set_temp("cl",1);
		}else if(cl == "2"){
			set_temp("cl",2);
		}else if(cl == "3"){
			set_temp("cl",3);
		}else{
			tell_object(me,"处理方式参数错误。\n");
			delete_temp("wuqi");
			delete_temp("xh");
			return 1;			
		}
		
		if(me->query_temp("dzz")){
			tell_object(me,"你正在种植中，重新设置请先停止种植。\n");
		}else{
			me->set_temp("dzz",1);
			call_out("zhuzao1", 2, me);			
		}

		return 1;	
	}
	
	if(sscanf(arg, "%s %s", wq, xh) == 2){
		pops = ZJOBLONG"请选择种植的处理方式：\n";
		pops += ZJOBACTS2+ZJMENUF(1,1,10,30)+
			HIR"立即卖掉（会得到一定的银两，不推荐）:lzdy "+wq+" "+xh + " 1"ZJSEP
			HIC"分享作物（田园牧歌修为会额外增加）:lzdy "+wq+" "+xh + " 2"ZJSEP
			HIG"存在包里（可以种植可提升田园牧歌。）:lzdy "+wq+" "+xh + " 3\n";
		tell_object(me,pops);
		return 1;	
	}
	
	if(arg){
		
		pops = ZJOBLONG"请选择种子的使用方式"ZJBR"（材料用完后会自动停止）：\n";
		pops += ZJOBACTS2+ZJMENUF(1,1,10,30)+
			HIR"优先种植低级种子:lzdy "+arg+" 1"ZJSEP
			HIG"优先种植高级种子:lzdy "+arg+" 2\n";
		tell_object(me,pops);
		return 1;		
		
	}

}

void zhuzao1(object me){
	object ob;
	
	if(!interactive(me)){
		tell_object(me,"你已离线，作物种植停止。\n");
		do_tzlz();
		return ;		
	}
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}		
	
	if((int)me->query("jing")<100
	||(int)me->query("qi")<100
	||(int)me->query("neili")<150)    
	{
		tell_object(me, "你的精、气、内或者少于100，无法种植。\n");
		do_tzlz();
		return;
	}
	
	if(query_temp("xh") == 1){
		if (!(ob = present("gaoliang zhong-b", this_player())) &&
		!(ob = present("putao zhong-b", this_player())) &&
		!(ob = present("dami zhong-b", this_player())) &&
		!(ob = present("nuomi zhong-b", this_player())) &&
		!(ob = present("lihua zhong-b", this_player())) &&
		!(ob = present("lvdou zhong-b", this_player())) &&
		!(ob = present("xiaomai zhong-b", this_player())) &&	
		!(ob = present("yumi zhong-b", this_player())))
		{
			tell_object(me, "只有高粱、葡萄、大米、糯米、梨花、绿豆、小麦、玉米等种苗才能种植。\n");
			do_tzlz();
			return;
		}
	}else{
		
		if (!(ob = present("yumi zhong-b", this_player())) &&
		!(ob = present("xiaomai zhong-b", this_player())) &&
		!(ob = present("lvdou zhong-b", this_player())) &&
		!(ob = present("lihua zhong-b", this_player())) &&
		!(ob = present("nuomi zhong-b", this_player())) &&
		!(ob = present("dami zhong-b", this_player())) &&
		!(ob = present("putao zhong-b", this_player())) &&	
		!(ob = present("gaoliang zhong-b", this_player())))

		{
			tell_object(me, "只有高粱、葡萄、大米、糯米、梨花、绿豆、小麦、玉米等种苗才能种植。\n");
			do_tzlz();
			return;
		}		
	}
	me->set_temp("zhong/name",ob->name());
	me->set_temp("zhong/id",ob->query("id"));
	me->set_temp("zhong/level",ob->query("level"));
	me->set_temp("zhong/end",ob->query("end"));
	me->set_temp("zhong/shuzi",shuzi[me->query_temp("zhong/id")]);

	ob->add_amount(-1);

	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][1]+"\n"NOR);
	call_out("zhuzao2", me->query_temp("zhong/shuzi"), me);
}

void zhuzao2(object me){

	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,HIW""+wenzi[me->query_temp("zhong/id")][2]+"\n"NOR);
	call_out("zhuzao3", me->query_temp("zhong/shuzi"), me);
}

void zhuzao3(object me){

	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][3]+"\n"NOR);
	call_out("zhuzao4", 2, me);
}

void zhuzao4(object me){

	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][4]+"\n"NOR);
	call_out("zhuzao5", me->query_temp("zhong/shuzi"), me);
}

void zhuzao5(object me){
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][5]+"\n"NOR);
	call_out("zhuzao6", me->query_temp("zhong/shuzi"), me);//注意改
}

void zhuzao6(object me){
	object ob1;
	string wqstr = query_temp("wuqi");
	string wqdj;
	string obid;
	int n,nn,skill;
	int bijiao,jilv,ok;
	skill=me->query_skill("tianyuan-muge",1);
	
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}		
	
	obid = me->query_temp("zhong/id");
	

	 
	//成功的几率和田园牧歌等级相关。
//成功率
	ok=0;	
	bijiao=skill-me->query_temp("zhong/level");
			
	if(bijiao<0)jilv=20;//
	if(bijiao>=100)jilv=100;//	超过100级100%
	else	
	jilv=25+bijiao;//超过50级75%,田园牧歌刚达到相应等级成功几率25%,
	
	if(jilv>=random(100))
	ok=1;		
	
	if(ok)	
	{
	ob1=new(me->query_temp("zhong/end"));	
	}

		if(ob1)
		{	
		ob1->move(me);      
	
		tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][6]+"\n"NOR);
		
		call_out("zhuzao8", 2, me,obid,ob1);		
		}
		else
		{
	
		tell_object(me,HIR""+wenzi[me->query_temp("zhong/id")][7]+"\n"NOR);
		
		call_out("zhuzao8", 2, me,obid,0);
		}	
}

void zhuzao8(object me, string obid, object ob1){
	int exp,pot,sld;
		
	if (! environment(me)->query("zhong")){
		tell_object(me,"只有在良田才能种植。\n");
		do_tzlz();
		return ;
	}
	
	exp = 50 + random(20);
	pot = 25 + random(5);
	
	me->add("combat_exp",exp);
	me->add("potential",pot);	
	
	sld = getsld(me,obid);
	sld = sld/2+random(sld);
	
		
	if(ob1){
			tell_object(me,"你得到了一"+ob1->query("unit")+ob1->name()+"。\n你获得了"+exp+"点修为、"+pot+"点潜能、"+sld+"点田园牧歌熟练度。\n");
			me->improve_skill("tianyuan-muge",sld,0); 
		if(query_temp("cl") == 1){
			me->force_me("sellob "+file_name(ob1));
		}if(query_temp("cl") == 2){ 
			tell_object(me,"你慷慨地将"+ob1->name()+"与老农分享。在老农热心指点下，你的田园牧歌熟练度+"+sld/2+"点。\n");
			destruct(ob1);
			me->improve_skill("tianyuan-muge",sld,0);
		}
	}else{
			me->improve_skill("tianyuan-muge",sld/2,0); 
			tell_object(me,"虽然种植失败，但还是得到了"+exp+"点修为，"+pot+"点潜能,"+sld/2+"点田园牧歌熟练度。\n");
	}
	
	//if(	me->query_temp("dzz")&&	me->querye_temp("zhong"))
	if(	me->query_temp("dzz"))	
	call_out("zhuzao1", 1, me);
}

int getsld(object me){
	int bl;
	string id;
	id=me->query_temp("zhong/id");
	bl = (100 + me->query_int()) * 10;
	if(id == "yumi zhong-b"){
		return bl + 3200;
	}else if(id == "xiaomai zhong-b"){
		return bl + 1600;
	}else if(id == "lvdou zhong-b"){
		return bl + 800;
	}else if(id == "lihua zhong-b"){
		return bl + 400;
	}else if(id == "nuomi zhong-b"){
		return bl + 200;	
	}else if(id == "dami zhong-b"){
		return bl + 100;
	}else if(id == "putao zhong-b"){
		return bl + 50;
	}else if(id == "gaoliang zhong-b"){
		return bl;
	}else{
		return bl;
	}
}


int valid_leave(object me, string dir)
{

	if (playerp(me) && dir == "west")
	{
		if (me->query_temp("dzz"))
			return notify_fail(HIR"种子这么珍贵，还没收获人就走了岂不可惜？\n"NOR);
	}

	return ::valid_leave(me, dir);
}