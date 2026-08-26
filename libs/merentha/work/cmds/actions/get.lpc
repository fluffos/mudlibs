// Petrarch
// Merentha Lib 1.0
// <get>

varargs int command(string str) {
object ob;
    if(!str) return notify_fail("Get what?\n");
    if(!ob=present(str, environment(this_player()))) return notify_fail("You do not see that here.\n");
    if(ob->move(this_player())) return 1;
    message("command", "You get "+ob->query_short()+".", this_player());
    message("command", this_player()->query_cap_name()+" gets "+ob->query_short()+".", environment(this_player()), this_player());
    return 1;
}

string help() {
return "Syntax: get <item>\n\nThis command will get the item from the current room and put it in your inventory, assuming you are able to carry it.";
}

