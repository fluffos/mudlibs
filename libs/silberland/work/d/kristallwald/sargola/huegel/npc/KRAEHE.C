inherit "std/mnpc";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <mnpc.h>
#include "../def.h"

create()
{
  if (!is_clone(ME)) return;
  ::create();
  SetProp (P_SHORT, "Eine Kraehe");
  SetProp (P_LONG, BS("Die Kraehe ist tiefschwarz, ihre Federn glaenzt, wenn "
	+"sie sich bewegt. Mit ihrem langen Schnabel kann sie vermutlich "
	+"leicht Schaden anrichten."));
  AddDetail(({"federn","federkleid"}),
  	BS("Das Federkleid ist komplett schwarz."));
  AddDetail("schnabel",
	"Pass auf, dass sie Dir nicht ein Auge auspickt!");
  SetProp (P_NAME, "Kraehe");
  SetProp (P_GENDER, FEMALE);
  AddId ( ({"kraehe" }) );
  create_default_npc (5);
 
  SetProp (P_HANDS, ({" mit ihrem scharfen Schnabel", 50}));
  SetProp (P_ALIGN, 50);

  SetProp (P_MSGOUT, "gleitet weiter");
  SetProp (P_MSGIN, "gleitet herein");
  SetProp(P_MMSGIN, "flatter munter herein");
  SetProp(P_MMSGOUT, "flattert munter weiter");



  //********************
  //Props zum moving NPC
  //********************
  SetProp(P_MNPC_AREA, ROOM+"0303t");
  SetProp (P_MNPC_DEFAULTROOM, ROOM+"0303t");
  SetProp (P_MNPC_WAIT, ({20,30,30}));
  SetProp (P_MNPC_FLAGS, MOV_OUTDOORS+MOV_MOVES);


  SetChats ( 30, ({
  	"Die Kraehe kraeht: KRAAAAAHHH\n",
  	"Die Kraehe pickt gelangweilt einen Halm aus.\n",
  	"Die Kraehe mustert Dich argwoehnisch.\n",
  	"Die Kraehe kraechzt Dich an.\n",
  	"Die Kraehe putzt sich mit ihrem Schnabel.\n",
  	"Die Kraehe fliegt ueber Deinem Kopf.\n" }) );
}
