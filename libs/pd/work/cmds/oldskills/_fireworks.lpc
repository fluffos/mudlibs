#include <daemons.h>
#include <std.h>
inherit DAEMON;
int spell();
int cmd_fireworks(string str) {
int mp;
 string mine, later, ours;
   if (this_player()->query_mp() < 150)
    return notify_fail("You do not have the concentration to do this.\n");
    if (!spell()) {
        return notify_fail("What?\n");
    }
   mp = this_player()->query_mp();
   if (mp >= 9000) {
     mine = "You rend the sky with your power!";
     later = "The realms shatter as you rend the skys!";
     ours = "A gargantua ball of fire launches into the sky\n"
            "%^RESET%^%^YELLOW%^The realms shatter and the skys are rended!";
   } else
   if (mp >= 2250) { 
     mine = "You summon a ball of flame and launch it into space!";
     later= "You shatter the moon with your power!";
     ours = "A great ball of flame launches into space, shattering the moon!";
   } else
   if (mp >= 1500) {
     mine = "You light up the sky with flames!";
     later = "Your ball of fire dwarfs the sun.";
     ours = "A huge ball of fire lights up the sky with flames.";
   } else
   if (mp >= 751) {
     mine = "You shoot a ball of fire into the sky.";
     later = "Your ball shoots through the clouds.";
     ours = "A ball of fire shoots through the clouds.";
   } else {
     mine = "You throw a ball of fire into the air.";
     later = "Your ball of fire sputters and goes out.";
     ours = "A ball of fire flys into the air, sputters and goes out.";
   }
   message("info", "%^YELLOW%^"+mine, this_player());
   call_out("next_step", 1, ours, later, this_player());
   this_player()->set_mp(0);
   return 1;
}
void next_step(string ours, string later, object tp) {
   string color;
   object *people;
   int i;
   i = random(6);
   switch(i) {
     case 0: color = "%^RED%^"; break;
     case 1: color = "%^ORANGE%^"; break;
     case 2: color = "%^BLUE%^"; break;
     case 3: color = "%^CYAN%^"; break;
     case 4: color = "%^MAGENTA%^"; break;
     case 5: color = "%^BOLD%^%^WHITE%^"; break;
     default: color = "%^GREEN%^"; break;
   }
   if(random(2) == 0)
     color += "%^BOLD%^";
   people = users();
   i = sizeof(people);
   message("info", color+later+"%^RESET%^", tp);
   while(i--) {
     if(tp == people[i]) continue;
     if(!environment(people[i])) continue;
     if(environment(people[i])->query_property("indoors") == 1) continue;
     message("info", color+ours+"%^RESET%^", people[i]);
   }
}
void help() {
write("
Syntax: <fireworks>
This level 30 spell enables the caster to conjur forth a flaming ball
of fire and launch it into the air. The size and ability of the
conjured ball depend on the caster's magical abilities, namely magic
points.
");
}
int spell() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 30) return 1;
   if (wizardp(this_player())) return 1;
}
