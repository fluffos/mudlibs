// 好友指令  by Wilfred@DS  2000/12/6

#include <ansi.h>

inherit F_CLEAN_UP;

void ft_ob(string str);
void ft_list();
void ft_tune();
void ft_talk(string str);

int main(object me, string arg)
{
  string str, index;
  if(!arg) arg = "...";
  if(sscanf(arg,"%s %s",index,str) != 2) index = arg;
  switch(index)
  {
    case "-ob"   : ft_ob(str);    break;
    case "-list" : ft_list();     break;
    case "-tune" : ft_tune();     break;
    default      : (str) ? ft_talk(index+" "+str) : ft_talk(index);
  }
  return 1;
}

void ft_ob(string str)
{
  string *ft;
  int i;
  object ob;

  ft = this_player()->query("friend");
  if( pointerp(ft) && member_array(str, ft) != -1 )
  {
    ft -= ({ str });
    write(HIC+str+" 己從好友名單中刪除!\n"NOR);
  }
  else
  {
    if(sizeof(ft) > 19)
    {
      write("抱歉, 你己設了太多好友, 請先整理你的好友名單.\n");
      return;
    }
    if(!ft) ft = ({ str });
      else ft += ({ str });
    write(HIC+str+" 己加入好友名單!\n"NOR);
  }
  this_player()->set("friend", ft);
  this_player()->save();

  return;
}

void ft_list()
{
  string *ft, *t_ft, temp, msg = "";
  int i;
  object ob;

  ft = this_player()->query("friend");

  if(sizeof(ft) < 1) msg = HIR"你目前尚未設定好友名單\n"NOR;

  for(i=0 ; i<sizeof(ft) ; i++)
  {
    if( ob = find_player(ft[i]) )
    {
      t_ft = ob->query("friend");
      if( pointerp(t_ft) && member_array(this_player()->query("id"), t_ft) != -1 )
        temp = "* "+ft[i];
      else temp = "? "+ft[i];
      if(wizardp(ob)) temp = ft[i];
    }
    else temp = ft[i];
    msg += sprintf("%-15s%s", temp, ( i % 5 == 4 ) ? "\n" : "");
  }
  msg += "\n";

  write(NOR"你的好友名單為: (星號為正在連線中, 問號代表此人並無將你設為好友)\n"+
  "--------------------------------------------------------------------------\n"NOR);
  this_player()->start_more(msg);
  (this_player()->query("ft_tune")) ? msg = "關閉" : msg = "開啟"; 
  write("\n你的好友公開頻道是"+msg+"的\n");
  return;
}

void ft_tune()
{
  if(this_player()->query("ft_tune"))
  {
    this_player()->set("ft_tune",0);
    write("開啟好友公開頻道.\n");
  }
  else
  {
    this_player()->set("ft_tune",1);
    write("關閉好友公開頻道.\n");
  }
  this_player()->save();
  return;
}

void ft_talk(string str)
{
  string *ft, *t_ft;
  object ob;
  int i;

  if(this_player()->query("ft_tune"))
  {
    this_player()->set("ft_tune",0);
    write("開啟好友公開頻道.\n");
  }

  ft = this_player()->query("friend");

  for(i=0 ; i<sizeof(ft) ; i++)
  {
    if( ob = find_player(ft[i]) )
    {
      t_ft = ob->query("friend");
      if( pointerp(t_ft) && member_array(this_player()->query("id"), t_ft) != -1 )
      {
        if(!ob->query("ft_tune"))
          tell_object(ob,HIW"【好友】"+this_player()->name_id(1)+"﹕"+str+"\n"NOR);
      }
    }
  }
  write(HIW"【好友】"+this_player()->name_id(1)+"﹕"+str+"\n"NOR);
  return;
}

int help(object me)
{
  write(@HELP
●指令格式﹕
           增/刪好友>      ft -ob [id]
           好友名單>       ft -list
           好友公開頻道>   ft [speaking]
           開/關好友頻道>  ft -tune

你可以利用這個指令及相關參數，其功能請看上列。

說明:
  A 設 B 為好友, 則 B 能夠在 A 設勿干擾的情況下 tell A
  A 和 B 皆互設為好友, 則 A 和 B 能接收對方來自好友頻道的訊息 

其他相關指令﹕tell, set auto_reply
HELP
);
  return 1;
}

