main(string arg) {
  int old = this_player()->query_autoready(), new;
  switch (arg) {
    case "off":
    case "clear": new = 0; break;
    case "low": new = 1; break;
    case "on":
    case "default":
    case "normal": new = 2; break;
    case "high": new = 3; break;
    default: if (!arg || sscanf(arg,"%d",new) != 1)
               new = old + 1;
  }
  if (new < 0 || new > 3)
    new = 0;
  this_player()->set_autoready(new);

  switch (new) {
    case 0: msg("~CCOMAutoready~CDEF turned ~CBRToff~CDEF. You will no longer see your readymeter in combat."); break;
    case 1: msg("~CCOMAutoready~CDEF turned to ~CBRTlow~CDEF. You will now see a minimal readymeter in combat."); break;
    case 2: msg("~CCOMAutoready~CDEF turned to ~CBRTnormal~CDEF. You now see your normal readymeter in combat."); break;
    case 3: msg("~CCOMAutoready~CDEF turned to ~CBRThigh~CDEF. You will now see a large readymeter in combat."); break;
    default: msg("~CWRNSomething went wrong. ~CDEFResetting your readymeter to ~CCOMdefault~CDEF.");
             this_player()->set_autoready(2);
  }
  return 1;
}
