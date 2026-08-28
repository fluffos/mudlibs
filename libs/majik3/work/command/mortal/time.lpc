#define pline(x) message("0", x, previous_object());
#define room(x) message("3", x, ENV(previous_object()), previous_object());

main ()
{
  string poks;
  int yeari;
  string years;

  poks = TIME_D->query_time_of_day();
  poks = poks[6..strlen(poks)-2];

  if (poks == "day-time")
    poks = "day";

  yeari = TIME_D->query_year();
  switch (yeari)
    {
      case 5: years = "Five"; break;
      case 6: years = "Six"; break;
      case 7: years = "Seven"; break;
      case 8: years = "Eight"; break;
      case 9: years = "Nine"; break;
      case 10: years = "Ten"; break;
      default: years = yeari; break;
    }

  if (THIS->query_security() > 1) {
    pline ("WIZINFO: ");
    "/command/immortal/time"->main();
  }

  if (file_name(ENV(THIS)) == "/world/misc/void") {
    pline ("You can't determine time in a void!\n");
    return 1;
  }

  if (ENV(THIS)->query_outdoors() == 0) {
    pline ("You are standing indoors without window. It is a bit hard to determine time.\n");
    return 1;
  }
  else if (ENV(THIS)->query_outdoors() == 4)
    {
  room(THIS->query_cap_name() + " looks around and tries to determine time.\n");
    }
  else
    {
  room(THIS->query_cap_name() + " looks out from window.\n");
    }
  pline("It is a "+TIME_D->query_season()+" "+poks+" of "+TIME_D->query_month_s()+".\n"+years+" years has passed since The World Creation.\n");
  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "You try to determine the current time in Majik from the position"
  + " of sun. You have to be outside in order be able to use this.";
}
query_position()
{
 return POS_RESTING;
}

