inherit "/ai/module";

string query_module_name()
{
   return "defensive_mage";
}

// respond to attackers with hold spell
void on_hit(object attacker, int damage)
{
   object mob = environment();

   if( damage > mob->query_hp() / 10 || damage > 10 )
   {
      say( "Oh yeah? Well, take that!" );
      command( "cast hold at "+attacker->query_name(), mob );
   }
}

void on_tick()
{
   object mob = environment();
   int rand = random( 500 ) + 1;

   // Don't waste mana if not in combat!
   if( !environment()->query_in_combat() ) return;

   // check each spell that he could have up, and maintain them ;)
   if( present_clone( "/magic/obj/slow_object", mob ) && rand < 100 )
   {
      if( !mob->query_env_var( "slowed_msg" ) )
         say( "Hmm... I'm slowed, casting haste" );
      else
         mob->msg_local( mob->query_env_var( "slowed_msg" ) );

      command( "cast haste", mob );
   }
   else if( !present_clone("/magic/obj/haste_object", mob ) && rand < 50 )
   {
      if( !mob->query_env_var( "haste_msg" ) )
         say( "Hmm... I'm no longer hasted, casting haste" );
      else
         mob->msg_local( mob->query_env_var( "slowed_msg" ) );

      command( "cast haste", mob );
   }
   else if( !present_clone( "/magic/obj/shield_object", mob ) && rand < 150 )
   {
      if( !mob->query_env_var( "shield_msg" ) )
         say( "Hmm... My shield has broken, casting shield" );
      else
         mob->msg_local( mob->query_env_var( "slowed_msg" ) );

      command( "cast shield", mob );
   }
}
