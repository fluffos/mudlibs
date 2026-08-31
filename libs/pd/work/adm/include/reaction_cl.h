#ifndef __REACTION_CL_H__
#define __REACTION_CL_H__

#define REACTION_SUCCEEDED 1 << 0
#define REACTION_FAILED    1 << 1
#define REACTION_CONTINUE  1 << 2
#define REACTION_PREVENT   1 << 3

#define REACTION_TYPE_ATTACK    1 << 0
#define REACTION_TYPE_DEFENSE   1 << 1
#define REACTION_TYPE_HEAL      1 << 2
#define REACTION_TYPE_GOOD      1 << 3
#define REACTION_TYPE_EVIL      1 << 4
#define REACTION_TYPE_MAGIC     1 << 5
#define REACTION_TYPE_FAITH     1 << 6
#define REACTION_TYPE_PHYSICAL  1 << 7
#define REACTION_TYPE_SONG      1 << 8
#define REACTION_TYPE_DANCE     1 << 9
#define REACTION_TYPE_BUFF      1 << 10
#define REACTION_TYPE_DEBUFF    1 << 11
#define REACTION_TYPE_CONJURING 1 << 12
#define REACTION_TYPE_ILLUSION  1 << 13
#define REACTION_TYPE_DECEPTION 1 << 14
#define REACTION_TYPE_ANY \
  REACTION_TYPE_ATTACK + REACTION_TYPE_DEFENSE + REACTION_TYPE_HEAL + \
  REACTION_TYPE_BUFF + REACTION_TYPE_DEBUFF + REACTION_TYPE_CONJURING + \
  REACTION_TYPE_ILLUSION + REACTION_TYPE_DECEPTION + REACTION_TYPE_GOOD + \
  REACTION_TYPE_EVIL + REACTION_TYPE_MAGIC + REACTION_TYPE_FAITH + \
  REACTION_TYPE_PHYSICAL + REACTION_TYPE_SONG + REACTION_TYPE_DANCE

class Reaction {
  string name;
  int time;
  function func;
  function postfunc;
  function failfunc;
  int type;
  int fail;
  int ignore;
  int continue_on_fail;
  int uses;
  string *verbs;
  string *fail_verbs;
  string *ignore_verbs;
  mapping current;
  mixed misc;
}

void init_reaction(class Reaction reac) {
  reac->type = REACTION_TYPE_ATTACK;
  reac->fail = 0;
  reac->ignore = 0;
  reac->continue_on_fail = 0;
  reac->verbs = ({});
  reac->fail_verbs = ({});
  reac->ignore_verbs = ({});
  reac->uses = 1;
  // these are meant to be changed by the reaction code each time
  reac->current = allocate_mapping(5);
  reac->current["target"] = 0;
  reac->current["subject"] = 0;
  reac->current["verb"] = 0;
  reac->current["type"] = 0;
  reac->current["fail"] = 0;
}

#endif

