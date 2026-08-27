/*  -*- LPC -*-  */
#include <command.h>
#include <mudlib.h>
#include <time.h>

inherit INHERIT_DIR "/time";

#define USAGE \
"usage: makemanpg <section #>"\
"  sections are:\n"\
"    1: nothing\n"\
"    2: Simulated External Functions\n"\
"    3: LPC Library Functions\n"\
"    4: Driver Applies\n"\
"    5: Player Commands\n"\
"    6: Wizard Commands\n"\
"    7: Admin  Commands"

string *sections = ({
  "",                               // man1
  "Simulated External Functions",   // man2
  "LPC Library Functions",          // man3
  "Driver Applies",                 // man4
  "Player Commands",                // man5
  "Wizard Commands",                // man6
  "Admin Commands",                 // man7
});

void
write_manpg(mapping cmdinfo)
{
  string date = cmdinfo["date"],
         name = cmdinfo["name"],
         short_desc = cmdinfo["short_desc"],
         *synopsis = cmdinfo["synopsis"],
         *description = cmdinfo["description"],
         *see_also = cmdinfo["see_also"];
  int section = cmdinfo["section"];
  string line;
  string outfile;

  outfile = RESOLVE_PATH(name +"."+ section + ".nroff");

  write_file(outfile, ".\\\""+ short_desc +"\n", 1);
  write_file(outfile, ".TH "+ name +" "+ section + " \"" + date +
	     "\" Ultralib \""+ sections[section-1] +"\"\n\n");
  write_file(outfile, ".SH NAME\n");
  write_file(outfile, short_desc + "\n\n");
  write_file(outfile, ".SH SYNOPSIS\n");
  foreach(line in synopsis)
    write_file(outfile, line +"\n");
  write_file(outfile, "\n");
  write_file(outfile, ".SH DESCRIPTION\n");
  foreach(line in description)
    write_file(outfile, line +"\n");
  write_file(outfile, "\n");
  write_file(outfile, ".SH SEE ALSO\n");
  foreach(line in see_also)
    write_file(outfile, line +"\n");
  
  printf("\n Output file %s has been created.\n", outfile);
}
  
int
main(string arg)
{
  mapping cmdinfo = ([]);
  string date = get_date(time(), DATESTR_DATE) +" "+
                get_date(time(), DATESTR_YEAR);

  cmdinfo += ([ "date" : date ]);
  cmdinfo += ([ "synopsis" : ({}) ]);
  cmdinfo += ([ "description" : ({}) ]);
  cmdinfo += ([ "see_also" : ({}) ]);

  if(!arg)
    return notify_fail(USAGE +"\n");

  cmdinfo["section"] = to_int(arg);
  write("File Name (don't use parens): ");
  input_to("get_cmd_name", 0, cmdinfo);
  return 1;
}

void
get_cmd_name(string input, mapping cmdinfo)
{
  cmdinfo["name"] = input;
  write("Enter NAME line--short descrip--not usage (less than 1 line):\n");
  input_to("get_short_desc", 0, cmdinfo);
}

void
get_short_desc(string input, mapping cmdinfo)
{
  cmdinfo["short_desc"] = input;
  write("Enter SYNOPSIS (usage) (usally 1 line); end with ** on a line by itself.\n");
  input_to("get_synopsis", 0, cmdinfo);
}

void
get_synopsis(string input, mapping cmdinfo)
{
  if(input != "**") {
    cmdinfo["synopsis"] += ({ input });
    input_to("get_synopsis", 0, cmdinfo);
    return;
  }
  write("Enter DESCRIPTION of command; end with ** on a line by itself\n");
  input_to("get_description", 0, cmdinfo);
}

void
get_description(string input, mapping cmdinfo)
{
  if(input != "**") {
    cmdinfo["description"] += ({ input });
    input_to("get_description", 0, cmdinfo);
    return;
  }
  write("Enter SEE ALSO for command; end with ** on a line by itself\n");
  input_to("get_see_also", 0, cmdinfo);
}

void
get_see_also(string input, mapping cmdinfo)
{
  if(input != "**") {
    cmdinfo["see_also"] += ({ input });
    input_to("get_see_also", 0, cmdinfo);
    return;
  }
  write_manpg(cmdinfo);
}

string
help()
{
  return "MANPAGE:cat5/makemanpg.6";
}
