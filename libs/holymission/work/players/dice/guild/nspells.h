#ifndef __ninja_spells__
#define __ninja_spells__

#include "/players/patience/guild/ndef.h"

_vanish( arg )
{
   string fn;
   int vcost;

   if ( !TP->query_immortal() && (TP->query_sp() < (TP->query_maxsp()*6) / 10) 
        && !(TP->query_ghost()) ) {
      write( "You have too less spellpoints to vanish.\n" );
      return( 1 );
   }
   else if ( TP->query_ghost() && arg!="guild" && arg!="jingu")
    {
      write( "Sorry, but as ghost you are already vanished!\n" );
      return( 1 );
   }
   else if (environment(TP)->query_property("no_teleport")) {
      write( "You try to vanish but a strong force is holding you back !!!\n");
      return( 1 );
   }

   vcost = -1 * ((TP->query_maxsp() * 6) / 10);
   switch(arg)    /* whisky it's faster */
   {
     if (TP->query_sp() < vcost && !TP->query_immortal() && arg!="guild" && arg!="jingu")
     {
       write("You are too low on power.\n");
      return 1;
     }
     case "church": 
         TP->move_player( "X", "/room/church" );
         if ( !(TP->query_immortal()) )
            TP->restore_spell_points(vcost);
      return( 1 );
      case "guild": 
         TP->move_player( "X", "/players/dice/guild/room" );
         if ( !(TP->query_immortal()) )
            TP->restore_spell_points(vcost);
      return( 1 );
     case "tree":
        TP->move_player( "X","/players/patience/ezo/inAlmond1");
        if ( !(TP->query_immortal()) )
           TP->restore_spell_points(vcost);
        return 1;
      case "jingu": 
         TP->move_player( "X", "/players/patience/ezo/coast/jingu" );
         if ( !(TP->query_immortal()) )
             TP->restore_spell_points(vcost);
      return( 1 );
      case "temple": 
         TP->move_player( "X", "/players/patience/ezo/forest/forestTemple" );
         if ( !(TP->query_immortal()) )
             TP->restore_spell_points(vcost);
       return( 1 );
       default:
       return( 0 );
     }
   return( 1 );
}

_night_eyes( arg )
{
   int i;

   if ( set_light(0) < 1 ) {
      if ( !arg ) {
         if ( TP->query_sp() >= LOOK_COST ) {
            environment( TP )->long();
            for ( i = 0; i < sizeof( all_inventory(environment(TP)) ); i++ )
               if ( all_inventory(environment(TP))[i]->short() && 
                    all_inventory(environment(TP))[i] != TP )
                  write( all_inventory(environment(TP))[i]->short()+".\n" );
            TP->restore_spell_points( LOOK_COST*-1 );
         }
         else
            write( "You are too low on power. So you only see darkness.\n" );
      }
      else
         write( "It is too dark to see details with your nighteyes.\n" );
         
      return( 1 );
   }

   return( 0 );
}

_night_inv( arg )
{
   int i;
   
   if ( set_light(0) < 1 ) {
      if ( TP->query_sp() >= LOOK_COST ) {
         for ( i = 0; i < sizeof( all_inventory(TP) ); i++ )
            if ( all_inventory(TP)[i]->short() )
               write( all_inventory(TP)[i]->short()+".\n" );
         TP->restore_spell_points( LOOK_COST*-1 );
      }
      else
         write( "You are too low on power. So you only see darkness.\n" );
   
      return( 1 );
   }
   
   return( 0 );
}

_night_get( arg )
{
   object what, where;
   string swhat, swhere;
   int    i;

   if ( set_light(0) > 0 )
      return;
      
   if ( !arg ) {
      write( "Get what ?\n" );
      return( 1 );
   }
   
   if ( sscanf( arg, "%s from %s", swhat, swhere ) == 2 ) {
      where = present( swhere, environment( TP ) );
      if ( !where ) {
         write( "There is no " + swhere + " here.\n" );
         return( 1 );
      }
      else if ( living( where ) ) {
         write( "You cannot get things from livings !\n" );
         return( 1 );
      }
   }
   else {
      where = environment( TP );
      swhat = arg;
   }
   
   if ( swhat == "all" ) {                                                /* get all */
      get_all_dark( where );
   }
   else {                                                                 /* get item */
      what = present( swhat, where );
      if ( !what ) {
         write( "There is no " + swhat + " here.\n" );
      }
      else {
         if ( transfer( what, TP ) )
            write( "You can't take that !\n" );
         else
            write( "Ok.\n" );
      }
   }

   return( 1 );
}

get_all_dark(from)
{
   object ob, next_ob;
 
   ob = first_inventory(from);
   while(ob) {
      string item;
      next_ob = next_inventory(ob);
      item = ob->short();
      if (item && ob->get()) {
         if ( transfer( ob, TP ) )
            write( item + ": Too heavy.\n" );
         else {
            write(item + ": taken.\n");
        }
     }
      ob = next_ob;
   }
}

/* ----- check monster or camouflage ---------------------------------------------- */
_check( arg )
{
   object ob;
   int    levelCmp, hpCmp;
   string poss, pron;
    
   if ( arg == "camouflage" ) {
      write( check_camou() + "\n" );
      return( 1 );
   }
    
   if ( TP->query_sp() < CHECK_COST ) {
      write( "You are too low on spellpoints to concentrate on Ameratsu.\n" );
      return( 1 );
   }
   
   if ( !arg )
      ob = TP->query_attack();
   else
      ob = present( arg, environment( TP ) );
   
   if ( !ob ) {
      if ( !arg )
         write( "Check whom ?\n" );
      else
         write( "Do you see a " + arg + " here ?\n" );
      return( 1 );
   }
   
   if ( !living( ob ) ) {
      write( "It's dead, defenetly dead !\n" );
      return( 1 );
   }

   levelCmp = ((ob->query_level()-TP->query_level()) * 100) / TP->query_level();
   hpCmp = ob->query_hp() - TP->query_hp();
   
   write( "You close your eyes and concentrate on Ameratsu.\n" + 
          "Ameratsu gives you the following description:\n" );
   if ( levelCmp > 400 )
      write( "  Don't hesitate. RUN !!!\n" );
   else if ( levelCmp > 200 )
      write( "  This opponent will make schaschlick of you !!!\n" );
   else if ( levelCmp > 100 )
      write( "  This could get an extremly hard fight.\n" );
   else if ( levelCmp > 25 )
      write( "  It might get hard, but it is to manage.\n" );
   else if ( levelCmp > -25 )
      write( "  You have nearly the same power.\n" );
   else if ( levelCmp > -50 )
      write( "  Beatable, absolutely beatable.\n" );
   else if ( levelCmp > -75 )
      write( "  Why bother this weak creature.\n" );
   else {
      write( "  Why do you bother me with such weak creatures !!!\n" +
             "  Ameratsu growls at you.\n" );
      return( 1 );
   }
   
   poss = ob->query_possessive();
   pron = ob->query_pronoun();
   
   if ( hpCmp > 20 )
      write( "  " + capitalize( pron ) + " is in a better condition than you.\n" );
   else if ( hpCmp < 20 )
      write( "  " + capitalize( pron ) + " is in a worse condition than you.\n" );
   else
      write( "  " + capitalize( pron ) + " is in the same condition than you.\n" );

   if ( ob->query_ac() > 20 )
      write( "  " + capitalize( poss ) + " protection is invincible.\n" );
   else if ( ob->query_ac() > 15 )
      write( "  " + capitalize( poss ) + " protection is extremely good.\n" );
   else if ( ob->query_ac() > 10 )
      write( "  " + capitalize( poss ) + " protection is very good.\n" );
   else if ( ob->query_ac() > 5 )
      write( "  " + capitalize( poss ) + " protection is good.\n" );
   else if ( ob->query_ac() > 2 )
      write( "  " + capitalize( poss ) + " protection is bad.\n" );
   else
      write( "  " + capitalize( poss ) + " protection is very bad.\n" );
      
   if ( ob->query_wc() > 18 )
      write( "  " + capitalize( poss ) + " weapon is deadly.\n" );
   else if ( ob->query_wc() > 15 )
      write( "  " + capitalize( poss ) + " weapon is almost deadly.\n" );
   else if ( ob->query_wc() > 10 )
      write( "  " + capitalize( poss ) + " weapon is superb.\n" );
   else if ( ob->query_wc() > 5 )
      write( "  " + capitalize( poss ) + " weapon is good.\n" );
   else if ( ob->query_wc() > 15 )
      write( "  " + capitalize( poss ) + " weapon is bad.\n" );

   TP->restore_spell_points( -1 * CHECK_COST );

   return( 1 );
}

/* ----- warcry --------------------------------------------------------------------- */
_warcry( arg )
{
   object atWhom;


   if ( (TP->query_sp() < TP->query_maxsp() / 10) ||
        (TP->query_hp() < TP->query_maxhp() / 20) ||
        (query_attackCon() < MAX_ATTACK_CON / 4) )
  {
      write( "You are too exhausted to make a warcry.\n" );
      return( 1 );
   }
   
   if ( !arg )
      atWhom = TP->query_attack();
   else
      atWhom = present( arg, environment( TP ) );
      
   if ( !atWhom || !living( atWhom ) || !present( atWhom, environment( TP ) ) ) {
      write( "Warcry at whom ?\n" );
      return( 1 );
   }
  
   TP->restore_spell_points( -1 * (TP->query_maxsp() / 5) );
   TP->reduce_hit_point( (TP->query_maxhp() / 10) );
   restore_attackCon( -1 * (MAX_ATTACK_CON / 2) );

   if ( random( atWhom->query_chr() ) > random( (TP->query_chr()*3)/2 ) ) {
      tell_object( TP,
             "You make a terrible warcry but your opponent doesn't feel disturbed.\n" );
      say( TP->query_name() + " makes a terrible warcry !!!\n" );
      return( 1 );
   }
   
   tell_object( TP,
           "You make a terrible WARCRY and your opponent runs away in fear !!!\n" );
   tell_object( atWhom,
           TP->query_name() + " makes a terrible warcry and you run away in fear !!!\n" );
   say( TP->query_name() + " makes a terrible warcry and " +
        capitalize( atWhom->query_real_name() ) + " runs away in fear !!!\n", atWhom );
   
   atWhom->run_away();
   
   return( 1 );
}

/* ----- spy ------------------------------------------------------------------------ */
_spy( arg )
{
   object room, inv;
   string *dest_dir;
   int    i;
   
   if ( !arg ) {
      write( "In which direction do you want to spy ?\n" );
      return( 1 );
   }

   if ( TP->query_sp() < SPY_COST ) {
      write( "You're too low on power for spying.\n" );
      return( 1 );
   }
   
   room = environment( TP );
   if ( !room )
      return;
      
   i = 1;
/* fixed by James. backup copy was made 300693 */
   dest_dir = (string *) room->query_room("dest_dir");
   
   while ( i < sizeof( dest_dir ) ) {
      if ( arg == dest_dir[i] ) {
         if ( !(dest_dir[i-1]) ) {
            write( "Somehow you don't manage it to spy " + arg + ".\n" );
            return( 1 );
         }
            
         write( "You spy " + arg + " and see the following:\n\n" );
         dest_dir[i-1]->long();
         room = find_object( dest_dir[i-1] );
         if ( !room )
            return( 1 );
         inv = all_inventory( room ); 
         if ( inv )
            for ( i = 0; i < sizeof( inv ); i++ )
               if ( inv[i] && inv[i]->short() && strlen( inv[i]->short() ) ) 
                  write( inv[i]->short() + ".\n" );
   
         TP->restore_spell_points( -1 * SPY_COST );
         return( 1 );
      }
      i += 2;
   }

   write( "Somehow you don't manage it to spy " + arg + ".\n" );
   return( 1 );
}

#endif /*__ninja_spells */
