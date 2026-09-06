main(string who) {
  object victim;

  WIZ_CHECK

  if (!who) {
    write ("Who do you want to set as a test character?\n");
    return 1;
  }
  if (victim = find_player(who)) {
    if (victim->query_testchar()) {
      write (capitalize(who)+" is no longer a test character.\n");
	  tell_object(victim,"You are no longer a test character.\n");
      victim->set_testchar(0);
      victim->set_alignment_string(0);
    } else {
      write (capitalize(who)+" is now set as a test character.\n");
	  tell_object(victim,"You have been set as "+this_player()->query_name()+"'s test character.\n");
      victim->set_testchar(1);
      victim->set_alignment_string(this_player()->query_name() + " testchar");
    }
  } else
    write ("Could not find "+capitalize(who)+".\n");
  return 1;
}
