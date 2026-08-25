/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** wieldable.c
**
** A funny name, but basically a modules that provides basic weapon
** functionality (wielding and the effects of being wielded).
**
** ??-Aug-94 Created.  By Beek.  Originally was /std/weapon.
** 12-Dec-94 Converted to modules approach.  Deathblade.
** 22-Oct-95 Beek separated out the combat stuff into M_DAMAGE_SOURCE, since
**           we don't want living objects to have the verb interaction
** 961216, Deathblade: added related skill for the weapon.
** ??-Apr-98 Iizuka updated to support the new adversary code. Limb
**           wielding is now available, and inventory description code has
**           been updated in respect to this.
*/

#include <flags.h>

void unwield_me();
void hook_state(string, mixed, int);
void assign_flag(int which, int state);
void clear_flag(int);

private
nosave object wielded_by;
private
nosave function move_hook = ( : unwield_me:);
private
string *wielding_limbs;
private
nosave string *properties;

string *query_properties()
{
   return properties;
}

void add_property(string prop)
{
   if (!properties)
      properties = ({});
   properties += ({capitalize(prop)});
}

void remove_property(string prop)
{
   if (properties)
      properties -= ({capitalize(prop)});
}

int valid_wield()
{
   // return 1 if they can wield this.
   return 1;
}

int valid_unwield()
{
   // return 1 if they can unwield this.
   return 1;
}

string query_wield_message()
{
   return "$N $vwield a $o.\n";
}

string query_unwield_message()
{
   return "$N $vunwield a $o.\n";
}

mixed query_wielding()
{
   return wielding_limbs;
}

object query_wielded_by()
{
   return wielded_by;
}

string wielded_attributes()
{
   return wielded_by ? wielded_by->get_wield_attributes() : "";
}

int query_dual_wielded()
{
   return sizeof(wielding_limbs) >= 2;
}

void mark_wielded_by(object which, string *limbs)
{
   wielded_by = which;
   assign_flag(F_WIELDED, which && which != this_object());
   wielding_limbs = limbs;
   if (!which)
      this_object()->unwielded();
   else
      this_object()->wielded();
   hook_state("move", move_hook, which && which != this_object());
   if (arrayp(limbs) && sizeof(limbs) >= 2)
   {
      this_object()->dual_wielded();
   }
}

mixed ob_state()
{
   return wielded_by ? wielded_attributes() : 0;
}

void unwield_me()
{
   if (wielded_by)
   {
      wielded_by->do_unwield(this_object());
      wielded_by = 0;
      clear_flag(F_WIELDED);
   }
}

void do_remove()
{
   unwield_me();
}

void remove()
{
   unwield_me();
}

mixed direct_wield_obj()
{
   object who = owner(this_object());

   if (who && who != this_body())
      return 0;

   if (wielded_by != 0)
      return "You're already wielding that!\n";

   return 1; /* Fall through */
}

mixed direct_dualwield_obj()
{
   return direct_wield_obj();
}

mixed direct_unwield_obj()
{
   object who = owner(this_object());

   if (who && who != this_body())
      return 0;

   if (wielded_by == 0)
      return "You're not wielding that!\n";

   return 1; /* Fall through */
}

mixed direct_wield_obj_in_str(object ob, string limb)
{
   object who = owner(this_object());
   string str;

   limb = replace_string(limb, "hand", "arm");

   if (who && who != this_body())
      return 0;

   if (!who)
      who = this_body();

   str = lower_case(limb);
   if (str == "both arms" || str == "both hands" || str == "both")
   {
      string *wield_limbs = who->query_wielding_limbs();
      int open_limbs = 0;
      foreach (string li in wield_limbs)
      {
         if (who->can_wield(li, ob))
            open_limbs++;
      }
      if ((ob->query_can_dual_wield() || ob->query_must_dual_wield()))
      {
         if (open_limbs >= 2)
         {
            if (ob->query_wielded_by() == who && ob->query_dual_wielded())
            {
               return "You are already dual wielding that!";
            }
            else
               return 1;
         }
         else
         {
            return "Dual wielding that requires two free limbs!";
         }
      }
   }
   if (member_array(limb, who->query_wielding_limbs()) == -1)
      return 0;

   if (!who->query_health(limb))
      return sprintf("Your %s is in no condition to wield that!\n", limb);

   return 1;
}

mixed direct_dualwield_obj_in_str(object ob, string limb)
{
   return direct_wield_obj_in_str(ob, limb);
}

mixed direct_wield_obj_with_str(object ob, string limb)
{
   return direct_wield_obj_in_str(ob, limb);
}

mixed direct_dualwield_obj_with_str(object ob, string limb)
{
   return direct_dualwield_obj_with_str(ob, limb);
}

mixed direct_remove_obj()
{
   object who = owner(this_object());

   if (!query_wielded_by())
      return "You are not wielding that.\n";

   if (who && who != this_body())
      return 0;

   return 1;
}

void internal_setup()
{
   this_object()->add_save(({"wielding_limbs"}));
}
