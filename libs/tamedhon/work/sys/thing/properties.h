// SilberLand MUDlib
//
// sys/thing/properties.h -- property system definitions
//
// $Date: 1997/03/31 16:02:25 $
/* $Revision: 3.0 $
 * $Log: properties.h,v $
 * Revision 3.0  1997/03/31 16:02:25  Woody
 * prepared for revision control
 *
 * Revision 2.8  1995/06/13  14:07:28  Jof
 * *** empty log message ***
 *
 * Revision 2.7  1995/06/06  20:33:49  Jof
 * SETCACHED/QUERYCACHED
 *
 * Revision 2.6  1995/05/15  06:57:59  Jof
 * added 2 flags
 *
 * Revision 2.5  1994/11/21  14:43:13  Kirk
 * F_MODE_AD and F_MODE_AS added
 *
 * Revision 2.4  1994/06/13  06:52:23  Jof
 * NOSETMETHOD defined
 *
 * Revision 2.3  1994/05/05  19:19:19  Jof
 * Removed ExistsProp
 *
 * Revision 2.2  1994/03/17  21:14:18  Jof
 * SECURED inserted
 *
 * Revision 2.1  1994/03/09  21:46:57  Hate
 * *** empty log message ***
 *
 *
 * Revision 1.1  1994/01/18  01:06:42  mud
 * Initial revision
 *             
 */                            

#ifndef __THING_PROPERTIES_H__
#define __THING_PROPERTIES_H__

// properties

#define P_UID   "uid"
#define P_EUID  "euid"

// special defines

#define F_VALUE         0
#define F_MODE          1
#define F_SET_METHOD    2
#define F_QUERY_METHOD  3
#define F_MODE_AS       4
#define F_MODE_AD       5

#define SAVE            64
#define PROTECTED       128  // only this_object() can change the values
#define SECURED         256  // like PROTECTED, but never resetable
#define NOSETMETHOD     512  // Keine Set-Methode => Nicht mofifizierbar
#define SETMNOTFOUND    1024 // Keine Set-Methode gefunden
#define QUERYMNOTFOUND  2048 // Keine Query-Methode gefunden
#define QUERYCACHED     4096
#define SETCACHED       8192

#endif // __THING_PROPERTIES_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_PROPERTIES_H_PROTO__
#define __THING_PROPERTIES_H_PROTO__

// prototypes

// direct property access
varargs mixed Set(string name, mixed Value, int Type); 
varargs mixed Query(string name, int Type);

// filtered property access
mixed SetProp(string name, mixed Value);
mixed QueryProp(string name);

// global property handling
void SetProperties(mapping props);
mapping QueryProperties();

public void _set_save_data(mixed data);
public mixed _get_save_data();

#endif // __THING_PROPERTIES_H_PROTO__

#endif // NEED_PROTOTYPES
