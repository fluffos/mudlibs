/*
 * This file contains all the code for handling corpses.
 * @author Rhinehold
 */

/**
 * This method will allow all sorts of modifications to a corpse once it has
 * been created, based on the weapon or attack used for the killing stroke.
 * @param corpse the corpse object
 * @param weapon the weapon used to inflict the fatal damage
 * @param attack the attack used to inflict the fatal damage
 * @return none
 * @see death_helper()
 * @see make_corpse()
 * @see do_death()
 */
int alter_corpse( object corpse, object weapon, string attack ) {
  object head, *heads;
  string behead_message = "";

  if (!attack) attack = "attack";
  switch (attack) {
    case "behead" :
      heads =
   this_object()->query_race_ob( this_object() )->query_possible_bits( "head" );
      if( sizeof( heads ) > 1 ) {
        head = corpse->make_bit(heads[random(sizeof(heads))] );
      } else {
        head = corpse->make_bit( heads[0] );
        head->move( environment( corpse ) );

        switch(random(6)) {
          case 0 : behead_message = head->a_short() +
            " drops onto the ground and rolls head over, well, head "
            "for a bit before coming to a rest.\n";
             break;
          case 1 : behead_message = head->a_short() +
            " sails through the air in a graceful arc before landing "
            "with a very soggy *squish*.\n";
            break;
          case 2 : behead_message = head->a_short() +
            " quivers a bit as it remains in place, perched atop its owner's "
            "corpse for a moment, then falls to pieces.\n";
            break;
          case 3 : behead_message = head->a_short() +
            " tips off to the left to hang by a small bit of flesh, before "
            "gravity has something to say about the matter and pulls it "
            "completely off of the corpse, landing with a small bounce.\n";
            break;
          case 4 : behead_message = head->a_short() +
            " slides off of its owner's corpse, upends, and lands upside "
            "down, helping to keep some of the blood from spilling.\n";
            break;
          case 5 : behead_message = head->a_short() +
            " drops onto the ground like a ball, *bouncy* *bouncy*.\n";
            break;
          case 6 :
          case 7 :
          case 8 :
          case 9 :
          default : behead_message = "oops, the mushrooms have turned.\n";
        }
        tell_room( environment( corpse ), behead_message );
      }
      break;
    default :
  }
  return 1;
} /* alter_corpse */