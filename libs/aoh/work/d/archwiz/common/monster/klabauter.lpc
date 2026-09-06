
/* A blue klabauter which lives under the white house */

inherit "/std/npc";

#include <moving.h>
#include <rooms.h>
#include <npc.h>
#include "path.h"

object keyob;

public varargs mixed SearchM(mixed s, int i, closure cl)
{
	log_file("klabauter", s);
	log_file("klabauter", ::SearchM(s, i, cl));
}

create() {
  if (::create()) return;

  SetName("blue klabauter");
  SetShort("Blue klabauter");
  SetLong(
"You face a strange looking small creature. It somehow looks like "
"a gnome, but did you ever hear about a gnome with a blue skin? Perhaps "
"one of its experiments went wrong? You hardly believe that this creature "
"always had been blue. Its eyes are dark red like glowing rubies and "
"it has an evil grin on its face.\n");
  SetIds(({"klabauter"}));
  SetAds(({"blue","a"}));
  SetAlign(-50);
  SetGender(GENDER_MALE);
  SetRace("gnome");
  SetLevel(11);
  InitChats (10, ({
	"The blue klabauter grins evilly at you.\n",
	"The blue klabauter kicks you.\n",
	"The blue klabauter stomps with his foot.\n" }));
  InitAChats (20, ({
	"The blue klabauter spits at you.\n",
	"The blue klabauter bounces against you.\n" }));
  SetHands(({({"left hand", 0, 8}),({"right hand", 0, 8})}));
  InitMatch (
  	({ "smiles",  "test_say", 0 ,           "gives" }),
  	({ "smiles",  "says:",    "tells you:", "gives" }),
  	({ 0,         0,          0,            0 }) );
  AddQuestion(({"necklace"}),
"The blue klabauter smiles evilly at you: "
"You want to know about our old family treasure? Some years "
"ago it got lost but I found it yesterday and now it is securely "
"hidden at a place only I myself know the way to. "
"Perhaps I would give it to you if you would do me a small favour.\n");
  AddQuestion(({"favour","small favour"}),
"The blue klabauter says: There is another treasure my family lost "
"long ago. As I for myself consider it to be more important I would give "
"you the key to find the necklace if you would find the treasure for me. "
"It is a crystal trident which should be somewhere around here, too.\n");
  AddQuestion(({"trident","treasure"}),
"Search behind the place of reflection.\n");
}

void notify_enter(mixed from,int method,mixed extra)
{
  if (previous_object()->id("klabauter_trident") && method == M_GIVE)
    call_out("got_trident", 2);
  else
    call_out("got_anything", 2);
	
  ::notify_enter(from,method,extra);
}

void got_anything()
{
  say("The klabauter smiles wickedly: Thank you very much!\n");
}

void got_trident()
{
  say(
"The klabauter says: Thank you. And now I'll keep my promise and "
"help you. I have hidden the necklace in a chest in a place of water. "
"I have the key. He grins evilly: But giving you the key would be just "
"too easy, so we'll make a game: I'll hide the key in the place of "
"great noise and if you can take the key, the necklace is yours. "
"He gives you his wierdest grin as he shows you a small key, just "
"out of reach.\n");
  move(WHITEHOUSE("loud_room"),M_TELEPORT);
  call_out("take_key", 5);
}

object get_key()
{
  object key;
  key = clone_object("/obj/key");
  key->AddAdjective("small");
  key->AddAdjective("bronze");
  key->SetShort("small bronze key");
  key->SetLong("It is a small, old bronze key.\n");
  key->AddId("whchest");
  key->SetKeyIds(({"whchest"}));
  return key;
}

void take_key()
{
  if (!present("whchest",environment(this_object()))) {
    keyob = get_key();
    say("A blue klabauter drops a small key.\n");
    keyob->move(environment(this_object()), M_SILENT);
  }
  else {
    say("A blue klabauter says: Fine, the key is already here.\n");
  }
  call_out("go_back", 5);
}

void go_back()
{
  move("/std/void",M_TELEPORT);
  remove();
  if (this_object()) destruct(this_object());
}
