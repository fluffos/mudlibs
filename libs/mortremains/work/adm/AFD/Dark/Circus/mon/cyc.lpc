inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a clumsy cyclops");
  enable_commands();
  set("long", @ENDLONG
Hersch is a giant humanoid creature with a single eye resting in the
middle of his forehead.  A small tuft of hair spouts from his pointed
skull.  He is wearing leather overalls, covered in stains of all kinds.
ENDLONG
  );
  set_alignment(100);
  set_name("hersch");
  set("id", ({
    "cyclops",
    "hersch",
    "clumsy cyclops",
  }));
  credit(100 + random(300) );
  set("damage", ({ 15, 40 }) );
  set("armor_class", 5);
  set("attack_strength", 14);
  set("race", "cyclops");
  set("attrib1", "middle aged");  set("attrib2", "long handed");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set("size", 9);
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7);
  set("chat_chance", 5);
  set("chat_output", ({
    "Hersch drops something on his foot and swears in an incomprehensible language.\n",
    "Hersch accidently pokes himself in the eye and is blinded for a few seconds.\n",
    "The cyclops sits on his stool and groans.\n", 

 }) );
  
}
