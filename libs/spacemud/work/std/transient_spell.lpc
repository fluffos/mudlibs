/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 *  Transient spell effects. Small extension to transient effects to allow
 * for spell effects.
 */

inherit TRANSIENT;

private
int strength;
private
string action;
private
object caster;
private
string limb;

//: FUNCTION query_caster
// Returns the caster of the spell.
object query_caster()
{
   return caster;
}

//: FUNCTION query_limb
// Returns the limb the spell is affecting.
string query_limb()
{
   return limb;
}

//: FUNCTION query_target
// Returns the target of the spell.
object query_target()
{
   return environment();
}

void extend_effect(object t)
{
   // If the effect is extended, we need to update the caster to the current body.
   caster = this_body();
   ::extend_effect(t);
}
//: FUNCTION query_boost_strength
// Returns the boost strength of the shield.
int query_boost_strength()
{
   return strength;
}

void mudlib_setup(int strength_par, int duration_par, string action_par, string limb_par)
{
   transient::mudlib_setup();
   strength = strength_par;
   action = action_par;
   caster = this_body();
   limb = limb_par;
   this_object()->setup();
}
