#include <command.h>

int
main()
{
  mixed* info = call_out_info();
  
  write("CH   Object                                      Func\n");
  
  foreach(mixed* ca in info)
    printf("%:3i  %-:40O  %-:20s\n", ca[2], ca[0], ca[1]);
  return 1;
  
}
