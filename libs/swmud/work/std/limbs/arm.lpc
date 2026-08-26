// Last edited by deforce on 07-02-2008
inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;

string the_name;
object link;

int is_living()
{
   return 0;
}

string in_room_desc()
{
   return query_in_room_desc();
}

mixed ob_state()
{
   return the_name;
}

object query_link()
{
   return link;
}

void mudlib_setup(string name, string long, object l)
{
   ::mudlib_setup();

   link = l;

   if (!name) { return; }

   the_name = name;
   set_long(long || "The lifeless body of " + capitalize(the_name) + " isn't particularly interesting.");

   set_id("corpse", "body");

   if (the_name[<1] == 's')
   {
      set_adj("lifeless", the_name);
      set_proper_name(capitalize(the_name) + "' body");
   }
   else
   {
      set_adj("lifeless", the_name + "s");
      set_proper_name(capitalize(the_name) + "'s body");
   }

   set_in_room_desc("Corpse of " + capitalize(the_name));
   set_plural_in_room_desc("Corpses of " + the_name + ".");
   add_relation("on");
   set_default_relation("on");
   set_max_capacity(300);
   set_mass(59000);
   set_num_decays(1);
   set_last_decay_action("The corpse of " + the_name + " $vdecay into dust and ash.\n");
   set_decay_time(120);
   set_decay_auto_remove(1);
}

string introduce_contents()
{
   return "On " + the_short() + " you see:\n";
}

mixed indirect_get_obj_from_obj(object ob1, object ob2)
{
   return 1;
}

int query_hide_contents()
{
   return 1;
}

void remove()
{
   foreach (object thing in all_inventory(this_object()))
   {
      thing->move(environment(this_object()));
   }

   destruct();
}