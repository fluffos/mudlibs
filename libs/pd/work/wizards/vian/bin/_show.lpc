#include <std.h>
int check_auto(object ob);


int cmd_show(string str) {
    object ob, pl;
    string a, b;
    if (!str) return notify_fail("Syntax: show <item> to <player>\n");
    if (sscanf(str, "%s to %s", a, b)!=2) return notify_fail("Syntax: show <item> to <player>\n");
    if (!ob=present(a, this_player())) return notify_fail("You are not carrying "+a+".\n");
    if (!pl=present(convert_name(b), environment(this_player()))) return notify_fail(b+" is not here with you.\n");
    if (!userp(pl)) return notify_fail(pl->query_cap_name()+" does not seem interested.\n");

    message("show", "You show "+pl->query_cap_name()+" "+ob->query_short()+".", this_player());
    ob->move(pl);
    message("show", this_player()->query_cap_name()+" shows you "+ob->query_short()+(ob->query_fingers() ?" ("+ob->query_fingers()+"fingers)":"")+":\n"+capitalize(ob->query_long())+"\n "+(check_auto(ob) ?capitalize(ob->query_short())+" will autoload for you.":capitalize(ob->query_short())+" will not autoload for you."), pl);
    ob->move(this_player());
    message("show", this_player()->query_cap_name()+" shows "+pl->query_cap_name()+" "+ob->query_short()+".", environment(this_player()), ({this_player(), pl}));
    return 1;
}
int check_auto(object ob) {
        if(ob->query_auto_load())
            if(ob->query_autload()!=({})){
                return 1;
    }
return 0;
}
