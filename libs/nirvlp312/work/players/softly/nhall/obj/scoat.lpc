#include "/players/softly/closed/ansi.h"
inherit "obj/armor";

int lit;

reset(arg) {
set_name("surcoat");
set_short("a Surcoat");
set_long(
"  This is a beautifully crafted surcoat. It fits snuggly\n"+
"over almost any type of armor.  The coat is trimmed in a\n"+
"gold fabric. It seems very durable.  You may also type\n"+
"help_surcoat to see a list of other functions that it\n"+
"may serve.\n");
set_ac(1);
set_type("chest");
set_weight(0);
set_value(0);
set_save_flag(0);
}


init(){
	::init();
	add_action("help_coat", "help_surcoat");
      add_action("light_it", "light");
	add_action("change_emblem", "change_emblem");
}



help_coat(){

	write(
		"You find that the surcoat may do any of the following:\n"+
		"  light surcoat............Cause the emblem to magically\n"+
		"                           light up.\n"+
		"  change_emblem............Changes the emblem to whatever\n"+
		"                           you choose. Use | to eliminate\n"+
		"                           the emblem.\n");
	return 1;
}


light_it(str){
	if(!str){
		write("Light what?\n");
		return 1;
	}


    
if(str == "surcoat"){

if(!worn){ write("You must be wearing it first!\n");
           return 1;
           }

    if(lit){
      write("You concentrate and will the emblem to stop glowing...\n");
	lit = 0;
	set_light(-1);
	return 1;
	}
        lit = 1;
		write("You concentrate and will the emblem on your surcoat to glow.\n");
		set_light(1);
		return 1;
	}
return;
}


change_emblem(str){
if(!worn){ write("You must be wearing it first!\n");
           return 1;
           }
	if(!str){
		write("Change the emblem to what?\n");
		return 1;
	}
    if(str == "|"){
		set_short("a Surcoat");
		write("You reset the emblem.\n");
		return 1;
	}
	set_short(this_player()->query_name()+"'s Surcoat ["+extract(str, 0, 15)+"]");
write("Emblem changed.\n");
return 1;
}	

drop(silently) {
::drop();
    write("The surcoat crumbles to dust as you drop it.\n");
    destruct(this_object());
    return 1;
}

/*
drop(silently) {
    if (worn) {
        call_other(worn_by, "stop_wearing", name);
        worn = 0;
        worn_by = 0;
        if (!silently)
            tell_object(environment(this_object()),"You drop your worn armor.\n");
     }
    write("The surcoat crumbles to dust as you drop it.\n");
    destruct(this_object());
    return 1;
}
*/

	
