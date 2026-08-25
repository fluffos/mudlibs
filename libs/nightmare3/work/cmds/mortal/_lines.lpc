// /cmds/mortal/_lines.c
// From Nightmare IV
// A utility to help wizards and players keep track of what lines they're
// on, and to them turn all off and on with one command.
// by Gregon@Nightmare
 
 
int cmd_lines(string str) {
 
string *channels;
int i;
 
channels = distinct_array((string *)this_player()->query_channels());
 
  if(!str) {
   for(i=0; i<sizeof(channels); i++) {
    if(this_player()->query_blocked(channels[i]))
      message("info","You are blocking "+channels[i]+".",this_player());
    else message("info","You are not blocking "+channels[i]+".",this_player());
   }
   return 1;
  }
 
  if(str=="on"){
      for(i=0; i<sizeof(channels);i++){
      if(this_player()->query_blocked(channels[i]))
        this_player()->set_blocked(channels[i]);
     }
     return 1;
   }
 
  if(str=="off"){
      for(i=0; i<sizeof(channels);i++){
      if(!this_player()->query_blocked(channels[i]))
        this_player()->set_blocked(channels[i]);
     }
     return 1;
  }
 
}		
 
void help(){
   message("help","Syntax: lines -or- lines [on|off]\n\n" 
           "With no argument this command will display the status "
           "of the lines to which you have access.  With the argument on|off "
           "it will turn all of the lines on or off.",this_player());
}
