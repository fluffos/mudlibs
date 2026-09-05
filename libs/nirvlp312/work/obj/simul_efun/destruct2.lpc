/*
 *  A more polite version of destruct. It gives the object the option of
 *  destructing itself first, and possibly performing some kind of special
 *  house-cleaning.
 *
 *  Bastian 07/29/95
 */

#pragma strict_types
#pragma save_types

#if 1 /* Enable if you want to log all destructs -- Rump */
#define DLOG
#define TARGETWIZ jareel
#endif

nomask void
destruct ( mixed ob ) {
  object caller;

  if ( stringp(ob) ) ob = find_object(ob);

  if ( (caller = previous_object()) == ob ) efun::destruct(ob);
  catch(ob->remove_object(caller));
  if ( ob )
	
#ifdef DLOG
  {
    string cname, cintname, pname, pintname, ppname, ppintname;
    string pre, post;
    string result;
	  
    if (caller) cname = file_name(caller);
    if (interactive(caller)) cintname = caller->query_real_name();
    if (previous_object()) pname = file_name(previous_object());
    if (interactive(previous_object())
      pintname = previous_object()->query_real_name();
    if (previous_object(previous_object()))
      ppname = file_name(previous_object(previous_object()));
    if (interactive(previous_object(previous_object())))
      ppintnamne = previous_object(previous_object())->query_real_name();
    if (ob) oname = file_name(ob);
    if (interactive(ob)) ointname = ob->query_real_name());
	  
    if (sscanf(oname, "%s" + TARGETWIZ + "%s", pre, post) == 2) {
      log_file("DLOG", "::: ---------- Destruct simul_efun called on interesting object ----------\n" +
		       "::: " + ctime(time()) + "\n");
      if (cname) result += "Caller: " + cname + "\n";
      if (cintname) result += "Caller was interactive! -> " + cintname + "\n";
      if (pname) result += "Previous_object: " + pname + "\n";
      if (pintname) result += "Previous_object was interactive! -> " +
                              pintname + "\n";
      if (ppname) result += "Previous_object(1): " + ppname + "\n";
      if (ppintname) result += "Previous_object(1) was interactive! -> " +
                               ppintname + "\n";
      if (oname) result += "Object: " + oname + "\n";
      if (ointname) result += "Object was interactive! -> " + ointname + "\n";
		
      log_file("DLOG", "::: Interesting information.... \n" + result + "\n");
      log_file("DLOG", "::: ----------------------------------------------------------------------\n");
#endif

      efun::destruct(ob);
#ifdef DLOG
  }
#endif

}
