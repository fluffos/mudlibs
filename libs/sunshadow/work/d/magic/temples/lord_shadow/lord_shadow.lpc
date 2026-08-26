//Temple of Lord Shadow - created by Nienne 2/18
//updated by ~Circe~ 10/5/19 with allies and enemies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("lord shadow");
   set_name("Temple of Lord Shadow");
   set_short("%^C075%^Temple of Lord Shadow%^CRST%^");
   set_long("%^C075%^Temple of Lord Shadow%^CRST%^\n\%^C244%^You have entered a massive cathedral showcasing the power and majesty of the %^C061%^Church%^C060%^ of L%^C061%^o%^C062%^r%^C060%^d S%^C061%^h%^C062%^a%^C060%^dow%^C244%^. As you pass through the arched entrance, the main area of the cathedral opens up into an expansive circular worship area, centered upon a vertically set circular piece of %^C153%^mirror-polished%^C244%^ %^C244%^o%^C246%^b%^C246%^s%^C250%^i%^C248%^d%^C246%^i%^C244%^an%^C244%^. The area around the %^C244%^mirror seems to be standing-room only, with not a chair or bench in sight. %^C244%^Great %^C244%^vertical supports ring the outside of the room, arching far above and converging %^C244%^on a circular ceiling, painted with a %^C075%^s%^C081%^w%^C087%^e%^C081%^e%^C075%^ping depiction%^C244%^ of some long ago event. %^C244%^The pillars have %^C059%^h%^C065%^e%^C071%^a%^C065%^v%^C059%^y i%^C065%^r%^C071%^o%^C059%^n r%^C065%^i%^C071%^n%^C059%^gs%^C244%^ attached to them, with a myriad of %^C059%^s%^C244%^p%^C246%^i%^C248%^k%^C246%^e%^C059%^d c%^C244%^h%^C246%^a%^C248%^i%^C246%^n%^C059%^s%^C064%^ %^C244%^running through them, creating a %^C060%^n%^C061%^i%^C062%^g%^C063%^h%^C062%^t%^C061%^m%^C060%^arish%^C244%^ and %^C060%^m%^C061%^a%^C062%^c%^C063%^a%^C062%^b%^C061%^r%^C060%^e%^C244%^ spectacle. %^C244%^Several %^C139%^f%^C145%^l%^C151%^e%^C139%^sh s%^C145%^cu%^C151%^l%^C145%^p%^C139%^tures%^C244%^ are placed near the entrance for all to see.%^CRST%^");
   set_smell("default","The smell of blood, bitter cold and dread are in the air.");
   set_listen("default","An organ plays a truly disturbing tune, each note the scream of some poor soul.");
   set_items(([
   "chains" : "%^C071%^The chains seem to feed through the rings and create a horrifying web of suffering along the outer walls of the temple. Impaled upon the various barbs of the chains are a myriad of dead and dying unfortunates, lending their suffering and souls to Lord Shadow's greatness.%^CRST%^",
   ({ "sculpture", "sculptures", "flesh sculptures", "flesh" }) : "%^C139%^Upon the arching pillars are set steel wheels, with suffering, gibbering victims, broken and twisted upon those wheels, stretched and contorted in unsettling displays of suffering, their lives sustained to endure their pain with magical spikes piercing their hearts. One of them almost seems to gaze upon you with an eyeless stare, its sight long ago plucked out by the hunger of ravens.%^CRST%^",
   ({ "obsidian", "mirror" }) : "%^C060%^The pillars and walls encircle a large open area, centered upon what seems to be a great vertical mirror of what looks like polished obisidian that emanates an aura of the deepest dread. Upon the surface of the mirror plays dark movements and fluttering and you get the impression you are looking directly into the Plane of Shadows itself.%^CRST%^",
   ({ "painting", "depiction", "ceiling" }) : "%^C247%^The ceiling is painted with a sweeping depiction of the odyssey of Tenebrosa as it ventured through the Plane of Shadow. The depiction seems to show a journey of hardship until the Shadovar, under the guidance of the mortal Lord Shadow, embraced the shadow and achieved their true destiny. %^CRST%^",
   ]));
   set_exits(([
      "out": "/d/magic/temples/lord_shadow/lord_shadowentry"
   ]));
}

void reset()
{
    ::reset();
    
    switch(random(4))
    {
        case 0:
        tell_room(this_object(), "%^C139%^Several shirtless supplicants stand before the mirror, %^C126%^whipping%^C139%^ themselves with %^C059%^barbed chains%^C139%^.%^CRST%^");
        break;
        case 1:
        tell_room(this_object(), "%^C248%^A sobbing slave is presented to the %^C087%^mirror%^C248%^, and the %^C244%^shadows%^C248%^ embrace him. Soon, he turns, his eyes deep wells of %^C244%^blackness%^C248%^, and smiles with %^C097%^pure malice%^C248%^.%^CRST%^");
        break;
        case 2:
        tell_room(this_object(), "%^C139%^One of the %^C145%^flesh sculptures%^C139%^ shudders and gasps, its mouth opening and closing in a %^C157%^silent scream%^C139%^.%^CRST%^");
        break;
        default:
        tell_room(this_object(), "%^C081%^Icicles slowly form on the blackened walls, and your breath seems to almost freeze in the frigid air.%^CRST%^");
        break;
    }
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Lord Shadow charges his followers with this message:%^RESET%^%^CYAN%^
The world is filled with darkness, fear and suffering - the only separation is between the powerful who wield these gifts, and the powerless who cower before them.  Hope is merely a temporary shelter for the weak, for as each day inevitably ends beneath the cloak of night, so will all things inevitably succumb to darkness.  Submit to the word of Lord Shadow and his ranking clergy, for true power can only be gained through unwavering loyalty.  Spread His fear across the realm, and strike down those who would defy His will, so that all may come to know servitude in His name.

%^RESET%^---

%^BOLD%^Lord Shadow has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^None
%^CYAN%^Enemies: %^RESET%^Jarmila, Callamir, Lysara

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.

CHARGE
   );
   return 1;
}