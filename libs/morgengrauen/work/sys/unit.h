// MorgenGrauen MUDlib
//
// unit.h -- Defines fuer Units
//
// $Id: unit.h 9017 2015-01-10 19:20:14Z Zesstra $

#ifndef _UNIT_H_
#define _UNIT_H_

#define P_UNIT_DECAY_INTERVAL      "unit_decay_interval"
#define P_UNIT_DECAY_QUOTA         "unit_decay_quota"
#define P_UNIT_DECAY_FLAGS         "unit_decay_flags"
#define P_UNIT_DECAY_MIN           "unit_decay_min"

// Flags fuer P_UNIT_DECAY_FLAGS 
// verhindert das Zerfallen einzelner Unit-Objekte.
#define NO_DECAY             0x1
// kein Decay bis zum ersten move() von einem Env in ein Env. (d.h. das erste
// move() in ein Env (Clonen im create vom NPC) ist unberuecksichtigt.)
#define NO_DECAY_UNTIL_MOVE  0x2
// ungenaueren Zerfall benutzt, dabei aber immer min. eine Einheit zerfallen
// lassen.
#define INACCURATE_DECAY     0x4
// kein prozentualer Zerfall, sondern P_UNIT_DECAY_QUOTA gibt eine abs. Menge
// an Einheiten an.
#define ABSOLUTE_DECAY       0x8

#define U_GPU   "u_gpu"
#define U_CPU   "u_cpu"
#define U_IDS   "u_ids"
#define U_REQ   "u_req"

#define IS_EQUAL(x) (objectp(x) && (IsEqual(x) && x->IsEqual(ME)))

#endif // _UNIT_H_

#ifdef NEED_PROTOTYPES
#ifndef _UNIT_H_PROTYPES_
#define _UNIT_H_PROTYPES_
// public functions
varargs int    id(string str,int lvl);
        int    IsEqual(object ob);
        int    IsUnit();
varargs int    move(object|string dest, int method);
        int    *QueryCoinsPerUnits();
        int    *QueryGramsPerUnits();
varargs int remove(int silent);
varargs string long();
varargs string|<string>* name(int fall, int demo);
varargs string QueryPronoun(int casus);
        string short();
        void   AddAmount(int am);
        void   AddPluralId(mixed str);
        void   AddSingularId(mixed str);
        void   RemovePluralId(mixed str);
        void   RemoveSingularId(mixed str);
        void   reset();
        void   SetCoinsPerUnits(int coins,int units);
        void   SetGramsPerUnits(int grams,int units);
public  int    DoDecay(int silent);

// internal functions
nosave    void    check_leave();
protected void    DoDecayMessage(int oldamount, int zerfall);

// Query- und Set-Methoden
nosave  int    _query_plural();
nosave  int    _query_total_weight();
nosave  int    _query_u_req();
nosave  int    _query_value();
nosave  int    _query_weight();
nosave  string|string* _query_name();
nosave  int    _set_amount(int am);
nosave  string|string* _set_name(mixed names);
nosave  int    _set_weight(int num);
nosave  int    _set_value(int num);
nosave  int    _query_unit_decay_interval();
nosave  int    _set_unit_decay_interval(int zeit);
nosave  int    _query_unit_decay_quota();
nosave  int    _set_unit_decay_quota(int quota);
nosave  int    _query_unit_decay_min();
nosave  int    _query_unit_decay_flags();

#endif // _UNIT_H_PROTYPES_
#endif // NEED_PROTOTYPES

