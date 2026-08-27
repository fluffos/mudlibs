#include <command.h>
#include <daemons.h>
#include <dirs.h>
#include <time.h>

inherit INHERIT_DIR "/time";

string *sections = ({
  "",                               // man1
  "Simulated External Functions",   // man2
  "LPC Library Functions",          // man3
  "Driver Applies",                 // man4
});

string* sequence = ({
  "NAME",
  "SYNOPSIS",
  "DESCRIPTION",
  "RETURN VALUES",
  "ENVIRONMENT",
  "FILES",
  "EXAMPLES",
  "ERRORS",
  "SEE ALSO",
  "HISTORY",
  "BUGS"
});

void get_info(string fname, int part, string* buf);

int
main(string arg)
{
  int section = to_int(arg);

  if(!section || section > sizeof(sections))
    return notify_fail("usage: mkmp <section>\n");

  write("Function name: ");
  input_to("get_fname", 0, arg, 0);
  return 1;
}

void
write_section(int sec, string fname, string text)
{
  write_file(fname, ".Sh " + sequence[sec] + "\n");
  write_file(fname, text + "\n");
}

void
get_fname(string input, string fname)
{
  string section = fname;
  fname = RESOLVE_PATH(input + "." + section);
  write_file(fname, ".Dd " + get_date(time(), DATESTR_DATE)
	     + " " + get_date(time(), DATESTR_YEAR) + "\n");
  write_file(fname, ".Dt " + upper_case(input) + " " + section
	     + " \"" + sections[to_int(section) - 1] + "\"\n");
  write_file(fname, ".Os \"" + mudlib_name() + " " +
	     mudlib_version() + "\"\n");
  write("Enter short description of function to be used by man -k.\n");
  EDITOR_D->edit((: get_info, fname, 0 :), ({ input }));
}

void
get_info(string fname, int part, string* buf)
{
  switch(part) {
  case 0: /* Name */
    write_section(0, fname, ".Fn " + buf[0] + "\n" + implode(buf[1..], "\n"));
    write("Enter function prototypes (one per line).:\n");
    EDITOR_D->edit((: get_info, fname, 1 :));
    break;
  case 1: /* Synopsis */
    write_section(1, fname, ".Fd " + implode(buf, "\n.Fd "));
    write("Enter DESCRIPTION field\n");
    EDITOR_D->edit((: get_info, fname, 2 :));
    break;
  default:
    if(sizeof(buf)) 
      write_section(part, fname, implode(buf, "\n"));
    if(++part > sizeof(sequence) - 1) {
      write("Done!\n");
      return;
    }
    write("Enter " + sequence[part] + " field.  Leaving blank omits field.\n");
    EDITOR_D->edit((: get_info, fname, part :));
  }
}
