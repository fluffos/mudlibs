string query_action_name() {
   return "Cut";
}

int main( string param ) {
   object ob;
   string shape;

   if( !param )
      return notify_fail( "Cut what?\n" );

   if ( sizeof(filter( all_inventory(this_player()), (: (HAS_ASPECT($1, C_KNIFE) || HAS_ASPECT($1, C_DAGGER) || HAS_ASPECT($1, C_DIRK)) && $1->query_held() :) )) == 0 )
     return notify_fail("What, with your teeth? You need to be holding a knife to do this correctly.\n");

   if( sscanf(param,"%s into %s",param,shape) == 2 ) {
      msg("The ~CCOMcut~CDEF command does not support shapes yet.");
   }

   ob = single_present( param, this_player(), (: $1->query_has_aspect(C_PELT) :) );

   if( !ob )
      return notify_fail( "Hrm, I can't seem to find that, or it isn't an animal skin.\n" );

   WALK_ACTION( 1100, ob );

   return 1;
}

void on_action( object ob ) {
   object piece_ob, knife, *knives;

   if( !ob || environment(ob) != this_player() ) {
      msg( "It appears that the object of your cutting is no longer present." );
      return;
   }

   knives = filter( all_inventory(this_player()), (: (HAS_ASPECT($1, C_KNIFE) || HAS_ASPECT($1, C_DAGGER) || HAS_ASPECT($1, C_DIRK)) && $1->query_held() :) );
   if( sizeof(knives) == 0 ) {
      msg( "Something appears to have happened to your knife... curious.");
      return;
   } else {
      knife = knives[0];
   }

   if( this_player()->query_stance() != ST_SITTING )
      this_player()->set_stance(ST_SITTING);

   piece_ob = ob->on_cut();
   set_target(ob);
   if (piece_ob) {
      piece_ob->move( this_player() );
      this_player()->msg_local( "~CACT~Name ~verbcut " + piece_ob->query_specific() + " from ~targ.~CDEF" );
      knife->add_condition(-1);
      if( this_player()->query_skill( "combat.weapon.dagger" ) < 20 )
         this_player()->practice_skill( "combat.weapon.dagger" );
   }
   this_player()->add_readiness( -250 );

   if ( ob->query_size() ) {
      if ( !knife || knife->query_broken() ) {
         this_player()->add_readiness( -100 );
         if ( sizeof(knives) > 1 ) {
           msg("You continue cutting ~targ after switching knives.");
         } else {
           msg("Since your knife is broken, you stop working on ~targ.");
           return;
         }
      }
      this_player()->set_action( -1, ({ 1000, this_object(), ob, ST_SITTING, 0 }) );
   } else {
      set_target(ob);
      this_player()->msg_local( "~CACT~Name ~verbfinish working on ~targ.~CDEF" );
      destruct(ob);
   }
}
