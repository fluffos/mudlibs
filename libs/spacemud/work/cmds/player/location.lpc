/*
** location.c -- where am I?
**
** Tsath, 2020
*/

//: PLAYERCOMMAND
//$$ see: skills, hp, stats, score, equip
// USAGE location
//
// Shows where you are in space using your pager systems.

#include <config.h>

inherit CMD;
inherit SPACE_CLASSES;
inherit M_FRAME;

private
string coord_str(int *coords)
{
   return "<228>[" + to_int(coords[0]) + "," + to_int(coords[1]) + "," + to_int(coords[2]) + "]<res>";
}

private
void main(string arg)
{
   string content = "";
   int pcount = 0;
   object body = this_body();
   int planet_location = body->query_planet();
   mixed vdu = filter(all_inventory(body), ( : $1->is_vdu() && $1->ob_state() :));
   class starsystem ss;
   class planet *planets;
   class structure *structures;
   class structure st = 0;

   if (!sizeof(vdu))
   {
      write("You need to wear a VDU to see your location.");
      return;
   }
   else
      vdu = vdu[0];

   frame_init_user();
   set_frame_title("VDU:: Location information");
   set_frame_left_header();
   set_frame_header("Location\n\n\n\nStar\n\n\nPlanets");

   if (strlen(arg) > 0 && wizardp(this_user()))
   {
      body = find_body(arg);
      if (!body)
      {
         out("Cannot find '" + arg + "'.\n");
         return;
      }
      write("Location for " + capitalize(arg) + ":\n");
   }
   ss = SPACE_D->query_starsystem(body->query_starsystem());
   planets = SPACE_D->query_planets(ss->name);
   structures = SPACE_D->query_structures(body->query_starsystem(), planet_location);
   if (sizeof(structures))
      st = filter(structures, ( : ((class structure)$1)->name == $(body)->query_location() :))[0];

   content = sprintf("<bld>      Star System<res>: %-17.17s\n" + "         <bld>Location<res>: %s\n" +
                         "<bld>Omega Coordinates<res>: %-17.17s       <bld>Distance to Omega<res>: %-17.17s\n\n",
                     body->query_starsystem(),
                     body->query_location() + (st && st->distance ? (" ~" + st->distance + " km from ") : " near ") +
                         (sizeof(planets) > planet_location ? planets[planet_location]->name : ""),
                     coord_str(body->query_coordinates()),
                     body->query_starsystem() == "Omega"
                         ? "-"
                         : pround(SPACE_D->distance("Omega", body->query_starsystem()), 2) + " LY");

   content +=
       sprintf("<118>%-25.25s<res>\n<bld>Spectral Type<res>: %-17.17s <bld>Kelvin<res>: %s <res>\n\n", ss->star->name,
               ss->star->spectral_type, ss->star->col + ss->star->temperature_min + "-" + ss->star->temperature_max);

   content += accent(sprintf("%-25.25s    %-17.17s   %-17.17s   %-17.17s\n", "Planet Name", "Planet Type", "# of Moons",
                             "Gravity force"));
   foreach (class planet p in planets)
   {
      content += sprintf("%s%-25.25s<res>    %-17.17s   %-17.17s   %8.8s\n", p->col, (p->player_name || p->name),
                         p->type, "" + (p->moons || "None"), pround(p->gravity, 1) + " Gs");
      pcount++;
   }

   set_frame_content(content);

   write(frame_render());
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}