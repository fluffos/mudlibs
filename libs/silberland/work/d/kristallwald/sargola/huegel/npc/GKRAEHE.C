inherit "std/mnpc"; 
 
#include <properties.h> 
#include <language.h> 
#include <moving.h> 
#include <mnpc.h> 
#include <combat.h>
#include <new_skills.h>
#include "../def.h" 


int auge();
 
create() 
{ 
  if (!is_clone(ME)) return; 
  ::create(); 
  SetProp (P_SHORT, "Eine gemeine Kraehe"); 
  SetProp (P_LONG, BS("Die Kraehe ist tiefschwarz, ihre Federn glaenzt, wenn " 
	+"sie sich bewegt. Mit ihrem langen Schnabel kann sie vermutlich " 
	+"leicht Schaden anrichten. Sie starrt Dich unentwegt an.")); 
 
  AddDetail(({"federn","federkleid"}), 
  	BS("Das Federkleid ist tief schwarz.")); 
  AddDetail("schnabel", 
	"Pass auf, dass sie Dir nicht ein Auge auspickt!"); 
  SetProp (P_NAME, "Kraehe"); 
  SetProp (P_GENDER, FEMALE); 
  AddId ( ({"kraehe" }) ); 
  create_default_npc (7); 
  
  SetProp (P_HANDS, ({" mit ihrem scharfen Schnabel", 70})); 
  SetProp (P_ALIGN, 50); 
 
  SetProp (P_MSGOUT, "gleitet weiter"); 
  SetProp (P_MSGIN, "gleitet herein"); 
  SetProp(P_MMSGIN, "flatter unheilvoll herein"); 
  SetProp(P_MMSGOUT, "flattert unheilvoll weiter"); 
 
 
 
  //******************** 
  //Props zum moving NPC 
  //******************** 
  SetProp(P_MNPC_AREA, ROOM+"0"); 
  SetProp (P_MNPC_DEFAULTROOM, ROOM+"0303t"); 
  SetProp (P_MNPC_WAIT, ({20,30,30})); 
  SetProp (P_MNPC_FLAGS, MOV_OUTDOORS+MOV_MOVES); 
 
  SetProp(P_SPELLRATE, 30);
  AddSpell(1,1, 
	"Die Kraehe pickt Dir ein Auge aus!\n", 
	"Die Kraehe pickt @WEM ein Auge aus!\n", 
	DT_BLUDGEON, "auge"); 
 
  AddSpell(10,400, 
	"Die Kraehe treibt ihre Krallen in Deinen Oberarm.\n", 
	"Die Kraehe treibt ihre Krallen in @WESSEN Oberarm.\n", 
	DT_SLASH, ([SP_SHOW_DAMAGE:1]) ); 


  SetChats ( 30, ({
  	"Die gemeine Kraehe kraeht: KRAAAAAHHH\n",
  	"Die gemeine Kraehe pickt gelangweilt einen Halm aus.\n",
  	"Die gemeine Kraehe mustert Dich argwoehnisch.\n",
  	"Die gemeine Kraehe kraechzt Dich an.\n",
  	"Die gemeine Kraehe putzt sich mit ihrem Schnabel.\n",
  	"Die gemeine Kraehe fliegt ueber Deinem Kopf.\n" }));







} 
 
auge(object enemy, int damage, mixed dam_type) 
{ 
	if(random(15)==1)
	{
		tell_object(enemy, "Die Kraehe pickt Dir ein Auge "
			+"aus! Du bist blind!\n");
		enemy->SetProp(P_BLIND, 1);
	}
}
