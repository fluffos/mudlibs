/*  -*- LPC -*-  */
#include <command.h>
#include <net/daemons.h>

#define PROMPT "iftp> "

int
main(string arg)
{
  if( !arg ) return notify_fail("usage: iftp <mudname>\n");

  if( !(arg = INTERMUD_D->GetMudName(arg)) )
    return notify_fail(mud_name() + " is not aware of such a place.\n");

  OOB_D->OOBBegin(arg, 0, (: write($1 + "\n") :));
  input_to("input_loop", 0, arg, "/");
  printf("Making FTP connect to %s.\n", arg);
  write(PROMPT);

  return 1;
}

void
input_loop(string input, string mud, string cwd)
{
  string verb, args;

  if( sscanf(input, "%s %s", verb, args) != 2 ) verb = input;
  if( !args ) args = "";

  switch(verb) {
  case "":
    break;
  case "?": case "help":
    write("Commands:\nquit (bye), cd, pwd (cwd), ls, help (?)\n");
    break;
  case "cd":
    cwd = absolute_path(cwd, args);
  case "pwd": case "cwd":
    printf("CWD is now %s\n", cwd);
    break;
  case "ls":
    args = absolute_path(cwd, args);
    SERVICES_D->eventSendFileListRequest(mud, args[1..]);
    write("FILE LIST request sent.\n");
    break;
  case "get":
    if( !sizeof(args) )
      write("usage:  get <remote filename>\n");
    else {
      args = absolute_path(cwd, args);
      SERVICES_D->eventSendFileGetRequest(mud, args[1..]);
      write("FILE GET request sent.\n");
    }
    break;
  case "put":
    if( !sizeof(args) )
      write("usage:  put <file>\nput <localfile> <remotefile>\n");
    else {
      string loc, rem;
      if( sscanf(args, "%s %s", loc, rem) == 2 ) {
	loc = RESOLVE_PATH(loc);
	rem = absolute_path(cwd, rem);
      } else {
	loc = RESOLVE_PATH(args);
	rem = absolute_path(cwd, args);
      }
      if( !file_exists(loc) )
	printf("file %s does not exist.\n", loc);
      else {
	SERVICES_D->eventSendFilePut(mud, rem[1..], read_file(loc));
	write("FILE PUT request sent.\n");
	printf("local: %s\n", loc);
      }
    }
    break;
  case "quit": case "bye":
    OOB_D->OOBEnd(mud);
    write("OOB END request sent.\nGoodbye!\n");
    return;
  default:
    write("Unrecognized command.\n");
  }

  write(PROMPT);
  input_to("input_loop", 0, mud, cwd);
}
