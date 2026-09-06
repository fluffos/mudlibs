/*
 * magic.h - it's a kind of magic
 *
 * Defines the Arts and Forms of the magic system..
 *
 */


#ifndef _MAGIC_H
#define _MAGIC_H

/* Arts */
 
#define MA_CREO       0x0001 /* Create */
#define MA_MUTO       0x0002 /* Change - needed? */
#define MA_INTELLEGO  0x0004 /* Know */
#define MA_PERDO      0x0008 /* Destroy */
#define MA_REGO       0x0010 /* Control */
 
/* Forms */
 
#define MF_AQUAM      0x0100 /* Water, Liquid */
#define MF_AURAM      0x0200 /* Air, Weather */
#define MF_CORPOREM   0x0400 /* Body, physical appearance */
#define MF_IGNEM      0x0800 /* Fire, Light, Warm. */
#define MF_IMAGONEM   0x1000 /* Illusions, alterations */
#define MF_MENTEM     0x2000 /* Mind, Intelligence */
#define MF_TERRAM     0x4000 /* Earth, metal, all solid */
#define MF_VIM        0x8000 /* Magic */
 
#endif /* _MAGIC_H */
