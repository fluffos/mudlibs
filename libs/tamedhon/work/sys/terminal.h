//
// Wunderland Mudlib
//
// sys/terminal.h  --  terminal defines
//
// basierend auf Morgengrauen Mudlib
//
// $Log: terminal.h,v $
// Revision 1.9  2004/02/18 07:59:17  Fiona
// UTF-8 Umlaute
//
// Revision 1.8  2002/08/09 09:39:28  Fiona
// Neue Zeichentabelle fuer MS CP 437/850
//
// Revision 1.7  2002/02/26 09:46:19  Fiona
// *** empty log message ***
//

#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#define BEEP		"\a"
#define ESC		"\e"
#define VTAB		"\011"  // Ascii <VT> oktal 013
#define FORMFEED	"\f"
#define NL		"\n"
#define CR              "\r"
#define CLS             ESC"[2J"ESC"[H"

#define BOLD		ESC"[1m"
#define UNDERSCORE	ESC"[4m"
#define BLINK		ESC"[5m"
#define INVERSE		ESC"[7m"
#define NORMAL		ESC"[0m"

// die erste Sequenz ist von Holger (ISO 8859-1 / Latin 1)
// die zweite Sequenz stammt von Ian@Regenbogen (MS CP437 / DOSLatinUS)
//     bzw (MS CP850 / DOSLatin1) aus Dos-Fenster von Windows
#define DIGRAPH_FROM    "\228\196\246\214\252\220\223" \
                        "\132\142\148\153\129\154\225"
#define DIGRAPH_TO      "aeAeoeOeueUess" \
                        "aeAeoeOeueUess"

// Zweibyte UTF-8 Sequenzen, jeweils mit 195 davor
#define UTF_8_FROM      "\164\132\182\150\188\156\159"
#define UTF_8_TO        "aeAeoeOeueUess"

#endif // __TERMINAL_H__
