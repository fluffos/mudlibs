#include <textdraw.h>
// The AFK verb (Away From Keyboard)

main(string message) {
  if (message) {
    if (message == "0" || message == "clear" || message == "none" ||
        message == "off") {
      this_player()->set_afk(0);
      this_player()->set_curr_prompt( this_player()->query_default_prompt() );
      this_player()->update_prompt();
      msg("~CDEFAFK message cleared");
      this_player()->say_local("~CEMO~Name is no longer AFK.~CDEF");
      return 1;
    }
    message = recolor( message );
    if (strlen(message) <= 200) {
      this_player()->set_afk(message);
      msg("~CBRTAFK message set to~CDEF: "+message,20);
      this_player()->say_local("~CEMO~Name is now AFK: ~CDEF"+message,strlen(this_player()->query_name())+13);
      this_player()->set_curr_prompt("[~CWRNAFK~CDEF] ");
      this_player()->update_prompt();
    } else
      msg("~CDEFAFK message must be 200 characters or less, I mean, honestly...");
  } else if (this_player()->query_afk()) {
      msg("~CBRTYour AFK message is currently~CDEF: "+this_player()->query_afk(),31);
      msg("~CDEFType ~CCOMafk off~CDEF to clear it.");
    } else {
      msg("~CDEFYou have no afk message set.");
      msg("~CDEFType ~CCOMafk whatever~CDEF to set it.");
    }
  return 1;
}
