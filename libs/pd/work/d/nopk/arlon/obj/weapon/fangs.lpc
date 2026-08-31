#include <std.h>
#include <arlon.h>

inherit WEAPON;

int weapon_hit(object ob);
void create()
{
 ::create();
 set_name("fangs");
 set_short("snake fangs");
 set_long("The fangs are razor sharp. There is a thin layer of "
          "a yellow liquid that looks like venom.");
 set_mass(6);
 set_wc(5);
 set_type("knife");
 set_id( ({ "fang", "fangs", "snake fangs" }) );
 set_hit((:weapon_hit:));
}

int weapon_hit(object ob)
{
 if (random(100) > 90)
   {
  //  write("%^MAGENTA%^%^BOLD%^The venom from your fangs dig into your opponent.");
 message("info", "%^MAGENTA%^%^BOLD%^The fangs dig into "+ob->query_cap_name()+".", environment(ob), ({ ob }) );
   message("info", "%^MAGENTA%^%^BOLD%^The fangs dig into you.",ob );
    ob->add_poisoning(random(5));
    return 1;
   }
 return 0;
}
