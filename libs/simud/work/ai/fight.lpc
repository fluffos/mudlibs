inherit "/ai/module";

string query_module_name() {
   return "fight";
}

void on_hit( object attacker, int hp ) {
   say( "Ugh, " + attacker->query_distant() + " hit me, and I took " + hp + " damage." );
}

void on_combat_action( object form ) {
   form->default_action(this_object());
}
