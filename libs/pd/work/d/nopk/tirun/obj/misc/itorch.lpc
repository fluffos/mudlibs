//      infinite torch based on
//      Forlock's torch (/std/obj/torch.c)
//      Nightshade
 
#include <std.h>

inherit OBJECT;

int lit;

int extinguish(string str);

int is_light()      { return 1; }

void create() {
   ::create();
   set_short("Infinite Torch");
   set_name("torch");
   set_long("This magical torch can be used by anyone.  It has no fuel, and you can <turn on> the torch at will.");
   set_id(({"torch","infinite torch"}));
   set_value(0);
   lit = 0;
    set_property("magic item", ({"turn on"}) );
}
 
void init() {
    ::init();
    add_action("turn", "turn");
}
 
int turn(string str) {
    string this;
    int *all_lit;
    if (!str || str == "") return 0;
    if(sscanf(str, "on %s", this) == 1) {
        str = "on";
        if(this_object() != present(this, this_player()))
            return 0;
    }
    if(sscanf(str, "off %s", this) == 1) {
        str = "off";
        if(this_object() != present(this, this_player()))
            return 0;
    }
    if(str == "off")
        return extinguish(str);
    if(lit) {
        write("It is already lit!");
        return 1;
    }
    all_lit = filter(all_inventory(this_player()), (: base_name($1) == base_name(this_object()) :) )->query_lit();
    if (sizeof(all_lit) > 1)
      foreach (int l in all_lit) if (l) { write("The torch refuses to light."); return 1; }
    write ("You turn on the "+this_object()->query_short()+".");
    say(this_player()->query_cap_name()+" turns on a "+
      this_object()->query_short()+".", this_player());
    environment(this_object())->set_property("light", 2);
    lit = 1;
    return 1;
}
 
int extinguish(string str) {
    if(!lit) {
        write("The "+this_object()->query_short()+" is not lit!");
        return 1;
    }
    write("You turn off the "+this_object()->query_short()+".");
    say(this_player()->query_cap_name()+" turns off a "+
      this_object()->query_short()+".", this_player());
    environment(this_object())->set_property("light", -2);
    lit = 0;
    return 1;
}
 
string query_short() {
    string str;

    str = ::query_short();
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

/* Valodin */
int remove() {
   if (lit) environment(this_object())->set_property("light",-2);
   return ::remove();
}

int query_auto_load() {return 1;}
