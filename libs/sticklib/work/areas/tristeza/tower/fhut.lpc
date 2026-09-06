/* fortune teller's hut. the fortune teller herself is not actually a living */
/* being but rather emulated by the room; she can't be killed nor attacked */
/* agaist. one set of three (3) cards costs 100 000 (one hundred thousand) */
/* gold pieces. you can quit picking at any time -- that is, if you still */
/* live. */
/* */
/* starbyt 151093 */

#include <room.h>

mapping cards;
int card_count;

void
create_room()
{
    set_short ("inside hut");
    set_long ("Inside a dark, small wooden hut. The dim light comes from "+
      "eerie mist so thick it's hard to see the walls; only a brighter opening "+
      "indicate a doorway out. Opposite the opening is a heavy wooden table and "+
      "behind the table sits an old gypsy woman.");
    add_item ("mist", "Eerie mist fills the air, making the scene look "+
      "rather scary.");
    add_item (({"walls","doorway","door","opening"}),
      "You can't really spot the walls, but a brighter light "+
      "in one direction indicates a doorway out.");
    add_item ("table", "A fine and heavy wooden table.");
    add_item (({"woman", "gypsy", "old woman", "gypsy woman"}),
      "Behind the table sits an old gypsy woman, dressed in "+
      "colourful clothes. The way she looks at you makes you "+
      "shiver.");
    set_light_level (LT_LIGHTS);
    add_exit ("out", "/room/tower/out_there_somewhere");

    cards = ([
      "sun": "a symbolic golden sun",
      "moon": "a symbolc silver moon",
      "star": "a symbolic silver star",
      "comet": "a symbolic golden comet",
      "throne": "a wealthy throne",
      "key": "a golden key",
      "knight": "a knight in full armour on a horse",
      "gem": "a colourful gem",
      "the void": "nothing but black",
      "flames": "lot of flames",
      "skull": "a grinning skull",
      "talons": "?????",               /* ???? */
      "ruin": "a ruin of a castle",
      "euryale": "a woman face, snakes as hair",              /* ???? */
      "rogue": "a rogue with a dagger",
      "balance": "balanced scales",
      "jester": "a juggling jester",
      "fool": "?????",                 /* ???? */
      "vizier": "a wizard with a crystal ball",
      "idiot": "?????",                /* ???? */
      "fates": "?????",                /* ???? */
      "donjon": "a skeleton hanging on the wall" ]);
}

void
init_room()
{
    add_action ("my_give", "give");
}

#define AM_INVIS this_player()->query_invis()
#define MYNAME (string)this_player()->query_name()
#define TELLROOM(s) tell_room(this_object(),s)
#define TELLPLAYER(s) write(s)
#define TELLOTHERS(s) tell_room(this_object(),s,({this_player()}))

int
my_give (string what)
{
    int amount;
    if (!what || (sscanf (what, "%d coins to %s", amount, what) != 2))
	return 0;
    if (AM_INVIS) { TELLPLAYER ("Gypsy whispers: Please, be visible.\n");
	return 1; }
    if (amount < 100000) {
	/* ehh.. tell_room */
	TELLPLAYER ("As you are about to hand the coins to the gypsy woman, "+
	  "she says: ");
	TELLOTHERS ("The gypsy looks at "+MYNAME+" and says: ");
	TELLROOM ("hundred times thousand coins, that is the price.\n");
	return 1;
    }
    /* inform and get money out of player */
    /* or maybe some item that need to be get from elsewhere ??? */

    card_count = 1;
    add_action ("pick_card", "pick");
    return 1;
}

int
pick_card(string arg)
{
    int card;
    string *names;

    if (arg && arg != "card" && arg != "a card")
	return 0;

    names = m_indices(cards);
    card = random(sizeof(names));

    TELLOTHERS (MYNAME + " picks a card from the gypsy's deck.\n");
    TELLPLAYER ("You pick a card. On the card is "+cards[names[card]]+".\n");

    switch (names[card]) {
    case "sun": TELLPLAYER("magic item and major experience"); break;
    case "moon": TELLPLAYER("d4 wishes?"); break;
    case "star": TELLPLAYER("2 points of major ability"); break;
    case "comet": TELLPLAYER("defeat next monster"); break;
    case "throne": TELLPLAYER("cha 18 and a small keep? lordcastle?"); break;
    case "key": TELLPLAYER("a treasuremap and a magic weapon?"); break;
    case "knight": TELLPLAYER("a fighter servant"); break;
    case "gem": TELLPLAYER("jewels and gems"); break;
    case "void": TELLPLAYER("soul trapped- no more command passthru:-)");break;
    case "flames": TELLPLAYER("emmity between you and a devil"); break;
    case "skull": TELLPLAYER("defeat Death or be forever destroyed"); break;
    case "talons": TELLPLAYER("all magic items are torn from you"); break;
    case "ruin": TELLPLAYER("bye bye money and castle and bank account");break;
    case "euryale": TELLPLAYER("turn to stone? (orig:-saves to petrif.");break;
    case "rogue": TELLPLAYER("henchmen turns against you.?"); break;
    case "balance": TELLPLAYER("change alignment or be judged?"); break;
    case "jester": TELLPLAYER("minor exp or 2 extra draws"); break;
    case "fool": TELLPLAYER("minor exp loss, draw again"); break;
    case "vizier": TELLPLAYER("know answer to your next dilemma??"); break;
    case "idiot": TELLPLAYER("int----, extra draw"); break;
    case "fates": TELLPLAYER("avoid any situation..once. lifesaving?"); break;
    case "donjon": TELLPLAYER("imprisonement, ha ha"); break;
    default: TELLPLAYER("error..error..error"); break;
    }
    return 1;
}
