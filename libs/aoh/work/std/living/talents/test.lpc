/*--------------------------------------------------------------------------
 * The OSB Talents
 *
 * Copyright (C) 15jan1998 by Softbyte for OSB
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * [Softbyte 15jan1998]  V0.1 First test implkementation
 *--------------------------------------------------------------------------
 */
/**
  @author Softbyte
  @version V0.1
*/
/** @synopsis
       Equips livings with a set of talents
*/
/** @description
  Talents give a living a set of new functions or attributes. They are
  unlike skills not teachable or learnable. Usually they are given 
  at character generation for a given race or by joining a guild. Of
  course magic influence can also grant or enhance certain talents.

  Actually talents were thought as a have or not-have feature but the
  current implementation supports talents of various quality measured
  in 1/10 of percent (0..1000, 0: no talent, 1000: excellent talent).

  Technically talents are implemented as modules which are either
  located in /std/living/talents for the default game talents or at
  any arbitrary location, which then has to be provided at function
  call. These modules contain the code for the talent, i.e.
  initialisation, deinitialisation, actions, etc. These modules will
  then be "linked" into the living and be called at appropriate times.
*/

/** @example
  Examples for talents might be a better infravision or ultravision.
  These two talents are implemented. Use a 
  "xcall $->SetTalent("infravision",1000)" to enable the talent and a
  "xcall $->SetTalent("infravision",0)" to disable it.
*/

/** @bugs
  Due to the bug/feature that add_actions can only be performed by
  objects present it is not possible to enable an talent of a living
  which is not present. The talent is enabled at next login though.
*/

/** @todo
   - More talent function calls (e.g. combat)
   - More talents
   - Check concept
   - Vote talents
*/

/** @see
  skills(c), living(s), /std/living/talents/test.c
*/

/**
  @function
   Will be called if living (me) got destroyed or the talent got removed
   Disable your talent acting on the living in this function
  @param object me
   The living on whose talent is meant
  @param int value
   The value of the talent (0..1000, 1000:excellent)
  @param mixed extra 
   The extra argument is identically passed to all functions as it
   got passed to SetTalent..do with it whatever you need to do
*/
void RemoveTalent(object me,int value,mixed extra)
{
  printf("RemoveTalent value=%d extra=%O\n",value,extra);
  printf("TP=%O me=%O\n",this_player(),me);
}

/**
  @function
   Set this talent (this file) of the living (me)  to the value 'value'
   Make your talent act on the living in this function, e.g. change
   attributes
  @param object me
   The living on whose talent is meant
  @param int value
   The value of the talent (0..1000, 1000:excellent)
  @param mixed extra 
   The extra argument is identically passed to all functions as it
   got passed to SetTalent..do with it whatever you need to do
*/
void SetTalent(object me,int value,mixed extra)
{
  printf("SetTalent value=%d extra=%O\n",value,extra);
  printf("TP=%O me=%O\n",this_player(),me);
}

/**
  @function
   The living's (me)  init got called and this call is forwared
   to this function
   DO NOT add_actions here. Use QueryActions() instead !!!
  @param object me
   The living on whose talent is meant
  @param int value
   The value of the talent (0..1000, 1000:excellent)
  @param mixed extra 
   The extra argument is identically passed to all functions as it
   got passed to SetTalent..do with it whatever you need to do
*/
void InitTalent(object me,int value,mixed extra)
{
  printf("InitTalent value=%d extra=%O\n",value,extra);
  printf("TP=%O me=%O\n",this_player(),me);
}

/**
  @function
   Return a string array of all commands (add_actions) the talent
   supports. Each action will call a function named "cmd_XXXX" in
   this file, e.g. "cmd_test" for the action "test"
  @param object me
   The living on whose talent is meant
  @param int value
   The value of the talent (0..1000, 1000:excellent)
  @param mixed extra 
   The extra argument is identically passed to all functions as it
   got passed to SetTalent..do with it whatever you need to do
  @return
   An array of verbs which the talent supports. They are used as
   add_actions.
*/
string *QueryActions(object me,int value,mixed extra)
{
  printf("QueryActions\n");
  printf("TP=%O me=%O\n",this_player(),me);
  return ({"ttest","atest"});
}

/**
  @function
   This is an EXAMPLE function for a assumed action "ttest":
   This function is called when the player types "ttest" because
   "ttest" is returned in the QueryActions function.
  @param string str
   The argument given to the add_action, i.e. what the player typed
   after the command verb
  @param object me
   The living on whose talent is meant
  @param int value
   The value of the talent (0..1000, 1000:excellent)
  @param mixed extra 
   The extra argument is identically passed to all functions as it
   got passed to SetTalent..do with it whatever you need to do
   @return
   The return value is identically to add_action functions, i.e. 1=ok
*/
int cmd_ttest(string str,object me, int value,mixed extra)
{
  printf("cmd_ttest: str=%O\n",str);
  printf("extra=%O\n",extra);
  printf("TP=%O me=%O\n",this_player(),me);
  return 1;
}

// also a command, but it returns 0, and sets a notify_fail!
varargs int cmd_atest(string str)
{
  printf("cmd_atest: str=%O\n",str);
  notify_fail("This is a notify_fail test.\n");
  return 0;
}



