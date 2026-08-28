//    Actually containing the function called by herb drinking.

int herb_action(object who, int strength) {
  if(!strength) return notify_fail("Potion BUG BUG BUG!");
  if(!who->add_stoned(strength))
    write("You are so out of it by this point, further herb potions "+
	  "will do you no good.");
  else if(who->query_stoned() > 200)
    write("You feel a little woozy.");
  destruct(this_object());
  return 1;
}
