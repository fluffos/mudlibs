/*****************************************************************************
** Der Server fuer die Paketpost
** (C) 1994/95 Loco@Morgengrauen
** Kopien in andere Muds, auch veraendert, sind untersagt, ausser mit 
** ausdruecklicher Genehmigung des Autors.
** Dies gilt fuer alle Objekte des Paketpostsystems.
******************************************************************************

   Funktionen:

   QueryAllowed(parcel [,noshow])
    prueft Paket. Rueckgabe: 3 als beides erlaubt, 1 als postlagerndes
    erlaubt, 2 als Kurierpaket erlaubt

   QueryNormalAllowed(parcel [,noshow])
    prueft Paket nur auf postlagerndes Paket, 0 oder 1 als Rueckgabe

   QueryNormalPrice(weight)
   QueryExpressPrice(weight)
    Preis, den ein Paket mit Gewicht weight w kostet

   QueryRoomAllowed(room)
    prueft, ob in einen Raum ein Kurierpaket ausgeliefert werden kann

   StoreParcel(parcel)
    packt ein Paket in den Lagerraum

   DeliverAllParcels(pl)
    sucht Pakete fuer Empfaenger und liefert sie in environment(player) aus
   
******************************************************************************/

#include "/mail/post.h"
#include <properties.h>
#include <moving.h>

#define STORAGE_TIME 21600 /* 6 Stunden */
#define STORAGE_ROOM "/p/service/loco/obj/parcelstore"
#define SELL_AT "/d/ebene/Midas/room/lagerraum"
#define MAX_WEIGHT_EXPRESS 10000  /* 10 Kilo */

create() {
  seteuid(getuid());
}

clean_up() { return 1; }  /* reset() muss immer weiterlaufen */

reset() {
  int i,t;
  object *inv,pl;

  call_other(STORAGE_ROOM,"???");
  inv=all_inventory(find_object(STORAGE_ROOM));
  t=time();
  for (i=sizeof(inv)-1;i>=0;i--) {
    if (t-inv[i]->QuerySendTime() > STORAGE_TIME) {
      if (find_player("debugger"))
	tell_object(find_player("debugger"),sprintf("DEBUG: Storage time expired: %O\n",inv[i]));
      inv[i]->move(SELL_AT,M_NOCHECK);
      inv[i]->remove();
    }
    else if (pl=find_player(inv[i]->QueryAdress()))
      tell_object(pl,"Ploetzlich faellt Dir siedendheiss ein, dass Du noch ein Paket auf der Post\nabholen wolltest.\n");
  }
}

varargs QueryAllowed(object parcel,int noshow) {
  object *inv;
  int i,ret;

  ret=3;
  inv=deep_inventory(parcel);
  for (i=0;i<sizeof(inv);i++) {
    if (!NormalAllowed(inv[i])) {
      if (!noshow) write(break_string(inv[i]->short()+" - darf nicht per Post versendet werden.\n",78));
      ret=0;
    } else
    if (!ExpressAllowed(inv[i])) {
      if (!noshow) write(break_string(inv[i]->short()+" - darf nicht in einem Kurierpaket versendet werden.\n",78));
      ret&=(~2);
    }
  }    
  return ret;
}
varargs QueryNormalAllowed(object parcel,int noshow) {
  object *inv;
  int i,ret;

  ret=3;
  inv=deep_inventory(parcel);
  for (i=0;i<sizeof(inv);i++) {
    if (!NormalAllowed(inv[i])) {
      if (!noshow) write(break_string(inv[i]->short()+" - darf nicht per Post versendet werden.\n",78));
      ret=0;
    }
  }
  return ret;
}

NormalAllowed(object ob) {
  return (ob->QueryProp(P_POST)!=PP_FORBIDDEN &&
	  (ob->QueryProp(P_POST)>0 ||
	   !(
	     ob->QueryProp(P_NODROP) ||
	     ob->QueryProp(P_NEVERDROP) ||
	     ob->QueryProp(P_NOBUY) ||
	     ob->QueryProp(P_NOGET) ||
	     ob->QueryProp(P_MAGIC) ||
	     ob->QueryProp(P_AUTOLOADOBJ) ||
	     file_name(ob)[0..9]=="/obj/money"
	     )
	   )
	  );
}
 
ExpressAllowed(object ob) {
  string *inher;
  inher=inherit_list(ob);
  return ( ob->QueryProp(P_POST)==PP_ALLOWED ||
	  (NormalAllowed(ob) && 
	   !(
	     (member(inher,"/std/weapon")>=0) ||
	     (member(inher,"/std/armour")>=0) 
	     ) &&
	   (ob->QueryProp(P_POST)!=PP_NO_EXPRESS)
	   )
	  );
}
	    

QueryRoomAllowed(room) {

  if (room->QueryProp(P_POST)==PP_ALLOWED) return 1;
  if (
      room->QueryProp(P_NO_TPORT) ||
      room->QueryProp(P_INDOORS) ||
      room->QueryProp(P_POST)<PP_DEFAULT
      ) return 0;
  
  return 1;

}


QueryNormalPrice(w) {
  if (w<500) return 100;
  if (w<2000) return 50+20*(w/200);
  if (w<5000) return 50+50*(w/500);
  return 100*(w/1000);
}


QueryExpressPrice(w) {
  if (w>MAX_WEIGHT_EXPRESS) return 0;
  if (w<500) return 500;
  if (w<2000) return 400+50*(w/250);
  return 400+100*(w/500);
}

StoreParcel(parcel) {
  return parcel->move(STORAGE_ROOM);
}

DeliverAllParcels(pl) {
  string n;
  object *store;
  int i;
  if (!pl) pl=this_player();
  if (!objectp(pl)) pl=find_player(pl);
  if (!interactive(pl)) return 0;
  n=geteuid(pl);

  call_other(STORAGE_ROOM,"???");
  store=all_inventory(find_object(STORAGE_ROOM));
  for (i=sizeof(store)-1;i>=0;i--) 
    if (store[i]->QueryAdress()==n) {
      tell_object(pl,"Der Postbeamte stellt Dir ein Paket vor die Fuesse.\n");
      say("Der Postbeamte stellt ein Paket fuer "+capitalize(n)+" in den Raum.\n",
	  ({pl}));
      store[i]->move(environment(pl));
      call_out("point_at_parcel",2,pl);
    }
  return 1;
}

point_at_parcel(object pl) {
  if (!pl) return;
  tell_object(pl,"Der Postbeamte zeigt noch einmal auf Dein Paket und setzt sich wieder.\n");
  say("Der Postbeamte zeigt noch einmal auf "+capitalize(pl->name())+"'s Paket und setzt\nsich wieder auf seinen Stuhl.\n",
      ({pl}));
}

