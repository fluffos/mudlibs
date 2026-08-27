inherit "obj/monster";
void setup()
{
    set_name("devil");
    add_adjective("dust");
    set_main_plural("dust devils");
    add_plural("devils");
    /*set_no_corpse();*/
    set_short("Dust Devil");
    set_long("The Dust Devil looks like a smoky intangible cloud.\n");
    set_race("devil");
    set_class("fighter");
    set_level(random(7)-3);
    set_al(-100);
    call_out("destruct", 500);
}

void destruct()
{
 tell_object(environment(),
  "The Dust Devil returns to the elemental plane of air.\n");
 dest_me();
}
