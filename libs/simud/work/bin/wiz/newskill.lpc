main(string str) {
  object victim;
  string who,what;
  if (!str) {
    write ("==> [Format] - newskill who skill\n");
    return 1;
  }
  sscanf(str,"%s %s",who,what);
  if (victim = find_player(who)) {
    victim->add_skill(what);
    write (capitalize(who)+" was given the "+what+" skill.\n");
    msg_object(victim,capitalize(this_player()->query_name())+" has given you the "+what+" skill.");
    command("query "+who+" skill "+what,this_player());
  } else
    write ("Could not find "+capitalize(who)+".\n");
  return 1;
}
