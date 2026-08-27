// HACER CAMBIOS A ESTA SHADOW

// 1.- Al contrario que espejos o pieles, esta shadow
// debe devolver un valor al sistema de combate paraa
// que se muestre el write_message del arma. Por eso
// no puede destruirse directamente una vez le han dado
// el ulimo toke, asi k hay k hacer un call_out y andar
// con variables para saber si la shadow esta activa o no.
// ademas hay que dar un mensaje en caso de no hacer nada
// de danyo. Y ademas, hay que controlar que la shadow este
// activa en el caso de un dispell, ya que si no lo esta
// habria q pasar el dispell mas abajo.



// Tyrael - Reescrito totalmente para eliminar bugs - Nov '01
// se puede poner como en mirror un tiempo para tenerlas viejas
// pero weno, vamos a dejarlo asi por ahora para omiqs y tal xD
//
// AL PONERLO EN JUEGO, habra que ponerle una duracion maxima
// porque si no, se pone uno a xpear con esto en un sitio donde
// no le peguen los npcs, y ale, a vivir sin temer por asesinos
// ladrones ni cosas destas.
//
// Una vez puesto, se puede aprovechar igualmente esto, YA QUE
// al ir xpeando con las pieles "viejas", el primer toque (por
// jugabilidad) siempre se lo come la piel, asi que un emboscar
// se lo comeria la piel. Por ello, deberiamos shadowear el
// move para que compruebe (como con otras shadows) si debe
// disiparse y asi el jugador sepa que de recibir un palo
// se lo comera.
//
// He quitado TODO call_out, ya que en las shadows NO SON BUENA
// IDEA (por ejemplo, un call_out para destruirse la shadow a
// los 0 segundos provocaba que una vez sin pieles NO se nos
// notificase -se destruyera la shadow- hasta el final del
// hearbeat, por lo que chupando palos a saco en ese heart,
// todos iban a pieles aunque no nos quedara ninguna ;)
//
// El tercer parametro de adjust_hp() solo se usa para shadows
// como esta, para saber que el danyo es por hechizo. Esto lo
// resolvieron en RL quitando la llamada a spell_damage()
// por lo que nunca un MG alli con pieles recibe hechizos
// criticos o pifias. -> MAL. Asi que ahora no se masquea
// spell_damage, sino como esta hace un adjust_hp con el
// tercer parametro a 1, se comprueba y se hace lo propio
// para esta shadow.
//
// Por ultimo, estaria bien shadowear los do_death para
// quitar estas shadows al morir.

// PIEL ROBLIZA (o algo parecido) - Tyrael - Jun'02
// NO PARA KIEN PUEDA TENER PIEL DE PIEDRA, ACTUA COMO SI FUESE PIEDRA!

#include <spells.h>

object my_player;
int pieles;

void destruct_stoneskin_shadow()
{
  tell_object(my_player,"Tu piel adquiere un color mas carnal.\n");
  tell_room(ENV(my_player),"La piel de "+my_player->QCN+" adquiere un color mas carnal.\n",my_player);
  //my_player->RTP("stoneskin_on");
  my_player->remove_extra_look("/d/gremios/hechizos/shadows/robliza_sh");
  destruct(TO);
}

void setup_shadow(object ob,int num_pieles)
{
  shadow(ob,1);
  my_player=ob;
  if (num_pieles > 8)
	  pieles = 8;
  else
	  pieles = num_pieles;
  my_player->add_extra_look("/d/gremios/hechizos/shadows/robliza_sh");
  //my_player->ATP("stoneskin_on",num_pieles,tiempo);
}

int query_stoneskin_spell()
{
  return pieles;
}

int adjust_hp(int amount,object hitter,int ha_sido_hechizo)
{
	if (hitter) {
  		if (!living(hitter) || pieles<=0 || amount>0) return my_player->adjust_hp(amount,hitter,ha_sido_hechizo);
	}
  if (ha_sido_hechizo) {
	//tell_object(my_player, "El hechizo traspasa tu piel de piedra!\n");
	//tell_room(ENV(my_player), "El hechizo traspasa la piel de "+my_player->QCN+".\n", my_player);

// TODO ESTE CODIGO ES SOLO POR SI SE PONE UN TIEMPO MAXIMO
  //if (!my_player->QP("stoneskin_on")) {
//	my_player->adjust_hp(damage,caster,ha_sido_hechizo);
//	destruct_stoneskin_shadow();
//	}
//  else
	return my_player->adjust_hp(amount, hitter, ha_sido_hechizo);
  }

	//if (hitter) {
  //tell_object(my_player,hitter->QCN+" te quita una piel de piedra.\n");
  //tell_object(hitter,"Quitas una piel de piedra a "+my_player->QCN+".\n");
  //tell_room(ENV(my_player),hitter->QCN+" quita una piel de piedra a "+my_player->QCN+".\n",({my_player,hitter}));
	//}
	//else {
  //		tell_object(my_player, "El dolor te hace perder una piel de piedra.\n");
  //tell_room(ENV(my_player), "El dolor hace que "+my_player->QCN+" pierda una piel de piedra.\n",({my_player}));
	//}
  //if (pieles <= 0 || !my_player->QP("stoneskin_on"))
	my_player->adjust_hp(amount*(8-pieles)/8, hitter, ha_sido_hechizo);
	pieles--;
	if (pieles <= 0)
    destruct_stoneskin_shadow();

  return 0;
}

//int spell_damage(int damage,string type,string sphere,int salvation,object caster)

void dispell_me()
{
	// interesante disyuntiva...
	// si vamos con pieles "viejas" que hacemos aqui?
	// disipamos estas pieles y hacemos un dispell mas? xD
	// lo dejamos asi por jugabilidad, iwal ke en adjust_hp
	// nos pueden quitar UNA piel teniendolas viejas.
  destruct_stoneskin_shadow();
}

string extra_look()
{
  return "Su piel es de color rojizo.\n";
}
