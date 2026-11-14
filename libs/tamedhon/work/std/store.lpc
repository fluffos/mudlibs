// Tamedhon MUDlib
//
// std/store.c -- base storage room
//
// $Date: 2009/08/19 16:00:00 $
/* $Revision: 3.2 $
 * $Log: store.c,v $
 *
 * Revision 3.2  2009/08/19 16:00:00  Grynnis
 * Bugfix beim aufraeumen() wenn Obj verschwunden oder verkauft
 *
 * Revision 3.1  2009/08/18 16:00:00  Rommy
 * Formatierung, Bugfix bei aufraeumen() vorbereitet
 *
 * Revision 3.0  1997/03/13 03:14:42  Woody
 * prepared for revision control
 *
 * Revision 2.9  1995/07/11  16:56:30  Jof
 * *** empty log message ***
 *
 * Revision 2.8  1995/07/11  16:54:49  Jof
 * *** empty log message ***
 *
 * Revision 2.7  1995/07/11  14:27:26  Jof
 * Ask bank for values now (runtime changeable!)
 *
 * Revision 2.6  1995/07/10  17:26:06  Jof
 * Only call bank if sum!=0 to keep logs clean
 *
 * Revision 2.5  1995/07/10  07:32:17  Jof
 * use bank.h
 *
 * Revision 2.4  1995/02/06  19:44:14  Jof
 * RCS-Logs aufgeraeumt (leere Logs raus usw)
 *
*/


#define ANZ 3
#include <properties.h>
#include <bank.h>
#include <defines.h>

inherit "/std/thing/properties";
inherit "/std/room/items";

mixed *all,all2;
object shop;
int sum;
int store_percent_left;

void _set_store_percent_left()
{
  store_percent_left=ZENTRALBANK->_query_store_percent_left();
}

void _register_shop(object ob)
{
  shop=ob;
}

void create()
{
  seteuid(getuid());
  properties::create();
  items::create();
  _set_store_percent_left();
}

void clean_double() {}

void reset()
{
  items::reset();
  _set_store_percent_left();
  all=all_inventory(this_object());
  if (sizeof(all)==0)
  {
    all=0;
    return;
  }
  all2=order_alist(({({}),({})}));
  call_out("aufraeumen",random(10));
  if (sum)
  {
    if (!shop)
      ZENTRALBANK->PayIn(sum);
    else
      shop->_add_money(sum);
  }
  sum=0;
}

void update_money() {
  if (sum) {
    if (!shop)
      ZENTRALBANK->PayIn(sum);
    else
      shop->_add_money(sum);
  }
  sum=0;
}

void RemoveObjectFromStore(object ob) {
  // Alle Funktionen die ausserhalb aufgerufen werden, werden "gecatcht"
  catch(sum+=ob->QueryProp(P_VALUE)*store_percent_left/100; publish);
  catch(ob->remove(); publish);
  if (ob) destruct(ob);  // Objekt auf jeden Fall zerstoeren
}

void aufraeumen() {
  int i, size;
  object ob;
  string element;

  if (!pointerp(all)) return;
  if (!mappingp(all2)) all2=([]);
  size=sizeof(all);
  for (i=(size<=50 ? 0 : size-50); i<size; i++) {
    if (!objectp(ob=all[i])) continue;
    if (object_name(ob)[0..2]=="/d/" || object_name(ob)[0..8]=="/players/")
      element=BLUE_NAME(ob);
    else
      catch(element=ob->short()+BLUE_NAME(ob); publish);
    if (all2[element]++>ANZ)
      RemoveObjectFromStore(ob);
  }
  if (size<=50) {
    all=0;  // Speicher freigeben...
    all2=0;
    update_money();
  } else {
    all=all[0..size-51];
    call_out(#'aufraeumen,2);
  }
}

int clean_up(int refcount) { return 1; }

int _query_current_money() { return sum; }
