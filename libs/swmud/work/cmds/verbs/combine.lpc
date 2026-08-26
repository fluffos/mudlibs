inherit VERB_OB;

void do_combine_obj_with_obj(object ob1, object ob2)
{
   if (ob1 == ob2)
   {
      write("It's not possible to combine something with itself.\n");
      return;
   }

   if ((ob1->query_herb_potency() || ob2->query_herb_potency())
      && (this_body()->query_race() != "ithorian"))
   {
      write("Only Ithorians know how to combine herbs.\n");
      return;
   }

   if ((ob1->query_herb_potency() && ob2->query_herb_potency())
      && (ob1->query_herb_type() == ob2->query_herb_type()))
   {
      int rank = this_body()->query_skill("horticulture") / 100;
      int max_potency = 20 + (rank * 8);
      string type = ob1->query_herb_type();
      int pot1 = ob1->query_herb_potency();
      int pot2 = ob2->query_herb_potency();
      int lowest = pot1;
      int highest = pot2;
      int new_potency;

      if (pot2 < lowest)
      {
         lowest = pot2;
      }

      if (pot1 > highest)
      {
         highest = pot1;
      }

      new_potency = highest + (((pot1 + pot2) / 2) * lowest / highest);

      if (new_potency > max_potency)
      {
         new_potency = max_potency;
      }

      if ((new_potency <= pot1) || (new_potency <= pot2))
      {
         write("You would be unable to achieve a greater potency by combining them.\n");
         return;
      }

      write("You combine two " + ob1->plural_short() + " to " + new_potency + "% potency.\n");
      this_body()->other_action("$N $vcombine " + ob1->a_short() + " with " + ob2->a_short() + ".");

      destruct(ob1);
      destruct(ob2);

      load_object("/d/obj/horticulture_herb");
      new("/d/obj/horticulture_herb", type, new_potency)->move(this_body());

      return;
   }

   write("It doesn't seem possible to combine " + ob1->a_short() + " with " + ob2->a_short() + ".\n");
}

void do_combine()
{
   write("Combine what with what?\n");
}

void create()
{
   add_rules( ({ "", "OBJ with OBJ" }) );
}