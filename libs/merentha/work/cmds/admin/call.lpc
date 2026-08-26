// Petrarch
// Merentha Lib 1.0
// <call>

varargs int command(string input) {
mixed ret;
object ob;
string *args=0;
string obj, fun;
int i;

    if(sscanf(input, "%s;%s", obj, fun)!=2) return notify_fail("Syntax: call object;function;args\n");
    i=sizeof(args=explode(fun,";"));

    if(obj=="me") ob=this_player();

    if (!ob) ob=present(obj, environment(this_player()));
    if (!ob) ob=find_player(player_name(obj));
    if (!ob) ob=find_living(obj);
    if (!ob) ob=find_object(obj);
    if (!ob) return notify_fail("Could not find "+obj+"\n");

    ret=call_other(ob, args);

    message("command", input+" = %^BOLD%^"+identify(ret), this_player());

    return 1;
}

string help() {
    return "Syntax: call <object>;<function>;<args;args;args;...>\n\nCalls the function in the object with any number of arguments.\n\nExample: call me;query_race";
}
