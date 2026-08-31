// Admin Tools - Whit

#include <daemons.h>

int get_character_creation_ip();
int lan_privs();
int lan_list();
int delete_user_set();

int cmd_admtool() {
   write("
           AdmTool v1.0 by Whit

      1) Get character creation ip
      2) Lan Privileges
      3) Delete User Set
      *) Quit
");
   input_to("get_selection");
   return 1;
}

int get_selection(string s) {
   switch(s) {
     case "1":
       get_character_creation_ip();
       break;
     case "2":
       lan_privs();
       break;
     case "3":
       delete_user_set();
       break;
     case "*":
     case "quit":
     case "q":
       write("Goodbye");
       break;
     default:
       write("Invalid selection.  Choice: ");
       input_to("get_selection");
       break;
   }
   return 1;
}

int get_character_creation_ip() {
   write("Please enter a users name: ");
   input_to("get_character_creation_ip_2");
   return 1;
}

int get_character_creation_ip_2(string user) {
   string ip;
   ip=MULTI_D->get_user_ip(user);
   write((ip?user+": "+ip+".*":user+": No such player.")+"\nEnter to continue...\n");
   input_to("cmd_admtool");
   return 1;
}

int lan_privs() {
   write("
          Lan Priviledges

      1) Add IP Range
      2) Remove IP Range
      3) List Ranges
      4) Back
");
   input_to("lan_privs_2");
   return 1;
}

int lan_privs_2(string s) {
   switch(s) {
     case "1":
       write("Please enter a range: ");
       input_to("lan_add_ip");
       break;
     case "2":
       write("Please enter a range: ");
       input_to("lan_remove_ip");
       break;
     case "3":
       lan_list();
       break;
     case "4":
       cmd_admtool();
       break;
     case "*":
     case "quit":
     case "q":
       write("Goodbye");
       break;
     default:
       write("Invalid selection.  Choice: ");
       input_to("lan_privs_2");
       break;

   }
   return 1;
}

int lan_add_ip(string s) {
   int i;
   int x;
   x=sizeof(explode(s,"."));
   if(x != 3 && x != 4) { 
     write("Invalid range.");
     lan_privs();
     return 1;
   }
   i=LAN_D->add_lan(s);
   write("IP Range: "+(i?"Range added.":"Already exists.")+"\nEnter to continue...");
   input_to("lan_privs");
   return 1;
}

int lan_remove_ip(string s) {
   int i;
   i=LAN_D->remove_lan(s);
   write("IP Range: "+(i?"Range removed.":"Range does not exist.")+"\nEnter to continue...");
   input_to("lan_privs");
   return 1;
}

int lan_list() {
   string *lan;
   lan=LAN_D->get_lans();
   if(!lan) write("No lans.");
   write(format_page(lan, 5)+"\nPress enter to continue...");
   input_to("lan_privs");
   return 1;
}

int delete_user_set() {
   write("%^RED%^%^BOLD%^Warning!%^RESET%^  This will delete all players from a given ip range.\n"
     "IP Range: ");
   input_to("delete_user_set_2");
   return 1;
}

int delete_user_set_2(string s) {
   mapping u;
   u=MULTI_D->get_users(s);
   if(!u || u == ([])) {
     write("No such user set found.\nPress enter to continue...");
     input_to("cmd_admtool");
     return 1;
   }
   write("Are you sure you want to delete "+sizeof(keys(u))+" users? (y/n)");
   input_to("delete_user_set_3", u);
   return 1;
}

int delete_user_set_3(string s, mapping u) {
   int i;
   string *k;
   switch(s) {
     case "y":
       write("Deleting...");
       i=sizeof(k=keys(u));
       while(i--) {
         this_player()->force_me("rid "+k[i]);
       }
       MULTI_D->do_cleanup();
       write("Press enter to continue...");
       input_to("cmd_admtool");
       break;
     case "n":
       write("Delete cancelled.");
       input_to("cmd_admtool");
       break;
   }
}

