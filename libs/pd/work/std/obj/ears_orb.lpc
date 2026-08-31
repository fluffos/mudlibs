//    /std/obj/ears_orb.c
//    Nightmare Mudlib
//    Object for use with the 'wizards ear' spell
//    By Kalinash@Nightmare April 19, 1994.

#include <std.h>

inherit OBJECT;

void set_caster_level(int x);
void set_caster(object who);
void start_dest(int x);

int caster_level;
object caster;



void create() {
    ::create();
    set_name("ears");
    set_id( ({"orb", "ear"}) );
    set_short("a small orb");
    set_long("You stare into the small orb.  Inside you see nothing but "
      "swirling chaos.  The longer you look at it, the more you feel like "
      "you are being drawn into it.");
    enable_commands();
    set_living_name("orb");
    set_prevent_get("You can't get that\n");
    set_mass(50);
    set_value(0);
}

int test_invis(object who, object to_whom) {
    string Class;

    Class = to_whom->query_class();
    if(Class != "sage") return 1;
    if((int)to_whom->query_level() < caster_level)
        return 1;
    return 0;
}

void set_caster_level(int x) { caster_level = x; }

void dest_me(int x) {
    if(!x) {
        message("my_action", "%^RED%^The sounds from the orb are silenced."
          "%^RESET%^", caster);
        this_object()->remove();
        return;
    }
    x--;
    message("my_action", "%^CYAN%^The voices from the orb grow slightly "
      "softer.", caster);
    call_out("dest_me", 25, x);
}

void set_caster(object who) { caster = who; }

void receive_message(string crap, string drow) {
    message("my_action", sprintf("%%^GREEN%%^(*)%%^RESET%%^ %s", drow),
          caster);
          }
void start_dest(int x) {
    call_out("dest_me", 25, x);
}
