/* /lib/weapon_server.c */

/*
 * Server which "sells" weapons.
 *
 * Notes:
 *
 * Players must not simply find wc 20 stuff lying on the floor!
 * Read the weapon documents!
 *
 */

mixed *weapons;
int array_size;

#include <weapon_defs.h>
/* Weapon name */
#define WEP_NAME                0
/* Weapon type */
#define WEP_WT	 		1
/* Damage type */
#define WEP_DT			2
/* Hand(s) */
#define WEP_HANDS		3
/* Weapon class */
#define WEP_WC			4
/* Weight */
#define WEP_WEIGHT		5
/* Value */
#define WEP_COST		6

/* Number of elements in a single weapon */
#define CELL_SIZE		7

/***************/
/* These defines should be in /include/weapon.h or something... */

/* One- or two-handed? (or three?) */
#define W_ONEH		0
#define W_TWOH		1

/* CD-like weapon types */
#define W_SWORD		0
#define W_KNIFE		1
#define W_CLUB		2
#define W_AXE		3
#define W_LANCE		4
#define W_POLEARM	5
#define W_STAFF		6
#define W_SPEAR		7
#define W_WHIP		8
#define W_THROWN	20
#define W_BOW		21
#define W_CROSSBOW	22
#define W_SLING		23

/* Weapon damage types */
#define W_IMPALE	0
#define W_SLASH		1
#define W_BLUDGEON	2

public void
create()
{

    weapons = ({

      "ball and chain",	W_CLUB,W_BLUDGEON,W_ONEH,	12, 6, 600,
      "bastard sword",	W_SWORD,W_SLASH,W_ONEH,		17, 8, 3000,
      "battle axe",	W_AXE,W_SLASH,W_TWOH,		15, 8, 1500,
      "beaked axe",	W_AXE,W_SLASH,W_TWOH,		17, 8, 3000,
      "broad axe",		W_AXE,W_SLASH,W_TWOH,		16, 8, 2000,
      "broad sword",	W_SWORD,W_SLASH,W_ONEH,		17, 7, 3000,
      "cat-o-nine tails",	W_WHIP,W_SLASH,W_ONEH,		7, 3, 150,
      "claymore",		W_SWORD,W_SLASH,W_TWOH,		19, 10, 3500,
      "club",		W_CLUB,W_BLUDGEON,W_ONEH,	5, 3, 90,
      "cutlass",		W_SWORD,W_SLASH,W_ONEH,		12, 5, 600,
      "dagger",		W_KNIFE,W_IMPALE,W_ONEH,	5, 1, 100,
      "dirk",		W_KNIFE,W_IMPALE,W_ONEH,	4, 1, 90,
      "elven long sword",	W_SWORD,W_IMPALE,W_ONEH,	15, 5, 1500,
      "elven short sword",	W_SWORD,W_SLASH,W_ONEH,		12, 3, 700,
      "falchion",		W_SWORD,W_SLASH,W_ONEH,		12, 5, 600,
      "flail",		W_CLUB,W_BLUDGEON,W_ONEH,	12, 6, 600,
      "foil",		W_KNIFE,W_IMPALE,W_ONEH,	4, 1, 50,
      "hand axe",		W_AXE,W_SLASH,W_ONEH,		5, 2, 100,
      "heavy bastard sword",W_SWORD,W_SLASH,W_TWOH,	20, 12, 3000,
      "knife",		W_KNIFE,W_IMPALE,W_ONEH,	4, 1, 100,
      "lance",		W_LANCE,W_IMPALE,W_TWOH,	15, 8, 1500,
      "lead filled mace",	W_CLUB,W_BLUDGEON,W_TWOH,	15, 7, 1500,
      "long sword",	W_SWORD,W_SLASH,W_ONEH,		15, 6, 1500,
      "mace",		W_CLUB,W_BLUDGEON,W_ONEH,	14, 6, 1200,
      "mithril sword",	W_SWORD,W_SLASH,W_ONEH,		16, 4, 2000,
      "morning star",	W_CLUB,W_BLUDGEON,W_ONEH,	12, 6, 600,
      "pick-axe",		W_AXE,W_SLASH,W_ONEH,		6, 2, 100,
      "quarterstaff",	W_STAFF,W_BLUDGEON,W_TWOH,	8, 3, 150,
      "rapier",		W_SWORD,W_IMPALE,W_ONEH,	11, 4, 400,
      "sabre",		W_SWORD,W_SLASH,W_ONEH,		12, 5, 600,
      "scimitar",		W_SWORD,W_SLASH,W_ONEH,		13, 5, 1000,
      "scythe",		W_POLEARM,W_SLASH,W_TWOH,	10, 5, 300,
      "short sword",	W_SWORD,W_IMPALE,W_ONEH,	10, 3, 400,
      "spear",		W_SPEAR,W_IMPALE,W_ONEH,	8, 4, 250,
      "trident",		W_POLEARM,W_IMPALE,W_ONEH,	7, 4, 150,
      "two handed great flail",
      W_CLUB,W_BLUDGEON,W_TWOH,	20, 12, 3500,
      "two handed sword",	W_SWORD,W_SLASH,W_TWOH,		19, 10, 3000,
      "two handed war hammer",
      W_CLUB,W_BLUDGEON,W_TWOH,	19, 11, 3000,
      "war hammer",	W_CLUB,W_BLUDGEON,W_ONEH,	12, 5, 600,
      "whip",		W_WHIP,W_SLASH,W_ONEH,		6, 3, 100,

      /* Not all polearms. They aren't so good with the simple battle system. */

      "halberd",           W_POLEARM,W_SLASH,W_TWOH,       17, 12, 3000,
      "pike",              W_POLEARM,W_IMPALE,W_TWOH,      15, 11, 1500,

#if 0
      "awl pike",		W_POLEARM,W_IMPALE,W_TWOH,	14,  9, 3700,
      "bardiche",		W_POLEARM,W_SLASH,W_TWOH,	14, 10, 3100,
      "bec de corbin",	W_POLEARM,W_IMPALE,W_TWOH,	14, 11, 2900,
      "bill-guisarme",	W_POLEARM,W_IMPALE,W_TWOH,	14, 10, 2900,
      "fauchard",		W_POLEARM,W_SLASH,W_TWOH,	14, 10, 3100,
      "glaive",		W_POLEARM,W_IMPALE,W_TWOH,	14, 10, 3200,
      "guisarme",		W_POLEARM,W_SLASH,W_TWOH,	15, 13, 4000,
      "lucern hammer",	W_POLEARM,W_IMPALE,W_TWOH,	13,  9, 2400,
      "partisan",		W_POLEARM,W_IMPALE,W_TWOH,	14, 10, 3000,
      "ranseur",		W_POLEARM,W_IMPALE,W_TWOH,	14, 10, 3000,
      "spetum",		W_POLEARM,W_IMPALE,W_TWOH,	13,  9, 2400,
      "voulge",		W_POLEARM,W_SLASH,W_TWOH,	12,  8, 2100,
#endif

      /* Not yet available */
#if 0
      /* Hurled weapons and missile weapons - how these
       * can be used? One engages in melee and others
       * use missiles? */

      /* Bows & crossbows are blunt weapons - if used in melee */

      "bola",		W_THROWN,W_BLUDGEON,W_ONEH,	1, 5, 0,
      "boomerang",		W_THROWN,W_BLUDGEON,W_ONEH,	1, 5, 0,
      "composite bow",	W_BOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "crossbow",		W_CROSSBOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "dart",		W_THROWN,W_IMPALE,W_ONEH,	1, 5, 0,
      "elven bow",		W_BOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "harpoon",		W_THROWN,W_IMPALE,W_ONEH,	1, 5, 0,
      "heavy crossbow",	W_CROSSBOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "javelin",		W_THROWN,W_IMPALE,W_ONEH,	1, 5, 0,
      "long bow",		W_BOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "orcish bow",	W_BOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "short bow",		W_BOW,W_BLUDGEON,W_TWOH,	1, 5, 0,
      "sling",		W_SLING,W_BLUDGEON,W_TWOH,	1, 5, 0,
#endif

    });

    array_size = sizeof(weapons);
}

/*
 * Function name: make_weapon
 * Description  : generate a standard weapon
 * Arguments    : n, weapon's full name
 * Returns      : /obj/weapon object: or 0 if failed
 */
public object
make_weapon(string n)
{
    int x;
    object wep;
    string *id_kludge;

    if(!n || n == "") return 0;

    n = lower_case(n);

    x = member(weapons, n);

    if(x < 0) return 0;

    wep = clone_object(WEAPON_FILE);
    wep->set_name(n);
    wep->set_short(n);
    wep->set_long("It is a rather typical " + n + ".");
    wep->set_wc(weapons[x + WEP_WC]);

    wep->set_value((weapons[x + WEP_COST] * 2) / 3);

    wep->set_weight(weapons[x + WEP_WEIGHT]); /* This was missing! //Elena */

    if (weapons[x + WEP_HANDS] == W_TWOH)
	wep -> set(WP_TWO_HANDED);

    if (weapons[x + WEP_DT] == W_BLUDGEON)
	wep -> set(WP_BLUNT);

    /* Using now the new id system. Great! */
    wep->set_id(explode(n + " "," "));

#if 0
    /* Kludge some id's for the weapons - 2.4.5 shitty mode */

    id_kludge = explode(n + " "," ");
    wep->set_id(id_kludge[sizeof(id_kludge) - 1]);
    if(sizeof(id_kludge) > 1) wep->set_id(id_kludge[0]);
#endif

    return wep;
}

/*
 * Function name: make_random_weapon
 * Description  : generate a random weapon
 * Arguments    : max_wc: maximum wc generated (at least 5), default 11
 * Returns      : /obj/weapon object: 0 if failed
 * Notes        : do not generate too good weapons in wrong places!
 *		  This may return 0: it has to be checked
 */ 
public object
make_random_weapon(int max_wc)
{
    int x,tries;

    if(max_wc < 5) max_wc = 11;

    tries = 50;

    do {
	x = random(array_size / CELL_SIZE) * CELL_SIZE;
	tries--;
    } while(weapons[x + WEP_WC] > max_wc && tries > 0);

    if(tries < 1) return 0;

    return make_weapon(weapons[x + WEP_NAME]);
}

/*
 * Function name: list_weapons
 * Description  : List the possible weapons of the server. Coders only!
 * Arguments    : none
 * Returns      : 0 or 1
 * Notes        : This can be used like a command.
 */
public int
list_weapons()
{
    int i;

    if(!this_player()->query_coder_level()) {
	notify_fail("You are not allowed to do this!\n");
	return 0;
    }

    write("The weapons cannot be listed yet - read the source code.\n");
    return 1;
}
