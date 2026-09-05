// tune.c

#include <ansi.h>
inherit F_CLEAN_UP;

varargs string show_tune(string *tuned_ch, string* tune_list, int flag)
{
  mapping ch_name=(["rw":HIY "〖任务〗"NOR, "jh":HIW "〖江湖〗"NOR, "bd":HBMAG+HIG "〖本地〗"NOR, "qy":HBMAG+HIC "〖区域〗"NOR,"qq":WHT "〖北侠QQ群〗"NOR, 
                    "chat":HIC "〖闲聊〗"NOR, "group":HIG "〖帮派〗"NOR, "rumor":HIM "〖谣言〗"NOR, "mp":GRN "〖门派〗"NOR,
                    "tt":HBCYN+HIY "〖队伍〗"NOR, "jy": HBGRN+HIW "〖交易〗"NOR, "helpme": HIW "〖求助〗"NOR, "baowei":HIY "〖任务〗"NOR,
                    "dasong":HIY "〖任务〗"NOR, "pm":HBGRN+HIW "〖交易〗"NOR, "sys":HIR "〖系统〗"NOR, "sys_misc":HIC "〖杂项〗"NOR, "wiz":BBLU+HIW "〖巫师〗"NOR]);
  int lp;
  string result;
  
  if ( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
    tuned_ch=({});
  
  if ( flag )
  {
    result=HIG"目前你的频道使用情况如下：\n"NOR;
  
    for(lp=0;lp<sizeof(tune_list);lp++)
      if ( member_array(tune_list[lp], tuned_ch)>=0 )
        result+=sprintf("%20s〖"GRN"开"NOR"〗\n", COLOR_D->format_string(ch_name[tune_list[lp]]+"("+tune_list[lp]+")", 20));
      else
        result+=sprintf("%20s〖"RED"关"NOR"〗\n", COLOR_D->format_string(ch_name[tune_list[lp]]+"("+tune_list[lp]+")", 20));
  }
  else
    result="";
  
  if ( sizeof(tuned_ch)>0 )
    result+=HIC"你现在打开的频道：" + implode(tuned_ch, ", ") + "。\n"NOR;
  else
    result+=HIC"你现在并没有打开任何频道。\n"NOR;
  
  if ( flag )  
    result+=HIR"\n其中江湖和任务两个频道只能接听消息，baowei、dasong、pm为旧频道编号，只供接听消息用。\n"NOR; 
  return result;
}

int main(object me, string arg)
{
  string *tuned_ch;
  string *wiz_ch=({"sys", "sys_misc", "wiz"});
  string *usr_ch=({"rw","jh","bd","qy","qq","chat","group","rumor","mp","tt","jy","helpme","baowei","dasong","pm"});


  tuned_ch = me->query("channels");
  if( !arg ) {
    if ( wizardp(me) )
      write( show_tune(tuned_ch, wiz_ch+usr_ch, 1) );
    else
      write( show_tune(tuned_ch, usr_ch, 1) );
    return 1;
  }
  
  if (arg == "all")
  {
    tuned_ch = ({});
    me->set("channels",tuned_ch);
    write("关闭所有频道。\n");
    if ( wizardp(me) )
      write( show_tune(tuned_ch, wiz_ch+usr_ch) );
    else
      write( show_tune(tuned_ch, usr_ch) );
    return 1;
  }
  if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
    write("关闭 " + arg + " 频道。\n");
    tuned_ch -= ({ arg });
    me->set("channels", tuned_ch);
    if ( wizardp(me) )
      write( show_tune(tuned_ch, wiz_ch+usr_ch) );
    else
      write( show_tune(tuned_ch, usr_ch) );
    
    return 1;
  } else {
    if ( ( wizardp(me) && member_array( arg, usr_ch+wiz_ch )==-1 ) ||
         ( !wizardp(me) && member_array( arg, usr_ch )==-1 ) )
      return notify_fail("目前该频道并未开放。\n");
        
    tuned_ch += ({ arg });
    me->set("channels", tuned_ch);
    write("打开 " + arg + "频道。\n");
    if ( wizardp(me) )
      write( show_tune(tuned_ch, wiz_ch+usr_ch) );
    else
      write( show_tune(tuned_ch, usr_ch) );
      
    return 1;
  }
}

int help(object me)
{
  write(@HELP
指令格式：tune [<频道名称>]

这个指令让你打开或者关闭某一个频道，如果没有指定频道名称，就会列出
你目前收听中的频道，如果指定了频道，原来收听中的就会关掉，反之打开。

要对一个频道讲话，只要用：

<频道名称> <讯息> ....

例子：
  chat hello everyone!
  
你可以用 help channel 查询目前有哪些频道可以收听。
打tune all可以关闭所有频道。

see also : shout
HELP
  );
  return 1;
}
