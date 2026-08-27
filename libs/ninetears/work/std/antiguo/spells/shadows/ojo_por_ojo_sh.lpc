// Paris. Nov'98
// Tyrael - Limpieza total y brutal de bugs - Nov'01

// SOLUCIONARIAMOS PROBLEMA DE LLAMADAS ENTRE MGS A ADJUST_HP
// SI HACEMOS QUE ESTE HECHIZO SOLO SE APLIQUE A DANYO DE ARMAS
// QUE ES BASTANTE LOGICO.

// UFFF, KE MAL ESTA LO DE DISPELL Y DESTRUCT DE LA SHADOW... PFF

#include <spells.h>
#define PROP "Ojo por Ojo"
#define ARCHIVO "/std/spells/shadows/ojo_por_ojo_sh"
// #define	BONUS MAX(myplayer->query_sphere("wizwar"),myplayer->query_sphere("wizwar"));
#define	BONUS	3

int check_off=0;
int contador = 0;
object myplayer;

void setshadow(object ob) 
{
  shadow(ob,1);
  myplayer = ob;
  myplayer->add_extra_look(ARCHIVO);
}

int check_duration()
{
  return (myplayer->query_dead() || !myplayer->QTP(PROP));
}

void destruct_ojo_por_ojo_shadow()
{
    if (!myplayer->query_dead())
    {
      tell_room(ENV(myplayer),"El %^BOLD%^aura de proteccion%^RESET%^ de "+myplayer->query_cap_name()+" desaparece "
                              "lentamente.\n",({ myplayer }));
      tell_object(myplayer, "Tu blanquecina aura de proteccion desaparece lentamente.\n");
	}
      myplayer->remove_extra_look(ARCHIVO); 
      destruct(TO);
}

void dispell_me()
{
  destruct_ojo_por_ojo_shadow();
}

// mmmm, a ver a ver que problemas habra si esto no rula...
varargs mixed move_player(string dir, string dest, mixed message,object followee, mixed enter )
{
  mixed kk=myplayer->move_player(dir,dest,message,followee,enter);
	// call_out a dest quitado... a ver como fona.
  if (check_duration())
	destruct_ojo_por_ojo_shadow();
  return kk;
}

int adjust_hp(int cantidad, object atacante, int hechizo)
{
	int ret;
  // el check se deberia hacer por aqui arriba...
  //int pupita = cantidad*(25+(myplayer->QL)+random(25))/100;
  int pupita = cantidad*(25+(myplayer->QL)+random(25))/300;
		// si llevas piel de piedra no hay ojo por ojo... aun
	if (hechizo || myplayer->query_stoneskin_spell())
		return myplayer->adjust_hp(cantidad,atacante,hechizo);
  if (pupita > 100) pupita = 100;
  if (cantidad>=0) return myplayer->adjust_hp(cantidad,atacante, hechizo);
  tell_room(ENV(myplayer),"El aura de "+myplayer->QCN+" brilla dolorosamente al entrar en accion.\n", ({myplayer,atacante}));
  tell_object(atacante,"El Aura de "+myplayer->QCN+" brilla con intensidad, sabes que tu tambien sufriras.\n");
  tell_object(myplayer,"Tu aura brilla con furiosidad cuando tu contrincante recibe el mismo danyo que tu.\n");
  contador++;
  atacante->adjust_hp(pupita,myplayer,1);
  ret = myplayer->adjust_hp(cantidad,atacante,hechizo);
  if (check_duration() || contador>=5) destruct_ojo_por_ojo_shadow();
	return ret;
}

int query_ojo_por_ojo_shadow(){ return 1; }
int query_contador_ojo() { return contador; }

string extra_look()
{
  return "Una %^BOLD%^WHITE%^blanquecina aura%^RESET%^ le protege.\n";
}
