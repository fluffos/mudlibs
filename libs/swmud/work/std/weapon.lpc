inherit OBJ;
inherit M_DAMAGE_SOURCE;
inherit M_DURABILITY;
inherit M_WIELDABLE;
inherit M_VALUABLE;
inherit M_GETTABLE;
inherit M_MESSAGES;

int cortosis_weave = 0;

void mudlib_setup()
{
   object::mudlib_setup();
   m_damage_source::mudlib_setup();
   m_durability::mudlib_setup();
   m_valuable::mudlib_setup();
   m_wieldable::mudlib_setup();
   add_id("weapon");
   add_save( ({ "cortosis_weave" }) );
}

mixed ob_state()
{
   return object::ob_state() + "/" + !!m_wieldable::ob_state();
}

void remove()
{
   object::remove();
   m_wieldable::unwield();
}

void set_cortosis_weave(int value)
{
   cortosis_weave = value;
}

int has_cortosis_weave()
{
   if (cortosis_weave == 2)
   {
      return random(2);
   }

   return cortosis_weave;
}

mixed direct_holster_obj_in_obj() { return 1; }
mixed direct_unholster_obj_from_obj() { return 1; }
int indirect_kill_liv_with_obj() { return 1; }