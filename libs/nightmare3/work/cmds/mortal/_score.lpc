#include <std.h>

inherit DAEMON;

int cmd_score(string str) {
   string rank, foo, name, title, Class, race;
    int sp, max_sp;
   int level, hp, max_hp, mp, max_mp, age;
   int exp, next_exp;

   if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
   }
   if(str) {
        notify_fail("See also <skills> and <stats>\n");
        return 0;
   }
   name = (string)this_player()->query_cap_name();
   title = (string)this_player()->query_title();
   Class = (string)this_player()->query_class();
   race = (string)this_player()->query_race();
   level = (int)this_player()->query_level();
   exp = (int)this_player()->query_exp();
   hp = (int)this_player()->query_hp();
   max_hp = (int)this_player()->query_max_hp();
   sp = (int)this_player()->query_sp();
   max_sp = (int)this_player()->query_max_sp();
   mp = (int)this_player()->query_mp();
   max_mp = (int)this_player()->query_max_mp();
   age = time() - (int)this_player()->query_birthday();
    message("status", sprintf("You are %s (%s) (%s)", title,
      (string)this_player()->query_al_title(), 
      (string)this_player()->query_race()), this_player());
   write("You are level " + level + " with " + exp + " experience.");
   write("You have:");
   write(hp+" ("+max_hp+") health points, "+sp+" ("+max_sp+") "+
     "stamina points, and "+mp+" ("+
         max_mp + ") magic points.");
   if((int)this_player()->query_intox()) {
	if((int)this_player()->query_intox() > 420) write("You are FUBAR");
	else if((int)this_player()->query_intox() > 300) 
            write("You are smashed out of your gourd");
	else if((int)this_player()->query_intox() > 180)
            write("You are quite drunk");
	else if((int)this_player()->query_intox() > 90) 
            write("You are drunk");
	else if((int)this_player()->query_intox() > 36) 
            write("You are tipsy");
	else write("You are buzzed");
   }
    else message("info", "You are sober"+
      (this_player()->query_stuffed() ? " and not hungry" : "")+
      (this_player()->query_quenched() ? " and not thirsty" : "")+".",
      this_player());
    if(this_player()->query_poisoning())
      message("info", "You are poisoned.", this_player());
   write("You are " + (18 + (age/4320000)) + " years old.");
   return 1;
}                                            

void help() {
    write("Syntax: <score>\n\n"
          "This command gives you information about your character.\n"
          "See also: status, body, biography, skills, stats, money, inventory\n"
    );
}
