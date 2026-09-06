
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL


inherit "/std/room";

varargs void create()
{
  string sign;
  sign =
   "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
   "  ~    This MUD is under construction! We welcome any visitors who    ~\n"
   "  ~    wish to hang out, discuss, offer critique and even play        ~\n"
   "  ~    test, but please be aware that we will have a player wipe      ~\n"
   "  ~    when the central area is ready to be officially opened.        ~\n"
   "  ~    Thanks for your patience and help.                             ~\n"
   "  ~    - The Management                                               ~\n"
   "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

  ::create();
  SetIntShort("Welcome to OSB");
  SetIntLong(
   "You are surrounded by thick, billowing fog - whether you stand or "
   "float is indeed a matter of question. Perhaps this is the world "
   "of dreams, or perhaps even the world of the undead, or a world "
   "outside the world.\n "
   "\n"
   "There is, though, a soft white light glowing, illuminating the "
   "fog around you. It appears to be brighter to the north. If you "
   "type " + AB("north") + " (or just n), you can move towards it.\n"
   "\n"
   "A large sign hangs here labeled IMPORTANT. Please 'read sign'.!\n\n");

//AddDetail("sign", sign);
// AddReadMsg("sign", sign);
  AddVItem(
    ([ P_IDS : ({ "sign" }),
       P_ADS : ({ "large", "important" }),
       P_LONG : ({ sign }),
       P_READ_MSG : sign
    ]) );

  AddExit("north","./room02");

  Set(P_NOWAY_MSG, "The fog only becomes thicker in that direction. North "
    "would be a wiser choice. Or choose south to select another character "
    "generation option.\n");

  SetIndoors(1);

}
