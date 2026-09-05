#include <action.h>
#include <combat.h>
#include <event.h>
#include <message.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("foot");
  set_name("foot");
  add_id(({"foot"}));
  add_position("lower");
  add_bodypart_connectors(({BPC_ANKLE}));
}

status query_unreachable(object by) {
  mixed h;

  if (BODYPART::query_unreachable(by))
    return 1;
  if ((h = get_compound_bodypart()) && h->query_unreachable(by))
    return 1;
}
