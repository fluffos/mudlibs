// 虚拟彩票机器 bingo.c
// 配套文件 caipiao.c
// by naihe 19:55 02-10-5~6
// 诸赔率等设置可待调整
// 最后修改：by naihe 02-10-13
// 最后修改：by naihe 02-10-31  学会了 for 及 *型变量后，
// 添加了一次性登记的程序，终于解决这最麻烦的问题
// 添加了随机一次性买多张彩票的问题 puma @xkm 03-1-22

#include <ansi.h>
inherit ITEM;

int caipiao_all();
int do_mai2(object me);

int number,yeah_nba,yeah_nbb,yeah_nbc,yeah_nbd,
pr_nba,pr_nbb,pr_nbc,pr_nbd,max_number,sell_times,
jj_arank,jj_brank,jj_crank,jj_leiji,arank,brank,crank,
wait_time,dengji_time,jiafen,
jiafen=0,         // 每期额外添加的奖金，由巫师手动设置（或不设置）
jj_leiji=300,
max_number=18,    // N 选 4 
wait_time=2400,   // 下注时限为40分钟
dengji_time=1200;   // 登记中奖时限为20分钟

// 当前设置为每1个小时开一期。
// 另外，若能开设数据同步的代办点，生意将会更好；但奈何现在的技术无法实现。。。

string now,wiz_id,biaoji,games_now,pindao,
now="stop",
wiz_id="系统",
biaoji="none",
pindao="jiaoyi";   // 这里可以更改所有公布信息所使用的频道。

int temp_time;  // 玩家可以此查询当前销售（对奖）之剩余时间（单位为分钟）。
string temp_time_ms1,temp_time_ms2;  // 上述变量的描述，是在什么阶段的等待时间，将要干什么

// temp_time_ms1="彩票销售" , temp_time_ms2="开奖"
// temp_time_ms1="对奖登记" , temp_time_ms2="停止对奖"

void create()
{
	set_name(HIW"彩票售卖机"NOR, ({"caipiao ji","ji"}));
	set_weight(10000000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一部彩票售卖机，机身上帖有一张说明(shuoming)。\n");
		set("unit", "部");
		set("value", 0);
		set("no_get","1");
	}

	set("no_clean_up",1);
	setup();
}

void init()
{
	add_action("do_mai","mai");
	add_action("do_duijiang","duijiang");
	add_action("do_duijiang","dengji");
	add_action("do_lingjiang","lingjiang");
	add_action("do_look","look");
	add_action("do_chk","chk");
	if(wizardp(this_player()))
	{
		add_action("do_qidong","qidong");
		add_action("do_guanbi","guanbi");
		add_action("do_setset","setset");
		add_action("do_kaijiang","kaijiang");
		add_action("do_zzdengji","zzdengji");
		add_action("do_ck","ck");
	}

// 修改 by naihe 2002-10-06 晚7时，系统将会自动开启程序。

	if(now=="stop" && wiz_id=="系统" && biaoji=="none" && !wizardp(this_player()))
	{
		now="start";
		switch(random(3))
		{
			case 0:biaoji="侠客之光";break;
                        case 1:biaoji="侠客风采";break;
			case 2:biaoji="天临之财";break;
		}
		number=1;
		games_now="waiting";
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf("“%s”彩票第%d期开始售卖了！",biaoji,number));
		log_file("caipiao/caipiao", sprintf("\n\n\n由%s于%s启动了名为“%s”的彩票程序。\n",wiz_id,ctime(time()),biaoji));
		remove_call_out("caipiao_all");
		call_out("caipiao_all",1);
		temp_time=wait_time /60;
		temp_time_ms1="彩票销售";
		temp_time_ms2="开奖";
		remove_call_out("now_all_time");
		call_out("now_all_time",1);
	}
}

int do_look(string arg)
{
	object me=this_player();

	if(!arg || (arg!="shuoming" && arg!="shuoming2" && arg!="shuoming3")) return 0;

	if(arg=="shuoming")
	{

write(HIW"━━━━━━━━━━━━━━━━━━━━━━━━━"NOR"
                 "HIY"彩票游戏说明"NOR" ("+max_number+"选4型)

本游戏共分三个奖级(中奖号码顺序不限)：
一等奖 4 个号码；二等奖 3 个号码；三等奖 2 个号码。

一等奖奖金为本期累积奖池的4/5金额，二等奖奖金为本
期累积奖池的1/5金额。三等奖奖金为本期销售额的1/2。
每期的1/3销售额累积入累积奖池中。若同奖级同时有数
人中得，将均分该期该级奖金。

一等奖奖金保底100 GOLD（即无论多少人中，人均至少可
获得100 GOLD），个人封顶300 GOLD。
二等奖奖金保底20 GOLD，个人封顶100 GOLD。
三等奖奖金保底1 GOLD。
"HIY"另外，累积奖金将实行最少每期300 GOLD的保底方案。"NOR"

欲查看更具体的操作流程及指令，请输入<look shuoming2>. 

另外，用 <chk 类型 期号> 指令将可查得该期开奖号码；
 <chk> 指令，将得到本期当前投注额、剩余时间等资讯；
 <chk now> 指令，查询本期开奖号码及当前累积奖池。\n");
	if(wizardp(me))
		write("\n"HIR"巫师可用之特殊指令，用look shuoming3 指令查看。\n"NOR);
	write(HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR);
	return 1;
	}


	if(arg=="shuoming2")
	{
write(HIW"━━━━━━━━━━━━━━━━━━━━━━━━━"NOR"
                 "HIY"彩票游戏流程"NOR" ("+max_number+"选4型)
    欢迎各位进行彩票游戏。本游戏基本流程如下：
    "HIY"1、售彩时间："NOR"
    每期的"HIR"售票时限是"+(wait_time/60)+"分钟"NOR"。在这段时间里，你可以
购买彩票，指令是：<mai 1 2 3 4> (自定号码) 或 
<mai random> (随机号码) 。彩票售1 GOLD/张。
    "HIY"2、对奖登记："NOR"
    在售票时限到达之后，机器将会随机开出本期的中奖
号码。短短的开奖结束了，就可以进行对奖登记的步骤，
指令是 <duijiang piao>。若你身上携带的彩票"HIR"数量甚多"NOR"，
那么你可以在之前的时候领取一个彩票盒子，把彩票都放
进去，输入 <duijiang he> 一次性自动对奖。
    "HIR"对奖登记的时限只有"+(dengji_time/60)+"分钟"NOR"。购买了当期彩票的各位
务必及时进行对奖登记，因为"HIR"下一期售票开始后，前一期
未登记的彩票都将作废"NOR"。
    "HIY"3、领奖："NOR"
    登记时间过后，将会公布本期得奖人数、奖金等，这
时候，已登记的彩票可在稍后的任意时间里进行领奖（当
然，机器重启时及一切意外情况，都不在此论）。指令为：
<lingjiang piao> 。进行过领奖的彩票，将会被机器回收。
    这个时候，机器开始发售新一期的彩票，进入新一轮
的循环。祝各位中得大奖！\n");
	write(HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR);
	return 1;
	}

	if(arg=="shuoming3")
	{
		if(!wizardp(this_player())) return 0;
		write(HIG"\n本彩票机，巫师可用的指令如下（请小心使用）：
qidong --启动彩票游戏。需要输入一个标识，例如“侠客之光”。

guanbi --关闭彩票游戏。必须小心的是如何处理本期已卖出的彩票。

setset --这里是一些设置，格式为 <setset 标记 数字>，详细有：
         wait   ->设置售彩时限，单位为秒。例如 setset wait 600 .
         dengji ->设置登记时限，单位为秒。
         max    ->最大号码，例如更改为 18 就是“18选4型”，谨慎！
         jiafen ->每期的额外加分，将在每期开始的时候添加到累积奖金池里。
         leiji  ->立即把该数值添加到累积奖金池里。请谨慎使用。

kaijiang --立刻开奖。当然，这需要游戏进程是在“等待售彩”的步骤，否则无效。

zzdengji --终止登记。当然，这需要游戏进程是在“登记中奖”的步骤，否则无效。

ck     --无信息(arg)时，可查询当前的一些设置以及本期的一些资讯。
         当信息是 1/2/3 的时候，将可以得到必中当期 1/2/3 等奖的彩票一张。

以上是本机现行的巫师可用的指令，请顾虑大局，小心使用。\n"NOR);
		return 1;
	}
	return 1;
}

int do_setset(string arg)
{
	int times;
	string which;

	if(!wizardp(this_player())) return 0;
	if(!arg || sscanf(arg, "%s %d", which,times)!=2)
		return notify_fail("指令格式：<setset wait/dengji/max/jiafen/leiji 数字> 详细请用 <look shuoming3> 指令查看。\n");

	if(which!="wait" && which!="dengji" && which!="max" && which!="jiafen" && which!="leiji")
		return notify_fail("指令格式：<setset wait/dengji/max/jiafen/leiji 数字> 详细请用 <look shuoming3> 指令查看。\n");

	if(which=="wait") wait_time=times;
	if(which=="dengji") dengji_time=times;
	if(which=="max") max_number=times;
	if(which=="jiafen") jiafen=times;
	if(which=="leiji") jj_leiji+=times;

	write("设置好了。\n");
	return 1;
}

int do_ck(string arg)
{
	object me,caipiao;

	me=this_player();

	if(!wizardp(me)) return 0;

	if(arg)
	{
		if(arg!="1" && arg!="2" && arg!="3")
			return notify_fail("想要几等奖（1/2/3）的彩票？\n");
		caipiao=new(__DIR__"caipiao");
		caipiao->set("number_info/biaoji_a",biaoji);
		caipiao->set("number_info/biaoji_b",wiz_id);
		caipiao->set("number_info/qihao",number);
		caipiao->set("long","这是一张 "+biaoji+" "+max_number+"选4 型彩票，上面印着几个模模糊糊的号码。\n");
		if(arg=="1") caipiao->set("is_bingo",4);
		if(arg=="2") caipiao->set("is_bingo",3);
		if(arg=="3") caipiao->set("is_bingo",2);
		caipiao->move(me);
		message_vision("$N拍了拍"+this_object()->query("name")+"，忽地从机器里掉出了一张彩票，$N拣了起来。\n",me);
		return 1;
	}

	write("最大号码："+max_number+" 押注时限（秒）："+wait_time+" 登记时限（秒）："+dengji_time+" 累积奖池： "+jj_leiji+" 本期投注额："+sell_times+" 启动者："+wiz_id+" 加分："+jiafen+" 正在进行："+temp_time_ms1+" 时间剩余 "+temp_time+" 分钟。\n");

	return 1;
}

int do_kaijiang()
{
	if(!wizardp(this_player())) return 0;
	if(games_now!="waiting") return notify_fail("这个指令只能作为加速开奖使用，现在并非等待开奖的状态。\n");
	remove_call_out("caipiao_all");
	remove_call_out("wait_shows");
	call_out("wait_shows",1);
	write("ok.\n");
	return 1;
}

int do_zzdengji()
{
	if(!wizardp(this_player())) return 0;
	if(games_now!="duijiang") return notify_fail("这个指令只能作为加速对奖登记使用，现在并非登记中的状态。\n");
	remove_call_out("bonus_all");
	call_out("bonus_all",1);
	write("ok.\n");
	return 1;
}	

int do_qidong(string arg)
{
	object me=this_player();

	if(!wizardp(me)) return 0;

	if(now!="stop")
		return notify_fail("程序已在执行，不必再次启动。\n");

	if(!arg) return notify_fail("请输入一个标记，例如“ 侠客风采”。\n");

	wiz_id=getuid(me);
	biaoji=arg;
	now="start";
	message_vision(HIW"$N启动了彩票程序！\n"NOR,me);
	number=1;
	CHANNEL_D->do_channel(me, "rumor", sprintf("由%s启动的“%s”彩票第%d期开始售卖了！", me->query("name"),biaoji,number));

// log 记录。 (1/4)
	log_file("caipiao/caipiao", sprintf("\n\n\n由%s于%s启动了名为“%s”的彩票程序。\n",wiz_id,ctime(time()),biaoji));
	games_now="waiting";

/************************************************
waiting  等待下注           （可以：押注、领奖）
wait_shows 准备开奖         （可以：领奖）
showing  开奖中             （可以：领奖）
duijiang 等待对奖登记中     （可以：对奖、领奖（本期除外））
wait_new 准备新一轮开始     （可以：领奖）
**************************************************/

	call_out("caipiao_all",1);
	temp_time=wait_time /60;
	temp_time_ms1="彩票销售";
	temp_time_ms2="开奖";
	remove_call_out("now_all_time");
	call_out("now_all_time",1);

	return 1;
}

int do_guanbi()
{
	object me=this_player();

	if(!wizardp(me)) return 0;

	if(now!="start")
		return notify_fail("程序已经停止执行，不必再次关闭。\n");

	wiz_id=getuid(me);
	now="stop";
	message_vision(HIR"$N关闭了彩票程序！\n"NOR,me);
	tell_object(me,"你关闭了彩票程序！本期售出的"+sell_times+"张彩票，可要想办法处理才行！\n");
	CHANNEL_D->do_channel(me, "rumor", sprintf("%s关闭了彩票程序！", me->query("name")));


// log 记录。 (2/4)
	log_file("caipiao/caipiao", sprintf("\n由%s于%s关闭了名为“%s”的彩票程序。\n",wiz_id,ctime(time()),biaoji));

	return 1;
}

void caipiao_all()
{
	if(now!="start") return;
	if(games_now!="waiting") return;

	call_out("wait_shows",wait_time);
// 实际上这个地方毫无必要，专门写一个函数，是为了看起来清晰舒服些而已。
}

void wait_shows()
{
	if(now!="start") return;
	if(games_now!="waiting") return;
	games_now="wait_shows";

/***********************************************************
******************** 奖级奖金分配设置在此 ******************
***********************************************************/

	jj_leiji = jj_leiji + jiafen + (sell_times*3/10);

// 总计本期累积奖金，为 上期累积奖金+每期额外的加分+本期销售额的十分之三，
// 额外加分由巫师手动设置（或不设置）。

	jj_arank=(jj_leiji*8/10);
// 头奖奖金为累积池里的8/10.

	jj_brank=(jj_leiji*2/10);           
// 二奖奖金为累积池里的2/10.

	jj_crank=(sell_times*5/10);
// 销售额的 5/10 分配给三奖（另外3/10计入累积奖金中，2/10为正常消耗。）.
	if(jj_crank<1) jj_crank=1;

// 注：当前计算方式为推广期间的测试方法，返奖率偏高。

/*
	if(find_player("naihe"))
		tell_object(find_player("naihe"),HIR"本期预算累积奖金达 "+jj_leiji+" 两。\n"NOR);

// 告诉本程序作者运转情况。
*/

	CHANNEL_D->do_channel(this_object(), pindao, sprintf("第%d期“%s”"+max_number+"选4型彩票中奖号码即将开出！",number,biaoji));
	CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期共有%d注投注，累积奖池奖金高达%d两黄金，头奖奖金高达%d两黄金！",sell_times,jj_leiji,jj_arank));
	call_out("shows",5);
}

void shows()
{
	if(now!="start") return;
	if(games_now!="wait_shows") return;
	games_now="showing";
	CHANNEL_D->do_channel(this_object(), pindao, sprintf("第%d期“%s”彩票中奖号码摇奖开始了！",number,biaoji));
	call_out("random_number_a",5);
}

void random_number_a()
{
	if(now!="start") return;
	if(games_now!="showing") return;

	yeah_nba=1+random(max_number);
	CHANNEL_D->do_channel(this_object(),pindao,sprintf("第一个中奖号码是：%d ！",yeah_nba));
	call_out("random_number_b",3);
}

void random_number_b()
{
	if(now!="start") return;
	if(games_now!="showing") return;

	yeah_nbb=1+random(max_number);
	if(yeah_nbb==yeah_nba) random_number_b();
	else
	{
		CHANNEL_D->do_channel(this_object(),pindao,sprintf("第二个中奖号码是：%d ！",yeah_nbb));
		call_out("random_number_c",3);
	}
}

void random_number_c()
{
	if(now!="start") return;
	if(games_now!="showing") return;

	yeah_nbc=1+random(max_number);
	if(yeah_nbc==yeah_nba || yeah_nbc==yeah_nbb) random_number_c();
	else
	{
		CHANNEL_D->do_channel(this_object(), pindao, sprintf("第三个中奖号码是：%d ！",yeah_nbc));
		call_out("random_number_d",3);
	}
}

void random_number_d()
{
	if(now!="start") return;
	if(games_now!="showing") return;

	yeah_nbd=1+random(max_number);
	if(yeah_nbd==yeah_nba || yeah_nbd==yeah_nbb || yeah_nbd==yeah_nbc) random_number_d();
	else
	{
		CHANNEL_D->do_channel(this_object(), pindao, sprintf("第四个中奖号码是：%d ！",yeah_nbd));
		call_out("caipiao_showsover",3);
	}
}

void caipiao_showsover()
{
	if(now!="start") return;
	if(games_now!="showing") return;

	CHANNEL_D->do_channel(this_object(), pindao, sprintf("请中了奖的朋友尽快到售票点登记对奖（下一期开始的时候本期将作废）！"));
	CHANNEL_D->do_channel(this_object(), pindao, sprintf("第%d期“%s”彩票开出的中奖号码是："HIR"%d %d %d %d "NOR"。",number,biaoji,yeah_nba,yeah_nbb,yeah_nbc,yeah_nbd));
	games_now="duijiang";

// log 记录 (3/4)。

	log_file("caipiao/caipiao", sprintf("\n“%s”第%d期(%d选4)共投%d注，头奖金额为%d两黄金。\n",biaoji,number,max_number,sell_times,jj_arank));
	log_file("caipiao/caipiao",sprintf("第%d期开奖号码是：%d %d %d %d .\n",number,yeah_nba,yeah_nbb,yeah_nbc,yeah_nbd));


	call_out("bonus_all",dengji_time);
	temp_time=dengji_time /60;
	temp_time_ms1="登记对奖";
	temp_time_ms2="停止登记，所有未登记彩票均会作废";
	remove_call_out("now_all_time");
	call_out("now_all_time",1);
}

void now_all_time()
{
	if(now!="start") return;
	if(temp_time<=0) return;

	if(temp_time==1)
	{
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf("第%d期“%s” %s 时间只剩余最后 %d 分钟即将%s！",number,biaoji,temp_time_ms1,temp_time,temp_time_ms2));
	}

	temp_time--;
	remove_call_out("now_all_time");
	call_out("now_all_time",60);
}

void bonus_all()
{
	string arank_temp,brank_temp,crank_temp,temp_here;
	int ar_tm,br_tm,cr_tm;

	if(now!="start") return;
	games_now="wait_new";
	CHANNEL_D->do_channel(this_object(), pindao, sprintf("第%d期“%s”彩票截止对奖登记了。",number,biaoji));

	if(arank!=0) jj_arank=jj_arank/arank;
	if(jj_arank<100) jj_arank=100;
	if(jj_arank>300) jj_arank=300;

// 头奖奖金至少100 GOLD/人，最多300 GOLD/人。

//	if(jj_leiji<1) jj_leiji=1;

	if(brank!=0) jj_brank=jj_brank/brank;
	if(jj_brank<20) jj_brank=20;
	if(jj_brank>100) jj_brank=100;

// 二奖奖金至少20 GOLD/人，最多100 GOLD/人。

	if(arank!=0) jj_leiji-=(jj_arank*arank);
	if(brank!=0) jj_leiji-=(jj_brank*brank);

// 计算还剩余的累积奖金池金额。

/*
	if(find_player("naihe"))
		tell_object(find_player("naihe"),HIR"本期还剩累积奖金 "+jj_leiji+" 两。\n"NOR);

// 告诉本程序作者运转情况。
*/

	if(crank!=0) jj_crank=jj_crank/crank;
	if(jj_crank<1) jj_crank=1;
	
	temp_here=sprintf("%d %d %d %d  投注额：%d 中奖注数：㈠ %d ㈡ %d ㈢ %d",yeah_nba,yeah_nbb,yeah_nbc,yeah_nbd,sell_times,arank,brank,crank);
	this_object()->set(biaoji+"_"+number+"/all_number",temp_here);
	this_object()->set(biaoji+"_"+number+"/arank",jj_arank);
	this_object()->set(biaoji+"_"+number+"/brank",jj_brank);
	this_object()->set(biaoji+"_"+number+"/crank",jj_crank);
	this_object()->save();
// 这一句 save 不知道起不起作用。。。安慰自己罢。

	if(arank!=0) CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期一等奖中出%d注，每注奖金%d两黄金。",arank,jj_arank));
	else CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期一等奖无人中，奖金%d两黄金将计入下期累积奖池中。",jj_arank));

	if(brank!=0) CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期二等奖中出%d注，每注奖金%d两黄金。",brank,jj_brank));
	else CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期二等奖无人中，奖金%d两黄金将计入下期累积奖池中。",jj_brank));

	if(crank!=0) CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期三等奖中出%d注，每注奖金%d两黄金。",crank,jj_crank));
	else CHANNEL_D->do_channel(this_object(), pindao, sprintf("本期三等奖无人中，本期三等奖奖金%d两黄金落空。",jj_crank));

	if(jj_leiji<300) jj_leiji=300;
// 累积奖金保底300 GOLD。


// log 记录。 (4/4)
	log_file("caipiao/caipiao",sprintf("第%d期累积奖池共%d两。头奖%d注中，单注奖%d；二奖%d注中，%d两；三奖%d注中，%d两。\n",number,jj_leiji,arank,jj_arank,brank,jj_brank,crank,jj_crank));

	number++;
	games_now="waiting";
	arank=0;
	brank=0;
	crank=0;
	sell_times=0;
	CHANNEL_D->do_channel(this_object(), "rumor", sprintf("第%d期“%s”彩票现已开始售卖，累积奖池奖金已高达%d两黄金！\n 
	             详情请至cs e n u enter彩票售卖间 查看并请关注 "+pindao+" 频道。",number,biaoji,jj_leiji));
	call_out("caipiao_all",1);
	temp_time=wait_time /60;
	temp_time_ms1="彩票销售";
	temp_time_ms2="开奖";
	remove_call_out("now_all_time");
	call_out("now_all_time",1);
}

void random_number_1()
{
	pr_nba=1+random(max_number);
}

void random_number_2()
{
	pr_nbb=1+random(max_number);
	if(pr_nbb==pr_nba) random_number_2();
}

void random_number_3()
{
	pr_nbc=1+random(max_number);
	if(pr_nbc==pr_nba || pr_nbc==pr_nbb) random_number_3();
}

void random_number_4()
{
	pr_nbd=1+random(max_number);
	if(pr_nbd==pr_nba || pr_nbd==pr_nbb || pr_nbd==pr_nbc) random_number_4();
}

int do_chk(string arg)
{
	object me;
	int temp_number,temp_ar,temp_br,temp_cr;
	string temp_biaoji,temp_haoma;

	if(!arg)
	{
		if(number==0 || now!="start") return notify_fail("彩票游戏并未启动。\n");
		if(games_now!="waiting" && games_now!="duijiang")
			return notify_fail("现在并非 售票 或 对奖 时段。请稍后再试。\n");

		if(temp_time<=0) 
			write("本期当前共投 "+sell_times+" 注。"+temp_time_ms1+"时间已到，即将"+temp_time_ms2+"！\n");
		else 
			write("本期当前共投 "+sell_times+" 注。"+temp_time_ms1+"时间还剩 "+temp_time+" 分钟即将"+temp_time_ms2+"！\n");
		return 1;
	}

	else if(arg=="now")
	{
		if(number==0 || now!="start") return notify_fail("彩票游戏并未启动。\n");
		if(games_now!="duijiang")
			return notify_fail("本期号码还未开出，请留意 "+pindao+" 频道的公布信息。\n");

		write("本期的开奖号码是："HIR""+yeah_nba+" "+yeah_nbb+" "+yeah_nbc+" "+yeah_nbd+""NOR" ，累积奖池达 "HIR""+jj_leiji+""NOR" 两黄金（头奖4/5，二奖1/5）。\n");
		return 1;
	}

	else if(sscanf(arg, "%s %d", temp_biaoji,temp_number)!=2)
		return notify_fail("格式：<chk 类型 期号> 用于查询曾开奖的号码。\n");

	if(!this_object()->query(temp_biaoji+"_"+temp_number))
		return notify_fail("很抱歉，并没有这个资料。。。\n");

	temp_haoma = this_object()->query(temp_biaoji+"_"+temp_number+"/all_number");
	temp_ar = this_object()->query(temp_biaoji+"_"+temp_number+"/arank");
	temp_br = this_object()->query(temp_biaoji+"_"+temp_number+"/brank");
	temp_cr = this_object()->query(temp_biaoji+"_"+temp_number+"/crank");

	write(temp_biaoji+" 第"+temp_number+"期的开奖号码是："+temp_haoma+" .
一等奖奖金是"+temp_ar+"两，二等奖奖金是"+temp_br+"两，三等奖奖金是"+temp_cr+"两。\n");

	return 1;
}

int do_mai(mixed arg)
{
	object me,qian,caipiao;
	int nb1,nb2,nb3,nb4,random_times,i,num=0;
	string temp;

	me=this_player();
	qian=present("gold_money",me);
	caipiao=new(__DIR__"caipiao");

	if(now=="stop")
		return notify_fail("彩票程序已被"+wiz_id+"关闭，请稍后再试。\n");

	if(games_now=="wait_shows")
		return notify_fail("现在正准备开奖，本期已经截止出售了。\n");
	if(games_now=="showing")
		return notify_fail("现在正在开奖，本期早已经截止出售了。\n");
	if(games_now=="duijiang")
		return notify_fail("现在正在对奖登记中，请稍后时间再来投注。\n");
	if(games_now=="wait_new")
		return notify_fail("新一期售票即将开始，请稍等一会儿。\n");
	
	if(!qian) return notify_fail("没钱还买彩票？每注一两黄金，请携带黄金在身上再买。\n");
	
	if(sscanf(arg, "random %d",random_times)==1) {
		
		if((int)random_times>50)
        	return notify_fail("你一次买这么多做么，一次只能买50张彩票\n");
        	
		if((int) qian->query_amount() < random_times)
        	return notify_fail("你身上两金子,不够买"+random_times+"张彩票\n");
		for(i=0;i<random_times;i++)
                     do_mai2(me);
                     message_vision("$N买下了一些彩票。\n",me);
                       return 1;
        }
        
	if(!arg || (sscanf(arg, "%d %d %d %d", nb1,nb2,nb3,nb4)!=4 && (string)arg!="random"))
		return notify_fail("你想买什么号码（"+max_number+" 选 4）或　随机（random）？\n");

	

	if(arg=="random")
	{
		random_number_1();
		random_number_2();
		random_number_3();
		random_number_4();
	}

	else
	{
		if(nb1==nb2 || nb1==nb3 || nb1==nb4 || nb2==nb3 || nb2==nb4 || nb3==nb4)
			return notify_fail("号码不能重复。\n");

		if(nb1<1 || nb1>max_number || nb2<1 || nb2>max_number || nb3<1 || nb3>max_number || nb4<1 || nb4>max_number)
			return notify_fail("号码范围是 1-"+max_number+" ，请核对后重新输入。\n");

		pr_nba=nb1;
		pr_nbb=nb2;
		pr_nbc=nb3;
		pr_nbd=nb4;
	}

	qian->add_amount(-1);
	caipiao->set("number_info/nba",pr_nba);
	caipiao->set("number_info/nbb",pr_nbb);
	caipiao->set("number_info/nbc",pr_nbc);
	caipiao->set("number_info/nbd",pr_nbd);
	caipiao->set("number_info/biaoji_a",biaoji);
	caipiao->set("number_info/biaoji_b",wiz_id);
	caipiao->set("number_info/qihao",number);
	caipiao->set("long","这是一张 "+biaoji+" "+max_number+"选4 型彩票，上面印着： 第"+number+"期："+pr_nba+" "+pr_nbb+" "+pr_nbc+" "+pr_nbd+" 。\n");
	caipiao->move(me);
	sell_times++;
	message_vision("$N买下了一张彩票。\n",me);
	return 1;
}

int do_mai2(object me)
{
	object qian,caipiao;
	int nb1,nb2,nb3,nb4,random_times,i;
	string temp;
	caipiao=new(__DIR__"caipiao");

	//me=this_player();
	qian=present("gold_money",me);
	
	random_number_1();
	random_number_2();
	random_number_3();
	random_number_4();
	

	qian->add_amount(-1);
	caipiao->set("number_info/nba",pr_nba);
	caipiao->set("number_info/nbb",pr_nbb);
	caipiao->set("number_info/nbc",pr_nbc);
	caipiao->set("number_info/nbd",pr_nbd);
	caipiao->set("number_info/biaoji_a",biaoji);
	caipiao->set("number_info/biaoji_b",wiz_id);
	caipiao->set("number_info/qihao",number);
	caipiao->set("long","这是一张 "+biaoji+" "+max_number+"选4 型彩票，上面印着： 第"+number+"期："+pr_nba+" "+pr_nbb+" "+pr_nbc+" "+pr_nbd+" 。\n");
	caipiao->move(me);
	sell_times++;
	return 1;
}

int do_duijiang(string arg)
{

	object me,caipiao,cp_he,*inv_he;
	int temp,temp1,temp2,temp3,temp4,i,all_amount,ark_amount,brk_amount,crk_amount;
	me=this_player();
	temp=0;

	if(now!="start") return notify_fail("彩票程序已被"+wiz_id+"关闭，请稍后再试。\n");
	if(games_now!="duijiang") return notify_fail("现在还未是对奖时间，请留意谣言频道。\n");

	if(!arg) return notify_fail("你要对什么奖（请输入彩票或盒子的ID）？\n");

	caipiao=present(arg,me);
	if(!caipiao) return notify_fail("你身上没有这样东西。\n");

	if(caipiao->query("id") !="cai piao" && caipiao->query("id") !="caipiao he")
		return notify_fail("这并非彩票或者彩票盒。\n");

	if(caipiao->query("id") == "cai piao")
	{
		if(caipiao->query("number_info/qihao")!=number || caipiao->query("number_info/biaoji_a")!=biaoji || caipiao->query("number_info/biaoji_b")!=wiz_id)
			return notify_fail("你已经错过了以前的对奖时间，这张彩票已经是废票了。\n");

		if(!caipiao->query("is_bingo"))
		{

// 这里开始判断这张彩票是否中奖。
			temp1=caipiao->query("number_info/nba");
			temp2=caipiao->query("number_info/nbb");
			temp3=caipiao->query("number_info/nbc");
			temp4=caipiao->query("number_info/nbd");

			if(temp1==yeah_nba || temp1==yeah_nbb || temp1==yeah_nbc || temp1==yeah_nbd) temp++;
			if(temp2==yeah_nba || temp2==yeah_nbb || temp2==yeah_nbc || temp2==yeah_nbd) temp++;
			if(temp3==yeah_nba || temp3==yeah_nbb || temp3==yeah_nbc || temp3==yeah_nbd) temp++;
			if(temp4==yeah_nba || temp4==yeah_nbb || temp4==yeah_nbc || temp4==yeah_nbd) temp++;

			if(temp==0) temp=1;
			caipiao->set("is_bingo",temp);
			message_vision("$N小心翼翼地掏出一张彩票进行对奖。\n",me);
			switch(temp)
			{
				case 1:write("这张彩票的号码是： "+temp1+" "+temp2+" "+temp3+" "+temp4+" ，无奖。\n");
				caipiao->set("long",caipiao->query("long")+"此票无奖。\n");
				break;
				case 4:write("这张彩票的号码是： "+temp1+" "+temp2+" "+temp3+" "+temp4+" ，恭喜你中得一等奖！\n");
				caipiao->set("long",caipiao->query("long")+"此票中得一等奖。\n");
				arank++;
				break;
				case 3:write("这张彩票的号码是： "+temp1+" "+temp2+" "+temp3+" "+temp4+" ，恭喜你中得二等奖！\n");
				caipiao->set("long",caipiao->query("long")+"此票中得二等奖。\n");
				brank++;
				break;
				case 2:write("这张彩票的号码是： "+temp1+" "+temp2+" "+temp3+" "+temp4+" ，恭喜你中得三等奖！\n");
				caipiao->set("long",caipiao->query("long")+"此票中得三等奖。\n");
				crank++;
				break;
			}
			return 1;
		}
		tell_object(me,"这张彩票已经登记过了，再对多少次结果都一样的。\n");
		return 1;
	}

	cp_he=caipiao;
	inv_he = all_inventory(cp_he);
	if(!inv_he || sizeof(inv_he) <1)
		return notify_fail("这里面并没有彩票。\n");

	message_vision("$N小心翼翼地掏出一个彩票盒，把彩票们进行对奖。\n",me);

	for(i=0;i<sizeof(inv_he);i++)
	{
		if( inv_he[i] ->query("id") != "cai piao" ||
		    inv_he[i] ->query("number_info/qihao")!=number ||
		    inv_he[i] ->query("number_info/biaoji_a")!=biaoji ||
		    inv_he[i] ->query("number_info/biaoji_b")!=wiz_id ||
		    inv_he[i] ->query("is_bingo") )
			continue;

		temp=0;
		temp1=inv_he[i]->query("number_info/nba");
		temp2=inv_he[i]->query("number_info/nbb");
		temp3=inv_he[i]->query("number_info/nbc");
		temp4=inv_he[i]->query("number_info/nbd");
	if(temp1==yeah_nba || temp1==yeah_nbb || temp1==yeah_nbc || temp1==yeah_nbd) temp++;
	if(temp2==yeah_nba || temp2==yeah_nbb || temp2==yeah_nbc || temp2==yeah_nbd) temp++;
	if(temp3==yeah_nba || temp3==yeah_nbb || temp3==yeah_nbc || temp3==yeah_nbd) temp++;
	if(temp4==yeah_nba || temp4==yeah_nbb || temp4==yeah_nbc || temp4==yeah_nbd) temp++;

		if(temp==0) temp=1;
		inv_he[i]->set("is_bingo",temp);

		if(temp == 1) inv_he[i]->set("long",inv_he[i]->query("long")+"此票无奖。\n");
		if(temp == 4)
		{
			inv_he[i]->set("long",inv_he[i]->query("long")+"此票中得一等奖。\n");
			arank++;ark_amount++;
		}
		if(temp == 3)
		{
			inv_he[i]->set("long",inv_he[i]->query("long")+"此票中得二等奖。\n");
			brank++;brk_amount++;
		}
		if(temp == 2)
		{
			inv_he[i]->set("long",inv_he[i]->query("long")+"此票中得三等奖。\n");
			crank++;crk_amount++;
		}
		all_amount++;
	}
	write("共登记有效彩票 "+all_amount+" 张。\n其中一等奖 "+ark_amount+" 张，二等奖 "+brk_amount+" 张，三等奖 "+crk_amount+" 张。\n");
	return 1;
}

int do_lingjiang(string arg)
{
	object me,caipiao,qian,temp_qian;
	int temp_qihao,temp_arank,temp_brank,temp_crank,this_game_gxd;

// this_game_gxd,本游戏推广期间，奖品里有额外的“神州贡献度”奖励。

	me=this_player();
	qian=new("/clone/money/gold");
	temp_qian=present("gold_money",me);
	this_game_gxd=0;
		
	if(now!="start") return notify_fail("彩票程序已被"+wiz_id+"关闭，请稍后再试。\n");

	if(!arg) return notify_fail("你要领什么奖（请输入彩票的ID）？\n");
	
	caipiao=present(arg,me);
	//if(caipiao->query("id") !="cai piao" && caipiao->query("id") !="caipiao he")
	//return notify_fail("这并非彩票或者彩票盒。\n");
	
	if(!caipiao) return notify_fail("你身上没有这样东西。\n");
	
	if(caipiao->query("id") == "cai piao")
	{
		if(!caipiao->query("is_bingo"))	return notify_fail("这张彩票并未登记对奖，无法领奖。\n");
	
		if(caipiao->query("number_info/qihao")==number && games_now!="wait_new")
		return notify_fail("当前这一期的统计数据还未公布，无法领奖。\n");
		if((int)caipiao->query("is_bingo")<2)
		{
		write("这张彩票无奖。\n");
		destruct(caipiao);
		return 1;
		}

		temp_qihao=(int)caipiao->query("number_info/qihao");
		temp_arank=this_object()->query(biaoji+"_"+temp_qihao+"/arank");
		temp_brank=this_object()->query(biaoji+"_"+temp_qihao+"/brank");
		temp_crank=this_object()->query(biaoji+"_"+temp_qihao+"/crank");

		message_vision("$N满脸喜悦地掏出一张彩票，看来是中了奖了。\n",me);
		switch(caipiao->query("is_bingo"))
		{
		case 4:
		message_vision("$N的这张彩票中的是第"+temp_qihao+"期“"+caipiao->query("number_info/biaoji_a")+"”的头奖！\n",me);
		qian->set_amount(temp_arank);

		this_game_gxd=50;
		// 游戏推广期间一等奖额外的奖励，初期定义为50点贡献度，要测试是否合理。


		// 以下判断为了防止人物负重过大无法收取奖金。头奖。

		if((me->query_encumbrance()+(qian->weight()))>me->query_max_encumbrance())
		{
			qian->move(environment(me));
			message_vision("$N上打开了一个小口子，哗啦啦地吐出了一大堆黄金。\n",this_object());
		}
		else
		{
			if(!temp_qian) qian->move(me);
			else temp_qian->add_amount(temp_arank);
			message_vision("$N接过奖金，笑得嘴都合不拢了。\n",me);
		}
		destruct(caipiao);
		break;

		case 3:
		message_vision("$N的这张彩票中的是第"+temp_qihao+"期“"+caipiao->query("number_info/biaoji_a")+"”的二等奖！\n",me);
		qian->set_amount(temp_brank);

		this_game_gxd=10;
		// 游戏推广期间二等奖额外的奖励，初期定义为5点贡献度，要测试是否合理。


		// 以下判断为了防止人物负重过大无法收取奖金。二奖。
		if((me->query_encumbrance()+(qian->weight()))>me->query_max_encumbrance())
		{
			qian->move(environment(me));
			message_vision("$N上打开了一个小口子，哗啦啦地吐出了一些黄金。\n",this_object());
		}
		else
		{
			if(!temp_qian) qian->move(me);
			else temp_qian->add_amount(temp_brank);
			message_vision("$N接过奖金，脸上笑意更浓了。\n",me);
		}
		destruct(caipiao);
		break;

		case 2:
		message_vision("$N的这张彩票中的是第"+temp_qihao+"期“"+caipiao->query("number_info/biaoji_a")+"”的三等奖！\n",me);
		qian->set_amount(temp_crank);
		this_game_gxd=1;

		// 以下判断为了防止人物负重过大无法收取奖金。三奖。

		if((me->query_encumbrance()+(qian->weight()))>me->query_max_encumbrance())
		{
			qian->move(environment(me));
			message_vision("$N上打开了一个小口子，哗啦啦地吐出了些许黄金。\n",this_object());
		}
		else
		{
			if(!temp_qian) qian->move(me);
			else temp_qian->add_amount(temp_crank);
			message_vision("$N微笑着接过了奖金。\n",me);
		}
		destruct(caipiao);
		break;
		}

		if(this_game_gxd!=0)
		{
		me->add("meng/pts", this_game_gxd);
		log_file("awards/gxadd","\n"+me->query("name")+"("+me->query("id")+")于"+ctime(time())+"在彩票游戏(/clone/misc/naihe/obj/bingo.c)里中得奖项，\n获得游戏推广期间额外的奖励 "+this_game_gxd+"点神州贡献度。\n");
		message_vision("$N获得了本游戏推广期间额外的奖励，贡献度"+this_game_gxd+"点！\n",me);
		}
	}
	return 1;
}
