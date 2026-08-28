inherit ITEM;

create_item ()
{
  set_name (({ "a book", "book" }));
  set_short ("a small leather covered book");
  set_long (
    "A small leather covered book. On top of it reads with golden letters: "
  + "'A book about a God and his nose, written by Throng the dwarf'. The "
  + "book seems to have historical value as it is written in the time "
  + "of The Old Majik.");

  set_material ("leather");
  set_dimensions (21, 28, 3);
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

  THIS->more_file ("/world/creek/jormap.txt");
  return 1;
}
