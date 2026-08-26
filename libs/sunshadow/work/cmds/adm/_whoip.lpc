//
// _whoip.c
//
// Similar to who but displays ip numbers.
//
// USAGE : whoip
//         whoip <player name>
//         whoip <ip number>
//
// Only available to admins.
//
// -- Tlaloc -- 10/28/21
//

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define DIVIDER "=======================================================================\n"

int cmd_whoip(string str)
{
    object user, userlist;
    string name, ip, tmp, *n;
    int x;
    
    userlist = users();
    
    if(!str)
    {
        printf("%s:  Local Time is: %s)\n%s", mud_name(), ctime(time()), DIVIDER);
        printf("Name              IP number          IP name\n" + DIVIDER);
        
        foreach(user in userlist)
        {
            name = user->query_name();
            
            if(!strlen(name))
                name = "(login)";
            else
                name = capitalize(name);
            
            printf("%-17s %-18s %-25s\n", name, query_ip_number(user), query_ip_name(user));
        }
        
        x = sizeof(userlist);
        printf("%sCurrently there %s %d player%s.\n", DIVIDER, x > 1 ? "are" : "is", x, x > 1 ? "s" : "");
        
        return 1;
    }
    
    if(user = find_player(str))
    {
        ip = query_ip_number(user);
        userlist = filter_array(userlist, (: query_ip_number($1) == $2 :), ip);
    }
    else if(sscanf(implode(explode(str, "."), ""), "%d", x) == 1)
    {
        userlist = filter_array(userlist, (: query_ip_number($1) == $2 :), str);
    }
    else if(sscanf(implode(explode(str, "."), ""), "%s", x) == 1)
    {
        userlist = filter_array(userlist, (: query_ip_name($1) == $2 :), str);
    }
    else
    {
        str = lower_case(str);
        userlist = filter_array(userlist, (: query_ip_number($1) == $2 :), str);
    }
    
    if((x = sizeof(userlist)) > 0)
    {
        n = map_array(userlist->query_name(), (: $1 ? capitalize($1) : "(login)" :));
        tmp = query_ip_name(userlist[0]);
        
        if(tmp != query_ip_number(userlist[0]))
            tmp += " (" + query_ip_number(userlist[0]) + ")";
        
        printf("There %s %d user%s from %s:\n", x > 1 ? "are" : "is", x, x > 1 ? "s" : "", tmp);
        printf("%-=78s", implode(n, ", ") + "\n");
    }
    else
    {
        write("No one is connected from that address.");
    }

    return 1;
}

int help()
{
    write("Command : whoip");
    write("Syntax  : whoip, whoip <username>, whoip <ip number>\n");
    write("This command will either show all users and their IP info, or give the IP info of a designated player, OR will give a list of all players logged in from the designated IP.");
    
    return 1;
}       