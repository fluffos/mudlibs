/*  -*- LPC -*-  */
#include <command.h>

int
main(string arg)
{
  int code;
  
  write("Shutting down imediately...\n");
  log_file("shutdown",
	   sprintf("mud shut down by %s\n", this_player()->query_cap_name()));

  if( arg )
    code = to_int(arg);
  
  shutdown(code);
  return 1;
}
