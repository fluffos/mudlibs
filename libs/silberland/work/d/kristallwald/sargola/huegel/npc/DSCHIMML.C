/************************************************  
** Schimmlerpapa				*  
** 					      	*  
** date: 23-09-97 by Sargola@Silberland     	*  
** Email: a9504778@unet.univie.ac.at         	*  
*************************************************  
** Updates:       :        
** Updates:       :        
** Updates:       :        
**   
*/  
  
inherit "std/mnpc";  
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
     SetProp(P_SHORT, "Ein Schimmlerpapa");  
     SetProp(P_LONG, BS("Der Schimmlerpapa ist schon um einiges groesser, "
	+"als das Schimmlerbaby. Mit ihm ist sicher nicht gut Kirschen "
	+"essen."));  

     SetProp(P_GENDER, MALE);  
     SetProp(P_NAME, "Schimmlerpapa");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"schimmler", "schimmlerpapa", "papa"}));  
     SetProp(P_DIE_MSG, " zerfranst sich in die Hoelle.\n");  
     SetProp(P_NOCORPSE, 1);
     create_default_npc (19);  
     SetProp(P_HANDS, ({" mit zerfransten Haenden", 150, DT_BLUDGEON}));  
     SetProp(P_AGGRESSIVE, 1);
   
     SetProp(P_RACE, "Schimmler");  
     SetProp(P_ALIGN, -350);  
     SetProp(P_SIZE, 160);
     
     
     SetProp(P_RESISTANCE_STRENGTHS, 
     	([DT_MAGIC:-0.3,
     	  DT_ACID:-0.3,
     	  DT_POISON:-0.3,
     	  DT_COLD:-0.2,
     	  DT_TERROR:-0.2,
     	  DT_FIRE: -0.3
     	]) );
     
     SetProp(P_NOMAGIC, 55);
 

     SetAttackChats( ({
	"Der Schimmlerpapa wird rasend wuetend.\n",
	"Der Schimmlerpapa wendet seine Verwirrtaktik an.\n",
	"Der Schimmlerpapa wird zum Berserker.\n"}) );   

	AddSpell (1,700,
	"Das Schimmlerbaby spricht einen Vernichtungszauber!\n",
	"Das Schimmlerbaby spricht einen Vernichtungszauber!\n",
	DT_MAGIC, ([SP_SHOW_DAMAGE:1]) );


}
