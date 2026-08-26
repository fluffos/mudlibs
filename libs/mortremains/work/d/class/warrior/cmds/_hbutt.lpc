#include <mudlib.h>
#include <config.h>
#define COST 5

int cmd_hbutt(string str){
  object targ;

  if(!str){
    write("Headbutting requires a target.\n");
  return 1; }

  targ = present(str, environment(TP));

  if(!targ){
    write("You don't see anything like that here.\n");
  return 1; }

  if(!TP->cast_spell(COST)){
    write("Your head hurts way too much already.\n");
  return 1; }

  targ->block_attack(random(4)+1);
  TP->receive_damage(3, "bludgeoning");
    write("You slam your head into "+targ->query("cap_name")+"'s face and knock them unconcious for a while.\n");
    say(TPN+" slams their head into "+targ->query("cap_name")+"'s face and it knocks them unconcious for a while.\n");

return 1;
}
