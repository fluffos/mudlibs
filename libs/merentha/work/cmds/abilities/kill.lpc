// Petrarch
// Merentha Lib 1.0
// <kill>

int command(string str) {
    object ob;
    if(!str) return notify_fail("Syntax: kill <living>\n");
    if(!ob=present(str, environment(this_player()))) return notify_fail("You do not see that here.\n");
    if(!living(ob)) return notify_fail("That is not alive.\n");
    if(!this_player()->kill_ok(ob)) return notify_fail("That being is protected,\n");
    this_player()->kill_ob(ob);
    message("combat", "You attack "+ob->query_cap_name()+".", this_player());
    message("combat", this_player()->query_cap_name()+" attacks you.", ob);
    message("combat", this_player()->query_cap_name()+" attacks "+ob->query_cap_name()+".", environment(this_player()), ({ob,this_player()}));
    return 1;
}

string help() {
    return "Syntax: kill <living>\n\nStarts combat between you and another living creature.";
}


