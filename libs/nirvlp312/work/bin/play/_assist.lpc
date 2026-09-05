#define TP this_player()
cmd_assist(string arg)
{
  object ob;
  object mob;
  string mn;
  if(!arg) return (notify_fail("Assist whom?\n"), 0);
  if(TP->query_attack()) { 
    write("You are already busy fighting.\n");
    return 1;
  }
  if(!(ob=present(arg,environment(this_player()))) || !living(ob) ||
      (int)ob->query_invis() > (int)this_player()->query_level())
    return (notify_fail("You don't see " + arg + " anywhere around you.\n"), 0);
  if(!ob->is_player())
    return (notify_fail("You may only assist a player in combat.\n"), 0);
  mob=ob->query_attack();
  if(!mob)
    return (notify_fail(capitalize(arg) + " is not in combat!\n"), 0);
  this_player()->attack_object(mob);
  return 1;
}
