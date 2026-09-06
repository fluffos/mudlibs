#include "path.h"
#include <rooms.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>

#define ASKED_HUNTER "asked_hunter"
#define STORY "told_story"
#define TOLD this_player()->Query(STORY)

inherit "/std/npc";

string ask_use() {
  if (!this_player()) return 0;
  if (!this_player()->Query(ASKED_HUNTER))
    return
"The hunter says: Why should I show you? You cannot have this knife from me!\n";
  return
"The hunter answers: To use this knife just 'cut belly' of the corpse.\n";
}

string ask_story() {
  if (!this_player()) return 0;
  if (TOLD) 
    return
      "The hunter says: Yes, you already told that story to me.\n"
      "He sighs deeply.\n";
  this_player()->Set(STORY,1);
  return
"The hunter looks questioningly at you, so you tell him the whole story. "
"After a while the hunter really looks alarmed. Perhaps you should ask "
"him some more questions now?\n";
}

string ask_wolf() {
  if (!this_player()) return 0;
  if (!TOLD)
    return
"The hunter answers: There is a big and very bad wolf running this park.\n"
"  Is there any special reason why you do ask?\n";
  return
"The hunter answers: The wolf you are searching for is an old enemy of\n"
"  mine. I am searching for his hiding place for ages now. Perhaps\n"
"  someone else around might know more, but there are people who won't tell\n"
"  a hunter the hiding place of his supposed victim.\n";
}

string ask_granny() {
  if (!this_player()) return 0;
  if (!TOLD)
    return
"The hunter answers: You know our granny? She's a lovely old woman! We all\n"
"  love her a lot. And all she knows and is she gives to her grandchild\n"
"  so there'll still be a part of her around when she will be gone\n"
"  forever.\n";
  return
"The hunter answers: Poor old granny! There's noone else left to her but\n"
"  that little girl. It would be a great deed to help her to get her\n"
"  grandchild back.\n";
}

string ask_hood() {
  if (!this_player()) return 0;
  if (!TOLD)
    return
"The hunter answers: Little red riding hood is the darling of everyone\n"
"  around. Noone would even think about hurting her, so she's free to walk\n"
"  the whole park.\n";
    return
"The hunter answers: Hurry up to help little red riding hood! Everyone\n"
"  around will be relieved if you can help her.\n"
"The hunter mumbles: Damned old wolf... if ever that witch would...\n"
"  strange... should have asked...\n"
"The hunter says:    I can help you if you want to.\n";
}

string ask_prob() {
  if (!this_player()) return 0;
  if (!TOLD)
    return
"The hunter looks questioningly at you.\n"
"The hunter says: With what could I help you? I don't understand..\n";
    return
"The hunter frowns.\n"
"The hunter answers: For sure I will teach you how to rescue our beloved\n"
"  girl! Sad that I am not allowed to help you, but I once had to give\n"
"  a promise to the father of the wolf never in my life to hurt a wolf.\n"
"  This happened after that good old wolf rescued my own life.\n"
"  If you want my help, just bring me a proof that you are willing to give\n"
"  your life for this task.\n";
}

string ask_proof() {
  if (!this_player()) return 0;
  if (!TOLD)
    return
"The hunter asks: What proof are you talking about? Did I miss something?\n"
"  Perhaps you should tell me your story once again.\n";
  return
"The hunter answers: Just bring me the tooth of the black wolf which loves\n"
"  to kill the small lambs in this park. It is for sure not the wolf you\n"
"  are looking for, but it will give me a proof that you are willing to\n"
"  fight a wolf. Give the tooth to me when you have it.\n";
}

create() {
  if (::create()) return 1;
  SetRace("half-elf");
  SetName("hunter");
  SetShort("An old hunter");
  SetLong(
"You view an old half-elf with long silver-grey hair running down half "
"of his back. You cannot even guess how old he is as his movement still looks "
"straight and dextrous. His face looks old though and so you think he has "
"to be one of the older half-elves in this world. His ears are not that "
"pointed like the ones of an elf would be, but he looks more like an elf than "
"a human.\n");
  SetGender(1);
  SetLevel(7);
  AddQuestion(({"wolf","big bad wolf","bad wolf","big wolf"}),#'ask_wolf);
  AddQuestion(({"grandma","granny"}),#'ask_granny);
  AddQuestion(({"grandchild","riding hood","hood","little red riding hood",
                "little riding hood","red riding hood","girl"}),#'ask_hood);
  AddQuestion(({"hunt","teaching","hunting","help","return","problem"}),
    #'ask_prob);
  AddQuestion(({"proof"}),#'ask_proof);
  AddQuestion("usage",#'ask_use);
  AddQuestion("story",#'ask_story);
  AddQuestion(({"place","hiding place"}),
"The hunter answers: I do not know where all animals hide. Is there a\n"
"  special one you are interested in, just ask me about that one.\n");
  AddQuestion(({"witch","good witch","bad witch","evil witch"}),
"The hunter says: There are two witches living in this park. They are\n"
"  sisters though they are very different. One is good and one is evil.\n"
"  The good one knows a lot about some animals.\n");
  AddQuestion(({"victim","victims"}),
"The hunter answers: Those animals I do hunt not only watch are my supposed\n"
"  victims.\n");
  AddQuestion("step-mother",
"The hunter's face turns pale as ashes.\n"
"The hunter says: Once that old bitch wanted to marry me!\n"
"  I am glad I could escape.\n");
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "a hunting spear",
      P_LONG: "This spear looks sharp, but not as if one could throw it.\n",
      P_WEAPON_TYPE:WT_SPEAR,
      P_DAM_TYPE:DT_PIERCE,
      P_WC: 6,
      P_RESET_QUALITY:random(49)+50,
      P_WEIGHT: 4000,
      P_VALUE: 60,
      P_ADS: ({"hunting","sharp"}),
      P_IDS: ({"spear"})]));
}

void got_tooth(object ob) {
  object ob2;
  if (!this_player()) return 0;
  if (!environment()) return 0;
  tell_room(environment(),
"The hunter looks happily.\n"
"He says: Well, you have given me a proof that you are worthy.\n"
"  Here I will give you a knife with which you are able to cut the wolf's\n"
"  corpse so that whoever was been eaten by him probably is able to get\n"
"  out of the wolf's belly. Just do a 'cut belly' to open the corpse's\n"
"  belly. It will only work one time, and only with this wolf though.\n"
"  I feel sorry about this, but powerful magic is necessary to allow to free\n"
"  an eaten person living and unhurted.\n"
"The hunter drops a hunting knife.\n");
  this_player()->Set(ASKED_HUNTER,1);
  ob->remove();
  if (ob) destruct(ob);
  ob2=clone_object(OBJ("hunting_knife"));
  ob2->move(environment(),M_SILENT);
}

void got_anything(object ob) {
  if (!ob) return 0;
  write(
"The hunter looks sad at the item you offered him.\n"
"Then he says: Thank you, but this is not what you should give me as a\n"
"  proof. Take it back.\n");
  write("The hunter gives "+ob->QueryShort()+" back to you.\n");
  ob->move(this_player(),M_GIVE);
}

void notify_enter(mixed from,int method,mixed extra) {
  if (M_GIVE == method)
  {
    if (previous_object()->id("black_wolf\ntooth"))
      call_out("got_tooth", 1, previous_object());
    else
      call_out("got_anything", 1, previous_object());
  }
  return ::notify_enter(from,method,extra);
}
