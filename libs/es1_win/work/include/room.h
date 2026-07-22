
inherit "std/room";
#include <ob.h>

#define set_exits(files, dirs) set("exits", merge(dirs, files))
#define set_item_descriptions(items, desc) set("item_desc", merge(items, desc))
#define add_exit(dest, dir) add("exits", ([ dir : dest ]))



mapping merge_arrays(string *x, string *y) {
	mapping foo;
	int i;

	if (sizeof(x) != sizeof(y)) return ([]);
	foo = allocate_mapping(sizeof(y));
	for(i=0;i<sizeof(y); i++) foo[x[i]] = y[i];
	return foo;
}
		


