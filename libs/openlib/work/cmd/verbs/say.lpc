void
create()
{
  parse_init();
  parse_add_rule("say", "STR");
}

mixed
can_say_str(string str)
{
  return 1;
}

mixed
do_say_str(string str)
{
  message("comm",
	  this_player()->query_cap_name() + " says: " + str + "\n",
	  all_inventory(environment(this_player())), this_player());
  message("system",
	  "You say: " + str + "\n",
	  this_player());
}
