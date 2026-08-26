// Last edited by deforce on 03-03-2010
inherit CONTAINER;
inherit M_GETTABLE;
inherit M_VALUABLE;

void setup()
{
   set_id("shoulder bag", "bag");
   set_long("A bag that you can carry on your shoulder.");
   add_relation("in");
   set_default_relation("in");
   set_mass(15000);
   set_max_capacity(240);
}

mixed indirect_get_obj_from_obj(object ob1, object ob2) { return 1; }
mixed indirect_put_obj_wrd_obj(object ob1, object ob2) { return 1; }

int is_carry_container() { return 1; }
int query_hide_contents() { return 1; }