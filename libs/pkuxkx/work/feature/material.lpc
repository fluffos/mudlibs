// Material.c
//
// Create by pretty 10/09/98

#include <dbase.h>

int is_material()
{
	return 1;
}

int init_material()
{
	switch ( query("material") )
	{
		case "steel" :
			set("rigidity", 150);
			set_weight( 1500);
			set("damage", 15);
			break;
		case "jade" :
			set("rigidity", 80);
			set_weight( 1000);
			set("damage", 10);
			break;
		case "wood" :
			set("rigidity", 50);
			set_weight( 500);
			set("damage", 5);
			break;
		case "bamboo" :
			set("rigidity", 70);
			set_weight( 600);
			set("damage", 7);
			break;
		case "gold" :
			set("rigidity", 130);
			set_weight( 1600);
			set("damage", 13);
			break;
		case "silver" :
			set("rigidity", 120);
			set_weight( 1300);
			set("damage", 12);
			break;
		case "stone" :
			set("rigidity", 140);
			set_weight( 1700);
			set("damage", 17);
			break;
		case "heavysteel" :
			set("rigidity", 250);
			set_weight( 2500);
			set("damage", 25);
			break;
		default :
			set("rigidity", 150);
			set_weight( 1500);
			set("damage", 10);
			break;
	}
	return 1;
}
