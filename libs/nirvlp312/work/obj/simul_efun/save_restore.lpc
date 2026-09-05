/*
 * Temporary sefuns to make sure original files are not getting messed with
 * when running/testing LD driver.
 * Adds "_LD" to the end of the filename when saving with save_object
 *
 * Checks for the existence of _LD on the filename when doing a restore
 * and restores that version on LD - if it exists
 *
 * Rumplemintz@Nirvana
 */


varargs mixed
save_object(string path, int flag)
{
  object ob = this_object();
  mixed retval;

  set_this_object(previous_object());
#ifdef __LDMUD__                /* LD Driver - Append the _LD */
  string * path_parts = explode(path, ".");
  path_parts[0] += "_LD";
  string new_path = implode(path_parts, ".");
  retval = efun::save_object(new_path, flag);
#else                           /* Amylaar driver, just pass on to the efun */
  retval = efun::save_object(path, flag);
#endif
  set_this_object(ob);
  return retval;
}

int
restore_object(string path)
{
  object ob = this_object();
  int retval;
  set_this_object(previous_object());
#ifdef __LDMUD__
  if (file_size(path + "_LD.o") != -1)
    retval = efun::restore_object(path + "_LD");
  else
    retval = efun::restore_object(path);
#else
  retval = efun::restore_object(path);
#endif
  set_this_object(ob);
  return retval;
}

