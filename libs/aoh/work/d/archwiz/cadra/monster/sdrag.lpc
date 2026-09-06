/* Cadra 20-12-94 for the 'free_turanu' quest */
#include "path.h"
#include <combat.h>
#include <moving.h>

inherit "/obj/spellmonster";

create() {
  if (::create()) return 1;
  SetName("mirror dragon");
  SetShort("a huge silver shimmering dragon");
  SetLong(
"You face a large silver dragon whose scales reflect everything like "
"small mirrors.\n");
  SetLevel(35);
  SetIds(({"dragon","mirrordragon"}));
  SetAds(({"wonderful","female","huge","shimmering","a","mirror"}));
  SetAC(15);
  SetAlign(2000);
  SetHP(1500);
  SetHands(({({"tail",0,20}),({"claws",0,20})}));
  AddSpell("icestorm","get hit by an icestorm.","gets hit by ice.",
             20,50,DT_COLD);
  SetSpellChance(10);
  SetAttribute("MagicDefence",77);
  AddDefence(DT_MAGIC,77);
  AddDefence(DT_COLD,77);
  AddDefence(DT_ELECTRO,77);
  AddDefence(DT_FIRE,77);
  AddDefence(DT_PSYCHO,100);
  SetRace("dragon");
  SetFemale();
  AddQuestion(({"quest","palace","cadra","deepthought","tiriki","turanu",
    "secrets","secret","shadows","shadow","wand","ring","elosar"}),
"The wonderful dragon says: ?naem ouy od tahW\n");
  AddQuestion(({"tseuq","ikirit","unarut"}),
"The wonderful dragon says: ?seireaf roop eht pleh ot tnaw uoy, hO\n");
  AddQuestion(({"ecalap","ecalap s'ardac"}),
"The wonderful dragon says: !cigam ruo fo edam si tI ?lufrednow ti t'nsI\n");
  AddQuestion(({"ardac","thguohtpeed"}),
"The wonderful dragon says: .tnemmoc oN\n");
  AddQuestion(({"sterces","terces"}),
"The wonderful dragon says: .sterces fo lluf si ecalap ehT\n");
  AddQuestion(({"swodahs","wodahs"}),
"The wonderful dragon says: .ecalap ruo rednu evil yehT\n");
  AddQuestion(({"gnir","gnir dlog"}),
"The wonderful dragon says: .eno sessim tnavres retsam ehT ?gnir ehT\n");
  AddQuestion(({"dnaw"}),
"The wonderful dragon says:\n\
.sriatspu erehwemos eb tsum msinahcem ehT. ti teg nac rehtegot snosrep\n\
owt ylno taht yaw eht ti deruces ardaC\n");
  AddQuestion(({"drowssap"}),
"The wonderful dragon says:\n\
.ssap uoy tel lliw I drowssap eht kaeps uoy fI\n");
  AddQuestion(({"sdneirf","dneirf"}),
"The wonderful dragon says: .era uoy ekil srerutnevda yb dellik era llA\n");
  InitChats( ({
"The wonderful dragon looks distorted.\n",
"The wonderful dragon says: !uoy, iH\n",
"The wonderful dragon says: .era sdneirf ym erehw rednow I\n",
"The wonderful dragon sighs deeply.\n",
"The wonderful dragon says: .sriats eseht draug ot gnirob os s'tI\n",
"The wonderful dragon says: .pu og ot drowssap eht kaepS\n"}) );
  SetChatChance(20);
}

init() {
  ::init();
  add_action("do_speak","speak");
  add_action("go_up","up");
}

int go_up() {
  if (!this_player()) return 1;
  write("The dragon stops you and says:\n\
.pu og ot drowssap eht kaepS\n");
  say(this_player()->QueryName()+" is stopped by the dragon.\n");
  return 1;
}

int speak(string str) {
  string code;
  if (!this_player()) return 0;
  if (!str) return (int) notify_fail("Speak what?\n") && 0;
  code=(present("palaceobj",this_player())->QueryReverseCode());
  if (str!=code) return (int) notify_fail(
"The wonderful female dragon looks questioningly at you and says:\n\
?naem uoy od tahW'\n") && 0;
  write("The dragon moves a step aside and lets you pass.\n");
  this_player()->move(PALACE("stairs4"),M_GO,"up");
  return 1;
}
