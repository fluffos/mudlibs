// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** money.c -- Currency administration
**
** 25-Jul-96   Valentino.    Created.
**  6-Aug-96   Valentino.    Generalized and ported to Da Bean.
*/

#include <daemons.h>
#define ADMINS "大神"
void std_handler(string str);
varargs void modal_simple(function input_func, int secure);
varargs void modal_func(function input_func, mixed prompt_func, int secure);
void do_one_arg(string arg_prompt, function fp, string arg);
void do_two_args(string arg1_prompt, string arg2_prompt,
                 function fp, string arg);
void do_three_args(string arg1_prompt, string arg2_prompt,string arg3_prompt,
                 function fp, string arg);

#define PROMPT_MONEY     "(AdmTool:currency)   [alrxmq?] > "

private nomask void write_money_menu()
{
    write("管理工具: 钱币管理\n"
          "\n"
          "    a [ar] [mat] [nic] - 增加新钱币 ["+ADMINS+"]\n"
          "    l [area]           - 钱币列表\n"
          "    r [area] [materi]  - 删除钱币 ["+ADMINS+"]\n"
          "    x [area] [amount]  - 调整兑换率 ["+ADMINS+"]\n"
          "\n"
          "    m                  - 主选单\n"
          "    q                  - 退出\n"
          "    ?                  - 帮助\n"
          "\n"
          );
}

varargs private nomask void
list_cur(string area)
{
  if (area=="") area=0;
  if (area && member_array(area,MONEY_D->query_currency_areas())==-1)
    {
      write("*** 没有定义这个区域。\n");
      return;
    }
  MONEY_D->stat_me(area,10000);
}

varargs private nomask void
add_cur(string area,string material,string nickname)
{
  if (!stringp(nickname) || !stringp(material) || !stringp(nickname))
    {
      write("*** 给出参数错误。\n");
      return;
    }
  MONEY_D->add_currency(area,material,nickname);
  write("增加钱币成功。\n");
}

varargs private nomask void
adj_ex(string area,int amount)
{
  if (!stringp(area) || !intp(amount))
    {
      write("*** 给出参数错误。\n");
      return;
    }
  if (MONEY_D->adjust_exchange_rate(area,amount))
    write("增加钱币成功。\n");
  else
    write("没有改动。\n");
}

varargs private nomask void
rem_cur(string area,string material)
{
  if (!stringp(area) || !stringp(material))
    {
      write("*** 给出参数错误。\n");
      return;
    }
  write("准备删除...\n");
  MONEY_D->remove_currency(area,material);
}

private nomask void receive_money_input(string str)
{
  int i;
  string arg,arg2;
  
  sscanf(str,"%s %s",str,arg);
  switch(str)
    {
    case "?":
      write_money_menu();
      break;
    case "a":
      if (!adminp(this_body()))
        {
          write("对不起，只对"+ADMINS+"开放。\n");
          return;
        }
      do_three_args("区域名称？","材料名称？","什么名字？",
                    (:add_cur:),arg);
      break;
    case "r":
      if (!adminp(this_body()))
        {
          write("对不起，只对"+ADMINS+"开放。\n");
          return;
        }
      do_two_args("区域名称？","材料名称？",(:rem_cur:),arg);
      break;
    case "x":
      if (!adminp(this_body()))
        {
          write("对不起，只对"+ADMINS+"开放。\n");
          return;
        }
      sscanf(arg,"%s %d",arg,i);
      adj_ex(arg,i);
      break;
    case "l":
      do_one_arg("区域名称？[预设为所有区域] ",(:list_cur:),arg);
      break;
    default:
      std_handler(str);
      break;
    }
}

protected nomask void begin_money_menu()
{
  modal_func((: receive_money_input :), PROMPT_MONEY);
  write_money_menu();
}



