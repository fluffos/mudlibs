#include <spells.h>
#define	MAX_MOVE_DAM 4

object my_player;
object my_thorn;

void setup_shadow(object ob, object thorn)
{
  shadow(ob,1);
  my_player = ob;
  my_thorn = thorn;
}

void dispell_me()
{
  tell_object(my_player, "Las espinas se sueltan lentamente de tus pies, parece que has tenido suerte.\n ");
  if ( my_thorn )
    destruct(my_thorn);
  destruct(TO);
}

void destruct_thorn_shadow()
{
  destruct(TO);
}

int query_thorn() { return 1; }

int check_duration()
{
  if ( my_thorn )
    return 0;
  else return 1;
}

varargs mixed move_player(string dir, string dest, mixed message, object
                                followee, mixed enter)
{
  int x;

  if ( check_duration() )
  {
    call_out("dispell_me",0,0);
    return my_player->move_player(dir,dest,message,followee,enter);
  }

  x = random(2);
  if(x==1)
  {
    tell_object(my_player,
      "Intentas menearte pero aprietas los pies demasiado contra el suelo "
      "y la herida de los pies se te abre cada vez mas por culpa de una espina. "
      "Quizas deberias quitartela primero?\n");
    tell_room(ENV(my_player), my_player->QCN+
      " grita de dolor al pisar demasiado fuerte el suelo y "
      " al clavarse mas profundamente una espina en sus pies.\n",my_player);
    my_player->adjust_hp(-random(MAX_MOVE_DAM)-1);
    return 1;
  }

  return my_player->move_player(dir,dest,message,followee,enter);
}

