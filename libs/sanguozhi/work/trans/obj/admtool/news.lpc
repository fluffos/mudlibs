// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** news.c -- News administration
**
** 950715, Rust: created
*/

#include <mudlib.h>
#define PROMPT_NEWS     "(AdmTool:news)   [larmq?] > "

void std_handler(string str);
varargs void modal_simple(function input_func, int secure);
varargs void modal_func(function input_func, mixed prompt_func, int secure);
void receive_news_input(string);

#define PROMPT_NEWS     "(AdmTool:news)   [larmq?] > "

private nomask void write_news_menu()
{
/*
    write("Administration Tool: news administration\n"
          "\n"
          "    l        - list newsgroups\n"
          "    a        - add a newsgroup\n"
          "    r <name> - remove a newsgroup\n"
          "\n"
          "    m        - main menu\n"
          "    q        - quit\n"
          "    ?        - help\n"
          "\n"
          );
*/
    write("管理工具：新闻管理\n"
          "\n"
          "    l        - 新闻组列表\n"
          "    a        - 增加新闻组\n"
          "    r <名称> - 删除新闻组\n"
          "\n"
          "    m        - 主选单\n"
          "    q        - 退出\n"
          "    ?        - 帮助\n"
          "\n"  
          );    
}

private nomask void list_newsgroups()
{
    string* grouplist = NEWS_D->get_groups();

    if ( sizeof(grouplist) == 0 )
    {
        //write("    <none>\n");
        write("         <无>\n");
        return;
    }
    grouplist = sort_array(grouplist, 1);
    more(grouplist);

}

private nomask void rcv_newsgroup_name(string str)
{
    str = lower_case(trim_spaces(str));

    if ( str == "" )
        return;

    if ( member_array(str,NEWS_D->get_groups()) != -1)
    {
        //write("** That group already exists.\n");
        write("** 这个新闻组早已存在了。\n");
        return;
    }
    NEWS_D->add_group(str);
    printf(//"** Group '%s' added.\n",
           "** 新闻组 %s 建立。\n", str);
    
    modal_func((:receive_news_input:), PROMPT_NEWS);
}

private nomask void add_newsgroup()
{
    //write("New group name? ");
    write("新的新闻组名称？");
    modal_simple((: rcv_newsgroup_name :));
}

private nomask void remove_newsgroup(string group_name)
{
    string* grouplist = NEWS_D->get_groups();
    
    if(!group_name)
      {
        //write("** no group name supplied.\n");
        write("** 缺少新闻组名称。\n");
        return;
      }
    group_name = lower_case(group_name);
    if ( member_array(group_name, grouplist) == -1 )
    {
        //write("** That newsgroup does not exist.\n");
        write("** 这个新闻组并不存在。\n");
        return;
    }

    NEWS_D->remove_group(group_name);
    printf(//"** Group '%s' removed.\n",
           "** 新闻组 %s 删除了。\n", group_name);
}

private nomask void receive_news_input(string str)
{
    string name;

    sscanf(str, "%s %s", str, name);

    switch ( str )
    {
    case "l":
        list_newsgroups();
        break;

    case "a":
        add_newsgroup();
        break;

    case "r":
        remove_newsgroup(name);
        break;

    case "?":
        write_news_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

protected nomask void begin_news_menu()
{
    if( !check_privilege(1) )
    {
        //write("Sorry... admin only.\n");
        write("对不起，只对大神开放。\n");
        return;
    }
    modal_func((: receive_news_input :), PROMPT_NEWS);
    write_news_menu();
}
