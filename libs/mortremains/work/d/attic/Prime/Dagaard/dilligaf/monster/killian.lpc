#include <mudlib.h>
inherit MONSTER ;

void create () {
  ::create();
  seteuid(getuid());
  set("no_attack" , 1);
  set("short" , "Killian");
  set("long" , @EndText
  Its Killian, she owns the place. She looks up at you as you enter
  and smiles at you, amazingly she is probably one of the most 
  beautiful women that you have ever seen. Long blond hair surrounds
  her perfect smiling face, big brown eyes stare up at you past her
  small glasses. Absolute perfection.

EndText
);
  set("id" , ({ "killian" }) );
  set_level(1);
  set_size(4);
  set_name("killian");
  set_living_name("killian");
  set("gender" , "female");
  set("race" , "human");
}

void init() {
  command("say Welcome to Killians.");
  command("smile");
 }
