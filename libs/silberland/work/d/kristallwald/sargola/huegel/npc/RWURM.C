/************************************************  
** Regenwurm			*  
** 					      	*  
** date: 23-09-97 by Sargola@Silberland     	*  
** Email: a9504778@unet.univie.ac.at         	*  
*************************************************  
** Updates:       :        
** Updates:       :        
** Updates:       :        
**   
*/  
  
inherit "std/npc";  
#include <properties.h>  
#include <language.h>  
#include <combat.h>  
#include <new_skills.h>  
#include <moving.h>

#include "../def.h"  

int zaehler;
cl(object enemy);

create()  
{  
     if (!is_clone(TO)) return;  
     ::create();   
     zaehler = 1;
     SetProp(P_SHORT, "Ein Regenwurm");  
     SetProp(P_LONG, BS("Ein dicker, fetter, eckeliger Regenwurm."));  

     create_default_npc(3);
     SetProp(P_GENDER, MALE);  
     SetProp(P_NAME, "Regenwurm");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"regenwurm", "wurm"}));  
     SetProp(P_DIE_MSG, " kringelt sich toedlich getroffen zusammen.\n");  
     SetProp(P_HANDS, ({"mit seinem winzigen Mund", 45, DT_BLUDGEON}) );
     SetProp(P_AGGRESSIVE, 1);
     SetProp(P_HEAL, -10);  
     SetProp(P_RACE, "Wurm");  
     SetProp(P_ALIGN, 20);  
     SetProp(P_SIZE, 5);
     SUID;
     
}


void Defend(int dam, string dam_type, mixed spell, object enemy)
{

	if(random(5)==1 && zaehler ==1 )
	{
		cl(enemy);
	}
	::Defend(dam, dam_type, spell, enemy);
}

cl(object enemy)
{
	object ob;
	tell_object(enemy, BS("Der Wurm wird von Dir getroffen und in "
		+"zwei Haelften gespalten. Doch Regenwuermern macht das "
		+"nichts!! Du hast jetzt zwei Gegner...\n"));
		ob = clone_object(NPC+"rwurm");
		ob->move(environment(TO), M_GO);
		ob->Kill(enemy);
	zaehler = 0;
}