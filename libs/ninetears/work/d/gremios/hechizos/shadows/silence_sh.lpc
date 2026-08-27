#include <spells.h>

object my_player;

void destruct_silence_shadow() 
{
  destruct(TO);
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
}

int check_duration()
{
  if ( !(my_player->query_timed_property("silence_on")) )
  {
    tell_object(my_player,
      "La presion que sentias sobre tu cuello desaparece, y puedes hablar de nuevo.\n");
    tell_room(ENV(my_player), my_player->QCN+
      " tose fuertemente y puede volver a hablar de nuevo.\n",
      my_player);
    my_player->remove_extra_look(TO);
    return 1;
  }
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
    call_out("destruct_silence_shadow",0,0);
  return my_player->move(dest, messout, messin );
}
  
int query_silence_spell() { return 1; }

int cast() 
{
  tell_object(my_player,"No puedes formular hechizos, estas silenciado.\n");
  if (check_duration())
    call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_say(string str)
{
  tell_object(my_player,"Estas silenciado y no puedes decir nada.\n");
  tell_room(ENV(my_player), my_player->QCN+
    " mueve la boca, pero no sale ningun ruido de ella.\n",
    my_player);
  if (check_duration())
    call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_loud_say(string str)
{
tell_object(my_player,"Estas silenciado y no puedes decir nada.\n");
  tell_room(ENV(my_player), my_player->QCN+
    " mueve la boca, pero no sale ningun ruido de ella.\n",
    my_player);
 
  if (check_duration())
    call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_shout(string str)
{
  tell_object(my_player,"No puedes gritar porque estas silenciado.\n");
  tell_room(ENV(my_player), my_player->QCN+
    " pega un grito silencioso.\n",
    my_player);
  if (check_duration())
    call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_whisper(string str)
{
  tell_object(my_player, "No puedes susurrar porque estas silenciado.\n");
  tell_room(ENV(my_player), my_player->QCN+
    " mueve "+my_player->query_possessive()+" labios pero no emite ningun sonido.\n",
    my_player);
  if (check_duration())
    call_out("destruct_silence_shadow",0,0);
  return 1;
}

/* for the player's desc. */
string extra_look()
{
  if (check_duration())
    call_out("destruct_silence_shadow",0,0);
  return "No puede emitir sonidos.\n";
}

/* for an eventual dispel magic spell */
void dispell_me()
{
  
  tell_object(my_player,
    "Recuperas tu voz mientras el hechizo se disipa.\n");
  tell_room(ENV(my_player), my_player->QCN+
    " tose fuertemente y misteriosamente rompe su silencio.\n",
    my_player);
  my_player->remove_extra_look(TO);
  destruct(TO);
}

