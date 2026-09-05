
id(str) { return (str == "blood"); }
reset() {}
long()
{ write("A small bag containing blood with a long, clear tube having a needle at the end.\n");}
short() { return "Huuman Blood"; }
init()
{ add_action("drink", "inject");}
drink(arg)
{
  if (id(arg)) {
    if (!call_other(this_player(), "drink_alcohol",13)){
write("You already haave enough blood in you!\n");
	return 1;
	}
    if (call_other(this_player(), "drink_alcohol", 20))
    {
say(call_other(this_player(),"query_name") + " gets a placid look on their face as they inject the blood into their veins.\n");
write("Your veins burn as you insert the needle and inject the blood.\n");
      call_other(this_player(),"heal_self",200);
      this_player()->add_weight(-2);
      destruct(this_object()); 
      return 1;
    }
    return 1;
  } else { return 0; }
}
get() { return 1; }
query_weight() { return 2; }
query_value() { return 5000; }

