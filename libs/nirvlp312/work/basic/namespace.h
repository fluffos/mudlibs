/*
 * basic/namespace.h
 */

#ifndef _basic_namespace_h
#define _basic_namespace_h

void add_namespace(mixed key);
status set_namespace(mixed keys, mixed data);
mixed get_namespace(mixed keys);

mixed export_namespace();
void import_namespace(mixed import);

#endif /* _basic_namespace_h */
