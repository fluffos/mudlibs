// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** i3chan.c -- Intermud channel administration
**
** 950630, Deathblade: created
*/

#include <mudlib.h>

void std_handler(string str);
varargs void modal_simple(function input_func, int secure);
varargs void modal_func(function input_func, mixed prompt_func, int secure);

#define PROMPT_I3CHAN   "(AdmTool:i3chan) [larmq?] > "


private nomask void write_i3chan_menu()
{
/*
    write("Administration Tool: Intermud channel administration\n"
          "\n"
          "    l        - list owned channels\n"
          "    a        - add owned channel\n"
          "    r <name> - remove owned channel\n"
          "\n"
          "    m        - main menu\n"
          "    q        - quit\n"
          "    ?        - help\n"
          "\n"
          );
*/
    write("管理工具：Intermud 频道管理。\n"
          "\n"
          "    l        - 所拥有的频道列表\n"
          "    a        - 增加拥有的频道\n"
          "    r <名称> - 删除拥有的频道\n"
          "\n"
          "    m        - 主选单\n"
          "    q        - 退出\n"
          "    ?        - 帮助\n"
          "\n"
          );
                     
}

private nomask void list_channels()
{
    mapping chanlist = IMUD_D->query_chanlist();

    chanlist = filter_mapping(chanlist,
                              (: $(chanlist)[$1][0] == mud_name() :));

    //write("Owned Channels:");
    write("所拥有的频道：");
    if ( sizeof(chanlist) == 0 )
    {
        //write("    <none>\n");
        write("    <无>\n");     
        return;
    }

    write(implode(({ "" }) + keys(chanlist),
                  (: $1 + sprintf("    %s/%s\n", $2,
                                  $(({"unrestricted",
                                          "restricted",
                                          "filtered"}))[$(chanlist)[$2][1]])
                   :)));
}

private nomask void rcv_channel_type(string channel_name, string str)
{
    if ( str == "" )
        return;

}

private nomask void rcv_channel_name(string str)
{
    str = lower_case(trim_spaces(str));

    if ( str == "" )
        return;

    if ( IMUD_D->query_chanlist()[str] )
    {
        //write("** That channel already exists.\n");
        write("** 这个频道早已存在。\n");
        return;
    }

    IMUD_D->add_channel(str);
}

private nomask void add_channel()
{
    //write("New channel name? ");
    write("新频道名称？");
    modal_simple((: rcv_channel_name :));
}

private nomask void remove_channel(string channel_name)
{
    mapping chanlist = IMUD_D->query_chanlist();

    channel_name = lower_case(channel_name);
    if ( undefinedp(chanlist[channel_name]) )
    {
        //write("** That channel does not exist.\n");
        write("** 这个频道并不存在。\n");
        return;
    }

    IMUD_D->remove_channel(channel_name);
}

private nomask void receive_i3chan_input(string str)
{
    string name;

    sscanf(str, "%s %s", str, name);

    switch ( str )
    {
    case "l":
        list_channels();
        break;

    case "a":
        add_channel();
        break;

    case "r":
        remove_channel(name);
        break;

    case "?":
        write_i3chan_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

protected nomask void begin_i3chan_menu()
{
    if ( !check_privilege(1) )
    {
        //write("Sorry... admin only.\n");
        write("对不起，只对大神开放。\n");
        return;
    }
    modal_func((: receive_i3chan_input :), PROMPT_I3CHAN);
    write_i3chan_menu();
}
