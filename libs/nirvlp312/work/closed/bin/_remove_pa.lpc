#define DAEMON "/pa/admin/pa-daemon"

int cmd_remove_pa(string str)
{
  object ob;
  if(!str) {
    write("Remove who as a PA wiz ?\n");
    return 1;
  }
  if(!DAEMON->query_name(str)) {
    write(str+" isn't a PA wiz.\n");
    return 1;
  }
  DAEMON->delete_name(str);
  write("Done.\n");
  return 1;
}
