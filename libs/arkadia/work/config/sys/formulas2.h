/*
 * formulas2.h
 *
 * This file defines some weapon dependant defines.
 * The only use of this file is that it should be included
 * by /sys/formulas.h.
 */

#define F_LEGAL_TYPE(type)   ((type) == W_SWORD   ||  \
			      (type) == W_POLEARM ||  \
			      (type) == W_AXE	||  \
			      (type) == W_KNIFE   ||  \
			      (type) == W_CLUB	||  \
			      (type) == W_MISSILE ||  \
			      (type) == W_JAVELIN)
