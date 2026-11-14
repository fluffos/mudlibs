// SilberLand MUDlib
//
// sys/moredef.h -- some more useful defines
//
// $Date: 1997/10/20 14:59:42 $
/* $Revision: 1.3 $
 * $Log: moredef.h,v $
 * Revision 1.3  1997/10/20 14:59:42  Feyaria
 * AddProp
 *
 * Revision 1.2  1997/08/26 20:34:39  Woody
 * CLONE und CLONEME moven nun M_NOCHECK
 *
 * Revision 1.1  1997/03/31 13:08:50  Woody
 * prepared for revision control
 *
 */


#ifndef __MOREDEF_H__
#define __MOREDEF_H__

/* some more useful defines... */

#ifndef TELL
#define TELL(x,y) if (find_player(x)) tell_object(find_player(x), y)
#endif

#ifndef CAP
#define CAP capitalize
#endif

#ifndef UPPER
#define UPPER capitalize
#endif

#ifndef LOWER
#define LOWER lower_case
#endif

#ifndef TO
#define TO this_object()
#endif

#ifndef TP
#define TP this_player()
#endif

#ifndef TPN
#define TPN TP->name()
#endif

#ifndef TPP
#define TPP TP->QueryPronoun
#endif

#ifndef TPPP
#define TPPP TP->QueryPossPronoun
#endif

#ifndef CAP_TPN
#define CAP_TPN capitalize(TPN)
#endif

#ifndef TI
#define TI this_interactive()
#endif

#ifndef PO
#define PO previous_object()
#endif

#ifndef BS
#define BS(x) break_string(x, 78)
#endif

#ifndef ENV
#define ENV(x) environment(x)
#endif

#ifndef MENV
#define MENV environment(this_object())
#endif

#ifndef SUID
#define SUID seteuid(getuid(this_object()));
#endif

#ifndef CLONEME
#define CLONEME(x) clone_object(x)->move(this_object(),2);
#endif

#ifndef CLONEOB
#define CLONEOB(x) clone_object(x)
#endif

#ifndef CLONE
#define CLONE(x,y) clone_object(x)->move(y,2);
#endif

#ifndef WLOG
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
#endif

#ifndef AddProp
#define AddProp(x,y) SetProp(x,QueryProp(x)+y)
#endif

#endif /* __MOREDEF_H__ */

