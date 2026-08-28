main (string str)
{
  if (!str)
    {
      write ("Usage: debug [verbose | normal | brief | off]\n");
      return 1;
    }

  if (str == "off")
    THIS->set_debug (3);
  else if (str == "verbose")
    THIS->set_debug (0);
  else if (str == "normal")
    THIS->set_debug (1);
  else if (str == "brief") 
    THIS->set_debug (2);
  else
    THIS->set_debug (0);

  return 1;
}
