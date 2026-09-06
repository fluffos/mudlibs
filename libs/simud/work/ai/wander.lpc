inherit "/ai/module";

string query_module_name() {
   return "wander";
}

void on_tick() {
   if( random(100) < 10 )
      environment()->wander();
   else if( random(100) < 25 )
      command( "walk random", environment() );
}
