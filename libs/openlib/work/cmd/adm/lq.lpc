#include <command.h>
#include <element.h>
#include <net/daemons.h>

int
main()
{
  element* Q;
  Q = OOB_D->dump_queue();

  write("Queued:\n");
  foreach(mixed mud in Q) {
    printf("%s: %O\n", ((element) mud)->key, ((element) mud)->val);
  }

  return 1;
}
