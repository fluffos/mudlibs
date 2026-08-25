string *attack_names;

int attack_num(string attack) { 
  if (!attack_names)
    attack_names = ({ "null", "sharp", "blunt", "piercing", "unarmed", 
    "acid", "age", "charm", "cold", "confusion", "dam", "disease", "fear",
    "fire", "light", "lightning", "missile", "paralysis", "petrification",
    "poison", "sleep", "special_attack", "stat_mod", "stunning", "undead",
    "wither" }); 
  return member_array(attack, attack_names);
} 
