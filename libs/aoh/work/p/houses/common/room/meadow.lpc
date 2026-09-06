/* A kind of "/std/meadow" or "/room/meadow" */

inherit "/std/room";
#include <moving.h>

mixed  *herbs;
object *finder;
int     coin_prob;

varargs void create()
{
  (::create());
  SetIntShort("a meadow");
  SetIntLong("A meadow lies around you. Maybe you can find herbs?\n");
  SetIndoors(0);
  herbs = ({({}),({})});
  finder = ({});
  coin_prob = 0;
}

void init()
{
  (::init());
  add_action("find","find");
  add_action("search","search");
}

int find(string str)
{
  if(!str)
    notify_fail("What do you want to find?\n");
  else if(str != "herbs")
    notify_fail("You don't find any " + str + " here. Sorry!\n");
  else
    notify_fail("Did you imagine that you'd simply \"find\" the herbs here?\n" +
		"Oh, no, you actually have to search for them!\n");
  return 0;
}

void reset()
{
  ::reset();
//   if(arg) finder = ({});
}

int search(string str)
{
  int    prob1, prob2;
  object herb;

  if(!str) {
    notify_fail("What are you searching for?\n");
    return 0;
  }
  if(str != "for herbs" && str != "herbs") {
    notify_fail("You don't find any " + str + " here. Sorry!\n");
    return 0;
  }
  if(!({int})this_player()->CanSee(this_object())) {
    notify_fail("You can't see well enough here. You find nothing.\n");
    return 0;
  }
if(!herbs || !pointerp(herbs) || !pointerp(herbs[0]) || !(prob1 = sizeof(herbs[0]))) {
    notify_fail("You found nothing, maybe herbs don't grow here?\n");
    return 0;
  }
  if(member(finder, this_player()) != -1) {
    notify_fail("You searched and searched, but found nothing...\n");
    return 0;
  }
  prob1 = random(prob1);
  prob2 = random(herbs[1][prob1]);
  if(!prob2) {
    if (!catch(herb = clone_object(herbs[0][prob1]))) {
      herb->move(this_object(),M_SILENT);
      write("You found " + ({string})herb->QueryShort() + ".\n");
      finder += ({this_player()});
      return 1;
    }
    write("You search and search, but it seems you have no luck today.\n");
    return 1;
  }
  prob1 = random(coin_prob);
/* The coin search is disabled on request of the department of finance.
   Sorry. [Loco 23Jul93]
  if(!prob1) {
    herb = clone_object("/obj/money");
    herb->AdjustMoney(MONEY_DEMON->CreateMoney(random(9)+1,MONEY_DEMON->QueryCoinTypes(getuid())));
    herb->move(this_object(),M_SILENT);
    write("You didn't find any herbs, but look!" +
	  " There seems to be money here!\n");
    finder += ({this_player()});
    return 1;
  }
*/
  notify_fail("You searched, but find nothing.\n");
  return 0;
}

mixed *AddHerb(string filename, int probability)
{
  herbs[0] += ({filename});
  herbs[1] += ({probability});
  return ({filename,probability});
}

mixed *QueryHerbs() { return herbs; }

int SetCoinsProb(int probability) { return coin_prob = probability; }

int QueryCoinsProb() { return coin_prob; }
