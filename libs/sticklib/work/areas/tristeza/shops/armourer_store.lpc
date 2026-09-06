inherit "/lib/shop_store";
#include <armour_defs.h>

void
reset_store()
{
    /*
	log_file("SHOP",ctime(time())+(x ? (" "+query_money()+"\n") : " *****\n"));
    */
    set_money(15000 + sizeof(users())*1000);
}

void
create_store()
{
    int i;
    for (i = 2 + random(3); i; --i)
	move_object((object)ARMOUR_SERVER->make_random_armour(3),
	  this_object());
    reset_store();
}

int
accept_object(object ob)
{
    if (!ob->is_armour() || ((int)ob->query_value() < 10) ||
      ob->query_thief_item()) return 0;
    return 1;
}
