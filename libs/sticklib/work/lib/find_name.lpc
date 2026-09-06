/*
 * Library function to get a name of an object.
 *
 * Copyright (c) 1993 The Stickmud Project,
 * All rights reserved.
 *
 */
#include <cmd.h>

/* Non-zero flag: we assume it's alive */
nomask string
find_name(object ob, int flag)
{
    string name;

    if (!ob) return (flag ? "Someone" : "Something");

    if (!(name = (string) ob -> query_name()) || name == "")
	name = (string) ob -> short();
    if (!name || name == "")
	return flag ? "Invisible creature" : "Invisible thing";
    return name;
}
