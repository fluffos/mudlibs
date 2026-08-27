#include <command.h>

int
main()
{
  string *lines;

  lines = explode(dump_socket_status(), "\n");

  foreach(string line in lines) {
    if(strsrch(line, "CLOSED") == -1)
      write(line + "\n");
  }

  return 1;
}
