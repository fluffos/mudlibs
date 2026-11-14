/*
** Spell-Definitions for the spellmonster
** Author: Thragor@Nightfall, 22may96
** Update:
*/

#ifndef _SPELLMONSTER_
#define _SPELLMONSTER_

#define S_CHECKFUN "CheckFunction" // may the spell be cast
#define S_CHANCE "Chance" // the chance that the monster casts this spell
                          // all chances will be summed up later on and
                          // then per random one spell wil be picked.
                          // So you might think of the chance as percentage
                          // but you don't need to.
#define S_COMBAT_DELAY "CombatDelay" // how long the monster will stop
                                     // the combat actions after it casted
                                     // the spell
#define S_SIMULT "Simultaneously" // 0 = monster does either physical attack
                                  //     or casts this spell
                                  // 1 = monster may do this together with
                                  //     with a physical attack
#define S_VICTIMS "Victims" // max. no. of victims (assuming that 30 is
                            // the same as all victims; this is not checked
                            // in the code, but I think you will never have
                            // more than 30 victims; to be sure, you may also
                            // set 100 victims)
                            // If the amount of victims is <0 then the whole
                            // room (i. e. all livings in it), will be affected
                            // by the spell (and not only the enemies of the
                            // monster.
#define S_DELAY "Delay" // How many combat-turns to wait before this spell
                        // may be cast again.
#define S_DAMTYPE "DamType" // The damage-type of the spell, if any.
#define S_MINDAM "MinDamage" // minimal damage done by the spell
#define S_MAXDAM "MaxDamage" // maximum damage done by the spell, if 0
                             // no damage will be done at all (i. e. even
                             // Defend will not be called).
#define S_FUN "Function" // Function which might modify the actual mapping,
                         // i. e., it gets the current settings and might
                         // return completely new ones.
                         // If the returned value is 0 the spell will be
                         // assumed as casted (nothing else will be done).
                         // A physical attack will be done then, too.
#define S_DAMFUN "DamFunction" // if defined, this closure will be called
                               // instead of evaluating the damage from
                               // S_MINDAM and S_MAXDAM
                               // Parameters are the victim and the spell map.
#define S_SP "Spellpoints" // How many spellpoints the monster has to
                           // afford to cast this spell.
#define S_HP "Hitpoints" // HOw many hitpoints the monster has to spent
                         // to cast the spell (blood-magic).
#define S_GLOBAL_ENVMSG "GlobalEnvMsg" // This message will be printed to all
                                       // livings in the room, before the damage
                                       // is dealt.
                                       // Format: <msg to all> or
                                       //     ({<msg to seeing>,<msg to blind>})
#define S_ENVMSG "EnvironmentMessage" // mapping what the environment will
                                      // see when the spell is casted,
                                      // where the environment are all players
                                      // which are not effected by the spell
#define S_VICMSG "VictimMessage" // mapping of the message all victims
                                 // will get
#define MSG_NORMAL "Normal" // Structure of S_ENVMSG and S_VICMSG:
#define MSG_DEAD "Dead"     //   ([MSG_NORMAL:<string|string*>,
                            // MSG_DEAD:<string|string*>])

#endif
