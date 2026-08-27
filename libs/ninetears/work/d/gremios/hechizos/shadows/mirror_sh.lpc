#include <spells.h>

object my_player;
int images;
string da_short;


void really_quit()
{
	my_player->setmin("@$N llega de $F.");
	my_player->setmout("@$N se va hacia $T.");
	my_player->really_quit();
}


void set_da_short()
{
	if (images > 3)
		my_player->set_short("Varias imagenes de "+da_short);
	else switch (images) {
		case 3:
			my_player->set_short("Cuatro imagenes de "+da_short);
			break;
		case 2:
			my_player->set_short("Tres imagenes de "+da_short);
			break;
		default:
			my_player->set_short("Dos imagenes de "+da_short);
	}
}

string combat_short(int dark)
{
	return da_short;
}

void destruct_mirror_shadow()
{
  tell_object(my_player,"Tus imagenes se desvanecen!\n");
  tell_room(ENV(my_player),"Las imagenes de "+my_player->QCN+" se desvanecen!\n",my_player);
  my_player->remove_extra_look("/d/gremios/hechizos/shadows/mirror_sh");
  my_player->set_short(da_short);
  my_player->setmin("@$N llega de $F.");
  my_player->setmout("@$N se va hacia $T.");
  destruct(TO);
}

void setup_shadow(object ob,int num_images,int tiempo)
{
  shadow(ob,1);
  my_player=ob;
  images=num_images;
  tell_object(my_player,"De pronto "+num_images+" imagenes tuyas aparecen a tu alrededor.\n");
  tell_room(ENV(my_player),"De pronto aparecen "+num_images+" imagenes de "+my_player->QCN+" a su alrededor.\n",my_player); 
  my_player->add_extra_look("/d/gremios/hechizos/shadows/mirror_sh");
  my_player->ATP("ESPEJOS",num_images,tiempo);
  da_short = my_player->query_short();
  set_da_short();
  my_player->setmin("@$N llegan de $F.");
  my_player->setmout("@$N se van hacia $T.");
}

int query_mirror_spell()
{
  return images+1;
}

// NO TENEMOS POR QUE SABER SI LE HEMOS DADO SI NO ESTA AKI (mayor p.e.)
int adjust_hp(int amount,object hitter)
{
  int ret;

  if (!hitter || !living(hitter) || hitter==my_player || images<=0 || amount>0) return my_player->adjust_hp(amount,hitter);
  if ((random(images+1)==random(images+1))||(hitter->query_property("vision_real")))
  {
	tell_object(my_player,hitter->QCN+" consigue golpearte a ti en lugar de a tus imagenes.\n");
	// para que no vean si me dan si no estoy alli
	if (ENV(my_player) == ENV(hitter)) {
		tell_object(hitter,"Consigues golpear a "+my_player->QCN+" en lugar de a sus imagenes.\n");
		tell_room(ENV(my_player),hitter->QCN+" consigue golpear a "+my_player->QCN+" en lugar de a sus imagenes.\n",({my_player,hitter}));
	}
	else
		tell_room(ENV(my_player), "Alguien consigue golpear a "+my_player->QCN+" en lugar de a sus imagenes.\n",({my_player,hitter}));
	ret = my_player->adjust_hp(amount,hitter);
  }
  else
  {
	images--;
	tell_object(my_player,hitter->QCN+" golpea una de tus imagenes, que se deshace en mil pedazos.\n");
	if (ENV(my_player) == ENV(hitter)) {
		tell_object(hitter,"Golpeas una imagen de "+my_player->QCN+", rompiendola en mil pedazos.\n");
		tell_room(ENV(my_player),hitter->QCN+" golpea una imagen de "+my_player->QCN+" rompiendola en mil pedazos.\n",({my_player,hitter}));
	}
	else
		tell_room(ENV(my_player), "Alguien golpea una imagen de "+my_player->QCN+" rompiendola en mil pedazos.\n",({my_player,hitter}));
	set_da_short();
	ret = 0;
  }

  if (images<=0 || !my_player->QP("ESPEJOS"))
  {
    //tell_room(ENV(my_player),"Las imagenes de "+my_player->QCN+" desaparecen!\n",my_player);
    //tell_object(my_player,"Tus imagenes desaparecen!\n");
    destruct_mirror_shadow();
  }
  return ret;
}

void dispell_me()
{
  destruct_mirror_shadow();
}

string extra_look(object ob)
{
  // asi no rula!
  //return "Tiene "+images+" imagenes identicas a su alrededor.\n";
  //return "Tiene "+my_player->query_mirror_spell()+" imagenes identicas a su alrededor.\n";
  return "Tiene "+ob->query_mirror_spell()+" imagenes identicas a su alrededor.\n";
}
