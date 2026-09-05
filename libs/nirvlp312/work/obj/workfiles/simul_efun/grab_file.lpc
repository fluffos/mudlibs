/*
 * grab_file sefun for compatibility
 * Rumplemintz
 */

varargs string *grab_file(string path, int start, int len) {
  set_this_object(previous_object());
  return explode(read_file(path, start, len), "\n");
  /* Don't call this locally, unless you add code to set this_object()
     back.
   */
}

