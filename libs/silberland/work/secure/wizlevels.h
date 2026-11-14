/* SilberLand MUDlib
 *
 * /secure/wizlevels.h -- wizlevel defines and macros
 *
 * $Date: 2001/03/01 19:09:09 $
 * $Revision: 1.5 $
 * $Log: wizlevels.h,v $
 * Revision 1.5  2001/03/01 19:09:09  Woody
 * FULLWIZ_LVL etc. definiert
 *
 * Revision 1.4  2000/10/03 08:48:29  Woody
 * neu: INACTIVEWIZ_LVL, IS_INACTIVEWIZ(), *_GRP aktualisiert
 *
 * Revision 1.3  1998/05/02 23:04:32  Woody
 * level_SECURITY #define's eingefuehrt
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

/*
 * wizlevels.h
 *
 * This file defines some useful macros to determine the level of
 * a wizard in terms of ability to do certain wizard things.
 * See also doc/concepts/levels. The grouping below is taken from there.
 *
 */

#include "/secure/config.h"

#define	SEER_LVL 1
#define	LEARNER_LVL 10
#define INACTIVEWIZ_LVL 15
#define	WIZARD_LVL 20
#define DOMAINMEMBER_LVL 25
#define QUESTWIZ_LVL 30
#define FULLWIZ_LVL 30
#define SPECIAL_LVL 35
#define	LORD_LVL 40
#define ELDER_LVL 50
#define	ARCH_LVL 60
#define GOD_LVL 100

#define SEER_GRP 1
#define LEARNER_GRP 2
#define INACTIVEWIZ_GRP 3
#define WIZARD_GRP 4
#define DOMAINMEMBER_GRP 5
#define QUESTWIZ_GRP 6
#define FULLWIZ_GRP 6
#define SPECIAL_GRP 7
#define LORD_GRP 8
#define ELDER_GRP 9
#define ARCH_GRP 10

/* user is an object which is to be checked */
/* for example, use IS_WIZARD(this_player()) to check */
/* if a player is a wizard. */
#define IS_SEER(user) (query_wiz_level(user) >= SEER_LVL)
#define IS_LEARNER(user) (query_wiz_level(user) >= LEARNER_LVL)
#define IS_INACTIVEWIZ(user) (query_wiz_level(user) >= INACTIVEWIZ_LVL)
#define IS_WIZARD(user) (query_wiz_level(user) >= WIZARD_LVL)
#define IS_DOMAINMEMBER(user) (query_wiz_level(user) >= DOMAINMEMBER_LVL)
#define IS_QUESTWIZ(user) (query_wiz_level(user) >= QUESTWIZ_LVL)
#define IS_FULLWIZ(user) (query_wiz_level(user) >= FULLWIZ_LVL)
#define IS_SPECIAL(user) (query_wiz_level(user) >= SPECIAL_LVL)
#define IS_LORD(user) (query_wiz_level(user) >= LORD_LVL)
#define IS_ELDER(user) (query_wiz_level(user) >= ELDER_LVL)
#define IS_ARCH(user) (query_wiz_level(user) >= ARCH_LVL)
#define IS_GOD(user) (query_wiz_level(user) >= GOD_LVL)

#define IS_LEARNING(user) (query_wiz_level(user) >= LEARNER_LVL &&\
                           user->QueryProp(P_WANTS_TO_LEARN))

#define SEER_SECURITY (secure_level() >= SEER_LVL)
#define LEARNER_SECURITY (secure_level() >= LEARNER_LVL)
#define WIZARD_SECURITY (secure_level() >= WIZARD_LVL)
#define DOMAINMEMBER_SECURITY (secure_level() >= DOMAINMEMBER_LVL)
#define QUESTWIZ_SECURITY (secure_level() >= QUESTWIZ_LVL)
#define FULLWIZ_SECURITY (secure_level() >= FULLWIZ_LVL)
#define SPECIAL_SECURITY (secure_level() >= SPECIAL_LVL)
#define LORD_SECURITY (secure_level() >= LORD_LVL)
#define ELDER_SECURITY (secure_level() >= ELDER_LVL)
#define ARCH_SECURITY (secure_level() >= ARCH_LVL)
#define GOD_SECURITY (secure_level() >= GOD_LVL)

#endif

