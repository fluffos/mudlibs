// SilberLand MUDlib
//
// /p/daemon/html.h -- HTML codes
//
// $Date: 2001/02/01 23:51:52 $
/* $Revision: 1.3 $
 * $Log: html.h,v $
 * Revision 1.3  2001/02/01 23:51:52  Woody
 * #endif syntax bugfixed
 *
 * Revision 1.2  1997/03/16 02:26:48  Woody
 * prepared for revision control
 *
 * Revision 1.1  1995/03/31  13:30:33  Hate
 * Initial revision
 *
 */

#ifndef __HTML_H__
#define __HTML_H__

#define HTMLD		"/p/daemon/htmld"	// the html parser daemon

// Error codes
#define NO_HTML_FILE    -1
#define EMPTY_FILE      -2

// regular expression to parse file
#define HTML_TAGS       "[<][^<]*[>]|[&][^&;]*[;]"

// html codes
#define H_TITLE		"title"		// document title
#define H_H1		  "h1"		// document heading
#define H_H2		  "h2"
#define H_H3		  "h3"
#define H_H4		  "h4"
#define H_H5		  "h5"
#define H_H6		  "h6"
#define H_PARAGRAPH	"p"
#define H_ANCHOR		"a"		// document reference
# define H_HREF			"href"	// anchor reference command
#define H_ULIST		"ul"		// unnumbered list
#define H_OLIST		"ol"		// enumerated list
#define H_DLIST		"dl"		// description list
#define H_LIST		"li"		// list item descriptor
#define H_PRE		  "pre"		// preformatted text
#define H_BREAK		"br"		// force line break;

#endif // __HTML_H__



