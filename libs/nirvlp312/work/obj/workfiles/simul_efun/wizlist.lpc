void wizlist(string wizard)
{
  if((int)this_player()->query_level() < 100)
  {
    write("\
'wizlist' has no purpose outside of administration diagnostics.\n\
Therefore, it has been disabled.\n");
  }
  else if(wizard)
  {
#ifndef __LDMUD__
    efun::wizlist(wizard);
#else
    funcall(symbol_function('wizlist), wizard);
#endif
  }
  else
  {
#ifndef __LDMUD__
    efun::wizlist();
#else
    funcall(symbol_function('wizlist));
#endif
  }
}
