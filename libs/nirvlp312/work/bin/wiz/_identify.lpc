int cmd_identify(string str)
{
  object ob;
  string *list;
  int i;
  if(this_player()->query_level() < 21) return 0;
  notify_fail("Usage: identify <object>\n");
  if(!str) return 0;
  ob=present(str,this_player());
  if(!ob) ob=present(str,environment(this_player()));
  if(!ob) ob = find_living(str);
  if(!ob) ob = find_object(str);
  if(!ob) return 0;
  if(function_exists("short", ob))
    write("Short: " + ob->short() + "\n");
  if(function_exists("query_name", ob))
    write("Name: " + (string)ob->query_name() + "\n");
  if(function_exists("query_weight", ob))
    write("Weight: " + (int)ob->query_weight() + "\n");
  if(function_exists("query_value", ob))
    write("Value: " + (int)ob->query_value() + "\n");
  if(function_exists("weapon_class", ob))
    write("Wc: " + (int)ob->weapon_class() + "\n");
  if(function_exists("armor_class", ob))
    write("Ac: "+(int) ob->armor_class()+"\n");
  if(function_exists("query_type"))
    write("Type: " + (string)ob->query_type() + "\n");
  if(creator(ob))
    write("Creator: "+creator(ob) + "\n");
  list = inherit_list(ob);
  write("Inherits:\n");
  for(i = 0; i < sizeof(list); i++)
    write("\t" + list[i] + "\n");
  if(living(ob))
    write("It is a living.\n");
  if(interactive(ob))
    write("It is interactive.\n");
  write("\n");
  return 1;
}
