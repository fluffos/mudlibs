// The magic flying carpet of Nightfall for HLPs
//
// Written by Softbyte on February 1997

#include <properties.h>
#include <magic.h>

inherit "/p/magic/std/maincarpet";

public create()
{
  ::create();
  if (!is_clone()) return;

  // Set this to choose the network your carpet is running on
  SetNetwork(2);    // HLP network

  AddId("_hlpcarpet");
  AddId("hlpcarpet");
  AddAdjective("hlp");
  AddAdjective("golden");
  AddAdjective("shimmering");
  RemoveAdjective("colourful");
  SetShort("a golden shimmering flying carpet");
  SetIntShort("on a golden shimmering flying carpet");
  SetLong(
  "This is a large oriental carpet which is looking very comfortable and\n"
  "fluffy. Its fabric is made of pure gold and with silver letters there is\n"
  "some text written into it. Some of the letters written at the edge of\n"
  "the carpet seem to form a small toplist\n"
  "Legends tell that these carpets can be used for flying to many locations\n"
  "far away.\n"
  "This carpet can be used by HLPs only.\n");
  SetIntLong(
  "You are sitting on a large oriental carpet. In silver letters some text\n"
  "is stiched into the carpet.\n"
  "You can 'leave' the carpet or 'fly' to a locations.\n");
}
