// Ein einfacher NPC, der Attack() und Defend() 
// benutzt.
//
//
// ACHTUNG: ER DARF DANN NICHT MEHR AddSpell() benutzen
//          DA ER SONST MEHRERE ANGRIFFE PRO RUNDE BEKOMMT.
//
// Samtpfote@Tamedhon

#include <combat.h>
#include <properties.h>

void Attack(object en)
{
	switch(random(100))
	{
		case 1..10:
			tell_room(environment(),
				"$MONSTER haut $EN eine runter.\n",
				({ en }));
			tell_object(en,
				"$MONSTER haut Dir eine runter.\n");
			en->Defend(schaden, damtype, spellmapping, en);
			break;
		
		// mit case halt mehrere monster.


		default:
			::Attack(en);
			break;
	}	
}


int Defend(int dam, string *dts, mixed spell, object en)
{
	// hier evtl so routinen, die dam rauf/runter manipulieren

	return ::Defend(dam, dts, spell, en);
}


void create()
{
	if(!clonep(TO)) return 0;
	::create(); 

	// ... bla bla bla 
}
