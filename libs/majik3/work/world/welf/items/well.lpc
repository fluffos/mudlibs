inherit ITEM;

create_item ()
{
  set_name (({ "a stone well", "well" }));
  set_short ("an old stone well is here");


  set_long ("The well is made of small blocks of stones and quite old "
           +"judging from the tiny cracks on its sides and the moss "
           +"covering the stones nearest the ground.\n");

  set_material ("stone");
  set_dimensions (100, 100, 100);
  set_no_get (1);
  set_no_clean_up(1);
}

init ()
{
  add_action ("do_drink", "drink");
}

do_drink (string str)
{
  if (!str || str != "well") {
    notify_fail ("Drink what?");
    return 0;
  }

  write ("You drink from the well and feel refreshed.\n");
  message ("3", THIS->query_cap_name() +
    " drinks from the well.\n", ENV(THIS), THIS);

  THIS->hydrate_me (300);

  return 1;
}
