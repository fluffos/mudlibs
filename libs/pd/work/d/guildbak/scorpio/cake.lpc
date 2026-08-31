#define COLORS ({ "%^BOLD%^%^YELLOW%^yellow%^RESET%^", \
                  "%^BOLD%^%^BLUE%^blue%^RESET%^", \
                  "%^BOLD%^%^GREEN%^green%^RESET%^", \
               })
inherit "/std/food";

int create() {
    string c;
    ::create();
    c = COLORS[random(sizeof(COLORS))];
    set_id(({ "cake", "peice of "+c+" cake", "peice of cake" }));
    set_name("cake");
    set_short("a peice of "+c+" cake");
    set_long("This is a yummy looking peice of cake with "+c+" iceing.");
    set_my_mess("You gobble down the peice of cake.");
    set_your_mess("gobbles down a peice of cake.");
    set_strength(8);
    set_weight(3);
}

