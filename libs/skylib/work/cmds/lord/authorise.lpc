
#include <parser.h>
#include <login.h>

inherit COMMAND_BASE;

nosave string var_name = "map_prop ";
nosave string fname;
mapping map_prop;
mapping player_info;
string name;
string password;
string email;
int last_log_on;

/*
 * This will add a property to a player.
 */
mixed cmd(string player) {
   if (LOGIN_OB->test_user(player)) {
      return "/cmds/lord/playera_ddproperty"->cmd(player, "authorised player",
                    "1");
   }
   write(capitalize(player) + " does not exists.  Do you wish to create them? ");
   input_to("really_create", 0, player);
   add_succeeded_mess("");
   return 1;
} /* cmd() */

void really_create(string response, string player) {
   response = lower_case(response);
   if (response[0] != 'y') {
      write("Aborting create.\n");
      return ;
   }
   write("Ok, creating player " + capitalize(player) + ".\n");
   write("What is their authorised email address: ");
   input_to("get_email", 0, player);
}
void get_email(string str, string player) {
  email = str;
  write("What password do you wish to use: ");
  input_to("get_password", 0, player);
} /* really_create() */

void get_password(string passw, string player) {
   string save_file_name;

   save_file_name = LOGIN_OB->query_player_file_name(player);
   map_prop = ([ "authorised player" : 1,
                 "new player" : 1,
                 "player" : 1,
                 "authorised email" : email, ]);
   player_info = ([ "email" : ":"+email, ]);
   last_log_on = time();
   name = player;
   password = crypt(passw, 0);
   save_object(save_file_name);
   write("Create player " + capitalize(player) + " with authorisation to login "
         "from nologin sites.\n");
} /* get_password() */

mixed *query_patterns() {
  return ({ "<word>", (: cmd($4[0]) :), });
} /* query_patterns() */
