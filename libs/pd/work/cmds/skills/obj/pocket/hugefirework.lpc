#include <std.h>
#include <dirs.h>
#include <rooms.h>
inherit OBJECT;
#define SMALLFIREWORK DIR_CLASS_CMDS+"/obj/pocket/firework"
int light(string str);
void display_messages(int i, object tp);
void create() {
  ::create();
  set_id( ({ "firework", "large firework", "huge firework" }) );
  set_name("a very large firework");
  set_short("a very large firework");
  set_long("This firework is simply HUGE.  You can <light> the firework to shoot it into the sky.");
  set_weight(80);
  set_value(0);
  set_property("no auction", 1);
  set_property("juggle", 1);
}
void init() {
  ::init();
  add_action("light", "light");
}
int light(string str) {
  object tp = this_player();
  if (!str || present(str, tp) != this_object())
    return notify_fail("Light what?\n");
  if (environment(tp)->query_property("indoors"))
    return notify_fail("You can't light the huge firework while indoors!\n");
  call_out("display_messages", 2, 0, tp);
  call_out("display_messages", 4, 1, tp);
  call_out("display_messages", 6, 2, tp);
  call_out("display_messages", 8, 3, tp);
  call_out("display_messages", 10, 10, tp);
  this_object()->move(ROOM_CACHE);
  return 1;
}
void display_messages(int i, object tp){ 
  object *who = filter(users(), (: environment($1) && !(environment($1)->query_property("indoors")) :));
  switch(i){
  case 0 :
    message("firework", "%^BOLD%^%^RED%^You shoot a HUGE red firework into the sky.%^RESET%^", tp);
    message("firework", "%^BOLD%^%^RED%^"+tp->query_cap_name()+" shoots a HUGE red firework into the sky.%^RESET%^", who, tp); break;
  case 1 : message("firework", "%^BOLD%^%^BLUE%^The red firework turns blue and starts to expand.%^RESET%^", who); break;
  case 2 : message("firework", "%^BOLD%^%^YELLOW%^The blue firework starts to fizzle and sparkle in the air.%^RESET%^", who); break;
  case 3 : message("firework", "%^BOLD%^%^BLACK%^The firework turns into a huge cloud of smoke in the air.%^RESET%^", who); break;
  default:
    who -= ({ tp });
    message("firework", "%^BOLD%^%^MAGENTA%^A small firework falls out of the smoke into your hands.%^RESET%^", who);
    foreach (object player in who) {
      new(SMALLFIREWORK)->move(player);
    }
    this_object()->remove();
  }
}
