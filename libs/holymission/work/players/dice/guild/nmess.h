

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
        how = " with a bone crushing sound";
        what = "smashed";
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
        how  = " and smash the face in pieces !!!\n";
        what = "";
		break;
	  case 40..49:
        how = " and did an enormous amount of damage !!!\n";
        what = "eye of the ";
		break;
      case 30..39:
        how = " and tears off the right cheeks !!!\n";
        what = "face of the ";
		break;
      case 20..29:
        how = " and hit with a bone crushing sound.\n";
        what = "face of the ";
		break;
      case 15..19:
        how = " and it cuts deep into the flesh.\n";
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
      tell_object(TP, "You failed to karate your opponent.\n");
      tell_object(att_obj, TPN + " failed to hit you with the foot.\n" );
      say(TPN+" failed to hit "+ att_obj_name +" with the foot.\n", att_obj);
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
         case 3:
         case 4:
         case 5:  how = " FOOT !!!";
                  what = "kick";
                  break;
         case 6:
         case 7:
         case 8:  how = " FOOT in the stomach !!!";
                  what = "kick";
                  break;
         case 9:
         case 10:
         case 11: how = " FOOT pretty hard in the stomach !!!";
                  what = "kick";
                  break;
         case 12:
         case 13:
         case 14: how = " FOOT very hard at the torso !!!";
                  what = "kick";
                  break;
         case 15:
         case 16:
         case 17: how = " FOOT extremely hard at the torso !!!";
                  what = "kick";
                  break;
         case 18:
         case 19:
         case 20: how = " FOOT with a bonecrushing sound at the head !!!";
                  what = "hit";
                  break;
         default: how = " FOOT critically at the head !!!";
                  what = "hit";
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
