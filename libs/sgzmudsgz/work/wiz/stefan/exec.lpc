#include <mudlib.h>
#include <playerflags.h>
#include <security.h>
inherit M_ACCESS;
create() { set_privilege(1); }

mixed exec_foo(){ 
this_body()->set_flag(F_INACTIVE);
write (this_body()->test_flag(F_INACTIVE));
write (F_INACTIVE);
write ("\n");
}
