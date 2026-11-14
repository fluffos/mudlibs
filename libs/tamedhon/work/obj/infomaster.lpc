/*
 * /obj/infomaster.c
 * ---
 * Zustaendig fuer die Ausgabe auf dem Info-Kanal
 * ---
 * 05-02-1996    Mupfel@AnderLand
 * Jan 06, 1997  Woody  Auch Merlin darf jetzt senden.
 * Apr 08, 1997  Woody  Was solls... ganz /secure/ darf senden :)
 * Jun 03, 2002  Querolin  Die Rassen duerfen auch senden -> Geburtsanzeige
 * Nov 10, 2004  Serii (hehe. quero hat seinen namen falsch geschrieben *G*)
 *               name() eingefuegt - fuer den channeld
 * Apr 25, 2008  TamTam Trolle gehoeren jetzt auch dazu
 * Dez 17, 2011  Querolin  Facebook write_file eingebaut und {} in IF integriert.
 */

inherit "/std/thing";

#include <properties.h>
#include <daemon.h>

varargs string name()
{
  return "Merlin";
}

void create() {
  if (clonep(this_object())) remove();
}

varargs int remove() {return 0;}

void InfoMsg(string msg)
{
  string po;

//  tell_object(find_player("querolin"),break_string("IM:"+msg+"\n",78) );
  po=object_name(previous_object());

  if ((po[0..7]=="/gilden/") || (po[0..7]=="/secure/") ||
      (po[0..7]=="/brownie") || (po[0..5]=="/human") ||
      (po[0..3]=="/orc")     || (po[0..5]=="/dwarf") ||
      (po[0..3]=="/elf")     || (po[0..6]=="/hobbit") ||
      (po[0..6]=="/daemon")  || (po[0..5]=="/troll") ||
      (po[0..6]=="/goblin") || (po[0..3]=="/std"))
  {
    catch(VOICEMASTER->SendToChannel("Info",this_object(),SAY,msg));
  }
  else
    return;
}
