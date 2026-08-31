#include <std.h>
inherit OBJECT;

 object oi;
void create() {
 ::create();
   set_short("a reception desk");
   set_id(( { "desk", "reception desk" }) );
   set_name("desk");
   set_long("The desk stands at the far side of "
            "the room, but no one is sitting behind "
            "it. Several drawers line the back of "
            "the desk.");
   set_weight(1);

   set_prevent_get("It's too large");
   oi = new("/std/bag_logic");
   oi->set_name("drawer");
   oi->set_id( ({"drawers", "drawer", "oi"}) );
   oi->set_long("The small wooden drawer is closed.");
   oi->set_closed_long("The small wooden drawer is closed.");
   oi->set_open_long("The small wooden drawer is open.");
   oi->set_short("a drawer");
   oi->set_possible_to_close(1);
   oi->set_weight(1);
   oi->set_value(0);
   oi->set_max_internal_encumbrance(200);
   oi->set_lock("unlocked");
   oi->set_key("I_have_no_key");
   oi->set_property("magic hold", 10);
/*   oi->blah=new("/d/standard/frealmz/obj/papers");
   oi->blah->move(this_object()); */
}

int get() { return 0; }
