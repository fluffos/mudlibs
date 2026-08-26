#include <mudlib.h>
inherit OBJECT;

void create(){
  seteuid(getuid());
  set("short" , "A nice piece of shit");
  set( "long" , @EndText
  A piece of shit.

EndText
  );
  set("mass" , 1);
  set("bulk" , 1);
  set("id" , ({ "shit" }) );
}

void init() {
  add_action( "fling_shit" , "fling" );
  add_action("throw_func" , "throw");
}
int fling_shit(string str){
  if(!str){
    write("Fling what?\n");
    return 1;
  }
  if(str == "shit"){
    write("You fling a bunch of shit at the wall, its sticks.\n");
    say(TPN+" flings a bunch of shit at the wall, it sticks.\n");
    remove();
    return 1;
  }
  return 1;
}
int throw_func(string str){
object target;
target = present(str , environment(this_player()) );

  if(!str){
  write(target->query("cap_name")+" isn't here.\n");
return 1; }
  if(str == "shit"){
    write("You fling the shit at"+target->query("cap_name")+".\n");
    say(TPN+" flings some shit at "+target->query("cap_name")+".\n",target);
    tell_object(target , TPN+" hucks a big piece of shit at you.\n");
    this_object()->move(target);
  return 1; }
return 1;
}
