// combat.h

#ifndef __COMBAT__
#define __COMBAT__

#define TYPE_REGULAR    0
#define TYPE_RIPOSTE    1
#define TYPE_QUICK        2

#define RESULT_DODGE    -1
#define RESULT_PARRY    -2

// This is used as skill_power()'s argument to indicate which type of skill
// usage will be used in calculating skill power.
#define SKILL_USAGE_ATTACK        1
#define SKILL_USAGE_DEFENSE        2


#endif

// 以下define 从/system/daemon/combatd.c转移过来的
#define TYPE_ATTACK             0
#define TYPE_DODGE              1
#define TYPE_PARRY              2

// 攻击的类型
#define AT_NORMAL       0
#define AT_FANJI        1
#define AT_FANGFAN      2
#define AT_QUICK        3
#define AT_PERFORM      AT_NORMAL

// 我们的决定
#define DECIDE_FANJI    0
#define DECIDE_DEFENSE  1
#define DECIDE_DODGE    2
#define DECIDE_PARRY    3


