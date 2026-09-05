#ifndef SARLF_H
#define SARLF_H

/*
 * SARLF - Search and replace logged functions
 *
 * This fn logs into /log/SARLF the filename of this object, and sets
 * the format to allow /obj/sarlf to replace the string 'old' with 'new'.
 * This has been done to make the changing of some old functions to the
 * newer function.
 *
 * Thus outdated functions can be easily replaced
 *
 */

void log_sarlf(string old, string new) {
  string file;
  int i;

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);
  if (sscanf(file, "inherit/%s", file) ||
      sscanf(file, "obj/%s", file)) {      /* don't log these files */
    file = file_name(previous_object());
    sscanf(file, "%s#%d", file, i);
    if (sscanf(file, "inherit/%s", file) == 1 ||
        sscanf(file, "obj/%s", file) == 1) {
      return;
    }
  }
  file = "/" + file + ".lpc";
  log_file("SARLF", file + ":" + old + ":" + new + "\n");
}

#endif

