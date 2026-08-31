#include <locations.h>
//     /bin/user/_fly.c
//     A dragon ability
//     Needed to get to their hall
//     Nightshade
//     demon and angel added 3/27/2002
//     New system added 10-26-02
 
#include <std.h> 
inherit DAEMON;
int abil(); 
int cmd_fly(string str) {
    string dest, list, *severed;
    int skill, i;
    if (!abil())
       return 0;
    if (this_player()->query_race()== "demon" && this_player()->query_alignment() > -800){
      notify_fail("You have betrayed your alignment.\n");
      return 0;
    }    
    if (this_player()->query_race()== "archangel" && this_player()->query_alignment() < 750){
      notify_fail("You have betrayed your alignment.\n");
      return 0;
    }
    skill = this_player()->query_skill("flying");
    if(str)
    if(str == "list") {
        list = "%^RESET%^%^BOLD%^  Known Places\n%^RESET%^%^CYAN%^================%^RESET%^\n";
        if(skill >= 100)
          list += " Dunsinane\n";
        if(skill >= 85)
          list += " Merkkirri\n";
        if(skill >= 70)
          list += " Helgrath\n";
        if(skill >= 60)
          list += " Roston\n";
        if(skill >= 30)
          list += " Lodos\n";
        if(skill >= 45)
          list += " Tenebrae\n";
        if(skill >= 25)
          list += " Arlon\n";
        if(skill >= 20)
          list += " Elven Village\n";
        list += " Tirun\n";
        list += " Hall\n";
        write(list);
        return 1;
    }
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
    if((int)this_player()->query_sp() < 0) {
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
    if(str == "hall" && this_player()->query_mounted())
      this_player()->query_mounted()->force_me("dismount "+this_player()->query_name());
    if(!str) {
        write("You leap into the air!");
        say(this_player()->query_cap_name()+" leaps into the air!");
        this_player()->move_player(new("/d/nopk/standard/obj/magic/sky", "into the sky"));
    }
    else {
        switch(str) {
            case "tirun": dest = SQUARE_LOC; break;
            case "hall": if (this_player()->query_race()== "archangel") dest = "/wizards/inferno/angel/main"; else
                      if (this_player()->query_race()== "demon") dest = "/d/freepk/merkkerri/demonquest/dquest115"; else
                         dest = "/d/nopk/tirun/dragon_hall"; break;
            case "elven village": if(skill >= 20) dest = "/d/nopk/standard/rain_forest/corinthor/rooms/square"; break;
            case "arlon": if(skill >= 25) dest = "/d/nopk/arlon/room/square"; break;
            case "tenebrae": if(skill >= 45) dest = "/d/shadow/rooms/tene10"; break;
            case "lodos": if(skill >= 30) dest = "/d/lodos/square"; break;
            case "roston": if(skill >= 60) dest = "/d/roston/rooms/roston"; break;
            case "helgrath": if(skill >= 70) dest = "/d/helgrath/rooms/wilndursquare"; break;
            case "merkkirri": if(skill >= 85) dest = "/d/freepk/merkkerri/jungle/merkkirri/mjungle1"; break;
            case "dunsinane": if(skill >= 100) dest = "/wizards/powerman/room/patha"; break;
            default: if(this_player()->query_subclass() == "blue")
                     say(this_player()->query_cap_name()+" tries to fly up, but"
                       " they are too heavy for thier wings to carry them.");
                 else
                     say(this_player()->query_cap_name()+" flys away for a little, "
                       " but returns after circling a few times.");
                 write("You do not know how to fly to that place!");
        }
        if(dest) {
            write("You leap into the air!");
            say(this_player()->query_cap_name()+" leaps into the air!");
            this_player()->move_player(new("/d/nopk/standard/obj/magic/skyquick", "into the sky"));
            call_out("go_sky", 6, str, dest);
        }
    }
    return 1;
}
int go_sky(string str, string dest) {
        write("Seeing "+capitalize(str)+" you swoop down to land!");
        this_player()->move_player(dest, "swoops down to land");
        if(this_player()->query_subclass() == "blue")
            say(this_player()->query_cap_name()+" lands with a thud.");
        else
            say(this_player()->query_cap_name()+" flies in from high above and lands.");
        this_player()->add_sp(-random(10) - random(10));
    return 1;
}
void help() {
   write("Syntax: <fly to [place]>\n\n"
         "Some races are able to fly to different places with use of their wings. \n"
         "<fly list> will list the places you are able to fly to. ");
}
int abil() {
   if (this_player()->query_class() != "dragon" && this_player()->query_race() != "archangel" && this_player()->query_race() != "demon") return 0;  
    if(this_player()->query("bear")) return 0;
   return 1;
}
