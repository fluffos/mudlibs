/* The hide in shadows shadow.  Cute huh?
 * Paris, Feb'98, Modificado para ser invis aunque te muevas. 
 * Paris,Feb'98, Traducidos los mensajes.
 */

#include <spells.h>
#define LEVEL_MOD 2

object tp;
int found;

void dest_invis_shadow();

void setup_shadow(object ob)
{
  tp = ob;
  shadow(ob,1);
}

attack_by(object him)
{
  dest_invis_shadow();
  return tp->attack_by(him);
}

int cast(string str)
{
  dest_invis_shadow();
  return tp->cast(str);
}

attack_ob(object him)
{
  dest_invis_shadow();
  return tp->attack_ob(him);
}

/* Comentado por Paris, razon: Ver principio del fichero
   object *move_player(string dir, string dest, string mess, object ob) {
   dest_invis_shadow();
   return (object *)tp->move_player(dir,dest,mess,ob);
   }
 */

int do_death(string str)
{
  dest_invis_shadow();
  return (int) tp->do_death(str);
}

int do_loud_say(string str)
{
  dest_invis_shadow();
  return (int) tp->do_loud_say(str);
}

int do_emote(string str)
{
  dest_invis_shadow();
  return (int) tp->do_emote(str);
}

int do_echo(string str)
{
  dest_invis_shadow();
  return (int) tp->do_echo(str);
}

int do_say(string str)
{
  dest_invis_shadow();
  return (int) tp->do_say(str);
}

int event_player_search()
{
  dest_invis_shadow();
}

int soul_com(string str)
{
  int i;
  if ((i=tp->soul_com(str))==1) dest_invis_shadow();
  return i;
}

void dest_invis_shadow()
{
  tell_room(ENV(tp),tp->QCN+" aparece de la nada delante de tus narices !!!.\n",tp);
  tell_object(tp,"Pierdes tu hechizo de invisibilidad.\n");
  call_out("do_dest_invis_shadow",0);
  found=1;
}

void do_dest_invis_shadow()
{
  destruct(TO);
}

int query_invis_shadow()
{
  int i=random(tp->query_level()*LEVEL_MOD);
  return i?i:1;
}

string pretty_short()
{
  if (found && tp) return tp->pretty_short();
  return 0;
}

string short ()
{
  if (found && tp || (query_verb() && query_verb()=="who")) return tp->short();
  return 0;
}

string pretty_plural()
{
  if (found && tp) return tp->pretty_plural();
  return 0;
}

string query_plural()
{
  if (found && tp) return tp->query_plural();
  return 0;
}

void dispell_me()
{
  dest_invis_shadow();
}
