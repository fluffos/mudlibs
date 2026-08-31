inherit OBJECT;

 
void create() {::create();;
    set_name("chocolates");;
    set_id( ({ "chocolates", "chocolate"}) );;
    set_short("Azire's box of Chocolates");;
    set_long("A golden packet of never ending chocolates with the name Azire
written in fancy lettering on the lid. Maybe she should %^BOLD%^CYAN%^eat a chocolate?%^RESET%^");;
    set_mass(1);;
}



void init() 

{
::init();

add_action("eat_function", "eat");

}

int eat_function(string str) {

    if (!str || str == "") {return 0;}
if (str == "chocolate"){write("%^BOLD%^YELLOW%^You eat a chocolate and feel much happier.%^RESET%^");;
        say(this_player()->query_cap_name()+" eats a chocolate and looks much happier.");
        return 1;;
}
}
