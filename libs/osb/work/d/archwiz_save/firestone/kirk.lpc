/* totally rewrote by Loco May 13 1993 
   to get rid of this sensitive mind error */
/* Moved the XP settings to QuestControl  5/8/1994 -Blackheart */

#include <properties.h>;
#include <config.h>;
inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetLevel(3);
  SetAlign(1000);
  SetName("Captain Kirk");
  SetShort("Captain James T. Kirk");
  SetIds(({"kirk","captain"}));
  SetRace("human");
  SetAttribute("MagicDefence",40);
  SetGender(GENDER_MALE);
}

QueryLong() {
  call_out("que",2);
  return "Captain James T. Kirk the captain of the Enterprise.\n";
}

que() {
  tell_room(environment(this_player()),
"\nCaptain Kirk asks hopefully: You have repaired the transporter?\n"
"But then he sniffs. He says: Unfortunately I have lost my "
"communicator, so the transporter cannot lock on to me.\n");
}

init() {
  (::init());
  add_action("give","give");
  call_out("que",2);
}

give(string str)
{
  string a;

  if (sscanf(str,"communicator to %s",a)==1) {
    object wa,ob;
    if (!(id(a))) return;
  ob=present("communicator",this_player());
    if (!ob) return;
    say("Captain Kirk says: Thank you very much. I've been stuck\n\
here for quite awhile.\n");
 /*
Out of gratitude for his rescue Kirk gives you\n\
his rolex watch.\n");
    wa = clone_object("/d/archwiz/firestone/watch");
    wa->move(this_player());
  */
    say("Captain Kirk switches on his communicator "
"and says: Scotty, energize!!\n"
"Then he becomes indistinct and disappears.\n");
    if (!QUESTMASTER->QueryQuestSolved("find_kirk",this_player())) {
      QUESTMASTER->SetPlayerQuest("find_kirk",this_player());
      CHANNEL_D->SendEmote("news",this_player()->QueryName(),
        "just helped Captain Kirk back on his ship.", 1);
      write("You have solved the Kirk Quest!\n");
      }
    else write("Thanks again for solving this quest.\n");
    destruct(ob);
    remove();
    return 1;
  }
}
