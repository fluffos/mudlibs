// Written by Tigran, September 7, 2000
inherit VERB_OB;

void do_descend_obj(object ob)
{
   if (base_name(ob) == SIMPLE_OB)
   {
      environment(ob)->do_descend("OBJ", ob);
   }
   else
   {
      ob->do_verb_rule("descend", "OBJ", ob);
   }
}

void create()
{
   add_rules( ({ "OBJ", }), ({ }) );
}