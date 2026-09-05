/*
 * _describe.c
 * bin version of command for players to enter their own desc
 * the player's name is still automatically prepended
 */

cmd_describe() {
  string current;
  current=this_player()->query_description();
  if(current) {
    current=capitalize(this_player()->query_real_name()+" "+current);
    write("Current description loaded for editing. (~l to show it)\n");
  }
  write("If your description does not start with your name followed by a space,\n"+
        "they will be automaticalled prepended after you save.\n"+
        "Enter 'clear' (without quotes) on a blank line and save to have no\n"+
        "description.\n");
  call_other("/obj/user/text_edit","start_edit",this_object(),"end_edit",10,current);
  return 1;
}

end_edit(string str) {
  string name;
  int len;
  name=this_player()->query_real_name();
  len=strlen(name);
  if(!str) {
    write("Description not changed.\n");
    return;
  } else if(str[0..4]=="clear") {
    str=0;
    write("Description cleared.\n");
  }
  else if(lower_case(str[0..len-1])==name+" ")
#ifndef __LDMUD__ /* Rumplemintz */
    str=str[len+1..-1];
#else
    str = str[len+1..<1];
#endif

  write("Description saved.\n");
  this_player()->set_description(str);
}
