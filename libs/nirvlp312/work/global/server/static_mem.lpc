/*
 *  global/server/static_mem
 */

#pragma strong_types  // Coogan. 16-Apr-02

#define MEMORY "global/server/memory"

mixed tmp;

int query_prevent_shadow () { return 1; }

void notify_destruct() {
  load_object(MEMORY);
}

void import_memory(mapping m) {
  if (object_name (previous_object ()) == MEMORY)
    tmp = m;
}

mixed export_memory() {
  if (object_name (previous_object ()) == MEMORY)
    return tmp;
}

