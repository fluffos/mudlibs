#pragma save_binary
inherit "/std/room";

#include <stdproperties.h>
#include <mail.h>	// Dla #define READER_ID

#define MAILCHECKER "/secure/mail_checker"
#define MAILREADER "/secure/mail_reader"

create_room()
{
    set_short("Poczta");
    set_long("Znajdujesz sie w glownym (i jedynym dostepnym dla ciebie) " +
      "urzedzie pocztowym " +
      "Arkadii. Wszedzie przewalaja sie stosy listow... Az strach " +
      "pomyslec, co by sie stalo jak by to wszystko sie przewrocilo. "+
      "Mimo tego calego balaganu masz wrazenie, ze System Pocztowy Arkadii "+
      "dziala bardzo sprawnie i wszystko jest pod kontrola. Do sciany "+
      "jest przyczepiona mala tabliczka.\n");

    add_item( ({"tabliczke", "mala tabliczke" }), "Jesli nie wiesz, jak "+
      "cos zrobic, wpisz '?poczta'.\n");

    add_prop(ROOM_I_INSIDE, 1);

    add_exit("/d/Standard/start/church", "polnoc", 0, 0);
}

init() 
{
  object obj;

  ::init();

  if (present(READER_ID, this_player()))
    return 1;
  if ((obj = clone_object(MAILREADER)) != 0)
    {
	obj->move(this_player());
    }
}

leave_inv(object who, object where) 
{
  object obj;

  if (who && 
      where && 
      where != this_object() &&
      (obj = present(READER_ID, who)) != 0)
    obj->remove_object();
  ::leave_inv(who, where);
}

query_mail(silent) 
{
  int mail;
  string tekst;

  seteuid(getuid());
  mail = MAILCHECKER->query_mail();
  if (!mail)
    return 0;
  if (silent)
    return 1;
  tekst = "";
  if (mail == 2)
    tekst += "\n-------------------------------------------------------------";
    
  tekst += "\nCzeka na ciebie";
  
  if (mail == 2)
    tekst += " NOWA";
  
  if (mail == 3)
    tekst += " nieprzeczytana";
  
  tekst += " poczta w najblizszym urzedzie pocztowym.\n";
  
  if (mail == 2)
    tekst += "-------------------------------------------------------------\n";
    
  tekst += "\n\n";

  write(tekst);    
  return 1;
}