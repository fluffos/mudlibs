#include "/obj/ansi.h"
#define PLAN "/open/pub_plans/star.plan"
void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIW+"                        ***"+NORM+HIB+"Areas"+NORM+HIW+"***\n\n"+NORM);
  write_file(PLAN, "Plan currently under construction\n");
  destruct(this_object());
}
