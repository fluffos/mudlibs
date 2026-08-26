#include <medpac.h>
#include <move.h>

void manufacture_object(object body)
{
   int rank = body->query_skill("pharmacology") / 100;
   int spec = body->query_guild_specialization_rank("physician", "pharmacology");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int bacta_limit = 10 + (rank_spec * 2);
   int bacta_count = check_total_bacta();
   int heal_capacity = 0;
   int heal_rate = 0;

   if (check_medpacs_for_bacta(1) < 1)
   {
      write("You have no bacta that you can use to manufacture a patch.\n");
      return;
   }

   if (bacta_count > bacta_limit)
   {
      bacta_count = bacta_limit;
   }

   heal_capacity = bacta_count * ((10 + (rank_spec * 9)) * (body->query_guild_level("physician") + body->query_int()) / 150);

   heal_rate = heal_capacity / bacta_count;

   if (!body->test_skill("pharmacology", (body->query_guild_level("physician") * 8)))
   {
      string waste = "";

      if ((300 - (body->query_int() * 3)) > body->query_skill("pharmacology"))
      {
         remove_bacta_from_medpacs(bacta_count);

         waste = ", and $vwaste " + bacta_count + " vials of bacta";
      }

      body->my_action("$N $vfail to manufacture a bacta patch" + waste + ".");
      body->other_action("$N $vfail to manufacture a bacta patch.");

      return;
   }

   if (remove_bacta_from_medpacs(bacta_count) == bacta_count)
   {
      object product = clone_object("/d/obj/transdermal_patch", "bacta", heal_capacity, heal_rate);
      product->set_customize_record("manufactured", body->short());
      product->set_autoload();

      if (product->move(body) == MOVE_NO_ROOM)
      {
         product->move(environment(body));
      }

      body->my_action("$N $vmanufacture a bacta patch from " + bacta_count + " vials of bacta, at " + heal_rate + "% of standard potency.");
      body->other_action("$N $vmanufacture a bacta patch.");
   }
   else
   {
      write("For some reason, you now have less bacta than you started with.  Please tell a wizard that you were unable to manufacture a bacta patch.\n");
   }
}