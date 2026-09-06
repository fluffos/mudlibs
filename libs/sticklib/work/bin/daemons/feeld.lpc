/****************************************************************
*								*
* Module:							*
*	/bin/daemons/feeld.c					*
* Description:							*
*	Centralized daemon that handles all 'feelings', ie.	*
*	commands related to social activities such as "smile",	*
*	"frown", "slap" and such. Called by living objects,	*
*	players or NPCs. For player objects the call is		*
*	done by module /basic/player/command_driver.c.		*
* Version:							*
*	1.0a (for StickLib), Aug-98				*
* Last update:							*
*	04-Sep-98 by Doomdark					*
*								'
* Modifications:						*
*								*
****************************************************************/



#include <daemons.h>
#include <coder_levels.h>
#include <gender.h>
#include <guild.h>
#include <room_defs.h>
#define TP this_player()
#define MY_NAME ((string)this_player()->query_name())
#define MY_OBJ      ((string)this_player()->Objective())
#define MY_PRON     ((string)this_player()->Pronoun())
#define MY_POSS       ((string)this_player()->Possessive())
#define TELL_HERE(x,y)  environment(this_player())->tell_here(x,y)
#define TELL_ME(x)      this_player()->tell_me(x)
#define NAME(x) ((string)x->query_name(0, this_player()))

string tar_name, my_name, *feels;
// NEW! Now we can catch feelings from other objects (namely, rooms) too.
object *catch_objects;
// NEW: We'll use closures here too. -+ Doomdark the Closure +-
closure *feel_funcs;

void
reset()
{
    if (catch_objects)
	catch_objects -= ({ 0 });
}

void
call_catch(object who, string what, object to_whom)
{
    object x;

    if (to_whom) to_whom->catch_feeling(who, what, to_whom);
    if (environment(who) &&
      member(catch_objects, environment(who)) >= 0)
	environment(who)->catch_feeling(who, what, to_whom);
}

// With this, we can catch feelings; there are two possibilities:
// a) We want to catch all feelings used inside an object (ie.,
//     in some room) or
// b) We want to catch all feelings by certain player, and report them to
//    given object.
void
add_catch_feeling(object whos_feeling, object to_whom)
{
    if (!whos_feeling) { // All feelings in a room then!
	if (member(catch_objects, to_whom) < 0)
	    catch_objects += ({ to_whom });
    } else {
	// Nothing yet!
    }
}

nomask status query_prevent_shadow() { return 1; }

status
ghost()
{
    if (TP->query_ghost()) {
	notify_fail("You can't do that, being in your immaterial state.\n");
	return 1;
    }

    return 0;
}

// second argument 1 means that this_player is a valid target

varargs object
find_target(string str, status flag)
{
    object who;

    if (!str) return 0;

    str = lower_case(str);

    if (flag && (str == "me" || str == "myself"))
	who = TP;
    else if(!who = present(str, environment(TP)))
	who = present(str, TP);

    if (who == TP && !flag) return 0;

    if (who) {
	if (!(tar_name = (string) who -> query_name(0, TP)))
	    tar_name = living(who) ? "Someone" : "something";
	if (living(who)  ||  who->catch_feeling(query_verb(), str)) {
	    my_name = MY_NAME;
	    return who;
	}
	else return notify_fail(
	      "Are you silly? Trying to "+query_verb()+" "+tar_name+"?\n"), 0;
    }

    return notify_fail("You can't see any \""+str+"\" here.\n"), 0;
}

void
create()
{
    int i;

    catch_objects = ({ });
    feels = ({
      "applaud","apuva","asslick","bark",
      "bite","blush","bounce","bow","burp",
      "cackle","cheer","chuckle","clap","comfort","complain",
      "cough","cry","cuddle",
      "curtsey","caress",
      "dance",
      "eyeroll","eye",
      "fart","flip","fondle","french", "frown",
      "gasp","giggle","glare","gloomy",
      "gnarl",
      "grin","groan","grope","growl",
      "hiccup","howl","hug","hungry",
      "hmm",
      "kick","kiss","knee",
      "laugh","lick","love","lag",
      "massage", "moan",
      "nibble", "nod","nope", "nudge",
      "panic","poke","pout","puke","purr","pace","ponder",
      "ruffle",
      "scream","shake","steam","shiver", "shrug","sigh","sing","slap",
      "smirk","smile","snap","snarl",
      "sneeze","snicker","sniff","snore","snort",
      "snuggle","sob","spit","squeeze","stare","stretch",
      "strut","sulk", "swear","scratch",
      "thank","thirsty",
      "twiddle","tremble","tickle",
      "uraa","whine",
      "whistle","wiggle","wink",
      "yawn","yodel",

      /* Frobozz's magic ones */
      "agree","aggressive","anxious",
      "confused",
      "drool","disagree",
      "eyebrow","embarrassed",
      "faint",
      "grovel","goodbye","greedy",
      "horny","happy","handkiss",
      "innocent",
      "jealous",
      "point","pat",
      "sad","silly",
      "think","tap",
      "worry","wipe","worship",

      /* Cal's additions */
      "ayt",
      "beep","bobbit","bonk","bump",
      "crawl","cringe",
      "dementia","die","dizzy","doh","doomed",
      "grumble","grunt",
      "heh","hi5","hide",
      "idiot",
      "moon","muah",
      "nodnod",
      "pant","pick","pinch","punch",
      "quiver",
      "rage","raise","rotfl",
      "shh","sick","sleep","stomp","spank",
      "tongue",
      "yuck","yummy","yup",
      "xfiles",

      /* Tamarindo's additions! */
      "pimpslap",
    });

    feel_funcs = allocate(i = sizeof(feels));
    while (i--)
	feel_funcs[i] = symbol_function(feels[i], this_object());
}

string*
get_feelings()
{
    return feels;
}

// general feeling, not 'guns and roses' :-)

status
gnr(string m1, string m2)
{
    if (ghost()) return 0;
    TELL_ME(m1);
    TELL_HERE(MY_NAME + m2, this_player());
    return 1;
}


/*** Feelings' functions ***/

status
applaud()
{
    return gnr("You applaud wholeheartedly.",
      " gives a round of applause.");
    call_catch(TP, "applaud", 0);
    return 1;
}

status
apuva()
{
    return gnr("You shout: APU-VA!",
      " shouts: APU-VA!");
    call_catch(TP, "apuva", 0);
    return 1;
}

status
blush()
{
    return gnr("Your cheeks are burning.",
      " blushes.");
    call_catch(TP, "applaud", 0);
    return 1;
}

status
bounce()
{
    return gnr("B O I N G !!",
      " bounces around.");
    call_catch(TP, "bounce", 0);
    return 1;
}

status
bark()
{
    return gnr("Vouh! Vouh!",
      " barks: Vouh! Vouh!");
    call_catch(TP, "bark", 0);
    return 1;
}

status
bow(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) {
	gnr("You bow to your audience.",
	  " bows gracefully.");
	call_catch(TP, "bow", 0);
	return 1;
    }

    if (!(who = find_target(str,1))) return 0;

    if (who == TP) return gnr(
	  "You try to bow to yourself and hurt you back. OUCH!",
	  " looks hilarious while trying to bow to " + MY_OBJ + "self.");

    who -> tell_me(my_name + " bows before you.");
    TELL_ME(sprintf("You bow to %s.", tar_name));
    TELL_HERE(sprintf("%s bows to %s.", my_name, tar_name),
      ({ who, TP }));
    call_catch(TP, "bow", who);
    return 1;
}

int
burp()
{
    return gnr("Excuse yourself!"," burps rudely.");
}

int
cackle()
{
    return gnr("You cackle gleefully.",
      " throws " + MY_POSS + " head back and cackles with glee!");
}

int
chuckle()
{
    return gnr("You chuckle politely.",
      " chuckles politely.");
}

int
clap()
{
    return gnr("You clap briefly.",
      " claps.");
}

int
comfort(string str)
{
    object who;

    if (ghost()) return 0;

    if (!(who = find_target(str,1)))
	return notify_fail("Comfort who?\n"), 0;

    if(who == TP) return gnr("You comfort yourself, but it doesn't help.",
	  " tries to comfort " + MY_POSS + "self, but it doesn't \
seem to help much.");

    who -> tell_me(sprintf("%s comforts you.", my_name));
    TELL_ME(sprintf("You comfort %s.", tar_name));
    TELL_HERE(sprintf("%s comforts %s.", my_name, tar_name),
      ({ TP, who }));
    call_catch(TP, "comfort", who);
    return 1;
}

int
complain(string str)
{
    object who;

    if (ghost()) return 0;

    if (str && !(who = find_target(str,1)))
	return notify_fail("Complain at who?\n"), 0;

    if (!who || who == TP)
	return gnr("You complain loudly about everything!",
	  " complains loudly about all this!");

    who -> tell_me(sprintf("%s complains loudly to you!", my_name));
    TELL_ME(sprintf("You complain to %s!", tar_name));
    TELL_HERE(sprintf("%s complains to %s!", my_name, tar_name),
      ({ TP, who }));
    call_catch(TP, "complain", who);
    return 1;
}

int
cough()
{
    return gnr("Cover your mouth when you do that!",
      " coughs noisily.");
}

int
cry()
{
    return gnr("Waaaaah!",
      " bursts into tears.");
}

int
cuddle(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Cuddle who?\n"), 0;

    if (!(who = find_target(str))) return 0;

    who -> tell_me(sprintf("%s cuddles you.", my_name));

    TELL_ME(sprintf("You cuddle %s.", tar_name));
    TELL_HERE(sprintf("%s cuddles %s.", MY_NAME, tar_name),
      ({ TP, who }));
    call_catch(TP, "cuddle", who);

    return 1;
}

int
curtsey()
{
    return gnr("You curtsey gracefully.",
      " curtseys gracefully.");
}

int
dance(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("Feels silly, doesn't it?",
	  " does the disco duck.");

    if (!(who = find_target(str))) return 0;

    who->tell_me(sprintf("%s sweeps you across the dance floor.", my_name));
    TELL_ME(sprintf("You sweep %s across the dance floor.", tar_name));
    TELL_HERE(sprintf("%s sweeps %s across the dance floor.", my_name,
	tar_name), ({ TP, who }));
    call_catch(TP, "dance", who);
    return 1;
}

int
fart()
{
    return gnr("How rude!",
      " lets off a real rip-roarer.");
}

int
flip()
{
    return gnr("You flip head over heels.",
      " flips head over heels.");
}

int
fondle(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Fondle who?\n"), 0;
    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " fondles you.");
    TELL_ME(sprintf("You fondle %s.", tar_name));
    TELL_HERE(sprintf("%s fondles %s.", my_name, tar_name), ({ TP, who }));
    call_catch(TP, "fondle", who);
    return 1;
}

int
french(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("French who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " grabs you by your head, pulls you close \
and coaxes " + MY_POSS + " tongue into your mouth, intertwining it with yours \
in a slow, warm, passionate embrace.");
    TELL_ME("You grab " + tar_name + " by the head, pull close, and \
give " + tar_name + " a REAL FRENCH kiss.");
    TELL_HERE(my_name + " gives " + tar_name + " a deep and passionate \
kiss...it seems to take forever...",
      ({ who, TP }));

    return 1;
}

int
frown()
{
    return gnr("Is something wrong?",
      " frowns.");
}

int
gasp()
{
    if(random(3) < 2) return gnr("You gasp in astonishment.",
	  " gasps in astonishment!");
    return gnr("You gasp in utter astonishment.",
      " gasps in utter astonishment!");
}

int
giggle()
{
    if(random(4) < 3) return gnr("You giggle inanely.",
	  " giggles inanely.");
    return gnr("You giggle insanely.",
      " giggles insanely.");
}

int
glare(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Glare who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(sprintf("%s glares at you.", my_name));
    TELL_ME(sprintf("You glare stonily at %s.", tar_name));
    TELL_HERE(sprintf("%s glares at %s.", my_name, tar_name), ({ TP,who }));
    call_catch(TP, "glare", who);
    return 1;
}

int
gloomy()
{
    TELL_ME("You look gloomy.");
    TELL_HERE("Dark clouds begin to gather above " +
      (string)TP->query_name() + ".", ({ TP }));
    return 1;
}

int
grin()
{
    switch(random(3)) {
    case 0:
	return gnr("You grin broadly."," grins broadly.");
    case 1:
	return gnr("You grin widely."," grins widely.");
    default:
	return gnr("You grin evilly."," grins evilly.");
    }

    return gnr("You grin evilly."," grins evilly.");
}

int
groan()
{
    return gnr("You groan.",
      " groans loudly.");
}

int
grope(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Grope who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(sprintf("%s gropes you.", my_name));
    TELL_ME("(Well what sort of noise do you expect here anyway?)");
    TELL_HERE(sprintf("%s gropes %s.", my_name, tar_name), ({ TP,who }));
    call_catch(TP, "grope", who);
    return 1;
}

int
growl(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return gnr("You growl.",
	  " growls.");

    if(!(who = find_target(str))) return 0;
    who -> tell_me(sprintf("%s growls at you.", my_name));
    TELL_ME(sprintf("You growl at %s.", tar_name));
    TELL_HERE(sprintf("%s growls at %s.", my_name, tar_name), ({TP,who}));
    call_catch(TP, "growl", who);
    return 1;
}

int
hiccup()
{
    return gnr("Hic!",
      " hiccups.");
}

int
howl(string str)
{
    string phase;
    object who;

    if (ghost()) return 0;
    who = 0;
    if (str && !(who = find_target(str,1))) return 0;

    phase = (string)NATURE_D->query_malerana_phase();

    if (!who || who == TP)
	if ((int)environment(TP)->query(ROOM_WD) == WD_OUTDOORS)
	    return gnr("You howl at the " + phase + " Malerana.",
	      " howls at the " + phase + " Malerana.");
	else
	    return gnr("You howl.", " howls!");

    who -> tell_me(sprintf("%s howls at you!", my_name));
    TELL_ME(sprintf("You howl at %s!", tar_name));
    TELL_HERE(sprintf("%s howls at %s!", my_name, tar_name), ({ TP,who }));
    call_catch(TP, "howl", who);
    return 1;
}

int
hug(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Hug who?\n"), 0;
    if(!(who = find_target(str,1))) return 0;

    if(who == TP)
	return gnr("You feel lonely and hug yourself.",
	  " feels lonely and hugs " + MY_OBJ +"self.");

    who -> tell_me(sprintf("%s hugs you.", my_name));
    TELL_ME(sprintf("You hug %s.", tar_name));
    TELL_HERE(sprintf("%s hugs %s.", my_name, tar_name), ({ TP,who }));
    call_catch(TP, "hug", who);

    return 1;
}

int
hungry()
{
    return gnr("You are hungry!",
      "'s stomach grumbles.");
}

int
kick(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Kick who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " kicks you.   OUCH!!");
    TELL_ME("You kick " + tar_name + ".");
    TELL_HERE(my_name + " kicks " + tar_name + ".", ({ TP, who }));
    call_catch(TP, "kick", who);
    return 1;
}

int
kiss(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Kiss who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " kisses you.");
    TELL_ME("You kiss " + capitalize(str) + ".");
    TELL_HERE(my_name + " kisses " + tar_name + ".", ({ TP, who }));
    if (who -> query_frog())
	TP -> frog_curse(1);
    call_catch(TP, "kiss", who);
    return 1;
}

int
knee(string str)
{
    object who;
    string p;

    if (ghost()) return 0;
    if (!str) return notify_fail("Knee who?\n"), 0;
    if(!(who = find_target(str))) return 0;
    if ((int) who->query_gender() == G_MALE) {
	p = MY_POSS;
	who -> tell_me(my_name + " hits you with " + p + " knee below your belt!\n\
You double over and fall to the ground, writhing in excrutiating pain, feeling\
 like you may throw up everything you have eaten!");
	TELL_ME("You hit " + tar_name + " with your knee.");
	TELL_HERE(my_name + " suddenly raises " + p + " knee, sending "
	  + tar_name + " to the floor, writhing in pain!", ({ TP, who }));
    } else {
	who -> tell_me(my_name + " tries to knee you, without much effect.");
	TELL_ME("You try to knee " + tar_name + ". Not very effective though.");
	TELL_HERE(my_name + " tries to knee " + tar_name + ", without much effect.",
	  ({ TP, who }));
    }
    call_catch(TP, "knee", who);
    return 1;
}

int
laugh()
{
    if (ghost()) return 0;

    return gnr("You fall down laughing.",
      " falls down laughing.");
}

int
lick(string str)
{
    object who;
    string part;

    if (ghost()) return 0;
    if (!str) return notify_fail("Lick who?\n"), 0;

    if (!(who = find_target(str))) return 0;

    part = ({"fingers","hand","neck","face"})[random(4)];
    who -> tell_me(sprintf("%s licks your %s.", MY_NAME, part));
    TELL_ME(sprintf("You lick %s's %s.", tar_name, part));
    TELL_HERE(sprintf("%s licks %s's %s.", my_name, tar_name, part),
      ({ TP, who }));
    call_catch(TP, "lick", who);

    return 1;
}

int
asslick(string str)
{
    object who;
    string part;

    if (ghost()) return 0;
    if (!str) return notify_fail("Lick who?\n"), 0;

    if (!(who = find_target(str))) return 0;

    who -> tell_me(sprintf("%s licks your ass!", MY_NAME));
    TELL_ME(sprintf("You lick %s's ass! Your tongue gets brown!", tar_name));
    TELL_HERE(sprintf("%s licks %s's ass, getting %s tongue brown!.",
	my_name, tar_name, (string)TP->query_possessive()),
      ({ TP, who }));
    call_catch(TP, "asslick", who);

    return 1;
}

int
love(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Love who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(sprintf("%s whispers sweet words of love to you.",
	my_name));
    TELL_ME(sprintf("You tell your true feelings to %s.", tar_name));
    TELL_HERE(sprintf("%s whispers softly to %s.", my_name, tar_name),
      ({ TP, who }));
    call_catch(TP, "love", who);
    return 1;
}

int
moan()
{
    return gnr("You start to moan.",
      " starts moaning.");
}

int
nibble(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Nibble who?\n"),0;
    if(!(who = find_target(str))) return 0;

    who->tell_me(my_name + " nibbles on your ear.");
    TELL_ME("You nibble " + tar_name + "s ear.");
    TELL_HERE(my_name + " nibbles on " + tar_name + "s ear.", ({ TP, who }));
    return 1;
}

int
nod()
{
    int ret;
    ret = gnr("You nod solemnly.", " nods solemnly.");
    call_catch(TP, "nod", 0);
    return ret;
}

int
panic()
{
    return gnr("PANIC!!!!!",
      " panics, screams, and runs around in small circles!");
}

int
pimpslap(string str)
{
    object who;

    if (ghost())
	return 0;

    if (!str)
	return notify_fail("Pimpslap who?\n"), 0;

    if (!(who = find_target(lower_case(str))))
	return 0;

    who->tell_me(sprintf("%s pimpslaps you!  Are you gonna take that?!", my_name));
    TELL_ME(sprintf("You pimpslap %s!", tar_name));
    TELL_HERE(sprintf("%s pimpslaps %s!", my_name, tar_name), ({ TP, who }));
    call_catch(TP, "pimpslap", who);

    return 1;
}

int
poke(string str)
{
    object who;
    string how;

    if (ghost()) return 0;
    if (!str) return notify_fail("Poke who?\n"), 0;

    if(!(who = find_target(str))) return 0;

    switch (random(5)) {
    case 0: how = "deeply "; break;
    case 1: how = "sharply "; break;
    default: how = "";
    }

    who -> tell_me(sprintf("%s pokes you %sin the ribs.", my_name, how));
    TELL_ME(sprintf("You poke %s %sin the ribs.", tar_name, how));
    TELL_HERE(sprintf("%s pokes %s %sin the ribs.", my_name,
	tar_name, how), ({ TP, who }));
    call_catch(TP, "poke", who);
    return 1;
}

int
pout()
{
    return gnr("Ah, don't take it so hard.",
      " pouts.");
}

int
puke(string str)
{
    object who;
    string s;

    if (ghost()) return 0;
    if (!str) return gnr("You puke on your shoes.",
	  " doubles over and pukes.");

    if (sscanf(str, "on %s", s)) str = s;
    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " pukes all over you!");
    TELL_ME("You puke on " + tar_name +".");
    TELL_HERE(my_name + " pukes on " + tar_name + ".", ({ TP, who }));
    return 1;
}

int
purr()
{
    return gnr("PURRRRRRR!",
      // Was: "MMMMEEEEEEEEOOOOOOOWWWWWWW!",
      " purrs contentedly.");
}

int
ruffle(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Ruffle who?\n"), 0;
    if (!(who = find_target(str))) return 0;
    who->tell_me(my_name + " ruffles your hair playfully.");
    TELL_ME("You ruffle " + tar_name + "'s hair playfully.");
    TELL_HERE(my_name + " ruffles " + tar_name + "'s hair playfully.",
      ({ TP, who }));
    return 1;
}

int
scream()
{
    return gnr("ARRGGGGGGHHHHHH!!!!",
      " screams loudly!");
}

int
steam()
{
    return gnr("Steam comes boiling out of your ears.",
      "'s face turns purple and steam starts to boil out of " + MY_POSS
      + " ears.");
}

int
shake(string str)
{
    object who;

    if (ghost()) return 0;
    if(!str)
	return gnr("You shake your head.",
	  " shakes " + MY_POSS + " head.");
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " shakes your hand.");
    TELL_ME("You shake hands with " + tar_name +".");
    TELL_HERE(my_name + " shakes " + tar_name + "'s hand.", ({ TP, who }));
    return 1;
}

int
shiver()
{
    return gnr("Brrrrrr!!!"," shivers from the cold.");
}

int
shrug()
{
    return gnr("You shrug."," shrugs helplessly.");
}

int
sigh()
{
    return gnr("You sigh."," sighs deeply.");
}

int
sing()
{
    if (((int)environment(TP)->query(ROOM_WD) == WD_OUTDOORS) &&
      NATURE_D->query_rain())
    {
	if ((string)NATURE_D->Rain_Type() != "snow")
	    return gnr("You sing: I'M SIIIIINGING IN THE RAIN!!!! I'M \
SIIIIIIIINGIN IN THE RAIN! ...",
	      " is singing in the rain!");
	return gnr("You sing: SNOW, SNOW, SNOW, SNOW, SNOOOOOOOOOWWW...",
	  " is singing about snow!!!");
    }

    if (random(2)) return gnr("You sing: O sole mio!",
	  " sings in Italian.");
    return gnr("FEELINGS! NOTHING MORE THAN FEELINGS!",
      " sings loudly (and badly)!!!");
}

int
slap(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Slap who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " slaps you!");
    TELL_ME("You slap " + tar_name + ".");
    TELL_HERE(my_name + " slaps " + tar_name + ".", ({ TP, who }));
    return 1;
}

int
smirk()
{
    return gnr("You smirk.",
      " smirks.");
}

int
smile(string str)
{
    object who;

    if (ghost()) {
	TELL_ME("You smile inwardly.");
	return 1;
    }
    if (!str) return gnr("You smile happily.",
	  " smiles happily.");

    if(!(who = find_target(str))) return 0;
    who -> tell_me(my_name + " smiles at you.");
    TELL_ME("You smile at " + tar_name +".");
    TELL_HERE(my_name + " smiles at " + tar_name + ".", ({ TP, who }));
    return 1;
}

int
snarl(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return gnr("Grrrrrrrrrrr!",
	  " snarls! Grrrrrrrrr!");

    if(!(who = find_target(str))) return 0;
    who -> tell_me(my_name + " snarls at you!");
    TELL_ME("You snarl at " + tar_name + "!");
    TELL_HERE(my_name + " snarls at " + tar_name + "!", ({ TP, who }));
    return 1;
}

int
gnarl(string str)
{
    return snarl(str);
}

int
snap()
{
    return gnr("You snap your fingers.",
      " snaps " + MY_POSS + " fingers.");
}

int
sneeze()
{
    return gnr("Gezundheit!",
      " sneezes.");
}

int
snicker()
{
    return gnr("You snicker.",
      " snickers.");
}

int
sniff()
{
    return gnr("You sniff.",
      " sniffs.");
}

int
snore()
{
    return gnr("Zzzzzzzzzz...",
      " snores loudly.");
}

int
snort()
{
    return gnr("You snort. Oink oink!",
      " snorts: Oink oink!");
}


int
snuggle(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Snuggle who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " snuggles up to you.");
    TELL_ME("You snuggle " + tar_name + ".");
    TELL_HERE(my_name + " snuggles up to " + tar_name + ".", ({ TP, who }));
    return 1;
}

int
sob()
{
    return gnr("You sob. WAAAAAAAH!"," sobs. WAAAAAAAAH!");
}

int
spit(string str)
{
    object who;

    if (ghost()) return 0;
    if(!str) return gnr("PHTOOIE!",
	  " spits on the ground.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " spits on you!");
    TELL_ME("You spit on " + tar_name +".");
    TELL_HERE(my_name + " spits on " + tar_name + ".", ({ TP, who }));
    return 1;
}

int
squeeze(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Squeeze who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " squeezes you fondly.");
    TELL_ME("You squeeze " + tar_name + " fondly.");
    TELL_HERE(my_name + " squeezes " + tar_name + " fondly.", ({ TP, who }));

    return 1;
}

int
stare(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return gnr("You stare into space.",
	  " stares into space.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " stares deep into your eyes.");
    TELL_ME("You stare dreamily at " + tar_name +".");
    TELL_HERE(my_name + " stares dreamily at " + tar_name + ".", ({ TP, who }));

    return 1;
}

int
stretch()
{
    return gnr("You stretch your muscles.",
      " stretches " + MY_POSS + " muscles.");
}

int
strut()
{
    return gnr("Strut your stuff!"," struts proudly.");
}

int
sulk()
{
    return gnr("You sulk.",
      " sulks in the corner.");
}

int
thank(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Thank who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " thanks you.");
    TELL_ME("You thank " + tar_name + ".");
    TELL_HERE(my_name + " thanks " + tar_name + ".", ({ who, TP }));
    return 1;
}

int
thirsty()
{
    return gnr("You are thirsty!",
      " is very thirsty.");
}


int
tremble()
{
    return gnr("You're trembling in your boots.",
      " trembles and quivers like a bowlful of jelly.");
}

int
twiddle()
{
    return gnr("You twiddle your thumbs.",
      " twiddles " + MY_POSS + " thumbs.");
}

int
whistle(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return gnr("You whistle appreciatively.",
	  " whistles appreciatively.");

    if (!(who = find_target(str))) return 0;
    who -> tell_me(my_name + " whistles appreciatively at you.");
    TELL_ME("You whistle appreciatively at " + tar_name +".");
    TELL_HERE(my_name + " whistles appreciatively at " + tar_name + ".",
      ({ who, TP }));
    return 1;
}

int
wiggle()
{
    return gnr("You wiggle your bottom.",
      " wiggles " + MY_POSS + " bottom.");
}

int
wink(string str)
{
    object who;

    if (ghost()) return 0;
    if(!str) return gnr("You wink.",
	  " seems to have something in " + MY_POSS + " eye.");
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " winks suggestively at you.");
    TELL_ME("You wink at " + tar_name +".");
    TELL_HERE(my_name + " winks suggestively at " + tar_name + ".",
      ({ TP, who }));
    return 1;
}

int
yawn()
{
    return gnr("My, what big teeth you have!",
      " yawns.");
}

int
yodel()
{
    return gnr("Yodelii yodeluu!",
      " yodels a merry tune.");
}

/*** Frobozz's Magic feelings ***/
/* Now using find_target() */

int
eyebrow()
{
    return gnr("You raise your eyebrow.",
      " raises an eyebrow.");
}

int
anxious()
{
    return gnr("You feel extremely anxious.",
      " looks anxious.");
}

int
jealous()
{
    return gnr("You feel jealous.",
      " looks jealous.");
}

int
think()
{
    return gnr("You think hard but accomplish the usual - nothing.",
      " thinks hard.");
}

int
silly(string str)
{
    /* Simply silly //Graah */
    if (!str || str == "me") return gnr("You feel very silly.",
	  " looks very silly.");
    if (str != "walk") return notify_fail("Silly what?\n"), 0;
    return gnr("You silly walk around for a while.",
      " silly walks around.");
}

/* Note: wave <yyy> gives "Xxx waves goodbye to Yyy." */
int
goodbye()
{
    return gnr("You wave goodbye.",
      " waves goodbye.");
}

int
faint()
{
    return gnr("You faint.",
      " faints.");
}

int
happy()
{
    return gnr("You are happy.",
      " looks happy.");
}

int
aggressive()
{
    return gnr("You feel like killing someone!",
      " looks like wanting to kill someone.");
}

int
tap(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You tap your foot.",
	  " taps foot.");
    if (!(who = find_target(str))) return 0;

    who->tell_me(my_name+" taps you on your shoulder.");
    TELL_ME("You tap "+tar_name+" on shoulder.");
    TELL_HERE(my_name+" taps "+tar_name+" on shoulder.", ({ TP, who }));

    return 1;
}

int
point(string str)
{
    object ob;
    string dest,prep;
    int i;

    if (ghost()) return 0;
    if (!str) return notify_fail("Point what (or where)?\n"), 0;

    str = lower_case(str);
    my_name = MY_NAME;

    if (!(ob = present(str,environment(TP))))
	ob = present(str,TP);

    if (ob) {
	prep = "at ";
	if (living(ob)) str = capitalize(str);
    } else {
	if (!environment(this_player())->query_exit(str)) {
	    TELL_ME("You cannot point that.");
	    return 1;
	}
	prep = "";
    }
    if (ob && living(ob)) {
	ob -> tell_me(my_name + " points at you.");
	TELL_HERE(my_name + " points " + prep + capitalize(str) + ".",
	  ({ TP, ob }));
    } else TELL_HERE(my_name + " points " + prep + str + ".", TP);

    TELL_ME("You point " + prep + str + ".");
    return 1;
}

int
handkiss(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Handkiss who?\n"), 0;

    if (!(who = find_target(str))) return 0;

    who->tell_me(my_name+" kisses your hand.");
    TELL_ME("You kiss "+tar_name+" on hand.");
    TELL_HERE(my_name+" kisses "+tar_name+" on hand.",({ TP, who }));
    return 1;
}

int
worship(string str)
{
    object who;
    string p;

    if(ghost()) return 0;

    if (!str) {
	string god;

	// NEW! Different guilds have their own gods... :-) -+ Doomdark +-

	switch ((string) TP -> query_guild()) {
#ifdef GN_PRIEST
	case GN_PRIEST: god = "Boccob"; break;
#endif
#ifdef GN_THIEF
	case GN_THIEF:   god = "Skert"; break;
#endif
#ifdef GN_NINJA
	case GN_NINJA:   god = "Bruce Lee"; break;
#endif
#ifdef GN_MAGE
	case GN_MAGE:    god = "Hubba Bubba"; break;
#endif
#ifdef GN_NECROMANCER
	case GN_NECROMANCER: god = "Zombie God"; break;
#endif
#ifdef GN_FIGHTER
	case GN_FIGHTER: god = "Frobozz";
#endif
	default:    god = "'Ukko Ylijumala'";               // :-)
	    // (finnish, literally, "Old Man God", from Kalevala)
	}
	return gnr("You worship " + god + "."," worships " + god + ".");
    }

    if (!(who = find_target(str,1))) return 0;

    if (who == TP) return gnr("You try to worship yourself, but fail\
 miserably.", " tries to worship " + MY_OBJ + "self, but has no faith\
 and fails.");

    p = MY_POSS;
    who -> tell_me(my_name+" falls on " + p + " knees and worships you.");
    TELL_ME("You worship " + tar_name + ".");
    TELL_HERE(my_name + " falls on " + p + " knees and worships " +
      tar_name + ".", ({ TP, who }));
    return 1;
}

int
drool(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You drool all over the place.",
	  " drools all over the place.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name+" drools at you.");
    TELL_ME("You drool at "+tar_name+".");
    TELL_HERE(my_name+" drools at "+tar_name+".", ({ TP, who }));

    return 1;
}

int
grovel(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You grovel on the ground.",
	  " grovels on the ground.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " falls to the ground and grovels in front of you.");
    TELL_ME("You fall to the ground and grovel in front of " + tar_name + ".");
    TELL_HERE(my_name + " falls to the ground and grovels in front of "
      + tar_name + ".", ({ TP, who }));
    return 1;
}

int
horny(string str)
{
    object who;

    if(ghost()) return 0;

    if (!str) {
	my_name = (string) TP->query_name();
	if ((int) TP -> query_gender() == G_NEUTER) {
	    TELL_ME("You feel sudden urge to divide.");
	    TELL_HERE(my_name+" examines itself with keen interest.", TP);
	    return 1;
	} else {
	    TELL_ME("You suddenly have a strange urge for opposite gender's\
 presence.");
	    TELL_HERE(my_name+" looks horny.",TP);
	    return 1;
	}
    }

    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " looks hornily at you.");
    TELL_ME("You look at "+tar_name+" with keen interest.");
    TELL_HERE(my_name+" looks hornily at "+tar_name+".", ({ TP, who }));

    return 1;
}

int
pat(string str)
{
    object who;
    string p;
    int cl, wcl;

    if(ghost()) return 0;

    if (!(who = find_target(str,1))) return 0;

    if (who == TP) return gnr("You pat yourself on the head. It didn't help.",
	  " pats " + MY_OBJ + "self on the head.");

    cl = (int)TP->query_coder_level();
    wcl = (int)who->query_coder_level();

    // Apprentice coders are known for their great humility.
    // And humidity. On the back of their ears.
    if (who->is_npc()
      || (cl == LVL_APPRENTICE))
    {
	who->tell_me(my_name+" grovels before you for a pat on the head.");
	TELL_ME("You grovel before "+tar_name+" for a pat on the head.");
	TELL_HERE(my_name+" grovel before "+tar_name+" for a pat on " +
	  MY_POSS + " head.", ({ TP, who }));
    }
    else
    if (((wcl > cl)
	|| ((int) who->query_lord() > (int) TP->query_lord()))
      && (wcl != LVL_APPRENTICE))
    {
	p = (string) who->Pronoun();
	who->tell_me(my_name + " kneels in front of you for pat on \
the head.");
	TELL_ME("You kneel in front of " + tar_name + " and " +
	  p + " pats you on the head.");
	TELL_HERE(my_name + " kneels in front of " + tar_name + " and "
	  + p + " pats " + my_name +" on the head.", ({ TP, who }));
    } else {
	TELL_ME("You pat "+tar_name+" on the head.");
	who->tell_me( my_name+" pats you on the head.");
	TELL_HERE(my_name+" pats "+tar_name+" on the head.", ({ TP, who }));
    }

    call_catch(TP, "pat", who);
    return 1;
}

int
confused()
{
    return gnr("You are confused."," looks confused.");
}

int
wipe()
{
    return gnr("You wipe sweat from your forehead.",
      " wipes sweat from " + MY_POSS + " forehead.");
}

int
pace()
{
    return gnr("You pace back and forth in the room.",
      " paces back and forth in the room.");
}

int
innocent()
{
    return gnr("You try to look innocent.",
      " looks innocent.");
}

int
sad()
{
    return gnr("You feel sad.",
      " looks sad.");
}

int
agree(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You agree.",
	  " agrees with you.");

    if (!(who = find_target(str))) return 0;

    who->tell_me( my_name+" agrees with you.");
    TELL_ME("You agree with "+tar_name+".");
    TELL_HERE(my_name+" agrees with "+tar_name+".", ({ TP, who }));

    return 1;
}

int
embarrassed()
{
    return gnr("You feel embarrassed.",
      " looks embarrassed.");
}

int
greedy()
{
    return gnr("You feel greedy.",
      " looks at your belongings greedily.");
}

int
disagree(string str)
{
    object who;

    if(ghost()) return 0;

    if (!str) return gnr("You disagree.",
	  " disagrees with you.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name+" disagrees with you.");
    TELL_ME("You disagree with "+tar_name+".");
    TELL_HERE(my_name+" disagrees with "+tar_name+".", ({ TP, ({ TP, who }) }));

    return 1;
}

int
worry()
{
    return gnr("You feel like something is terribly wrong.",
      " looks worried.");
}

/*** Add new ones here ***/

/* Lia's suggestions: nope, eyeroll, nudge, caress, eye, tickle */
/* Caldaemon edited 'nope' */
int
nope()
{
    return gnr("Nope. You shake your head.",
      " shakes " + MY_POSS + " head and says 'Nope'.");
}

int
eyeroll()
{
    return gnr("You roll your eyes in disbelief.",
      " rolls " + MY_POSS + " eyes in disbelief.");
}

int
nudge(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Nudge who?"), 0;
    if (!(who = find_target(str))) return 0;

    who->tell_me(my_name + " nudges you knowingly.");
    TELL_ME("You nudge " + tar_name + " knowingly.");
    TELL_HERE(my_name+" nudges "+tar_name+" knowingly.",({TP,who}));

    return 1;
}

int
caress(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Caress who?"), 0;
    if (!(who = find_target(str))) return 0;

    who->tell_me(my_name + " caresses you lovingly.");
    TELL_ME("You caress " + tar_name + " lovingly.");
    TELL_HERE(my_name + " caresses " + tar_name + " lovingly.", ({ TP, who }));

    return 1;
}

int
eye(string str)
{
    object who;

    if(ghost()) return 0;

    if (!str) return gnr("You eye everyone suspiciously.",
	  " eyes you suspiciously.");

    if(!(who = find_target(str))) return 0;

    who->tell_me(my_name + " eyes you suspiciously.");
    TELL_ME("You eye " + tar_name + " suspiciously.");
    TELL_HERE(my_name + " eyes " + tar_name + " suspiciously.", ({ TP, who }));

    return 1;
}

int
tickle(string str)
{
    object who;
    string p;

    if (ghost()) return 0;
    if (!str) return notify_fail("Tickle who?"), 0;
    if (!(who = find_target(str))) return 0;

    p = (string) who->Pronoun();
    who -> tell_me(my_name + " tickles you playfully.");
    TELL_ME("You tickle " + tar_name + " 'til " + p + " laughs.");
    TELL_HERE(my_name + " tickles " + tar_name + " 'til " + p + " laughs.",
      ({ TP, who }));

    return 1;
}

int
ponder()
{
    /* Pondering the deepest dreams, worst nightmares was
       invented by Attila, not by batmud "gods" */

    return gnr("You ponder your deepest dreams, worst nightmares.",
      " ponders " + MY_POSS + " deepest dreams, worst nightmares.");
}

int
hmm()
{
    return gnr("You 'hmmmmmm' for a moment. It doesn't help much.",
      " mumbles: hmmmmmm...");
}

int
swear()
{
    return gnr("%$#$&*^?#@$%!!!!!!!",
      " swears loudly!");
}

int
bite(string str)
{
    object who;
    string part;

    if (ghost()) return 0;
    if (!str) return 0;

    if(!(who = find_target(str))) return notify_fail("Bite who?"), 0;

    part = ({"left","right"})[random(2)] + " " + ({"hand","leg","ankle",
      "arm","shoulder","ear","buttock"})[random(7)];

    who -> tell_me("GRR! " + my_name + " bites your " + part + "! OWW!");
    TELL_ME("GRR! You bite " + tar_name + "'s " + part + "!");
    TELL_HERE(my_name+" bites "+tar_name+"'s "+part+"!", ({
	TP, who }));
    return 1;
}

int
cheer()
{
    return gnr("You cheer. Hip-hip-hurrah!",
      " cheers. Hip-hip-hurrah!");
}

/* :-D */
int
uraa()
{
    return gnr("You yell URAA and wave your sickle and hammer.",
      " yells URAA and waves his sickle and hammer in the air.");
}

int
lag(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You complain loudly about the extreme amount\
 of lag!", " complains loudly about the extreme amount of lag!");

    if (!(who = find_target(str,1))) return 0;

    if (who == TP) return gnr("You are struck by a horrible lag!",
	  " slows down a lot, being stuck by a horrible lag!");

    who -> tell_me(my_name + " thinks that you are extremely lagged.");
    TELL_ME("You think that " + tar_name + " is extremely lagged.");
    TELL_HERE(my_name + " thinks that " +tar_name + " is extremely lagged.",
      ({ TP, ({ TP, who }) }));

    return 1;
}

int
scratch(string str)
{
    object who;

    if (ghost()) return 0;

    if(!str) return gnr("You scratch your head.",
	  " scratches " + MY_POSS + " head.");

    if (!(who = find_target(str,0))) return 0;

    who->tell_me(my_name+" scratches you.");
    TELL_ME("You scratch " + tar_name + ".");
    TELL_HERE(my_name + " scratches " + tar_name + ".", ({ TP, ({ TP, who }) }));

    return 1;
}

int
massage(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return notify_fail("Massage who?"), 0;

    if (!(who = find_target(str,1))) return 0;

    if(who == TP)
	return gnr("You try to massage yourself, but only hurt yourself.",
	  " tries to tie " + MY_OBJ + "self into a knot or something!");

    who -> tell_me(my_name + " gently massages your shoulders...");
    TELL_ME("You gently massage " + tar_name + "'s shoulders...");
    TELL_HERE(my_name + " massages " + tar_name + "'s shoulders.",
      ({ TP, who }));

    return 1;
}

int
whine(string str)
{
    object who;
    string w;
    int i;

    if (ghost()) return 0;

    if (str && !(who = find_target(str,1)))
    {
	if (sizeof(str) > 70)
	{
	    notify_fail("You are whining too much...maximum is 70 characters.");
	    return 0;
	}

	for (i = sizeof(str) - 1; i >= 0; i--)
	    if (str[i..i] < " ")
	    {
		notify_fail("Trying to harrass other players?\n");
		return 0;
	    }

	return gnr("You whine: \""+str+"!\"",
	  " whines: \""+str+"!\"");
    }

    w = ({ "MY GUILD SUCKS", "CODERS SUCK", "THIS MUD SUCKS",
      "NINJAS SUCK", "THIEVES SUCK", "NECROMANCERS SUCK",
      "PRIESTS SUCK", "FIGHTERS SUCK", "MAGES SUCK",
      "EVERYTHING SUCKS", "I WANT UPGRADE",
      "TROLLS SUCK","HOBBITS SUCK","DWARVES SUCK",
      "ELVES SUCK","DARK ELVES SUCK","HUMANS SUCK",
      "HALF-ORCS SUCK","SPELLCASTERS SUCK",
      "ZOMBIEMUD IS COOL", "BATMUD IS COOL","MK SUCKS",
      "LAG SUCKS","PK SUCKS","SUMMON KILLS SUCK",
      "HEALERS SUCK", "HEALERS CAN'T BE PKILLED",
      "I WANT SKILLS BACK", "I WANT RESTORATION" })[random(29)];

    if (!who || who == TP)
	return gnr("You whine: \""+w+"!\"",
	  " whines: \""+w+"!\"");

    who -> tell_me(sprintf("%s whines: \"%s\" to you!", my_name, w));
    TELL_ME(sprintf("You whine: \"%s\" to %s!", w, tar_name));
    TELL_HERE(sprintf("%s whines: \"%s\" to %s!", my_name, w, tar_name),
      ({ TP, who }));
    call_catch(TP, "whine", who);
    return 1;
}

/* Cal's feelings */

int
ayt(string str)
{
    object who;
    if (ghost()) return 0;
    if (!str) return notify_fail("Ayt who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    if(who == TP)
	return gnr("You wave your hand in front of your face. Anyone home?",
	  " waves " + MY_POSS + " hand in front of " + MY_POSS + " face. Anyone home??");

    who -> tell_me(my_name + " waves " +MY_POSS+ " hand in front of your face. Are you there??");
    TELL_ME("You wave your hand in front of " + tar_name+ "'s face. Anyone home?");
    TELL_HERE(my_name + " waves " +MY_POSS+ " hand in front of " + tar_name+ "'s face. Anyone home?",
      ({ who, TP }));
    return 1;
}

int
beep(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Beep who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " beeps you on triumphantly on the nose!");
    TELL_ME("You beep " + tar_name + " triumphantly on the nose.");
    TELL_HERE(my_name + " beeps " + tar_name + " triumphantly on \
the nose.",
      ({ who, TP }));
    return 1;
}

int
bobbit(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Bobbit who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    if(who == TP)
	return gnr("You DON'T want to do THAT!",
	  " tries to do something nasty to " + MY_OBJ + "self, but hesitates.");

    if ((int) who -> query_gender() == G_MALE) {

	who -> tell_me(my_name + " grabs your manly organ and pulls a knife threatening to make you sing one octave higher. EEEK!");
	TELL_ME("You grab " + tar_name + "'s manly organ and threaten \
to cut it off.");
	TELL_HERE(my_name + " suddenly grabs " + tar_name + "'s manly organ and pulls a knife. - Say, isn't that Bobbit's wife?!",
	  ({ TP, who }));
    } else {

	who -> tell_me(my_name + " looks at you like wanting to cut off \
'something' on you.");
	TELL_ME("You try to grab " + tar_name + " by her balls to cut'em off. \
Not very effective though.");
	TELL_HERE(my_name + " tries to grab " + tar_name + " by the balls to \
cut'em off, without much effect.",
	  ({ TP, who }));
    }
    return 1;
}

int
bonk(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return notify_fail("Bonk who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " bonks you on the head!");
    TELL_ME("You bonk " + tar_name + " hard on the head.");
    TELL_HERE(my_name + " bonks " + tar_name + " hard on the head.",
      ({ who, TP }));
    return 1;
}

int
bump(string str)
{
    object who;
    if (ghost()) return 0;
    if (!str) return notify_fail("Bump who?\n"), 0;
    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " bumps you with " + MY_POSS + " butt. BUMP!");
    TELL_ME("You bump " + tar_name + " with your butt.");
    TELL_HERE(my_name + " bumps " + tar_name + " with " + MY_POSS + " \
butt. BUMP!",
      ({ who, TP }));
    return 1;
}

int
crawl()
{
    string dir;

    if (ghost()) return 0;

    dir = ({"to the left","to the right","backwards","forward","in a circle","behind a boulder"})[random(6)];

    return gnr("You crawl " + dir + ".",
      " crawls " + dir + ".");
}

int
cringe()
{
    return gnr("You cringe in terror.",
      " cringes in terror.");
}

int
dementia()
{
    return gnr("You suddenly feel very dem...eh... DAMN, what's that word again..?!?!",
      " looks suddenly very old, senile and demented.");
}

int
die()
{
    return gnr("You die.",
      " drops down dead. R.I.P.");
}

int
dizzy()
{
    return gnr("Suddenly the whole world spins. You're dizzy.",
      " takes suddenly a step back and looks very dizzy.");
}

int
doh()
{
    return gnr("You kick a small stone from here to orbit and exclaim:\
'DOOOOOOOOOOH!!'",
      " kicks a small stone from here to orbit and exclaims:\
'DOOOOOOOOOOH!!'");
}

int
doomed(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You feel that all gods have turned their back at \
you. You're DOOMED!",
	  " looks anxious because all gods have turned their \
back at " + MY_OBJ + ". " + MY_NAME + " is DOOMED!");

    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " thinks you're DOOMED!");
    TELL_ME("You think " + tar_name + " is DOOMED.");
    TELL_HERE(my_name + " thinks that " + tar_name + " is DOOMED.",
      ({ TP, who }));

    return 1;
}

int
grumble()
{
    return gnr("You grumble about this and that.",
      " grumbles about this and that.");
}

int
grunt()
{
    return gnr("You grunt.",
      " grunts.");
}

int
heh()
{
    return gnr("You grin and emit a 'Heh.'",
      " grins and emits a 'Heh.'");
}

int
hi5 (string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You jump up and give yourself a thundering high five in the forehead. SPLATT!",
	  " jumps up and gives " + MY_OBJ + "self a thundering high five in the forehead. SPLATT!");

    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " jumps up and gives you a thundering high five!");
    TELL_ME("You jump up and give " + tar_name + " a thundering high five.");
    TELL_HERE(my_name + " jumps up and gives " + tar_name + " a thundering high five. RROOAAAR!",
      ({ who, TP }));
    return 1;
}

int
hide(string str)
{
    object who;

    if (ghost()) return 0;
    if (!str) return gnr("You dig a hole and stick your head in like an ostrich.",
	  " digs a hole in the ground and sticks " + MY_POSS + " head in it.");

    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " hides behind you.");
    TELL_ME("You hide behind " + tar_name + ".");
    TELL_HERE(my_name + " hides behind " + tar_name + "'s back.",
      ({ who, TP }));
    return 1;
}

int
idiot(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("Gratz! You've done it again, you IDIOT!", 
	  " looks like an utter idiot.");

    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " thinks that you are an idiot!");
    TELL_ME("You think that " + tar_name + " is an utter idiot.");
    TELL_HERE(my_name + " thinks that " +tar_name + " is an utter idiot!",
      ({ who, TP }));
    return 1;
}

int
moon(string str)
{
    object who;

    if (ghost()) return notify_fail("You don't even have a body yet, numbskull!\n"), 0;
    if(!str) return gnr("You drop your shorts and show your cute little behind.",
	  " drops " + MY_POSS + " pants and shows " + MY_POSS + " large and ugly BUTT.");

    if(!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " drops " + MY_POSS + " pants and shows " + MY_POSS + " large and ugly BUTT to you.");
    TELL_ME("You MOON " + tar_name + " !");
    TELL_HERE(my_name + " drops " + MY_POSS + " pants and MOONS " + tar_name + " !",
      ({ who, TP }));
    return 1;
}

int
muah()
{
    return gnr("You throw your head back and muah.",
      " throws " + MY_POSS + " head back and muahs.");
}

int
nodnod()
{
    return gnr("You nod twice in agreement.",
      " nods twice in agreement.");
}

int
pant()
{
    return gnr("You pant like an exhausted dog.",
      " pants like an exhausted dog.");
}

int
pick()
{
    return gnr("You pick your nose.",
      " sticks " + MY_POSS + " finger up " + MY_POSS + " nostril \
and starts digging. YUCK!");
}

int
pinch(string str)
{
    object who;
    string part;

    if (ghost()) return 0;
    if (!str) return notify_fail("Pinch who?\n"), 0;

    if (!(who = find_target(str))) return 0;

    part = ({"butt","ear","nose","arm","leg","tummy","genitals"})[random(7)];
    who -> tell_me(sprintf("%s pinches your %s.", MY_NAME, part));
    TELL_ME(sprintf("You pinch %s's %s.", tar_name, part));
    TELL_HERE(sprintf("%s pinch %s's %s.", my_name, tar_name, part),
      ({ TP, who }));
    call_catch(TP, "pinch", who);

    return 1;
}

int
punch(string str)
{
    object who;
    string part;

    if (ghost()) return 0;
    if (!str) return notify_fail("Punch who?\n"), 0;

    if (!(who = find_target(str))) return 0;

    part = ({"left eye","right eye","nose","stomach","forehead","knee cap","groin"})[random(7)];
    who -> tell_me(my_name + " punches you in the " + part + ".");
    TELL_ME("You punch " + tar_name + " in the " + part + ".");
    TELL_HERE(my_name + " punches " + tar_name + " in the " + part + ".",
      ({ TP, who }));
    return 1;
}

int
quiver()
{
    return gnr("You shiver and quiver like a bowful of JELLO.",
      " shivers and quivers like a bowful of JELLO.");
}

int
rage()
{
    return gnr("You RAGE! RAAAAAH!",
      " suddenly becomes possessed, rips " + MY_POSS + " shirt \
and howls in anger. RAAAAAAH! ");
}

int
raise()
{
    return gnr("You raise an eyebrow inquisitively.",
      " raises an eyebrow inquisitively.");
}

int
rotfl()
{
    return gnr("You roll on the floor laughing hysterically.",
      " falls to the ground and rolls all over the place \
laughing hysterically.");
}

int
shh()
{
    return gnr("You put your index finger to your lips and say 'SHH!!'.",
      " puts " + MY_POSS + " index finger to " + MY_POSS + " mouth \
and says 'SHH!'");
}

int
sick(string str)
{
    object who;

    if (ghost()) return 0;

    if (!str) return gnr("You look very sick.",
	  " suddenly looks very sick.");

    if (!(who = find_target(str))) return 0;

    who->tell_me(my_name + " is SICK and TIRED of YOU and your \
BEHAVIOUR!");
    TELL_ME("You are SICK and TIRED of " + tar_name + "'s behaviour.");
    TELL_HERE(my_name + " expresses " + MY_POSS + " deepest contempt \
against " + tar_name,
      ({ TP, who }));
    return 1;
}

int
sleep()
{
    return gnr("Good night. Don't let the bedbugs bite.",
      " looks around for some bedbugs, closes " + MY_POSS + " \
eyes and falls asleep.");
}

int
stomp(string str)
{
    object who;

    if (ghost()) return 0;
    if(!str) return gnr("You stomp like a bantha.",
	  " stomps like a bantha.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " stomps your foot. OUCH!");
    TELL_ME("You stomp hard on " + tar_name + "'s foot.");
    TELL_HERE(my_name + " stomps hard on " + tar_name + "'s foot.",
      ({ who, TP }));
    return 1;
}

int
spank(string str)
{
    object who;

    if (ghost()) return 0;
    if(!str) return gnr("You've been bad, VERY BAD.",
	  " spanks " + MY_OBJ + "self hard while looking guilty.");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " thinks you've been VERY bad and gives \
you a good spanking. OUCH! AI! OU!");
    TELL_ME("You spank " + tar_name + " thorougly.");
    TELL_HERE(my_name + " gives " + tar_name + " a good spanking. \
SLAP! SLAP! SLAP!",
      ({ who, TP }));
    return 1;
}

int
tongue(string str)
{
    object who;

    if (ghost()) return 0;
    if(!str) return gnr("You stick your tongue out. BLAAH!",
	  " sticks " + MY_POSS + " tongue out. BLAAH!");

    if (!(who = find_target(str))) return 0;

    who -> tell_me(my_name + " sticks " + MY_POSS + " tongue out at you. \
BLAAH!");
    TELL_ME("You stick you tongue out at " + tar_name + " BLAAH!");
    TELL_HERE(my_name + " sticks " + MY_POSS + " tongue out at " + tar_name + " BLAAH!",
      ({ who, TP }));
    return 1;
}

int
yuck()
{
    return gnr("Yuck. You show your tongue and express your deepest contempt.",
      " shows " + MY_POSS + " tongue and exclaims: 'YUCK!'.");
}

int
yummy()
{
    return gnr("You lick your lips and rub your tummy. Yummy!",
      " licks " + MY_POSS + " lips and rubs " + MY_POSS + " tummy. YUMMY!");
}

int
yup()
{
    return gnr("Yup. You nod.",
      " nods and says 'Yup'.");
}

int
xfiles()
{
    return gnr("Hmm... You're certain that the truth IS out there...",
      " wrinkles " + MY_POSS + " forehead and mumbles: 'Hmm...the truth IS out there...'");
}
