#include <guilds.h>
#include <spells.h>
inherit "/std/guilds/sacerdote";

void setup()
{
  set_name("nigromante");
  set_short("Clerigo nigromante");
  set_long("Los clerigos nigromantes son especialistas en hacer danyo y el "
    "mal, enfrentarse a uno de ellos es como enfrentarse a la muerte, ya que "
    "sus hechizos se especializan en la misma. "
    "Los Clerigos nigromantes pueden llevar todo tipo de armaduras "
    "y empunyar cualquier arma.\n");
  set_needed_align("evil");
  reset_get();
  add_guild_command("juzgar", 1);
  add_guild_command("reparar", 1);
  add_guild_command("repeler",1);
}

int query_extra_con_bonus()
{
  return 1;
}

int query_legal_race(string race)
{
  if (DEBUG(TP)) return 1;
  switch (race)
  {
    case "Elfo": 
      return 0;
  }
  return 1;
}

int query_legal_weapon(string type) 
{ 
  return 1;
}

mixed query_legal_spheres()
{
  return 
  ({
    ({"combate",	"mayor"}),
    ({"danyadora",	"mayor"}),
    ({"necromantica",	"mayor"}),
    ({"caos",	        "mayor"}),
    ({"hechizo",        "mayor"}),
    ({"elemental",      "mayor"}),
    ({"proteccion",	"neutral"}),
    ({"llamada",	"neutral"}),
    ({"animal",		"neutral"}),
    ({"clima",		"neutral"}),
    ({"curadora",	"menor"}),
    ({"adivinacion",	"menor"}),
    ({"total",		"menor"}),
    ({"sol",		"menor"}),

  });
}

int query_thac0_step()
{
  return ::query_thac0_step()+1;
}