// /obj/container.c
// Eine Anwendung des Standardcontainers in /std/container:
// ein Behaelter (Beutel, Kiste, Flasche, etc.), den man
// oeffnen und schliessen kann (mit Schluessel oder ohne).
//
// Benutzung mittels 'inherit "obj/container";'
// (ggf. '#include <container.h>' wenn P_CNT_* Properties
// verwendet werden sollen)
//
// Soll ein Schluessel verwendet werden, so setzt man
// P_CNT_KEY auf die Id des zu verwendenden Schluessels:
// 1. Wenn EIN Schluessel zum Oeffnen und Schliessen verwendet
//    werden soll:
//    SetProp(P_CNT_KEY, schluessel_id)
// 2. Wenn fuers Oeffnen und Schliessen unterschiedliche
//    Schluessel verwendet werden sollen (oder nur fuers
//    Oeffnen oder nur fuers Schliessen):
//    SetProp(P_CNT_KEY, ([CNT_STATUS_OPEN:open_id,
//                         CNT_STATUS_LOCKED:lock_id]))
//
// Version 1.0	30-11-1995	Mupfel
// Version 1.0a	01-12-1995	Mupfel
//

inherit "/std/container";

#include <language.h>
#include <properties.h>
#include <container.h>
#include <defines.h>

private int open_key, lock_key, is_open, is_locked;

void create()
{
  ::create();
  is_open = 0; is_locked = 0;
  open_key = 0; lock_key = 0;
  SetProp(P_CNT_STATUS, CNT_STATUS_CLOSED);
  
  AddCmd(({"oeffne","öffne"}), "do_open");
  AddCmd(({"schliess", "schliesse", "verschliesse","schließ", "schließe", "verschließe"}), "do_close");
}

// Methode zum Setzen des Container-Status
int _set_cnt_status(int st)
{
  switch (st)
  {
    case CNT_STATUS_OPEN :
      is_open = 1; is_locked = 0;
      break;
    case CNT_STATUS_CLOSED :
      is_open = 0;
      break;
    case CNT_STATUS_LOCKED :
      is_open = 0; is_locked = 1;
      break;
    default :
      return -1;  // Fehlerstatus
  }
  SetProp(P_TRANSPARENT, is_open);
  return Set(P_CNT_STATUS, st);
}

// Methode zum Abfragen des Container-Status
int _query_cnt_status()
{
  if (is_locked)
    return CNT_STATUS_LOCKED;
  if (is_open)
    return CNT_STATUS_OPEN;
  else
    return CNT_STATUS_CLOSED;
  return -1;   // Fehlerstatus
}

// Methode zum Setzen eines Schluessels (wenn P_CNT_KEY gesetzt
// wird, wird angenommen, dass ein Schluessel erforderlich ist)
mixed _set_cnt_key(mixed key)
{
  if (stringp(key))
  {
    open_key = lock_key = 1;
    return Set(P_CNT_KEY, ([CNT_STATUS_OPEN:key,CNT_STATUS_LOCKED:key]));
  }
  else if (mappingp(key))
  {
    open_key = stringp(key[CNT_STATUS_OPEN]);
    lock_key = stringp(key[CNT_STATUS_LOCKED]);
    return Set(P_CNT_KEY, key);
  }
  else
    return -1;  // Fehlerstatus
}

// short() ueberschreiben, damit der Status mitausgegeben wird:
varargs string short()
{
  string sh;

  if (QueryProp(P_INVIS)) return 0;
  if (sh = QueryProp(P_SHORT))
    if (is_open)
      return process_string(sh) + " (geöffnet).\n";
    else
      return process_string(sh) + (is_locked?" (ab":" (") + "geschlossen).\n";
  return "";
}

// long() ueberschreiben, damit der Status mitausgegeben wird:
varargs string long()
{
  string descr, inv_descr;

  descr = process_string(QueryProp(P_LONG));
  if(!QueryProp(P_TRANSPARENT))
    return descr+capitalize(QueryPronoun())+" ist "+(is_locked?"ab":"")+"geschlossen.\n";

  inv_descr = make_invlist(PL, all_inventory(ME));
  if (inv_descr != "")
    descr += capitalize(QueryPronoun()) + " ist geöffnet und enthält:\n" + inv_descr;
  else
    descr += capitalize(QueryPronoun()) + " ist geöffnet und leer.\n";
  return descr;
}

// Funktionen zum Oeffnen/Schliessen des Containers, ggf. mit Schluessel
// (in Anlehnung an entsprechende Funktionen aus /obj/doormaster.c)

int do_open(string args)
{
  object key;
  string s1, s2;

  notify_fail("WAS möchtest Du öffnen?\n");
  if (!args || !PL) return 0;
  notify_fail("Das kannst Du nicht öffnen.\n");
  if (sscanf(args, "%s mit %s", s1, s2) < 2)
  { s1 = args; s2 = 0;}
  if (!id(s1)) return 0;
  if (open_key)
    if (s2)
    {
      if (!(key = present(s2, PL)))
      {
        write("So einen Schlüssel hast Du nicht.\n");
        return 1;
      }
      if (!key->id(QueryProp(P_CNT_KEY)[CNT_STATUS_OPEN]))
      {
        write(CAP(key->name(WER,1))+" passt nicht zu "+name(WEM,1)+".\n");
        return 1;
      }
    }
    else
    {
      write("Du benötigst einen Schlüssel, um "+name(WEN,1)+" zu öffnen.\n");
      return 1;
    }
  if (is_open)
  {
    write(CAP(name(WER,1))+" ist doch schon geöffnet!\n");
    return 1;
  }
  if (open_key)
    write("Du öffnest "+name(WEN,1)+" mit "+key->name(WEM,1)+".\n");
  else
    write("Du öffnest "+name(WEN,1)+".\n");
  say(CAP(PL->name())+" öffnet "+name(WEN,1)+".\n");
  SetProp(P_CNT_STATUS, CNT_STATUS_OPEN);
  return 1;
}

int do_close(string args)
{
  object key;
  string s1, s2;

  notify_fail("WAS möchtest Du schließen?\n");
  if (!args || !PL) return 0;
  notify_fail("Das kannst Du nicht schließen.\n");
  if (sscanf(args, "%s mit %s", s1, s2) < 2)
  { s1 = args; s2 = 0;}
  if (!id(s1)) return 0;
  if (lock_key)
    if (s2)
    {
      if (!(key = present(s2, PL)))
      {
        write("So einen Schlüssel hast Du nicht.\n");
        return 1;
      }
      if (!key->id(QueryProp(P_CNT_KEY)[CNT_STATUS_LOCKED]))
      {
        write(CAP(key->name(WER,1))+" passt nicht zu "+name(WEM,1)+".\n");
        return 1;
      }
    }
    else
    {
      write("Du benötigst einen Schlüssel, um "+name(WEN,1)+" zu schließen.\n");
      return 1;
    }
  if (!is_open)
  {
    write(CAP(name(WER,1))+" ist doch schon geschlossen!\n");
    return 1;
  }
  if (lock_key)
    write("Du schließt "+name(WEN,1)+" mit "+key->name(WEM,1)+".\n");
  else
    write("Du schließt "+name(WEN,1)+".\n");
  say(CAP(PL->name())+" schließt "+name(WEN,1)+".\n");
  if (lock_key)
    SetProp(P_CNT_STATUS, CNT_STATUS_LOCKED);
  else
    SetProp(P_CNT_STATUS, CNT_STATUS_CLOSED);
  return 1;
}
