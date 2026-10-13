#ifndef __DBASE__
#define __DBASE__

// This is the 'expected' dbase size, which is allocated when initial
#define DEFAULT_DBASE_SIZE                15

mapping query_entire_dbase();
mapping query_entire_temp_dbase();

// F_DBASE (feature/dbase.lpc) 的属性函数原型。
// Prototypes of F_DBASE's property functions.  A mixin that is inherited next to
// F_DBASE (equip, itemmake, dealer1 ...) must see these: without a prototype a bare
// query("x") in it compiles as the simul_efun fallback, which runs in the simul_efun
// object and reads that object's one shared dbase instead of this object's own.
varargs mixed set(string prop, mixed data, object ob);
varargs mixed query(string prop, mixed raw_or_ob);
varargs int delete(string prop, object ob);
varargs mixed set_temp(string prop, mixed data, object ob);
varargs mixed query_temp(string prop, mixed raw_or_ob);
varargs int delete_temp(string prop, object ob);
mixed add(string prop, mixed data);
mixed add_temp(string prop, mixed data);

#endif
