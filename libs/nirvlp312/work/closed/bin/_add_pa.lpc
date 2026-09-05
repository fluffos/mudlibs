#define DAEMON "/pa/admin/pa-daemon"

int cmd_add_pa(string str)
{
  object ob;
  if(!str) {
    write("Add who as a PA wiz ?\n");
    return 1;
  }
  if(!valid_wizard(str)) {
    write(str+" is not a wizard.\n");
    return 1;
  }
  if(DAEMON->query_name(str)) {
    write(str+" is already a PA wiz.\n");
    return 1;
  }
  DAEMON->add_name(str);
  write("Done.\n");
  return 1;
}
