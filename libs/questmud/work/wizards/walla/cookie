inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("cookie");
set_short("A delicious cookie");
set_long("This is a very special cookie. It is given\n"+
         "to players who do nice things.\n");
set_weight(1);
set_value(0);
set_strength(20000);
}
                                                                                                         
set_id(arg) {
    return name == arg;
}

init() {
        ::init();
        add_action("eatt","eat");
}

eatt(str) {
        if(present(str) != this_object()) return;
        write("You feel good!\n");
        this_player()->set_hp(this_player()->query_max_hp());
        this_player()->set_sp(this_player()->query_max_sp());
        this_player()->set_ep(this_player()->query_max_ep());
        return;
}
