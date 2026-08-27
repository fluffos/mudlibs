/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

void callback(string file, string head, string* buf);

int
main()
{
  string header;
  string dir = this_player()->query_cwd();

  header = sprintf("%s (%s (%s))\n", ctime(time()),
		   this_player()->query_connection()->query_email_addr(),
		   this_player()->query_cap_name());
  header = break_string(header, 79);

  printf("Editing ChangeLog for directory %s...\n", dir);

  EDITOR_D->edit((: callback, dir + "/ChangeLog", header :));
  return 1;
}

void
callback(string file, string head, string* buf)
{
  if( !sizeof(buf) ) {
    write("ChangeLog edit aborted.\n");
    return;
  }

  if( !NEWSSERVER->new_post("mudlib.devel.changes", "no-thread", file,
			     this_player()->query_name(),
			     implode(buf, "\n") + "\n") )
    write("Newsgroup post failed.\n");

  write_file(file, head);
  write_file(file, "    " + implode(buf, "\n    ") + "\n\n");
  printf("Appended to %s\n", file);
}
