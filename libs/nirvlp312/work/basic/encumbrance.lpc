/*
 * /basic/encumbrance.c
 *
 */

#include <encumbrance.h>

private mixed encumbrance;

void set_encumbrance(mixed enc) {
  encumbrance = enc;
}

int query_encumbrance() {
  return funcall(encumbrance);
}

int query_weight() {
  /* This is 2.4.5 weight * standard WEIGHT_FACTOR */
  return (query_encumbrance() + WEIGHT_FACTOR - 1) / WEIGHT_FACTOR;
}

void set_weight(int w) {
  set_encumbrance(w * WEIGHT_FACTOR);
}
