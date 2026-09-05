#include <ansi.h>
#include <identify.h>
#include "/quest/changan/quest.h"
#include "/quest/changan/reward.h"

//查询当前爵位的兑奖服务列表
string list_reward(int level)
{
  string title, lists, *slist;
  int len, lp;
  
  title=TITLE_RANK->query_rank(level);
  len=strwidth(COLOR_D->uncolor(title));
  lists=CYN"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  if ( len==16 )
    lists+=CYN"~~~~~~~~~~~~~~~~~~~~"+title+HIG"可兑换服务列表"NOR+CYN"~~~~~~~~~~~~~~~~~~~~\n"NOR;
  else
    lists+=CYN"~~~~~~~~~~~~~~~~~~"+title+HIG"可兑换服务列表"NOR+CYN"~~~~~~~~~~~~~~~~~~\n"NOR;
  lists+=CYN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  lists+=CYN"服务ID    服务名称                      服务价格            \n"NOR;
  lists+=CYN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  
  slist=title_slist["LV"+level];
  for(lp=0;lp<sizeof(slist);lp++)
    lists+=sprintf("%-10s%-30s%-30s\n", slist[lp], COLOR_D->format_string(service_lists[slist[lp]]["name"],30), service_lists[slist[lp]]["price_desc"]);
  lists+=CYN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  lists+=HIG"查看服务的详细信息请使用命令list 服务ID；\n"NOR;
  lists+=HIG"兑换服务请使用命令duihuan 服务ID;\n"NOR;
  lists+=CYN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  return lists;
}

//查询某一种服务的详细服务信息
string list_detail(string sid)
{
  string detail;
  object item;
  mapping serv;
  mixed *flist;
  int lp;
  
  serv=service_lists[sid];
  if ( !serv )
    return "无此服务信息。\n";
  
  detail=CYN"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  detail+=sprintf(CYN"\n~~~~~~~~~~服务名称：%-40s"NOR+CYN"~~~~~~~~~~\n"NOR, COLOR_D->format_string(service_lists[sid]["name"],40));
  detail+=CYN"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  detail+=YEL"服务详细描述：\n"+service_lists[sid]["desc"]+NOR;
  detail+=CYN"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
  if ( serv["goods_type"]=="attribute"||
       serv["goods_type"]=="item" )
    return detail;
  
  if ( serv["goods_type"]=="equip" ||
       serv["goods_type"]=="rent" )
  {
    detail+=YEL"装备详细信息：\n";
    flist=serv["fitem"];
    for ( lp=0; lp<sizeof(flist); lp++ )
    {
      if ( stringp(flist[lp]) )
      {
        item=new(flist[lp]);
        detail+=item->identify(IL_FULL);
        destruct(item);
      }
      else if ( arrayp(flist[lp]) )
      {
        item=new(flist[lp][0]);
        //目前仅支持fitem中字符串列表定义的物件元素为2或者3的情况，分别为仅带一个初始化函数或者一个初始化函数加一个参数
        if ( sizeof(flist[lp])==2 )
          call_other(item, flist[lp][1]);
        else
          call_other(item, flist[lp][1], flist[lp][2]);
        
        detail+=item->identify(IL_FULL);
        destruct(item);
      }
    }
    detail+=CYN"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR;
    return detail;
  }
  
  return "未知的服务类型。\n";
}

//获得某一种服务
int get_reward(int level, string sid, object player)
{
  string *slist, *klist;
  mapping serv;
  int price, lp;
  object item;
  
  slist=title_slist["LV"+level];
  if ( !sizeof(slist) )
  {
    tell_object(player, "你目前的爵位上还未开放任何服务。\n");
    return 1;
  }
  
  if ( member_array(sid, slist)<0 )
  {
    tell_object(player, "你目前的爵位上还未提供此服务。\n");
    return 1;
  }
  
  serv=service_lists[sid];
  price=serv["price"];
  if ( player->query("changan/ext_points")<price )
  {
    tell_object(player, "你目前的爵位上的兑奖积分不足，不足以兑换此服务。\n");
    return 1;
  }
  
  //limit_min和limit_max限制属性判定，limit_min是服务对被服务者能力的最低要求
  //limit_max是服务对被服务者能力的最高要求
  if ( serv["limit_min"] &&
       mapp(serv["limit_min"]))
  {
    klist=keys(serv["limit_min"]);
    for(lp=0;lp<sizeof(klist);lp++)
    {
      if ( player->query(klist[lp])<serv["limit_min"][klist[lp]] )
      {
        tell_object(player, "你现在的能力还不足以兑换此服务。\n");
        return 1;
      }
    }
  }
  
  if ( serv["limit_max"] &&
       mapp(serv["limit_max"]))
  {
    klist=keys(serv["limit_max"]);
    for(lp=0;lp<sizeof(klist);lp++)
    {
      if ( player->query(klist[lp])>serv["limit_max"][klist[lp]] )
      {
        tell_object(player, "你现在的能力已经远超此服务所能提供的范畴了。\n");
        return 1;
      }
    }
  }
  
  if ( serv["goods_type"]=="attribute" )
  {
    player->add("changan/ext_points", -price);
    player->add(serv["attribute"], serv["value"]);
    tell_object(player, "你支付了"+chinese_number(price)+"点积分，获得了朝廷提供的福利〖"+serv["name"]+"〗！\n");
    return 1;
  }
  
  if ( serv["goods_type"]=="item" ||
       serv["goods_type"]=="equip" ||
       serv["goods_type"]=="rent" )
  {
    player->add("changan/ext_points", -price);
    item=new(serv["item"]);
    item->set("file", serv["fitem"]);
    item->set("owner", player->query("id"));
    if ( serv["goods_type"]=="rent" )         //租借模式下设置租借日期
      item->set("rent_time", time()+86400 );
    item->move(player);
    tell_object(player, "你支付了"+chinese_number(price)+"点积分，获得了朝廷提供的福利〖"+serv["name"]+"〗！\n");
    if ( serv["goods_type"]=="rent" )
      tell_object(player, "福利〖"+serv["name"]+"〗将会在"+ctime(time()+86400)+"自动到期。\n");
    tell_object(player, "你拿着"+item->name()+"去库房哪里领取物资。\n");
    return 1;
  } 
}