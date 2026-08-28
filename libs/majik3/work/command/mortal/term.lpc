#define pline(x) message ("0", x, previous_object())

int
main(string term)
{
  if (!term)
    {
      pline ("usage: term <terminal type>\n");
      pline ("available terminal types are: unknown, vt100, ansi, html, xterm, raw and majik\n");
      pline ("use 'raw' if you are using the web client\n");
      return 1;
    }

  if (term == "ansi") {
    THIS->set ("term", 2);
    pline ("Terminal type set to: ^c1^cya^cgn^ccs^cgi^c0\n");
  }
  else if (term == "xterm") {
    THIS->set ("term", 4);
    pline ("Terminal type set to: ^cCx^c0^cct^cWe^c0r^c0m^c0\n");
  }
  else if (term == "html") {
    THIS->set ("term", 3);
    pline ("Terminal type set to: ^cRh^c0^crt^cYm^c0^cyl^c0\n");
  }  
  else if (term == "raw") {
    THIS->set ("term", 5);
    pline ("Terminal type set to: ^c1raw^c0\n");
  }
  else if (term == "majik") {
    THIS->set ("term", 6);
    pline ("Terminal type set to: ^c1majik^c0\n");
  }
  else if (term == "vt100") {
    THIS->set ("term", 1);
    pline ("Terminal type set to: ^c1vt100^c0\n");
  }
  else
  {
    THIS->set ("term", 0);
    pline ("Terminal type set to: unknown\n");
  }
  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Changes your current terminal setting to one defined in <type>."
  + " Currently there are availabe:\n"
  + "vt100, ansi, html, xterm, raw, majik and unknown.";
}

query_see_also()
{
  return "set(1), sclear(1)";
}

query_synopsis()
{
  return "term <type>";
}

query_example()
{
  return "term ansi";
}
