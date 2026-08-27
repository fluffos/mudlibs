inherit "/std/comando";

object me,ob;

void setup() {
  poner_ayuda("\nNombre del Comando: Marca Oscura\nCoste en Energia: 10\nSintaxis: marcaoscura <objetivo>\nDescripcion: \n    Esta habilidad de los shamanes les permite tocar a sus enemigos con la energia del Mal, provocandoles graves danyos.\n");
  gasta_energia(10);
  impedir_movimiento("Detienes la ejecucion de la Marca Oscura al moverte.\n");
  poner_retardo(1);
}

int precondiciones() {
  object* armas;
  int dosmanos=0;
  me=query_ejecutor();

  ::precondiciones();

  if (me->query_static_property("marcando")) return notify_fail("\n");
  if (me->query_timed_property("marcado")) return notify_fail("\n");


  if(sizeof(find_match(query_argumento(),ENV(me)))) ob=find_match(query_argumento(),ENV(me))[0];
  else return notify_fail("A quien pretendes imponer la Marca Oscura?\n");
  if (ob==me) return notify_fail("Eso no seria una buena idea!\n");
  if (ob->query_dead()) return notify_fail("No puedes imponer la Marca Oscura sobre aquellos que ya estan muertos.\n");
  me->add_static_property("marcando",1);
  return 1;
}

int condiciones() {
  me->remove_static_property("marcando");
  if (me->query_dead()) return notify_fail("Tu muerte prematura ha impedido que tu oponente sufriese el Terror de la Marca Oscura.\n");
  ::condiciones();
  if (me->query_property("noguild")||me->query_pacify_spell()||ob->query_pacify_spell()) return notify_fail("Por alguna razon eres incapaz de terminar la imposicion de la Marca Oscura.\n");
  if (!ob||ob->query_dead()) return notify_fail("Tu oponente ha muerto y no podra sufrir el Terror de la Marca Oscura.\n");
  if (ENV(ob)!=ENV(me)) return notify_fail("Tu oponente ha huido como un cobarde!\n");
  return 1;
  me->add_static_property("marcando",1);
}

int efecto( string inutil, object masinutil ) {
  int mychance,itschance,pupa;

  me->remove_static_property("marcando");
  ::efecto(inutil,masinutil);
  mychance=me->query_level()+me->query_wis()+20;
  itschance=ob->query_level()+ob->query_con();
  itschance*=(100-ob->query_total_ac());
  mychance*=(300-me->query_thac0());

  if(random(mychance)+random(me->query_habilidad("marcar"))>random(itschance)) {
  tell_room(environment(me), me->query_cap_name()+" impone su mano sobre la piel de "+ob->query_cap_name()+", que comienza a arder con el Fuego Negro de la Marca Oscura.\n", ({me, ob}));
  tell_object(me, "Impones la Marca Oscura sobre la piel de "+ob->query_cap_name()+", que comienza a arder con el impio Fuego Negro!\n");
  tell_object(ob, me->query_cap_name()+" impone su Marca Oscura sobre tu piel, que comienza a arder con el impio Fuego Negro!\nEso realmente duele!!!\n");
  if(me->query_level()<ob->query_level()) me->adjust_sp(1);
  }
  else {
  tell_room(environment(me),ob->query_cap_name()+" consigue esquivar la imposicion de Marca Oscura de "+me->query_cap_name()+".\n",({me,ob}));
  tell_object(me, "No consigues alcanzar a tu enemigo!\n");
  tell_object(ob, "Consigues esquivar la imposicion de "+me->query_cap_name()+".\n");
  }
  me->add_timed_property("marcado",1,100);
  ob->attack_by(me);
  return 1;
}

void mostrar_mensajes(int r) {
        switch(r) {
                case 1:
                tell_object(me,"Concentras toda la energia del Mal en la palma de tu mano, que comienza a emitir una pulsacion de energia impia: la convocacion de la Marca Oscura da comienzo.\n");
                tell_room(ENV(me),me->QCN+" comienza a concentrarse, y su palma de la mano comienza a emitir una pulsante energia negra.\n",me);
                break;
                }
        }
