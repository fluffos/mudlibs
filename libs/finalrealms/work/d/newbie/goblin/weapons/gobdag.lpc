/* one way of doing a "racially" customized weapon, in this case a dwarf axe */
/* The Goblins dagger is made out of the code dwarf_axe.c by Calamari*/
/* The todays date when compiled this little code is  18.05 1995*/
/* Thanks to:	Taniwha, & Goodfoot plus testcal who tested out this dager!*/
#define RACE_BONUS 2
inherit "/baseobs/weapons/dagger";

void setup()
{
	/* not we call this existing setup command first, then override the thing we
want to change */
	::setup();
	 set_long("This is a goblin dagger. The special about it is that the old Goblin"
	 " Golliom made this out of evil bones of the old Mage Sabeltooth Many hundred "
	 " centries ago. Rumour says that this weapons that after he made the daggers, "
	 "He boiled them in the Sabeltooths blood and lots of magic in it.But then for "
	 "other races than Goblins it will nealry funcionate as a normal dagger,but for"
	 " Goblins it will work GREAT!\n");
}

/* if the wielder is a dwarf, and this is his only weapon, he gets a bonus */
int weapon_attack(object him,object me)
{
	int rv;
	::weapon_attack(him,me);
	if((string)me->query_race() == "half-orc")
	{
/* this checks to make sure that this is the ONLY wielded weapon then 50% of the time awards a bonus attack */
		if( sizeof(me->query_weapons_wielded()) == 2 && !random(RACE_BONUS) )
	  {
			tell_object(me,"You use your dagger with skills learned by generations of goblin masters.\n");
		  tell_object(him,"The nasty goblin does something clever with an sneaks an extra low blow in !\n");
			::weapon_attack(him,me);
	  }

	}

		/* Hmm, wonder if this will work....*/
	else if((string)me->query_race() != "half-orc")
	{
	 if( sizeof(me->query_weapons_wielded()) == 1)
	 {
			tell_object(me,"You try to hit him hard but fails...There is something worng with this dagger \n");
		  tell_object(him,"There seems like the dagger is taking control over him\n");
			::weapon_attack(him,me);
	  }

	}

}

