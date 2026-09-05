/*
 * /sys/money.h
 */
#ifndef _MONEY_H
#define _MONEY_H

#define MONEY_OBJECT "/obj/money"

#define P_MONEY   "money"
#define P_COINS   "coins"

#define COIN_NAME "coin"

#define COPPER   "copper"
#define SILVER   "silver"
#define GOLD     "gold"
#define PLATINUM "platinum"
#define MITHRIL  "mithril"

/* The following list MUST be held in increasing value order */
#define VALID_COINAGES ({ COPPER, SILVER, GOLD, PLATINUM, MITHRIL })

/* This allows typing of 'give 5 sc and 3 cc to dudeguy'
 * The abbreviations are give as regexps (see manpage) and are
 * replaced accordingly via regexplode()
 */
#define COIN_SHORT_ID ([ "cc\\>": " "COPPER  " coin", \
                         "sc\\>": " "SILVER  " coin", \
                         "gc\\>": " "GOLD    " coin", \
                         "pc\\>": " "PLATINUM" coin", \
                         "mc\\>": " "MITHRIL " coin" ])

#define COIN_VALUE ([ COPPER:       1, \
                      SILVER:      10, \
                      GOLD:       100, \
                      PLATINUM:  1000, \
                      MITHRIL:  10000 ])

#define DEFAULT_COINAGE COPPER

/* Copper coins are LARGE, thus they have high encumbrance,
 * silver is smaller, gold even smaller, but as gold is heavier
 * they weigh equally,
 * Platinum and mithril, much more precious, thus the coins are
 * even smaller, the mithril coin is only about thumbnailsized.
 */
#define COIN_WEIGHT ([\
  COPPER   : 70,\
  SILVER   : 40,\
  GOLD     : 40,\
  PLATINUM : 25,\
  MITHRIL  : 10 \
  ])

/* Here are the long descriptions of the different coins */
#define COIN_DESCRIPTION ([\
  COPPER : ("The copper coin is about two finger' width in diameter and"     \
            " is rather heavy--compared to the other coins you know."        \
            " It is almost round and coarse.\n"                              \
            "On the front side the Village Church with its wide open portal" \
            " and its tower to the right is engraved. The other side bears a"\
            " large and very beautiful tree which you recognize as the"      \
            " Mallorn Tree of Avalon.\n"),                                   \
  SILVER : ("The silver coin is distinctly smaller than the copper coins"    \
            " you have seen yet. It is also round but its surface is"        \
            " somewhat smoother.\n"                                          \
            "On the front side you can recognize the head of Leo the"        \
            " Highpriest in a regal manner. On the other side a symbolized"  \
            " version of the Orcslayer, the ancient and famous sword, is"    \
            " engraved.\n"),                                                 \
  GOLD   : ("The gold coin is even a bit smaller than the silver coins but"  \
            " weighs about the same. Its outline is finely crafted and the"  \
            " rim bears only very few scratches.\n"                          \
            "On the front side you see King George of Alwar wielding a"      \
            " scepter and a long sword. On the other side a silhouette of"   \
            " the Glandon skyline with the remarkable shape of the king's"   \
            " palace is shown.\n"),                                          \
  PLATINUM:("The platinum coin is a bit smaller than a gold coin and bears"  \
            " nearly no scratches. As you look at it you notice that it"     \
            " looks very well crafted indeed; its surface is very smooth"    \
            " and it is a pleasure to touch it (and to have it).\n"          \
            "On the front side the mighty Padrone, Wizard of Law and"        \
            " Balance, with his characteristic large nose is displayed."     \
            " He has a very wise expression on his face and wears a"         \
            " pointed hat made of a soft cloth with stars and moons on"      \
            " it. On the other side you see the famous Walking Castle"       \
            " standing on its giant legs.\n"),                               \
  MITHRIL: ("As you look at it you feel awe. This is by far one of the most" \
            " beautiful things of this size you have ever seen. It is about" \
            " the same size as a gold coin but very much lighter and even"   \
            " smoother and better minted than a platinum coin. Touching it"  \
            " is a simple delight.\n"                                        \
            "On its front side a beautiful picture of Boltar, the mighty god"\
            " of Nirvana, is engraved in very fine lines. He wears a gentle" \
            " smile and it seems as if he were looking at you; maybe you"    \
            " are right about this. He is surrounded by the runes of the"    \
            " ten different Lored of Magic.\n"                               \
            "On the other side of this wonderful coin you see ghostlike"     \
            " figures, watching out of the depths of Eternity. You have"     \
            " the feeling that this world owes its existence to them as"     \
            " much as to the people who use these coins and who might be"    \
            " counted as part of them one day.\n") ])

/*
 * The next define (DUMMY_ALL) is used by /etc/dummy_money which is
 * useed for parsing money-descriptions when this money is not around
 * (e.g. when a player wants to retrieve money from a bank).
 */
#define DUMMY_ALL 98989

#endif /* _MONEY_H */
