main(string str) {
    object ob;
    if(THIS->query_resting())
    {
	message("0","You think that you can kill while resting, hah?\n",THIS);
	return 1;
    }
    if (!str) {
	write("Kill what?\n");
	return 1;
    }
    /*
	ob = find_player (str);
    */
    ob = present(lower_case(str), ENV(THIS));
    if (!ob) {
	write("Kill what?\n");
	return 1;
    }

    if (!living(ob)) {
	write(str + " is not a living thing!\n");
	say(THIS->query_cap_name() + " tries foolishly to attack " + str + ".\n");
	return 1;
    }

    if (ob == this_player()) {
	write("What? Attack yourself?\n");
	return 1;
    }
    if (ob->query_is_dead())
    {
      write (ob->query_cap_name()+" is dead already.\n");
      return 1;
    }

    ob->fix_heart();
    THIS->fix_heart();

    if (!query_heart_beat(ob))
    {
      write (ob->query_cap_name()+" is a unkillable zombie.\n");
      return 1;
    }

    tell_object (ob, "^cR" + THIS->query_cap_name()+" attacks YOU!^c0\a\n");

    message ("3", THIS->query_cap_name()+" attacks "+
      capitalize(str)+"!\n", ENV(THIS), ({ THIS, ob }));
ob->before_battle (THIS);
    THIS->set_target(ob->query_name());
    write(wrap("-- BATTLE INITIALIZED --\n"));
    THIS->begin_battle(ob);
    return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "kill <target>";
}

query_help ()
{ 
  return "When this command is typed it will begin combat with specified "
       + "target. Be careful of who you attack as there may be many "
       + "laws in different lands that forbid fighting or killing. "
       + "You have been warned.";
}

query_see_also ()
{
  return "skills(1), use(1), wield(1), kills(1)";
}

query_position ()
{
  return POS_STANDING;
}

