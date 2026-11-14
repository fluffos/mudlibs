/*  HEADER-FILE von Impulz
 *  verwendet von den Objekten in +gebirge/impulz
 */

#ifndef __IMPULZ_H__
#define __IMPULZ_H__

#ifndef ME
#define ME this_object()
#endif

#ifndef ROOT
#define ROOT(x) "/d/gebirge/impulz/"+x
#endif

#ifndef PALWEG
#define PALWEG(x) ROOT("paladinweg/")+x
#endif

#ifndef TROLLWEG
#define TROLLWEG(x) ROOT("trollweg/")+x
#endif

#ifndef TP
#define TP this_player()
#endif

#ifndef TPN
#define TPN this_player()->name()
#endif

#ifndef TO
#define TO this_object()
#endif

#ifndef BS
#define BS(x) break_string(x)
#endif

#ifndef ENV
#define ENV(x) environment(x)
#endif

#ifndef MENV
#define MENV(x) ENV(ME)
#endif

#ifndef TELL_IMPULZ
#define TELL_IMPULZ(x) tell_object(find_player("impulz"),x)
#endif

#ifndef TOB
#define TOB(x,y) tell_object(x,y);
#endif

#ifndef CLONEME
#define CLONEME(x) clone_object(x)->move(ME,1);
#endif

#ifndef CLONE
#define CLONE(x,y) clone_object(y)->move(x,1);
#endif

#endif