// SilberLand MUDlib
//
// sys/skills.h -- old skills header
//
// $Date: 1997/03/31 13:40:04 $
/* $Revision: 1.1 $
 * $Log: skills.h,v $
 * Revision 1.1  1997/03/31 13:40:04  Woody
 * prepared for revision control
 *
 */

#define LOG_ADD     "SKILLS_ADD"
#define LOG_REMOVE  LOG_ADD
#define LOG_GAIN    "SKILLS_GAIN"
#define LOG_ILLEGAL "SKILLS_ILLEGAL"

#define SK_SWORDFIGHTING   "Schwertkampf"
#define SK_TWOHANDED       "Kampf mit Zweihändern"
#define SK_WEAPONLESS      "Waffenloser Kampf"
#define SK_CASTING         "Zauberfertigkeit"
#define SK_LOCKPICK        "Schlösser knacken"
#define SK_STEAL           "Stehlen"

#define STDSKILLS ({SK_SWORDFIGHTING, SK_TWOHANDED, SK_WEAPONLESS,\
                    SK_CASTING, SK_LOCKPICK, SK_STEAL})

#define ADD "Add"
#define RMV "Remove"
#define SET "Set"

#define FAIL_NOT_ALLOWED ([ ADD : "** Fehler - AddSkill: keine Berechtigung **",\
                            RMV : "** Fehler - RemoveSkill: keine Berechtigung **",\
                            SET : "** Fehler - SetSkill: keine Berechtigung **"])
#define FAIL_ADD_NO_LIVING    "** Fehler - AddSkill: Ziel nicht lebend **"
#define FAIL_SET_NOT_IN       "** Fehler - SetSkill: Skill nicht vorhanden **"
#define FAIL_SET_OUT_OF_RANGE "** Fehler - SetSkill: Wert überschreitet Grenzen **"
#define WARN_ADD_NO_STANDARD  "** Warnung - AddSkill: kein Standard-Skill **"
#define WARN_ADD_ALREADY_IN   "** Warnung - AddSkill: Skill bereits vorhanden **"
#define WARN_RMV_NO_STANDARD  "** Warnung - RemoveSkill: kein Standard-Skill **"
#define WARN_RMV_NOT_IN       "** Warnung - RemoveSkill: Skill nicht vorhanden **"
#define WARN_SET_NO_STANDARD  "** Warnung - SetSkill: kein Standard-Skill **"

