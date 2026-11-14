// SilberLand MUDlib
//
// sys/player/skills.h -- (old) skill handling
//
// $Date: 1997/03/31 15:17:59 $
/* $Revision: 1.1 $
 * $Log: skills.h,v $
 * Revision 1.1  1997/03/31 15:17:59  Woody
 * prepared for revision control
 *
 */
 
#ifndef __PLAYER_SKILLS_H__
#define __PLAYER_SKILLS_H__

// properties

#define P_SKILLS				"skills"

#endif // __PLAYER_SKILLS_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_SKILLS_H_PROTO__
#define __PLAYER_SKILLS_H_PROTO__
                                 
// prototypes

mixed GiveAbility(string verb, string skill, int promill);
mixed GetVerbAbilities(string verb);
int GetProbability(string verb, string skill);
mixed GetSkillAbilities(string verb, string skill);
void AddSkillAction();

#endif // __PLAYER_SKILLS_H_PROTO__
#endif // NEED_PROTOYPES
