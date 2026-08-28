#include <ansi.h>

int main() {
  mapping poks;

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

  poks = rusage();

  printf (C_IN1 + "%-39s   %-30s"+C_NRM+"\n", "The resources utilized", "Amount");
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "user time used", poks["utime"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "system time used", poks["stime"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "maximum resident set size", poks["maxrss"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "integral resident set size", poks["idrss"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "page faults not requiring physical I/O", poks["minflt"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "page faults requiring physical I/O", poks["majflt"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "swaps", poks["nswap"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "block input operations", poks["inblock"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "block output operations", poks["oublock"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "messages sent", poks["msgsnd"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "messages received", poks["msgrcv"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "signals received", poks["nsignals"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "voluntary context switches", poks["nvcsw"]);
  printf ("%-39s : "+C_BLD+"%i"+C_NRM+"\n", "involuntary context switches", poks["nivcsw"]); 

  return 1;
}

