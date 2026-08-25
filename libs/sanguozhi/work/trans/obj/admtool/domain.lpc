// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** domain.c -- domain adminstration
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

#define PROMPT_DOMAIN   "(AdmTool:domain) [lscCduaArmq?] > "


private nomask void write_domain_menu()
{
/*
    write("Administration Tool: domain administration\n"
          "\n"
          "    l                 - list domains\n"
          "    s [domain]        - show domain information\n"
          "\n"
          "    c [domain]        - create a domain                  [admin]\n"
          "    C [domain]        - create abstract domain (no dir)  [admin]\n"
          "    d [domain]        - delete a domain                  [admin]\n"
          "\n"
          "    u [user]          - show user's domains\n"
          "    a [user] [domain] - add user to a domain             [lord]\n"
          "    A [user] [domain] - add user as a lord of the domain [lord]\n"
          "    r [user] [domain] - remove a user from a domain      [lord]\n"
          "\n"
          "    m                 - main menu\n"
          "    q                 - quit\n"
          "    ?                 - help\n"
          "\n"
          );
*/
    write("管理工具：区域管理\n"
          "\n"
          "    l                 - 区域列表\n"       
          "    s [区域]          - 显示某区域信息\n"
          "\n"
          "    c [区域]          - 建立一个区域                 [大神]\n" 
          "    C [区域]          - 建立一个抽象区域(无目录)     [大神]\n"
          "    d [区域]          - 删除一个区域                 [大神]\n"              
          "\n"
          "    u [用户]          - 显示用户信息\n"
          "    a [用户] [区域]   - 把用户加入一个区域           [域主]\n"
          "    A [用户] [区域]   - 提升用户为域主               [域主]\n"      
          "    r [用户] [区域]   - 把用户从区域中删除           [域主]\n"      
          "\n"                                          
          "    m        - 主选单\n"
          "    q        - 退出\n"
          "    ?        - 帮助\n"
          "\n"
          );      
          
}

private nomask void list_domains()
{
    string * domains;

    domains = SECURE_D->query_domains();
    if ( !sizeof(domains) )
    {
        //write("There are no domains.\n");
        write("没有任何区域。\n");
    }
    else
    {
        printf(//"The following domains exist:\n%-#78s\n",
               "存在下列区域：\n%-#78s\n",
               implode(sort_array(domains, 1), "\n") + "\n");
    }
}

private nomask void show_domain_info(string domain)
{
    string * members;
    string * lords;

    members = SECURE_D->query_domain_members(domain);
    if ( !members )
    {
        //printf("There is no domain named '%s'\n", domain);
        printf("没有以 %s 为名的区域\n", domain);
    }
    else
    {
        lords = SECURE_D->query_domain_lords(domain) || ({ });
        members -= lords;

        //printf("Domain %s:\n", domain);
        printf("区域 %s：\n", domain);

        switch ( sizeof(lords) )
        {
        case 0:
            //write("Lords:   (none)\n");
            write("域主：       (空缺)\n");
            break;

        case 1:
            //printf("Lord:    %s\n", lords[0]);
            printf("域主：      %s\n", lords[0]);
            break;

        default:
            printf("域主：      %s\n", //"Lords:   %s\n", 
                   implode(lords, ", "));
            break;
        }

        switch ( sizeof(members) )
        {
        case 0:
            //write("Members: (none)\n");
            write("成员：       (无)\n");
            break;

        case 1:
            //printf("Member:  %s\n", members[0]);
            printf("成员：      %s\n", members[0]);
            break;

        default:
            printf("成员：      %s\n",//"Members: %s\n",
             implode(members, ", "));
            break;
        }
    }
}

private nomask void create_domain(int no_domain_dir, string domain)
{
    string err;

    domain = lower_case(domain);

    /* this checks for admins... */
    if ( write_error(SECURE_D->create_domain(domain)) )
        return;

    //write("Domain created.\n");
    write("区域建成。\n");

    if ( !no_domain_dir )
    {
        string dirname = "/domains/" + domain;

        mkdir(dirname);
        //printf("Created %s\n", dirname);
        printf("建立 %s\n", dirname);
        printf(//"Setting protection level of %s\n",
               "设定 %s 的保护级别\n", dirname);
        
        write_error(SECURE_D->set_protection(dirname,
                                             1,
                                             domain + ":"));
    }
}

private nomask void delete_domain(string domain)
{
    SECURE_D->set_protection("/domains/" + domain, 1, -1);

    /* this checks for admins... */
    if ( write_error(SECURE_D->delete_domain(domain)) )
        return;

    //write("Domain deleted.\n");
    write("区域删掉了。\n");
}

private nomask void show_users_domains(string user)
{
    string * domains;

    domains = SECURE_D->query_domains(user) || ({ });
    if ( !sizeof(domains) )
        //printf("Wizard %s doesn't belong to any domain.\n", user);
        printf("巫师 %s 不属于任何一个区域。\n", user);
    else
        printf(//"Wizard %s belongs to %s.\n", 
               "巫师 %s 属于 %s。\n", user,
               implode(sort_array(domains, 1), ", "));
}

private nomask void add_user_to_domain(int lord, string user, string domain)
{
    /* this checks for lord privs... */
    if ( write_error(SECURE_D->add_domain_member(domain, user, lord)) )
        return;

    printf(//"Added %s %s %s.\n",
           "让 %s %s。\n", user, lord ? "成为 "+domain+" 的域主" : "加入 "+domain);
}

private nomask void remove_user_from_domain(string user, string domain)
{
    /* this checks for lord privs... */
    if ( write_error(SECURE_D->remove_domain_member(domain, user)) )
        return;

    //printf("Removed %s from %s.\n", user, domain);
    printf("把 %s 从 %s 区域中删除。\n", user, domain);
}

private nomask void receive_domain_input(string str)
{
    string arg;

    if ( sizeof(str) > 1 )
    {
        if ( sscanf(str, "%s %s", str, arg) != 2 )
        {
            //write("** Format is: <option> <argument>\n");
            write("** 格式：<option> <argument>\n");
            write_domain_menu();
            return;
        }
    }

    switch ( str )
    {
    case "l":
        if ( arg )
            //write("** No argument is required.\n");
            write("** 无需参数。\n");
        list_domains();
        break;

    case "s":
        do_one_arg(//"Show information on which domain? ",
                   "显示哪一个区域的信息？",
                   (: show_domain_info :),
                   arg);
        break;

    case "c":
        do_one_arg(//"Name for the new domain? ",
                   "新区域的名称？",
                   (: create_domain, 0 :),
                   arg);
        break;

    case "C":
        do_one_arg(//"Name for the new domain? ",
                   "新区域的名称？",
                   (: create_domain, 1 :),      /* 1 == no_domain_dir */
                   arg);
        break;

    case "d":
        do_one_arg(//"Delete which domain? ",
                   "删除哪一个区域？",     
                   (: delete_domain :),
                   arg);
        break;

    case "u":
        do_one_arg(//"Show information for which user? ",
                   "显示哪一个用户的信息？",     
                   (: show_users_domains :),
                   arg);
        break;

    case "a":
        do_two_args(//"Add which user? ",
                    "增加哪个用户？",    
                    //"Add '%s' to which domain? ",
                    "增加 %s 到哪个区域？",
                    (: add_user_to_domain, 0 :),
                    arg);
        break;

    case "A":
        do_two_args(//"Add which user as a lord? ",
                    //"Add '%s' to which domain? ",
                    "把哪个用户提升为域主？",
                    "增加 %s 到哪个区域？", 
                    (: add_user_to_domain, 1 :), /* 1 == lord */
                    arg);
        break;

    case "r":
        do_two_args(//"Remove which user? ",
                    //"Remove '%s' from which domain? ",
                    "删除哪个用户？",
                    "把 %s 从哪个区域中删除？",
                    (: remove_user_from_domain :),
                    arg);
        break;

    case "?":
        write_domain_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

protected nomask void begin_domain_menu()
{
    modal_func((: receive_domain_input :), PROMPT_DOMAIN);
    write_domain_menu();
}
