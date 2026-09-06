inherit "/basic/id";

#include <alltime_cmds.h>
#include <player_defs.h>
#include <room_defs.h>

object temproom;
int cnt;

int
fake_death(object tp, int count)
{
    string str;
    int    wait;

    wait = 5;
    switch (count) {
    case 0: str = "\nYou die.\n\
You have a strange feeling.\n\
You can see your own dead body from above.";
	wait = 4;
	break;

    case 1: str =
	"\nYou can see a hooded skeletal figure standing beside your corpse. He is \
wiping the bloody blade of a wicked looking scythe with slow measured \
motions. Suddenly he stops and seems to look straight at you with his \
empty...no, not empty but.... orbs....";
	wait = 4;
	break;

    case 2: str =
	"\nDeath says: COME WITH ME, MORTAL ONE!";
	wait = 3;
	break;

    case 3: str =
	"\nHe reaches for you and suddenly you find yourself in another place.";
	wait = 6;
	break;

    case 4:
	str = "\nDeath says: Cheer up, " +
	capitalize((string)environment()->query_real_name()) +
	". You know what they say.";
	wait = 4;
	break;

    case 5:
	str = "\nDeath says: Some things in life are bad,\n\
\tThey can really make you mad.\n\
\tOther things just make you swear and curse.";
	wait = 4;
	break;

    case 6:
	str = "\nDeath says: When you're chewing on life's gristle,\n\
\tDon't grumble, give a whistle!\n\
\tAnd this'll help things turn out for the best...";
	wait = 4;
	break;

    case 7:
	str = "\nDeath says: And...\n\n\
(a music starts to play)";
	wait = 4;
	break;

    case 8:
	str = "\nDeath sings: Always look on the bright side of life!";
	wait = 4;
	break;

    case 9:
	str = "\nDeath whistles a happy tune.";
	wait = 2;
	break;

    case 10:
	str = "\nDeath sings: Always look on the bright side of life!";
	wait = 3;
	break;

    case 11:
	str = "\nDeath sings: If life seems jolly rotten,\n\
\tThere's something you've forgotten!\n\
\tAnd that's to laugh and smile and dance and sing,";
	wait = 4;
	break;

    case 12:
	str = "\nDeath sings: When you're feeling in the dumps,\n\
\tDon't be silly chumps,\n\
\tJust purse your lips and whistle -- that's the thing!";
	wait = 4;
	break;

    case 13:
	str = "\nDeath sings: And... always look on the bright side of life...";
	wait = 4;
	break;

    case 14:
	str = "\nDeath whistles a happy tune.";
	wait = 2;
	break;

    case 15:
	str = "\nDeath yells: Come on!";
	wait = 2;
	break;

    case 16:
	str = "\nA choir of skeletons arrives and joins in the song!";
	wait = 2;
	break;

    case 17:
	str = "\nDeath (and the skeletal choir) sing: Always look on the bright side of life!";
	wait = 4;
	break;

    case 18:
	str = "\nDeath whistles a happy tune.";
	wait = 3;
	break;

    case 19:
	str = "\nDeath sings: For life is quite absurd,\n\
\tAnd death's the final word.\n\
\tYou must always face the curtain with a bow!";
	wait = 2;
	break;

    case 20:
	str = "\nDeath bows to the audience.";
	wait = 2;
	break;

    case 21:
	str = "\nDeath sings: Forget about your sin -- give the audience a grin,\n\
\tEnjoy it -- it's the last chance anyhow!";
	wait = 2;
	break;

    case 22:
	str = "\nDeath grins broadly.";
	wait = 2;
	break;

    case 23:
	str = "\nDeath sings: So always look on the bright side of death!\n\
\tJust before you draw your terminal breath.";
	wait = 4;
	break;

    case 24:
	str = "\nDeath sings: Life's a piece of shit,\n\
\tWhen you look at it.";
	wait = 4;
	break;

    case 25:
	str = "\nDeath sings: Life's a laugh and death's a joke, it's true,\n\
\tYou'll see it's all a show,\n\
\tKeep 'em laughing as you go.";
	wait = 2;
	break;

    case 26:
	str = "\nDeath falls down laughing.";
	wait = 2;
	break;

    case 27:
	str = "\nDeath sings: Just remember that the last laugh is on you!";
	wait = 3;
	break;

    case 28:
	str = "\nDeath (and the skeletal choir) sing: And always look \
on the bright side of life...";
	wait = 4;
	break;

    case 29:
	str = "\nDeath whistles a happy tune.";
	wait = 3;
	break;

    case 30:
	str = "\nDeath (and the skeletal choir) sing: Always look \
on the bright side of life!";
	wait = 4;
	break;

    case 31:
	str = "\nDeath whistles a happy tune.";
	wait = 3;
	break;

    case 32:
	str = "\nDeath (and the skeletal choir) sing: Always look \
on the bright side of life! (the voice begins to fade away...)";
	wait = 4;
	break;

    case 33:
	str = "\nDeath whistles a happy tune. (fading...)";
	wait = 3;
	break;

    case 34:
	str = "\nYou still hear Death singing: Always look \
on the bright side of life...";
	wait = 4;
	break;

    case 35:
	str = "\nThe song fades away, and everything goes black...";
	wait = 4;
	break;

    case 36:
	str = "\nYou became solid again!";
	wait = 3;
	break;

    case 37:
	tp->tell_me("\nYou are transferred elsewhere...");
	tp->move_player("X","/room/church");
	/* no break */

    default:
	if (temproom) destruct(temproom);
	return -1;
    }

    if (str)
	tp -> tell_me(str + "\n");

    return wait;
}

void
temproom()
{
    if (temproom) return 0;

    temproom = clone_object("/lib/room");
    temproom->set_short("Death's workroom");
    temproom->set_long(
      "A dark room lighted with a dark light that seems to defy darkness not \
so much by actually illuminating the room as by being a darkpoint in \
less dark surroundings. In the strange light (dark?) you can see a \
desk, placed in center, covered with books and diagrams. The walls \
are covered with bookshelves filled with dark tomes bound in leather \
that gleam with strange runes.");
    temproom->set_light_level(LT_LIGHTS);
    temproom->set(ROOM_WD, WD_NONE);
    temproom->set(ROOM_PREVENT_WHERE);
    temproom->set(PREVENT_TELEPORT);
    temproom->set(PREVENT_SHOUT);
    move_object(environment(), temproom);
}

void
create()
{
    set_name("fake death");
    set_short("Fake death");
    set_long(
      "This object fakes a death sequence where Death sings 'Always look \
at the bright side of life'. You must be a coder, because you can \
see this. Just 'dest fakedeath' if you want to stop it.");  
    set_id(({ "fakedeath", "fake" }));
}

int get() { return 1; }
int drop() { return 1; }

void
deathloop()
{
    int c;

    c = fake_death(environment(), cnt);

    if (c == -1)
    {
	destruct(this_object());
	return;
    }

    cnt++;

    call_out("deathloop", c);
}

void
init()
{
    object ob;

    ob = this_player();
    if (!living(environment()) || environment() != ob) return;
    if (!temproom) temproom();
    add_action("filter", "", 1);
    cnt = 0;
    call_out("deathloop", 1);
}

status
filter(string arg)
{
    if (member(ALLTIME_CMDS, query_verb()) != -1) return 0;
    notify_fail("Not now.\n");
    if (this_player()->query_coder_level()) return 0;
    return 1;
}
