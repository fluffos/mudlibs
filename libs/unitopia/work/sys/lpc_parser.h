// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/lpc_parser.h
// Description:	Defines fuer den LPC-Parser
// Author:	Gnomi (2000)
//
// $Log: lpc_parser.h,v $
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_PARSER_H
#define LPC_PARSER_H 1

/*
 Damit wird dem Parser der Zugriff auf globale Variablen im aktuellen
 Programm gestattet. Dazu muss in einer einzelnen Zeile stehen:
  LPC_PARSER_VARS
 Falls ein inheritetes Objekt bereits den Zugriff gestattete, muss
 LPC_PARSER_IVARS stattdessen genutzt werden.
*/

#define LPC_PARSER_VARS nosave mixed parser_get_symbol_variable(mixed arg) {return symbol_variable(arg);}
#define LPC_PARSER_IVARS nosave mixed parser_get_symbol_variable(mixed arg) {return symbol_variable(arg)||::parser_get_symbol_variable(arg};}

#endif // LPC_PARSER_H
