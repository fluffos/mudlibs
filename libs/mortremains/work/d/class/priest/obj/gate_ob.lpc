/*
**  Ilz
**  23 Nov 98  Cyanide cleaned up a little. Also added movement 
**             notification for portal opening and closing, and
**             players going in and out.
*/

#include <mudlib.h>
#include <move.h>

inherit OBJECT;

void create() {
    set("id", ({ "gate" }) );
    set("short", "a magical gate");
    set("long", wrap("A mystic portal created to gate a creature "+
	"to another plane of existence.\nYou can 'enter' gate if "+
	"you wish.") );
    set("prevent_get", 1);
    set("prevent_clean", 1);
    call_out("remove", 60);
}

void init(){
    add_action("enter", "enter");
}

int enter(string str){
    int result;

    if (!str || (str!="gate")){
	write ("What did you want to enter?\n");
	return 1;
    }

    write("You step through the gate.\n");
    say(TPN+" steps into the gate!\n");
    result = TP->move_player(query("destination"), "SNEAK");

    if (result != MOVE_OK) {
	write("There is something very wrong. Please notify "+
	  "an administrator!\n");
    } else {
	say(TPN+" emerges from the gate!\n");
    }

    return 1;
}

int remove() {
    object env = environment();

    if (env) tell_room(env, "The portal closes, suddenly.\n");

    ::remove();
}

/* EOF */
