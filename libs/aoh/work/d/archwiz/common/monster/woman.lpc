/* A woman called Angela in the kitchen of the white house */

inherit "/std/npc";

#include <config.h>
#include <rooms.h>
#include <moving.h>
#include <living.h>
#include "path.h"

#define LOG "cadra/WHITEHOUSE.LOG"
#define QUESTNAME "whitehouse"

create() {
  if (::create()) return 1;
  SetName("Angela");
  SetShort("Angela");
  SetLong("Angela sighs and sobs and looks terribly sad.\n");
  SetAlign(300);
  SetGender(GENDER_FEMALE);
  SetRace("human");
  SetLevel(5);
  InitChats (10, ({
	"Angela sobs.\n",
	"Angela sighs deeply.\n",
	"Angela suddenly bursts into tears.\n",
	"Angela says: Oh, why only did that happen!\n" }));
  InitAChats (20, ({
	"Angela cries: But what I have I done to you?\n",
	"Angela shouts: HEEEELP!!!\n" }));
  InitMatch (
  	({ "smiles", "comfort"}),
  	({ "smiles", "comfort"}),
  	({ 0, 0}) );
  AddQuestion(({"sorrow","problem","problems","grief","sadness","happen",
		"why","help"}),
"Angela sighs deeply: Yesterday when I was out swimming in the Sea, "
"I lost my beautiful old necklace I inherited from my beloved mother. "
"As I saw a strange looking blue creature running away some seconds "
"after I recognized the loss, I believe this creature stole it.\n");
  AddQuestion(({"creature","blue creature"}),
"Angela says: It looked like a kobold, but who ever heard of a "
"BLUE one? I saw it running away from the beach towards the city. "
"My mother told me once there was a blue klabauter living "
"beneath this house, perhaps this creature is the one that now "
"stole my necklace?\n");
  AddQuestion(({"necklace","beautiful necklace","old necklace"}),
"Angela says: My mother once got it as a present from my father. He "
"caught a fish in whose belly he found it. As we are not that rich he was "
"very proud to be able to give her such a marriage present.\n");
  AddQuestion(({"mother","beloved mother"}),
"Angela sobs: I loved her a lot. She died 10 years ago.\n");
  AddQuestion(({"father"}),
"Angela says: He was a fisherman and went out on the Sea fishing.\n");
  AddQuestion(({"house","white house"}),
"Angela says: Legends say it once belonged to a great adventurer who "
"collected antiquities.\n");
  AddQuestion(({"legends","adventurer"}),
"Angela says: Rumours say he built a secret door in the house to enter "
"the Underground.\n");
}


notify(str) {
   if (!(this_player())) {return;}
  if (environment(this_player()))
    call_out("notify_out",1,environment(this_player()), str);
    /*
    tell_room(environment(this_player()), str, ({ this_player() }));
  write(str);
  */
}
notify_out(ob, str) {
    tell_room(ob, str);
}
  
	
smiles(str) {
  string who, what;
  sscanf(str, "%s %s", who, what);
  if(lower_case(who) == "angela") return;
  if (sscanf(str, "%s smiles %s", who, what) == 2)
    notify("Angela sighs and says: You lucky one!\n");
}

comfort(str) {
  string who, what;
  sscanf(str, "%s %s", who, what);
  if(lower_case(who) == "angela") return;
  if (sscanf(str, "%s comforts %s", who, what) == 2)
    notify("Angela looks hopefully at you: Will you help me?\n");
}

set_quest(object ob) {
  object env;
  if ((env=ob->QueryCreator()!=OBJ("whchest")) ||
    (env->QueryCreator()!=WHITEHOUSE("reservoir"))) {
  // BEGONE log_file(LOG,this_player()->QueryRealName()+
  // BEGONE   "wanted to give Angela a necklace cloned by: "+
  // BEGONE   ob->QueryCreator()+"at "+ctime(time())+"\n.");
   call_out("got_anything",1);
  }
  QUESTMASTER->SetPlayerQuest(QUESTNAME,this_player());
  log_file(LOG,this_player()->QueryRealName()+
    " solved the quest at "+ctime(time())+"\n.");
  call_out("me_shouts",5,ob);
}

me_shouts(object ob) {
  QUESTMASTER->qshout(
"You hear a loud curse from far away. Seems as if "+this_player()->QueryName()+
"\ncame through the blue klabauter's tricks.\n");
  ob->remove();
  if (ob) detruct(ob);
}

void got_necklace(object ob)
{
  say(
"Angela's face lightens up: Oh, thank you very much! You don't know how "
"happy I am to have that necklace back! My mother told me to never give it "
"away. She laughs merrily: Whatever you do, my best wishes will be with you.\n");

  write("\n- You have solved this quest -\n\n");
}

void got_anything(object ob)
{
  if (!ob) return 0;
  say("Thank you, but I can't use that. Please take it back.\n");
  say("Angela gives "+ob->QueryShort()+" back.\n");
  ob->move(this_player(),M_GIVE);
}

void notify_enter(mixed from,int method,mixed extra)
{
  if (previous_object()->id("angelas_necklace") && method == M_GIVE) {
    call_out("got_necklace", 1, previous_object());
    set_quest(previous_object());
    return ::notify_enter(from,method,extra);
    }
  call_out("got_anything", 1, previous_object());
  return ::notify_enter(from,method,extra);
}

