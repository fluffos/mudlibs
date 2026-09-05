// jewelrystore.c 珠宝店
// by seagate@pkuxkx 2011/04/18
// 用来进行新货币单位-金块交易使用。

inherit ROOM;

void init()
{
	add_action("do_withdraw", ({"sell", "卖"}));
	add_action("do_deposit", ({"buy", "买"}));
	add_action("do_check", ({"check", "cha", "查"}));
	add_action("do_pawn", ({"dang", "当"}));
	add_action("do_exchange", ({"exchange", "兑换"}));
}

int do_deposit(string arg)
{
	object ob=this_player();
	int bgolds;
	
	if ( !arg || sscanf(arg, "%d", bgolds)!=1)
	  return notify_fail("命令格式：buy <金条数量>, 1 金条=100gold。\n");
	
	if ( bgolds > 1000 )
		return notify_fail("每次最多买1000根金条。\n");

  if ( bgolds <=0 )
  	return notify_fail("你至少要买一根金条。\n");

	if ( ob->query("balance")<bgolds*1000000 )
		return notify_fail("你在钱庄的存款不足以支付这笔交易。\n");
  
  if ( ob->query("age")<=18 )
  	return notify_fail("本店只接受成年人交易。\n");
  
  if ( !ob->query("reborn/all") )
  	return notify_fail("只有大宗师才有资格在本店进行投资交易。\n");
	
	ob->add("balance", bgolds*(-1000000));
	ob->add("advance_balance", bgolds);
	message_vision("伙计过来给$N办理了大额金条投资业务，$N从钱庄那里买了"+chinese_number(bgolds)+"根金条，\n"
	               "目前$N由本店代为保管"+chinese_number(ob->query("advance_balance"))+"根金条。\n", ob);
	return 1;
}

int do_withdraw(string arg)
{
	object ob=this_player();
	int sgolds;
	
	if (!arg || sscanf(arg, "%d", sgolds)!=1)
	  return notify_fail("命令格式：sell <金条数量>, 1 金条=100gold。\n");
	
	if ( sgolds > 1000 )
		return notify_fail("每次最多卖1000根金条。\n");

  if ( sgolds <=0 )
  	return notify_fail("你至少要卖一根金条。\n");
  
  if ( ob->query("advance_balance") < sgolds )
  	return notify_fail("你没有在本店买过这么多金条。\n");
  	
	if ( ob->query("balance")/1000000+sgolds>=2000 )
		return notify_fail("你在钱庄的存款太多了，出售金条以后将会超出钱庄存款上限。\n");
		
  if ( ob->query("age")<=18 )
  	return notify_fail("本店只接受成年人交易。\n");
/*  
  if ( !ob->query("reborn/all")  )
  	return notify_fail("只有大宗师才有资格在本店进行投资交易。\n");
	*/
	ob->add("balance", sgolds*1000000);
	ob->add("advance_balance", -sgolds);
	if ( ob->query("advance_balance") )
	  message_vision("伙计过来将$N存放在本店的"+chinese_number(sgolds)+"根金条出售给了钱庄，\n"
	                 "目前$N在本店还保管"+chinese_number(ob->query("advance_balance"))+"根金条。\n", ob);
	else
		message_vision("伙计过来将$N存放在本店的"+chinese_number(sgolds)+"根金条都出售给了钱庄。\n", ob);
	return 1;
}

int do_pawn(string arg)
{
	object me=this_player(), ob;
	mixed *tm=localtime(time());
	string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	int *price=({3,8,20,60,200,500,1500,4000}), level, dprice;
	string name,material;
	
	if ( !arg || !(ob=present(arg, me)) || !objectp(ob) || base_name(ob)!="/obj/gem/gem" )
		return notify_fail("本店仅回收宝石！\n");
	
	if ( me->is_busy() )
		return notify_fail("你正忙着！\n");
	
	level=ob->query("level");
	name=ob->query("name");
	material=ob->query("material");
  
  if ( query("time")!=date )
  {
  	set("gold", 5000);
    set("golds", 500);
    set("time",date);
    set("no_clean_up", 1);
  }
  
  if ( level<=4 && query("gold")<=0 )
  	return notify_fail("本店资本金不足，暂时无法收购宝石，请第二天再来。\n");
  else if ( level>4 && query("golds")<=0 )
  	return notify_fail("本店资本金不足，暂时无法收购宝石，请第二天再来。\n");
  
	destruct(ob);
	me->start_busy(1);
	if ( me->query("balance")/1000000>1900 )
	{
		me->add("balance", -600*1000000);
		me->add("advance_balance", 600);
	  tell_object(me, "由于你的存款太多，店伙计自动的将你的部分存款转换成金条。\n");
	}
	if ( level>4 )
	{
		dprice=price[level-1]/100;
		if ( material=="ri" )
			dprice=dprice*9;
		else if ( material=="yue" )
			dprice=dprice*3;
		me->add("advance_balance", dprice );
		add("golds", -dprice);
	  tell_object(me, "店伙计过来回收了"+name+"，付给你"+chinese_number(dprice)+"根金条。\n");
	}
	else
	{
		dprice=price[level-1]*10000;
		if ( material=="ri" )
			dprice=dprice*9;
		else if ( material=="yue" )
			dprice=dprice*3;
		me->add("balance", dprice);
		add("gold", -dprice/10000);
	  tell_object(me, "店伙计过来回收了"+name+"，付给你"+chinese_number(dprice/10000)+"两黄金。\n");
	}
	return 1;
}

int do_exchange(string arg)
{
    int gs, lp, gint, exs;
    string gid;
    object *invs, me=this_player(), gem, *glist, *nglist, newg;
    mapping gchar;
    
  	if (!arg || sscanf(arg, "%d %s", gs, gid)!=2)
	    return notify_fail("命令格式：exchange <宝石数量> <宝石ID>。\n");
	  
	  if ( !gs )
	    return notify_fail("至少要兑换一个宝石。\n");
	  
	  invs=all_inventory(me);
	  gint=0;
	  gchar=([]);
	  
	  for ( lp=0; lp<sizeof(invs); lp++ )
	  {
	    if ( base_name(invs[lp])=="/obj/gem/gem" &&
	         invs[lp]->id(gid) )
	    {
	      if ( !gint )
	      {
	        gint++;
	        gchar["yinyang"]=invs[lp]->query("yinyang");
	        gchar["material"]=invs[lp]->query("material");
	        gchar["level"]=invs[lp]->query("level");
	        gchar["name"]=invs[lp]->query("name");
	        glist=({})+({invs[lp]});
	      }
	      else if ( gchar["yinyang"]==invs[lp]->query("yinyang") &&
	                gchar["material"]==invs[lp]->query("material") &&
	                gchar["level"]==invs[lp]->query("level") )
	      {
	        gint++;
	        glist=glist+({invs[lp]});
	      }	        
	    }
	  }
	  
	  if ( !gint || gint<gs )
	    return notify_fail("你身上没有那么多宝石或者你所要的宝石种类并不存在！\n");
	  
	  if ( gchar["level"]<=5 && gs%2 )
	    return notify_fail("低级宝石兑换必须偶数个兑换！\n");
	    
	  if ( gchar["level"]==1 )
	    return notify_fail("地宝石无法兑换成更低级的宝石。\n");
	  
	  if ( me->is_busy() )
	    return notify_fail("你正忙着呢！\n");
	  
    me->start_busy(2);
    if ( gchar["level"]<=5 )
      exs=gs*3/2;
    else
      exs=gs*2;
    
    nglist=({});
    for ( lp=1; lp<=exs; lp++)
    {
      newg=F_GEMS->new_gem( gchar["material"], gchar["level"] - 1, gchar["yinyang"] );
      if ( !objectp(newg) )
        return notify_fail("宝石兑换出现异常！\n");
      
      nglist=nglist+({newg});
    }
    
    for ( lp=0; lp<gs;lp++)
      destruct(glist[lp]);
    
    for ( lp=0; lp<sizeof(nglist);lp++)
      nglist[lp]->move(me);
    
    printf("将你给的%d个%s兑换成了%d个%s。\n", gs, gchar["name"], exs, nglist[0]->query("name"));
    return 1;
}

int do_check()
{
	object ob=this_player();
	
	if ( ob->query("advance_balance") > 0 )
		message_vision("伙计过来告诉$N：目前本店保管着$N的金条数量为"+chinese_number(ob->query("advance_balance"))+"根。\n", ob);
	else
		message_vision("伙计过来告诉$N：$N和本店没有任何业务往来。\n", ob);
	
	return 1;
}

string show_notice()
{
	return  @TEXT
本店提供以下几种投资交易：
  购买金条      buy或者买
  出售金条      sell或者卖
  查询寄存金条  check或者查
  收购宝石      dang或者当
  兑换宝石      exchange或者兑换

宝石收购价格如下：
  地宝石        三两黄金
  山宝石        八两黄金
  水宝石        二十两黄金
  风宝石        六十两黄金
  雷宝石        二根金条  
  火宝石        五根金条  
  泽宝石        十五根金条  
  天宝石        四十根金条  
月魄宝石基础价格之上三倍，日魂宝石基础价格之上九倍。

宝石兑换：
  火泽天三类宝石兑换成低级宝石为1个换2个
  山水风雷四类宝石兑换成低级宝石为2个换3个，不接受奇数个数的兑换。
  命令格式:exchange 数量 宝石类型
TEXT;
}
