/*
 * belongs to the inner city, courthouse
 * a gipsy which should tell you your future
 *
 * last changes:
 * [m] 25 jan 98 - first version
 */
// TODO: add more question

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

//*************************************************
// special string arrays for answers and shrug msgs
//*************************************************
string *shrug = ({
  "Zola says: Hey I can't know all.\n",
  "Zola shrugs.\n",
  "Zola looked in another corner and didn't heared your question.\n",
  "Zola ignores you.\n",
  "Zola hmms: I can ask the crystal ball, but this will take a while.\n",
});

string *future = ({
  "Zola says: You will be very rich some day.\n",
  "Zola says: But this is the line of death, be careful!\n",
  "Zola says: You will find a wife in the next time.\n",
  "Zola says: Something wonderful will happen!\n",
  "Zola says: Something very cruel will happen, be careful.\n",
});

//***************************
// special don't know answers
//***************************
string shrug_answer() {
  return shrug[random(sizeof(shrug))];
}

//******************
// sepcial questions
//******************
string answer_future() {
  string ret;
  int idx;
  if (!TP->Query("__Zola_visit__")) {
    ret="Zola takes a deep view into her crystal ball, then she looks "
      "at you. She takes your hand and looks into it.\n"
      "Zola hmms.\n";
    idx=random(sizeof(future));
    ret+=future[idx];
    TP->Set("__Zola_visit__",idx+1);
  } else {
    ret="Zola says: Hey you visited me already. I had told you the "
        "following:\n";
    ret+=future[TP->Query("__Zola_visit__")-1];
  }
  return ret;
}

//*******
// create
//*******
create() {
  if (::create()) return;
  SetName("Zola");
  SetRace("gipsy");
  SetShort("the red Zola");
  SetLong(
    "Red Zola is a gipsy, which can tell you your future, if you "
    "ask her!\n");
  SetGoChance(0);
  SetLevel(13);
  SetGender(GENDER_FEMALE);
  AddId(({"gipsy","zola"}));
  SetAds(({"red"}));

  SetShrugMsg(#'shrug_answer);

  /* questions */
  AddQuestion(({"future","my future"}),#'answer_future);
  AddQuestion("time",
    "Zola says: Hmm time is relational and non linear.\n");
  AddQuestion("quest",
    "Zola says: I don't know anything about that, but did you visited "
    "the libary? or asked other people?\n");
}

