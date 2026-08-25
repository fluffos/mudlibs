#include "gopher.h"

int query_type() { return '7'; }

void create() {
  seteuid(getuid());
} /* create() */

string do_gopher(string *bits) {
  rm(GOPHER_PATH+"/.finger_results");
  if (sizeof(bits) < 2) {
    rm(GOPHER_PATH+"/.finger_results");
    bits += ({ "" });
/*
    write_file(GOPHER_PATH+"/.finger_results", "Failed utterly.\n");
 */
  }
  write_file(GOPHER_PATH+"/.finger_results",
             (string)"/secure/finger"->finger_info(bits[1]));
  return "0Finger results\t0/.finger_results\t"+MACHINE_NAME+
         "\t"+GOPHER_PORT+"\n";
} /* do_gopher() */
