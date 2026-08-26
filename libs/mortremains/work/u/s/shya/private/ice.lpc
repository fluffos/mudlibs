//Created by Shya July 8, 2000//

#include <mudlib.h>
inherit OBJECT ;

void create() {
    set("author", "shya");
    set ("short", "Ice");
    set("long", @EndLong
This ice cube cane be used for many things. 
Either chilling a drink or cooling someone down.
You can 'massage' this ice cube in someone's hot body.  You can
'suck' on it or 'slide' it down ones body as well. Or just 'drip'
it down someone's back ;-). 
EndLong
    );
    set("id", ({ "ice", "ice cube", "cube" }) );
    
}
void init() {
    add_action("massage", "massage") ;
    add_action("suck", "suck");
    add_action("slide", "slide");
    add_action("drip", "drip");
}

int massage (string str)  {
 string name;   
 object target;

if (!str) {
write("Massage who?\n");
return 0;
    }

if (sscanf(str, "%s with %s", name, str) != 2) {
write("Who do you want to massage with an ice cube?\n");
return 1;
    }

if (str!="ice") {
return 1;
    }
target = find_player(name);
if (!target) {
	write("There's no player named "+target->query("cap_name")+" on the mud!\n");
return 1;
    }
write(wrap(
     "You massage the body of "+target->query("cap_name")+" with an ice cube,\n"+
     "til "+(target->query("gender"))+" gets goosebumps.\n"));

tell_object(target, wrap(
   TPN+" massages your body with an ice cube, giving you goosebumps.\n"));
say(
   TPN+" massages "+target->query("cap_name")+" with an ice cube in an erotic way.\n",target);
return 1 ;
}
int suck(string str) {
    say(TPN+" brings an ice cube to "+objective(TP->query("gender"))+" mouth and suck on it erotically.\n");
write(wrap(
      "You bring an ice cube to your mouth and start sucking on it.\n"));
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
write("Whose body do you want to slide an ice cube over?\n");
return 1;
    }
if (str!="ice") {
return 1;
    }
target = find_player(name);
if (!target) {
	write("There's no player named "+target->query("cap_name")+" on the mud!\n");
return 1;
    }
write(wrap(
	"You slide an ice cube over the body of "+target->query("cap_name")+" giving\n" +
       objective(target->query("gender"))+" goosebumps.\n"));
tell_object(target,wrap( 
      TPN+" slides an ice cube over your body, giving you goosebumps.\n"));
say(
   TPN+" slides an ice cube over "+target->query("cap_name")+" in an erotic way.\n",target);
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
write("Whose back do you want to drip an ice cube down?\n");
return 1;
    }
if (str!="ice") {
return 1;
    }
target = find_player(name);
if (!target) {
write("There's no player named "+target->query("cap_name")+" on the mud!\n");
return 1;
    }
write(wrap(
"You drip a melting ice cube down "+target->query("cap_name")+"'s back, \n"+
"making "+objective(target->query("gender"))+" gasp.\n"));

tell_object(target, wrap(
TPN+" drips a melting ice cube down your back, making you gasp.\n"));

say(
    TPN+" drips an ice cube down "+target->query("cap_name")+"'s back in an erotic way.\n",target);
return 1;
}

