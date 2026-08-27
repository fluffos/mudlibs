// PONER EN LUGAR D MSG_PUESTO UNA FLAG POR SI ES DISPELL
// YA KE SIEMPRE SAKAREMOS EL MENSAJE CUANDO NOS PEGAN.
// ni sikiera hay un ATP de la property... buff xD
#include <spells.h>
object my_player;
int pieles, pieles_on, msg_puesto;

void setup_shadow(object ob,int i)
{
  int j;
  j=random(5)+10;
  shadow(ob,j);
  my_player=ob;
  pieles=i;
	pieles_on=1;
	msg_puesto = 0;
  my_player->add_extra_look("/std/spells/shadows/stoneskin_sh");
}

void destruct_stoneskin_shadow(int dispelling)
{
	if (dispelling) {
	my_player->RTP("stoneskin_on");
  	tell_object(my_player,"Tu piel vuelve a ser normal.\n");
  	tell_room(ENV(my_player),"La piel de "+my_player->QCN+" vuelve a ser normal.\n",my_player);
  	my_player->remove_extra_look("/std/spells/shadows/stoneskin_sh");
	}
  destruct(TO);
}

int check_duration()
{
  return (my_player->QP("stoneskin_on") && (pieles > 0));
}

int query_stoneskin_spell() { return pieles;}

int spell_damage(int damage,string type,string sphere,int salvation,object caster)
{
  if (!check_duration()) {
	pieles_on = 0;
	msg_puesto = 1;
	my_player->RTP("stoneskin_on");
	tell_object(my_player,"Tu piel vuelve a ser normal.\n");
	tell_room(ENV(my_player),"La piel de "+my_player->QCN+" vuelve a ser normal.\n",my_player);
	my_player->remove_extra_look("/std/spells/shadows/stoneskin_sh");
	call_out("destruct_stoneskin_shadow",0,0);
	}
//Arreglos aki , por Dimmak
  my_player->adjust_hp(damage,caster);
    return damage;
}

// NECESITA REVISION POR TEMA CALL_OUT Y POR TEMA ADJUST_HP(0, HITTER)
int adjust_hp(int amount,object hitter)
//int weapon_damage(int amount,object hitter,object arma)
{
  if (!pieles_on || amount>0 || !hitter) return my_player->adjust_hp(amount,hitter);
	if (!amount)
		return 0;
  tell_object(hitter,"Quitas una piel de piedra a "+my_player->QCN+".\n");
  tell_object(my_player,hitter->QCN+" te quita una piel de piedra.\n");
  tell_room(ENV(my_player),hitter->QCN+" le quita a "+TO->QCN+" una piel de piedra.\n",({hitter,my_player}));
  pieles--;
  if (!check_duration()) {
	pieles_on = 0;
	msg_puesto = 1;
	my_player->RTP("stoneskin_on");
	tell_object(my_player,"Tu piel vuelve a ser normal.\n");
	tell_room(ENV(my_player),"La piel de "+my_player->QCN+" vuelve a ser normal.\n",my_player);
	my_player->remove_extra_look("/std/spells/shadows/stoneskin_sh");
	call_out("destruct_stoneskin_shadow",0,0);
	}
  // return my_player->adjust_hp(0,hitter); mmm, esto parece no devolver 0
	return 0;
}

// problema: se nos van las pieles y antes del call_out
// nos meten un disipar - resultado: nos disipan unas pieles
// que ya no tenemos - arreglar (arreglado ahora?)
void dispell_me()
{
	if (!pieles_on)
		my_player->dispell_me(); // dispell otro hechizo
	else {
		pieles_on = 0;
		// PQ USAR UN call_out? naa, directamente
		destruct_stoneskin_shadow();
	}
}

void dispel_stoneskin()
{
  dispell_me();
}

string extra_look()
{
  return "Su piel tiene el color y la textura de la roca.\n";
}
