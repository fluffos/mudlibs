// #define debug(x, y) message ("0", x+": "+y+"\n", find_player("namhas"))
#define debug(x, y) {}
#define emote(x, y) message ("0", y+"\n", x)
#define room(x) message ("0", x+"\n", ENV(THOB), THOB)

int
die (object kill)
{
  object corpse, o, *all;
  int alxm;

  emote (THOB, "You die.");
  room (THOB->query_cap_name()+" dies.");

  if (kill)
    {
      write_file ("/log/kill", ctime(time())+" "+kill->query_name()+
        " "+THOB->query_name()+"\n");

      if (THOB->query_alignx() < 0)
        alxm += -((THOB->query_alignx()/20));
      else if (THOB->query_alignx() > 0)
        alxm -= THOB->query_alignx()/20;

      if (interactive(THOB) && interactive(kill))
        {
          write_file ("/log/pkill", ctime(time())+" "+kill->query_name()+
            " "+THOB->query_name()+"\n");

          alxm = alxm * 2;
        }

      if (THOB->query_race() == kill->query_race())
        alxm = alxm * 2;

      kill->add_alignx(alxm);

      if (THOB->query_race() != "raceless")
        {
          kill->add_kill (THOB->query_race());
        }

      if (kill->query_kills())
        {
          switch (kill->query_kills()[THOB->query_race()])
            {
              case 1:
                emote (kill, "You feel victorious as you killed "+
                  THOB->query_race()+" first time.\n");
                break;
              case 10:
                emote (kill, "You are getting the idea in killing "+
                  pluralize(THOB->query_race())+".\n");
                break;
              case 30:
                emote (kill, "You feel yourself as average "+
                  THOB->query_race()+" killer.\n");
                break;
              case 50:
                emote (kill, "It seems "+pluralize(THOB->query_race())+
                " are getting killed more easily.\n");
                break;
              case 70:
                emote (kill, "You feel yourself as expert "+
                  THOB->query_race()+" killer.\n");
                break;
              case 85:
                emote (kill, "Fuck those "+THOB->query_race()+
                " bastards prove no resistance against you.\n");
                break;
              case 100:
                emote (kill, "You feel like "+pluralize(THOB->query_race())+
                " are far too easy for such great warrior as you.\n");
                break;
            }
        }
    }

  corpse = new ("/obj/corpse");
  corpse->create_corpse (THOB);

  all = all_inventory(THOB);

  foreach (o in all)
      o->move (corpse);

  if (THOB->query_money())
    {
      o = new ("/obj/money");
      o->set_amount (THOB->query_money());
      THOB->add_money (-THOB->query_money());
      o->move (corpse);
    }

  corpse->move (ENV(THOB));
  emote (THOB, "You feel yourself floating away from your body.\n");

  if (!interactive(THOB))
    {
      if (THOB->short() && THOB->short()[0] > 64 && THOB->short()[0] < 91)
        {
          "/daemon/astral"->add_ghost(THOB->query_race(),
            THOB->query_pow());
        }
      else
        {
          "/daemon/astral"->add_ghost(THOB->query_cap_name(),
            THOB->query_pow());
        }

      destruct (THOB);
    }
  else
    {
      o = new ("/world/misc/astral");
      o->set_env (ENV(THOB));

      THOB->move(o);
      THOB->set_ghost(1);
    }

  return 1;
}

