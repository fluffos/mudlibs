#include <std.h>
inherit WEAPON;
int wear_glove();

void create() {
   ::create();
   set_name("staff");
   set_id( ({"staff","justicestaff",}) );
   set_short("%^BOLD%^%^BLACK%^The S%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^f%^BOLD%^%^BLACK%^f of %^BOLD%^%^WHITE%^Ju%^RESET%^%^ORANGE%^s%^BOLD%^%^YELLOW%^t%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^ce%^RESET%^");
   set_long("Wraith will get back with you shortly.");
   set_wc(12);
   set_ac(1);
   set_mass(999);
   set_value(1);
   set_type("staff");
   set("skill level", 100+random(35));
   set_type("melee");
   set_unwield("%^BOLD%^%^RED%^The power leaves you swiftly.\n");
}
int slap_on_the_wrist(string str) {
   message("info","%^BOLD%^%^RED%^" +this_player()->query_cap_name()+
     " now wields %^BOLD%^%^BLACK%^The S%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^f%^BOLD%^%^BLACK%^f of %^BOLD%^%^WHITE%^Ju%^RESET%^%^ORANGE%^s%^BOLD%^%^YELLOW%^t%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^ce%^BOLD%^%^RED%^.%^RESET%^\n",users());
   this_player()->add_skill("melee", 30);
   return 1;
}



void init() {
   ::init();
   add_action("zap","zap");
   add_action("humble","humble");
   add_action("slap_on_the_wrist","wield");
   add_action("die","kill");

}

int zap(string str) {
   object who;
   if(!str){ notify_fail("Page whom?\n"); return 0; }
   if(!present(this_object(), this_player())) return 0;
   if(!(who = find_living(lower_case(str)))) {
        notify_fail("That person is not currently on primal darkness.\n");
        return 0;
}
    if (present("gag", who)) present("gag", who)->remove();
    if (present("pillow", who)) present("pillow", who)->remove();
    who->force_me("restartheart");
    message("page",""+this_player()->query_cap_name()+" zaps you with a bolt of %^BOLD%^%^YELLOW%^li%^BOLD%^%^WHITE%^gh%^BOLD%^%^YELLOW%^tn%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^ng.%^RESET%^",who);
    message("page",capitalize(str)+" has been zapped.",this_player());
   return 1;
}


int humble(string str) {
   object who;
   if(!str){ notify_fail("Humble whom?\n"); return 0; }
   if(!present(this_object(), this_player())) return 0;
   if(!(who = find_living(lower_case(str)))) {
        notify_fail("That person is not currently on primal darkness.\n");
        return 0;
}
    who->force_me("shout Im a little teapot, short and stout. Here is my handle and here is my spout.");
    message("page",""+this_player()->query_cap_name()+" has forced you to humble yourself in front of others.",who);
    message("page",capitalize(str)+" has been humbled.",this_player());
   return 1;
}

int die(string str) {
   object who;
   if(!str){ notify_fail("Kill whom?\n"); return 0; }
   if(!present(this_object(), this_player())) return 0;
   if(!(who = find_living(lower_case(str)))) {
        notify_fail("That person is not currently on primal darkness.\n");
        return 0;
}
    who->die();
    message("page","%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" has smited you to oblivion!",who);
    message("page",capitalize(str)+" has been killed.",this_player());
   return 1;
}
