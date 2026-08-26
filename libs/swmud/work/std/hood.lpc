#include <flags.h>

void do_raise(string word)
{
   object this_ob = this_object();

   if (word == "hood")
   {
      if (member_array("head", this_ob->query_slots()) > -1)
      {
         write("The hood has already been raised.\n");
         return;
      }

      if (this_ob->test_flag(F_WORN))
      {
         object wearer = environment();

         if (wearer->query_armor_slot("head") != wearer)
         {
            write("Your head is already covered.\n");
            return;
         }

         wearer->remove_item(this_ob);
         this_ob->add_slot("head");
         wearer->wear_item(this_ob);

         wearer->simple_action("$N $vraise the hood on $p $o.", this_ob);
      }
      else
      {
         this_ob->add_slot("head");

         previous_object(1)->simple_action("$N $vraise the hood on $o.", this_ob);
      }
   }
   else
   {
      write("It doesn't have a \"" + word + "\".\n");
   }
}

void do_lower(string word)
{
   object this_ob = this_object();

   if (word == "hood")
   {
      if (member_array("head", this_ob->query_slots()) == -1)
      {
         write("The hood has already been lowered.\n");
         return;
      }

      if (this_ob->test_flag(F_WORN))
      {
         object wearer = environment();

         wearer->remove_item(this_ob);
         this_ob->remove_slot("head");
         wearer->wear_item(this_ob);

         wearer->simple_action("$N $vlower the hood on $p $o.", this_ob);
      }
      else
      {
         this_ob->remove_slot("head");

         previous_object(1)->simple_action("$N $vlower the hood on $o.", this_ob);
      }
   }
   else
   {
      write("It doesn't have a \"" + word + "\".\n");
   }
}

int indirect_raise_wrd_on_obj() { return 1; }
int indirect_lower_wrd_on_obj() { return 1; }