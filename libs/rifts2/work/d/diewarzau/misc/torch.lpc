//	/obj/torch.c
//	from the Nightmare mudlib
//	created by Forlock
//	motion checks added by Descartes of Borg 12 october 1992
//	other fixes by Hanse 02 november 1992
 
#include <std.h>
#include <daemons.h>
#include <security.h>
#include <rooms.h>

inherit OBJECT;
 
int lit, fuel, light_time;
 
void create() {
  ::create();
    set_name("torch");
    set_id( ({ "torch" }) );
    set_short("A torch");
    set_long("A torch to light up the dark parts of your life.\n");
    set_weight(100);
    set_value(70);
    fuel = 1200;
    lit = 0;
}
 
void init() {
     add_action("test_func","test");
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
}
 

int clean_up() {
  if(find_player("diewarzau")) {
    tell_object(find_player("diewarzau"), "It is clean!");
  }
  return ::clean_up();
}

void origin_test() {
  message("info", "Origin: "+origin(), find_player("diewarzau"));
  message("info", "prev: "+sprintf("%O", previous_object()),
	find_player("diewarzau"));
  return;
}

int test_func(string str) {
  object ob;
  int i, light;
  object *inv;

  write(base_name(this_object()));
  write(implode(explode("/d/damned/akkad", "/"), "/"));
  write(sprintf("%O", deep_inherit_list(this_object())));
  seteuid(getuid());
  inv = all_inventory(load_object(ROOM_VOID));
  i = sizeof(inv);
  while(i--) inv[i]->move(environment(this_player()));
  write("tlight: "+total_light(this_player()) + "elight: "+effective_light(this_player()));
  inv = all_inventory(environment(this_player()));
  light = 0;
  i = sizeof(inv);
  while(i--) light += (int) inv[i]->query_property("light");
  write("Env: "+(int)environment(this_player())->query_property("light") +
	" tot: "+light);
  if(ob) write("there!");
  else write("not there.");
  write(sprintf("%O", call_other("/d/damned/virtual/weapon_db",
    "get_table", (str?str:"two-handed-sword"))));
  return 1;
}


void test2() {
   call_out("beep_dr", 4, "yo", "dude");
   return;
}

void beep_dr(string yo, string dude) {
    tell_object(find_player("diewarzau"), yo+dude);
   return;
}

int light(string str) {
    if(effective_light(this_player()) < -1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(!id(str)) {
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
    say(this_player()->query_cap_name()+" lights a torch.\n", this_player());
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
        notify_fail("The torch is not lit!\n");
        return 0;
    }
    write("You extinguish the torch.\n");
    say(this_player()->query_cap_name()+" extinguishes a torch.\n",
        this_player());
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
 
    if(lit) environment(this_object())->set_property("light", -2);
    x = ::move(dest);
    if(lit) environment(this_object())->set_property("light", 2);
    return x;
}

/*Plura 9302??*/
int query_lit() { return lit; }

/*Plura*/
int query_fuel() { return fuel; }

/* Valodin */
remove()
{
   if (lit) environment(this_object())->set_property("light",-2);
   return ::remove();
}


