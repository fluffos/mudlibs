/*
 * kernel/simul/mapping.c
 * 
 * simul_efuns concerning mappings
 * Rumplemintz
 */

#include "/sys/closures.h"
#include "/kernel/simul/lpc.h"
#include "/kernel/simul/list.h"

mapping clear_mapping(mapping m) {
  return m - ([ 0 ]);
}

void dump_mapping(mapping m) {
  mixed *v, *i;
  int t;
  v = m_values(m);
  i = m_indices(m);
  for (t=0; t<sizeof(v); t++)
    write("[\"" + i[t] + "\"] :\t" + v[t] + "\n");
}

private void tidy_mapping_helper(mixed key,mapping old,mapping new) {
  int i;
  for (i=widthof(old); i--; )
    new[key,i] = old[key,i];
}

mapping tidy_mapping(mapping m) {
  mapping new;
  new = m_allocate(sizeof(m),widthof(m));
  filter_indices(m,#'tidy_mapping_helper,m,new);
  return new;
}

varargs mapping invert_mapping(mapping m, int dim) {
  return
    factorize(m_indices(m),sort_args(CL_MAPPING_INDEX,({1,0,2})),({m,dim}));
}

