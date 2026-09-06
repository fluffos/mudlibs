//Jeweler for the wedding & engagement ring shop

#include <npc.h>
#define here environment()

void
create_monster(){

    set_name("gordon");
    set_id("jeweler");
    set_level(15);
    set_race("human");
    set_gender(G_MALE);
    set_short("Gordon the jeweler");
    set_long("This jeweler has been working in fine metals and \
gem stones for years. He should be capable of answering your \
questions. So you might as well <ask Gordon about> something.");

}

// Used to answer any questions about ring options

status
catch_ask(object who, string what)
{
    if (what == "ring" || what == "rings" || 
      what == "engagement ring" || what == "engagement rings" || 
      what == "wedding ring" || what == "wedding rings" ) {

	who->tell_me(
	  "The jeweler says: I can make you a beautiful engagement or wedding \
ring. Before you <order a ring> for your beloved betrothed, you need to \
decide how you would like to customize that ring. I can offer you choices \
in the type of <metal>, type of <stone>, and overall <appearance>. In \
addition, you can also compose an <inscription>. If you have any \
questions about any of these options or the <prices> involved, \
please, just <ask about> it.\n\The jeweler smiles at you and \
waits for you to ask another question.");
	return 1;
    }

    if (what == "metal" || what == "types of metals" ||
      what == "the types of metals" || what == "metals" ||
      what == "metal choices" ) {

	who->tell_me(
	  "The jeweler says: Currently, I can offer you these metals: gold, silver, \
platinum, or mithral.\n\The jeweler smiles at you and waits for you to \
ask another question.");
	return 1;
    }

    if (what == "stone" || what == "stones" ||
      what == "types of stones" || what == "the types of stones" ||
      what == "stone choices") {

	who->tell_me(
	  "The jeweler says: Today, I can offer you these choices: none, diamond \
chips, a normal diamond, a two karat diamond, sapphire, ruby, emerald, \
pearl, or opal.\n\
The jeweler shows you a dazzling diamond and a sparkling sapphire.");
	return 1;
    }

    if (what == "appearance" || what == "overall appearance" ||
      what == "appearance choices"){

	who->tell_me(
	  "The jeweler tells you: Actually, there are two different kinds of \
appearances, per say, that you will be able to chose. The first kind is \
the description at a glance (i.e. short description). These choices are \
currently: beautiful, splendid, gorgeous, breath taking, exquisite, \
radiant, brilliant, divine, marvelous, impressive, elegant, artistic, or\
charming. The second kind describes what the ring represents (i.e. \
additional long description sentence). Here is a list of the possible \
choices.\n\
This ring represents the promise between two souls to live life \
together as one united soul.\n\
This ring represents the love and respect between husband and wife.\
This ring represents the only happiness in life, to love and to be \
loved.\n\
This ring represents the love, which above all, is the gift of one's \
self to another.\n\
To get the full value of love, you must have someone to \
divide it with. This ring represents half of such a division.\n\
The jeweler smiles at you and hopes you like those choices.");
	return 1;
    }

    if (what == "inscription" || what == "inscription choices"){

	who->tell_me(
	  "The jeweler smiles and says: In order to fully personalize your ring for \
your beloved, we offer a 35 character inscription with every ring.");
	return 1;
    }

    if (what == "prices"){

	who->tell_me(
	  "The jeweler shows you the following price list:\n\
        Base price: Engagement ring .......... 10000 gc\n\
                     Wedding ring ............ 25000 gc\n\
		    (Includes: silver ring description,\n\
		      inscription and channel.)\n\
\n\
\n\
 Additional prices: Gold ..................... 1000 gc\n\
                    Platinum ................. 2000 gc\n\
                    White Gold ............... 1500 gc\n\
                    Mithril .................. 5000 gc\n\
                    Diamond Chips ............ 1000 gc\n\
                    Diamond .................. 3000 gc\n\
                    Two Karat Diamond ........10000 gc\n\
                    Sapphire .................  800 gc\n\
                    Ruby .....................  800 gc\n\
                    Emerald .................. 1000 gc\n\
                    Pearl .................... 1200 gc\n\
                    Opal ..................... 1200 gc\n\
\n\
The jeweler looks at you and says: I hope this isn't out of your price \
range.");
	return 1;
    }

    if (what == "order a ring" || what == "ordering a ring" ||
      what == "ordering" || what == "order"){

	who->tell_me(
	  "The jeweler gets a gleam in his eye and says: It's easy to <order a \
ring> once you have decided on your options.");

	return 1;
    }

    who->tell_me(
      "The jeweler says: Hmm... I'm not sure what you mean. Please, rephrase \
the question.");
    return 1;

}





