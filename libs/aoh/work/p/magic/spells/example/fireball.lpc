/*
   This is an example spell for the spellserver
*/

#include <magic.h>
#include <skills.h>

inherit SP_STD("spell");


// ------------------------------------------------------------
// REQUIRED functions
/* Will be called when a spell can be cast successfully  
   liv: The living which casts the spell
   arg: The arguments given to teh cast
   target: If possible the object array of the targets of the spell
*/
mixed OnSucceedCasting(object liv, string arg,object *target )
{
  printf("OnSucceedCasting liv=%O arg=%s target=%O\n",liv,arg,target);
  return 1;
}

/* Will be called when a spell fails 
   liv: The living which casts the spell
   arg: The arguments given to teh cast
   target: If possible the object array of the targets of the spell
   modus: BACKFIRE or FAIL
*/
mixed OnFailCasting(object liv,string arg,object *target,int modus)
{
  printf("OnFailCasting liv=%O arg=%s target=%O\n",liv,arg,target);
  return 1;
}

/* Return the strength level of this spell if you have a proficienty
   of value in that spell
   TODO: formula
*/
int QueryStrengthLevel(int value)
{
  return 10;
}

create()
{

  ::create();

  // Required
  SetSpellType(ST_FIRE);
  SetShort("fireball spell");
  SetLong(
  "This is a fireball spell. It will throw a huge ball of\n"
  "fire at your opponetn doing up to 200HP damage.\n");
  SetCastCost(20);              // in SP
  SetBackfireChance(500);       // 0..1000
  SetDifficulty(500);           // 0..1000
  SetSkill(SK_FIRE);            // On what type of skill depends the spell

  // Optional
  SetCastDelay(3); // Spell needs 3 sec to fire  
  SetDuration(4);  // When will the spell be over. CAN be set in the OnSucceed
                   // casting
}

// ------------------------------------------------------------
// OPTINONAL functions
/* Check whether the living is allowed to cast the spell. 
   Return a string which will be notify_failed to the player or
   0 for ok 
*/
string CannotCast(object liv,string arg,object *target)
{
  printf("CannotCast liv=%O arg=%s target=%O\n",liv,arg,target);
  return 0; // everybody can cast
}

/*
   Will be called if the spell is finished. Do all cleanup here 
   Mode=SP_SUCCESS or SP_FAILURE to indicate why cleanup is called
*/
int CleanUp(object liv,string arg,object *target,int mode)
{
  printf("CleanUp liv=%O arg=%s target=%O mode=%d\n",liv,arg,target,mode);
  return 1; // all done
}
/*
   Will be called when a spell is begun to be cast but before the
   Success checks. This function is optinonal and actually only
   needed in the case of delayed spells
   liv: The living which casts the spell
   arg: The arguments given to teh cast
   target: If possible the object array of the targets of the spell
*/
mixed OnCastMessage(object liv, string arg,object *target )
{
  printf("OnCastMessage liv=%O arg=%s target=%O\n",liv,arg,target);
  return 1;
}
