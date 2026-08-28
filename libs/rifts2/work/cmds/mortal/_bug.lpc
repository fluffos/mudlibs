//	_bug.c
//	original written by Sulam 030192
//	help added by Buddha 180192
//	logging for individual creators added by Descartes 201092
//      Edit, word wrap added by Manny 100893
 
#include <std.h>
#include <dirs.h>
#include <security.h>
#include <daemons.h>
 
inherit DAEMON;
 
int cmd_bug(string text);
int report(string *lines);
void end_text();
void abort();
string file;
 
 
int cmd_bug(string text) {
    string *lines;
    string str, new_text;
    object ob;

    if(!text || ob = present(text,this_player()) ||
      ob = present(text, environment(this_player()))) {
        rm(DIR_TMP+"/"+geteuid(previous_object())+".bug");
        file = file_name(ob ? ob : environment(previous_object()));
        previous_object()->edit(DIR_TMP+"/"+geteuid(previous_object())+".bug",
            "end_edit", this_object());
        return 1;
    }
    if(sscanf(text, "%s %s", str, new_text) == 2) {
        if(!(ob = present(str, this_player())) &&
          !(ob = present(str, environment(this_player()))))
            new_text = str+" "+new_text;
    }
    if(!ob) ob = environment(this_player());
	  file = file_name(ob);
          text = file + ": "+text;
          lines = explode(wrap(text), "\n");
          report(lines);
          return 1;
}
 
end_edit() {
  string *lines;
  string tmpfile;
    tmpfile = file+":\n"+read_file(DIR_TMP+"/"+geteuid(this_player())+".bug");
    lines = explode(wrap(replace_string(tmpfile, "\n", " "), 77), "\n");
  rm("/tmp/"+this_player()->query_name()+".bug");
  report(lines);
}
 
report(string *lines) {
  string who, *elements;
  int x;
 
  elements = explode(file, "/");
  if(elements[0] == "wizards") who = elements[1];
  else if(elements[0] == "d") who = elements[1];
  else who = 0;
  
  seteuid(UID_LOG);
  log_file("bugs", "Bug reported by "+this_player()->query_cap_name()+
            " "+ctime(time())+":\n");
  if(who) log_file("reports/"+who, "Bug reported by "+
                    this_player()->query_cap_name()+":\n");
  x = -1;
  while(++x < sizeof(lines)) {
    log_file("bugs", lines[x]+"\n");
    if(who) log_file("reports/"+who, lines[x]+"\n");
  }
  INFORM_D->do_inform("typos,_bugs,_etc.","Bug ("+(string)this_player()->
	query_cap_name()+"): "+implode(lines,"\n"));
  seteuid(getuid());
  write("Bug reported!  Thank you!\n");
  return 1;
}
 
void abort() {
  notify_fail("Bug report aborted.\n");
  rm("/tmp/"+this_player()->query_name()+".bug");
  return 0;
}

int help() {
message("help",
"This command may be used to report bugs with the game.  "
"DO NOT use this command to report suggestions.  Remember that if you "
"overuse this command, we won't be able to get to the real bugs.  "
"Use the idea command for suggestions, and the typo command for typos.\n"
"Usage: bug <text>",
this_player());
return 1;
}
