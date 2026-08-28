inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("robe");
    set_alias("robe");
    set_short("A dark silk robe of Nyx");
    set_long("This robe is made of dark silk. It glows magically when you touch it,\n"
             "It covers your torso. It has a picture of human skull written in golden letters.");
    set_ac(5);
    set_value(5000);
    set_stats("int", 15);
    set_stats("wis", 10);
    set_stats("con", -10);
    set_stats("str", -10);
    set_stats("spr", 15);
    set_slot("torso");

}
