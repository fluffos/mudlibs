// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/zauberstab/zinhalt.inc
// Description: zinhalt-Befehl, Infofunktionen
// Author:      Garthan (14.02.94)
//
// $Log: zinhalt.inc,v $
// Revision 1.5  2001/03/15 22:28:15  gnomi
// Ordentlicher Umbruch beim Namen. ("=-" statt nur "-")
//
// Revision 1.4  2001/02/14 02:37:27  gnomi
// Neue Option -w und -H. Format der vordefinierten Formatierungen geaendert.
// Ein paar neue Felder fuer den volk-Befehl.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types

private string j_name(object what)
{
   string tmp;
   return (tmp = what->query_name()) ? capitalize(tmp) : "-";
}

private string j_id(object what)
{
   string *ids;
   return sizeof(ids = what->query_id()) ? ids[0] : "-";
}

private string j_value(object what)
{
   return null_or_string(what->query_value()+what->query_money());
}

private string j_class(object what)
{
   string tmp;
   if(tmp = what->query_weapon_class())
      return tmp;
   if(tmp = what->query_armour_class())
      return tmp;
   if(what->query_cloth() && (tmp = what->query_typ()))
      return tmp;
   return "";
}

private string j_prot(object what)
{
   if(what->query_armour())
      return null_or_string(what->query_armour_protection());
   else
      return null_or_string(what->query_schutz());
}

private string j_uid(object what) { return getuid(what) || ""; }
private string j_euid(object what) { return geteuid(what) || ""; }


private int j_auto_load(object what) { return what->query_auto_load()?'*':' ';}

private string j_auto_long(object what) 
{
   return mixed2str(what->query_auto_load());
}

private int j_oclass(object what)
{
   if(what->query_nahrung())
      return 'N';
   if(what->query_getraenk())
      return 'G';
   if(what->query_armour())
      return 'R';
   if(what->query_weapon())
      return 'W';
   if(what->query_cloth())
      return 'K';
   if(what->query_container())
      return 'C';
   return ' ';
}

private int j_con_close(object what)
{
   if(what->query_container())
      if(what->query_con_close(1))
	 return '1';
      else
	 return '0';
   return ' ';
}

private int j_origin(object what)
{
   int w;
   return (w=explode(object_name(what),"/")[1][0])=='o'?' ':w;
}

private int j_moveable(object what) { return what->query_no_move()?' ':'*'; }

private string j_material(object what)
{
   string *materialien;

  if(pointerp(materialien = what->query_material()))
      return implode(materialien,", ");
   return "";
}


private mapping query_inv_infos()
{
    return
	([
	   "#" : ({ 0,0,		"",   2, "d", "Nr", "Lfd. Nummer"}),
	   "A" : ({ #'j_auto_load,0,	"",   1, "c", "A", "Autoloader" }),
	   "B" : ({ #'j_auto_long,0,	"=-",50, "s", "Autoload Parameter",
						      "Autoload Parameter"}),
	   "C" : ({ #'j_con_close,0,	"",   1, "c", "C", "Container closed" }),
	   "E" : ({ CXS("max_internal_encumbrance"),0,
					"",   3, "s", "mEc", "Max. Encumbrance"}),
	   "G" : ({ #'i_gender,0,	"",   1, "c", "G", "Geschlecht"}),
	   "K" : ({ #'j_prot, 0,	"",   3, "s", "Sch", "Schutz" }),
	   "L" : ({ CXS("max_life"),0,	"",   4, "s", "mLif", "Max. Life"}),
	   "M" : ({ #'j_moveable,0,	"",   1, "c", "M", "Bewegbarkeit"}),
	   "N" : ({ #'j_name,#'r_name,	"=-", 24, "s", "Name", 
							"Name (mit Unsichtbarkeit)" }),
	   "O" : ({ #'object_name,0,	"=-",33, "s", "Objekt", "Objekt"}),
	   "S" : ({ CXS("max_damage"),0,"",   2, "s", "S+", "maxminaler Schaden"}),
	   "U" : ({ #'j_euid,0,		"",  20, "s", "Euid", "Euid" }),
	   "W" : ({ CXS("max_value"),0, "",   5, "s", "Wert+", "Maximalwert"}),
	   "a" : ({ CXS("amount"),0,	"",   3, "s", "Amt", "Amount" }),
	   "c" : ({ #'j_oclass,0,	"",   1, "c", "c", "Objektklasse"}),
	   "e" : ({ CXS("internal_encumbrance"),0,
					"",   3, "s", "Enc", "Encumbrance"}),
	   "g" : ({ CXS("weight"),0,	"",   3, "s", "Gew", "Gewicht"}),
	   "h" : ({ CXS("healing"),0,	"",   2, "s", "Hl", "Healing" }),
	   "i" : ({ #'j_id,0,		"=-",13, "s", "Id","Erste Id" }),
	   "k" : ({ #'j_class,0,	"-", 11, "s", "Klasse", "Klasse" }),
	   "l" : ({ CXS("life"),0,	"",   4, "s", "Life", "Life"}),
	   "m" : ({ #'j_material,0,     "-", 30, "s", "Materialien", "Materialien"}),
	   "n" : ({ #'j_name,0,		"=-", 24, "s", "Name", "Name" }),
	   "o" : ({ #'j_origin,0,	"",   1, "c", "o", "Ursprung des Files"}),
	   "r" : ({ CXS("strength"),0,	"",   2, "s", "St", "Staerke" }),
	   "s" : ({ CXS("min_damage"),0,"",   2, "s", "S-", "minimaler Schaden"}),
	   "u" : ({ #'j_uid,0,		"",  20, "s", "Uid", "User Id"}),
	   "v" : ({ #'j_value,0,	"",   5, "s", "Wert","Wert"}),
	   "w" : ({ CXS("min_value"),0,	"",   5, "s", "Wert-", "Minimalwert"}),
	]);
}

private mapping query_inv_groups()
{
    return
        ([
	   "a": "# N i v g cC k K s S"; 0,
	   "u": "# N o A u U"; 0,
	   "e": "# N o A M g cC k E e"; 0,
	   "l": "# N B"; 0,
	]);
}
