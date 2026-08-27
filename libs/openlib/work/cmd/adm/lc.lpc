#include <command.h>
#include <net/daemons.h>

class con
{
  string name;
  int i;
}

int
main()
{
  mapping Q;
  Q = OOB_D->dump_conns();

  write("Connected:\n");
  foreach(int fd, class con item in Q) {
    printf("fd=%i: %s\n", fd, item->name);
  }
  return 1;
}
