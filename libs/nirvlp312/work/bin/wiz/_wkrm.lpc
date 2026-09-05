int cmd_wkrm(string str)
{
 object soul;
 if(!str)
 {
  write("Usage: 'wkrm <file>', or 'wkrm |' to clear.\n");
  return 1;
 }
 if(!(soul = present("wiz_soul", this_player())))
 {
  write("You need a soul.\nType 'soul on'.\n");
  return 1;
 }
 if(str == "|")
 {
  soul->set_alt_wkrm(0);
  this_player()->update(10);
  write("Ok.\nWorkroom cleared.\n");
  return 1;
 }
 if(!(str = (string)this_player()->valid_read(str)))
 {
  write("Bad file name.\n");
  return 1;
 }
 soul->set_alt_wkrm(str);
 this_player()->update(10);
 write("Ok.\nWorkroom updated to: "+str+"\n");
 return 1;
}

