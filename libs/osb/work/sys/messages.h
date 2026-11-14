#ifndef MESSAGES_H
#define MESSAGES_H 1

#define MSG_DAMAGE "Damage"
#define MSG_ENEMY  "Enemy"
#define MSG_DIE    "Die"
#define MSG_HEAR   "Hear"
#define MSG_HIT    "Hit"
#define MSG_MISS   "Miss"
#define MSG_MOVE   "Move"
#define MSG_SEE    "See"
#define MSG_STUN   "Stun"

// --- MSG_MOVE ---

#define MOVE_ORIG   1
#define MOVE_DEST   2
#define MOVE_METHOD 3
#define MOVE_EXTRA  4

// --- MSG_SEE ---

#define SEE_CAN   1
#define SEE_CANT  2

// --- MSG_HEAR ---

#define HEAR_TYPE   1
#define HEAR_TEXT   2

#define HEAR_SAY      "say"
#define HEAR_TELL     "tell"
#define HEAR_SHOUT    "shout"
#define HEAR_PSHOUT   "pshout"
#define HEAR_WSHOUT   "wshout"
#define HEAR_HSHOUT   "hshout"
#define HEAR_WHISPER  "whisper"
#define HEAR_CONVERSE "converse"
#define HEAR_ECHOTO   "echoto"
#define HEAR_ECHO     "echo"
#define HEAR_PECHO    "pecho"
#define HEAR_WECHO    "wecho"
#define HEAR_ECHOALL  "echoall"

// --- MSG_MISS ---

#define MISS_VICTIM  1
#define MISS_WEAPON  2

// --- MSG_HIT ---

#define HIT_ATTACKER 1
#define HIT_VICTIM   2
#define HIT_WEAPON   3
#define HIT_SUCCESS  4
#define HIT_DAMAGE   5
#define HIT_RELDAM   6

// --- MSG_DIE ---

#define DIE_CORPSE 1

// --- MSG_DAMAGE ---

#define DAMAGE_CAUSE  1
#define DAMAGE_AMOUNT 2

// --- MSG_ENEMY

#define ENEMY_ENEMY   1
#define ENEMY_ACTION  2

// --- MSG_STUN ---

#define STUN_CAUSE  1
#define STUN_ROUNDS 2

#endif
