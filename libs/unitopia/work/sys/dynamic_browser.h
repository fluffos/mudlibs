// This file is part of UNItopia Mudlib.
// -----------------------------------------------------------------------
//  Datei:  /sys/dynamic_browser.h
//  Autor:  Myonara 30.Okt.2012 nach einer Idee von Gnomi.
// -----------------------------------------------------------------------
// Beschreibung: Headerdatei fuer den dynamischer Browser
// -----------------------------------------------------------------------
// Aenderungen:
//  Myonara  13.Nov.2012 Mehr von allem.
//  Myonara  20.Dez.2012 Einfuehrung B_NOTHING, BF_DIRTY
//  Sorcerer 04.Jan.2013 ins P und Registry
//  Myonara  04.Jan.2013 BF_RETURN
//  Myonara  27.Apr.2013 B_HEADER_LINES
//  Myonara  01.Mai.2013 B_HEADER4HELP
//
//  $Log: dynamic_browser.h,v $
//  Revision 1.5  2016/05/30 04:40:23  myonara
//  Neues Define B_END_LINE
//
//  Revision 1.4  2013/12/01 14:45:46  myonara
//  neuer Schluessel B_SEARCH_STRING
//
//  Revision 1.3  2013/08/29 18:33:21  myonara
//  Neues Flag BF_NO_DISPLAY
//
//  Revision 1.2  2013/08/17 18:40:48  myonara
//  neue defines B_REBUILT und B_DONE
//
//  Revision 1.1  2013-05-03 16:08:03  myonara
//  Umzug von P in die Mudlib
//
//

#ifndef _DYNAMIC_BROWSER_H
#define _DYNAMIC_BROWSER_H

// Defines fuer das Menuemapping dynamic_browse
#define B_TYPE          "dynbrowse_type"
#define B_OB            "dynbrowse_ob"
#define B_START_LINE    "dynbrowse_start_line"
#define B_CURRENT_LINE  "dynbrowse_current_line"
#define B_END_LINE      "dynbrowse_end_line"
#define B_NUM_LINES     "dynbrowse_num_lines"
#define B_FLAGS         "dynbrowse_flags"
#define B_PROMPT        "dynbrowse_prompt"
#define B_DATA          "dynbrowse_data"
#define B_FILE          "dynbrowse_file"
#define B_HEADER_LINES  "dynbrowse_header_lines"
#define B_SEARCH_STRING "dynbrowse_search_string"
#define B_STATICMORE    "staticmore"
#define B_DYNAMICMORE   "dynamicmore"
#define B_HELP          "dynbrowse_help"

#define B_HEADER4HELP ({ \
"------ Hilfe: -----------------------------------------------------------------",\
"-------------------------------------------------------------------------------",\
"...-------------------------------------------------------------------- (Hilfe)",\
"...-------------------------------------------------------------------- (Hilfe)"})

// Flags fuer B_FLAGS:
#define BF_DIRTY        1
#define BF_RETURN       2
#define BF_NO_DISPLAY   4

//Rueckgabewerte fuer <type>_action
#define B_NOTHING     0
#define B_QUIT       -1
#define B_CONTINUE   -2
#define B_REDRAW     -3
#define B_REBUILT    -4
#define B_DONE       -5

#endif // _DYNAMIC_BROWSER_H
