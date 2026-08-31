#define GM       "guild/master"
#include "/players/patience/guild/skill_id.h"

/* ------------------------------------------------------------------------ */
/*   advances a skill                                                       */
/*                                                                          */
/*   -> tp: advance at which player                                         */
/*      which: name of the skill (string)                                   */
/*      sub: how much should be advanced (normally 1) (int)                 */
/*      blockLevel: a blocking-factor (int), if -1: force advance           */
/*   <- -1 if error, new-value (>0) if ok                                   */ 
/* ------------------------------------------------------------------------ */
advance_skill( tp, which, sub, blockLevel )
{
// return -1;
// return -1;
   mixed  skill;
int actSkill, maxSkill, skillId, chance, gid;

   skill = tp->get_skill( which );
   if ( !skill || !sizeof( skill ) )
      return;
   actSkill = skill[0];
   maxSkill = skill[1]; 
   gid = skill[2];
 
   if ( gid != tp->query_guild() && gid != -1 )           /* wrong guild    */
      return( -1 );
   if ( blockLevel <= actSkill && blockLevel != -1 )      /* don't advance  */ 
      return( -1 );
   if ( actSkill >= maxSkill )                            /* overflow       */
      return( -1 );

   if ( blockLevel == -1 )                                /* chance to adv. */ 
      chance = 1000;
   else
      chance = (maxSkill*10) / actSkill;

   if ( chance > random(1000) )                           /* advance it     */
      return( GM->change_skill( tp, which, actSkill+sub, maxSkill, gid ) );
   
   return( -1 );
}

/* ---------------------------------------------------------------------- */
/*   advances the maximum-level of a ki                                   */
/* ---------------------------------------------------------------------- */
advance_skill_max( tp, which, new_max, forced )
{
   int maxSkill, actSkill;
   string skillName;

   switch( which ) {
      case THROW_SKILL:  actSkill = actThrowSkill;
                         maxSkill = maxThrowSkill;
                         skillName = "ninja_throw";
                         break;
      case KARATE_SKILL: actSkill = actKarateSkill;
                         maxSkill = maxKarateSkill;
                         skillName = "ninja_karate";
                         break;
      case PARRY_SKILL:  actSkill = actParrySkill;
                         maxSkill = maxParrySkill;
                         skillName = "ninja_parry";
                         break;
      case THC_SKILL:    actSkill = actTHCSkill;
                         maxSkill = maxTHCSkill;
                         skillName = "ninja_thc";
                         break;
      case ACC_SKILL:    actSkill = actAccSkill; 
                         maxSkill = maxAccSkill;
                         skillName = "ninja_accuracy";
                         break;
      case CAMOU_SKILL:  actSkill = actCamouSkill;
                         maxSkill = maxCamouSkill;
                         skillName = "camouflage";
                         break;
      case ASSASS_SKILL: actSkill = actAssassSkill;
                         maxSkill = maxAssassSkill;
                         skillName = "assassinate";
                         break;
      default:           return( 0 );
   }

   if ( (maxSkill < new_max && actSkill < new_max) || forced )
      GUILD_MASTER->change_skill( tp, skillName, 0, new_max,
                                GUILD_MASTER->query_number( "ninja" ) );
   else
      return( 0 );

   switch( which ) {
      case THROW_SKILL:  maxThrowSkill = new_max;
                         break;
      case KARATE_SKILL: maxKarateSkill = new_max;
                         break;
      case PARRY_SKILL:  maxParrySkill = new_max; 
                         break;
      case THC_SKILL:    maxTHCSkill = new_max;
                         break;
      case ACC_SKILL:    maxAccSkill = new_max;
                         break;
      case CAMOU_SKILL:  maxCamouSkill = new_max;
                         break;
      case ASSASS_SKILL: maxAssassSkill = new_max;
                         break;
      default:           return( 0 );
   }

   return( 1 );
}
