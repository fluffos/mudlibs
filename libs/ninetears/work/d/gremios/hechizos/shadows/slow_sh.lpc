#include <spells.h>
object my_player;
int counter;

int toka = 2;

void destruct_slow_shadow() 
{
  my_player->remove_timed_property("slow_on");
  destruct(TO);
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player=ob;
  counter=0;
}

int check_duration()
{
  if ( !(my_player->query_timed_property("slow_on")) )
  {
    tell_object(my_player,
      "El tiempo parece volver a su velocidad normalm cuando el hechizo desaparece.\n");
    tell_room(ENV(my_player), my_player->QCN+
      " parece que sus movimientos vuelven a su velocidad normal.\n",
      my_player);
    return 1;
  }
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
  if (check_duration()) call_out("destruct_slow_shadow",0,0);
  return my_player->move(dest, messout, messin );
}

varargs mixed move_player(string dir, string dest, mixed message, object
				followee, mixed enter)
{
  if (check_duration() )
    call_out("destruct_slow_shadow",0,0);
  return my_player->move_player(dir, dest, message, followee, enter);
}
  
int query_time_spell() { return 1; }
int query_slow_spell() { return 1; }

void dispell_me()
{  
  tell_object(my_player,
    "No te podias mover rapidamente, pero parece que todo vuelve a su normalidad.\n");
  tell_room(ENV(my_player), my_player->QCN+
    " se mueve normalmente otra vez, la magia que le afectaba ha sido destruida.\n",
    my_player);
  destruct(TO);
}

void dispell_time_spell()
{
  dispell_me();
}

// ESTO NO SE LLAMA...
void heart_beat()
{
  /*if ((counter=!counter)) my_player->heart_beat();
  else write("\nPUTON!\n");*/
  if (toka > 1) { toka = 0; my_player->heart_beat(); }
  else { tell_object(TO, "ahora no toka\n"); toka++; }
}
