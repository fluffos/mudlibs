#include <ansi.h>

int    shortFix;
object targetObject;

void doShadow(object input)
{
 targetObject = input;
 shadow(targetObject, 1);
}

void deShadow()
{
 destruct(this_object());
}

int drop()
{

 if(query_verb()=="quit" || !this_player() || this_player()->query_ghost())
 {
  int tmp;
  tmp = (int)targetObject->drop();
  deShadow();
  return tmp;
 }
 if(targetObject->short()) write("You cannot perform that action while "+(string)targetObject->short()+" is kept.\n");
  return 1;
}

int queryKept() { return 1; }

string short() {
 string flag;
 if(query_verb()=="quit" || shortFix || (this_player()!=environment(targetObject)))
  return (string)targetObject->short();
 else {
  if( this_player() && member( this_player()->query_treasure_obj(), targetObject ) >= 0 )
    flag = BOLD + "["+GREEN+"K"+WHITE+"]";
  else
    flag = BOLD + "["+YELLOW+"K"+WHITE+"]";
  return (flag +NORM+" "+(string)targetObject->short());
 }
}

set_vtest(x) { shortFix = x; }
