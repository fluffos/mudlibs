inherit "/ai/module";

mapping threats;

string query_module_name() {
   return "hit_around";
}

int most_dangerous(object a, object b) {
   return threats[a] > threats[b];
}

// hit around randomly, picking particularly on whoever is doing the most
// damage
void on_hit( object attacker, int hp ) {
   object mob = environment();
   object *enemies = mob->query_targets();
   if (!mappingp(threats))
      threats = ([]);
   threats[attacker] += hp;
   sort_array(enemies, "most_dangerous");
   mob->set_targets(enemies);
}
