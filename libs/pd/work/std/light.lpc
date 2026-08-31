//	/std/light.c
//      Created by ::Inferno(12/29/00);
//      An inheritable light source object, based on
//      Forlock's torch (/std/obj/torch.c)
 
#include <std.h>

inherit OBJECT;
 
int lit, fuel, light_time, max_fuel, fill;

int query_fuel()    { return fuel; }
int query_fill()    { return fill; }
void set_fill(int x){ fill = x;    }
void set_fuel(int x) { fuel = x; if (fuel > max_fuel) fuel = max_fuel; }
void add_fuel(int x) { fuel += x; if (fuel > max_fuel) fuel = max_fuel; }
int is_light()      { return 1; }
int query_max_fuel(){ return max_fuel; }
void set_max_fuel(int x) { max_fuel = x; }

void create() {
 ::create();
   lit = 0;
}
 
void init() {
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
}
 
int light(string str) {
    if(!id(str)) {
        notify_fail("Light what?\n");
        return 0;
    }
    if(!fuel) {
        notify_fail("The "+this_object()->query_short()+" is "
          "out of fuel.");
        return 0;
    }
    if(lit) {
        notify_fail("It is already lit!\n");
        return 0;
    }
    write ("You light the "+this_object()->query_short()+".");
    say(this_player()->query_cap_name()+" lights a "+
      this_object()->query_short()+".", this_player());
    environment(this_object())->set_property("light", 2);
    call_out("go_dark", fuel);
    light_time = time();
    lit = 1;
    return 1;
}
 
int extinguish(string str) {
    if(!id(str)) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
    if(!lit) {
        notify_fail("The "+this_object()->query_short()+" is not lit!\n");
        return 0;
    }
    write("You extinguish the "+this_object()->query_short()+".");
    say(this_player()->query_cap_name()+" extinguishes a "+
      this_object()->query_short()+".", this_player());
    environment(this_object())->set_property("light", -2);
    fuel -= (light_time - time());
    remove_call_out("go_dark");
    lit = 0;
    return 1;
}
 
void go_dark() {
    environment(this_object())->set_property("light", -2);
    fuel = 0;
    if(living(environment(this_object())))
	tell_object(environment(this_object()), "Your "
          +this_object()->query_short()+" goes dark.");
//    set_short(::query_short()+" (out of fuel)");
//    set_long("The "+this_object()->query_short()+" has exhuasted its "
//      "fuel.");
    set_destroy();
    set_value(10);
    lit = 0;
}

string query_long(string str) {
   if (!fuel) return "The "+query_short()+" has exhausted it's fuel.";
   else return ::query_long(str);
}
 
string query_short() {
    string str;

    str = ::query_short();
    if (!fuel) str = str+" (out of fuel)";
    if (lit) str = str+" (lit)";
    return str;
}
 
int move(mixed dest) {
    int x;
 
    if(lit) environment(this_object())->set_property("light", -2);
    x = ::move(dest);
    if(lit) environment(this_object())->set_property("light", 2);
    return x;
}

/*Plura 9302??*/
int query_lit() { return lit; }

/*Plura
int query_fuel() { return fuel; }
*/
/* Valodin */
int remove() {
   if (lit) environment(this_object())->set_property("light",-2);
   return ::remove();
}
