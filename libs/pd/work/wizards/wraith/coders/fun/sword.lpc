inherit "/std/weapon";

create() {
    ::create();
   set_id( ({ "sword", "long sword", "longsword" }) );
   set_name("longsword");
   set_short("a master longsword");
   set_long("This sword's blade is long, and thin, requiring two hands "
      "and a master's skill. It is not for those skilled in blade, but "
      "rather those skilled in the arts of two-handed weapons.");
   set_weight(4);
    set_curr_value("silver", 625);
   set_wc(5);
   set_ac(1);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_skill("two handed") > 12)
return 1; }
