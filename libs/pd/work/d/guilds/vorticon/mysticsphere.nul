//mysticsphere.c
//Item useful for exping
#include <std.h>
#include <guild.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("invoke", "invoke");
}
string magic_colour();
string magic_colour() {
    if(!random(4)) return "%^BOLD%^%^MAGENTA%^M%^RESET%^%^MAGENTA%^"
        "y%^BOLD%^s%^RESET%^%^MAGENTA%^t%^BOLD%^i%^RESET%^%^MAGENTA%^"
        "c %^BOLD%^S%^RESET%^%^MAGENTA%^p%^BOLD%^h%^RESET%^%^MAGENTA%^"
        "e%^BOLD%^r%^RESET%^%^MAGENTA%^e";
    else if(!random(3)) return "%^BOLD%^%^BLUE%^M%^RESET%^%^BLUE%^y"
        "%^BOLD%^s%^RESET%^%^BLUE%^t%^BOLD%^i%^RESET%^%^BLUE%^c "
        "%^BOLD%^S%^RESET%^%^BLUE%^p%^BOLD%^h%^RESET%^%^BLUE%^e%^BOLD%^"
        "r%^RESET%^%^BLUE%^e";
    else if(!random(2)) return "%^BOLD%^%^RED%^M%^RESET%^%^RED%^y"
        "%^BOLD%^s%^RESET%^%^RED%^t%^BOLD%^i%^RESET%^%^RED%^c %^BOLD%^"
        "S%^RESET%^%^RED%^p%^BOLD%^h%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^"
        "RED%^e";
    else if (!random(1)) return "%^BOLD%^GREEN%^M%^RESET%^%^GREEN%^"
        "y%^BOLD%^s%^RESET%^%^GREEN%^t%^BOLD%^i%^RESET%^%^GREEN%^c "
        "%^BOLD%^S%^RESET%^%^GREEN%^p%^BOLD%^h%^RESET%^%^GREEN%^e%^BOLD%^"
        "r%^RESET%^%^GREEN%^e";
}
int sphere;
void create() {
    ::create();
    sphere = 0;
    set_name("mystic sphere");
    set_id( ({ "sphere", "mystic sphere", "magic sphere", 
        "a magic sphere" }) );
    set_short(""+magic_colour()+"%^RESET%^");
    set_long("The sphere is perfectly round, it is so small "
      "that it would easily fit inside an average human's "
      "hands. An aura of magic covers it completely. They "
      "were created by the children of Vaul, a powerful "
      "artifact in the hands of the chosen.");
    set_mass(2);
   set_curr_value("gold", 1200);
    set_destroy();
}

//  BALANCE- made it random time

int invoke(string str) {
    int de, i;
    object *stuff;

    if(!str) return notify_fail("What?\n");
    if(str != "sphere") return notify_fail("What?\n");
    if(this_player()->query_guild() != "vorticon") return notify_fail("What?\n");
    if(sphere) {
        write("The power of the mystic spheres are already inside of you.\n");
        return 1;
    }
    stuff = all_inventory(this_player());
    i = sizeof(stuff);
    while(i--) {
        if(stuff[i]->query_sphere()) {
          write("The power of the mystic spheres are already inside of you.\n");
          return 1;
        }
    }
    write("You invoke the "+magic_colour()+" into your "
      "body and an aura of protection surrounds you.\n");
    de=1800 + random(1800);
    this_player()->add_magic_protection(({0, 7, de}));
    if(random(3)) this_player()->disable();
    this_object()->set_short("");
    this_object()->set_id(({ "hidden_object" }));
    sphere = 1;
    call_out("sphere_dead", de, this_player());
    return 1;
}

int sphere_dead() {
    sphere = 0;
    write("%^BOLD%^The aura around you fades into the darkness.\n");
    this_object()->remove();
    return 1;
}

string extra_look() {
    if(sphere) return "%^BOLD%^A slight protective aura surrounds "+
        objective(environment(this_object()))+"\n";
    return 0;
}

int query_sphere() {return sphere;}
