// Neat little simul-efun that is to be used instead of present-efun.
// Takes 4 arguments:
// 1st: Id of the desired object; if it contains trailing number
//	("object 4") means we want the n:th (in this case, 4th)
//	item that has matching id ("object" in this case). Same as
//	1st arg for present()-efun.
// 2nd: Object in which to search for the object. Same as 2nd arg
//	for present()-efun
// 3rd: Object that is testing for existence of the object; often
//	this_player(). For example, if player entered command
//	"take object", this argument will be the player object
//	in question.
// 4th: Invisibility level we are able to see; levels defined by
//	<invis_levels.h>. If we should only see 'normal', non-invisible
//	objects, we'll use 0.

object
present4(string Id, object where, object who, int iflags)
{
    int i, x, c;
    object ob;
    if (!stringp(Id)) return 0;
    // Id can contain trailing number ("object 2" and alike)...
    if (Id[<1] >= '0' && Id[<1] <= '9') {
	x = sizeof(Id);
	while (--x && (c = Id[x]) >= '0' && c <= '9')
	    i = i * 10 + (c - '0');
	while (x && Id[x] == ' ')	// Let's also skip spaces...
	    x--;
	Id = Id[0..x];
	i--;
    }
    ob = first_inventory(where);
    while (ob) {
	if (ob != who && ob->id(Id, iflags, who)) {
	    if (!i--)
		return ob;
	}
	ob = next_inventory(ob);
    }
    return 0;
}
