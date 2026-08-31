inherit MONSTER;
void create(){
    ::create();
    set_name("Helgrath Guardian");
    set_short("Helgrath Guardian");
    set_id(({"helgrath guardian", "guardian", "guard"}));
    set_long(
      "A guardian of Helgrath,");
    set_level(35);
    set_gender("male");
    set_race("human");
    set_body_type("human");
    set_alignment(1500);
    set_class("fighter");
    set_subclass("warrior");
    set_spell_chance(45);
    set_spells( ({"slash"}) );
    new("/d/helgrath/items/weapons/shortsword")->move(this_object());
    command("wield sword");
    new("/d/helgrath/items/armor/platemail")->move(this_object());
    command("wear all");
}

