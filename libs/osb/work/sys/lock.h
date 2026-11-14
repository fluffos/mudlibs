#ifndef LOCK_H
#define LOCK_H 1

#ifndef P_KEYCODE

#define P_KEYCODE     "KeyCode"
#define P_KEYIDS      "KeyIds"
#define P_LOCKSTATE   "LockState"
#define P_PICK_CHANCE "PickChance"

#define P_NOLOCK   "NoLock"
#define P_NOUNLOCK "NoUnlock"

#endif

#define LOCK_OPEN   0
#define LOCK_CLOSED 1
#define LOCK_LOCKED 2

#define LOCK_OK       0
#define LOCK_NOCHANGE 1
#define LOCK_NOTLOCK  2
#define LOCK_KEYWRONG 3
#define LOCK_KEYDENY  4

#define LOCK_DO_OPEN   0
#define LOCK_DO_CLOSE  1
#define LOCK_DO_LOCK   2
#define LOCK_DO_UNLOCK 3

#define LOCK_ACT_ALREADY  0
#define LOCK_ACT_LOCK     1
#define LOCK_ACT_OPEN     2
#define LOCK_ACT_NOKEY    3
#define LOCK_ACT_WRONGKEY 4

#endif
