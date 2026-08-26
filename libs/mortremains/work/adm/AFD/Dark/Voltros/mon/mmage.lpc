inherit MONSTER;
void create() {
  seteuid(getuid());
  ::create();
  set("short", "munchkin mage");
  enable_commands();
  set("long", @ENDLONG
This is a frail looking, old munchkin.  He leans apon his cane
and rambles somthing about those damn trees getting in his
way.  It would seem that anything short of talking could 
hurt him.
ENDLONG
  );
  set_name("munchkin mage");
  set("id", ({
  "munchkin",
  "mage"
  }));
	set_level(10);
  set("damage", ({ 20, 50 }) );
  set("armor_class", 10);
  set("attack_strength", 10);
  set("race", "munchkin");
	set("size", 3);
  set("attrib1", "thin-faced");  set("attrib2", "wise");
  set("gender", "male");
  set("weapon_name", "fists");
  spell_cast("demon", 30);
  set_verbs( ({
    "attack",
    "swing at",

}));
}
int demon_cast() {
  object target;
  int damage;
  string name,x,y,z;
  target=query_current_attacker();
  if (!target || target->query("dead")) return 1;
  name = target->query("cap_name");
  switch(random(3)+1) {
    case 1: x = "The munchkin mage waves his hands in strange patterns!\n";
            y = "The mage casts sliver at "+name+"!\n";
            z = "You cast sliver at "+name+"!\n";
            damage = random(21)+20;
            break ;
    case 2: x = "The mage shouts incoherent words at you!\n";
            y = "The mage shouts words of power at "+name+"!\n";
            z = "You shout at "+name+"!\n";
            damage = 30;
            break ;
    case 3: x = "The munchkin mage points at you and laughs!";
            y = "The mage points at "+name+" and laughs!\n";
            z = "You fuck up "+name+"!\n";
            damage = 50;
            break ;
  }
  tell_object(target, wrap(x));
  message("combat", wrap(y), environment(), ({ this_object(), target }) );
  tell_object(this_object(), wrap(z));
    target->receive_damage(damage);
  return 1;
}
