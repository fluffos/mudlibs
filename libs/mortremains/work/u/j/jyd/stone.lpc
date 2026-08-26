id(str) {
    return str == "stone" || str == "black stone";
}
short() {
    return "A black stone";
}
long() {
    write("The stone is completely black, and feels warm to the touch.\n");
    write("There seems to be some magic in it.\n\n");
}
query_weight() { return 1; }
drop()
{ drop_object();
  return 1;
}
get() { return 1; }
init() {
    add_action("CloneFor", "CF");
}
CloneFor(str) 
{
  object obj,who,what;
  who = explode(str,"#")[0];
  what = explode(str,"#")[1];
  write("Attempting to clone "+what+" for "+who+"\n");
  if ((!who) || (!what)) {write("unable to clone "+what+" for "+who+"\n");return 0;}
  obj = clone_object(what);
  move_object(obj,find_player(who));
  return 1;
}
drop_object(str) {
    if (str == "all") {
        drop_object("black stone");
        return 0;
    }
    if (!str || !id(str)) return 0;
    write("The stone dissapears.\n");
    say(call_other(this_player(), "query_name") + " drops a black stone. It dissapears.\n");
    call_other(this_player(), "add_weight", -1);
    destruct(this_object());
    return 1;
}
