// potion.c
// Written by Valkyrie@TMI-2
// Cleaned up a little by Mobydick@TMI-2 on 8-17-93
// This is the basic potion object. A user can open the potion and
// drink it. If that happens, the potion takes effect after 5-15
// seconds, and the function do_effect() is called. After the effect
// time passes, the function do_wear_off() is called, and the object
// destructs itself.
// To create a potion for yourself, make an object that inherits this
// object, and just add a do_effect() and a do_wear_off() function
// which do what you want your potion to do. See /obj/strength_potion.c
// for an example.
// When the user drinks the potion, an empty vial is created and move
// to him, and the potion object goes invisible. The call_out remains
// active in the potion object: the potion object stays on the user
// until the effect wears off, and it's dested then. This isn't the
// most robust way to handle things but it is very easy and flexible,
// and it's wonderfully OO.  ;)
// A couple of bugs cleared up by Blue, 940527.  Thanks to Shredder
// for pointing them out and showing me the fixed code on his mud.
// When the potion was desting itself, it wasn't fixing the weight
// correctly.  Also moved /u/m/mobydick/vial.c into a #define.
// I'm sure we can spare the disk space to put it in /std.

#define VIAL_OBJECT "/obj/vial"

#include <config.h>
#include <mudlib.h>

inherit OBJECT;

// Drinker stores an object pointer to the person who drunk the potion.
// This is needed because this_player() isn't defined in the call_out.
object drinker ;
int closed;
int delay;
int full;

int do_effect();
int do_wear_off() ;

void create() {
  set ("id", ({ "potion", "vial" }) ) ;
  set("bulk",30);
  set("mass",30);
  closed=1;
  full=1;
// effect_time is the length of time the potion is in effect.
  if (!query("effect_time")) set ("effect_time", 200) ;
// color is the color of the potion...
    if (!query("color")) set ("color", "red") ;
}


void init() {
    add_action("open_bottle","open");
    add_action("close_bottle","close");
    add_action("close_bottle","cork");
    add_action("quaff_potion","drink");
    add_action("quaff_potion","quaff");
}

int close_bottle(string str) {
    if (str=="potion" || str == "vial"|| str==query("color") ) {
  if(closed==0) {

  closed=1;
  write("You cork the vial containing a "+query("color")+" potion.\n");
  say(this_player()->query("cap_name") +" corks a small vial.\n"); 
  return 1; 
  }
  write("The vial containing the "+query("color")+" potion is already corked.\n");
  return 1;
  }
  return 0;
}

int open_bottle(string str) {
if (!full) {return 1; }
  if (str=="potion" || str == "vial"||str==query("color") ) {
  if(closed==1) {
  closed=0;
  write("You open a vial containing a "+query("color")+" potion.\n");
  say(this_player()->query("cap_name") +" opens a small vial.\n"); 
  return 1; 
  }
  write("The vial containing the "+query("color")+" potion is already open.\n");
  return 1;
  }
  return 0;
}

int quaff_potion(string str) {

    object vial;
    int temp ;

    if (!full) {return 0; }
    if( str=="potion"||str=="vial"|| str==query("color")){
	if(closed==1) {
	    write("Perhaps you should open the potion vial first.\n");
	    return 1;
	}
    write("You quickly quaff the draught from the "+query("color")+" potion.\n");
    say(this_player()->query("cap_name") +" drinks a small vial.\n");
    seteuid(getuid()); 
    drinker = this_player() ;
    full=0; 
    delay=5+(random(15));
    call_out("potion_effect",delay);
// Don't want anyone messing with this while it's in effect.
// this isn't the Right Way to do this but it's better than
// any equally easy alternative.
    set ("id", ({ }) ) ;
    delete("short");
    move(VOID);
    delete("mass");
    delete("bulk");
    move(this_player());
// Now the mass and bulk are correctly removed from the player
// when the object is drunk.  There should probably be a place
// to put objects like this in the mud, to keep them somewhere
// safer than the player's inventory.  Maybe I'll make one.
    vial=clone_object(VIAL_OBJECT);
     vial->move(this_player()); 
    return 1;
    }
    return 0;
}


int potion_effect() {

    int temp;

    do_effect();
    call_out ("wear_off", query("effect_time")) ;
    return 1;
}

int do_effect() {    // define potion effect here
    return 1;      
}

int wear_off() {
	do_wear_off() ;
        remove();
        return 1;
}
