/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_DAMAGE_SOURCE;
inherit M_WIELDABLE;
inherit M_GETTABLE;
inherit M_MESSAGES;
inherit M_SALVAGEABLE;

inherit M_DURABILITY;

#define WEAPON_LVL_PRICE 25

void mudlib_setup()
{
   ::mudlib_setup();
   add_id("weapon");
   set_combat_messages("combat-bludgeon");
   set_skill_used("combat/melee/club");
   set_salvageable((["wood":40, "textile":10, "metal":50]));
   add_save(({"persist_flags"}));
}

int query_value()
{
   int value = ::query_value();
   int level = query_weapon_class() + (query_raw_hit_bonus() * 2) + query_raw_disarm_bonus() + query_raw_anti_disarm() +
               (query_must_dual_wield() ? -1 : 0) + (query_raw_damage_bonus() * 3);
   if (!value)
      value = WEAPON_LVL_PRICE * level - random(WEAPON_LVL_PRICE);
   set_value(value);
   return value;
}

nomask void set_proper_name(string str)
{
   error("Do not use set_proper_name() with weapons.");
}

mixed ob_state()
{
   return object::ob_state() + "/" + !!m_wieldable::ob_state();
}

void remove()
{
   object::remove();
   m_wieldable::remove();
}

int indirect_kill_liv_with_obj()
{
   return 1;
}
