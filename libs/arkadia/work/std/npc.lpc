/*
  /std/npc.c

  This is the base for all NPC creatures that need to use combat tools.

*/
#pragma save_binary
#pragma strict_types

inherit "/std/creature";

#include <pl.h>
#include <stdproperties.h>

void
create_npc() 
{ 
    ::create_creature(); 
}

nomask void
create_creature() 
{
    if (!random(5))
	add_leftover("/std/leftover", ({ "zab", "zeba", "zebowi", "zab",
	    "zebem", "zebie" }), ({ "zeby", "zebow", "zebom", "zeby", "zebami",
	    "zebach" }), PL_MESKI_NOS_NZYW, random(5) + 1, 0, 1, 0);
	  
    if (!random(5))
	add_leftover("/std/leftover", ({ "czaszka", "czaszki", "czaszce", 
	    "czaszke", "czaszka", "czaszce" }), ({ "czaszki", "czaszek",
	    "czaszkom", "czaszki", "czaszkami", "czaszkach" }), PL_ZENSKI,
	    1, 0, 1, 1);
    if (!random(5))
	add_leftover("/std/leftover", ({ "kosc", "kosci", "kosci", "kosc",
	    "koscia", "kosci" }), ({ "kosci", "kosci", "kosciom", "kosci", 
	    "koscmi", "kosciach" }), PL_ZENSKI, 2, 0, 1, 1);
	    
    if (!random(5))
        add_leftover("/std/leftover", ({ "rzepka", "rzepki", "rzepce",
            "rzepke", "rzepka", "rzepce" }), ({ "rzepki", "rzepek", 
            "rzepkom", "rzepki", "rzepkami", "rzepkach" }), PL_ZENSKI, 
            2, 0, 1, 1);
            
    if (!random(5))
	add_leftover("/std/leftover", ({ "lopatka", "lopatki", "lopatce",
	    "lopatke", "lopatka", "lopatce" }), ({ "lopatki", "lopatek", 
	    "lopatkom", "lopatki", "lopatkami", "lopatkach" }), 
	    PL_ZENSKI, 2, 0, 1, 1);
	    
    if (query_prop(LIVE_I_UNDEAD))
    {
	create_npc();
	return;
    }
    if (!random(5))
        add_leftover("/std/leftover", ({ "ucho", "ucha", "uchu", "ucho",
            "uchem", "uchu" }), ({ "uszy", "uszu", "uszom", "uszy", 
            "uszami", "uszach" }), PL_NIJAKI_OS, 2, 0, 0, 0);
    if (!random(5))
        add_leftover("/std/leftover", ({ "skalp", "skalpu", "skalpowi", 
            "skalp", "skalpem", "skalpie" }), ({ "skalpy", "skalpow",
            "skalpom", "skalpy", "skalpami", "skalpach" }), PL_MESKI_NOS_NZYW,
            1, 0, 0, 1);
    if (!random(5))
        add_leftover("/std/leftover", ({ "paznokiec", "paznokcia",
            "paznokciowi", "paznokiec", "paznokciem", "paznokciu" }), 
            ({ "paznokcie", "paznokci", "paznokciom", "paznokcie",
            "paznokciami", "paznokciach" }), PL_MESKI_NOS_NZYW, 
            random(5) + 1, 0, 0, 0);
    if (!random(5))
	add_leftover("/std/leftover", ({ "serce", "serca", "sercu", "serce",
	    "sercem", "sercu" }), ({ "serca", "serc", "sercom", "serca",
	    "sercami", "sercach" }), PL_NIJAKI_NOS, 1, 0, 0, 1);
    if (!random(5))
	add_leftover("/std/leftover", ({ "nos", "nosa", "nosowi", "nos",
	    "nosem", "nosie" }), ({ "nosy", "nosow", "nosom", "nosy",
	    "nosami", "nosach" }), PL_NIJAKI_NOS, 1, 0, 0, 0);
    if (!random(5))
	add_leftover("/std/leftover", ({ "nerka", "nerki", "nerce", "nerke",
	    "nerka", "nerce" }), ({ "nerki", "nerek", "nerkom", "nerki",
	    "nerkami", "nerkach" }), PL_ZENSKI, 2, 0, 0, 1);
    add_leftover("/std/leftover", ({ "oko", "oka", "oku", "oko", "okiem",
        "oku" }), ({ "oczy", "oczu", "oczom", "oczy", "oczami", "oczach" }),
        PL_NIJAKI_OS, 2, 0, 0, 0);
    create_npc(); 
}

void
reset_npc() 
{  
    ::reset_creature(); 
}

nomask void
reset_creature() 
{ 
    reset_npc(); 
}

/*
 * Description:  Use the combat file for generic tools
 */
public string 
query_combat_file() 
{
    return "/std/combat/ctool"; 
}

/*
 * Function name:  default_config_npc
 * Description:    Sets all neccessary values for this npc to function
 */
varargs public void
default_config_npc(int lvl)
{
    default_config_creature(lvl);
}
