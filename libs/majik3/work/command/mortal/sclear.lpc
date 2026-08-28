// ++ Namhas, 01 Aug 1997

int main (string str)
{
  if (!str)
    {
      message ("0",
        "Sclear  is command  which  clears  screen  automatically  before long\n"+
        "description, thus verbose mode is suggested. It needs full vt100/ansi\n"+
        "support, and it will not work if you are using 'TF' (tinyfugue). Only\n"+
        "'telnet' client is tested to work with this command.\n"+
        "\n"+
        "usage: ^c1sclear^c0 <^c3mode^c0> where mode is number between ^c10^c0 and ^c13^c0.\n"+
        "\n"+
        "available modes are:\n"+
        "  ^c10^c0     reset back to normal mode\n"+
        "  ^c11^c0     normal sclear mode\n"+
        "  ^c12^c0     super fast sclear mode for slow terminals\n"+
        "  ^c13^c0     same as 2 but removes cursor (some amigas)\n", THIS);
      return 1;
    }

  if (str == "0") {
    if (THIS->query("sclear") == 3)
      write ("\e[1 p");
    write ("\e[1;1H\e[2JScreen clear mode is now off.\n");
    THIS->set("sclear", 0);
  }
  else if (str == "1") {
    write ("\e[1;1H\e[2J");
    THIS->set("sclear", 1);
  }
  else if (str == "2") {
    write ("\e[1;1H\e[2J");
    THIS->set("sclear", 2);
  }
  else if (str == "3") {
    write ("\e[0 p\e[1;1H\e[2J");
    THIS->set ("sclear", 3);
  }
  else
  {
    write ("\e[1;1H\e[2JScreen clear mode is now off.\n");
    THIS->set("sclear", 0);
  }
  return 1;
}
query_author()
{
  return"namhas";
}
query_help()
{
  return "Sclear  is command  which  clears  screen  automatically  before long"
  + " description, thus verbose mode is suggested. It needs full vt100/ansi"
  + " support, and it will not work if you are using 'TF' (tinyfugue). Only"
  + " 'telnet' client is tested to work with this command."
  + "\n"
  + " available modes are:\n"
  + "   0     reset back to normal mode\n"
  + "   1     normal sclear mode\n"
  + "   2     super fast sclear mode for slow terminals\n"
  + "   3     same as 2 but removes cursor (some amigas)";
}
query_synopsis()
{
  return "sclear <mode> where mode is number between 0 and 3.";
}
query_see_also()
{
  return"term(1)";
}
query_position ()
{
  return POS_RESTING;
}

