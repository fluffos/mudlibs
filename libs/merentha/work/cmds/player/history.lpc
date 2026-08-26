// Petrarch
// Merentha Lib 1.0
// <history>

string help() {
return "\
Syntax: history\n\
This command displays the history of the last 15 lines typed.  You can\n\
repeat any of these lines with the ! operator as follows:\n\n\
!!  =  repeat the last line type\n\
!4  =  repeat line 4\n\
!a  =  repeat the last command starting with the letter 'a'";
}

int command() {
string *history=this_player()->query_history();
int i=sizeof(history), j;

for (j=0;j<i;j++) 
  message("command", ""+(j+1)+" : "+history[j], this_player());

  return 1;
}

