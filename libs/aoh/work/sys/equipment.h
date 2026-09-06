#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H 1

// Usage modes of the equipment.

#define EQM_NONE  0
#define EQM_WEAR  1
#define EQM_WIELD 2
#define EQM_BOTH  3

#define EQM_MUTUAL 4 // Binary flag

// Binary flag values for the Wield()/Wear() functions.

#define EWF_NONE    0
#define EWF_WEAPON  1
#define EWF_SILENT  2

// Fields in the Wield/Weardata arrays.

#define EQD_DO    0
#define EQD_UNDO  1
#define EQD_ADJ   2

// Return values of Wield(), Unwield(), Wear(), Unwear()

#define EQ_OK       0
#define EQ_MUTUAL   1
#define EQ_ALREADY  2
#define EQ_FORBID   3
#define EQ_NOHANDS  4
#define EQ_SMALL    5
#define EQ_LARGE    6
#define EQ_ERROR    7

#endif
