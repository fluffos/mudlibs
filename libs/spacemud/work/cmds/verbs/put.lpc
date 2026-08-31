/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** put.c
**
*/

#include <move.h>

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``put <something> <preposition> <something>``
//  |  ``put <count> <money> in <something>``
//  |  ``put <count> <money> into <something>``
//
//  Put/insert/place/stuff/hide the blanket into the suitcase, put the dogfood in the cupboard,
//  put 10 gold into the sack.
//
// .. TAGS: RST

void do_put_obj_wrd_obj(object ob1, string p, object ob2)
{
   mixed tmp;
   string prep;
   if (ob2->is_living())
   {
      write("Try giving it.\n");
      return;
   }

   if (!try_to_acquire(ob1))
      return;

   prep = PREPOSITION_D->translate_preposition(p);
   tmp = ob1->move(ob2, prep);
   if (tmp == MOVE_OK)
   {
      write("Done.\n");
      this_body()->other_action("$N $vput a $o " + prep + " the $o1.", ob1, ob2);
      return;
   }
   if (!tmp)
      tmp = "That doesn't seem possible.\n";
   write(tmp);
}

void do_put_obs_wrd_obj(object *info, string p, object ob2)
{
   handle_obs(info, ( : do_put_obj_wrd_obj:), p, ob2);
}

void do_put_wrd_str_in_obj(string amount, string str, object ob)
{
   string s;
   int number;

   if (MONEY_D->is_currency(str))
   {
      sscanf(str, "%s %s", str, s);
      str = MONEY_D->singular_name(str);
      if (amount == "all")
         number = this_body()->query_amt_money(str);
      else
         number = to_int(amount);
      if (number < 0)
      {
         write("Nice try.\n");
         return;
      }
      if (this_body()->query_amt_money(str) < number)
      {
         write("You don't have " + MONEY_D->denomination_to_string(number, str) + ".\n");
         return;
      }
      else
      {
         if (ob->can_hold_money())
         {
            ob->add_money(str, number);
            this_body()->subtract_money(str, number);
            this_body()->other_action("$N $vput some money in $o.", ob->the_short());
            this_body()->my_action("$N $vput " + MONEY_D->denomination_to_string(number, str) + " in $o.",
                                   ob->the_short());
         }
         else
            write("You cannot put " + str + "s into " + ob->the_short() + ".\n");
      }
   }
   else
   {
      // See if this is a crafting component
      if (strlen(str) > 3 && CRAFTING_D->valid_material(amount + " " + str[0.. < 2]))
      {
         if (str[ < 1.. < 1] == "s")
            str = str[0.. < 2];
      }
      if (CRAFTING_D->valid_material(amount + " " + str))
      {
         str = amount + " " + str;
         amount = "1";
      }
      if (strlen(str) > 3 && CRAFTING_D->valid_material(str[0.. < 2]))
      {
         if (str[ < 1.. < 1] == "s")
            str = str[0.. < 2];
      }
      if (CRAFTING_D->valid_material(str))
      {
         TBUG("amount: " + amount + " str: " + str);
         number = to_int(amount);
         if (number < 0)
         {
            write("Nice try.\n");
            return;
         }

         if (ob->can_hold_materials())
         {
            ob->add_materials(str, number);
            this_body()->remove_material(str, number);
            this_body()->other_action("$N $vput some materials in $o.", ob->the_short());
            this_body()->my_action("$N $vput " + number + " " + str + " in $o.", ob->the_short());
         }
         else
            write("You cannot put " + str + "s into " + ob->the_short() + ".\n");
      }
      else
      {
         write("Sorry, put how many of what where?\n");
         return;
      }
   }
}

void do_put_wrd_str_into_obj(string amount, string str, object ob)
{
   return do_put_wrd_str_in_obj(amount, str, ob);
}

void create()
{
   add_rules(({"OBS WRD OBJ", "WRD STR in OBJ", "WRD STR into OBJ"}), ({"insert", "place", "stuff", "hide"}));
   // add_rules(({"OBS WRD OBJ",}), ({"insert", "place", "stuff", "hide"}));

   /*
    ** "hide OBS next to OBJ" -> "put OBS next to OBJ"
    ** "hide OBS beside OBJ" -> "put OBS beside OBJ"
    ** "hide OBS with OBJ" -> "put OBS with OBJ"
    */
}
