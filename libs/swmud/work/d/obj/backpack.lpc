// Last edited by deforce on 03-03-2010
inherit CONTAINER;
inherit M_GETTABLE;
inherit M_VALUABLE;
inherit M_WEARABLE;

void setup()
{
   set_id("backpack", "pack");
   set_long("A pack that you can wear on your back.");
   add_relation("in");
   set_default_relation("in");
   set_mass(20000);
   set_max_capacity(320);
   set_slot("back");
}

mixed indirect_get_obj_from_obj(object ob1, object ob2) { return 1; }
mixed indirect_put_obj_wrd_obj(object ob1, object ob2) { return 1; }

int is_carry_container() { return 1; }
int query_hide_contents() { return 1; }