/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;
inherit M_HEALING;

int is_bandage()
{
   return 1;
}

float query_value()
{
   return (float)(query_heal_value());
}

void mudlib_setup()
{
   object::mudlib_setup();
   set_id("bandage");
   set_adj("simple");
   set_heal_value(5);
}

mixed direct_apply_obj(object ob)
{
   return "Apply to what limb?";
}

mixed direct_apply_obj_to_str(object ob, string str)
{
   return 1;
}

void apply_to(string str)
{
   this_object()->heal_from_bandage(str);
   destruct(this_object());
}