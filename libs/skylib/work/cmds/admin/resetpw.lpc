#include <parser.h>

inherit COMMAND_BASE;

string basename;

/*
 * This will reset a players password.
 */
mixed cmd(string player, string newpw) {
  string file, password;
  string *bits;
  int i;
  
  if (!sizeof(filter(previous_object(-1), (: interactive($1) :)))) {
    unguarded((: write_file, "/log/CHEAT", ctime( time() ) +
               ": illegal attempt to reset password.\nTrace: " + back_trace()
               :));
    return 0;
  }
  if (!sizeof(filter(previous_object(-1),(:adminp($1):)))) {
    unguarded((: write_file, "/log/CHEAT", ctime( time() ) +
               ": illegal attempt to reset password.\nTrace: " + back_trace()
               :));
    return 0;
  }

  if(!newpw || newpw == "")
    return notify_fail("Syntax: resetpw <player> <new password>\n");
  
  seteuid("Root");

  /* Restore them... */
  if ("/secure/login"->test_user(player)) {

    basename = "/save/players/" + player[0..0] + "/" + player;
    
    file = unguarded( (: read_file(basename + ".o") :));
    bits = explode(file, "\n");
    
    for (i = 0; i < sizeof(bits); i++) {
      if (bits[i][0..strlen("password")-1] == "password") {
        password = restore_variable(bits[i][strlen("password") + 1..]);
        break;
      }
    }
    password = crypt(newpw, newpw[0..1]);
    if (i < sizeof(bits)) {
      bits[i] = "password " + save_variable(password);
    } else {
      bits += ({ "password " + save_variable(password) });
    }
    
    unguarded( (: rm(basename + ".old") :) );
    unguarded( (: rename(basename+".o", basename+".old") :) );
    unguarded( (: write_file(basename + ".o", implode($(bits), "\n") + "\n") :));
    write(sprintf("Reset password for %s to %s\n", player, newpw));

  } else {
    write("Unable to find player "+player+".\n");
  }

  return 1;
} /* cmd() */

mixed *query_patterns() {
  return ({ "<word> <string>", (: cmd($4[0], $4[1]) :),
            });
} /* query_patterns() */
