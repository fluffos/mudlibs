/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``introduce``
//  |  ``introduce yourself``
//  |  ``introduce myself``
//  |  ``introduce yourself to <someone>``
//  |  ``introduce myself to <someone>``
//  |  ``introduce to <someone>``
//
// Introduce yourself to someone or everyone in the room. 
//
// .. TAGS: RST

void do_introduce()
{
   write("Introduce who?");
}

void do_introduce_wrd_to_obj(string word, object ob)
{
   if (word != "yourself" && word != "myself")
   {
      write("You can only introduce yourself.");
      return;
   }

   if (!ob->is_body())
   {
      write("You fail to introduce yourself to " + ob->short() + ".");
      return;
   }

   ob->introduce(this_body());
   tell(this_body(), "You introduce yourself to " + ob->query_name() + ".");
   tell(ob, this_body()->query_name() + " introduces " + this_body()->query_reflexive() + " to you.");
}

void do_introduce_to_obj(object ob)
{
   return do_introduce_wrd_to_obj("yourself", ob);
}

void do_introduce_wrd(string word)
{
   object *players = filter_array(all_inventory(environment(this_body())), ( : $1->is_body() && $1 != this_body() :));

   if (word != "yourself" && word != "myself")
   {
      write("You can only introduce yourself.");
      return;
   }

   foreach (object p in players)
   {
      p->introduce(this_body());
   }
   this_body()->my_action("$N $vintroduce $r as \"$O1\".", this_body()->physical_appearance(),
                          this_body()->query_name());
   this_body()->other_action("$O $vintroduce $r as \"$O1\".", this_body()->physical_appearance(),
                             this_body()->query_name());
}

void do_introduce_obj(object ob)
{
   if (ob == this_body())
      return do_introduce_wrd("yourself");
   if (ob->is_body())
      this_body()->simple_action("$N $vare happy to introduce: $O!", ob->query_name());
   else
      write("You are not sure how to introduce that.");
}

void create()
{
   add_rules(({
       "WRD",
       "WRD to OBJ",
       "to OBJ",
       "OBJ",
       "",
   }));
}
