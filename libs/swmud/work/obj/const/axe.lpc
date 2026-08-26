#include <move.h>

int construct_object(object body)
{
   int damage = 0;
   int durability = 0;
   int mass = 0;
   int value = 0;
   int cortosis_weave = 0;
   string blade_desc = "unknown";
   string hilt_desc = "unknown";
   object blade = filter_array(all_inventory(body), (: $1->id("blade_axe") :))[0];
   object hilt = filter_array(all_inventory(body), (: $1->id("handle_axe") :))[0];
   object product = clone_object("/d/weap/axe");

   if (!blade || !hilt || !product)
   {
      write("Unable to construct axe, please tell a wizard.\n");
      return 0;
   }

   mass += blade->query_mass() + hilt->query_mass();
   value += blade->query_value() + hilt->query_value();

   switch (base_name(blade))
   {
      case "/d/const/prod/bronze_blade_axe": damage += 7; durability += 2; blade_desc = "bronze"; break;
      case "/d/const/prod/steel_blade_axe": damage += 10; durability += 4; blade_desc = "steel"; break;
      case "/d/const/prod/cortosis_blade_axe": damage += 10; durability += 5; cortosis_weave = 1; blade_desc = "steel cortosis-weave"; break;
      default: damage = 1; break;
   }

   switch (base_name(hilt))
   {
      case "/d/const/prod/wooden_axe_handle": durability += 2; hilt_desc = "wooden"; break;
      case "/d/const/prod/bronze_axe_handle": durability += 4; hilt_desc = "bronze"; break;
      case "/d/const/prod/steel_axe_handle": durability += 5; hilt_desc = "steel"; break;
      default: durability = 1; break;
   }

   product->set_long("A large, heavy axe.  It has " + add_article(blade_desc) + " blade and " + add_article(hilt_desc) + " handle.");
   product->set_damage_type("slashing", damage);
   product->set_damage_type("striking", damage);
   product->set_durability(durability);
   product->set_max_durability(durability);
   product->set_mass(mass);
   product->set_value(value);
   product->set_cortosis_weave(cortosis_weave);
   product->set_customize_record("constructed", body->query_userid());
   product->set_autoload();

   if (product->move(body) == MOVE_NO_ROOM)
   {
      product->move(environment(body));
   }

   body->simple_action("$N carefully $vconstruct " + add_article(blade_desc) + " axe with " + add_article(hilt_desc) + " handle.");

   return 1;
}