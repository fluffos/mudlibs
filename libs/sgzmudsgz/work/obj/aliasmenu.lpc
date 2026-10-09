// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** aliasmenu.c -- alias manipulation menu
**
** 950807, Deathblade: Created from Rust's alias.c module.
*/

#include <mudlib.h>
#include <classes.h>

inherit M_INPUT;

inherit CLASS_ALIAS;

private nosave object shell_ob; /* which shell ob we're editing aliases for */
private nosave string * display_menu_options;
private nosave class alias new_alias_in_progress;
private nosave string new_alias_name;
private nosave int num_defaults;
private nosave int default_index;


/*
**  From here on lies a menu interface to aliases.
**  It's probably a bit messy. =/
**  (Written in a hurry, unfortunatly.)
*/

void input_from_main_menu(string);
string main_menu_prompt();
void display_main_menu();
protected void init_alias_editor();

nomask void begin_menu(object for_shell_ob)
{
    shell_ob = for_shell_ob;
    modal_push((: input_from_main_menu :), (: main_menu_prompt :));
    display_main_menu();
}

private void goto_main_menu()
{
    display_main_menu();
    modal_func((: input_from_main_menu :), (: main_menu_prompt :));
}

private void quit_alias_editor()
{
//    write("Exiting alias editor.\n");
    write("退出 alias 编辑器。\n");
    modal_pop();
    destruct(this_object());
}

private void display_main_menu()
{
/*
    write("Alias Editor\n\n"
          "l - list all aliases\n"
          "s - show one alias\n"
          "a - add or adjust an alias\n"
          "r - remove an alias\n"
          "\n"
          "q - quit\n");
*/
    write("Alias 编辑器\n\n"
          "   l         - 列出所有的 aliases\n"
          "   s         - 显示一个 alias\n"
          "   a         - 增加或修改一个 alias\n"
          "   r         - 删除一个 alias\n"
          "\n"
          "   q         - 退出\n");
}

private string main_menu_prompt()
{
    return "[lsarq] ";
}

varargs nomask void display_one_alias(string alias_name, object shell_to_use)
{
    class alias this_alias;
    string output = "";
    int i;

    if ( !shell_to_use )
        shell_to_use = shell_ob;

    this_alias = shell_to_use->query_one_alias(alias_name);
    if(!this_alias)
    {
        printf(//"You have no alias for %s.\n"
               "你并未设定 %s 这样的 alias。\n" , alias_name);
        return;
    }

    output += sprintf("Alias: %-15s 展开: %s\n",
                      alias_name, this_alias->template);

    if(sizeof(this_alias->defaults) > 1 || this_alias->defaults[0] != "")
    {
        output += sprintf("\t预设值:\n"
                          "  $*: %s\n", this_alias->defaults[0]);
        if(sizeof(this_alias->defaults) > 1)
            for(i=1;i<sizeof(this_alias->defaults);i++)
                output +=sprintf("  $%d: %s\n", i, this_alias->defaults[i]);
    }

    if ( shell_to_use->is_xalias(alias_name) )
        output += //"You don't have to type a space after you type this alias.\n\n";
                  "你不必在输入完 alias 之后再键入空格。\n\n";
    write(output);
}


private void display_all_aliases()
{
    string * names;
    string a;
    class alias val;
    string output;
    int i;

    output = sprintf("Alias:%9s展开:%29s预设:\n","","");
    output += sprintf("%77'-'s\n", "");

    names = sort_array(shell_ob->query_alias_names(), 1);
    foreach ( a in names )
    {
        val = shell_ob->query_one_alias(a);

        output += sprintf("%-14s %-38s ", a, val->template);
        if(sizeof(val->defaults) == 1 && val->defaults[0] == "")
            output += "\n";
        else
        {
            output += "$*: " + val->defaults[0] + "\n";
            for(i=1;i<sizeof(val->defaults);i++)
                output += sprintf("%54s$%d: %s\n","",i,val->defaults[i]);
        }
    }

    more(output);
}


private void process_display_alias_menu_choice(string input)
{
    int index;

    if(input=="q")
    {
        quit_alias_editor();
        return;
    }
    if(!sscanf(input,"%d",index) || index < 1 || 
       index > sizeof(display_menu_options))
    {
        //write("Invalid selection.\n");
        write("非法选项。\n");
        return;
    }
    display_one_alias(display_menu_options[index-1]);
    display_menu_options = 0;
    goto_main_menu();
}

private void display_alias_menu()
{
    int i;

    display_menu_options = sort_array(shell_ob->query_alias_names(), 1);
    //write("Select alias to display:\n");
    write("请选择你要显示的 alias：\n");
    for(i=0; i<sizeof(display_menu_options); i++)
    {
        printf("%-4d%-6s  ", i+1, display_menu_options[i]);
        if(i%5==4)
            write("\n");
    }
    write("\n");
    modal_func((:process_display_alias_menu_choice:), "[#q] ");
}

private void display_alias(string s)
{
    string* matches;
    int i;

    matches = M_COMPLETE->complete(s, shell_ob->query_alias_names());

    switch(sizeof(matches))
    {
    case 0:
        //write("No such alias.\n");
        write("无此 alias。\n");
        goto_main_menu();
        return;

    case 1:
        display_one_alias(matches[0]);
        goto_main_menu();
        return;

    default:
        //write("Possible completions are:\n");
        write("符合的有：\n");
        matches = sort_array(matches,1);
        for(i = 0; i<sizeof(matches); i++)
            printf("  %-4d%s\n",i,matches[i]);
        display_menu_options = matches;   
        modal_func((:process_display_alias_menu_choice:),
                   //"Select one by number, or q to quit: "
                   "用数字选择，或 q 退出：");
        return;
    }
}

private string get_arg_default_prompt()
{
    return sprintf(//"What's the default for $%d (enter for none)? ", 
                   "$%d 的预设值是什么？(回车代表无)",
                   default_index + 1);
}

private void get_xverb_status(string s)
{
    if(s == "")
        return;

    switch(s[0])
    {
    case '?':
        /*
        write(
            "Do you want to be able to omit the space between the alias and the "
            "rest of\nwhat you type?  Ie, if your alias is for ', do you want "
            "to be able to do:\n'foo\nor do you want to be forced to put a space "
            "between the ' and the foo??\n");
        */
        write(
            "你希望省去 alias 和余下部分之间的空格吗？\n"
            "比如：'foo\n"
            "你要在 ' 和 foo 之间自动省去空格吗？(y/n)\n");
           
        return;
    case 'y':
        shell_ob->add_xalias(new_alias_name);
        break;
    case 'n':
        break;
    default:
        //write("Invalid response.\n");
        write("非法回答。\n");
        return;
    }
    shell_ob->add_alias_simple(new_alias_name, new_alias_in_progress);

    printf(//"Alias %s defined.\n",
           "Alias %s 定义了。\n", new_alias_name);
    goto_main_menu();
}
  

private void ask_for_xverb_status()
{
    modal_func((: get_xverb_status :), //"Allow space ommision? [yn?] "
                                       "允许省去空格吗？[yn?]" );
}

private void set_arg_default(string s)
{
    default_index++;
    new_alias_in_progress->defaults[default_index] = s;
    if(default_index == num_defaults)
    {
        ask_for_xverb_status();
    }
}

private void set_star_default(string s)
{
    new_alias_in_progress->defaults[0] = s;
    default_index = 0;
    num_defaults  = new_alias_in_progress->num_args;
    if(!num_defaults)
    {
        ask_for_xverb_status();
        return;
    }

    modal_func((: set_arg_default :), (: get_arg_default_prompt :));
}


private void new_template(string s)
{
    if(s == "")
        return;

    if(s == "?")
    {/*
        write(
            "An alias definition can change each time you use the alias:\n"
            "$1  -- Wherever you put this in your alias definition,\n"
            "       the $1 will be replaced with the first word after\n"
            "       the alias when you use the alias.\n"
            "       You can do the same with $2, $3, $4, ad infinitum.\n"
            "       If you have $1 in your alias definition, but don't\n"
            "       provide a first argument when you use an alias,\n"
            "       the default value for $1 is used.  You can set the\n"
            "       default value when you are done with the alias definition.\n\n"
            "       Example:  If you alias \"you're\" to:\n"
            "                  say Hey, $2, you're $1!\n"
            "       When you type:\n"
            "                  you're studly Rust\n"
            "       You'll say: \"Hey, Rust, you're studly!\"\n"
            "\n"           
            "$*  -- It's the same as $1, but it means 'everything else'. \n"
            "       Example:  If you alias \"you're\" to:\n"
            "                  say $2, you're $1!  Do you $*?\n"
            "       When you type:\n"
            "                 you're studly Rust excersise much\n"
            "   You'll say: \"Hey, Rust, you're studly!  Do you excersise much?\"\n"
            "\n"
            "Notice $* matches any number of words, whereas $1, $2, etc...\n"
            "only match one word.\n\n"
            "If you don't put a $* in your expansion, one will be automatically\n"
            "added to the end of the alias for you.\n");
      */
        write(
            "一个 alias 可以在每次扩展时产生不同的扩展结果：\n"
            "$1  -- 当你在 alias 定义中使用它时，$1 会被跟在你的 alias 后的\n"
            "       第一个参数取代。同理可推 $2 $3 $4 等。\n"
            "       如过你没有在使用这个 alias 时给出第一个参数，那么它的预\n"
            "       设值就会被采用。\n"
            "       你可以在设定 alias 后也设定 $1 等的预设值，\n\n"
            "       比如：如果你把 you're 设定为：\n"
            "             say Hey, $2, you're $1!\n"
            "       之后，当你输入：\n"
            "             your're studly Rust\n"
            "       你就会说道：Hey, Rust, you're studly!\n\n"
            "$*  -- 它和 $1 类似，它代表剩余的所有参数。\n"
            "       比如：如果你把 you're 设定为：\n"
            "             say $2, you're $1! Do you $*?\n"
            "       之后，当你输入：\n"
            "             you're studly Rost excercise much\n"
            "       你就会说道：Hey, Rust, your're studly! Do you exercise much?\n\n"
            
            "请注意 $* 代表任何数目的词汇，而 $1 $2 等只能代表一个词。\n"
            "如果你没有在你的 alias 扩展中使用 $*，它会被自动加在你的扩展之后。\n");
        return;
    }

    if(strsrch(s,"$*") == -1)
        s = s + " $*";

    new_alias_in_progress->template = s;

    new_alias_in_progress->num_args =
        max(map(explode(s[strsrch(s,"$")..],"$"), 
                function(string s){
            int d;
            sscanf(s, "%d%s",d,s);
            return d;}));

    new_alias_in_progress->defaults = 
        allocate(new_alias_in_progress->num_args+1);

    modal_func((: set_star_default :), 
               //"What's the default for $* (enter for none)? "
               "请输入 $* 的预设值：(回车表示没有)");
}


private void rcv_new_alias_name(string s)
{
    if(strsrch(s," ") != -1)
    {
        write(//"Aliases may not have spaces.  Try again.\n"
              "作为一个 alias 的名字，不允许有空格。请重新输入。\n");
        return;
    }
    if(s=="")
        return;
  
    new_alias_in_progress = new(class alias);
    new_alias_name = s;
    //write("Type in the expansion for this alias.\n");
    write("请输入这个 alias 的扩展结果：\n");
    modal_func((: new_template :), //"Expansion (? for help): "
                                   "扩展：(? 可获取帮助)");
}

  
private void cmd_adjust_alias(string s)
{
    if(strsrch(s," ") != -1)
    {
        write(//"Aliases may not have spaces.  Try again.\n");
              "作为一个 alias 的名字，不允许有空格。请重新输入。\n");
        modal_func((: rcv_new_alias_name :), //"Name of alias: "
                                             "Alias 的名字：");
        return;
    }
    if(s=="")
    {
        modal_func((: rcv_new_alias_name :), //"Name of alias: "
                                             "Alias 的名字：");
        return;
    }
    rcv_new_alias_name(s);
}

private varargs void process_remove_alias(mixed s, int not_using_menu)
{
    if ( !shell_ob->query_one_alias(s) )
    {
        printf(//"You don't have '%s' as an alias.\n"
               "你并未设定 %s 这样的 alias。\n" ,s);
    }
    else
    {
        shell_ob->remove_alias(s);
        printf(//"Alias '%s' removed.\n"
               "Alias %s 被删除了。\n", s);
    }

    goto_main_menu();
}

private void input_from_main_menu(string arg)
{
    int cmd;

    if(arg == "")
{
  quit_alias_editor();
  return;
}
    if(strlen(arg) == 1)
    {
        cmd = arg[0];
        arg = 0;
    }
    else
    {
        if(arg[1] != ' ')
        {
            //write("Invalid command.\n");
            write("非法命令。\n");
            display_main_menu();
            return;
        }
        if(strlen(trim_spaces(arg)) > 1)
            arg = arg[2..];
        else
            arg = 0;
    }
    switch(cmd)
    {
    case 'q':
        quit_alias_editor();
        return;
    case 'l':
        if( !shell_ob->query_alias_count() )
        {
            //write("You currently have no aliases defined.\n");
            write("你现在没有任何 alias。\n");
            goto_main_menu();
            return;
        }
        display_all_aliases();
        return;
    case 's':
        if( !shell_ob->query_alias_count() )
        {
            //write("You currently have no aliases defined.\n");
            write("你现在没有任何 alias。\n");
            goto_main_menu();
            return;
        }
        if(!arg)
            display_alias_menu();
        else
            display_alias(arg);
        return;
    case 'a':
        if(!arg)
            modal_func((: cmd_adjust_alias :), //"Alias name? "
                                               "Alias 的名字：" );
        else
            cmd_adjust_alias(arg);
        return;
    case 'r':
        if( !shell_ob->query_alias_count() )
        {
            //write("You currently have no aliases defined.\n");
            write("你现在没有任何 alias。\n");
            goto_main_menu();
            return;
        }
        if(!arg)
            modal_func((: process_remove_alias :), //"Alias name? "
                                                   "Alias 的名字：");
        else
            process_remove_alias(arg);
        return;
    default:
        //write("Invalid command.\n");
        write("非法命令。\n");
        return;
    }
}
