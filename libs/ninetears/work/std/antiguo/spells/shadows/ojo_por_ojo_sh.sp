// Paris. Nov'98

#include <spells.h>
#define PROP "Ojo por Ojo"
#define ARCHIVO "/std/spells/shadows/ojo_por_ojo_sh"
#define	BONUS	MAX(myplayer->query_sphere("wizwar"),myplayer->query_sphere("wizwar"));

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
  return (myplayer->query_dead() || myplayer->query_timed_property(PROP));
}

void destruct_ojo_por_ojo_shadow()
{
  if (!check_duration())
    if (!myplayer->query_dead())
    {
      tell_room(ENV(myplayer),"El %^BOLD%^aura de proteccion%^RESET%^  de "+myplayer->query_cap_name()+" desaparece "
                              "lentamente.\n",({ myplayer }));
      tell_object(myplayer, "Tu blanquecina aura de proteccion desaparece lentamente.\n");
      myplayer->remove_extra_look(ARCHIVO); 
      destruct(TO);
    }
}

void dispell_me()
{
  destruct_ojo_por_ojo_shadow();
}

varargs mixed move_player(string dir, string dest, mixed message,object followee, mixed enter )
{
  mixed kk=myplayer->move_player(dir,dest,message,followee,enter);
  if (check_duration()) call_out("destruct_ojo_por_ojo_shadow",1);
  return kk;
}

int adjust_hp(int cantidad, object atacante)
{
  int pupita = cantidad*(50+random(50))/100;
//  if (cantidad>=0) return myplayer->adjust_hp(cantidad,atacante);
  tell_room(ENV(myplayer),"El aura de "+myplayer->QCN+" brilla dolorosamente al entrar en accion.\n");
  tell_object(atacante,"El Aura de "+myplayer->QCN+" brilla con intensidad, sabes que tu tambien sufriras.\n");
  tell_object(myplayer,"Tu aura brilla con furiosidad cuando tu contrincante recibe el mismo danyo que tu.\n");
  if (check_duration() || contador>=5) call_out("destruct_ojo_por_ojo_shadow",1);
  contador++;
  atacante->adjust_hp(pupita,myplayer);
  return myplayer->adjust_hp(cantidad,atacante);
}
    
  
int query_ojo_por_ojo_shadow(){ return 1; }
int query_contador_ojo() { return contador; }
string extra_look()
{
  return "Una %^BOLD%^WHITE%^blanquecina aura%^RESET%^ le protege.\n";
}
