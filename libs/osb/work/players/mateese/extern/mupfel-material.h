// MorgenGrauen MUDlib
//
// THING/MATERIAL.H -- material handling
//
// Version 0.1	21.07.95	Mupfel
// Behandelt Materialien, aus denen Objekte bestehen
// (z.B. ein Knueppel aus Holz, oder eine Kugel aus Glas)
// Version 0.2	24.07.95	Mupfel
// Materialtypen Keramik, Horn, 'magisch'
// Version 0.3  17.08.95	Mupfel
// Konstanten etwas umsortiert
 
#ifndef __THING_MATERIAL_H__
#define __THING_MATERIAL_H__

// properties
#define P_MATERIAL     "material"

// special defines
// Eine Waffe mit Holzgriff koennte MAT_IRON | MAT_WOOD haben

#define MAT_UNKNOWN	0x0000	// Defaulteinstellung
// 'lebende' Materialien
#define MAT_WOOD	0x0001	// Holz
#define MAT_HORN	0x0002	// Horn
#define MAT_LEATHER	0x0004	// Leder
#define MAT_CLOTH	0x0008	// (Kleidungs-)Stoff
// 'tote' Materialien
#define MAT_STONE	0x0010	// Stein
#define MAT_GLASS	0x0020	// Glas
#define MAT_METAL	0x0040	// Metall, unspezifiziert
// Metalle
#define MAT_IRON	0x0100	// Eisen und Stahl
#define MAT_SILVER	0x0200	// Silber
#define MAT_GOLD	0x0400	// Gold
// Spezielle Materialien
#define MAT_CERAMIC	0x1000	// Keramik
#define MAT_SPECIAL	0x2000	// Bereitgestellt von der Alchimie :-)
#define MAT_MAGIC	0x4000	// 'magisch', z.B. eine Keule aus Wasser


#endif // __THING_MATERIAL_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_MATERIAL_H_PROTO__
#define __THING_MATERIAL_H_PROTO__

// prototypes
// (zur Zeit keine)

#endif // __THING_MATERIAL_H_PROTO__

#endif // NEED_PROTOYPES





