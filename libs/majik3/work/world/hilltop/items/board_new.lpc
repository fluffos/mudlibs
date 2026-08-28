// DESCRIPTION : hilltop's generic bulletin board
// CODER       : namhas

inherit ITEM;

#define SAVE "/data/board/hilltop"

mapping ms;

int cid;

#define pline(x) message("0", x, THIS);
#define room(x) message("3, x, ENV(THIS), THIS);

create_item ()
{
  set_short ("A large bulletin board");
  set_name (({ "board", "bulletin", "bulletin board" }));
  restore_object (SAVE);
}

init ()
{
  add_action ("do_read", "read");
  add_action ("do_remove", "remove");
  add_action ("do_write", "write");
}

long ()
{
  string buf;
  string *key;

  buf = "This is a bulletin board. Usage: READ/REMOVE <msg #>, WRITE "
      + "<topic>. There are "+cid+" messages on the board right now.\n\n";

  for (int i=0;i<sizeof(key);i++)
    buf += sprintf ("%2d : %-15s [%s] :: %s\n", key[i], ms[key[i]]["time"], ms[key[i]]["name"], ms[key[i]]["topic"]);

  return buf;
}

do_write (string str)
{
  if (!str || str == "board" || str == "")
    {
      pline ("Usage: write <topic>\n");
      return 1;
    }

  if (!ms)
    ms = ([ ]);

  cid++;

  ms[cid] = ([ "name"  : THIS->query_name(),
               "time"  : "-",
               "topic" : str,
               "data"  : 0 ]);

  return 1;
}
