/*    /adm/daemons/terminal.c
 *    from TMI-2
 *    holds terminal colour translation information
 *    created by Descartes of Borg 93????
 *    using the colour code protocol developed by Pinkfish@Discworld
 */


#define ANSI(p) sprintf("%c["+(p)+"m", 27)
#define ESCMAC(p) sprintf("%c"+(p), 27)

nosave mapping term_info;

void create() {
    term_info = ([ "unknown":
      ([ "RESET": "", "BOLD": "", "FLASH":"", "BLACK":"", "RED":"", "BLUE":"",
      "CYAN":"", "MAGENTA":"", "ORANGE":"", "YELLOW":"", "GREEN":"",
      "WHITE":"", "BLACK":"", "B_RED":"", "B_ORANGE":"", "B_YELLOW":"",
      "B_BLACK":"", "B_CYAN":"","B_WHITE":"", "B_GREEN":"",
      "B_MAGENTA":"", "STATUS":"", "WINDOW":"", "INITTERM": "","ENDTERM":""]),
      "ansi": ([ "RESET":ANSI("0;37;40"), "BOLD":ANSI(1), "FLASH":ANSI(5),
      "BLACK":ANSI(30), "RED":ANSI(31), "GREEN":ANSI(32), "ORANGE":ANSI(33),
      "YELLOW":ANSI(1)+ANSI(33), "BLUE": ANSI(34), "CYAN":ANSI(36),
      "MAGENTA":ANSI(35), "BLACK":ANSI(30), "WHITE": ANSI(37),
      "B_RED":ANSI(41), "B_GREEN":ANSI(42), "B_ORANGE":ANSI(43),
      "B_YELLOW":ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
      "B_CYAN":ANSI(46), "B_BLACK":ANSI(40), "B_WHITE": ANSI(47),
      "B_MAGENTA":ANSI(45), "STATUS":"", "WINDOW":"", "INITTERM":ESCMAC("[H")+ESCMAC("[2J"),
      "ENDTERM":"" ]),
      "freedom": ([ "RESET": ESCMAC("G0"), "BOLD":ESCMAC("G@"), "FLASH":ESCMAC("G2"),
      "BLACK":"", "RED":"", "GREEN":"", "ORANGE":"", "YELLOW":"", "BLUE":"",
      "CYAN":"", "MAGENTA":"", "BLACK":"", "WHITE":"", "B_RED":ESCMAC("GD"),
      "B_GREEN": ESCMAC("GD"), "B_ORANGE":ESCMAC("G4"), "B_YELLOW":ESCMAC("G4"),
      "B_BLUE":ESCMAC("G4"), "B_CYAN":ESCMAC("GD"), "B_BLACK": ESCMAC("GD"),
      "B_WHITE":ESCMAC("G4"), "B_MAGENTA":("G4"), "STATUS":"", "WINDOW":"",
      "INITTERM":"", "ENDTERM":"" ]),
      "ansi-status": ([ "RESET": ANSI("0;37;40"), "BOLD":ANSI(1),
      "FLASH":ANSI(5), "BLACK":ANSI(30), "RED":ANSI(31),
      "GREEN":ANSI(32), "ORANGE":ANSI(33), "YELLOW":ANSI(33), "BLUE":ANSI(34),
       "CYAN": ANSI(36), "MAGENTA": ANSI(35), "BLACK":ANSI(30),
      "WHITE":ANSI(37), "B_RED":ANSI(41), "B_GREEN":ANSI(42),
      "B_ORANGE":ANSI(43), "B_YELLOW": ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
      "B_CYAN": ANSI(46), "B_BLACK":ANSI(40), "B_WHITE":ANSI(47),
      "B_MAGENTA":ANSI(45), "STATUS":ESCMAC("[23;24r")+ESCMAC(8),
      "WINDOW":ESCMAC(7)+ESCMAC("[0;22r")+ESCMAC("[22H\n"),
      "INITTERM":ESCMAC("[H")+ESCMAC("[J")+ESCMAC("[23;24r")+ESCMAC("23H\n"),
      "ENDTERM":ESCMAC("[0r")+ESCMAC("[H")+ESCMAC("[J") ]),
      "xterm": ([ "RESET": ESCMAC(">")+ESCMAC("[1;3;4;5;61")+ESCMAC("[?7h")+ESCMAC("[m"),
      "BOLD": ESCMAC("[7m"), "FLASH":ESCMAC("[5m$<2>"), "BLACK":ANSI(30),
      "RED":ANSI(31), "GREEN":ANSI(32), "ORANGE":ANSI(33), "YELLOW":ANSI(33),
      "BLUE":ANSI(34), "CYAN":ANSI(36), "MAGENTA":ANSI(35),"BLACK":ANSI(34),
      "WHITE":ANSI(38), "B_RED":ANSI(41), "B_GREEN":ANSI(42),
      "B_ORANGE":ANSI(43), "B_YELLOW":ANSI(43), "B_BLUE":ANSI(44),
      "B_CYAN":ANSI(46), "B_BLACK":ANSI(40), "B_WHITE": ANSI(47),
      "B_MAGENTA": ANSI(45), "STATUS":"", "WINDOW":"", "INITTERM":"",
      "ENDTERM":"" ]),
    ]);
}
mapping query_term_info(string type) {
    return (term_info[type] ? term_info[type] : term_info["unknown"]);
}

string *query_terms() { return keys(term_info); }

int query_term_support(string str) {
    return (term_info[str] ? 1 : 0);
}

#include <ansi.h>


string strip_ansi (string str) {
    int i,j ;
    string *strippable ;
// Initialize this array once at the start.
    strippable = ({ BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
	HIK, HIR, HIG, HIY, HIB, HIM, HIC, HIW,
	BBLK, BRED, BGRN, BYEL, BBLU, BMAG, BCYN, BWHT,
	HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
	NOR, BOLD, CLR, HOME, REF, BIGTOP, BIGBOT, SAVEC, REST,
	REVINDEX, SINGW, DBL, FRTOP, FRBOT, UNFR, BLINK, U ESC,
	REV ESC, HIREV ESC }) ;
// Find the first occurence of ESC in the string.
    i = strsrch(str,ESC) ;
// If none, return the string.
    if (i==-1) return str ;
// OK, there is one. Does it match a recognized ansi sequence?
// shortest legal sequence is 3 chars: longest is 9
    for (j=2;j<9;j++) {
// If we've hit the end of the string, then return the previous bit.
	if (i+j==strlen(str)) return str[0..i-1] ;
// If not, then see if the part of the string from i to i+j is ansi.
	if (member_array(str[i..i+j],strippable)>-1) {
// Found one. Delete it and look for another.
	    if (i==0) {
		str = str[j+1..<1] ;
	    } else {
		if (i+j==strlen(str)-1) {
		    str = str[0..i-1] ;
		} else {
	    	    str = str[0..i-1]+str[i+j+1..<1] ;
		}
	    }
	    return strip_ansi(str) ;
	}
    }
// If we get here, it means we found an ESC in the string but it didn't
// match any recognized ansi sequence.
// I'm not real sure what to do: I'm just going to strip out the ESC
// and let the rest through.
    if (i==0) {
	str = str[1..<1] ;
    } else {
	if (i=sizeof(str)-1) {
	    str = str[0..i-1] ;
	} else {
	    str = str[0..i-1] + str[i+1..<1] ;
	}
    }
    return strip_ansi(str) ;
}

//      Filter to remove the colour % ^ COLOR % ^ protocol from a string
//      and return the 'clean' string.
//      Author: Chuck @ Crossed Swords [pgregg@nyx10.cs.du.edu]
//      If you use this code please leave this header intact.

string filter_colours(string str) {
  string tmp;
   str = strip_ansi(str) ;
  while (sscanf(str, "%*s%%^%s%%^%*s", tmp) > 2)
    str = replace_string(str, "%^"+tmp+"%^", "");
  return str;
}
