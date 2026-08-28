/* namhas was here, using cvs! */

inherit ITEM;

int fuel;
int lighted;

create ()
{
  ::create();
  fuel = 5000;
  lighted = 0;

  set_name (({ "a torch", "torch" }));
  set_short ("a torch");
  set_long ("");
  set_material ("oak");
  set_dimensions (50, 5, 5);
  THOB->create_item();
}

init ()
{
  add_action ("do_light", "light");
  add_action ("do_light", "ignite");
  add_action ("do_extinguish", "extinguish");
  add_action ("do_extinguish", "unlit");
  add_action ("do_extinguish", "douse");
}

set_fuel (int i)
{
  if (i < -1)
    i = -1;

  fuel = i;
  lighted = 0;
  remove_call_out ("do_update");
}

do_update ()
{
  switch (fuel)
    {
      case 1201..2400:
        fuel = 1200;
        call_out ("do_update", 600);
        break;
      case 601..1200:
        fuel = 600;
        call_out ("do_update", fuel);
        break;
      case 1..600:
        fuel = 0;
        out_of_fuel ();
        break;
      default:
        fuel = 2400;
        call_out ("do_update", 1200);
        break;
    }
}

out_of_fuel ()
{
  lighted = 0;
  fuel = 0;

  tell_room (ENV(THIS), THIS->query_cap_name()+"'s torch goes dark.\n",
    ({THIS}));
  write ("Your torch goes dark.\n");
  remove_call_out ("do_update");
}

query_fuel ()
{
  return fuel;
}

query_light ()
{
  return lighted;
}

int
do_light (string str)
{
  if (!str)
    {
      notify_fail ("Light what?\n");
      return 0;
    }

  if (present(str) != THOB)
    {
      notify_fail ("Light what?\n");
      return 0;
    }

  if (lighted)
    {
      write (THOB->query_true_name()+" is already lit!\n");
      return 1;
    }

  if (!fuel)
    {
      write (THOB->query_true_name()+" can no longer give light!\n");
      return 1;
    }

  lighted = 1;

  switch (fuel)
    {
      case 1201..2400:
        call_out ("do_update", fuel-1200);
        break;
      case 601..1200:
        call_out ("do_update", fuel-600);
        break;
      case 1..600:
        call_out ("do_update", fuel);
        break;
      default:
        call_out ("do_update", fuel-2400);
        break;
    }

  emote ("$n {light} "+THOB->query_true_name()+".", THIS, 0, ENV(THIS));
  THIS->check_light();
  return 1;
}

do_extinguish (string str)
{
  int i;

  if (!str) 
    {
      notify_fail ("Extinguish what?\n");
      return 0;
    }
     
  if (present(str) != THOB)
    {
      notify_fail ("Extinguish what?\n");
      return 0;
    }

  if (fuel == -1)
    {
      write (THOB->query_true_name()+" cannot be extinguished!\n");
      return 1;
    }

  if (!lighted)
    {
      write (THOB->query_true_name()+" is not lit!\n");
      return 1;
    }

  lighted = 0;
  i = remove_call_out ("do_update");

  if (i == -1)
    i = 0;

  switch (fuel)
    {
      case 1201..2400:
        fuel = 1200 + i;
        break;
      case 601..1200:
        fuel = 600 + i;
        break;
      case 1..600:
        fuel = i;
        break;
      default:
        fuel = 2400 + i;
        break;
    }

  emote ("$n {extinguish} "+THOB->query_true_name()+".", THIS, 0, ENV(THIS));
  THIS->check_light();
  return 1;
}

long ()
{
  string buf = "";

  switch (fuel)
    {
      case -1:
        buf += "It will give light until the end of time.\n";
        break;
      case 0:
        buf += "It can no longer give light.\n";
        break;
      case 1..600:
        buf += "It will not give light much longer.\n";
        break;
      case 601..1200:
        buf += "It will give light for a while yet.\n";
        break;
      case 1201..2400:
        buf += "It will give light for a long time.\n";
        break;
      default:
        buf += "It will give light for a very long time.\n";
        break;
    }

  return "It is a fine torch made of oak.\n" + buf + ::long();
}

short ()
{
  string ext = "";

  if (lighted)
    ext += " (lit)";
  else if (!fuel)
    ext += " (useless)";

  return ::short()+ext;
}

is_torch() { return 1; }
