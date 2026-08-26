#include <verbs.h>

inherit VERB_OB;

void do_unwield_obj(object ob)
{
   ob->do_unwield();
}

void do_unwield()
{
   this_body()->query_weapons()[0]->do_unwield();
}

void do_unwield_wrd(string word)
{
   if (word == "all")
   {
      foreach (object weapon in this_body()->query_weapons())
      {
         weapon->do_unwield();
      }
   }
}

void create()
{
   clear_flag(NEED_TO_SEE);

   add_rules( ({ "", "OBJ", "WRD", }), ({ "" }));
}