#include <std.h>
#include <waterworld.h>

inherit OBJECT;

void create()
{
  ::create();
  set_name("Captain's logbook");
  set_id(({"logbook","ledger","log","book"}));
  set_short("A leatherbound ledger");
  set_long("This is the captain's logbook. It appears the captain was able to write a final entry before whatever sank this ship finally got around to him.\n\n Pages 5, 14 and 32 are still readable.\n");
  set_weight(20);
  set_curr_value("gold",20);
  set_read("default", "%^YELLOW%^Captain's Log Book%^RESET%^\n\n    Daily Ledger");
  set_read( ({ "page 5", "page five", "fifth page", "5th page" }),
    "Trydryill has dispatched the fourth, fifth, and seventh navies to Tirun. "
    "He has determined it is a mage's power in this area that is preventing the dracoliches from enslaving this world. "
    "We, the elite guards, gladly do his bidding and will lay waste to everything in and around Tirun as soon as we arrive. "
    "This should be an easy battle since we have over 100,000 well-trained soldiers and over 5,000 ships at our command."
  );
  set_read( ({ "page 14", "page fourteen", "fourteenth page", "14th page" }),
     "We have arrived in the mouth of Tirun's bay."
     " There appear to be soldiers with strange markings upon their armor standing on the beaches."
     "\n\nNo matter. Everything in this pathetic city dies this day even these unfortunate travelers."
     " The boats are now preparing to land and the soldiers to raid the beaches."
     " His majesty Trydryill will be pleased!! CHARGE!!!!\n"
  );
  set_read( ({ "page 32", "page thirty two", "page thirtytwo", "page thirty-two", "thirty-second page", "thirtysecond page", "thirty second page", "32nd page" }),
     "By the lords of darkness... Most of our navies have been destroyed by a swarm of tentacles the size of trees."
     " I have no idea what this beast is but nothing we have can even hurt it."
     " My final act before my own ship was crushed in these massive tentacles was to dispatch our fastest ship to our lord Trydryill."
     "\n\n I pray it makes it to my lord..."
     "\n\n (The rest is caked in blood and is unreadable)"
     "\n\n"
  );
}
