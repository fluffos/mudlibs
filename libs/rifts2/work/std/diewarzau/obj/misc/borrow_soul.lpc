//    Prepare skill soul

inherit "/std/Object";

nosave object caster;
nosave object spell_ob;

void create() {
  ::create();
  set_name("soul");
  set_id(({ "borrow soul" }));
  set_long("A soul");
  return;
}

void init() {
  ::init();
  add_action("allow_borrow", "allow");
  return;
}

void set_allow(object who, object spell) {
  caster = who;
  spell_ob = spell;
  call_out("expire_time", 60);
  return;
}

int allow_borrow(string str) {
  if(!caster) return 0;
  if(lower_case(str) != (string)caster->query_name())
    return 0;
  if(!spell_ob) {
    write("Cannot find the borrow spell.  This is a BUG.");
    return 1;
  }
  spell_ob->allowed(this_player());
  write("Ok.");
  return 1;
}

void expire_time() {
  remove();
  return;
}
