// DESCRIPTION : top explorers plaque
// CODER       : dazzt, rewritten by namhas - sort_array()

inherit ITEM;

#define UPDATE_TIME     (5 * 60)
#define CLEANUP_TIME    (60 * 60 * 24 * 14)

#define pline(x)        message ("0", x, THIS)
#define lw(x)           wrap(x)

mapping players;

create_item ()
{
  restore_object (base_name(THOB));

  if (!players)
    players = ([ ]);

  set_name ("plaque");
  set_short ("a massive golden plaque \"Richest players\"");
  set_no_get();

  call_out("do_update", UPDATE_TIME);
}

long ()
{
  string buf;
  string k;
  int t;

  remove_call_out ("do_update");
  do_update ();

  buf = lw("This ancient plaque has been shaped from a single piece of gold. "
      + "Only the most wealthy players have their name "
      + "carved on this magical plaque, blessed by the gods.\n\n");

  buf += "^c0^cW^bb##. name             wealth^c0\n";

  k = keys(players);
  k = sort_array (k, "do_sort");

  for (int i=0;i<sizeof(k);i++)
    {
      if (i>9)
        break;

      buf += sprintf ("^c0%s%2d^c0. ^c1%-15s^c0 %7d\n", "^cc",
               i+1, k[i], players[k[i]][0]);
    }

  return buf;
}

do_sort (mixed a, mixed b)
{
  int c, d;

  c = players[a][0];
  d = players[b][0];

  if (c < d)
    return 1;
  else if (c == d)
    return 0;
  else
    return -1;
}

do_update ()
{
  int    i;
  object u, o;
  string *s;

  u = users();

  for (i=0;i<sizeof(u);i++)
    {
      if (!wizardp(u[i]->query_name()) && !u[i]->query_npc())
        {
          players[u[i]->query_name()] = ({ u[i]->query_money (),
                                           time () });
        }
    }

  s = keys(players);

  for (i=0;i<sizeof(s);i++)
    {
      if (players[s[i]][1] - time() > CLEANUP_TIME)
        map_delete (players, s[i]);

      if (s[i])
        {
          o = find_player (s[i]);

          if (o)
            {
              if (wizardp (o->query_name()))
                map_delete (players, s[i]);
            }
        }
    } 

  save_object (base_name(THOB));
  call_out ("do_update", UPDATE_TIME);
}
