// the harbourmaster of Silvere

#include <silvere.h>
#include <npc.h>
#include <properties.h>

#define OFFICE  SIL_HARBOUR("harbourmaster")

inherit "/std/npc";

int check_office()
{
   if(environment(this_object()) == find_object(OFFICE))
      return 1;  // he's in his office
   return 0;
}

string office_chats()
{
  if(check_office())
    return random_select( ({
      "The harbour master glances out the window at the bay.\n",
      "The harbour master briefly consults the large hanging map.\n",
      "The harbour master shuffles through the papers on his desk.\n",
      "Gregore consults his list of incoming ships.\n"
    }) );
  return "";  // TODO
}

void create()
{
  ::create();

  Set(P_NAME, "Gregore d'Angelina");
  Set(P_SHORT, "Gregore d'Angelina, the harbour master");

  Set(P_LONG,
    "Gregore d'Angelina is a retired captain, and runs his office with "
    "the same precision and orderliness as he used to command his beloved "
    "ship. \n");

  Set(P_RACE, "human");
  Set(P_GENDER, 1);
  Set(P_LEVEL, 25);

  AddId( ({ "master", "harbourmaster", "harbormaster", "gregore",
            "angelina", "d'angelina" }) );
  AddAdjective( ({ "harbor", "harbour" }) );

  Set(P_MSGIN, ({"strides in", "strides in"}) );
  Set(P_MSGOUT, ({"strides out", "strides out"}) );

  Set(P_CHAT_CHANCE, 2);
  Set(P_CHATS,  // can be closure..
      ({
         #'office_chats /*'*/
      }) );

  Set(P_TALK_TYPE,
      ({ "look", "look" }) );

  Set(P_TALK_MATCH,
      ({ "desk", "map" }) );

  AddQuestion( ({ "gregore", "name" }),
   "'Aye, sailor, that's me name. 'Twas the name of me great-grandad, "
   "and me mother named me after him, hoping I'd be sensible and stay "
   "home to become a farmer. Don't think it worked - I ended up at "
   "sea, just like me dad and his dad before him.'\n");

  AddQuestion("mermaid",
   "Gregore grunts roughly in your general direction with a dangerous "
   "glint in his eye, suggesting that's perhaps not a subject you should "
   "bring up with him.\n");

  AddQuestion("figurehead",
   "'Aye, she's a beauty, isn't she? Now, there aren't many vessels left "
   "today as fine as me old Balclutha. And that's all that remains of her, "
   "that thar' figurehead. Used to ride on the prow and watch over me "
   "ship.'\n");

  AddQuestion("balclutha",
   "'Went down in a storm, she did. Me best vessel ever. You don't see "
   "many like her today. Aye, 'twas a shame to lose her.'\n");

  AddQuestion(({"cubbyhole","cubbyholes"}),
   "'Now dontcha go stickin' yer grubby fingers into me maps and me "
   "charts. It's bad enough that that looney Al'berte keeps filching "
   "them for his lunatic hobby. Why anyone would want to keep a ship "
   "in a bottle is a mystery to me... Vessels is meant to sail, not "
   "collect dust on some old shelf.'\n");

  AddQuestion("maps",
   "'Aye, been collecting 'em for years. I reckon I've the best "
   "collection of old maps in all of Silvere.'\n");

  AddQuestion("charts",
   "'Well now, I've got charts of the stars, charts of the waters, "
   "and charts of various ships. It's them that looney old Al'berte "
   "keeps filching for his blasted hobby.'\n");

  AddQuestion("desk",
   "'Why, me thinks that desks were a landlubber invention. You really "
   "don't know what a desk is?'\n");

  AddQuestion("al'berte",
   "'Why, dontcha know him, he's the looney keeper who sits in that "
   "tower and keeps the light lit. Why, if it weren't for him, me vessel "
   "would have surely hit those rocks beyond the harbour.'\n");

  AddQuestion( "permission",
      "Gregore gives you a keen stare, as if to size you up in his mind, "
      "and replies carefully: \n"
      "So you be wanting to enter the towers, hmm? Well, not just "
      "any old landlubber may gain entrance to the towers. Ye'll "
      "have to prove yerself worthy of that first. Take yerself "
      "to the guards at the southern tower, and ask them about the "
      "smugglers. Then, if yer still so keen on getting into that "
      "tower, come back and ask me again.\n");

   AddQuestion( ({"smuggler","smugglers"}),
      "The harbour master looks at you with contempt, and sighs. "
      "'Now why did I be knowing that ye'd ask me that? Are ye "
      "landlubbers all daft? Go be enquiring about them smugglers "
      "at the southern tower like I told ye afore.\n");

   AddQuestion( ({"tower","defense tower"}),
      "The harbour master says:\n"
      "The towers was built a long time ago to protect the harbour of "
      "our city from unwanted guests. Nowadays, they are mere decoration "
      "as we are not at war with anyone. But in the last time, there is "
      "something strange going on over there. The guards assigned to the "
      "towers vanished and some other people i sent over there never came "
      "back. It would be good, if you could help me with that problem, "
      "but i need some experienced people, so you have to proove yourself "
      "with something else first.\n");

  SetShrugMsg(
   "Gregore mutters something under his breath about idiotic landlubbers "
   "and their blasted questions.\n");
}
/*
       The living is also able to react on things it hears using 'talks'.
        Everything it hears is parsed to be one of this forms:

          '<who> <type><match> <what>'
          '<who> <type><match><what>'
          '<who> <type><match>'
          '<who> <type> <match> <what>'
          '<who> <type> <match><what>'
          '<who> <type> <match>'

        <type> and <match> are predefined (default is the empty string ""),
        <who> and <what> are parsed from the message heard.
        So every talk is described by <type> and <match>, and if a
        parse was successful, the <who> (and possible <what>) are
        given to an 'talkfun'ction in a 'talkobject' to process.

          string P_TALK_MATCH  "TalkMatch"
            An array of <match> strings.

          string P_TALK_TYPE   "TalkType"
            An array of <type> strings.

          mixed  P_TALK_FUN    "TalkFun"
            An array of function designations.
            Each can be the string with a function name, or a closure.

          int    P_TALK_DELAY  "TalkDelay"
            An array of integers defining the delay between the match
            of a talk and the call to its function. 0 means no delay.

          mixed  P_TALK_OBJ    "TalkObject"
            The talk object to call the talk function in.
            It can be given as string with the object name, or as
            actual object.
            Talks for which a closure is set as function, ignore the
            talkobject.

          void void InitMatch ( mixed  *fun  , string *type
                              , string *match, object ob   )
            Sets P_TALK_FUN from <fun>, P_TALK_TYPE from <type>,
            P_TALK_MATCH from <match> and P_TALK_OBJ from <obj>.

          mixed TestMatch (string str)
            Match the given <str> against all set talks and return the
            result of the talkfunction call (or 0).


        Finally, the living can react on questions.
        This is implemented as a command 'ask' bound to the function
        fask().
        The answers (and the default 'shrug message') can be set as
        strings or as closures. In the latter case, the closure is
        evaluated when needed with the questioned keyword as argument
        and has to return the actual answer.
        A third possibility is to set the answer/shrugmessage to an
        array of two strings - the first is sent to the player asking,
        the second the the environment. As 0 or "" entries are
        ignored, 'silent' asking is possible (only the asking player
        hears the answer).

*/





