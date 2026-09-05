// zhuangjia. 赌场庄家
#include <ansi.h>
inherit NPC;
inherit F_SAVE;

void restore_default(object ob, mapping dbase);
protected int chn_check(string msg, int maxlen);
protected string show_bet(string msg, int type);
protected string show_odds(string bet_id);
protected string show_time(int time);
protected void modify_odds(string odds, object me, string bet_id, string *odds_list, int serial);
protected void save_deposit(string deposit, object me, string bet_id, string *odds_list, int serial);
protected int wager_golds(object me, string bet_id, string odds_id, int golds);
protected int wager_gem(object me, string bet_id, string odds_id, int gem);
protected void autochg_status(string bet_id);
protected void clear_bet();

//赌局信息记录
//主键是赌局编号，赌局编号由a-z和0-9组成的不超过8位的编码。
//包含内容：name（赌局标题）、desc（赌局描述）、dealer（庄家）、wagerTime（投注截至时间）、createTime（赌局创建时间）、
//          odds（赔率信息，mapping结构）、winOdds（获胜的赔率ID）、endTime（赌局截至时间，一般是获胜赔率公布之后顺延7天）、
//          status（状态：0-初始化、1-接受投注、2-投注截至、3-公布结果、4-赌局结束，庄家领取收益（庄家收益包括之前保证金、
//          投注各赔率未赔尽资金、赌局结束后玩家未领走资金）、5-赌局强制终止、6-系统强行关闭）、wagerType（投注类型：0-仅接受金条、
//          1-仅接受宝石、2-接受金条和宝石）、startTime（投注开始时间）、wagerDays（投注天数，1-7天）、
//          taxes（抽水比例，数字表示N:1，比如10：1，20：1，50：1，比率由赌局大小决定，赌局越大抽水越低）、
//          total_golds（总金条数）、total_gem（总宝石数）、dealer_golds（庄家总押金）、dealer_gem（庄家总宝石数）、
//          max_golds（投注金条限制，0不限制）、max_gem（投注宝石限制，0不限制）
//          dwin_golds(庄家获利黄金）、dwin_gem（庄家获利宝石）
//odds（赔率信息）也是一个mapping结构，主键是赔率的id，
//内容包括：name（赔率标题）、desc（赔率描述）、odds（赔率值，两个数字组成，表示1：3，3：1之类的赔率）、
//          wagers（投注信息，mapping结构）、total_golds（总金条数）、total_gem（总宝石数）、dealer_golds（庄家押金）、
//          dealer_gems（庄家宝石）
//wagers（投注信息）也是一个mapping结构，主键是玩家userid，
//内容主要是表名wager(财物的mapping，其中golds表示为金条，其他都是宝石id）、wagerTime(投注时间)、addTime(加注时间)、
//status（状态：0-已投注，1-可以领取奖励， 2-投注被赔付， 3-已领走奖励）、userType（玩家类型：0-玩家、1-庄家）、
//win_golds（盈利的金条）、win_gems（盈利的宝石）、gems（投注的宝石折算雷月数）
mapping bet_info;
nosave string find_arg;

void create()
{
	set_name("轩辕三光", ({ "xuanyuan sanguang", "xuanyuan" }));
	set("str", 35);
	set("title", HIW"恶赌鬼"NOR);
	set("gender", "男性");
	set("age", 35);
	set("long", "他是著名的恶赌鬼轩辕三光，只要你敢赌，他什么样的赌局都敢开。\n");
  set("qi", 1500);
  set("max_qi", 1500);
  set("jing", 1200);
  set("max_jing", 1200);
  set("neili", 800);
  set("max_neili", 800);
  set("jiali", 50);

  set("combat_exp", 80000);
  set("score", 1000);
    
  set_skill("literate",200);
  set_skill("force", 80);
  set_skill("dodge", 80);
  set_skill("parry", 70);
  set_skill("hand",70);
  set_skill("strike", 80);
  set_skill("sword",60);

  set_skill("changhen-jian",70);
  set_skill("zhemei-shou",60);
  set_skill("liuyang-zhang",70);
  set_skill("yueying-wubu",60);
  set_skill("bahuang-gong", 70);

  map_skill("force", "bahuang-gong");
  map_skill("strike","liuyang-zhang");
  map_skill("dodge", "yueying-wubu");
  map_skill("hand", "zhemei-shou");
  map_skill("parry", "liuyang-zhang");
  map_skill("sword", "changhen-jian");

  prepare_skill("strike","liuyang-zhang");
  prepare_skill("hand","zhemei-shou");

	set("attitude", "friendly");

	set("shen_type",1);
	set("score",200);

  set("inquiry", ([
    "赌局" : "只有非常具有声誉的人士才能到我这里开立赌局(bet)，其他人可以查询(find)\n现在可以投注的赌局，选择合适的赔率进行投注(wager)。\n",
    "庄家" : "庄家必须是巫师、新手导师或者富豪，开立的赌局只接受金条或者宝石，赌局公\n布结果后一周内未领取的财物自动归庄家所有。\n",
    "投注" : "玩家可以选择庄家开设的赌局中选择其中一个赔率进行投注，直到庄家保证金不足以支付可\n能赔付的金额的时候才会停止接收投注。\n",
    "保证金" : "庄家开设赌局要投入保证金到自己开立的各个赔率中作为赔付玩家的资本金，当然庄\n家可以通过不断调整赔率来获得合适的收益。\n",
    "赔率" : "庄家开立的赌局可以对多种胜负关系设置不同的赔率，赔付的\n财物来源于同一赌局其他赔率赔付的金额和庄家的保证金。也就是说同一赌局不\n同赔率之间都是对立的，一个赌局不能同时拥有两个或者两个以上获胜的赔率。"
  ]) );

	setup();
	restore();
	restore_default(this_object(), base_name(this_object())->query_entire_dbase());
  carry_object("/d/lingjiu/obj/changpao")->wear();
  carry_object("/clone/weapon/jian")->wield();
}

void init()
{
	add_action("do_bet","bet");
	add_action("do_find","find");
	add_action("do_wager", "wager");
	add_action("do_win", "win");
}

string query_save_file()
{
  return "/data/business/bet_changan";
}

//用默认的dbase信息更新ob中dbase信息，将其恢复到默认配置
void restore_default(object ob, mapping dbase)
{
	string *klist=keys(dbase);
	int lp;
	
	for(lp=0;lp<sizeof(klist);lp++)
	  ob->set(klist[lp], dbase[klist[lp]]);
}

//非玩家或者top rich人士才有资格作赌局的庄家。
//bet命令具有以下几种模式：
//open 赌局ID 开启赌局
//modify 赌局ID 维护赌局，可以修改描述性内容
//odds 赌局ID 修改赔率
//add 赌局ID 增加赔率类型
//start 赌局ID 开放投注，同时庄家在各个赔率投入保证金。
//close 赌局ID 关闭赌局，在赌局投注截至时间到达前，庄家可以强制关闭赌局，关闭以后玩家可以取回自己的财物。
int do_bet(string arg)
{
	object me=this_player();
	string status, betType, betId;
	mapping *top_rich;
	int lp, rich,odds;
	
	status = SECURITY_D->get_status(me);
	top_rich = TOPTEN_D->query_topten("rich");
	rich=0;
	
	if ( top_rich ) 
	{
	  for(lp=0;lp<sizeof(top_rich);lp++)
    {
	    if ( top_rich[lp]["id"]==me->query("id") )
	    {
	  	  rich=1;
	  	  break;
	    }
	  }
	}
		
	if ( !arg || 
		   sscanf(arg, "%s %s", betType, betId)!=2 )
	{
	  tell_object(me, @ERROR
命令格式：bet {open|modify|odds|add|start|close} 赌局唯一ID
    bet open     创建赌局
    bet modify   修改赌局描述
    bet odds     修改赔率
    bet add      增加赔率ID
    bet start    开放投注并且投入初始保证金
    bet close    强行关闭赌局
ERROR);
	  return 1;
	}

	if ( !bet_info )
		bet_info=([]);
	
	if ( !betId || !stringp(betId) )
	{
		write("赌局ID不能为空。\n");
		return 1;
	}
	
	for ( lp=0;lp<strwidth(betId);lp++ )
	{
		if ( (betId[lp]>='a' && betId[lp]<='z') ||
			   (betId[lp]>='0' && betId[lp]<='9') ||
			   (betId[lp]>='A' && betId[lp]<='Z') )
	  	continue;
  	write("赌局ID仅为a-zA-Z0-9等字母组成。\n");
  	return 1;
	}
	
	if ( strwidth(betId) > 10 )
	{
		write("赌局ID长度最长不能超过10。\n");
  	return 1;
	}

	if ( !wizardp(me) && status=="(player)" && !rich &&
		   !(me->query("combat_exp")>=100000000&&
		     me->query("advance_balance")>=1000) )
	{
	  message_vision("仅巫师、新手导师、富豪排行榜、100m以上1000根金条以上等四种资质的人士才有资格进行和开启/维护/关闭赌局相关的操作。\n", me);
	  return 1;
	}
	
  switch(betType)
  {
  	case "open":
  	  if ( member_array(betId, keys(bet_info) )>=0 )
	    {
		    write("该赌局ID已经在使用，无法用在新开局赌局中。\n");
		    return 1;
	    }
	    bet_info[betId]=([]);
	    bet_info[betId]["dealer"]=me->query("id");
	    bet_info[betId]["dealer_name"]=me->query("name");
	    bet_info[betId]["createTime"]=time();
	    bet_info[betId]["taxes"]=10;  //初始的抽水比例，初始的抽水比例总是10：1，随着后来投注的人越来越多，抽水比例越来越低。
	    bet_info[betId]["status"]=-1; //初始的时候赌局是初始化，只有庄家决定开放以后才会开放赌局。
	    tell_object(me, "请输入赌局标题（最多10个汉字）：\n");
	    input_to("openbet_input", me, betId, "name");
	    break;
  	case "modify":
  		if ( member_array(betId, keys(bet_info) )<0 )
	    {
		    write("该赌局并没有开局，无法进行信息维护操作。\n");
		    return 1;
	    }
	    
	    if ( bet_info[betId]["dealer"]!=me->query("id") )
	    {
	    	write("只有庄家才能进行本赌局的信息维护操作。\n");
	    	return 1;
	    }
	    
	    if ( bet_info[betId]["status"]<0 )
	    {
	    	write("未知的赌局状态，只能进行关闭赌局操作。\n");
	    	return 1;
	    }
	    
	    show_bet(betId,0);
	    tell_object(me, "你可以维护的信息有赌局名称（name），赌局描述（desc），赔率名称（赔率ID name），赔率描述（赔率ID desc），\n请输入你要维护的信息类型：\n");
	    input_to("modify_bet", me, betId, 0, 0);
	    break;
	  case "odds":
  		if ( member_array(betId, keys(bet_info) )<0 )
	    {
		    write("该赌局并没有开局，无法进行维护赔率操作。\n");
		    return 1;
	    }
	    
	    if ( bet_info[betId]["dealer"]!=me->query("id") )
	    {
	    	write("只有庄家才能进行本赌局的维护赔率操作。\n");
	    	return 1;
	    }
	    
	    if ( bet_info[betId]["status"]<0 )
	    {
	    	write("未知的赌局状态，只能进行关闭赌局操作。\n");
	    	return 1;
	    }

	    if ( bet_info[betId]["status"]>1 )
	    {
	    	write("在关闭投注以后禁止修改赔率。\n");
	    	return 1;
	    }
	    
	    show_bet(betId,0);
	    modify_odds(0, me, betId, keys(bet_info[betId]["odds"]), -1 );
	    break;
	  case "add":
  		if ( member_array(betId, keys(bet_info) )<0 )
	    {
		    write("该赌局并没有开局，无法进行增加赔率类型操作。\n");
		    return 1;
	    }
	    
	    if ( bet_info[betId]["dealer"]!=me->query("id") )
	    {
	    	write("只有庄家才能进行本赌局的增加赔率类型操作。\n");
	    	return 1;
	    }
	    
	    if ( bet_info[betId]["status"]>0 )
	    {
	    	write("该赌局只有处于初始化未开放投注的状态下才能进行增加赔率类型操作。\n");
	    	return 1;
	    }
	    
	    if ( bet_info[betId]["status"]<0 )
	    {
	    	write("未知的赌局状态，只能进行关闭赌局操作。\n");
	    	return 1;
	    }
	    
	    show_bet(betId,0);
	    odds=sizeof(bet_info[betId]["odds"]);
	  	tell_object(me, "请输入第"+chinese_number(odds+1)+"个赔率的赔率ID（a-zA-Z0-9组成的字符串）：\n");
	  	input_to("odds_init", me, betId, 0, odds+1, "oddsid");
	    break;
	  case "start":
  		if ( member_array(betId, keys(bet_info) )<0 )
	    {
		    write("该赌局并没有开局，无法进行开放投注操作。\n");
		    return 1;
	    }
	    
	    if ( bet_info[betId]["dealer"]!=me->query("id") )
	    {
	    	write("只有庄家才能开启本赌局的投注。\n");
	    	return 1;
	    }
	    
	    autochg_status(betId);
	    
	    if ( bet_info[betId]["status"]>1 )
	    {
	    	if ( !bet_info[betId]["status"] )
	    	  write("该赌局只有处于初始化未开放投注的状态下才能进行开放投注动作。\n");
	    	else
	    		write("该赌局只有处于接受投注的状态下才能进行修改押金动作。\n");
	    	return 1;
	    }
	    
	    if ( bet_info[betId]["status"]<0 )
	    {
	    	write("未知的赌局状态，只能进行关闭赌局操作。\n");
	    	return 1;
	    }
	    
	    show_bet(betId,0);
	    save_deposit(0, me, betId, keys(bet_info[betId]["odds"]), -1 );
	    break;
  	case "close":
  		if ( member_array(betId, keys(bet_info) )<0 )
	    {
		    write("该赌局并没有开局，无法进行维护或者关闭操作。\n");
		    return 1;
	    }
	    
	    if ( bet_info[betId]["dealer"]!=me->query("id") )
	    {
	    	write("只有庄家才能强行关闭本赌局。\n");
	    	return 1;
	    }
	    
      autochg_status(betId);
	    
	    if ( bet_info[betId]["status"]>1 )
	    {
    		write("该赌局只有处于初始化或者接受投注的状态下才能强行关闭该赌局。\n");
	    	return 1;
	    }
	    
	    if ( bet_info[betId]["status"]!=1 &&
	    	   !bet_info[betId]["dealer_golds"] &&
	    	   !bet_info[betId]["dealer_gem"] )
	    {
	    	tell_object(me, "该赌局已经强行关闭，请取回押金。\n");
	      CHANNEL_D->do_channel(this_object(), "jy", "赌局『"+bet_info[betId]["name"]+"("+betId+")』已经被庄家"+me->query("name")+"("+me->query("id")+")强行关闭。");
	    	map_delete(bet_info, betId);
	      save();
	    }
	    else
	    {
	      bet_info[betId]["status"]=5;
	      bet_info[betId]["endTime"]=time();
	      tell_object(me, "该赌局已经强行关闭，请取回押金。\n");
	      CHANNEL_D->do_channel(this_object(), "jy", "赌局『"+bet_info[betId]["name"]+"("+betId+")』已经被庄家"+me->query("name")+"("+me->query("id")+")强行关闭，请各位玩家领回押金。");
        show_bet(betId,0);
	      save();
	    }
	    break;
  	default:
  	  write("命令格式：bet {open|modify|close} 赌局唯一ID");
	    return 1;
  }
	return 1;
}

//显示赌局列表
//没有参数显示所有赌局，-w 显示可以接受投注的赌局，-e 显示关闭投注的赌局，-s 显示已经公布结果的赌局
//-o 显示处于各种关闭状态的赌局
int do_find(string arg)
{
	object me=this_player();
	string *sst=({"初始化  ","接受投注","投注截至","结果公布","赌局关闭","强行终止","系统强行关闭"}), *betk;
	string user;
	int lp;
	
	find_arg=arg;
	if ( !bet_info )
		bet_info=([]);
	betk=keys(bet_info);

	if ( strwidth(arg)>0 &&
		   arg!="-w" &&
		   arg!="-e" &&
		   arg!="-s" &&
		   arg!="-o" &&
		   !sscanf(arg,"-u %s", user) )
	{
		tell_object(me, @ERROR
查询赌局列表命令：find [-w|-e|-s|-o]，各种输入参数含义如下：
未加参数表示显示所有赌局，
-w 显示处于开放投注状态的赌局，
-e 显示处于投注截至状态的赌局，
-s 显示处于结果公布状态的赌局，
-o 显示处于各种关闭状态的赌局。
-u userid 显示该庄家的赌局。
ERROR);
    return 1;
  }
  
  if ( user )
  	arg="-u";
  
//首先清理赌局结束超过30天以上的所有赌局。	
	clear_bet();
	tell_object(me, "###############################################################################################\n");
	tell_object(me, "赌局ID     赌局名称             赌局状态 投注截至时间        赌局关闭时间      庄家            \n");
	tell_object(me, "###############################################################################################\n");
	for(lp=0;lp<sizeof(betk);lp++)
	{
		if ( arg=="-w" && 
			   bet_info[betk[lp]]["status"]!=1 )
		  continue;
		
		if ( arg=="-e" && 
			   bet_info[betk[lp]]["status"]!=2 )
		  continue;
		  
		if ( arg=="-s" && 
			   bet_info[betk[lp]]["status"]!=3 )
		  continue;
		  
		if ( arg=="-o" && 
			   bet_info[betk[lp]]["status"]<=3 )
		  continue;
		
		if ( arg=="-u" &&
			   bet_info[betk[lp]]["dealer"]!=user )
			continue;
		
		tell_object(me, sprintf("%-10s %-20s %-8s %-19s %-19s %s\n",
		  betk[lp], bet_info[betk[lp]]["name"], bet_info[betk[lp]]["status"]<0?"未知赌局":sst[bet_info[betk[lp]]["status"]], 
		  show_time(bet_info[betk[lp]]["wagerTime"]), show_time(bet_info[betk[lp]]["endTime"]), bet_info[betk[lp]]["dealer_name"] ) );
	}
	
	tell_object(me, "###############################################################################################\n");
	tell_object(me, "显示赌局详细信息请用命令"HIY"b 赌局编号"NOR"，其他输入退出赌局查询命令。\n");
	tell_object(me, "###############################################################################################\n");
	input_to("show_bet",0,1);
	
	return 1;
}

//庄家公布赌局结果，同时计算获胜赌局各方的获利情况。
int do_win(string arg)
{
	object me=this_player();
	string bet_id, odds_id, *ulist;
	mapping odds_info, wager_info;
	int wgolds, wgem, ugolds, ugem, uodds, dodds, lp;
	
	if ( !arg ||
		   sscanf(arg,"%s %s", bet_id, odds_id)!=2 )
	{
		write("命令格式：win 赌局ID 赔率ID，宣布哪个赔率获胜。\n");
		return 1;
	}
	
  if ( member_array(bet_id, keys(bet_info) )<0 )
	{
	  write("该赌局并没有开局。\n");
	  return 1;
	}
	
	if ( me->query("id")!=bet_info[bet_id]["dealer"] )
	{
		write("只有庄家才有权限宣布赌局获胜结果。\n");
		return 1;
	}
	
	if ( bet_info[bet_id]["status"]!=2 )
	{
		write("只有赌局关闭投注以后才能公布获胜结果。\n");
		return 1;
	}
	
	odds_info=bet_info[bet_id]["odds"];
	if ( member_array(odds_id, keys(odds_info)) < 0 )
	{
		write("似乎赌局中吧不存在该赔率。\n");
		return 1;
	}

	if ( sscanf(bet_info[bet_id]["odds"][odds_id]["odds"], "%d:%d", dodds, uodds)!=2 )
	{
		write("该获胜赔率的赔率值设置有问题，无法进行下一步处理。\n");
		return 1;
	}
		
	bet_info[bet_id]["endTime"]=time()+7*24*3600;//赌局关闭时间是公布结果之后顺延7天
	bet_info[bet_id]["status"]=3;
	bet_info[bet_id]["winOdds"]=odds_id;
	wgolds=bet_info[bet_id]["total_golds"]-odds_info[odds_id]["total_golds"]+
	       bet_info[bet_id]["dealer_golds"]-odds_info[odds_id]["dealer_golds"];
	wgem=bet_info[bet_id]["total_gem"]-odds_info[odds_id]["total_gem"]+
	     bet_info[bet_id]["dealer_gem"]-odds_info[odds_id]["dealer_gem"];
	wgolds=wgolds*100;
	wgem=wgem*9;
	ugolds=odds_info[odds_id]["total_golds"]*100*uodds/dodds; //计算玩家获利的时候金额放大100倍
	ugem=odds_info[odds_id]["total_gem"]*9*uodds/dodds;       //计算玩家获利的时候宝石放大到水月
	if ( ugolds>wgolds )
	{
		ugolds=wgolds;
	  wgolds=0;
	}
	else
	  wgolds=wgolds-ugolds;                                   //计算庄家获利的金额
	
	if ( ugem>wgem )
	{
		ugem=wgem;
		wgem=0;
	}
	else
	  wgem=wgem-ugem;                                         //计算庄家获利的宝石
  
  wager_info=odds_info[odds_id]["wagers"];
  bet_info[bet_id]["dwin_golds"]=wgolds;
  bet_info[bet_id]["dwin_gem"]=wgem;
  ulist=keys(wager_info);
//  printf("wgolds:%d wgem %d ugolds %d ugem %d odds %d:%d\n",wgolds, wgem, ugolds, ugem, dodds, uodds);
  for(lp=0;lp<sizeof(ulist);lp++)
  {
  	if ( wager_info[ulist[lp]]["userType"] )
  	{
  		wager_info[ulist[lp]]["win_golds"]=wgolds;
  		wager_info[ulist[lp]]["win_gems"]=wgem;
  		wager_info[ulist[lp]]["status"]=1;
  		continue;
  	}
  	
  	if ( wager_info[ulist[lp]]["wager"]["golds"]*100*uodds/dodds<=ugolds ) 
  	{
  	  wager_info[ulist[lp]]["win_golds"]=wager_info[ulist[lp]]["wager"]["golds"]*100*uodds/dodds;
  	  ugolds-=wager_info[ulist[lp]]["wager"]["golds"]*100*uodds/dodds;
  	}
  	else
  	{
  		wager_info[ulist[lp]]["win_golds"]=ugolds;
  		ugolds=0;
  	}
  	
  	if ( wager_info[ulist[lp]]["gems"]*9*uodds/dodds<=ugem ) 
  	{
  	  wager_info[ulist[lp]]["win_gems"]=wager_info[ulist[lp]]["gems"]*9*uodds/dodds;
  	  ugem-=wager_info[ulist[lp]]["gems"]*9*uodds/dodds;
  	}
  	else
  	{
  		wager_info[ulist[lp]]["win_gems"]=ugem;
  		ugem=0;
  	}
  	
  	wager_info[ulist[lp]]["status"]=1;
  }
  
  if ( ugolds>0 )
  	wager_info[ulist[0]]["win_golds"]+=ugolds;
  	
  if ( ugem>0 )
  	wager_info[ulist[0]]["win_gems"]+=ugem;
  
  CHANNEL_D->do_channel(this_object(), "jy", 
  "赌局『"+bet_info[bet_id]["name"]+"("+bet_id+")』已经公布获利赔率，获利赔率是"+odds_info[odds_id]["name"]+"("+odds_id+")"+"。");
  CHANNEL_D->do_channel(this_object(), "jy", "请投注该赔率的玩家尽快过来领取奖励。");
  return 1;
}

//庄家或者玩家领取奖励，庄家可以领取两次奖励，第一次是领取自己剩余的保证金，第二次是赌局结束以后领取玩家未领走的收益
int do_wager(string arg)
{
	string bet_id, *olist, *ulist, *wlist, uid, material;
	object me=this_player(), gem;
	mapping odds_info, wager_info, src_wager;
	int p1, p2, p3, wgolds, wgem, tgolds, tgem, taxes, yang, yin;
	int bufg,bufl,level;
	
	if ( !arg )
	{
		write("命令格式：wager 赌局ID，领取赌局收益。\n");
		return 1;
	}
	
	bet_id=arg;
	uid=me->query("id");
	if ( member_array(bet_id, keys(bet_info))<0 )
	{
		write("输入的赌局ID并不存在。\n");
		return 1;
	}
	
	if ( bet_info[bet_id]["status"]!=3 &&
		   bet_info[bet_id]["status"]!=5 &&
		   bet_info[bet_id]["status"]!=6 &&
		   bet_info[bet_id]["dealer"]!=uid )
  {
  	write("玩家只有在赌局处于公布结果、强行终止、系统强行关闭等阶段才能领取收益和保证金。\n");
  	return 1;
  }
  
  if ( bet_info[bet_id]["status"]!=4 &&
  	   bet_info[bet_id]["status"]!=5 &&
  	   bet_info[bet_id]["dealer"]==uid )
  {
  	write("庄家只有在赌局处于赌局关闭、强行终止等阶段才能领取收益和保证金。\n");
  	return 1;
  }
  
  wgolds=0;
  wgem=0;
  yang=0;
  yin=0;
  src_wager=([]);
  if ( bet_info[bet_id]["status"]==5 ||
  	   bet_info[bet_id]["status"]==6 )
  {
  	olist=keys(bet_info[bet_id]["odds"]);
  	for(p1=0;p1<sizeof(olist);p1++)
  	{
  		odds_info=bet_info[bet_id]["odds"][olist[p1]];
  		if ( !odds_info["wagers"] ||
  			   !odds_info["wagers"][uid] )
    	  continue;

 			wager_info=odds_info["wagers"][uid];
 			if ( wager_info["status"]!=1 &&
			  bet_info[bet_id]["status"]==6 )
    		continue;

  		if ( wager_info["status"]==3 )
  			continue;
  			
  		wlist=keys(wager_info["wager"]);
  		for(p3=0;p3<sizeof(wlist);p3++)
  			src_wager[wlist[p3]]+=wager_info["wager"][wlist[p3]];
  			
  		if ( bet_info[bet_id]["status"]==6 )
  		{
  			src_wager["win_golds"]+=wager_info["win_golds"];
  			src_wager["win_gems"]+=wager_info["win_gems"];
  		}
  		yang+=wager_info["gems_yang"];
  		yin+=wager_info["gems_yin"];
  		wager_info["status"]=3;
  	}
  }
  
  if ( bet_info[bet_id]["status"]==3 || 
  	   bet_info[bet_id]["status"]==4 )
  {
  	odds_info=bet_info[bet_id]["odds"][bet_info[bet_id]["winOdds"]];
  	ulist=keys(odds_info["wagers"]);
  	for ( p2=0;p2<sizeof(ulist);p2++)
  	{
  		if ( uid!=ulist[p2] &&
  			   bet_info[bet_id]["status"]==3 )
  		  continue;
  		
		  wager_info=odds_info["wagers"][ulist[p2]];
  	  if ( wager_info["status"]!=1 )
  		  continue;
  			
  	  wlist=keys(wager_info["wager"]);
  	  for(p3=0;p3<sizeof(wlist);p3++)
  		  src_wager[wlist[p3]]+=wager_info["wager"][wlist[p3]];
  			
 		  src_wager["win_golds"]+=wager_info["win_golds"];
 		  src_wager["win_gems"]+=wager_info["win_gems"];
  		yang+=wager_info["gems_yang"];
  		yin+=wager_info["gems_yin"];
  	  wager_info["status"]=3;
  	}
  }
    
  save();
  
  taxes=bet_info[bet_id]["taxes"];
  if ( taxes < 10 )
  	taxes=10;
  
  if ( taxes > 50 )
  	taxes=50;		

//庄家不会被抽走收益  
  if ( bet_info[bet_id]["dealer"]!=uid )
  {
    tgolds=src_wager["win_golds"]/taxes;
    tgem=src_wager["win_gems"]/taxes;
    src_wager["win_golds"]-=tgolds;
    src_wager["win_gems"]-=tgem;
  
    if ( tgolds > 0 )
      CHANNEL_D->do_channel(this_object(), "jy", me->query("name")+"领取赌局本金和收益中被赌场抽走了"+chinese_number(tgolds)+"两黄金。");
  
    if ( tgem > 0 )
  	  CHANNEL_D->do_channel(this_object(), "jy", me->query("name")+"领取赌局本金和收益中被赌场抽走了相当于"+chinese_number(tgem)+"颗水月的宝石。");
  }
  
  if ( src_wager["win_golds"]>0 )
  {
  	src_wager["golds"]+=src_wager["win_golds"]/100;
  	src_wager["win_golds"]=src_wager["win_golds"]%100;
  }
  
  if ( src_wager["win_gems"]>0 )
  {
  	if ( yang > yin )
  	{
  		bufg=src_wager["win_gems"];
  		bufl=3;

  		if ( (bufg%3) > 0 )
  		{
  		  src_wager["yue_3"]+=bufg%3;
  		  bufg=bufg/3;
  		}

  		for(p1=0;p1<8;p1++)
  		{
  			if ( (bufg%3) > 0 )
  		    src_wager[sprintf("ri_%d",bufl)]+=bufg%3;
  		  
  		  bufg=bufg/3;
  		  bufl++;
  		  
  		  if ( bufl==8 ||
  		  	   bufg< 3 )
  		  {
  		  	src_wager[sprintf("ri_%d",bufl)]+=bufg;
  		  	break;
  		  }
  		}
  	}
  	else
  	{
  		bufg=src_wager["win_gems"];
  		bufl=3;
  		for(p1=0;p1<8;p1++)
  		{
  			if ( (bufg%3) > 0 )
  		    src_wager[sprintf("yue_%d",bufl)]+=bufg%3;

 		    bufg=bufg/3;
 		    bufl++;
  		  
  		  if ( bufl==8 ||
  		  	   bufg< 3 )
  		  {
  		  	src_wager[sprintf("yue_%d",bufl)]+=bufg;
  		  	break;
  		  }
  		}
  	}
  }
  
  wlist=keys(src_wager);
  for( p1=0;p1<sizeof(wlist);p1++)
  {
  	if ( wlist[p1]=="win_gems" )
  		continue;
  	
  	if ( wlist[p1]=="win_golds" &&
  		   src_wager[wlist[p1]]>0 )
  	{
  		me->add("balance", src_wager[wlist[p1]] );
  		message_vision("$N支付给$n"+chinese_number(src_wager[wlist[p1]])+"两黄金。\n", this_object(), me);
  		continue;
  	}
  	
  	if ( wlist[p1]=="golds" &&
  		   src_wager[wlist[p1]]>0 )
  	{
  		me->add("advance_balance", src_wager[wlist[p1]] );
  		message_vision("$N支付给$n"+chinese_number(src_wager[wlist[p1]])+"根金条。\n", this_object(), me);
  		continue;
  	}
  	
  	if ( sscanf(wlist[p1], "%s_%d", material, level)==2 )
  	{
  		if ( src_wager[wlist[p1]]>0 )
  		{
  			for(p2=0;p2<src_wager[wlist[p1]];p2++)
  			{
  				gem=new("/obj/gem/gem");
  				gem->set_special(material,level);
  				if ( !gem->move(me) )
  				{
  					tell_object(me,HIR+BNK+"由于你拿不动这许多宝石，"+this_object()->query("name")+"把宝石都给你放在了地上。\n"+NOR);
  					gem->move(environment(me));
  				}
  				message_vision("$N支付给$n一颗"+gem->query("name")+"。\n", this_object(), me);
  			}
  		}
  	}  				
  }
  
	return 1;
}

//查询赌局信息（debug用）
mapping query_betinfo()
{
	return bet_info;
}

//查询赔率信息（debug用）
mapping query_oddsinfo(string bet_id, string odds_id)
{
	return bet_info[bet_id]["odds"][odds_id];
}

//修改赌局设置（debug用）
void set_betinfo(string key, mixed value)
{
	if ( !bet_info )
		bet_info=([]);
  
  if( strsrch(key, '/')!=-1 )
  	this_object()->_set( bet_info, explode(key, "/"), value );
  else
    bet_info[key]=value;

  save();
}

//显示某一个赌局的基本信息
// type 0为显示特定赌局模式，不带附属命令
// type 1为通用赌局列表选择赌局模式，附带附属命令
protected string show_bet(string msg, int type)
{
	string output,bet_id,cmd, wodds;
	string *sst=({"初始化  ","接受投注","投注截至","结果公布","赌局关闭","强行终止","系统强行关闭"});
	string *wtype=({"金条", "宝石", "金条/宝石"});
	object me=this_player();
	
	if ( !type )
		bet_id=msg;
	else
	{
		if ( sscanf(msg,"%s %s",cmd,bet_id)!=2 )
			return 0;
		
		if ( cmd!="b" )
			return 0;
		
		if ( member_array(bet_id, keys(bet_info)) < 0 )
		{
			tell_object(me, "赌局编号输入错误，请重新输入命令：\n");
			input_to("show_bet",0,1);
			return 0;
		}
	}

  autochg_status(bet_id);
	output="赌局："HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR" \t 庄家："HIW+bet_info[bet_id]["dealer_name"]+"("+bet_info[bet_id]["dealer"]+")"NOR" \n";
	output+="赌局描述：\n";
	output+=bet_info[bet_id]["desc"]+"\n";
	output+="状态："+((bet_info[bet_id]["status"]<0)?"未知赌局":sst[bet_info[bet_id]["status"]])+"  投注类型："+(!bet_info[bet_id]["status"]?"未知":wtype[bet_info[bet_id]["wagerType"]])+
	"  获胜赔率："GRN+((bet_info[bet_id]["status"]==3||bet_info[bet_id]["status"]==4)?sprintf("%s(%s)",bet_info[bet_id]["odds"][bet_info[bet_id]["winOdds"]]["name"],bet_info[bet_id]["winOdds"]):"结果未公布")+NOR"\n";
	output+="赌局创建时间："+show_time(bet_info[bet_id]["createTime"])+ "  投注截至时间："+show_time(bet_info[bet_id]["wagerTime"])+"\n";
	output+="赌局关闭时间："+show_time(bet_info[bet_id]["endTime"])+"  赌局抽水比例："+sprintf("%d:1", bet_info[bet_id]["taxes"]) +"\n";
	output+=HIC"每个玩家投注限额："+(!bet_info[bet_id]["max_golds"]?"不限制金条":sprintf("最多%s根金条", chinese_number(bet_info[bet_id]["max_golds"])))+
	     "   "+(!bet_info[bet_id]["max_gem"]?"不限制宝石":sprintf("最多%s颗雷月", chinese_number(bet_info[bet_id]["max_gem"])))+"\n"NOR;
	output+="总投注金条："+chinese_number(bet_info[bet_id]["total_golds"])+"根 总投注宝石："+chinese_number(bet_info[bet_id]["total_gem"])+"颗雷月\n";
	output+="庄家金条："+chinese_number(bet_info[bet_id]["dealer_golds"])+"根 庄家宝石："+chinese_number(bet_info[bet_id]["dealer_gem"])+"颗雷月\n";
	if ( bet_info[bet_id]["status"]>=3 && bet_info[bet_id]["status"]<=4 )
		output+="庄家获利（包含非获胜赔率投入的保证金）："+chinese_number(bet_info[bet_id]["dwin_golds"])+"两黄金 "+chinese_number(bet_info[bet_id]["dwin_gem"])+"颗水月\n";
	output+="###############################################################################\n";
	output+=show_odds(bet_id);
	output+="###############################################################################\n";
	
	if ( type )
	{
		tell_object(me, output);
		tell_object(me, "请选择命令"HIY"o 赔率ID"NOR"显示详细的该赔率的详细信息，命令b返回上一层，其他命令退出查询赌局命令：\n");
		input_to("show_odds_detail", bet_id);
	}
	
	return output;
}

//显示某一个赌局下各个赔率的基本信息（不显示具体投注明细）
protected string show_odds(string bet_id)
{
	string output;
	mapping odds=bet_info[bet_id]["odds"];
	string *okey;
	int lp, tgolds, tgem, dgolds, dgem, wgolds, wgem, o1,o2;
	
	if ( !odds )
		return "";

	okey=keys(odds);
	output="\n";
	tgolds=bet_info[bet_id]["total_golds"];
	tgem=bet_info[bet_id]["total_gem"];
	dgolds=bet_info[bet_id]["dealer_golds"];
	dgem=bet_info[bet_id]["dealer_gem"];
	
	for(lp=0;lp<sizeof(okey);lp++)
	{
		output+="赔率名称："HIY+odds[okey[lp]]["name"]+"("+okey[lp]+")"NOR" \t 赔率："RED+odds[okey[lp]]["odds"]+NOR"\n";
		if ( odds[okey[lp]]["desc"] &&
			   strwidth(odds[okey[lp]]["desc"])>= 2 )
		  output+="赔率描述：\n"+odds[okey[lp]]["desc"]+"\n";
		output+="已投注金条："+chinese_number(odds[okey[lp]]["total_golds"])+"根  已投注宝石："+chinese_number(odds[okey[lp]]["total_gem"])+"颗雷月\n";
		output+="庄家金条："+chinese_number(odds[okey[lp]]["dealer_golds"])+"根  庄家宝石："+chinese_number(odds[okey[lp]]["dealer_gem"])+"颗雷月\n";
	  if ( !stringp(odds[okey[lp]]["odds"]) || 
	  	   sscanf(odds[okey[lp]]["odds"], "%d:%d", o1, o2)!=2 )
	  {
	  	output+="\n";
	  	continue;
	  }
	  wgolds=tgolds+dgolds-odds[okey[lp]]["dealer_golds"]-odds[okey[lp]]["total_golds"]*(o2+o1)/o1;
	  wgem=tgem+dgem-odds[okey[lp]]["dealer_gem"]-odds[okey[lp]]["total_gem"]*(o2+o1)/o1;
	  output+="本赔率获胜庄家盈利（包含庄家保证金）："+chinese_number(wgolds)+"根金条，"+chinese_number(wgem)+"颗雷月。\n\n";
	}
	
	return output;
}

//检查庄家押金是否足额支付玩家赌注。
//其中uodds是分子，dodds是分母，对于N:M来说N为dodds，M为uodds
protected int check_odds(int bet_total, int bet_dealer, int odds_total, int odds_dealer, string bet_id, int uodds, int dodds)
{
//	printf("%d, %d, %d, %d, %d, %d\n", bet_total, bet_dealer, odds_total, odds_dealer, uodds, dodds);
	if ( bet_total+bet_dealer-odds_dealer-odds_total*(uodds+dodds)/dodds < 0 )
		return 0;
	
	return 1;
}

//显示某一个赌局下某赔率的具体投注明细（包括庄家的保证金信息）
protected void show_odds_detail(string msg, string bet_id)
{
	string output, cmd, odds_id, *glist, material;
	mapping odds_info, oddsd_info, wager_info, gem_info;
	object me=this_player();
	string *wst=({"已投注  ","可以领奖","投注失利","已经领奖"}), *wkey;
	int lp, p2, level, ind;
	
	odds_info=bet_info[bet_id]["odds"];
	
  if ( sscanf(msg,"%s %s",cmd,odds_id)!=2 &&
		   msg!="b")
	  return;

	if ( msg == "b" )
	{
		printf("\n");
		do_find(find_arg);
		return;
	}
		
  if ( cmd!="o" )
		return;
		
	if ( member_array(odds_id, keys(odds_info)) < 0 )
	{
		tell_object(me, "赔率ID输入错误，请重新输入命令：\n");
		input_to("show_odds_detail",bet_id);
		return;
	}
	
	oddsd_info=odds_info[odds_id];
	wager_info=oddsd_info["wagers"];

	output="赔率名称："HIY+oddsd_info["name"]+"("+odds_id+")"NOR" \t 赔率："RED+oddsd_info["odds"]+NOR"\n";
	if ( oddsd_info["desc"] &&
		   strwidth(oddsd_info["desc"])>= 2 )
	  output+="赔率描述：\n"+oddsd_info["desc"]+"\n";
	output+="已投注金条："+chinese_number(oddsd_info["total_golds"])+"根  已投注宝石："+chinese_number(oddsd_info["total_gem"])+"颗雷月\n";
	output+="庄家金条："+chinese_number(oddsd_info["dealer_golds"])+"根  庄家宝石："+chinese_number(oddsd_info["dealer_gem"])+"颗雷月\n";
	if ( wager_info )
	{
		output+="玩家投注明细："HIC"（其中宝石数单位是颗雷月，盈利宝石单位是颗水月）\n"NOR;
		output+="###############################################################################\n";
		output+="玩家ID     投注状态 玩家类型 金条数 宝石数 盈利黄金 盈利宝石 最近投注时间\n";
		output+="           具体宝石明细                                                  \n";
		output+="###############################################################################\n";
		wkey=keys(wager_info);
		for(lp=0;lp<sizeof(wkey);lp++)
		{
			output+=sprintf(HIG"%-10s %-8s %-8s %-6d %-6d %-8d %-8d %-19s\n"NOR,
			 wkey[lp], wst[wager_info[wkey[lp]]["status"]], wager_info[wkey[lp]]["userType"]?"庄家":"玩家", 
			 wager_info[wkey[lp]]["wager"]["golds"], wager_info[wkey[lp]]["gems"], wager_info[wkey[lp]]["win_golds"],
			 wager_info[wkey[lp]]["win_gems"], show_time(wager_info[wkey[lp]]["addTime"]) );
			if ( wager_info[wkey[lp]]["gems"]>0 )
			{
				output+="           ";
				gem_info=wager_info[wkey[lp]]["wager"];
				glist=keys(gem_info);
				ind=0;
				for(p2=0;p2<sizeof(glist);p2++)
				{
					if ( sscanf(glist[p2],"%s_%d", material, level)==2 )
					{
						output+=sprintf("%s"CYN"[%d颗]  "NOR,F_GEMS->query_gem_name(material, level), gem_info[glist[p2]]);
						ind++;
					  if ( ind%4==0 )
						  output+="\n           ";
					}
				}
				if ( ind%4==0 ) 
				  output+="\n";
				else
					output+="\n\n";
			}
		}
	}
	
	output+="###############################################################################\n";
	output+="\n支持命令"HIY"a 金条数"NOR"增加金条投注，"HIY"g 宝石数"NOR"增加宝石投注，其中宝石数是宝石折算到雷月以后的等值雷月数量，\n";
	output+=  "会自动寻找五行宝石中火以上等级，日月宝石要求雷以上等级，命令b返回上一层，输入其他命令自动退出赌局查询命令。：\n";
	tell_object(me, output);
	input_to("add_wager", bet_id, odds_id);
	return;
}

//开启赌局的时候和赌局相关的信息输入检核和录入
protected void openbet_input(string msg, object me, string bet_id, string type)
{
	int len,days,wtype, mgolds, mgem;
	len=strwidth(msg);
	
	switch(type)
	{
		case "name":
			if ( !chn_check(msg, 20) )
			{
		    tell_object(me, "对不起，赌局标题输入非法，请重新输入（最多10个汉字）：\n");
		    input_to("openbet_input", me, bet_id, "name");
		    break;
			}
	    bet_info[bet_id][type]=msg;
	    tell_object(me, "\n请输入赌局的简单描述（最多100个汉字或者200个英文字母）：\n");
	    input_to("openbet_input", me, bet_id, "desc");
	    break;
	  case "desc":
			if ( strwidth(msg)>200 || strwidth(msg)< 2 )
			{
		    tell_object(me, "对不起，赌局的描述输入非法，请重新输入（最多100个汉字或者200个英文字母）：\n");
		    input_to("openbet_input", me, bet_id, "desc");
		    break;
			}
	    bet_info[bet_id][type]=msg;
	    tell_object(me, "\n请输入赌局的投注小时数（数字1-360表示1小时-15天，从开启投注开始算起的小时数）：\n");
	    input_to("openbet_input", me, bet_id, "wagerDays");
	    break;
	  case "wagerDays":
	  	if ( !msg ||
	  		   !sscanf(msg, "%d", days) )
	  	{
	  		tell_object(me, "请输入赌局的投注小时数（数字1-360表示1小时-15天，从开启投注开始算起的小时数）：\n");
	  		input_to("openbet_input", me, bet_id, "wagerDays");
	  		break;
	  	}
	  	
	  	if ( days<1 || days > 360 )
	  	{
	  		tell_object(me, "请输入赌局的投注小时数（数字1-360表示1小时-15天，从开启投注开始算起的小时数）：\n");
	  		input_to("openbet_input", me, bet_id, "wagerDays");
	  		break;
	  	}
	  	
	  	bet_info[bet_id][type]=days;
	  	tell_object(me, "请选择赌局接受的财物类型（0-仅接受金条，1-仅接受宝石，2-接受金条和宝石）：\n");
	  	input_to("openbet_input", me, bet_id, "wagerType");
	  	break;
	  case "wagerType":
	  	if ( !msg ||
	  		   !sscanf(msg, "%d", wtype) )
	  	{
	  		tell_object(me, "请选择赌局接受的财物类型（0-仅接受金条，1-仅接受宝石，2-接受金条和宝石）：\n");
	  		input_to("openbet_input", me, bet_id, "wagerType");
	  		break;
	  	}
	  	
	  	if ( wtype<0 || wtype > 2 )
	  	{
	  		tell_object(me, "请选择赌局接受的财物类型（0-仅接受金条，1-仅接受宝石，2-接受金条和宝石）：\n");
	  		input_to("openbet_input", me, bet_id, "wagerType");
	  		break;
	  	}
	  	
	  	bet_info[bet_id][type]=wtype;
	  	tell_object(me, "请选择赌局的投注限额（格式是N|M，N表示限制投注金条的数量，M表示限制投注宝石的雷月数，数值0表示不限制或者直接回车也表示不限制）：\n");
	  	input_to("openbet_input", me, bet_id, "wagerMax");
	  	break;
	  case "wagerMax":
	  	if ( msg &&
	  		   sscanf(msg,"%d|%d", mgolds, mgem)==2 )
	  	{
	  		bet_info[bet_id]["max_golds"]=mgolds;
	  		bet_info[bet_id]["max_gem"]=mgem;
	  	}
	  	tell_object(me, "赌局将开启至少2个以上赔率，现在请输入第一个赔率的赔率ID（a-zA-Z0-9组成的字符串）：\n");
	  	input_to("odds_init", me, bet_id, 0, 1, "oddsid");
	  	break;
	  default:
	  	error("非法的赌局信息输入类型。\n");
	}
	save();
}

//开启赌局的时候和赔率相关的信息输入检核和录入（保证输入两个赔率）
protected void odds_init(string msg, object me, string bet_id, string odds_id, int odds, string type)
{
	int len,lp, o1, o2;
	len=strwidth(msg);
	
	switch(type)
	{
		case "oddsid":
	    for ( lp=0;lp<len;lp++ )
	    {
		    if ( (msg[lp]>='a' && msg[lp]<='z') ||
			       (msg[lp]>='0' && msg[lp]<='9') ||
			       (msg[lp]>='A' && msg[lp]<='Z') )
	  	    continue;
	      if ( odds==1 )
	      {
	  	    tell_object(me, "赌局将开启至少2个以上赔率，现在请输入第一个赔率的赔率ID（a-zA-Z0-9组成的字符串）：\n");
	  	    input_to("odds_init", me, bet_id, 0, odds, "oddsid");
  	      return;
  	    }
  	    else 
  	    {
	  	    tell_object(me, "请输入第"+chinese_number(odds)+"个赔率的赔率ID（a-zA-Z0-9组成的字符串）：\n");
	  	    input_to("odds_init", me, bet_id, 0, odds, "oddsid");
  	      return;
  	    }
	    }
	    
	    if ( len > 10 )
	    {
		    tell_object(me, "赔率ID长度最长不能超过10，请重新输入：\n");
  	    input_to("odds_init", me, bet_id, 0, odds, "oddsid");
  	    break;
	    }
	    
	    if ( odds == 1 )
	    {
	      bet_info[bet_id]["odds"]=([]);
	    }
	    
	    if ( bet_info[bet_id]["odds"][msg] )
	    {
	    	tell_object(me, "该赔率ID已经使用，请重新输入：\n");
  	    input_to("odds_init", me, bet_id, 0, odds, "oddsid");
  	    break;
	    }

	    bet_info[bet_id]["odds"][msg]=([]);
	    bet_info[bet_id]["odds"][msg]["total_golds"]=0;
	    bet_info[bet_id]["odds"][msg]["total_gem"]=0;
	    bet_info[bet_id]["odds"][msg]["dealer_golds"]=0;
	    bet_info[bet_id]["odds"][msg]["dealer_gem"]=0;
      tell_object(me, "请输入本赔率的标题（最多10个汉字或者20个英文字母）：\n");
      input_to("odds_init", me, bet_id, msg, odds, "name");
	    break;
	  case "name":
	  	if ( len<2 || len>20 ) 
	  	{
        tell_object(me, "请输入本赔率的标题（最多10个汉字或者20个英文字母）：\n");
        input_to("odds_init", me, bet_id, odds_id, odds, "name");
	      break;
	    }
	    bet_info[bet_id]["odds"][odds_id][type]=msg;
      tell_object(me, "请输入本赔率的简单描述（最多100个汉字或者200个英文字母，非必输项）：\n");
      input_to("odds_init", me, bet_id, odds_id, odds, "desc");
	    break;
	  case "desc":
	  	if ( len>200 ) 
	  	{
        tell_object(me, "请输入本赔率的简单描述（最多100个汉字或者200个英文字母，非必输项）：\n");
        input_to("odds_init", me, bet_id, odds_id, odds, "desc");
	      break;
	    }
	    bet_info[bet_id]["odds"][odds_id][type]=msg;
      tell_object(me, "请输入本赔率的赔率值（请用N:M或者N$M的形式表示赔率，其中N，M为数值，表示投入的奖金和获胜后抽水前的盈利）：\n");
      input_to("odds_init", me, bet_id, odds_id, odds, "odds");
	    break;
	  case "odds":
	  	if ( sscanf(msg,"%d:%d",o1,o2)!=2 )
	  	{
	  		if ( sscanf(msg,"%d$%d",o1,o2)!=2 )
	  		{
	  		  tell_object(me, "请输入本赔率的赔率值（请用N:M或者N$M的形式表示赔率，其中N，M为数值，表示投入的奖金和获胜后抽水前的盈利）：\n");
          input_to("odds_init", me, bet_id, odds_id, odds, "odds");
          break;
        }
      }
      
      if ( o1<=0 || o2 <=0 )
	  	{
	  		tell_object(me, "请输入本赔率的赔率值（请用N:M或者N$M的形式表示赔率，其中N，M为数值，表示投入的奖金和获胜后抽水前的盈利）：\n");
        input_to("odds_init", me, bet_id, odds_id, odds, "odds");
        break;
      }
      
      bet_info[bet_id]["odds"][odds_id][type]=sprintf("%d:%d",o1,o2);
      if ( odds==1 ) 
      {
      	tell_object(me, "请输入第"+chinese_number(odds+1)+"个赔率的赔率ID（a-zA-Z0-9组成的字符串）：\n");
	  	  input_to("odds_init", me, bet_id, 0, odds+1, "oddsid");
	  	  break;
	  	}
	  	else
	  	{
	  		tell_object(me, "是否再设定一个赔率（Y/N）？：\n");
	  	  input_to("odds_init", me, bet_id, odds_id, odds, "decide");
	  	  break;
	  	}
	  case "decide":
	  	if ( msg=="Y" || msg=="y" )
	  	{
	  		tell_object(me, "请输入第"+chinese_number(odds+1)+"个赔率的赔率ID（a-zA-Z0-9组成的字符串）：\n");
	  	  input_to("odds_init", me, bet_id, 0, odds+1, "oddsid");
	  	  break;
	  	}
	  	else
	  	{
	  		tell_object(me, @DESC
本赌局所有设定都已完成，确认以后可以用bet modify修改信息，bet add 新增
赔率（开放投注以后禁止新增赔率），bet start 投入保证金开启赌局，bet odds修
改赔率，每个设定好的赔率都至少投入价值100的金条或者18 雷月的宝石作为保证金，
保证金的多少直接影响该赌局玩家投入到各个赔率的资金规模，bet start 命令在接
受投注以后转为追加押金模式，bet close 强制关闭赌局，只能在投注截至之前能够
进行强制关闭赌局，强制关闭之后各方可以无损取回本金，庄家取回的保证金要按照
抽水比例缴纳赔偿金。
DESC);
        if ( bet_info[bet_id]["status"]<0 )
        	bet_info[bet_id]["status"]=0;
        break;
	  	}
	  default:
	  	error("非法的赔率信息输入类型。\n");
	}
	save();
}

//维护赌局信息，step=0为输入维护类型， 1-赌局名称（name），2-赌局描述（desc），3-赔率名称（name），4-赔率描述（desc）
protected void modify_bet(string msg, object me, string bet_id, string odds_id, int step)
{
	string m1,m2;
	int len;
	
	len=strwidth(msg);
	switch(step)
	{
		case 0:
			if ( msg!="name" && msg!="desc" )
			{
				if ( sscanf(msg, "%s %s",m1,m2)!=2 )
				{
					tell_object(me, "你仅可以维护赌局名称（name），赌局描述（desc），赔率名称（赔率ID name），赔率描述（赔率ID desc）四种类型，\n请重新输入你要维护的信息类型：\n");
	        input_to("modify_bet", me, bet_id, 0, 0);
	        break;
	      }
	      
	      if ( member_array(m1, keys(bet_info[bet_id]["odds"]) )<0 )
	      {
		      write("该赌局并不存在你所要维护的赔率ID，请重新输入你要维护的信息类型\n（name-赌局名称，desc-赌局描述，赔率ID name-赔率名称，赔率ID desc-赔率描述）：\n");
		      input_to("modify_bet", me, bet_id, 0, 0);
		      break;
	      }
	      
	      if ( m2!="name" && m2!="desc" )
				{
					tell_object(me, "你仅可以维护赌局名称（name），赌局描述（desc），赔率名称（赔率ID name），赔率描述（赔率ID desc）四种类型，\n请重新输入你要维护的信息类型：\n");
	        input_to("modify_bet", me, bet_id, 0, 0);
	        break;
	      }
	      
	      if ( m2=="name" )
	      {
	      	tell_object(me, "请输入本赔率的新标题（最多10个汉字或者20个英文字母）：\n");
	      	input_to("modify_bet", me, bet_id, m1, 3);
	      	break;
	      }
	      else
	      {
	      	tell_object(me, "请输入本赔率的简单描述（最多100个汉字或者200个英文字母，非必输项）：\n");
	      	input_to("modify_bet", me, bet_id, m1, 4);
	      	break;
	      }
	    }
	    else
	    {
	      if ( msg=="name" )
	      {
	      	tell_object(me, "请输入本赌局的新标题（最多10个汉字）：\n");
	      	input_to("modify_bet", me, bet_id, 0, 1);
	      	break;
	      }
	      else
	      {
	      	tell_object(me, "请输入本赌局的简单描述（最多100个汉字或者200个英文字母）：\n");
	      	input_to("modify_bet", me, bet_id, 0, 2);
	      	break;
	      }
	    }
	  case 1:
			if ( !chn_check(msg, 20) )
			{
		    tell_object(me, "对不起，赌局标题输入非法，请重新输入（最多10个汉字）：\n");
		    input_to("modify_bet", me, bet_id, odds_id, 1);
		    break;
			}
	    bet_info[bet_id]["name"]=msg;
	    break;
	  case 2:
			if ( len>200 || len< 2 )
			{
		    tell_object(me, "对不起，赌局的描述输入非法，请重新输入（最多100个汉字或者200个英文字母）：\n");
		    input_to("modify_bet", me, bet_id, odds_id, 2);
		    break;
			}
	    bet_info[bet_id]["desc"]=msg;
	    break;
	  case 3:
	  	if ( len<2 || len>20 ) 
	  	{
        tell_object(me, "请输入本赔率的标题（最多10个汉字或者20个英文字母）：\n");
        input_to("modify_bet", me, bet_id, odds_id, 3);
	      break;
	    }
	    bet_info[bet_id]["odds"][odds_id]["name"]=msg;
	    break;
	  case 4:
	  	if ( len>200 ) 
	  	{
        tell_object(me, "请输入本赔率的简单描述（最多100个汉字或者200个英文字母，非必输项）：\n");
        input_to("modify_bet", me, bet_id, odds_id, 4);
	      break;
	    }
	    bet_info[bet_id]["odds"][odds_id]["desc"]=msg;
	    break;
	  default:
	  	error("非法的赌局信息维护类型。");
	}
	save();
}

//维护赌局的所有赔率，按照顺序依次修改各个赔率ID对应的具体赔率
//serial -1为开始修改赔率前的准备工作，0到odds_list个数上限为一一修改各个赔率ID的具体赔率
protected void modify_odds(string odds, object me, string bet_id, string *odds_list, int serial)
{
	mapping odds_info;
	int o1,o2;
	
	odds_info=bet_info[bet_id]["odds"];
	if ( serial<0 )
	{
		if ( sizeof(odds_list)>0 )
		{
			tell_object(me, "请输入赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』中『"HIY+
			  odds_info[odds_list[0]]["name"]+"("+odds_list[0]+")"NOR"』的最新赔率\n（旧赔率值："+
			  odds_info[odds_list[0]]["odds"]+"，不修改该赔率请直接回车。）：\n");
			input_to("modify_odds", me, bet_id, odds_list, 0);
			return;
		}
		else 
		{
			tell_object(me, "未输入赔率信息。\n");
			return;
		}
	}
	
	if ( sscanf(odds,"%d:%d",o1,o2)!=2 )
	{
		if ( sscanf(odds,"%d$%d",o1,o2)!=2 )
	  {
		  if ( sizeof(odds_list)<serial+2 )
		  {
			  tell_object(me, "赔率修改结束。\n");
			  return;
		  }
		
		  tell_object(me, "请输入赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』中『"HIY+
			  odds_info[odds_list[serial+1]]["name"]+"("+odds_list[serial+1]+")"NOR"』的最新赔率\n（旧赔率值："+
			  odds_info[odds_list[serial+1]]["odds"]+"，不修改该赔率请直接回车。）：\n");
		  input_to("modify_odds", me, bet_id, odds_list, serial+1);
      return;
    }
  }
  
  if ( o1<=0||o2<=0 )
	{
		tell_object(me, "请输入赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』中『"HIY+
			  odds_info[odds_list[serial]]["name"]+"("+odds_list[serial]+")"NOR"』的最新赔率\n（旧赔率值："+
			  odds_info[odds_list[serial]]["odds"]+"，不修改该赔率请直接回车。）：\n");
		input_to("modify_odds", me, bet_id, odds_list, serial);
    return;
  }
  
  if ( !check_odds(bet_info[bet_id]["total_golds"], bet_info[bet_id]["dealer_golds"], odds_info[odds_list[serial]]["total_golds"], 
             odds_info[odds_list[serial]]["dealer_golds"], bet_id, o2, o1) ||
       !check_odds(bet_info[bet_id]["total_gem"], bet_info[bet_id]["dealer_gem"], odds_info[odds_list[serial]]["total_gem"], 
             odds_info[odds_list[serial]]["dealer_gem"], bet_id, o2, o1) )
  {
  	tell_object(me, "修改赔率以后你目前的押金并不能足额支付玩家的赌注，请增加押金或者重新修改赔率。\n");
  	tell_object(me, "请输入赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』中『"HIY+
			  odds_info[odds_list[serial]]["name"]+"("+odds_list[serial]+")"NOR"』的最新赔率\n（旧赔率值："+
			  odds_info[odds_list[serial]]["odds"]+"，不修改该赔率请直接回车。）：\n");
		input_to("modify_odds", me, bet_id, odds_list, serial);
    return;
  }
  
  odds_info[odds_list[serial]]["odds"]=sprintf("%d:%d",o1,o2);
	save();
	CHANNEL_D->do_channel(this_object(), "jy", "赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』中『"HIY+
			  odds_info[odds_list[serial]]["name"]+"("+odds_list[serial]+")"NOR"』的赔率修改为"RED+odds+NOR"。");
	
	if ( sizeof(odds_list)<serial+2 )
	{
		tell_object(me, "赔率修改结束。\n");
		return;
	}
	
	tell_object(me, "请输入赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』中『"HIY+
			  odds_info[odds_list[serial+1]]["name"]+"("+odds_list[serial+1]+")"NOR"』的最新赔率\n（旧赔率值："+
			  odds_info[odds_list[serial+1]]["odds"]+"，不修改该赔率请直接回车。）：\n");
	input_to("modify_odds", me, bet_id, odds_list, serial+1);
  return;
}

//庄家缴纳保证金开启赌局
protected void save_deposit(string deposit, object me, string bet_id, string *odds_list, int serial)
{
	mapping odds_info;
	int golds,gem,igolds,igem;
	
	odds_info=bet_info[bet_id]["odds"];
	
	switch(bet_info[bet_id]["wagerType"])
	{
		case 0:
	    if ( serial<0 )
	    {
		    if ( sizeof(odds_list)>0 )
		    {
			    tell_object(me, "请输入黄金赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			      odds_info[odds_list[0]]["name"]+"("+odds_list[0]+")"NOR"』要缴纳的保证金\n"+
			      "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			      "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			      "局需要输入两个数字，中间用|分隔，每个赔率庄家押金中金条不能少于100根，宝\n"+
			      "石不能少于等值9颗雷月的宝石数）：\n");
			    input_to("save_deposit", me, bet_id, odds_list, 0);
			    return;
		    }
		    else 
		    {
			    tell_object(me, "未输入赔率信息。\n");
			    return;
		    }
	    }
	    
	    igolds=odds_info[odds_list[serial]]["dealer_golds"];
			if ( !sscanf(deposit, "%d", golds) || 
				   (golds+igolds)<100 )
			{
			  tell_object(me, "请输入黄金赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			    odds_info[odds_list[serial]]["name"]+"("+odds_list[serial]+")"NOR"』要缴纳的保证金\n"+
			    "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			    "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			    "局需要输入两个数字，中间用|分隔，每个赔率庄家押金中金条不能少于100根，宝\n"+
			    "石不能少于等值9颗雷月的宝石数）：\n");
			  input_to("save_deposit", me, bet_id, odds_list, serial);
			  return;
			}
			
			if ( wager_golds(me, bet_id, odds_list[serial], golds) )
			{
				if ( sizeof(odds_list)<serial+2 )
	      {
		      tell_object(me, HIR"完成所有赔率的保证金缴纳，赌局开放投注。\n"NOR);
		      if ( !bet_info[bet_id]["status"] )
		      {
		      	CHANNEL_D->do_channel(this_object(), "jy", "赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』开放投注，欢迎各位玩家到长安城长乐坊投注。");
		        bet_info[bet_id]["status"]=1;
	          bet_info[bet_id]["startTime"]=time();
	          bet_info[bet_id]["wagerTime"]=time()+bet_info[bet_id]["wagerDays"]*3600;
	          save();
	        }
	        show_bet(bet_id,0);
		      return;
	      }
	      
			  tell_object(me, "请输入黄金赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			    odds_info[odds_list[serial+1]]["name"]+"("+odds_list[serial+1]+")"NOR"』要缴纳的保证金\n"+
			    "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			    "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			    "局需要输入两个数字，中间用|分隔，每个赔率庄家押金中金条不能少于100根，宝\n"+
			    "石不能少于等值9颗雷月的宝石数）：\n");
			  input_to("save_deposit", me, bet_id, odds_list, serial+1);
			  return;
	    }
	    else
	    {
	    	tell_object(me, "保证金缴纳失败，请过一会儿重新缴纳保证金。\n");
	    	return;
	    }
	  case 1:
	    if ( serial<0 )
	    {
		    if ( sizeof(odds_list)>0 )
		    {
			    tell_object(me, "请输入宝石赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			      odds_info[odds_list[0]]["name"]+"("+odds_list[0]+")"NOR"』要缴纳的保证金\n"+
			      "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			      "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			      "局需要输入两个数字，中间用|分隔，每个赔率庄家押金中金条不能少于100根，宝\n"+
			      "石不能少于等值9颗雷月的宝石数）：\n");
			    input_to("save_deposit", me, bet_id, odds_list, 0);
			    return;
		    }
		    else 
		    {
			    tell_object(me, "未输入赔率信息。\n");
			    return;
		    }
	    }
	    
	    igem=odds_info[odds_list[serial]]["dealer_gem"];
			if ( !sscanf(deposit, "%d", gem) || 
				   (gem+igem)<9 )
			{
			  tell_object(me, "请输入宝石赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			    odds_info[odds_list[serial]]["name"]+"("+odds_list[serial]+")"NOR"』要缴纳的保证金\n"+
			    "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			    "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			    "局需要输入两个数字，中间用|分隔，每个赔率庄家押金中金条不能少于100根，宝\n"+
			    "石不能少于等值9颗雷月的宝石数）：\n");
			  input_to("save_deposit", me, bet_id, odds_list, serial);
			  return;
			}
			
			if ( wager_gem(me, bet_id, odds_list[serial], gem) )
			{
				if ( sizeof(odds_list)<serial+2 )
	      {
		      tell_object(me, "完成所有赔率的保证金缴纳，赌局开放投注。\n");
		      if ( !bet_info[bet_id]["status"] )
		      {
		      	CHANNEL_D->do_channel(this_object(), "jy", "赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』开放投注，欢迎各位玩家到长安城长乐坊投注。");
		        bet_info[bet_id]["status"]=1;
	          bet_info[bet_id]["startTime"]=time();
	          bet_info[bet_id]["wagerTime"]=time()+bet_info[bet_id]["wagerDays"]*3600;
	          save();
	        }
	        show_bet(bet_id,0);
		      return;
	      }
	      
			  tell_object(me, "请输入宝石赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			    odds_info[odds_list[serial+1]]["name"]+"("+odds_list[serial+1]+")"NOR"』要缴纳的保证金\n"+
			    "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			    "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			    "局需要输入两个数字，中间用|分隔，每个赔率庄家押金中金条不能少于100根，宝\n"+
			    "石不能少于等值9颗雷月的宝石数）：\n");
			  input_to("save_deposit", me, bet_id, odds_list, serial+1);
			  return;
	    }
	    else
	    {
	    	tell_object(me, "保证金缴纳失败，请过一会儿重新缴纳保证金。\n");
	    	return;
	    }
	  case 2:
	    if ( serial<0 )
	    {
		    if ( sizeof(odds_list)>0 )
		    {
			    tell_object(me, "请输入宝石和黄金赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			      odds_info[odds_list[0]]["name"]+"("+odds_list[0]+")"NOR"』要缴纳的保证金\n"+
			      "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			      "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			      "局需要输入两个数字，中间用|分隔，举例：100|18，表示100根金条，等值18颗雷\n"+
			      "月的宝石每个赔率庄家押金中金条不能少于100 根，宝石不能少于等值9颗雷月的\n"+
			      "宝石数）：\n");
			    input_to("save_deposit", me, bet_id, odds_list, 0);
			    return;
		    }
		    else 
		    {
			    tell_object(me, "未输入赔率信息。\n");
			    return;
		    }
	    }
	    
	    igolds=odds_info[odds_list[serial]]["dealer_golds"];
	    igem=odds_info[odds_list[serial]]["dealer_gem"];
			if ( sscanf(deposit, "%d|%d", golds, gem)!=2 || 
				   (golds+igolds)<100 ||
				   (gem+igem)<9 )
			{
			  tell_object(me, "请输入宝石和黄金赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			    odds_info[odds_list[serial]]["name"]+"("+odds_list[serial]+")"NOR"』要缴纳的保证金\n"+
			    "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			    "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			    "局需要输入两个数字，中间用|分隔，举例：100|18，表示100根金条，等值18颗雷\n"+
			    "月的宝石每个赔率庄家押金中金条不能少于100 根，宝石不能少于等值9颗雷月的\n"+
			    "宝石数）：\n");
			  input_to("save_deposit", me, bet_id, odds_list, serial);
			  return;
			}
			
			if ( wager_golds(me, bet_id, odds_list[serial], golds) &&
				   wager_gem(me, bet_id, odds_list[serial], gem) )
			{
				if ( sizeof(odds_list)<serial+2 )
	      {
		      tell_object(me, "完成所有赔率的保证金缴纳，赌局开放投注。\n");
		      if ( !bet_info[bet_id]["status"] )
		      {
		      	CHANNEL_D->do_channel(this_object(), "jy", "赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』开放投注，欢迎各位玩家到长安城长乐坊投注。");
		        bet_info[bet_id]["status"]=1;
	          bet_info[bet_id]["startTime"]=time();
	          bet_info[bet_id]["wagerTime"]=time()+bet_info[bet_id]["wagerDays"]*3600;
	          save();
	        }
	        show_bet(bet_id,0);
		      return;
	      }
	      
			  tell_object(me, "请输入宝石和黄金赌局『"HIM+bet_info[bet_id]["name"]+"("+bet_id+")"NOR"』的赔率『"HIY+
			    odds_info[odds_list[serial+1]]["name"]+"("+odds_list[serial+1]+")"NOR"』要缴纳的保证金\n"+
			    "（根据赌局收取的投注类型不同收取对应的采取，对于仅收取金条或者宝石的赌局\n"+
			    "输入数字表示金条根数或者宝石折算到雷月的数量，对于同时收取金条和宝石的赌\n"+
			    "局需要输入两个数字，中间用|分隔，举例：100|18，表示100根金条，等值18颗雷\n"+
			    "月的宝石每个赔率庄家押金中金条不能少于100 根，宝石不能少于等值9颗雷月的\n"+
			    "宝石数）：\n");
			  input_to("save_deposit", me, bet_id, odds_list, serial+1);
			  return;
	    }
	    else
	    {
	    	tell_object(me, "保证金缴纳失败，请过一会儿重新缴纳保证金。\n");
	    	return;
	    }
	  default:
	  	error("错误的赌局投注类型。\n");
	}
}

//玩家向赌局投注押金
protected void add_wager(string msg, string bet_id, string odds_id)
{
	object me=this_player();
	string cmd;
	int golds;
	
	if ( bet_info[bet_id]["status"]!=1 &&
		   msg!="b" )
	{
		tell_object(me, "该赌局未处于接受投注状态，无法进行押注。\n");
		printf("\n");
	  show_bet("b "+bet_id, 1);
	  return;
	}
	
	if ( sscanf(msg,"%s %d",cmd,golds)!=2 &&
		   msg!="b" )
		return;
	
	if ( msg == "b" )
	{
		printf("\n");
		show_bet("b "+bet_id, 1);
		return;
	}
	
	if ( cmd!="a" &&
		   cmd!="g")
		return;
	
	if(cmd=="a")
		wager_golds(me, bet_id, odds_id, golds);
	else
		wager_gem(me, bet_id, odds_id, golds);
	
	printf("\n");
	show_odds_detail("o "+odds_id, bet_id);
}

//庄家或者玩家向赌局缴纳押金（金条）
protected int wager_golds(object me, string bet_id, string odds_id, int golds)
{
	mapping odds_info,wager;
	int o1,o2;
	
	if ( me->query("advance_balance")<golds )
	{
		tell_object(me, "你身上拥有的金条数不足，请补足以后再来操作。\n");
		return 0;
	}
	
	odds_info=bet_info[bet_id]["odds"][odds_id];
	if ( !odds_info["wagers"] )
		odds_info["wagers"]=([]);
	if ( !odds_info["wagers"][me->query("id")] )
		odds_info["wagers"][me->query("id")]=([]);
	wager=odds_info["wagers"][me->query("id")];
	if ( !wager["wager"] )
		wager["wager"]=([]);

	if ( me->query("id")!=bet_info[bet_id]["dealer"] &&
		   bet_info[bet_id]["max_golds"] &&
		   wager["wager"]["golds"]+golds> bet_info[bet_id]["max_golds"] )
  {
  	tell_object(me, "庄家限制该赌局每个玩家在每个赔率上最多投注"+bet_info[bet_id]["max_golds"]+"根金条。\n");
		return 0;
	}
  
  if ( sscanf(odds_info["odds"],"%d:%d",o1,o2)!=2 )
  {
  	tell_object(me, "未设置具体赔率禁止下注或者缴纳保证金。\n");
		return 0;
	}
  
  if ( me->query("id")!=bet_info[bet_id]["dealer"] &&
  	   !check_odds(bet_info[bet_id]["total_golds"]+golds, bet_info[bet_id]["dealer_golds"], odds_info["total_golds"]+golds, 
             odds_info["dealer_golds"], bet_id, o2, o1) )
  {
  	tell_object(me, "增加投注以后庄家押金将会不足，投注失败。\n");
		return 0;
	}
	
	me->add("advance_balance", -golds);
	wager["wager"]["golds"]+=golds;
	if ( !wager["wagerTime"] )
		wager["wagerTime"]=time();

	wager["addTime"]=time();
	wager["status"]=0;
	if ( me->query("id")==bet_info[bet_id]["dealer"] )
	{
	  odds_info["dealer_golds"]+=golds;
	  bet_info[bet_id]["dealer_golds"]+=golds;
		wager["userType"]=1;
	}
	else
	{
		odds_info["total_golds"]+=golds;
		bet_info[bet_id]["total_golds"]+=golds;
	  wager["userType"]=0;
	  bet_info[bet_id]["taxes"]=10+bet_info[bet_id]["total_golds"]/100+bet_info[bet_id]["total_gem"]/9;  
	  //每1万黄金增加1点抽水，每1泽月增加1点抽水
	  if ( bet_info[bet_id]["taxes"]> 50 )
	  	bet_info[bet_id]["taxes"]=50;
	}
	tell_object(me, "你将"+chinese_number(golds)+"根金条投入到赌局当作。\n");
	save();
	return 1;
}

//庄家或者玩家向赌局缴纳押金（宝石）
//宝石仅限于五行类型宝石或者日月类宝石，其中五行类宝石中阳性宝石必须泽以上，其他火以上
//日月类宝石雷以上就可以了。
protected int wager_gem(object me, string bet_id, string odds_id, int gem)
{
	object *gems, *inv;
	mapping odds_info,wager;
	int lp,lei,o1,o2,yang, yin;
	
	inv=all_inventory(me);
	lei=0;
	yang=0;
	yin=0;
	gems=({});
	for(lp=0;lp<sizeof(inv);lp++)
	{
		if ( inv[lp]->is_gem() && 
			   ( inv[lp]->query("type")=="wuxing" ||
			     inv[lp]->query("type")=="riyue" ) )
	  {
	  	if ( ( inv[lp]->query("type")=="wuxing" &&
	  		     inv[lp]->query("level")>=6 ) ||
	  		   ( inv[lp]->query("type")=="riyue" &&
	  		     inv[lp]->query("level")>=5 ) )
	  	{
	  		if ( inv[lp]->query("type")=="wuxing" )
	  		{
	  			if ( inv[lp]->query("level") == 6 )
	  			{
	  				lei++;
	  				if ( inv[lp]->query("yinyang")=="yang" )
	  					yang++;
	  				else
	  					yin++;
	  			}
	  			else
	  			{
	  				lei+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-6))));
	  				if ( inv[lp]->query("yinyang")=="yang" )
	  					yang+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-5))));
	  				else
	  					yin+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-5))));
	  			}
	  		}
	  		
	  		if ( inv[lp]->query("type")=="riyue" &&
	  			   inv[lp]->query("material")=="yue" )
	  		{
	  			if ( inv[lp]->query("level") == 5 )
	  			{
	  				lei++;
	  				yin++;
	  			}
	  			else
	  			{
	  				lei+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-5))));
	  				yin+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-5))));
	  			}
	  		}
	  		
	  		if ( inv[lp]->query("type")=="riyue" &&
	  			   inv[lp]->query("material")=="ri" )
	  		{
  				lei+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-4))));
  				yang+=to_int(ceil(pow(3.0,(inv[lp]->query("level")-4))));
  			}
  			gems+=({inv[lp]});
  		}
  	}
  	
  	if ( lei>=gem )
  		break;
  }
  
  if ( lei<gem )
  {
  	tell_object(me, "你身上拥有的宝石数量不足，请补足以后再来操作。\n");
  	return 0;
  }
  
	odds_info=bet_info[bet_id]["odds"][odds_id];
	if ( !odds_info["wagers"] )
		odds_info["wagers"]=([]);
	if ( !odds_info["wagers"][me->query("id")] )
		odds_info["wagers"][me->query("id")]=([]);
	wager=odds_info["wagers"][me->query("id")];
	if ( !wager["wager"] )
		wager["wager"]=([]);

  if ( sscanf(odds_info["odds"],"%d:%d",o1,o2)!=2 )
  {
  	tell_object(me, "未设置具体赔率禁止下注或者缴纳保证金。\n");
		return 0;
	}
  
  if ( me->query("id")!=bet_info[bet_id]["dealer"] &&
  	   !check_odds(bet_info[bet_id]["total_gem"]+lei, bet_info[bet_id]["dealer_gem"], odds_info["total_gem"]+lei, 
             odds_info["dealer_gem"], bet_id, o2, o1) )
  {
  	tell_object(me, "增加投注以后庄家押金将会不足，投注失败。\n");
		return 0;
	}
	
	if ( me->query("id")!=bet_info[bet_id]["dealer"] &&
		   bet_info[bet_id]["max_gem"] &&
		   wager["gems"]+lei> bet_info[bet_id]["max_gem"] )
  {
  	tell_object(me, "庄家限制该赌局每个玩家在每个赔率上最多投注等值"+bet_info[bet_id]["max_gem"]+"颗雷月的宝石。\n");
		return 0;
	}

  for(lp=0;lp<sizeof(gems);lp++)
  {
  	tell_object(me, "你将"+gems[lp]->query("name")+"投入赌局。\n");
  	wager["wager"][sprintf("%s_%d", gems[lp]->query("material"), gems[lp]->query("level"))]+=1;
    destruct(gems[lp]);
  }
  
	if ( !wager["wagerTime"] )
		wager["wagerTime"]=time();

	wager["addTime"]=time();
	wager["status"]=0;
	wager["gems"]+=lei;
	if ( yang>0 )
		wager["gems_yang"]+=yang;
	
	if ( yin>0 )
		wager["gems_yin"]+=yin;
	if ( me->query("id")==bet_info[bet_id]["dealer"] )
	{
	  odds_info["dealer_gem"]+=lei;
	  bet_info[bet_id]["dealer_gem"]+=lei;
		wager["userType"]=1;
	}
	else
	{
		odds_info["total_gem"]+=lei;
		bet_info[bet_id]["total_gem"]+=lei;
	  wager["userType"]=0;
	  bet_info[bet_id]["taxes"]=10+bet_info[bet_id]["total_golds"]/100+bet_info[bet_id]["total_gem"]/9;  
	  //每1万黄金增加1点抽水，每1泽月增加1点抽水
	  if ( bet_info[bet_id]["taxes"]> 50 )
	  	bet_info[bet_id]["taxes"]=50;
	}
	tell_object(me, "你将"+chinese_number(lei)+"颗等值雷月的宝石投入到赌局当作。\n");
	save();
	return 1;
}

//自动更新赌局状态
//赌局状态自动更新包括如果超过投注截至时间，自动将状态从接受投注修改为投注结束
//如果超过投注截至时间一周，庄家仍然没有公布结果，自动将状态从投注结束修改为系统强行终止赌局，庄家保证金平摊给各玩家。
//如果超过赌局结束时间，自动将赌局从公布结果修改为赌局结束，终止玩家领取收益和赎回押金。
protected void autochg_status(string bet_id)
{
	mapping odds_info, wager_info;
	int p1,p2, tgolds, tgem, wgolds, wgem, dgolds, dgem;
	string *olist,*ulist, uid;
	
	if ( bet_info[bet_id]["wagerTime"]<=time() &&
	 	   bet_info[bet_id]["status"]==1 )
	{
		CHANNEL_D->do_channel(this_object(), "jy", "赌局『"+bet_info[bet_id]["name"]+"("+bet_id+")』关闭投注，等待庄家公布结果，请庄家在七天内公布结果。");
	  bet_info[bet_id]["status"]=2;
	  save();
	}
	
	if ( time()-bet_info[bet_id]["wagerTime"]>=7*24*3600 &&
		   bet_info[bet_id]["status"]==2 )
	{
		CHANNEL_D->do_channel(this_object(), "jy", "赌局『"+bet_info[bet_id]["name"]+"("+bet_id+")』超过七天未公布赌局结果，被系统强行关闭，请各位玩家领走押金。");
		bet_info[bet_id]["status"]=6;
		bet_info[bet_id]["endTime"]=time();
		olist=keys(bet_info[bet_id]["odds"]);
		for(p1=0;p1<sizeof(olist);p1++)
		{
			odds_info=bet_info[bet_id]["odds"][olist[p1]];
			tgolds=odds_info["total_golds"];
			tgem=odds_info["total_gem"];
			dgolds=odds_info["dealer_golds"];
			dgem=odds_info["dealer_gem"];
			wgolds=dgolds*100;
			wgem=dgem*9;
			ulist=keys(odds_info["wagers"]);
			uid=0;
			for(p2=0;p2<sizeof(ulist);p2++)
			{
				wager_info=odds_info["wagers"][ulist[p2]];
				if ( wager_info["userType"] )
					continue;
			  
			  uid=ulist[p2];
			  
				if ( tgolds && wgolds>dgolds*100*wager_info["wager"]["golds"]/tgolds )
				{
					wager_info["win_golds"]=dgolds*100*wager_info["wager"]["golds"]/tgolds;
					wgolds-=dgolds*100*wager_info["wager"]["golds"]/tgolds;
				}
				else if ( !tgolds )
				{
          wager_info["win_golds"]=dgolds*100/(sizeof(ulist)-1);
					wgolds-=dgolds*100/(sizeof(ulist)-1);
				}
				else
				{
					wager_info["win_golds"]=wgolds;
					wgolds=0;
				}
				
				if ( tgem && wgem>dgem*9*wager_info["gems"]/tgem )
				{
					wager_info["win_gems"]=dgem*9*wager_info["gems"]/tgem;
					wgem-=dgem*9*wager_info["gems"]/tgem;
				}
				else if ( !tgem )
				{
					wager_info["win_gems"]=dgem*9/(sizeof(ulist)-1);
					wgem-=dgem*9/(sizeof(ulist)-1);
				}
				else
				{
					wager_info["win_gems"]=wgem;
					wgem=0;
				}
				
				wager_info["status"]=1;
			}
		}
		
		if ( uid && wgolds>0 )
			odds_info["wagers"][uid]["win_golds"]+=wgolds;
		
		if ( uid && wgem>0 )
			odds_info["wagers"][uid]["win_gems"]+=wgem;
		
		save();
	}
	
	if ( time()>=bet_info[bet_id]["endTime"] &&
		   bet_info[bet_id]["status"]==3 )
	{
		CHANNEL_D->do_channel(this_object(), "jy", "赌局『"+bet_info[bet_id]["name"]+"("+bet_id+")』已经关闭，关闭投注者领取收益，请庄家领取赌局收益。");
		bet_info[bet_id]["status"]=4;
		save();
	}
}

//清理所有赌局结束超过30天以上的所有赌局。
protected void clear_bet()
{
	string *bkey=keys(bet_info),*dkey;
	int lp;
	
	dkey=({});
	for(lp=0;lp<sizeof(bkey);lp++)
	{
		autochg_status(bkey[lp]);
		if ( ( bet_info[bkey[lp]]["status"]==4 ||
			     bet_info[bkey[lp]]["status"]==5 ||
			     bet_info[bkey[lp]]["status"]==6 ) &&
			   time()-bet_info[bkey[lp]]["endTime"]>30*24*3600 )
		  map_delete(bet_info, bkey[lp]);
	}
}

//中文检查
protected int chn_check(string msg, int maxlen)
{
	int len=strwidth(msg);
	
  if( len < 1 || len > maxlen ) 
	  return 0;

  while(len--) 
  {
		if( msg[len]<=' ' ) 
      return 0;
		    
    if(  !CHINESE_D->is_chinese_character(msg[len..<0]) ) 
      return 0;
  }
  
  return 1;
}

//标准时间显示
protected string show_time(int time)
{
	mixed *tm=localtime(time);
	
	if ( !time )
		return "未知时间";
	else
	  return sprintf("%d-%d-%d %d:%d:%d", tm[5], tm[4]+1, tm[3], tm[2], tm[1]+1, tm[0]+1);
}