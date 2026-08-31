inherit MATERIAL;
inherit M_THROWABLE;
inherit M_DAMAGE_SOURCE;

//CRAFTING:baseball grenade

void setup()
{
  set_id("baseball grenade", "grenade", "baseball");
  set_long("Baseball grenades are hollowed out baseballs filled "
           "with oil and fertilizer, which act as an improvised explosive mix.\n"
           "Throw it or throw it at someone.");
  set_skill_used("combat/thrown/grenade");
  set_combat_messages("combat-firearm");
  set_damage_type("bludgeon");
  set_weapon_class(10);
  set_value(40);
  set_weight(1);
}

mapping query_recipe()
{
  return (["excess adhesive":2, "baseball":1, "raw fertilizer":2, "waste oil":1, "steel scrap":2]);
}

string query_station()
{
  return "chemistry";
}

int calc_damage(int targets)
{
  return 10+random(10) / targets;
}

void has_been_thrown(object target)
{
  if (target)
  {
    set_damage_type("force");
    do_thrown_vital_damage(target, (: calc_damage, 1 :));
    tell_from_inside(environment(),"The baseball grenade detonates near the target in a BANG!\n");
  }
  else
  {
    object targets = filter_array(all_inventory(environment()), (: $1->attackable() && !$1->is_body() :));
    foreach(object t in targets)
    {
      do_thrown_damage(t, (: calc_damage, sizeof(targets) :));
      tell_from_inside(environment(),"The baseball grenade detonates in the middle of the room with a BANG!\n");
    }
  }
    remove();  
}
