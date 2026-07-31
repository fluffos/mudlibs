#include <ansi.h>
void yes_no(string arg,object ob);


void kill_ob(object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
