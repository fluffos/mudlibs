int cmd_errormsgs()
{
 int em;

 write("Error messages: ");

 if(this_player()->query_errormsgs())
 {
  write("OFF\n");
  this_player()->set_errormsgs(1);
 }

 else
 {
  write("ON\n");
  this_player()->set_errormsgs(0);
 }
 return 1;
}
