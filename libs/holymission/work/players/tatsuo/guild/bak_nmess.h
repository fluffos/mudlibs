
#include "/players/tatsuo/guild/ndef.h"

/* last edit: 21.03.94 whisky uni-linz.ac.at..for a faster code */

#ifndef _ninja_messages_
#define _ninja_messages_

/* --------------------------------------------------------------------- 
   The combat-messages of the ninjas                               
   to be included to ninjasoul                                          
   -> attacker (object), name of attacker (string), caused damage (int)         
  --------------------------------------------------------------------- */
CalcDam( att_obj, att_obj_name, tmp )
{
    string how, what;
   
   if ( objectp(att_obj) && 
        !((att_obj)->query_ghost()) && living( att_obj) )
   {
    switch(tmp)
	{
	 case 20..10000:
        what = "did an INSANE amount of damage to";
        how = "";
		break;
     case 17..19:
        how = " into a puddle of blood and body parts";
        what = "pound";
		break;
     case 14..16:
        how = " to small fragments";
        what = "massacred";
		break;
	 case 10..13:
        how = " with your bone crushing sound";
        what = "smash";
		break;
     case 8..9: 
        how = " very hard";
        what = "hit";
		break;
     case 6..7:
        how = " pretty hard";
        what = "hit";
		break;
     case 4..5:
        how = " hard";
        what = "hit";
		break;
     case 3:
        how = "";
        what = "hit";
		break;
     case 2:
        how = "";
        what = "grazed";
		break;
	 case 1:
        how = " in the stomach";
        what = "tickled";
		break;
     default:
		how =  " with the attack";
		what = "missed";
		break;
     }
	 tell_object(TP,"You " + what + " " + att_obj_name + how + ".\n");
	 tell_object(att_obj,TPN+ " " + what + " you "+ how +".\n");
	 say(TPN+" "+what+" " + att_obj->query_name() + how +".\n",att_obj);
     return( 1 );
   }
   tell_object( TP, "You killed " + att_obj_name + ".\n" );
   say( TPN +" killed "+ att_obj_name +".\n");
}


/* ---------------------------------------------------------------------- 
     The messages, when you hit the other player by throwing something 
     -> attacker (object), name of attacker (string), which item has thrown ,
     caused damage (int)                                               
   -------------------------------------------------------------------- */
CalcThrowDam( att_obj, att_obj_name, item, tmp )
{
   string nameOfItem;
   string how, what;
   
   if (objectp(item) && item->query_info() == "ninja_weapon" )
      if ( item->query_can_throw() )
           nameOfItem = item->query_cap_name();
         
   if ( !nameOfItem || !strlen( nameOfItem ) )
         nameOfItem = item->query_name();
      
   if ( objectp(att_obj) && 
        !((att_obj)->query_ghost()) && living( att_obj) )
   {
 
   switch(tmp)
   {
	  case 50..1000:
        how  = " - rending flesh and bone !!!\n";
        what = "";
		break;
	  case 40..49:
        how = " - rending flesh and bone !!!\n";
        what = "face of the ";
		break;
      case 30..39:
        how = " and leave a gaping wound !!!\n";
        what = "face of the ";
		break;
      case 20..29:
        how = " and rattle their pitiful skull.\n";
        what = "face of the ";
		break;
      case 15..19:
        how = " ,bouncing it off their skull.\n";
        what = "head of the ";
		break;
      case 10..14:
        how = " and make a very hard hit.\n";
        what = "head of the ";
		break;
      case 5..9:
        how = " and make a hard hit.\n";
        what = "torso of the ";
		break;
      case 2..4:
        how = " and make a hit.\n";
        what = "torso of the ";
		break;
      default:
        how = " and make a hit.\n";
        what = "stomach of the ";
		break;
     }
	 tell_object(TP,"You THROW a "+nameOfItem+" at the "+what+att_obj_name+how);
     tell_object( att_obj, TPN + " throws a " + nameOfItem + "at you" + how );
	 say(TPN+" throws a "+nameOfItem+ " at the " + what + att_obj_name + how);
     say( TPN + " " + what + " " + att_obj_name + how+".\n",att_obj);
     return( 1 );
   }
   tell_object( TP, "You killed " + att_obj_name + ".\n" );
   say( TPN+" killed "+ att_obj_name +".\n");
}

/* --------------------------------------------------------------------- 
   The messages, when you hit your opponent with the feet            
   -------------------------------------------------------------------- */
CalcKarateDam( att_obj, att_obj_name, tmp )
{
    string how, what, wfoot, tpos;

   if ( tmp == 0 ) 
   {
      tell_object(TP, "Your karate skills fail.\n");
      tell_object(att_obj, TPN + " tried to use karate on you.\n" );
      say(TPN+" failed to hit "+ att_obj_name +" with karate skills.\n", att_obj);
      return( 1 );
   }
    
   if ( objectp(att_obj) && 
        !((att_obj)->query_ghost())  && living( att_obj) )
   {

      TP->add_exp( tmp );
  
	  tpos = TP->query_possessive();

      switch ( tmp ) 
	  {
         case 1:
	 case 2:
         case 3: how = " FOOT to the shin !!!";
                 what = "annoy";
                 break;
         case 4:
         case 5:  how = " FOOT !!!";
                  what = "kick";
                  break;
         case 6:
         case 7:
         case 8:  how = " FOOT in the stomach !!!";
                  what = "kick";
                  break;
         case 9:  how = " ELBOW in the ribs !!!";
                  what = "hit";
                  break;
         case 10:
         case 11: how = " KNEE pretty hard in the stomach !!!";
                  what = "blast";
                  break;
         case 12: how = " KNEE to the solar plexus !!!";
                  what = "pound";
                  break;
         case 13:
         case 14: how = " FOOT blasted into the kidneys !!!";
                  what = "nail";
                  break;
         case 15:
          case 16: how = " SPINNING HOOK to the gut !!!";
                  what = "surprise";
                  break;
         case 17: how = " ELBOW smash right across the face !!!";
                  what = "daze";
                  break;
         case 18: how = "SPINNING HOOK to the face !!!";
                  what = "surprise";
                  break;
         case 19:
         case 20: how = " FOOT and score a bonecrushing blow to the head !!!";
                  what = "hit";
                  break;
         default: how = " FOOT to the throat !!!";
                  what = "massacre";
      }
      if ( random(2) )
         wfoot = "right";
      else
         wfoot = "left";
     
     tell_object(TP, "You " + what + " " + att_obj_name + 
                 " with your " + wfoot + how + "\n");
     tell_object(att_obj, TPN + " " + what + "s you with " + tpos+
                 " " + wfoot + how + "\n");
     say( TPN + " " + what + "s " + att_obj_name + " with " + tpos
          + " " + wfoot + how + "\n",att_obj );
     return( 1 );
   }
   tell_object( TP, "You killed " + att_obj_name + ".\n" );
   say( TPN+" killed "+ att_obj_name +".\n");
}


/* --------------------------------------------------------------------- 
    The messages, when you parries a hit  
    -> attacker (object), name of attacker (string), caused damage (int) 
  ---------------------------------------------------------------------- */
ParryMess( me, monst )
{
   string monstName, message, message1, wname, mposs;
   object monstWeap;

   monstName = monst->query_name();
   monstWeap = monst->query_wielded();
   mposs = monst->query_possessive();
   
   if ( monstWeap ) 
   {

    wname = monstWeap->query_name();

    message = monstName+" tries to hit you with "+mposs+ " "+wname+",\nbut ";
    message1 = monstName+" tries to hit  "+TPN+" with "+mposs+
			   " "+wname+",\nbut ";
   }
   else 
   {
      message = monstName + " tries to hit you with " + mposs +
                " physical force,\nbut ";
      message1 = monstName + " tries to hit " + TPN + " with " + 
                 mposs + " physical force,\nbut ";
   }
   
   switch( random(8) ) 
   {
      case 0: message += "you make a move to the left and PARRY the attack.\n";
              message1 += TPN + " makes a move to the left " +
                          "and PARRIES the attack.\n";
              break;
      case 1: message += "you make a move to the right and PARRY the attack.\n";
              message1 += TPN + " makes a move to the right " +
                          "and PARRIES the attack.\n";
              break;
      case 2: message += "you jump to the left and PARRY the attack.\n";
              message1 += TPN + " jumps to the left " +
                          "and PARRIES the attack.\n";
              break;
      case 3: message += "you jump to the right and PARRY the attack.\n";
              message1 += TPN + " jumps to the right " +
                          "and PARRIES the attack.\n";
              break;
      case 4: message += "you jump back and PARRY the attack.\n";
              message1 += TPN + " jumps back and PARRIES the attack.\n";
              break;
      case 5: message += "you dodge left and PARRY the attack.\n";
              message1 += TPN + " dodges left and PARRIES the attack.\n";
              break;
      case 6: message += "you dodge right and PARRY the attack.\n";
              message1 += TPN + " dodges right and PARRIES the attack.\n";
              break;
      case 7: message += "you dodge back and PARRY the attack.\n";
              message1 += TPN + " dodges back and PARRIES the attack.\n";
              break;
      default: message += "you duck the swing and PARRY the attack.\n";
               message1 += TPN + " ducks the swing and PARRIES the attack.\n";
			  break;
   }

   tell_object(me, message );
   tell_object(monst, TPN + " parries your attack.\n" );
   say( message1, me );
}


#endif /*_ninja_messages_*/
