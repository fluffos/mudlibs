
inherit COMMAND_BASE;

#include <login_handler.h>

int cmd() {
  int players, logins, login_q, first, creators, total;
  string output, *str, *logins_n;
  object pl;

  str = ({ });
  foreach(pl in users()) {
    if (pl->query_login_ob())
      logins++;
    else {
      str += ({ pl->query_cap_name() });
      if (creatorp(pl))
        creators++;
      else
        players++;
    }
  }

  logins_n = map(LOGIN_HANDLER->query_login_queue(),
                 (: $1->query_cap_name() :));
  logins_n = filter(logins_n, (: $1 :));
  logins_n = sort_array(logins_n, 1);
  login_q = sizeof(logins_n);
  if (login_q > 0) {
    first = 0;
    if (login_q > 1)
      write(sprintf(login_q+" currently queued: %-=*s\n",
                    this_player()->query_cols()-17,
                    implode(logins_n[0..<2], ", ")+" and "+
                    logins_n[<1]));
    else
      write(sprintf("Currently Queued: %-=*s\n",
                    this_player()->query_cols()-19,
                    logins_n[0]));
  }
  
  output = "There ";
  
  first = 1;
  if (creators > 0) {
    if (first)
      if (creators == 1)
        output += "is ";
      else
        output += "are ";
    if (creators == 1)
      output += "one creator";
    else
      output += creators +" creators";
    first = 0;
    if (logins - login_q > 0)
      output += ", ";
    else
      if ( !players )
        output += " logged on.\n";
      else
        output += " and ";
  }
  
  if (logins - login_q > 0) {
    if (first)
      if (logins - login_q == 1)
        output += "is ";
      else
        output += "are ";
    if (logins - login_q == 1)
      output += "one person logging in";
    else
      output += ( logins - login_q ) +" people logging in";
    first = 0;
    if ( !players )
      output += ".\n";
    else
      output += " and ";
  }

  if ( players ) {

    if (first)
      if (players == 1)
        output += "is ";
      else
        output += "are ";
    if (players == 1)
      output += "one player ";
    else
      output += players +" players ";
    
  }

  total = sizeof(users());
  output += "A total of "+ sizeof(users()) + " people logged on.\n";

  write( output );

  str = filter(str, (: $1 :));
  str = sort_array(str, 1);
  if (sizeof(str) > 1)
    write(sprintf("Currently logged on: %-=*s\n",
                  this_player()->query_cols()-24,
                  implode(str[0..<2], ", ")+" and "+
                  str[<1]));
  else
    write("Currently logged on: "+str[0]+".\n");
  return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd() :) });
}  /* query_patterns() */
