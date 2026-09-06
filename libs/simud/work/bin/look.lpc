#include <const.h>

int main( string param ) {
   object env;
   string buf, tmp, *inv;

//   msg("Begin look:" + utime()[0] + ":" + utime()[1]);
   env = environment(this_player());
   set_listener(this_player());

   if(!env) {
      this_player()->move( "/obj/void" );
      env = environment(this_player());
   }
   if(!env) {
      msg("Look command fails; I couldn't even get the void to work.\n");
      return 1;
   }

   // generates the room description
   if( !param ) {
      // start area soundtrack
      if( this_player()->query_env_var("Tmsp") )
         AUDIO_DAEMON->start_the_music( this_player() );
      // Fetch the top line.
      buf = "~CTIT" + env->query_short();
      tmp = env->query_exit_list();
      if( tmp )
         buf += " ~CREF(Exits: " + comma_list( tmp ) + ")~CDEF";
      else
         buf += "~CDEF";
      msg( buf );
      buf = "";
      if( !this_player()->query_brief() || query_verb() == "look" ) {
         tmp = env->query_room_desc();
         if( !tmp ) tmp = env->query_long();
         buf += tmp;
      }
      inv = env->query_inventory_list();
      if( inv ) {
         mapping actions = ([ ]);
         mixed *mobs;
         string para2, curr_phrase, *curr_actors;
         int i;

         para2 = "\n\n";

         inv -= ({ this_player() });
         mobs = filter( inv, (: $1->query_is_living() :) );
         if( sizeof(mobs) ) {
            for( i = sizeof(mobs); i--; ) {
               string doing;

               doing = mobs[i]->query_doing();
               if( !doing ) doing = "standing here";
               if( !actions[doing] ) actions[doing] = ({ });
               actions[doing] += ({ mobs[i] });
            }

            tmp = "";
            mobs = ({ });
            i = 0;
            foreach( curr_phrase, curr_actors : actions ) {
               mobs = curr_actors;
               if( sizeof(curr_actors) == 1 ) {
                  switch( i % 3 ) {
                     case 0: tmp += "You see " + inventory_string(curr_actors) + " " + curr_phrase + ". "; break;
                     case 1: tmp += capitalize(inventory_string(curr_actors)) + " is " + curr_phrase + ". "; break;
                     case 2: tmp += "You also see " + inventory_string(curr_actors) + " " + curr_phrase + ". "; i = -1; break;
                  }
                  i++;
               }
               else
                  tmp += capitalize( inventory_string(curr_actors) + " are " + curr_phrase + ". " );
            }
            para2 += eval_exp(tmp, this_player());
         }

         inv = filter( inv, (: !$1->query_is_living() :) );
         tmp = inventory_string(inv);
         if( tmp != "" ) {
            if( para2 == "\n\n" )
               para2 += "You see " + tmp + ". ";
            else
               para2 += "You also see " + tmp + ". ";
         }
         if( para2 != "\n\n" ) buf += para2;
      }
      if( this_player()->query_env_var("Tmap") ) {
         int width, map_width;
         string map;

//         msg("Before map query: "+utime()[0]+":"+utime()[1]);
         map = env->query_map();
         if( !map ) {
            msg( buf + "\n" );
            return 1;
         }
         map_width = env->query_map_xdim();
         width = this_player()->query_term_width();
         width -= map_width + 3;
         buf = "  " + break_string(process_codes(buf), width, 2);
         buf = "/inherit/textdraw"->splice_text( process_ansi(map), buf, env->query_map_xdim() );
//         msg("After splice: "+utime()[0]+":"+utime()[1]);
         write( buf ); write( "\n" );
      }
      else
         msg( buf + "\n" );
   }
   // looks for a matching item
   else {
      string prep, what, container, invstr;
      object ob, *oblist, *containers;

      // looks for whether a preposition was used
      sscanf( param, "%s %s", prep, what );
      // defaults to "at" if none was given
      if( member(STD_PREPOSITIONS, prep) < 0 ) {
         what = param;
         prep = "at";
      }
      // checks for possessive, which equates to looking "in"
      if ( sscanf(param, "%s's %s", container, what) == 2 )
         prep = "in";

      // searches player's inventory first
      oblist = all_present(what, this_player());
      // searches player's environment next
      if( !oblist )
         oblist = all_present(what, env);
      // searches inventory of things in player's environment last
      if( !oblist ) {
         containers = all_present( container, env );
         if( !containers ) containers = ({ });
         oblist = ({ });
         foreach( ob : containers )
            oblist += all_present( what, ob );
      }

      if( sizeof(oblist) ) {
         foreach( ob: oblist ) {
            if( !valid_manipulate(this_player(), ob) && !ob->query_worn() && !ob->query_held())  {
               if( ob == environment(this_player()) )
                  msg("Just type 'look' by itself for a room description.");
               else
                  msg("You can't see that, skipping...");
               continue;
            }
            buf = ob->query_look();
            if( !buf ) continue;
            set_actor(ob);
            msg( eval_exp(buf, ob) + "\n" );
         }
         if( sizeof(oblist) > 1 ) {
            this_player()->set_pronoun( oblist );
            this_player()->say_local( "~CACT~Name ~verbtake a good look around.~CDEF" );
            this_player()->set_doing( "taking a look around" );
         }
         else {
            set_target(oblist[0]);
            this_player()->set_pronoun( oblist[0] );
            this_player()->say_local( "~CACT~Name ~verbexamine ~targ intently.~CDEF" );
            this_player()->set_doing( "examining ~targ", oblist[0] );
         }
      }
      else
      if( buf = env->extra_id(what) ) {
         msg( eval_exp(buf, env) + "\n" );
         this_player()->set_pronoun( 0 );
      }
      else
         msg("Sorry, I don't know what you mean by '"+what+"'.");
   }
   return 1;
}
