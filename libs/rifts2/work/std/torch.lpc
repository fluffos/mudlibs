//	/obj/torch.c
//	from the Nightmare mudlib
//	created by Forlock
//	motion checks added by Descartes of Borg 12 october 1992
//	other fixes by Hanse 02 november 1992

#include <std.h>

inherit OBJECT;

int lit, fuel, light_time;
object shadow;

void create() {
  ::create();
    set_name("torch");
    set_id( ({ "torch" }) );
    set_short("A torch");
    set_long("A torch to light up the dark parts of your life.\n");
    set_weight(100);
    set_float_value(0.1);
    fuel = 1200;
    lit = 0;
    shadow = 0;
    set_property("no save", 1);
}


void init() {
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
}

int light(string str) {
    if(effective_light(this_player()) < -2) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(!str || present(str, this_player()) != this_object()) {
        notify_fail("Light what?\n");
        return 0;
    }
    if(!fuel) {
        notify_fail("The torch is out of fuel.\n");
        return 0;
    }
    if(lit) {
        notify_fail("It is already lit!\n");
        return 0;
    }
    write ("You light the torch.\n");
    seteuid(getuid());
    say(this_player()->query_cap_name()+" lights a torch.\n", this_player());
    shadow = new("/std/spells/shadows/light_shad");
    shadow->set_light(2);
    shadow->start_shadow(environment());
    call_out("go_dark", fuel);
    light_time = time();
    lit = 1;
    return 1;
}

int extinguish(string str) {
    if(!str || present(str, this_player()) != this_object()) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
    if(!lit) {
        notify_fail("The torch is not lit!\n");
        return 0;
    }
    write("You extinguish the torch.\n");
    say(this_player()->query_cap_name()+" extinguishes a torch.\n",
        this_player());
        fuel -= (light_time - time());
    if(shadow) shadow->external_destruct(shadow);
    remove_call_out("go_dark");
    lit = 0;
    return 1;
}

void go_dark() {
    if(shadow) shadow->external_destruct(shadow);
    fuel = 0;
    if(living(environment(this_object())))
	tell_object(environment(this_object()), "Your torch goes dark.\n");
    set_short(::query_short()+" (out of fuel)");
    set_long("The torch has exhuasted its fuel.\n");
    set_destroy();
    set_value(10);
    lit = 0;
}

string query_short() {
    string str;

    str = ::query_short();
    if(lit) str = str+ " (lit)";
    return str;
}

int move(mixed dest) {
    int x;

    if(lit && shadow) {
      seteuid(getuid());
      shadow->external_destruct(shadow);
    }

    x = ::move(dest);
    if(lit) {

      shadow = new("/std/spells/shadows/light_shad");
      shadow->set_light(2);
      shadow->start_shadow(environment());
    }
    return x;
}

/*Plura 9302??*/
int query_lit() { return lit; }

/*Plura*/
int query_fuel() { return fuel; }

/* Valodin */
int remove()
{
   if(lit && shadow)
      shadow->external_destruct(shadow);

   return ::remove();

}
