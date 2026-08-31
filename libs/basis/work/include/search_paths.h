// file:   /include/search_paths.h
// mudlib: basis
// author: Truilkan
// date:   1992 September 5
// desc:   currently used by /std/living.c

#define USER_SEARCH_PATH ({ \
	"/bin/user/comm", \
	"/bin/user/senses", \
	"/bin/user/system", \
	"/bin/user/move", \
	"/bin/user/objects", \
	"/bin/user/shell", \
	"/bin/user/combat", \
	"/bin/user/driver", \
	"/bin/user/help", \
	"/bin/user/status", \
	"/bin/user/admin" \
})

#define MAKER_SEARCH_PATH ({ \
	"/bin/maker/comm", \
	"/bin/maker/system", \
	"/bin/maker/file", \
	"/bin/maker/move", \
	"/bin/maker/admin", \
	"/bin/maker/senses", \
	"/bin/maker/objects", \
	"/bin/maker/shell", \
	"/bin/maker/status", \
	"/bin/maker/driver", \
	"/bin/maker/test", \
	"/bin/maker/help" \
})

#define ADMIN_SEARCH_PATH ({ \
	"/bin/admin/admin", \
	"/bin/admin/status", \
	"/bin/admin/system", \
	"/bin/admin/objects", \
	"/bin/admin/shell", \
	"/bin/admin/file" \
})
