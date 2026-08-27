#include <spells.h>

object my_player,shadow;
int level,save,roll,doomed;
string guild;

void setshadow(object ob, object caster)
{
  shadow(ob,1);
  my_player=ob;
  if (my_player==caster) return;
  level=ob->query_level();
  guild=ob->query_guild_name();
  save=15-(level/3);
  roll=random(19) + 1;
  if (level<13 && !(guild=="hokemj" || guild=="taniwha")) doomed = 1;
  else if (roll < save) doomed = 1;
}

void destruct_hw1_shadow()
{
  if (doomed)
  {
    switch (level)
    {
      case 0..5:
        tell_object(my_player,"You are still dazed and confused after being exposed to such power.\n");
        shadow=clone_object(SHADOWS+"h_word_sh3");
        shadow->setshadow(my_player);
        break;
      case 6..8:
        tell_object(my_player,"You are still dazed and confused after being exposed to such power.\n");
        shadow = clone_object(SHADOWS+"h_word_sh3");
        shadow->setshadow(my_player);
        break;
      case 9..12:
        tell_object(my_player,"As your head slowly begins to clear, you find yourself unable to hear the world around you.\n");
        shadow = clone_object(SHADOWS+"h_word_sh2");
        shadow->setshadow(my_player);
        break;
      default:
        tell_object(my_player,"You are still dazed and confused after being exposed to such power.\n");
        shadow = clone_object(SHADOWS+"h_word_sh3");
        shadow->setshadow(my_player);
        break;
      }
    }
    else tell_object(my_player,"You return to your senses, shaking out the cobwebs after being blasted by such power.\n");
    destruct(TO);
}

int action_check(string str)
{
  tell_object(my_player,"You are too stunned to do anything.\n");
  return my_player->action_check("");
}

int cast()
{
  tell_object(my_player,"You are too stunned to do anything.\n");
  return 1;

}