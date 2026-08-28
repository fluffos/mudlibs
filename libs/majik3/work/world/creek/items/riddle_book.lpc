inherit ITEM;

create_item ()
{
  set_name (({ "a book of riddles", "a book", "book" }));
  set_short ("a medium-sized parchment book");
  set_long (
    "The book has well-worn pages, containing many befuddling riddles "
  + "to suprise, confuse, and abuse you. You find yourself bewildered "
  + "by its contents and put it down to sort your head out.");

  set_material ("leather");
  set_dimensions (18, 24, 5);
}

init ()
{
  add_action ("do_read", "read");
}

do_read (string str)
{
  if (!str)
    {
      notify_fail ("Read what?\n");
      return 0;
    }

  if (present(str) != THOB)
    {
      notify_fail ("Read what?\n");
      return 0;
    }

  tell_room (ENV(THIS), THIS->query_cap_name()+" reads a book.\n",
    ({ THIS }));

  write ("The book is full of strange riddles, but for now - you don't understand anything of its contents. Maybe, later...\n");
  return 1;
}
