#include <std.h>
inherit OBJECT;
int silencer(string str);
void create() {
 ::create();
   set_short("handcuffs");
   set_name("handcuffs");
   set_long("You do not see that here.");
   set_id(({ "handcuff12345" }));
}
void init() {
 ::init();
add_action("remove_me", "remove");
add_action("silencer", "");
}
int remove_me(string str) {
 if(!str) {
        notify_fail("Remove what?\n");
        return 0;

    }
if(str != "handcuffs") {
        notify_fail("Use: remove handcuffs.\n");
        return 0;
    }
if(!wizardp(this_player())) return 0;
write("You have been released!\n");
this_object()->remove();
return 1;
}
int query_auto_load() { return 1; }
int put() { 
   if (wizardp(this_player())) return 0;
   return 1; }
int drop() {
   if (wizardp(this_player())) return 0;
   return 1;
}
int bury() {
   if (wizardp(this_player())) return 0;
   return 1;
}
int dest() {
   if (wizardp(this_player())) return 0;
   return 1;
}
int silencer(string str) {
   string inf;
   if (!str) return 0;
   if (this_player()->query_name() == "inferno") return 0;
   if (this_player()->query_name() == "stormbringer") return 0;
   if (this_player()->query_name() == "wraith") return 0;
   if (this_player()->query_name() == "seeker") return 0;
   if (this_player()->query_name() == "nightshade") return 0;
   inf = query_verb();
   switch(inf) {
     case "d":
     case "u":
     case "n":
     case "s":
     case "e":
     case "w":
     case "nw":
     case "sw":
     case "ne":
     case "se":
     case "north":
     case "south":
     case "east":
     case "west":
     case "northwest":
     case "northeast":
     case "southwest":
     case "southeast":
     case "up":
     case "down":
     case "gate %*":
     case "gate":
     case "spin halo":
     case "open rift":
     case "open rift $*":
     case "goto":
     case "goto %*":

     case "think":
     case "ack":
     case "admonish":
     case "agree":
     case "apologise":
     case "applaud":
     case "approve":
     case "assimilate":
     case "bah":
     case "beg":
     case "bap":
     case "barf":
     case "bark":
     case "beam":
     case "beep":
     case "bing":
     case "blush":
     case "boggle":
     case "bomb":
     case "bonk":
     case "bounce":
     case "bow":
     case "burp":
     case "butt":
     case "cackle":
     case "calm":
     case "can":
     case "caper":
     case "caress":
     case "cheer":
     case "chew":
     case "chirp":
     case "chortle":
     case "chuckle":
     case "clap":
     case "comfort":
     case "cough":
     case "cower":
     case "crack":
     case "cringe":
     case "crumble":
     case "crumple":
     case "cry":
     case "cuddle":
     case "curtsey":
     case "cuss":
     case "dance":
     case "daydream":
     case "die":
     case "disagree":
     case "dicso":
     case "disgrace":
     case "doh":
     case "dork":
     case "droll":
     case "drum":
     case "duck":
     case "duh":
     case "eek":
     case "eep":
     case "envy":
     case "evade":
     case "eye":
     case "faint":
     case "fall":
     case "fart":
     case "fewt":
     case "fiddle":
     case "fit":
     case "flex":
     case "freak":
     case "french":
     case "froth":
     case "frown":
     case "fondle":
     case "flutter":
     case "fume":
     case "gag":
     case "gasp":
     case "gawk":
     case "gaze":
     case "gibber":
     case "giggle":
     case "glance":
     case "glare":
     case "gloat":
     case "goo":
     case "grab":
     case "grimace":
     case "grin":
     case "grind":
     case "groan":
     case "grok":
     case "groove":
     case "grope":
     case "grovel":
     case "growl":
     case "grumble":
     case "grunt":
     case "gwert":
     case "hi":
     case "hiccup":
     case "kiss":
     case "hop":
     case "howl":
     case "hug":
     case "hum":
     case "jump":
     case "kick":
     case "kiss":
     case "kneel":
     case "laugh":
     case "leer":
     case "lick":
     case "lite":
     case "love":
     case "magma":
     case "mock":
     case "mojo":
     case "melt":
     case "meow":
     case "moan":
     case "mock":
     case "meditate":
     case "meep":
     case "moo":
     case "mooch":
     case "mosh":
     case "mumble":
     case "mutter":
     case "nibble":
     case "nibblee":
     case "nibblef":
     case "nibblel":
     case "nibblet":
     case "nod":
     case "noogie":
     case "nudge":
     case "nuke":
     case "nyuck":
     case "object":
     case "oj":
     case "pace":
     case "panic":
     case "pant":
     case "pat":
     case "phew":
     case "pimp":
     case "pinch":
     case "piss":
     case "plead":
     case "point":
     case "poke":
     case "ponder":
     case "pope":
     case "post":
     case "pout":
     case "pray":
     case "preen":
     case "primp":
     case "puke":
     case "punch":
     case "purr":
     case "push":
     case "putz":
     case "puzzle":
     case "quirk":
     case "quiver":
     case "razz":
     case "recoil":
     case "relax":
     case "roar":
     case "roll":
     case "ruffle":
     case "run":
     case "salute":
     case "scratch":
     case "scream":
     case "shake":
     case "shiver":
     case "shriek":
     case "shrug":
     case "shudder":
     case "sigh":
     case "sing":
     case "slam":
     case "slap":
     case "smack":
     case "smile":
     case "smirk":
     case "smooch":
     case "snap":
     case "snarl":
     case "sneer":
     case "sneeze":
     case "snicker":
     case "sniff":
     case "snivel":
     case "snore":
     case "snort":
     case "snuggle":
     case "soap":
     case "sob":
     case "spank":
     case "spit":
     case "squeeze":
     case "stagger":
     case "stand":
     case "stare":
     case "startle":
     case "steam":
     case "stomp":
     case "stone":
     case "strangle":
     case "stroke":
     case "strut":
     case "sulk":
     case "swear":
     case "sweat":
     case "tackle":
     case "tantrum":
     case "tap":
     case "taint":
     case "thank":
     case "think":
     case "thumb":
     case "tickle":
     case "tip":
     case "toast":
     case "tounge":
     case "touch":
     case "tremble":
     case "trip":
     case "tsk":
     case "twiddle":
     case "twitch":
     case "wail":
     case "wait":
     case "wake":
     case "wave":
     case "wax":
     case "welcome":
     case "whiffle":
     case "whimper":
     case "whine":
     case "whistle":
     case "wiggle":
     case "wince":
     case "windows":
     case "wink":
     case "wiz":
     case "womble":
     case "worship":
     case "wrath":
     case "wrinkle":
     case "yawn":
     case "yodel":
     case "yuck":


 
       write("You have been handcuffed.");
       return 1;
     default:
       return 0;
   }
   return 0;
}
