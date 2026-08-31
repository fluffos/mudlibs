//      /cmds/mortal/_suicide
//      -- seeker
         
#include <std.h>

void unlock_terminal(string pa)
{
 string pass, str;
 object ob;
if(((pass = (string)this_player()->query_password()) !=oldcrypt(pa, pass)) &&
      ((string)this_player()->query_password() != crypt(pa, pass)))
  {
write("Incorrect password:  Please enter your password: ");
input_to("unlock_terminal");
   return 1;
  }
write("Terminal Unlocked:  Returning to play.\n");
return 0;
 }

int cmd_secure(string str) {
if(!str) return 0;
if(str != "terminal") return 0;

write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
write("Terminal Secure:  Please enter your password: ");
    input_to("unlock_terminal", I_NOECHO | I_NOESC);
log_file("", "");
    return 1;
}

void help() {
  write( @EndText
Syntax: secure terminal
Effect: This will lock your terminal preventing 
any commands from being used without entering your 
password.
EndText
  );
}

