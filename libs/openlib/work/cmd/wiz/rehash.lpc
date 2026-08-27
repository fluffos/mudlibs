#include <command.h>
#include <daemons.h>

void do_rehash(string arg);

int
main(string arg)
{
  if(!arg) {
    string path;

    foreach(path in this_player()->query_path()) {
      printf("%s: ", path);
      do_rehash(path);
    }
  } else {
    do_rehash(arg);
  }

  return 1;
}

void
do_rehash(string arg) {

  if(CMD_D->hash_path(arg))
    write("Ok.\n");
  else
    write("Failed.\n");
}
