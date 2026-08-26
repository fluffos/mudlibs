/*
** File: _password.c
** Purpose: Allows admin to set other people's passwords.
** Credits: 
**    31 Mar 98  Cyanide created the file.
*/

// Prototypes:
void get_password(string, string, object);
void get_password2(string, string, string, object);

#define SYNTAX "Syntax: password <player name>\n"

#include <uid.h>
#include <config.h>

int cmd_password (string name) {
   object user;

   seteuid(ROOT_UID);

   if (!name || name=="") {
      write(SYNTAX);
      return 1;
   }

   name = lower_case(name);

   user = new(CONNECTION);

   if (!file_exists(user_data_file(user, name) + __SAVE_EXTENSION__)) {
      write("There is no known player by the name of \""+
       capitalize(name)+"\".\n");
      return 1;
   }
   
   reload_object(user);
 
   seteuid(name);
   export_uid(user);
   seteuid(ROOT_UID);
 
   user->set("name", name);

   if(!user->restore()) {
      write("Attempt to restore link object failed.\n");
      return;
   }

   write("Please enter the new password for "+capitalize(name)+": ");
   input_to("get_password", name, user);
   return 1;
}

void get_password(string word, string name, object user) {
   write("\nPlease enter again to confirm: ");
   input_to("get_password2", word, name, user);

   return;
}


void get_password2(string confirm, string word, string name, 
 object user) {

   if (confirm==word) {
      user->SET_PASS(crypt(word,0));
      user->save_data();
      user->remove();
      write("Password successfully changed.\n");
      return;
   }

   write("Sorry, the passwords must match.\n");
   return;
}

string help() {
   string str = (@EndHelp
The 'password' command is a wizard tool used exclusively to 
  a) Aid players who have lost their passwords, or
  b) Temporarity lock out players.

PLEASE (Nightmask  ;) try not to abuse it, okay?
EndHelp
);
   return str;
}
