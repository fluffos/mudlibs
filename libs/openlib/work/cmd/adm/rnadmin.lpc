#include <command.h>
#include <daemons.h>

#define display(X) message("system", X, this_player())
#define VERSION "0.1"

int
main()
{
  display("RnAdmin v"+VERSION+" NEWS administion tool.\n"
	  "Created by Tim@UltraLib.\n\n"
	  "Type ? for help.\n"
	  ": ");
  input_to("main_loop");
  return 1;
}

void
main_loop(string input)
{
  string* args = explode(input, " ")[1..];

  switch(input[0]) {
  case 0:
    /* Blank line or input == "" */
    break;
  case '?':
    display("Help for RnAdmin:\n"
	    "n <name> [domain_name]   Create a new newsgroup with optional\n"
	    "                         domain restriction.\n"
	    "d <name>                 Delete the named newsgroup.\n"
	    "l                        List known newsgroups.\n"
            "q                        Quit RnAdmin.\n");
    break;
  case 'n':
    if( sizeof(args) != 1 && sizeof(args) != 2 )
    {
      display("Failed command.\n");
      break;
    }
    else
    {
      if( NEWSSERVER->create_group(args...) )
	display("Newsgroup created.\n");
      else
	display(query_notify_fail());
    }
    break;
  case 'd':
    if( sizeof(args) != 1 )
    {
      display("Failed command.\n");
      break;
    }
    else
    {
      if( NEWSSERVER->delete_group(args[0]) )
	display("Deleted newsgroup.\n");
      else
	display(query_notify_fail());
    }
    break;
  case 'l':
  {
    mixed* list = NEWSSERVER->get_group_list();
    string text = "";

    foreach(mixed* groupinfo in list)
      text += sprintf("%s: %d-%d\n", groupinfo...);

    this_player()->more(explode(text, "\n"), (: main_loop, "" :));
    return;
  }
  case 'q':
    display("Exiting.\n");
    return;
  default:
    display("Unknown command.\n");
  }
  display(": ");
  input_to("main_loop");
}
