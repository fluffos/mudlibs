#ifndef __EFFECT_CL_H__
#define __EFFECT_CL_H__

class Effect {
  // name of this effect
  string name;
  // name of whoever created it in case the object goes away
  string castername;
  // object pointer to whoever created the effect
  object caster;
  // object pointer to the target of this effect
  object target;
  // description of this effect
  string desc;
  // func to be called each time this effect goes off (except the last time)
  function func;
  // func to be called the last time func happens
  function endfunc;
  // hide this effect from being detected??
  int hide;
  // how long between calls to func
  int interval;
  // tracks the current hit number, incremented by effect code
  int numhits;
  // maximum number of hits
  int maxhits;
  // this is used by the effect code itself, holds time() of last func call
  int lasthit;
  // time() at which to end this effect (alternative to using interval and numhits)
  int endtime;
  // messages to be shown each time func is called
  //   messages[0] is shown to the target
  //   messages[1] is shown to everyone else in the room
  string *messages;
  // like above, but shown when endfunc is called
  string *endmessages;
  // for storing whatever
  mixed misc;
  // room where this effect started, used to keep track of possible movement
  string startroom;
  // PK zone where this effect started, used for DoTs if they kill
  string startzone;
}

#endif

