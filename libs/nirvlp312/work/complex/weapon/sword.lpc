#include <combat.h>
#include <message.h>
#include <persistence.h>

inherit WEAPON;

void configure() {
  WEAPON::configure();
  set_persistence(__FILE__,PER_KEEP_VARS);
  set_type("sword");
  set_name("sword");
  set_short("a sword");
  set_long("This is a simple sword.\n");
  set_pointiness(400+random(300));
  set_sharpness(700+random(300));
}

status prevent_wield(object by) {
  mixed h;

  if (h = WEAPON::prevent_wield(by))
    return h;
  if (query_weight()*5 > by->query_str()*sizeof(h = get_holding_parts(by)))
    return
      send_message(({M_ME_THE,M_ME_VERB,"are",
                    " too heavy to be wielded in only ",
                    M_OBJECT,M_THE,h,".\n"}),by), 1;
}
