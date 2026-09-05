/*
 *  A more polite version of destruct. It gives the object the option of
 *  destructing itself first, and possibly performing some kind of special
 *  house-cleaning.
 *
 *  Bastian 07/29/95
 */

#pragma strict_types
#pragma save_types

#if 0 /* Enable if you want to log all destructs -- Rump */
#define DLOG
#endif

nomask void
destruct ( mixed ob ) {
    object caller;

#ifdef DLOG
  log_file("DLOG", "::: destruct simul_efun called - " + ctime(time()) + "\n");
  if (previous_object())
    log_file("DLOG", ":::    previous_object is " +
                     file_name(previous_object()) + "\n");
  else log_file("DLOG", ":::    No previous_object() !!!\n");
#endif

    if ( stringp(ob) ) ob = find_object(ob);

#ifdef DLOG
  if (ob) log_file("DLOG", ":::    ob is " + file_name(ob) + "\n");
  else log_file("DLOG", ":::   No 'ob' variable!!\n");
#endif

    if ( (caller = previous_object()) == ob )
        efun::destruct(ob);
    catch(ob->remove_object(caller));
    if ( ob )
        efun::destruct(ob);
}
