// Petrarch
// Merentha Lib 1.0
// <users>

#include <daemons.h>

string help() {
    return "Syntax: users\n        users @<mud>\n\n\
This command will display a list of all the people currently connected to \
"+mud_name()+" in alphabetical order.  If the @ symbol is used will \
display a list of all people currently logged on the MUD mentioned.  The \
mentioned MUD must be part of the Merentha InterMUD System.\n\n\
See also: finger, muds"; 
}

varargs int command( string str) {
    string *u;
    int i=this_player()->getenv("SCREEN");
    if(!i) i=75;
    if(!str) {
        u=users()->query_cap_name();
        message("command", border("%^RED%^"+format_page(u, 4),"users",i),this_player());
        return 1;
    }
    if(str[0]!='@') return notify_fail(help()+"\n");
    str=str[1..<0];
    if(str[0]==' ') str=str[1..<0];
    return NETWORK_D->send_rwho_request(str,this_player()->query_name(),i);
}


