#include <locations.h>
//     /bin/user/_fly.c
//     A dragon ability
//     Needed to get to their hall
//     Nightshade
//     demon and angel added 3/27/2002
//     New system added 10-26-02
 
#include <std.h> 
#include <daemons.h>
inherit DAEMON;
int abil(); 
string type() { return "other"; }
int cmd_fly(string str) {
    string *severed, tmp;
    string area, dir, *folders;
    object o;
    int *c1, *c2;
    int skill, i;
    if (!abil())
       return 0;
    if(environment(this_player())->query_property("sky")) return 0;
    if (this_player()->query_race()== "demon" && this_player()->query_alignment() > -800){
      notify_fail("You have betrayed your alignment.\n");
      return 0;
    }    
    if (this_player()->query_race()== "archangel" && this_player()->query_alignment() < 750){
      notify_fail("You have betrayed your alignment.\n");
      return 0;
    }
    skill = this_player()->query_skill("flying");

    if((object)this_player()->query_current_attacker()) {
       notify_fail("You try to fly away, but battle prevents you.\n");
       return 0;
    }
    if((object)this_player()->query_arena()) {
       notify_fail("You wouldnt dare try to fly out of the arena!\n");
       return 0;
    }
    if (this_player()->query_disable()) {
       write("You are off balance.");
       return 1;
    }
    if(environment(this_player())->query_property("no fly")) {
       notify_fail("The winds are to fierce.\n");
       return 0;
    }
    if(environment(this_player())->query_property("indoors")) {
       notify_fail("You cannot do that indoors.\n");
       return 0;
    }
    if((int)this_player()->query_sp() < 10) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    if(this_player()->query_rest_type()) {
        notify_fail("You are too comfortable to start flying.\n");
        return 0;
    }
    severed = this_player()->query_severed_limbs();
    i = sizeof(severed);
    while(i--) {
      if((severed[i] == "left wing") || (severed[i] == "right wing")) {
        write("Your "+severed[i]+" is missing!");
        return 1;
      }
    }
    if(this_player()->query_riding()) this_player()->force_me("dismount");
    if(str == "hall" && this_player()->query_mounted() && this_player()->query_race() == "dragon") {
      this_player()->query_mounted()->force_me("dismount "+this_player()->query_name());
    }
    if(str == "hall" && this_player()->query_race() == "dragon") {
      write("You fly to your hall in the sky.");
      say(this_player()->query_cap_name()+" leaps into the air!");
      this_player()->move_player("/d/nopk/tirun/dragon_hall", "into the sky");
      return 1;
    }
    if(base_name(environment(this_player())) == "/std/room/sky_room") {
      write("You are already flying.");
      return 1;
    }
    write("You leap into the sky.");
    say(this_player()->query_cap_name()+" leaps into the air!");
    if(environment(this_player())->query_property("coords")) {
      o=SKY_D->get_room(environment(this_player())->query_property("coords"));
      this_player()->move_player(o, "into the sky");
      return 1;
    }
    dir=base_name(environment(this_player()));
    folders=explode(dir, "/");
    area=folders[1];
    if(area == "nopk" || area == "freepk") area=folders[2];
    if(sscanf(dir, "/d/nopk/standard/rain_forest/corinthor/%s", tmp) == 1) {
      o=SKY_D->get_room(SKY_D->query_coord_from_letter("O")); 
    } else
    switch(area) {
      case "aekari": o=SKY_D->get_room(SKY_D->query_coord_from_letter("A")); break;
      case "forest": o=SKY_D->get_room(SKY_D->query_coord_from_letter("B")); break;
      case "tirunmts": o=SKY_D->get_room(SKY_D->query_coord_from_letter("C")); break;
      case "citrin": o=SKY_D->get_room(SKY_D->query_coord_from_letter("D")); break;
      case "distopia": o=SKY_D->get_room(SKY_D->query_coord_from_letter("E")); break;
      case "durst": o=SKY_D->get_room(SKY_D->query_coord_from_letter("F")); break; // Desert
      case "merkkerri": o=SKY_D->get_room(SKY_D->query_coord_from_letter("G")); break;
      case "purgatory": o=SKY_D->get_room(SKY_D->query_coord_from_letter("H")); break;
      case "rhondale": o=SKY_D->get_room(SKY_D->query_coord_from_letter("I")); break;
      case "helgrath": o=SKY_D->get_room(SKY_D->query_coord_from_letter("J")); break;
      case "lodos": o=SKY_D->get_room(SKY_D->query_coord_from_letter("L")); break;
      case "lodos_path": o=SKY_D->get_room(SKY_D->query_coord_from_letter("L")); break;
      case "metaisland": o=SKY_D->get_room(SKY_D->query_coord_from_letter("M")); break;
      case "arlon": o=SKY_D->get_room(SKY_D->query_coord_from_letter("N")); break;
      case "elven_path": o=SKY_D->get_room(SKY_D->query_coord_from_letter("O")); break;
      case "standard": o=SKY_D->get_room(SKY_D->query_coord_from_letter("S")); break; // Corinthor
      case "roston": o=SKY_D->get_room(SKY_D->query_coord_from_letter("Q")); break;
      case "shadow": o=SKY_D->get_room(SKY_D->query_coord_from_letter("R")); break;
      case "tirun": o=SKY_D->get_room(SKY_D->query_coord_from_letter("S")); break;
      default: write("A gust of wind prevents you from flying here!"); return 1; break;
    }
    this_player()->move_player(o, "into the sky");
    return 1;
}

void help() {
   write("Syntax: <fly>\n\n"
         "Some races are able to fly to different places with use of their wings. \n");
}

int abil() {
   if(this_player()->query_position() == "wizard") return 1;
   if (this_player()->query_class() != "dragon" && this_player()->query_race() != "archangel" && this_player()->query_race() != "demon") return 0;  
    if(this_player()->query("bear")) return 0;
   return 1;
}
