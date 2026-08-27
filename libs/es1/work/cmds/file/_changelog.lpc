//#pragma save_binary
/* _changelog.c
 * original author: wayfarer
 * date: 12/8/91
 * note: adds an entry into the ChangeLog file in the named domain
 * bugs: no error checking on non-existant domains
 * Modified for the TMI distribution mudlib by Buddha (1/9/92)
 * Changed to fit into the /cmds command structure, setting its
 * euid to the current user, then self-destructs to reduce memory use.
 * Also created a stack of active users, so that any number of people can
 * use this command at one time.
 * (93-03-20) Pallando changed a hardwired reference to the tmp dir.
 *  93-07-30  Grendel added logging to a central log, and turned about
 *                four write_file()s into one big one.
 */

#include <uid.h>
#include <config.h>
#include <mudlib.h>
#include <logs.h>

inherit DAEMON ;

 string *files, *coders;

void create() { seteuid(ROOT_UID); coders = ({}); files = ({}); }

int get_ref() { 
	return member_array(geteuid(this_player()), coders);
}
void push_coder(string file) {
        string who;
        who = geteuid(this_player());
        coders += ({ who });
	files += ({ file });
}
void pop_coder(int ref) {
	coders -= ({ coders[ref] });
	files -= ({ files[ref] });
}
int cmd_changelog(string path) {
   string who, tmp;
   who = geteuid(this_player());
   if (!path)  path = (string)this_player()->query("cwd");
   path = resolv_path((string)this_player()->query("cwd"), path);
   if (!master()->valid_write(path + "/ChangeLog", this_player(),
      "write_file")) {
      write("You don't have permission to write there!\n");
      return 1;
   }
   push_coder(path + "/ChangeLog");
   write("Editing ChangeLog for " + path + "\n");
   this_player()->edit(TMP_DIR+"changelog_"+who,"changelog_done",
		this_object());
   return 1;
}

void changelog_done() {
   string old, msg, infile, clfile;
   string *lines, *newlines;
   string entry;
   int count, i, j;
   
   infile = (string)this_player()->query_edit_filename();
   msg = read_file(infile);
   if (msg == "" || !msg) return;
   clfile = files[get_ref()];
   old = read_file(clfile);
   rm(clfile);
   entry = sprintf("%s   %s   (%s at %s)\n\n\t* ", ctime(time()),
      (string)this_player()->query_link()->query("real_name"),
      (string)this_player()->query("cap_name"),
      query_ip_name(this_player()));
   lines = explode(msg," ");
   if (lines)
      for (i = 0; i < sizeof(lines); i++) {
      newlines = explode(lines[i],"\n");
      if (!newlines) newlines = ({lines[i]});
      for (j = 0; j < sizeof(newlines); j++) {
         if (newlines[j] == 0)
            continue;
         if (count + strlen(newlines[j]) >= 65) {
            entry += "\n\t";
            count = 0;
           }
         entry += newlines[j] + " ";
         count += strlen(newlines[j]) + 1;
         }
   }
   entry += "\n\n";
   write_file(clfile,entry);
#ifdef MASTER_CHANGELOG
   log_file(MASTER_CHANGELOG,"---"+clfile+"---\n"+entry);
#endif
   if (old)
      write_file(clfile, old);
   rm(infile);
   write("Updated ChangeLog.\n");
   pop_coder(get_ref());
}

void abort() {
   write ("changelog aborted\n");
   return;
}
int help() {
    write("Usage: changelog <directory>\n"+@HELP

  Updates the ChangeLog file in either the current directory (If no
directory is specified) or the specified directory.  This will put you
in an editor, like the one on the bulletin boards.  This is useful for
keeping a record of the changes that have been made in the directory in
question.
HELP
	);
    return 1;
}

void clean_up() {
    if (!sizeof(coders) && !sizeof(files))
        destruct(this_object());
}
