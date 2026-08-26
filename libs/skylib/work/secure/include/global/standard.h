#ifndef __STANDARD_H
#define __STANDARD_H

#define NULL      0

#define TRUE      1
#define FALSE     0

#define TP        this_player()
#define TO        this_object()
#define TU        this_user()
#define PO        previous_object()

#define CAP(XXX)  capitalize(XXX)
#define ENV(XXX)  environment(XXX)
#define INV(XXX)  all_inventory(XXX)
#define ABS(XXX)  ((XXX < 0) ? (XXX * -1) : XXX)

#define HIM       query_objective()
#define HIS       query_possessive()
#define HE        query_pronoun()

#define CNAME     query_cap_name()
#define NAME      query_name()

#endif /* __STANDARD_H */
