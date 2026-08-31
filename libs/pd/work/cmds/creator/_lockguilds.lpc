//  lockguilds cmd
//  Whit
#include <daemons.h>

#include <guild.h>

int cmd_lockguilds() {
   int current;

   current = GUILD_D->query_locked();
   if(!GUILD_D->valid_master(this_player()->query_name())) return 0;
   if(!current) {
     write("Securing Guild System.\n");
     if(find_player("whit")) tell_object(find_player("whit"), 
       this_player()->query_name()+" %^BOLD%^%^RED%^locked%^RESET%^ the guild system.\n");
     GUILD_D->lock_guilds();
     write("Please type a reason for locking the system: ");
     input_to("get_reason");
     return 1;
   }
   write("Unlocking Guild System.\n");
   GUILD_D->unlock_guilds();
   if(find_player("whit")) tell_object(find_player("whit"), 
     this_player()->query_name()+" %^BOLD%^%^RED%^unlocked%^RESET%^ the guild system.\n");
   return 1;
}

void help() {
   write("Syntax: <lockguilds>\n\nThis will lock or unlock the guild "
     "system.\n  Only authorized people my do this.\n");
}

void get_reason(string str) {
   GUILD_D->set_lock_reason(str+"\n");
   write("Done.\n");
   return;
}

