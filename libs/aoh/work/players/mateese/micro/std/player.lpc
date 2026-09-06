// Dummy player object.

#define THIS this_object()

inherit "/w/mateese/obj/lpd_inh";

void create()
{
  if (explode(file_name(THIS), "#")[0] != "/std/player")
  {
    raise_error ("Illegal attempt.\n");
    destruct(THIS);
    return;
  }
}

void StartPlayer (int guestno)
{
  write ("Starting dummy player.\n");
  add_action("fdebug", "debug");
  add_action("fload", "load");
  add_action("fupdate", "destruct");
  add_action("fquit", "quit");
  add_action("fshut", "shutdown");
  lpd_inh::add_actions();
}

int quit()
{
  write ("See you again next time...\n");
  destruct(THIS);
}

int fquit (string arg)
{
  if (arg)
    return (int) notify_fail("Can't quit "+arg+".\n");
  quit();
  return 1;
}

int fshut (string arg)
{
  int minutes;
  string reason;
  if (!arg || arg == "") shutdown();
  else
  {
    if (   sscanf (arg, "%d %s", minutes, reason) != 2
        && sscanf (arg, "%d", minutes) != 1)
    {
      minutes = 5;
      reason = "Unknown.";
    }
    ARMAGEDDON->Shutdown(minutes, reason);
  }
  write ("Ok.\n");
  return 1;
}

int fload (string arg)
{
  if (arg == "thing")
  { object ob;
    if (ob = find_object("/std/thing")) destruct(ob);
    if (ob = find_object("/std/thing/physical")) destruct(ob);
    if (ob = find_object("/std/thing/moving")) destruct(ob);
    if (ob = find_object("/std/object")) destruct(ob);
    call_other("/std/thing", "???");
  }
  else if (arg)
    call_other(arg, "???");
  else
    return (int) notify_fail("Illegal arg.\n");
  write ("Ok.\n");
  return 1;
}

int fupdate (string arg)
{ object ob;

  if (!arg)
    return (int) notify_fail("Illegal arg.\n");
  ob = find_object(arg);
  if (ob)
  {
    ob->remove();
    if (ob)
    {
      destruct(ob);
      write("Hard destructed "+arg+"\n");
    }
    else
      write("Destructed "+arg+"\n");
  }
  else
    write("No object '"+arg+"'\n");
  return 1;
}

int fdebug (string arg)
{
  write(tail("/"+__HOST_NAME__+".debug.log"));
  return 1;
}
