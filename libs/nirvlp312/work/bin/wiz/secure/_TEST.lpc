#include "/sys/temp.h"

int cmd_TEST(string arg) {
  mixed blah;

  if (DR_RUNNING) return 0;
  blah = unguarded(#'write_file,"/bin/wiz/secure/TESTING", ctime()+": Successful.\n");
  write("RESULTS: "+blah+"\n");
  return 1;
}
