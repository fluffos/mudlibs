#include <move.h>

int construct_object(object body)
{
   int damage = 0;
   int durability = 0;
   int mass = 0;
   int value = 0;
   int cortosis_weave = 0;
   string blade1_desc = "unknown";
   string blade2_desc = "unknown";
   string hilt_desc = "unknown";
   object blade1 = filter_array(all_inventory(body), (: $1->id("blade_long") :))[0];
   object blade2 = filter_array(all_inventory(body), (: $1->id("blade_long") :))[1];
   object hilt = filter_array(all_inventory(body), (: $1->id("hilt_double_sword") :))[0];
   object product = clone_object("/d/weap/sword_double");

   if (!blade1 || !blade2 || !hilt || !product)
   {
      write("Unable to construct double-sword, please tell a wizard.\n");
      return 0;
   }

   mass += blade1->query_mass() + blade2->query_mass() + hilt->query_mass();
   value += blade1->query_value() + blade2->query_value() + hilt->query_value();

   switch (base_name(blade1))
   {
      case "/d/const/prod/bronze_blade_long": damage += 6; durability += 1; blade1_desc = "bronze"; break;
      case "/d/const/prod/steel_blade_long": damage += 8; durability += 2; blade1_desc = "steel"; break;
      case "/d/const/prod/cortosis_blade_long": damage += 8; durability += 4; cortosis_weave += 1; blade1_desc = "steel cortosis-weave"; break;
      default: damage = 1; break;
   }

   switch (base_name(blade2))
   {
      case "/d/const/prod/bronze_blade_long": damage += 6; durability += 1; blade2_desc = "bronze"; break;
      case "/d/const/prod/steel_blade_long": damage += 8; durability += 2; blade2_desc = "steel"; break;
      case "/d/const/prod/cortosis_blade_long": damage += 8; durability += 4; cortosis_weave += 1; blade2_desc = "steel cortosis-weave"; break;
      default: damage = 1; break;
   }

   if (cortosis_weave == 2)
   {
      cortosis_weave = 1;
   }
   else if (cortosis_weave == 1)
   {
      cortosis_weave = 2;
   }

   switch (base_name(hilt))
   {
      case "/d/const/prod/wooden_sword_double_hilt": durability += 2; hilt_desc = "wooden"; break;
      case "/d/const/prod/bronze_sword_double_hilt": durability += 4; hilt_desc = "bronze"; break;
      case "/d/const/prod/steel_sword_double_hilt": durability += 8; hilt_desc = "steel"; break;
      default: durability = 1; break;
   }

   if (blade1_desc == blade2_desc)
   {
      product->set_long("The " + hilt_desc + " hilt of this weapon has two " + blade1_desc + " sword blades, close to a meter long, attached at both ends.  The entire length is just over 2 meters.");
   }
   else
   {
      product->set_long("The " + hilt_desc + " hilt of this weapon has " + add_article(blade1_desc) + " sword blade and " + add_article(blade2_desc) + " sword blade, close to a meter long, attached at both ends.  The entire length is just over 2 meters.");
   }

   product->set_damage_type("slashing", damage);
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

   if (blade1_desc == blade2_desc)
   {
      body->simple_action("$N carefully $vconstruct a double-sword with two " + blade1_desc + " blades and " + add_article(hilt_desc) + " hilt.");
   }
   else
   {
      body->simple_action("$N carefully $vconstruct a double-sword with " + add_article(blade1_desc) + " blade and " + add_article(blade2_desc) + " blade, and " + add_article(hilt_desc) + " hilt.");
   }

   return 1;
}