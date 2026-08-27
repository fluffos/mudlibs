/*  -*- LPC -*-  */
// element.h:  element class for use with queue and other data structures
//             Using an array of these is faster than a mapping
// written by Tim 2/8/96

#ifndef _ELEMENT_H
#define _ELEMENT_H

class _element {
  mixed key;
  mixed val;
}

#define element class _element

#endif /* _ELEMENT_H */
