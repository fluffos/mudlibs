//Created by Shya July 10, 2000//

#include <mudlib.h>
inherit OBJECT ;

void create() {
    set("author", "shya");
    set ("short", "Tyran's Fudgsicle");
    set("long", @EndLong
This fudgsicle can be used for many things. 
You can 'suck' on it or 'slide' it down ones body as well. 
Or just 'drip' it down someone's back ;-). 
EndLong
    );
    set("id", ({ "fudgsicle", "popsicle" }) );
    
}
void init() {
    add_action("suck", "suck");
    add_action("slide", "slide");
    add_action("drip", "drip");
}

int suck(string str) {
    say(TPN+" brings a fudgsicle to "+objective(TP->query("gender"))+" mouth and suck on it erotically.\n");
write(wrap(
      "You bring a fudgsicle to your mouth and start sucking on it.\n"));
return 1;
}
int slide(string str) {
string name;   
object target;
    
if (!str) {
write("Slide what?\n");
return 1;
    }
if (sscanf(str, "%s over %s", str, name) != 2) {
write("Whose body do you want to slide a fudgsicle over?\n");
return 1;
    }
if (str!="fudgsicle") {
return 1;
    }
target = find_player(name);
if (!target) {
	write("There's no player named "+target->query("cap_name")+" on the mud!\n");
return 1;
    }
write(wrap(
	"You slide a fudgsicle over the body of "+target->query("cap_name")+" giving\n" +
       objective(target->query("gender"))+" goosebumps.\n"));
tell_object(target,wrap( 
      TPN+" slides a fudgsicle over your body, giving you goosebumps.\n"));
say(
   TPN+" slides a fudgsicle over "+target->query("cap_name")+" in an erotic way.\n",target);
return 1;
}
int drip (string str)  {
   string name; 
   object target ;
 
if (!str) {
     write("Drip what?\n");
return 1;
    }

if (sscanf(str, "%s on %s", str, name) != 2) {
write("Whose back do you want to drip a fudgsicle down?\n");
return 1;
    }
if (str!="fudgsicle") {
return 1;
    }
target = find_player(name);
if (!target) {
write("There's no player named "+target->query("cap_name")+" on the mud!\n");
return 1;
    }
write(wrap(
"You drip a melting fudgsicle down "+target->query("cap_name")+"'s back, \n"+
"making "+objective(target->query("gender"))+" gasp.\n"));

tell_object(target, wrap(
TPN+" drips a melting fudgsicle down your back, making you gasp.\n"));

say(
    TPN+" drips a melting fudgsicle down "+target->query("cap_name")+"'s back in an erotic way.\n",target);
return 1;
}

