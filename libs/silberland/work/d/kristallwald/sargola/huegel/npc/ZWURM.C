/************************************************  
** Zombiwurm			*  
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



create()  
{  
     if (!is_clone(TO)) return;  
     ::create();   
     SetProp(P_SHORT, "Ein Zombiwurm");  
     SetProp(P_LONG, BS("Ein eckelig dicker, weisslicher Zombiwurm. Du "
	+"Er hat grosse, gewoelbte schwarze Augen und einen fuer seine Verhaelt"
	+"nisse riesigen Mund. Sein Koerper ist gut und gern 30 cm lang."));  

     AddDetail("augen",
	"Die schwarzen, gewoelbten Augen sind weit offen. Wohl, damit er in "
	+"der Dunkelheit alles erkennen kann. Irgendwie erinnert es Dich an "
	+"Rosettenaugen.");

     AddDetail("mund",
	"Der Mund macht einen nicht ungefaehrlichen Eindruck. Obwohl der Wurm "
	+"so klein ist. Wer weiss, was der fuer Krankheiten uebertragen kann...");

     AddDetail("koerper",
	"Der Koerper ist fuer einen Wurm recht gross und er bewegt sich auch "
	+"aehnlich einer Schlange fort.");

     create_default_npc(6);
     SetProp(P_GENDER, MALE);  
     SetProp(P_NAME, "Zombiwurm");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"zombiwurm", "wurm"}));  
     SetProp(P_DIE_MSG, " bleibt regungslos liegen.\n");  
     SetProp(P_HANDS, ({"mit seinem Schwanz",80,DT_BLUDGEON}) );
     SetProp(P_AGGRESSIVE, 1);
     SetProp(P_HEAL, -100);  
     SetProp(P_ALIGN, 20);  
     SetProp(P_SIZE, 30);
     
     
}
