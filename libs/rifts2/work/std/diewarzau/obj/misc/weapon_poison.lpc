inherit "/std/Object";

int strength;

void create() {
  ::create();
  set_name("poison");
  set_id( ({ "poison", "weapon poison", "vial" }) );
  set_short("A vial of weapon poison");
  set_long("This poison may be placed on weapons to increase their "
"deadliness.  Apply with the command 'apply <what> to <weapon>' where "
"<what> is the vial you wish to use and <weapon> is the weapon you wish to "
"poision.  The poison runs out after a few hits with the weapon.");
  set_weight(10);
  return;
}

void set_strength(int x) {
  strength = x;
  set_value(x * 5);
  return;
}

void init() {
  ::init();
  add_action("poison_weapon", "apply");
  return;
}

int poison_weapon(string str) {
  string tmp1, tmp2;
  object weap;

  if(sscanf(str, "%s to %s", tmp1, tmp2) != 2)
    return 0;
  if(present(tmp1, this_player()) != this_object()) return 0;
  weap = present(tmp2, this_player());
  if(!weap) {
    write("You don't have "+article(str)+".");
    return 1;
  }
  if(!weap->is_weapon()) {
    write("That is not a weapon.");
    return 1;
  }
  weap->add_poisoning(strength);
  write("You apply the poison.");
  message("other_action", (string)this_player()->query_cap_name() +
	  " applies a vial of poison to "+ (string)weap->query_short() +
	  ".", environment(this_player()), ({ this_player() }) );
  remove();
  return 1;
}

