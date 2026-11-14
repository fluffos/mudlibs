/*     This is a demo room for OSB
*
*      It shows the use of secrets in rooms
*
*
*
*   (c) Softbyte@OSB 16oct97
*
*
*/


#include <rooms.h>
#include <skills.h>
#include <regions.h>
#include <moving.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <herbs.h>
#include <nightday.h>


inherit "/std/room";


//************************************************************************ 
//                   Find letter secret and detail
//************************************************************************ 
// Returns the string holding the text descriptions for the secret
// which is shown two 'who'
//
// The arguments of this function are 'who':the player to which the
// text will be shown and 'secret':The name of the secet as given
// as first argument to the AddSecret command and 'skillvalue':
// the 1/10 precent value how well the player passed the skill test
// 1:very poor and 1000:superb..you might want to return different
// strings depending on this value
varargs string FindLetter(string secret,object who,int skillvalue)
{
string s;
object ob;
  
  // a hack to use the same function for Secrets and Details
  // as the argument 2 of the special detail function is no object
  // but an vitem object
  if (!who || !objectp(who)) who=this_player();
  if (!who) return 0;


  // The letter has alrady been found and the secret removed but we
  // still want to be able to look at the chairs
  if (Query("already_found")) return "Just ordinary chairs.\n";



  // Show this to the player
  s="Wow "+ capitalize(who->QueryName())+", in one of the chairs you see "
	"a bit of paper,\n might be an old and important letter.\n";

  // clone the letter
  ob=clone_object("/std/thing");
  ob->SetShort("a letter");
  ob->SetLong("A demonstration letter only...");
  ob->SetIds(({"letter","old letter"}));
  ob->move(this_object(),M_SILENT);

  // no more letters to be found
  RemoveSecret("hidden letter");
  Set("already_found",1);

  return s;
}

//************************************************************************ 
//                   Main create
//************************************************************************ 
create()
{
  ::create();
  SetIntShort("inside a small hut");
  SetIntLong(
  "Inside this small hut you see nothing much but a couple of chairs and "
  "a lot of dust.\n"
  );

  // We demosntrate how to reuse the same function for special details
  // and secrets
  AddDetail(({"chair","chairs"}),#'FindLetter);
  AddDetail(({"floor","ground"}),
    "An ordinary floor, but below one of the chairs might be a trap door.\n");
  AddDetail(({"trap door"}),
    "In the real room it would lead down to another room when found.\n");
  
  SetIntLight(55);
  SetIndoors(1);

  Set(P_TEMPERATURE,20);
  SetCoordinates( ({2500,2000,0}));

  // Adds a secret 'hidden letter' to this room. Its difficulty to find
  // is 250 (1/10 percetn=medium easy) and the text the players sees when
  // finding the secret is provided by the Function "Find Letter"
  AddSecret("hidden letter",250,#'FindLetter);

  // Adds a secret 'trap door' to this room. Its difficulty to find is
  // 750 (1/10 precent=hard) and the text the player sees when detecting
  // the secret is contained in the array. The first string is given
  // when the skill check gives a low result the third string resp.
  // is shown when the skill checks results a high result. So you can
  // show an experienced player more information
  AddSecret("trap door",750,
    ({"The floor below one of the chairs looks a bit strange.\n",
	  "You detect a trap door below one of the chairs.\n",
	  "Below one of the chairs you detect a trapdoor to a treasure chamber.\n"
	}) );

  // If one string is enough we could as well write
  // AddSecret("trap door",750,"One of the chairs looks a bit strange.\n");

  AddExit("west","./secret2_room");

}
// reset the letter to reappear every room reset
reset()
{
 ::reset();
 Set("already_found",0);
}
