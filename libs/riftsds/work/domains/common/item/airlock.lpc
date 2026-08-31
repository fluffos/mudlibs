/* Do not remove the headers from this file! see /USAGE for more info. */

inherit PORTAL;
inherit SPACE_CLASSES;

void setup()
{
   set_flag(ATTACHED);
   set_long("The lighted airlock door leads into or out of the ship. It can only be used when docked.");
   add_adj("lighted");
   set_id("airlock", "ship_furniture");
   set_look_in_desc("The airlock seems empty.");
}

mixed direct_enter_obj()
{
   string docked_at = environment()->is_docked();
   object terminal = present("docking_terminal_id", environment());
   class docking_info di = terminal ? terminal->query_docking() : 0;

   if (di)
   {
      if (lower_case(this_body()->query_name()) != di->who)
         return "#Your VDU is rejected, and the airlock remains locked.";
      if (terminal->is_docking_completed())
         set_destination(di->vfile);
      else
         return "#No ship is currently docked.";
   }
   else
   {
      if (docked_at)
         set_destination(docked_at);
      else
         return "#The airlock is locked since the ship is not currently docked.";
   }
   return 1;
}

int do_not_restore()
{
   return 1;
}

string furniture_sound()
{
   return random(3) ? 0 : "a small hissing sound can be heard like something being kept under pressure";
}