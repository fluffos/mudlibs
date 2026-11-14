// SilberLand MUDlib
//
// sys/unit.h -- standard unit header
//
// $Date: 1997/10/19 19:38:01 $
/* $Revision: 1.1 $
 * $Log: unit.h,v $
 * Revision 1.1  1997/10/19 19:38:01  Woody
 * Initial revision
 *
 */

#ifndef __UNIT_H__
#define __UNIT_H__

// defines
// properties
#define P_AMOUNT                "amount"
#define P_VALUE_PER_UNIT        "value_per_unit"
#define P_WEIGHT_PER_UNIT       "weight_per_unit"
#define P_GIVEN_AMOUNT          "u_ga"
#define P_GIVEN_OBJECT          "u_go"
#define P_REQUESTED_AMOUNT      "u_req"

#endif // __UNIT_H__

#ifdef NEED_PROTOTYPES

#ifndef __UNIT_H_PROTO__
#define __UNIT_H_PROTO__

// prototypes
void AddSingularId(mixed id);
void AddPluralId(mixed id);
void RemoveSingularId(mixed id);
void RemovePluralId(mixed id);
varargs void SetCoinsPerUnits(int coins, int units);
varargs void SetGramsPerUnits(int grams, int units);
int *QueryCoinsPerUnits();
int *QueryGramsPerUnits();
void AddAmount(int am);
int IsUnit();
void NotifyClone(object other);

#endif // __UNIT_H_PROTO__

#endif  // NEED_PROTOYPES

