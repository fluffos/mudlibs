//    Transmutation soul

inherit "/std/Object";

nosave object spell_ob;
nosave object caster;

void create() {
  ::create();
  set_name("soul");
  set_id(({ "borrow soul" }));
  set_long("A soul");
  return;
}

void init() {
  ::init();
  add_action("dest_spell", "quit");
  return;
}

void set_spell(object spell, object cas) {
  spell_ob = spell;
  caster = cas;
  return;
}

int dest_spell(string null) {
  if(spell_ob && caster) spell_ob->remove_trans(caster);
  return;
}
