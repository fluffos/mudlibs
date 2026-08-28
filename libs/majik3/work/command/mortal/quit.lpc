int
main (string str)
{
    object *arr;
    write ("Your character is now sleeping. Be back soon!\n");
    say (THIS->query_cap_name () + " falls asleep.\n");
    arr = all_inventory(environment(THIS));
    arr += ({ THIS });
    message ("announce",
      "Info: ^c1" + capitalize(THIS->query_name()) + "^c0 falls asleep.\n",
      users(), arr);

    THIS->set("start", file_name(environment(THIS)));
    THIS->save_me ();

    write_file ("/log/stats", ctime(THIS->query("last_date"))[11..12] + 
      " " + ((time() - THIS->query("last_date")) / 60) + "\n");
    destruct (THIS);
    return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "Saves your character and exits from the game.";
}


query_see_also()
{
  return "save(1)";
}
