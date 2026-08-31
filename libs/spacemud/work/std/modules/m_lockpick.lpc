/*
** M_LOCKPICK: Module to inherit in things that can be used for picking locks.
**
** Tsath, 2020.
*/

private
nosave int lockpick_str = 10;
private
nosave int break_chance = 10;

//: FUNCTION set_lockpick_strength
// Set the direct skill bonus to lockpick.
void set_lockpick_strength(int lps)
{
   lockpick_str = lps;
}

//: FUNCTION query_lockpick_strength
// The lockpick adds a direct skill bonus to the lockpicking attempt,
// the chance is returned by this function.
int query_lockpick_strength()
{
   return lockpick_str;
}

//: FUNCTION set_break_chance
// Set the chance in percent to break when used.
void set_break_chance(int bc)
{
   break_chance = bc;
}

//: FUNCTION query_break_chance
// Chance in percent to break when used.
int query_break_chance()
{
   return break_chance;
}

mixed indirect_pick_obj_with_obj()
{
   return 1;
}