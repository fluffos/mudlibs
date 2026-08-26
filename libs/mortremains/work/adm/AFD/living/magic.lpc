// Spell_damage() exists so the damage from spells comes from the player,
// .. otherwise kills and xp won't get logged right.
int spell_damage(int damage, object target, string type) {
   if (!target) return -1;
   if (damage<1) return -1;
   if (!type) type = "magic";
  target->receive_damage(damage, type);
  target->kill_ob(this_object());
  return 1;
}

int cast_spell(int cost) {
  if (!cost) return -1;
  if ((int)this_object()->query("spell_points")<cost) return 0;
  this_object()->add("spell_points", -1 * cost);
  if (userp(this_object()))
  this_object()->monitor();
  this_object()->add("spell_block", 1);
  return 1;
}
