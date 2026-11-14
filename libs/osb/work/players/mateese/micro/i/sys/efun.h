#ifndef SYS_EFUN_H
#define SYS_EFUN_H 1

// Useful functions

#define moveto(dest)      move_object(this_object(), dest)
#define wizardp(ob)       (ob && set_is_wizard(ob,-1))

// Level stuff

#define wizlevel(ob)      ((int)SECUREINFO->Wizlevel(ob,0))  // Overall wizlevel
#define domainlevel(d,ob) ((int)SECUREINFO->Wizlevel(ob,d))  // Level within one domain

#define isPlayer(ob)  (wizlevel(ob) >= PLAYER_LVL)
#define isLearner(ob) (wizlevel(ob) >= LEARNER_LVL)
#define isWizard(ob)  (wizlevel(ob) >= WIZARD_LVL)
#define isArch(ob)    (wizlevel(ob) >= ARCH_LVL)
#define isAdmin(ob)   (wizlevel(ob) >= ADMIN_LVL)

#define isMemberOf(ob,d) (domainlevel(d,ob) >= MEMBER_LVL)
#define isLordOf(ob,d)   (domainlevel(d,ob) >= LORD_LVL)

// Flags for stime()

#define SD_WDAY 1
#define SD_DATE 2
#define SD_TIME 4
#define SD_SDATE 8
#define SD_FULL (SD_WDAY|SD_DATE|SD_TIME)

#endif
