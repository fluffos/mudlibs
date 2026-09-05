#include <ansi.h>

void reset(int x)
{
  if(x) return;
  call_out("pee_em", 8, 1);
}

status id(string str)
{
  return(str=="pee_obj"||str=="urine stain"||str=="stain");
}

drop()
{
  return 1;
}

extra_look()
{
  if(environment()==this_player())
    write("You reek of "+HIY+"URINE"+NORM+".\n");
  else
    write((string)environment()->query_name()+" reeks of "+HIY+"URINE"+NORM+".\n");
}

pee_em(x)
{
  if(!environment()) return;
  if(x == 5) {
    tell_object(environment(), "Thank god.\nThe urine smell faded away.\n");
    return destruct(this_object());
  }
  x ++;
  if(environment(environment())) {
    tell_room(environment(environment()), (string)call_other(environment(),(living(environment())?"query_name":"short"))+" REEKS of "+HIY+"URINE"+NORM+"!\n");
  }
  call_out("pee_em", 16, x);
}

short() {
  if(!living(environment())) return "A "+HIY+"urine"+NORM+" stain";
}

