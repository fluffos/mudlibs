/*
 * kernel/simul/obsolete.c
 *
 * efuns which have been declared as deprecated/obsoleted due to driver
 * development
 * Rumplemintz
 */

#pragma strong_types

#if __VERSION__ < "3.2.9-dev.300"

nomask int mapping_contains(varargs args) {
  raise_error("Usage of mapping_contains() is deprecated. "
              "Use m_contains() intead.\n");
}

nomask int query_imp_port() {
  raise_error("Usage of query_imp_port() is deprecated. "
              "Use query_udp_port() instead.\n");
}

nomask int send_imp(string host, int port, mixed message) {
  raise_error("Usage of send_imp() is deprecated. "
              "Use send_udp() instead.\n");
}

nomask int allocate_mapping(varargs args) {
  raise_error("Usage of allocate_mapping() is deprecated. "
              "Use m_allocate() instead.\n");
}

nomask void efun308(mixed a, mixed b) {
  raise_error("Usage of efun308() is deprecated. "
              "Use set_environment() instead.\n");
}

nomask varargs void file_name(object ob) {
  raise_error("Usage of file_name() is deprecated. "
              "Use object_name() instead.\n");
}

nomask mixed* filter_arry(varargs mixed *m) {
  raise_error("Usage of filter_array() is deprecated. "
              "Use filter() instead.\n");
}

nomask mixed* map_array(varargs mixed *m) {
  raise_error("Usage of map_array() is deprecated. "
              "Use map() instead.\n");
}

nomask void filter_mapping(mapping mpa, varargs mixed *m) {
  raise_error("Usage of filter_mapping() is deprecated. "
              "Use filter() resp. filter_indices() instead.\n");
}

nomask mapping map_mapping(mixed map, varargs mixed *m) {
  raise_error("Usage of map_mapping() is deprecated. "
              "Use map() resp. map_indices() instead.\n");
}

nomask int m_sizeof(mapping map) {
  raise_error("Usage of m_sizeof() is deprecated. "
              "Use sizeof() instead.\n");
}

nomask mapping copy_mapping(mapping map) {
  raise_error("Usage of copy_mapping() is deprecated. "
              "Use copy() instead.\n");
}

nomask void add_verb(string str) {
  raise_error("Usage of add_verb() is deprecated. "
              "Use the parser (/basic/parser) instead.\n");
}

nomask void add_xverb(string str) {
  raise_error("Usage of add_xverb() is deprecated. "
              "Use the parser (/basic/parser) instead.\n");
}

#endif
