// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/description.h
// Description: Defines fuer /i/tools/description_core.c
// Author:      Gnomi (2006)
//
// $Log: description_core.h,v $
// Revision 1.10  2013-03-16 16:09:29  gnomi
// Typos.
//
// Revision 1.9  2008/02/25 11:51:45  gnomi
// Hinweise auf das info-Mapping in die Dokus eingebaut.
//
// Revision 1.8  2008/01/16 09:56:32  gnomi
// T_ATOM_COMPILE definiert.
//
// Revision 1.7  2007/12/05 11:00:15  gnomi
// T_CALL_OTHER eingebaut.
//
// Revision 1.6  2007/02/04 22:05:10  gnomi
// T_NOT eingebaut.
//
// Revision 1.5  2006/06/07 20:54:19  gnomi
// Umbenennung nach description_core.
//
// Revision 1.4  2006/05/12 10:01:38  gnomi
// Neues Include fuer /i/tools/description.
//

#ifndef __DESCRIPTION_CORE_H__
#define __DESCRIPTION_CORE_H__

// Erstes Element im Array
#define T_ATOM_INVALID	0	// Nur fuer Dokumentationszwecke
#define T_ATOM_COND	1
#define T_ATOM_FILTER	2
#define T_ATOM_TEXT	3
#define T_ATOM_TAG	4
#define T_ATOM_ELSE	5
#define T_ATOM_AND	6
#define T_ATOM_OR	7
#define T_ATOM_NOT	8
#define T_ATOM_COMPILE	9
#define T_ATOM_NOTHING	10	// Fuer desc_compile

// In Verbindung mit T_ATOM_COND (2. Element im Array)
#define T_ATOM_FUNC		1
#define T_ATOM_GREATER		2
#define T_ATOM_LESSER		3
#define T_ATOM_EQUAL		4
#define T_ATOM_NE		5
#define T_ATOM_GE		6
#define T_ATOM_LE		7
#define T_ATOM_CALL_OTHER	8

// Vordefinierte Eigenschaften fuer T_GREATER & Co.
// (3. Element im Array)
#define TN_ATOM_FUNC		1
#define TN_ATOM_CALL_OTHER	2

// Und nun die Defines, die man verwenden sollte:
#define T_ELSE			({ T_ATOM_ELSE })
#define T_NOT(cond)		({ T_ATOM_NOT, (cond) })
#define T_AND(cond1, cond2)	({ T_ATOM_AND, (cond1), (cond2) })
#define T_OR(cond1, cond2)	({ T_ATOM_OR, (cond1), (cond2) })
#define T_GREATER(what, num)	({ T_ATOM_COND, T_ATOM_GREATER, (what), (num)})
#define T_LESSER(what, num)	({ T_ATOM_COND, T_ATOM_LESSER, (what), (num)})
#define T_EQUAL(what, num)	({ T_ATOM_COND, T_ATOM_EQUAL, (what), (num)})
#define T_NOT_EQUAL(what, num)	({ T_ATOM_COND, T_ATOM_NE, (what), (num)})
#define T_GREATER_EQUAL(what, num)	({ T_ATOM_COND, T_ATOM_GE, (what), (num)})
#define T_LESSER_EQUAL(what, num)	({ T_ATOM_COND, T_ATOM_LE, (what), (num)})
#define T_GT(what, num)		({ T_ATOM_COND, T_ATOM_GREATER, (what), (num)})
#define T_LT(what, num)		({ T_ATOM_COND, T_ATOM_LESSER, (what), (num)})
#define T_EQ(what, num)		({ T_ATOM_COND, T_ATOM_EQUAL, (what), (num)})
#define T_NE(what, num)		({ T_ATOM_COND, T_ATOM_NE, (what), (num)})
#define T_GE(what, num)		({ T_ATOM_COND, T_ATOM_GE, (what), (num)})
#define T_LE(what, num)		({ T_ATOM_COND, T_ATOM_LE, (what), (num)})

#define T_FUNC(func)		({ T_ATOM_COND, T_ATOM_FUNC, (func) })
#define T_FUNCV(func, pars)	(({ T_ATOM_COND, T_ATOM_FUNC, (func) })+(pars))
#define T_CL(cl)		({ T_ATOM_COND, (cl) })
#define T_CLV(cl, pars)		(({ T_ATOM_COND, (cl) })+(pars))
#define T_CALL_OTHER(obj, func)		({ T_ATOM_COND, T_ATOM_CALL_OTHER, (obj), (func) })
#define T_CALL_OTHERV(obj, func, pars)	(({ T_ATOM_COND, T_ATOM_CALL_OTHER, (obj), (func) })+(pars))

#define T_FILTER_FUNC(func)		({ T_ATOM_FILTER, T_ATOM_FUNC, (func) })
#define T_FILTER_FUNCV(func, pars)	(({ T_ATOM_FILTER, T_ATOM_FUNC, (func) })+(pars))
#define T_FILTER_CL(cl)			({ T_ATOM_FILTER, (cl) })
#define T_FILTER_CLV(cl, pars)		(({ T_ATOM_FILTER, (cl) })+(pars))
#define T_FILTER_CALL_OTHER(obj, func)		({ T_ATOM_FILTER, T_ATOM_CALL_OTHER, (obj), (func) })
#define T_FILTER_CALL_OTHERV(obj, func, pars)	(({ T_ATOM_FILTER, T_ATOM_CALL_OTHER, (obj), (func) })+(pars))

#define T_TEXT_FUNC(func)		({ T_ATOM_TEXT, T_ATOM_FUNC, (func) })
#define T_TEXT_FUNCV(func, pars)	(({ T_ATOM_TEXT, T_ATOM_FUNC, (func) })+(pars))
#define T_TEXT_CL(cl)			({ T_ATOM_TEXT, (cl) })
#define T_TEXT_CLV(cl, pars)		(({ T_ATOM_TEXT, (cl) })+(pars))
#define T_TEXT_CALL_OTHER(obj, func)		({ T_ATOM_TEXT, T_ATOM_CALL_OTHER, (obj), (func) })
#define T_TEXT_CALL_OTHERV(obj, func, pars)	(({ T_ATOM_TEXT, T_ATOM_CALL_OTHER, (obj), (func) })+(pars))

#define T_TAG(flag)		({ T_ATOM_TAG, (flag) })
#define T_TAGVAL(flag,val)	({ T_ATOM_TAG, (flag), (val) })
#define T_TAG_COND(flag, cond)	({ T_TAG(flag), (cond) })
#define T_TAGVAL_COND(flag, val, cond)	({ T_TAGVAL(flag, val), (cond) })

/*
FUNKTION: T_LISTE
DEKLARATION: Liste allgemeiner T-Defines
BESCHREIBUNG:

Vordefinierte Bedingungen:
 - T_ELSE		Die unmittelbar vorherige Bedingung war falsch.
 - T_AND(cond1, cond2)	cond1 und cond2 sind wahr.
 - T_OR(cond1, cond2)	cond1 oder cond2 ist wahr.
 - T_NOT(cond)		cond ist falsch.
 - T_FUNC(func)		Der Aufruf von func(info, ) liefert einen Wert != 0.
 - T_FUNCV(func, pars)	Der Aufruf von func(info, pars...) liefert != 0.
 - T_CALL_OTHER(ob, fn) Der Aufruf von ob->fn(info) liefert einen Wert != 0.
 - T_CALL_OTHERV(o,f,p) Der Aufruf von o->f(i, p...) liefert einen Wert != 0.
 - T_CL(cl)		Der Aufruf von cl(info) liefert einen Wert != 0.
 - T_CLV(cl, pars)	Der Aufruf von cl(info, pars...) liefert != 0.
 - T_GREATER(what, num), T_LESSER(what, num), T_GREATER_EQUAL(what, num),
   T_LESSER_EQUAL(what, num), T_EQUAL(what, num), T_NOT_EQUAL(what, num)
			num ist >, <, >=, <=, == bzw. != der Eigenschaft
			what. Die Eigenschaft what wird durch entsprechende
			TN-Defines (z.B. TN_STAT_INT) dargestellt und
			durch desc_number ermittelt.

Vordefinierte Filter:
 - T_FILTER_FUNC(func)		Ergebnis = func(info, original)
 - T_FILTER_FUNCV(func,pars)	Ergebnis = func(info, original, pars...)
 - T_FILTER_CALL_OTHER(ob, fun) Ergebnis = ob->fun(info, original)
 - T_FILTER_CALL_OTHERV(o,f,p)  Ergebnis = o->f(info, original, p...)
 - T_FILTER_CL(cl)		Ergebnis = cl(info, original)
 - T_FILTER_CLV(cl, pars)	Ergebnis = cl(info, original, pars...)

Vordefinierte Texte:
 - T_TEXT_FUNC(func)		Ergebnis = func(info)
 - T_TEXT_FUNCV(func,pars)	Ergebnis = func(info, pars...)
 - T_TEXT_CALL_OTHER(ob, fun)	Ergebnis = ob->fun(info)
 - T_TEXT_CALL_OTHERV(ob,fun,p) Ergebnis = ob->fun(info, p...)
 - T_TEXT_CL(cl)		Ergebnis = cl(info)
 - T_TEXT_CLV(cl, pars)		Ergebnis = cl(info, pars...)
  
VERWEISE: compile_desc, desc_number
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_ELSE
DEKLARATION: T_ELSE
BESCHREIBUNG:
T_ELSE ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn die unmittelbar vorhergehende Bedingung falsch ist.
VERWEISE: compile_desc
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_AND
DEKLARATION: T_AND(cond1, cond2)
BESCHREIBUNG:
T_AND ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn die beiden angegebenen Bedingungen 'cond1' und 'cond2' wahr sind.
VERWEISE: compile_desc, T_OR
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_OR
DEKLARATION: T_OR(cond1, cond2)
BESCHREIBUNG:
T_OR ist eine Bedingung in Beschreibungen, welche wahr ist, wenn mindestens
eine der beiden angegebenen Bedingungen 'cond1' und 'cond2' wahr ist.
VERWEISE: compile_desc, T_AND
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_GREATER
DEKLARATION: T_GREATER(what, num)
BESCHREIBUNG:
T_GREATER ist eine Bedingung in Beschreibungen, welche wahr ist, wenn
der angenebene Wert 'what' groesser als 'num' ist. 'what' ist dabei
ein von der Funktion desc_number auszuwertendes TN-Define wie
z.B. TN_STAT_INT.
VERWEISE: compile_desc, desc_number, T_GT, T_LESSER, T_EQUAL, T_NOT_EQUAL,
          T_GREATER_EQUAL, T_LESSER_EQUAL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_LESSER
DEKLARATION: T_LESSER(what, num)
BESCHREIBUNG:
T_LESSER ist eine Bedingung in Beschreibungen, welche wahr ist, wenn
der angenebene Wert 'what' kleiner als 'num' ist. 'what' ist dabei
ein von der Funktion desc_number auszuwertendes TN-Define wie
z.B. TN_STAT_INT.
VERWEISE: compile_desc, desc_number, T_LT, T_GREATER, T_EQUAL, T_NOT_EQUAL,
          T_GREATER_EQUAL, T_LESSER_EQUAL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_EQUAL
DEKLARATION: T_EQUAL(what, num)
BESCHREIBUNG:
T_EQUAL ist eine Bedingung in Beschreibungen, welche wahr ist, wenn
der angenebene Wert 'what' gleich 'num' ist. 'what' ist dabei
ein von der Funktion desc_number auszuwertendes TN-Define wie
z.B. TN_STAT_INT.
VERWEISE: compile_desc, desc_number, T_EQ, T_GREATER, T_LESSER, T_NOT_EQUAL,
          T_GREATER_EQUAL, T_LESSER_EQUAL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_NOT_EQUAL
DEKLARATION: T_NOT_EQUAL(what, num)
BESCHREIBUNG:
T_NOT_EQUAL ist eine Bedingung in Beschreibungen, welche wahr ist, wenn
der angenebene Wert 'what' ungleich 'num' ist. 'what' ist dabei
ein von der Funktion desc_number auszuwertendes TN-Define wie
z.B. TN_STAT_INT.
VERWEISE: compile_desc, desc_number, T_NE, T_GREATER, T_LESSER, T_EQUAL,
          T_GREATER_EQUAL, T_LESSER_EQUAL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_GREATER_EQUAL
DEKLARATION: T_GREATER_EQUAL(what, num)
BESCHREIBUNG:
T_GREATER_EQUAL ist eine Bedingung in Beschreibungen, welche wahr ist, wenn
der angenebene Wert 'what' groesser oder gleich 'num' ist. 'what' ist dabei
ein von der Funktion desc_number auszuwertendes TN-Define wie
z.B. TN_STAT_INT.
VERWEISE: compile_desc, desc_number, T_GE, T_GREATER, T_LESSER, T_EQUAL,
	  T_NOT_EQUAL, T_LESSER_EQUAL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_LESSER_EQUAL
DEKLARATION: T_LESSER_EQUAL(what, num)
BESCHREIBUNG:
T_LESSER_EQUAL ist eine Bedingung in Beschreibungen, welche wahr ist, wenn
der angenebene Wert 'what' kleiner oder gleich 'num' ist. 'what' ist dabei
ein von der Funktion desc_number auszuwertendes TN-Define wie
z.B. TN_STAT_INT.
VERWEISE: compile_desc, desc_number, T_LE, T_GREATER, T_LESSER, T_EQUAL,
          T_NOT_EQUAL, T_GREATER_EQUAL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_GT
DEKLARATION: T_GT(what, num)
BESCHREIBUNG:
T_GT ist eine Abkuerzung fuer T_GREATER
VERWEISE: compile_desc, T_GREATER, T_LT, T_EQ, T_NE, T_GE, T_LE
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_LT
DEKLARATION: T_LT(what, num)
BESCHREIBUNG:
T_LT ist eine Abkuerzung fuer T_LESSER
VERWEISE: compile_desc, T_LESSER, T_GT, T_EQ, T_NE, T_GE, T_LE
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_EQ
DEKLARATION: T_EQ(what, num)
BESCHREIBUNG:
T_EQ ist eine Abkuerzung fuer T_EQUAL
VERWEISE: compile_desc, T_EQUAL, T_GT, T_LT, T_NE, T_GE, T_LE
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_NE
DEKLARATION: T_NE(what, num)
BESCHREIBUNG:
T_NE ist eine Abkuerzung fuer T_NOT_EQUAL
VERWEISE: compile_desc, T_NOT_EQUAL, T_GT, T_LT, T_EQ, T_GE, T_LE
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_GE
DEKLARATION: T_GE(what, num)
BESCHREIBUNG:
T_GE ist eine Abkuerzung fuer T_GREATER_EQUAL
VERWEISE: compile_desc, T_GREATER_EQUAL, T_GT, T_LT, T_EQ, T_NE, T_LE
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_LE
DEKLARATION: T_LE(what, num)
BESCHREIBUNG:
T_LE ist eine Abkuerzung fuer T_LESSER_EQUAL
VERWEISE: compile_desc, T_LESSER_EQUAL, T_GT, T_LT, T_EQ, T_NE, T_GE
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FUNC
DEKLARATION: T_FUNC(func)
BESCHREIBUNG:
T_FUNC ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn der Aufruf der Funktion 'func' einen Wert != 0 liefert.
Die Funktion enthaelt als ersten Parameter ein info-Mapping
(siehe query_long_exec fuer die Details).
VERWEISE: compile_desc, desc_call_func, T_FUNCV, T_CALL_OTHER, T_CALL_OTHERV,
          T_CL, T_CLV, query_long_exec
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FUNCV
DEKLARATION: T_FUNCV(func, pars)
BESCHREIBUNG:
T_FUNCV ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn der Aufruf der Funktion 'func' mit den Elementen aus 'pars' als
2. und folgende Parameter einen Wert != 0 liefert.
Die Funktion enthaelt als ersten Parameter ein info-Mapping
(siehe query_long_exec fuer die Details).
VERWEISE: compile_desc, desc_call_func, T_FUNC, T_CALL_OTHER, T_CALL_OTHERV,
          T_CL, T_CLV, query_long_exec
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_CALL_OTHER
DEKLARATION: T_CALL_OTHER(obj, func)
BESCHREIBUNG:
T_CALL_OTHER ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn der Aufruf der Funktion 'func' im Objekt 'obj' einen Wert != 0 liefert.
Die Funktion enthaelt als ersten Parameter ein info-Mapping
(siehe query_long_exec fuer die Details).
VERWEISE: compile_desc, desc_call_func, T_CALL_OTHERV, T_FUNC, T_FUNCV,
          T_CL, T_CLV, query_long_exec
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_CALL_OTHERV
DEKLARATION: T_CALL_OTHERV(obj, func, pars)
BESCHREIBUNG:
T_CALL_OTHERV ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn der Aufruf der Funktion 'func' im Objekt 'obj' mit den Elementen aus
'pars' als 2. und folgende Parameter einen Wert != 0 liefert.
Die Funktion enthaelt als ersten Parameter ein info-Mapping
(siehe query_long_exec fuer die Details).
VERWEISE: compile_desc, desc_call_func, T_CALL_OTHER, T_FUNC, T_FUNCV,
          T_CL, T_CLV, query_long_exec
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_CL
DEKLARATION: T_CL(cl)
BESCHREIBUNG:
T_CL ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn der Aufruf der Closure 'cl' einen Wert != 0 liefert.
Die Closure erhaelt als ersten Parameter den Wert, welcher der
von compile_desc generierten Closure beim Aufruf uebergeben wurde.
VERWEISE: compile_desc, desc_call_cl, T_FUNC, T_FUNCV,
          T_CALL_OTHER, T_CALL_OTHERV, T_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_CLV
DEKLARATION: T_CLV(cl, pars)
BESCHREIBUNG:
T_CLV ist eine Bedingung in Beschreibungen, welche wahr ist,
wenn der Aufruf der Closure 'cl' einen Wert != 0 liefert.
Die Closure erhaelt als ersten Parameter den Wert, welcher der
von compile_desc generierten Closure beim Aufruf uebergeben wurde.
Die Elemente aus 'pars' werden als weitere Parameter uebergeben.
VERWEISE: compile_desc, desc_call_cl, T_FUNC, T_FUNCV,
          T_CALL_OTHER, T_CALL_OTHERV, T_CL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FILTER_FUNC
DEKLARATION: T_FILTER_FUNC(func)
BESCHREIBUNG:
T_FILTER_FUNC ist ein Filter fuer Beschreibungen. Dabei wird
die Funktion 'func' mit dem zu filternden Text aufgerufen,
das Ergebnis wird in die Beschreibung uebernommen.
VERWEISE: compile_desc, desc_call_func, T_FILTER_FUNCV,
          T_FILTER_CALL_OTHER, T_FILTER_CALL_OTHERV, T_FILTER_CL, T_FILTER_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FILTER_FUNCV
DEKLARATION: T_FILTER_FUNCV(func, pars)
BESCHREIBUNG:
T_FILTER_FUNCV ist ein Filter fuer Beschreibungen. Dabei wird
die Funktion 'func' mit dem zu filternden Text und den Elementen aus 'pars'
als weitere Parameter aufgerufen, das Ergebnis wird in die Beschreibung
uebernommen.
VERWEISE: compile_desc, desc_call_func, T_FILTER_FUNC, 
          T_FILTER_CALL_OTHER, T_FILTER_CALL_OTHERV, T_FILTER_CL, T_FILTER_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FILTER_CALL_OTHER
DEKLARATION: T_FILTER_CALL_OTHER(obj, func)
BESCHREIBUNG:
T_FILTER_CALL_OTHER ist ein Filter fuer Beschreibungen. Dabei wird
die Funktion 'func' im Objekt 'obj' mit dem zu filternden Text aufgerufen,
das Ergebnis wird in die Beschreibung uebernommen.
VERWEISE: compile_desc, desc_call_func, T_FILTER_CALL_OTHERV,
          T_FILTER_FUNC, T_FILTER_FUNCV, T_FILTER_CL, T_FILTER_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FILTER_CALL_OTHERV
DEKLARATION: T_FILTER_CALL_OTHERV(obj, func, pars)
BESCHREIBUNG:
T_FILTER_CALL_OTHERV ist ein Filter fuer Beschreibungen. Dabei wird
die Funktion 'func' im Objekt 'obj' mit dem zu filternden Text und den
Elementen aus 'pars' als weitere Parameter aufgerufen, das Ergebnis wird
in die Beschreibung uebernommen.
VERWEISE: compile_desc, desc_call_func, T_FILTER_CALL_OTHER,
          T_FILTER_FUNC, T_FILTER_FUNCV, T_FILTER_CL, T_FILTER_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FILTER_CL
DEKLARATION: T_FILTER_CL(cl)
BESCHREIBUNG:
T_FILTER_CL ist ein Filter fuer Beschreibungen. Dabei wird
die Closure 'cl' mit dem Wert, welcher der von compile_desc
generierten Closure beim Aufruf uebergeben wurde, und dem
zu filternden Text aufgerufen. Das Ergebnis wird in die
Beschreibung uebernommen.
VERWEISE: compile_desc, desc_call_cl, T_FILTER_FUNC, T_FILTER_FUNCV,
	  T_FILTER_CALL_OTHER, T_FILTER_CALL_OTHERV, T_FILTER_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_FILTER_CLV
DEKLARATION: T_FILTER_CLV(cl, pars)
BESCHREIBUNG:
T_FILTER_CLV ist ein Filter fuer Beschreibungen. Dabei wird
die Closure 'cl' mit dem Wert, welcher der von compile_desc
generierten Closure beim Aufruf uebergeben wurde, dem
zu filternden Text und den Elementen aus pars als weitere
Parameter aufgerufen. Das Ergebnis wird in die Beschreibung
uebernommen.
VERWEISE: compile_desc, desc_call_cl, T_FILTER_FUNC, T_FILTER_FUNCV,
          T_FILTER_CALL_OTHER, T_FILTER_CALL_OTHERV, T_FILTER_CL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TEXT_FUNC
DEKLARATION: T_TEXT_FUNC(func)
BESCHREIBUNG:
T_TEXT_FUNC ruft die Funktion 'func' auf und fuegt das Ergebnis
in die Beschreibung ein.
VERWEISE: compile_desc, desc_call_func, T_TEXT_FUNCV,
          T_TEXT_CALL_OTHER, T_TEXT_CALL_OTHERV, T_TEXT_CL, T_TEXT_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TEXT_FUNCV
DEKLARATION: T_TEXT_FUNCV(func, pars)
BESCHREIBUNG:
T_TEXT_FUNCV ruft die Funktion 'func' mit den Elementen aus 'pars' als
Parameter auf und fuegt das Ergebnis in die Beschreibung ein.
VERWEISE: compile_desc, desc_call_func, T_TEXT_FUNC,
          T_TEXT_CALL_OTHER, T_TEXT_CALL_OTHERV, T_TEXT_CL, T_TEXT_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TEXT_CALL_OTHER
DEKLARATION: T_TEXT_CALL_OTHER(obj, func)
BESCHREIBUNG:
T_TEXT_CALL_OTHER ruft die Funktion 'func' im Objekt 'obj' auf und fuegt das
Ergebnis in die Beschreibung ein.
VERWEISE: compile_desc, desc_call_func, T_TEXT_CALL_OTHERV,
          T_TEXT_FUNC, T_TEXT_FUNCV, T_TEXT_CL, T_TEXT_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TEXT_CALL_OTHERV
DEKLARATION: T_TEXT_CALL_OTHERV(obj, func, pars)
BESCHREIBUNG:
T_TEXT_CALL_OTHERV ruft die Funktion 'func' im Objekt 'obj' mit den Elementen
aus 'pars' als Parameter auf und fuegt das Ergebnis in die Beschreibung ein.
VERWEISE: compile_desc, desc_call_func, T_TEXT_CALL_OTHER,
          T_TEXT_FUNC, T_TEXT_FUNCV, T_TEXT_CL, T_TEXT_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TEXT_CL
DEKLARATION: T_TEXT_CL(cl)
BESCHREIBUNG:
T_TEXT_CL ruft die Closure 'cl' auf und fuegt das Ergebnis in die
Beschreibung ein. Die Closure erhaelt als ersten Parameter den Wert,
welcher der von compile_desc generierten Closure beim Aufruf uebergeben
wurde.
VERWEISE: compile_desc, desc_call_cl, T_TEXT_FUNC, T_TEXT_FUNCV,
          T_TEXT_CALL_OTHER, T_TEXT_CALL_OTHERV, T_TEXT_CLV
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TEXT_CLV
DEKLARATION: T_TEXT_CLV(cl, pars)
BESCHREIBUNG:
T_TEXT_CLV ruft die Closure 'cl' auf und fuegt das Ergebnis in die
Beschreibung ein. Die Closure erhaelt als ersten Parameter den Wert,
welcher der von compile_desc generierten Closure beim Aufruf uebergeben
wurde. Die Elemente aus 'pars' werden als weitere Parameter uebergeben.
VERWEISE: compile_desc, desc_call_cl, T_TEXT_FUNC, T_TEXT_FUNCV,
          T_TEXT_CALL_OTHER, T_TEXT_CALL_OTHERV, T_TEXT_CL
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TAG
DEKLARATION: T_TAG(flag)
BESCHREIBUNG:
Dies ist ein Hinweis fuer compile_desc, dass es den Schluessel 'flag'
in das Mapping 'tags' (siehe compile_desc) aufnehmen soll.
VERWEISE: compile_desc, T_TAGVAL, T_TAG_COND
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TAGVAL
DEKLARATION: T_TAG(flag, val)
BESCHREIBUNG:
Dies ist ein Hinweis fuer compile_desc, dass es den Schluessel 'flag'
mit dem Wert 'val' in das Mapping 'tags' (siehe compile_desc) aufnehmen soll.
VERWEISE: compile_desc, T_TAG, T_TAGVAL_COND
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TAG_COND
DEKLARATION: T_TAG_COND(flag, cond)
BESCHREIBUNG:
Dies ist eine Kombination aus T_TAG(flag) und der Bedingung 'cond'.
Achtung: 'flag' wird unabhaengig vom Status der Bedingung 'cond'
(welche ja noch nicht ausgewertet wird) in das Mapping 'tags' aufgenommen.
VERWEISE: compile_desc, T_TAG, T_TAGVAL_COND
GRUPPEN: beschreibung
*/
/*
FUNKTION: T_TAGVAL_COND
DEKLARATION: T_TAGVAL_COND(flag, val, cond)
BESCHREIBUNG:
Dies ist eine Kombination aus T_TAGVAL(flag, val) und der Bedingung 'cond'.
Achtung: 'flag' wird unabhaengig vom Status der Bedingung 'cond'
(welche ja noch nicht ausgewertet wird) in das Mapping 'tags' aufgenommen.
VERWEISE: compile_desc, T_TAGVAL, T_TAG_COND
GRUPPEN: beschreibung
*/

#endif
