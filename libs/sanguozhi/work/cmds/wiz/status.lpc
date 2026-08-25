// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

#define DELIM write(repeat_string("-", 70) + "\n")

inherit CMD;

void main() {
  mapping text = ([
      "utime":"user time used",
      "stime":"system time used",
      "maxrss":"maximum resident set size",
      "idrss":"integral resident set size",
      "minflt":"page faults not requiring physical I/O",
      "majflt":"page faults requiring physical I/O",
      "nswap":"swaps",
      "inblock":"block input operations",
      "oublock":"block output operations",
      "msgsnd":"messages sent",
      "msgrcv":"messages received",
      "nsignals":"signals received",
      "nvcsw":"voluntary context switches ",
      "nivcsw":"involuntary context switches"
      ]);
  
  DELIM;
  printf("%-39s   %s\n",
         "资源用途","量");
  DELIM;

  foreach (string key, mixed value in rusage())
      printf("%-39s : %i\n", text[key] || key, value);

  DELIM;

  return;
}

