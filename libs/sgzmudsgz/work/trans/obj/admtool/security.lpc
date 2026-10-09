// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** security.c -- security administration
**
** 950710, Deathblade: Created.
*/

#include <mudlib.h>
#include <security.h>

int write_error(string err);
void std_handler(string str);
void do_one_arg(string arg_prompt, function fp, string arg);
void do_two_args(string arg1_prompt, string arg2_prompt,
                 function fp, string arg);

varargs void modal_func(function input_func, mixed prompt_func, int secure);

#define PROMPT_SECURITY "(AdmTool:security) [psnuadlwrcmq?] > "

private nomask void write_security_menu()
{
/*
    write("Administration Tool: security administration\n"
          "\n"
          "    p             - privileges\n"
          "    s [priv]      - show sub-privileges\n"
          "    n [priv]      - define new privilege               [admin/owner]\n"
          "    u [priv]      - undefine privilege                 [admin/owner]\n"
          "\n"
          "    a [priv [priv]] - add a privilege to another       [admin/owner]\n"
          "    d [priv [priv]] - delete a privilege from another  [admin/owner]\n"
          "\n"
          "    l [dir]       - list directory protections\n"
          "    w [dir priv]  - set a directory's write protection [parent priv]\n"
          "    r [dir priv]  - set a directory's read protection  [admin]\n"
          "    c [dir]       - clear a directory's protection     [parent priv]\n"
          "\n"
          "    m             - main menu\n"
          "    q             - quit\n"
          "    ?             - help\n"
          "\n"
          );
*/
    write("管理工具：安全管理\n"
          "\n"
          "    p               - 特权\n"
          "    s [特权]        - 列出附属特权\n"
          "    n [特权]        - 定义新特权                     [大神/拥有者]\n"
          "    u [特权]        - 取消一个特权                   [大神/拥有者]\n"
          "\n"
          "    a [特权 [特权]] - 让一个特权成为另一个的附属     [大神/拥有者]\n"
          "    d [特权 [特权]] - 把一个特权从另一个的附属中删除 [大神/拥有者]\n"
          "\n"
          "    l [目录]        - 列出目录的保护权\n"
          "    w [目录][特权]  - 设定目录的写保护               [获权]\n"
          "    r [目录}[特权]  - 设定目录的读保护               [大神]\n"
          "    c [目录]        - 消除目录的保护权               [获权]\n"
          "\n"
          "    m        - 主选单\n"
          "    q        - 退出\n"
          "    ?        - 帮助\n"
          "\n"  
          );        
}

private nomask void privilege_owners()
{
    string * owners = SECURE_D->query_privilege_owners();

    printf(//"Owners:\n%-#79s\n"
           "拥有者：\n%-#79s\n", implode(sort_array(owners, 1), "\n"));
}

private nomask void receive_privilege_for_show(string priv)
{
    int n;
    mapping privmap;

    n = member_array(':', priv);
    if ( n == -1 )
    {
        string * privnames;
        string privname;

        privmap = SECURE_D->query_privilege_list(priv);
        if ( !privmap )
        {
            //write("** There is no such privilege.\n");
            write("** 没有这种特权。\n");
            return;
        }

        privnames = sort_array(keys(privmap), 1);
        foreach ( privname in privnames )
            {
                if ( sizeof(privmap[privname]) )
                    write("[" + privname + "] -> " +
                          implode(privmap[privname], ", ") + "\n");
                else
                    write("[" + privname + "]\n");
            }
    }
    else
    {
        privmap = SECURE_D->query_privilege_list(priv[0..n-1]);
        if ( !privmap || !privmap[priv] )
        {
            //write("** There is no such privilege.\n");
            write("没有这种特权。\n:");
            return;
        }

        if ( sizeof(privmap[priv]) )
            write("[" + priv + "] -> " + implode(privmap[priv], ", ") + "\n");
        else
            write("[" + priv + "]\n");
    }
}

private nomask void receive_privilege_for_define(string priv)
{
    /* checks for admin/owner... */
    if ( write_error(SECURE_D->define_privilege(priv)) )
        return;

    printf(//"Privilege '%s' has been defined.\n",
           "特权 %s 被定义了。\n", priv);
}                                      

private nomask void receive_privilege_for_undefine(string priv)
{
    /* checks for admin/owner... */
    if ( write_error(SECURE_D->undefine_privilege(priv)) )
        return;

    printf(//"Privilege '%s' has been undefined.\n"
           "特权 %s 被取消了。\n", priv);
}

private nomask void receive_privilege_for_add(string user, string priv)
{
    /* checks for admin/owner... */
    if ( write_error(SECURE_D->extend_access(priv, user)) )
        return;

}

private nomask void receive_privilege_for_remove(string user, string priv)
{
    /* checks for admin/owner... */
    if ( write_error(SECURE_D->restrict_access(priv, user)) )
        return;

    printf(//"Privilege '%s' has been removed from '%s'.\n",
           "特权 %s 从 %s 中取消了。\n",
           user, priv);
}

private nomask void remap_tree(mapping result, mapping tree, string path)
{
    string subdir;
    mixed * data;

    foreach ( subdir, data in tree )
    {
        string fullpath = path + "/" + subdir;

        if ( data[0] != -1 )    /* cleared privs */
        {
            result[fullpath] = "" + data[0];
        }

        if ( data[1] )
            remap_tree(result, data[1], fullpath);
    }
}

private nomask void list_dir_privs(string arg)
{
    mapping r_tree;
    mapping w_tree;
    string dir;
    string priv;
    string output;

    if ( !arg )
        arg = ".";
    else  if( !is_directory( arg ))
    {
        write( "非法目录。\n");
        return;
    }
    arg = evaluate_path(arg);
    if ( arg == "/" )
        dir = arg = "";
    else
        dir = arg[0..strsrch(arg, "/", -1)-1];

    r_tree = ([ ]);
    w_tree = ([ ]);

    remap_tree(r_tree, SECURE_D->query_access_tree(arg, 0), dir);
    remap_tree(w_tree, SECURE_D->query_access_tree(arg, 1), dir);

    foreach ( dir, priv in r_tree )
    {
        if ( w_tree[dir] )
            w_tree[dir] += sprintf("   (read: %s)", priv);
        else
            w_tree[dir] = sprintf("(read: %s)", priv);
    }

    output = implode(({ "" }) + sort_array(keys(w_tree), 1),
                     (: $1 + $2 + "   " + $(w_tree)[$2] + "\n" :)) + "\n";
    more(output);
}

private nomask void perform_set_dir_priv(int rw, string dir, mixed priv)
{
    dir = evaluate_path(dir);

    if ( priv == "0" )
        priv = 0;
    else if ( priv == "1" )
        priv = 1;

    /* checks for parent dir priv... */
    if ( write_error(SECURE_D->set_protection(dir, rw, priv)) )
        return;

    printf(//"Directory '%s' has been set to '%s'.\n"
           "目录 %s 被设成权限 %s 。\n", dir, priv);
}

private nomask void perform_clear_dir_priv(string dir)
{
    dir = evaluate_path(dir);

    /* checks for parent dir priv... */
    if ( SECURE_D->query_protection(dir + "/foo", 0) )
        if ( write_error(SECURE_D->set_protection(dir, 0, -1)) )
            return;

    if ( SECURE_D->query_protection(dir + "/foo", 1) )
        if ( write_error(SECURE_D->set_protection(dir, 1, -1)) )
            return;

    printf(//"The privileges on '%s' have been cleared.\n"
           "在 %s 上的权限已经被取消了。\n", dir);
}

private nomask void receive_security_input(string str)
{
    string arg;

    if ( sizeof(str) > 1 )
    {
        if ( sscanf(str, "%s %s", str, arg) != 2 )
        {
            //write("** Format is: <option> <argument>\n");
            write("格式：<option> <argument>\n");
            write_security_menu();
            return;
        }
    }

    switch ( str )
    {
    case "p":
        if ( arg )
            //write("** No argument is required.\n");
            write("** 不需要参数。\n");
        privilege_owners();
        break;

    case "s":
        do_one_arg(//"Show information for which privilege? ",
                   "显示哪一个特权的信息？",
                   (: receive_privilege_for_show :),
                   arg);
        break;

    case "n":
        do_one_arg(//"Define which privilege? ",
                   "定义哪个特权？", 
                   (: receive_privilege_for_define :),
                   arg);
        break;

    case "u":
        do_one_arg(//"Undefine which privilege? ",
                   "取消哪个特权？",
                   (: receive_privilege_for_undefine :),
                   arg);
        break;

    case "a":
        do_two_args(//"Adding which user (to a priv) ? ",
                    //"Add '%s' to which privilege? ",
                    "把哪个用户加入特权？",
                    "把 %s 加入哪个特权？",
                    (: receive_privilege_for_add :),
                    arg);
        break;

    case "d":
        do_two_args(//"Remove which user (from a priv) ? ",
                    //"Remove '%s' from which privilege? ",
                    "把哪个用户从特权中取消？\n",
                    "把 %s 从哪个特权中取消？\n",
                    (: receive_privilege_for_remove :),
                    arg);
        break;

    case "l":
        list_dir_privs(arg);
        break;

    case "w":
        do_two_args(//"Set which directory's write privilege? ",
                    //"Set '%s' to what privilege? ",
                    "要设定哪个目录的写保护？",
                    "把 %s 设定成哪种权限的写保护？", 
                    (: perform_set_dir_priv, 1 :),
                    arg);
        break;

    case "r":
        do_two_args(//"Set which directory's read privilege? ",
                    //"Set '%s' to what privilege? ",
                    "要设定哪个目录的读保护？",
                    "把 %s 设定成哪种权限的读保护？",               
                    (: perform_set_dir_priv, 0 :),
                    arg);
        break;

    case "c":
        do_one_arg(//"Clear which directory's privileges? ",
                   "清除哪个目录的权限保护？",
                   (: perform_clear_dir_priv :),
                   arg);
        break;

    case "?":
        write_security_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

protected nomask void begin_security_menu()
{
    modal_func((: receive_security_input :), PROMPT_SECURITY);
    write_security_menu();
}
