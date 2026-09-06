/* Cadra@Nightfall 06Sep1995 */

#include <combat.h>   
#include <rooms.h>

inherit "/obj/spellmonster";

create () {
  if (::create()) return 1;
  SetRace("human");
  SetName("Frankenstein");
  SetShort("Dr. Frankenstein");
  SetLong(
"You face a young dynamic man who looks interested at your body. He looks "
"really strong and you feel that he could be a VERY tough enemy as he is "
"here to serve the Gods of Nightfall with his work. To make him able to "
"handle even the strongest player, he is equipped with mighty powers.\n");
  SetGender(1);
  SetIds(({"frankenstein","dr","dr.","doctor","man"}));
  SetAds(({"doctor","dr","dr.","young","dynamic"}));
  SetLevel(55);
  SetStr(60);
  SetCon(30);
  SetInt(60);
  AddQuestion("money",
"Dr. Frankenstein answers:\n"
"It will cost you a lot of money to change your race again once "
"you are no Newbie anymore. The price is about 100000 coins then.\n");
  AddQuestion(({"races","race"}),
"Dr. Frankenstein says: Just type   info races    to get more informations.\n");
  AddQuestion("help",
"Dr. Frankenstein says: Just type    help   without any argument to see more.\n");
  AddQuestion(({"gender","female","male","neuter"}),
"Dr. Frankenstein says: You can only choose to be either male or female.\n"
"  Everything else has been forbidden by the Gods of Nightfall.\n");
  SetShrugMsg(
"Dr. Frankenstein says: I don't know an answer right now. You'd help me and\n"
"  others if you'd type\n"
"           idea frankenstein cannot answer on <what you asked me>\n");
  SetMaxHP(3000); 
  SetHP(3000); 
  SetDex(60);
  SetKillXP(200000);
  AddSpell("lightning bolt","are hit by a lightning bolt.",
	   "is hit by a lightning bolt.",120,140,DT_ELECTRO);
  SetSpellChance(40);
  SetAttribute("MagicDefence",80);
  AddDefence(DT_ELECTRO,200);
  SetAC(20);
  SetAlign(0);
  InitChats(5,({
"Frankenstein points at his table.\n",
"Frankenstein says: Please type   info races   if you are new in Nightfall.\n",
"Frankenstein says: Every player has to choose a race before he can start\n"
"  his mudlife.\n",
"Frankenstein says: Type  morph gnome female  if you'd like to be a gnome!\n",
"Frankenstein says: I can give you a different shape if you want to.\n",
"Frankenstein says: Homarids are great!\n",
"Frankenstein says: Would be cool to be an orc, wouldn't it?\n",
"Frankenstein says: Trolls, demons and giants are of large bodysize.\n",
"Frankenstein says: Gnomes, dwarves and halflings are small in size.\n",
"Frankenstein says: Humans are kind of usual, but still popular.\n",
"Frankenstein says: Darkelves start far away, but probably it would be kind\n"
"  of a challenge to be one?\n",
"Frankenstein says: Oglons are strange cat-like creatures.\n",
"Frankenstein says: Being an elf is quite ... uhm, elvish. But there are\n"
"  half-elfs, too.\n"
}));
  SetHands( ({ ({"right hand",0,38}),({"left hand",0,30}) }) );
}

Defend(int dam,int dam_type,object weapon) {
  object who;
  int i;
  if (this_player()==this_object())
    for (i=0;(who=previous_object(i))==this_object();i++);
  else who=this_player();
  if (!who) return;
  if (who->QueryLevel()<6) {
    write("Dr. Frankenstein looks at you, grabs your arm and shows you\n"
    "his strong muscles.\n"
    "He says: \"I am here to help you, not to kill you, so don't attack me.\"\n"
    "He looks at you with his good eyes and suddenly you feel that you\n"
    "can't even hurt him.\n");
    show("Dr. Frankenstein looks at "+this_player()->QueryName()+", feels\n"+
     this_player()->QueryPossessive()+" muscles and shakes his head.\n");
    say("Dr.Frankenstein says:\"I am here to help you, not to kill you, so\n"
    "don't attack me.\n");
    who->StopHunting(this_object());
    return;
    }
  ::Defend(dam,dam_type,weapon);
}

Die() {
  log_file("cadra/MONSTERKILLS",previous_object()->QueryRealName()+"["+
    previous_object()->QueryLevel()+"] has killed Frankenstein.\n");
  ::Die();
}
