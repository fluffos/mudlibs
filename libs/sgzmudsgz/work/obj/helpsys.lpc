// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** helpsys.c
**
** Standard help system object.  Interfaces with the Help Daemon to
** provide a complete help system to the user.  This object also acts
** as a modal input object via the standard input system functions.
**
** 26-OCT-94.  Created.  Deathblade.
** 14-APR-95   Wirehead added memory for old topcs vs. new ones.
*/

#include <mudlib.h>
#include <daemons.h>
#include <log.h>

inherit M_ACCESS;
inherit M_INPUT;


private nosave string * topic_files;
private nosave string * lines;
private nosave int      cur_line;
private nosave mapping  directives;

/* hack. */
private nosave int      i;

nomask void display_topics(mixed);
private nomask void receive_choice(string arg);
private nomask void receive_more(string arg);
private nomask void receive_topic(string arg);

private nomask string query_prompt()
{
    if ( topic_files )
    {
        return sprintf(//"\nWhich topic to display? [1-%d,?]: ",
                       "\n显示哪个标题？[1-%d,?]：",
                       sizeof(topic_files));
    }

    if ( cur_line )
    {
        return sprintf(//"--More--(%d%%) [?]: "
                       "--下面还有--(%d%%) [?]: " , 100 * cur_line / sizeof(lines));
    }

    return //"\nHelp topic? [?]: ";
           "\n关于什么标题？[?]: ";
}

private nomask void quit_help()
{
    modal_pop();
    destruct(this_object());
}

private nomask int f_parse(string s)
{
    string * x;

    if ( s[0..1] != "$$" )
        return 1;

    if ( s[2] == '#' )
        return 0;

    if ( member_array(':', s) == -1 )
    {
        directives[trim_spaces(s[2..])] = 1;
    }
    else
    {
        x = explode(s[2..], ":");
        directives[trim_spaces(x[0])] = trim_spaces(x[1]);
    }
    
    return 0;
}

private nomask string last_component(string fname) {
    return (explode(fname, "/") - ({ "" }))[<1];
}

private nomask void parse_directory(string fname) 
{
    string * files = get_dir(fname + "*") - ({ ".", ".." });
    string topic = last_component(fname);
    
    cur_line = 0;
    directives = ([]);

    lines = ({"Help topics available under the general topic '" + topic + "':"}) +
        map_array(files, (: "\t" + last_component($1) :));
}

private nomask void parse_file(string fname)
{
    cur_line = 0;
    directives = ([ ]);
    
    lines = explode(read_file(fname), "\n");
    lines = filter_array(lines, (: f_parse :));

    if ( directives["see"] )
    {
//### make this a bit more "in-your-face" ??
        lines += ({ "", //"See also: "
                        "参见：" + directives["see"] });
    }
}

private nomask void print_lines()
{
    int count;

    count = this_body()->query_shell_ob()->get_variable("MORE") || 20;
      if(!intp(count)) count =to_int(count);  
    if ( sizeof(lines) - cur_line < count )
        count = sizeof(lines) - cur_line;

    write(implode(lines[cur_line .. (cur_line + count - 1)], "\n") + "\n");

    if ( (cur_line += count) == sizeof(lines) )
    {
        cur_line = 0;
    }
}

/*
** present_topic()
**
** Present a topic to the user
*/
private nomask void present_topic(string fname)
{
    switch (file_size(fname)) {
    case -1:
        lines = ({ "这个帮助文件已经不存在了。", "它的索引在下次 help_d 更新时就会消失。" });
        break;
    case -2:
        parse_directory(fname);

        write("\n");
        print_lines();
        break;
    default:
        parse_file(fname);

        write("\n");
        print_lines();
    }
    /*
    ** The current receive function is unknown on entry to this function.
    ** Make sure it is set correctly.  cur_line will be zero if print_lines()
    ** ends up printing everything.
    */
    modal_func(cur_line ? (: receive_more :) : (: receive_topic :));
}

private nomask string format_choice(string choice)
{
    return sprintf("%2d. %s", ++i, choice);
}

private nomask void lookup_topic(string topic)
{
    string * files;

    files = HELP_D->find_topic(topic);
    if ( sizeof(files) == 0 )
    {
        //write("\nSorry, there is no help on that topic (try: topics)\n\n");
        write("\n对不起，没有关于那个标题的帮助(用 topics 来获取这方面的信息)\n\n");
        LOG_D->log(LOG_HELP_MISS,
                   sprintf("%s: %s\n", this_user()->query_userid(), topic));
    }
    else if ( sizeof(files) == 1 )
    {
        present_topic(files[0]);
    }
    else
    {
//### need to devise a better scheme for presenting these.
//### preferably, we can use the topic's "parent".  if one
//### or more topics don't have parents, though... ??
//### not to mention that we don't have their parents until
//### we read the files.
        
        /* ack. must use a global to get the index to work */
        i = 0;

        write(//"There are multiple help files for \"" + topic + "\"\n" +
              //"Please choose one:\n\n" +
              "有多个关于 " + topic + " 的帮助文件，请选择一个：\n\n" +
              implode(map_array(files, (: format_choice :)),
                      "\n") + "\n");
              
        topic_files = files;
        modal_func((: receive_choice :));
    }
}

private nomask void receive_choice(mixed arg)
{
    if(arg == -1)
      destruct(this_object());

    if ( arg )
        arg = trim_spaces(arg);

    if ( !arg || arg == "" || arg == "q" )
    {
        quit_help();
    }
    else if ( arg == "?" )
    { /*
        write("\nThe following commands are available:\n\n" +
              "             q : quit using the help system.\n" +
              "             ? : this help.\n\n" +
              "  <topic name> : will display help for the new topic.\n\n"
              );
      */
      write("\n有下列命令供使用：\n\n"
            "           q : 退出帮助系统。\n"
            "           ? : 本帮助。\n\n"
            "      <标题> : 显示关于指定标题的帮助。\n\n"
            );
    }
    else if ( to_int(arg) > 0 )
    {
        int which;

        which = to_int(arg) - 1;
        if ( which >= sizeof(topic_files) )
        {
            printf(//"\nPlease type a number between 1 and %d.\n",
                   "\n请在 1 到 %d 之间选择一个数字。\n",
                   sizeof(topic_files));
        }
        else
        {
            present_topic(topic_files[which]);
            topic_files = 0;
        }
    }
    else
    {
        topic_files = 0;
        lookup_topic(arg);
    }
}

private nomask void receive_more(mixed arg)
{
    if (arg == -1)
      destruct(this_object());
    if ( arg )
        arg = trim_spaces(arg);

    if ( arg == "q" )
    {
        quit_help();
    }
    else if ( arg == "?" )
    {/*
        write("\nThe following commands are available:\n\n" +
              "             q : quit using the help system.\n" +
              "             ? : this help.\n\n" +
              "      <return> : will display more of this help topic.\n" +
              "  <topic name> : will display help for the new topic.\n\n"
              );
     */
      write("\n有下列命令供使用：\n\n"
            "           q : 退出帮助系统。\n"
            "           ? : 本帮助。\n\n"
            "      <回车> : 显示更多的信息。\n" 
            "      <标题> : 显示关于指定标题的帮助。\n\n"
            );
    }
//    else if ( arg == "topics" )
//    {
//      display_topics();
//    }
    else if ( !arg || arg == "" )
    {
        print_lines();
        if ( cur_line == 0 )
        {
            modal_func((: receive_topic :));
        }
    }
    else
    {
        /*
        ** We will ignore the lookup and continue the "more" process or
        ** a topic will be found and we'll switch to that one.
        */
        lookup_topic(arg);
    }
}

private nomask void receive_topic(mixed arg)
{
    if (arg == -1)
      destruct(this_object());

    if ( arg )
        arg = trim_spaces(arg);

    if ( !arg || arg == "" || arg == "q" )
    {
        quit_help();
        return;
    }
    if ( arg == "?" )
        arg = "help";

    lookup_topic(arg);
}

nomask void begin_help(string topic)
{
    if ( !topic || topic == "" )
        topic = "topics";

    modal_push((: receive_topic :), (: query_prompt :));
    lookup_topic(topic);
}



// display_topic_columns and display_topics by Wirehead

private nomask void display_topic_columns(string *files, string header)
{
    string name;
    int i;
    int n = sizeof(files);

    files = map_array(files, (: explode($1, "/")[<1] :) );
    write(header + "\n\n");
    for (i = 0; i < (n/2) + 1; i++) {
        if ((i == n/2) && (n % 2)) {
            printf("\t%-20s\n", files[i]);
            break;
        }
        printf("\t%-20s%-20s\n", files[i], files[i + n/2]);
    }
}

// uses this_body()->query_help_topic() to determine what has been
// read recently.
nomask void display_topics(string *arr)
{
    string *new_stuff, *old_stuff;

    old_stuff = filter_array(arr,
                             (: stat($1)[1] <= $(this_body())->query_help_topic($1) :));

    new_stuff = arr - old_stuff;
    if (sizeof(new_stuff)) display_topic_columns(new_stuff, "未读过的标题");//"Unread topics:");
    if (sizeof(old_stuff)) display_topic_columns(old_stuff, "已读过的标题");//"Topics already read:");
}

private create() {
    set_privilege(1);
}            
