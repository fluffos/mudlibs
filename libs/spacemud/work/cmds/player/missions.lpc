/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** missions.c
**
** Show you all the missionss on the mud.
** 2024, Tsath
**
*/

//: PLAYERCOMMAND
//$$see: quests
// USAGE
//    ``missions``
//
// Shows you all the missions and mission variants for the area you are in.
//
// .. TAGS: RST

inherit CMD;
inherit M_FRAME;
inherit CLASS_MISSION_INFO;

nomask private void main()
{
   string c = "";
   string domain = explode(base_name(environment(this_body())), "/")[1];
   class mission_info *missions = MISSION_D->live_missions(domain);
   int mission_count = sizeof(clean_array(flatten_array(map(missions, ( : $1.name:)))));
   int variant_count = sizeof(flatten_array(map(missions, ( : $1.variants:))));
   int mission_max = sizeof(missions) ? 2 + max(map(missions, ( : strlen($1.name) :))) : 0;
   int variant_max;
   if (mission_max)
      variant_max = 2 + max(map(flatten_array(map(missions, ( : $1.variants:))), ( : strlen($1) :)));

   frame_init_user();
   set_frame_title("Missions");
   set_frame_header(
       sprintf("%-" + mission_max + "." + mission_max + "-s %-" + variant_max + "." + variant_max + "-s %-7.7s %s\n",
               "Missions", "Variant", "Levels", "Who/Where"));
   set_frame_footer(
       sprintf("In the " + accent("%s") + " area there %s %d mission%s with a total of %d variant%s available.",
               capitalize(domain), mission_count == 1 ? "is only" : "are", mission_count, mission_count == 1 ? "" : "s",
               variant_count, variant_count == 1 ? "" : "s", ));

   foreach (class mission_info mi in missions)
   {
      foreach (string v in mi.variants)
         c += sprintf(" % -" + mission_max + "." + mission_max + " - s % -" + variant_max + "." + variant_max +
                          "-s %-7.7s %s in %s\n",
                      capitalize(mi.name), v, mi.rec_level_min + "-" + mi.rec_level_max, mi.giver_name, mi.location);
   }

   set_frame_content(c);
   outf(frame_render());
}
