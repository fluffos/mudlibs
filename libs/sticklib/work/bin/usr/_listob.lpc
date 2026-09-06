// List cloned objects
// Haw 260497
#include "/sys/interactive_info.h"


#include <cmd.h>
#include <config.h>

#define LOOP_LEN 4000

status 
listob_cmd(string s)
{
    object ob, ob2;
    string env, fname, fn, res, sh;
    int i, lim, ulim, count;

    if(!CHECK) return 0;

    if(!s)
	return notify_fail("Usage: listob <path/filename> [llim]\n"),0;
    else if(sscanf(s, "%s %d", fname, ulim) != 2)
	if(sscanf(s, "%s", fname) != 1)
	    return notify_fail("Illegal argument(s).\n"),0;

    if(fname[0] == '/')
	fname = fname[1..];
    if(!ulim) {
	i = lim - LOOP_LEN;
	if(i <= 0)
	    i = 1;
    } else if(ulim < lim)
	i = ulim;
    if(lim > i + LOOP_LEN)
	lim = i + LOOP_LEN;

    res = sprintf("Loop range: %d..%d\nCloned objects of %s:\n\n",
      i, lim, fname);
    if((ob = find_object(fname)) && (ob2 = environment(ob)))
	res = sprintf("%sMaster object is in %s.", res,
	  (interactive_info(ob2, II_IP_NUMBER) ?
	    sprintf("PLR(%s)", ob2->query_real_name()) :
	    sprintf("OBJ(%s)", object_name(ob2))));

    while(i < lim) {
	if((ob = find_object(fname + "#" + i))) {
	    if(interactive_info(ob, II_IP_NUMBER))
		sh = capitalize((string)ob->query_real_name());
	    else if(!(sh = (string)ob->query_short()))
		sh = (string)ob->short();
	    if(!sh)
		sh = "(INVISIBLE OBJECT)";
	    res = sprintf("%s%s -> %s", res, object_name(ob), sh);

	    if((ob2 = environment(ob)))
		env = object_name(ob2);
	    else
		env = "null";
	    if(sscanf(env, PATH_USER_FNAME+"%s", fn))
		env = "~" + fn;
	    res = sprintf("%s\n-- is in %s.\n", res,
	      (interactive_info(ob2, II_IP_NUMBER) ?
		sprintf("PLR(%s)", ob2->query_real_name()) :
		sprintf("OBJ(%s)", env)));

	    count++;
	}
	i++;
    }

    res = sprintf("%s\nTotal of %d matches found.", res, count);
    this_player()->tell_me(res);

    return 1;
}
