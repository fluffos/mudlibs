// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/convert.inc
// Description:	Beliebige Variablentypen in Strings umwandeln
// Author:	Freaky
//
// $Log: convert.inc,v $
// Revision 1.8  2015/03/14 11:10:25  gnomi
// Structs mit Member ausgeben.
//
// Revision 1.7  2002/11/22 00:24:24  gnomi
// mixed2str: Alien-Lfuns als solche ausgeben.
//
// Revision 1.6  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

#ifndef CLOSURE_IS_ALIEN_LFUN
#define CLOSURE_IS_ALIEN_LFUN(x)	((x) == 1)
#endif

private string get_closure(mixed vari)
{
    int tmp;

    if (typeof(vari) != T_CLOSURE)
	return "*KEINE CLOSURE*";

    tmp = get_type_info(vari,1);
    if (CLOSURE_IS_ALIEN_LFUN(tmp))
	return sprintf("ALIEN-LFUN(%O)",vari);
    if (CLOSURE_IS_LFUN(tmp))
	return sprintf("LFUN(%O)",vari);
    if (CLOSURE_IS_IDENTIFIER(tmp))
	return sprintf("IDENTIFIER(%O)",vari);
    if (CLOSURE_IS_BOUND_LAMBDA(tmp))
	return sprintf("BOUND-LAMBDA(%O)",vari);
    if (CLOSURE_IS_LAMBDA(tmp))
	return sprintf("LAMBDA(%O)",vari);
    if (CLOSURE_IS_UNBOUND_LAMBDA(tmp))
	return sprintf("UNBOUND-LAMBDA(%O)",vari);
    if (CLOSURE_IS_SIMUL_EFUN(tmp))
	return sprintf("SIMUL-EFUN(%O)",vari);
    if (CLOSURE_IS_EFUN(tmp))
	return sprintf("EFUN(%O)",vari);
    if (CLOSURE_IS_OPERATOR(tmp))
	return sprintf("OPERATOR(%O)",vari);
    return sprintf("*UNBEKANNTE CLOSURE:%O*",vari);
}

/*
FUNKTION: mixed2str
DEKLARATION: string mixed2str(mixed arr)
BESCHREIBUNG:
Wandelt einen beliebigen Datentyp in einen String um.
Gut fuer Debuggingzwecke.
GRUPPEN: simul_efun, array, string
VERWEISE: to_string, to_int, to_float
*/
string mixed2str(mixed arr)
{
    switch(typeof(arr))
    {
      case T_INVALID:
	return sprintf("*FEHLER:%O*",arr);
      case T_LVALUE:
	return sprintf("LVALUE(%O)",arr);
      case T_STRING:
        // Alle Escape-Codes durch ihre leserliche Form ersetzen.
        arr = regreplace(arr,"\\\\","\\\\\\\\",1);
	arr = regreplace(arr,"\a","\\\\a",1);
	arr = regreplace(arr,"\b","\\\\b",1);
	arr = regreplace(arr,"\e","\\\\e",1);
	arr = regreplace(arr,"\f","\\\\f",1);
	arr = regreplace(arr,"\n","\\\\n",1);
	arr = regreplace(arr,"\r","\\\\r",1);
	arr = regreplace(arr,"\t","\\\\t",1);
	arr = regreplace(arr,"\"","\\\\\"",1);
	return "\"" + arr + "\"";
      case T_NUMBER:
      case T_FLOAT:
	return to_string(arr);
      case T_POINTER:
      {
	int i;
	string st;
	if (sizeof(arr) <= 0)
	    return "({})";
	st = "({";
	for (i = 0; i < sizeof(arr) - 1; i++)
	    st += mixed2str(arr[i]) + ",";
	return st + mixed2str(arr[i]) + "})";
      }
      case T_OBJECT:
	return "OBJ(" + object_name(arr) + ")";
      case T_MAPPING:
      {
	mixed *ind;
	string stm;
	int a, end, j;
	if (sizeof(arr) <= 0)
	    return "([])";
	stm = "([";
	ind = m_indices(arr);
	end = get_type_info(arr,1)-1;
	for(j = 0; j < sizeof(ind); j++)
	{
	    stm += mixed2str(ind[j]);
	    if (end >= 0)
	    {
		stm += ":";
		for (a = 0; a < end; a++)
		    stm += mixed2str(arr[ind[j],a]) + ";";
		stm += mixed2str(arr[ind[j],end]);
	    }
	    stm += ",";
	}
	return stm[0..<2] + "])";
      }
      case T_CLOSURE:
	return get_closure(arr);
      case T_SYMBOL:
	return sprintf("SYMBOL(%O)",arr);
      case T_QUOTED_ARRAY:
	return sprintf("QUOTED-ARRAY(%O)",arr);
      case T_STRUCT:
      {
        string st = sprintf("STRUCT(<%s>", get_type_info(arr, 2));
        for(int i = 0; i < sizeof(arr); i++)
            st += (i ? "," : " ") + mixed2str(arr->(i));
        return st += ")";
      }
      default:
	return sprintf("*UNBEKANNT:%O:*",arr);
    }
}
