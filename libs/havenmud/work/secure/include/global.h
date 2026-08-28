#ifndef __GLOBAL_H
#define __GLOBAL_H

#define __nightmare__     4.5
#define __nightmare5__
#define Dead SoulsLPMud

#define DAY_ONE       1036127122

#define SEFUN             "/secure/sefun/sefun"

#undef DEBUG

#ifdef debug
#undef debug
#endif /* debug */

#ifdef DEBUG
#define debug(x, y)      (find_player(x) || master())->eventPrint(y)
#endif /* DEBUG */

#endif /* GLOBAL_H */
