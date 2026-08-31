inherit "/std/weapon";
int weapon_hit(object ob);

create() {
    ::create();
   set_id(({"sword", "the_one_orc_slayer","orcslayer","fine sword"}));
   set_name("orcslayer");
   set_short("a fine sword");
    set_long("It is a very finely crafter sword with the picture of a dying orc on it.\nThere are writings on it.\n");
   set_weight(9);
   set_curr_value("gold", 63);
   set_wc(5);
   set_ac(1);
   set_type("blade");
    set_wield("You feel a great hatred for orcs as you wield the sword.\n");
    set_hit((:weapon_hit:));
    set("read", "Orcslayer\n");
   set_destroy();
}

int weapon_hit(object ob) {
    int x, y;

    if((string)ob->query("race") != "orc") return 0;
    y = random(10);
    x = (int)this_player()->query_alignment();
    if(x> 0) x = (x/100);
    else x = 0;
    y += x;
    write("The Orcslayer draws more orc blood!\n");
    say(this_player()->query_cap_name()+" Orcslayer draws more orc blood!\n", this_player());
    return y;
}
int query_autoload() { if (this_player()->query_level() > 4) return 1; }
