/* Tamedhon MUDlib
 *
 * /secure/wizlevels.h -- wizlevel defines and macros
 *
 * $Date: 2009/08/02 07:00:00 $
 * $Revision: 1.3 $
 * $Log: wizlevels.h,v $
 * Revision 1.3  2009/08/02 07:00:00  Gralkor
 * Neuer Level Erzmagier im Ruhestand
 *
 * Revision 1.2  2001/01/13 12:48:38  Samtpfote
 * Eintragung neuer Levels, auch Mapping fuer Stufentitel
 *
 * Revision 1.1  2001/01/13 12:22:02  Samtpfote
 * Initial revision
 *
 * Revision 1.2  1997/03/15 23:59:22  Woody
 * _WIZLEVELS_ -> __WIZLEVELS_H__
 *
 * Revision 1.1  1997/03/15 23:58:59  Woody
 * prepared for revision control
 *
 */

#ifndef __WIZLEVELS_H__
#define __WIZLEVELS_H__

#include "/secure/config.h"

#define PLAYER_LVL                               0
#define SEER_LVL                                 1
#define ARCHSEER_LVL                             2
#define LEARNER_LVL                             10
#define WIZARD_LVL                              20
#define FULL_WIZARD_LVL                         21
#define DOMAINMEMBER_LVL                        25
#define QUESTWIZ_LVL                            30
#define SPECIAL_LVL                             35
#define LORD_LVL                                40
#define ELDER_LVL                               50
#define PENSION_ARCH_LVL                        55
#define ARCH_LVL                                60
#define ARCHON_LVL                              90
#define GOD_LVL                                 100


#define SEER_GRP                                 1
#define LEARNER_GRP                              2
#define WIZARD_GRP                               3
#define DOMAINMEMBER_GRP                         4
#define SPECIAL_GRP                              5
#define LORD_GRP                                 6
#define ELDER_GRP                                7
#define ARCH_GRP                                 8

/* user is an object which is to be checked */
/* for example, use IS_WIZARD(this_player()) to check */
/* if a player is a wizard. */
#define IS_PLAYER(user) (query_wiz_level(user) >= PLAYER_LVL)
#define IS_SEER(user) (query_wiz_level(user) >= SEER_LVL)
#define IS_ARCHSEER(user) (query_wiz_level(user) >= ARCHSEER_LVL)
#define IS_LEARNER(user) (query_wiz_level(user) >= LEARNER_LVL)
#define IS_WIZARD(user) (query_wiz_level(user) >= WIZARD_LVL)
#define IS_FULL_WIZARD(user) (query_wiz_level(user) >= FULL_WIZARD_LVL)
#define IS_DOMAINMEMBER(user) (query_wiz_level(user) >= DOMAINMEMBER_LVL)
#define IS_QUESTWIZ(user) (query_wiz_level(user) >= QUESTWIZ_LVL)
#define IS_SPECIAL(user) (query_wiz_level(user) >= SPECIAL_LVL)
#define IS_LORD(user) (query_wiz_level(user) >= LORD_LVL)
#define IS_ELDER(user) (query_wiz_level(user) >= ELDER_LVL)
#define IS_PENSION_ARCH(user) (query_wiz_level(user) >= PENSION_ARCH_LVL)
#define IS_ARCH(user) (query_wiz_level(user) >= ARCH_LVL)
#define IS_ARCHON(user) (query_wiz_level(user) >= ARCHON_LVL
#define IS_GOD(user) (query_wiz_level(user) >= GOD_LVL)

#define IS_LEARNING(user) (query_wiz_level(user) >= LEARNER_LVL &&\
                           user->QueryProp(P_WANTS_TO_LEARN))

#define SEER_SECURITY (secure_level() >= SEER_LVL)
#define ARCHSEER_SECURITY (secure_level() >= ARCHSEER_LVL)
#define LEARNER_SECURITY (secure_level() >= LEARNER_LVL)
#define WIZARD_SECURITY (secure_level() >= WIZARD_LVL)
#define DOMAINMEMBER_SECURITY (secure_level() >= DOMAINMEMBER_LVL)
#define SPECIAL_SECURITY (secure_level() >= SPECIAL_LVL)
#define LORD_SECURITY (secure_level() >= LORD_LVL)
#define ELDER_SECURITY (secure_level() >= ELDER_LVL)
#define ARCH_SECURITY (secure_level() >= ARCH_LVL)
#define ARCHON_SECURITY (secure_level() >= ARCHON_LVL)
#define GOD_SECURITY (secure_level() >= GOD_LVL)


/* title for wizard levels */
#define WIZ_MALE_TITLES \
      ([PLAYER_LVL:                             "Spieler",\
        SEER_LVL:                               "Seher",\
        ARCHSEER_LVL:                           "Erzseher",\
        LEARNER_LVL:                            "Magier im Ruhestand",\
        WIZARD_LVL:                             "Neumagier",\
        FULL_WIZARD_LVL:                        "Magier",\
        DOMAINMEMBER_LVL:                       "Regionsmitarbeiter",\
        QUESTWIZ_LVL:                           "Questmagier",\
        SPECIAL_LVL:                            "Magier f. besondere Aufgaben",\
        LORD_LVL:                               "Regionsmagier",\
        ELDER_LVL:                              "Weiser",\
        PENSION_ARCH_LVL:                       "Erzmagier im Ruhestand",\
        ARCH_LVL:                               "Erzmagier",\
        ARCHON_LVL:                             "Archon",\
        GOD_LVL:                                "Gott"\
  ])

#define WIZ_FEMALE_TITLES\
  ([    PLAYER_LVL:                             "Spielerin",\
        SEER_LVL:                               "Seherin",\
        ARCHSEER_LVL:                           "Erzseherin",\
        LEARNER_LVL:                            "Magierin im Ruhestand",\
        WIZARD_LVL:                             "Neumagierin",\
        FULL_WIZARD_LVL:                        "Magierin",\
        DOMAINMEMBER_LVL:                       "Regionsmitarbeiterin",\
        QUESTWIZ_LVL:                           "Questmagierin",\
        SPECIAL_LVL:                            "Magierin f. besondere Aufgaben",       \
        LORD_LVL:                               "Regionsmagierin",\
        ELDER_LVL:                              "Weise",\
        PENSION_ARCH_LVL:                       "Erzmagierin im Ruhestand",\
        ARCH_LVL:                               "Erzmagierin",\
        ARCHON_LVL:                             "Archonin",\
        GOD_LVL:                                "Goettin"\
  ])


#endif
