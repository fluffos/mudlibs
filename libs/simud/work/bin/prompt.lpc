#include <textdraw.h>
// Allows players to reset their prompts to a custom string

main( string message ) {
  if ( message ) {
    if ( message == "0" || message == "clear" || message == "none" ||
         message == "off" || message == "\"\"" ) {
      this_player()->set_default_prompt( "" );
      this_player()->set_curr_prompt( "" );
      this_player()->update_prompt();
      return 1;
    }
    if ( strstr( message, "~C", 0 ) == -1 )
       message = recolor( message );
    if (strlen(message) <= 80) {
      this_player()->set_default_prompt( message + " " );
       this_player()->set_curr_prompt( message + " " );
      this_player()->update_prompt();
    } else
      msg( "~CDEFPrompts must be 80 characters or less, I mean, honestly..." );
  } else {
      msg( "~CDEFSet your prompt to what?" );
  }
  return 1;
}
