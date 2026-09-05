/* 08/19/06 Earwax: Daemonized */

int cmd_setmail(string addr) {
  string mailaddr;

  if(!addr)
  {
    write("Your current email address is ");
    write((string)this_player()->query_mailaddr());
    write("\nType setmail <arg> to list a new one.\n");
    return 1;
  }
  
  this_player()->set_mailaddr(addr);
  write("Your email address is now: ");
  write(addr); write("\n");
  return 1;
}
