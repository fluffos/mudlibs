/*  -*- LPC -*-  */
#include <cmdline.h>
#include <login.h>

#define USAGE "usage:\
 last [-<number>] [-h <hostname>] [-i <address>] [name...]\n"

int
main(string *argv, string *argv2)
{
  string* names = ({});  // list of usernames
  string hostname;       // hostname to match
  string address;        // address to match
  int count, number;     // number of entries displayed/to display
  int long;
  string* lines;
  int curr_line = 1;
  int i;

  if(sizeof(argv) > 1) {
    if(sscanf(argv[1], "-%d", number) == 1)
      i = 2;
    else
      i = 1;

    for(; i < sizeof(argv); i++) {
      switch(argv[i]) {
      case "-h":
	if(i+1 >= sizeof(argv))
	  return notify_fail(USAGE);
	else
	  hostname = argv[++i];
	break;
      case "-i":
	if(i+1 >= sizeof(argv))
	  return notify_fail(USAGE);
	else
	  address = argv[++i];
	break;
      case "-l":
	long = 1;
	break;
      default:
	if(argv[i][0] == '-')
	  return notify_fail(USAGE);
	else
	  names += ({ argv[i] });
      }
    }
  }

  lines = explode(read_file(LASTLOG), "\n");

  for(i = sizeof(lines)-1; i >= 0; i--) {
    string line = lines[i];
    int disp_line = FALSE;

    if(number && count == number)
      break;
    
    if(!hostname && !address)
      disp_line = TRUE;
    else if(hostname && !strsrch(line[12..], hostname))
      disp_line = TRUE;
    else if(address && !strsrch(line[60..], address))
      disp_line = TRUE;

    if(disp_line && sizeof(names)) {
      disp_line = FALSE;

      foreach(string nm in names) {
	if(!strsrch(line, nm)) {
	  disp_line = TRUE;
	  break;
	}
      }
    }

    if(disp_line && line != "") {
      if(long)
	write(line +"\n");
      else
	write(line[0..<18] + "\n");

      count++;
    }
  }
  
  return 1;
}
