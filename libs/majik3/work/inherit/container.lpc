/****
*  *    Name                            container.c
* *     Description                     Container object
**      Coder                           Dazzt
*/

inherit ITEM;

int     condimx, condimy, condimz;      /* dimensions of container space */
int     containedvol;                   
int     solid;                          /* is solid container? */

int     closable;                       /* can container be closed? */
int     closed; 
int     lockable;                       /* can it be locked? */

string  keycode;

create()
{
    no_get = 0;             worn = 0;
    weight = 0;
    this_object()->create_container();
}

query_container ()
{
  return 1;
}

void set_open() { closed = 0; }
void set_closed() { closed = 1; }
int query_closed() { return closed; }

string short()
{
    string str = short_desc;

    if (closable)
    {
	str += " (";
	if (closed)
	{
	    if (this_object()->query_locked())
		str += "locked";
	    else
		str += "closed";
	}
	else
	    str += "open";
	str += ")";
    }
    return str;
}

string long()
{
    int i;
    object *contents;
    string str = long_desc;

    str += "It looks " + query_weightstr() + ".\n";
    str += "It's in " + query_cond() + " condition.\n";

    if (closable && closed)
	{
	    str += "It is closed";
	    if (this_object()->query_locked())
		str += " and locked";
	    str += ".\n";
	}
	else
	{
		if (closable)
			str += "It is open, containing: \n";
		else
			str += "It contains:\n";
	    contents = all_inventory(this_object());
	    for (i = 0; i < sizeof(contents); i++)
		str += contents[i]->short() + "\n";
	    if (i == 0)
		str += "Nothing.\n";
    }
    return str;
}



int set_container_dimensions(int x, int y, int z)
{
    condimx = x;
    condimy = y;
    condimz = z;

    containedvol = 0;
    return x * y * z;
}

int set_dimensions(int x, int y, int z)
{
    xdim = x; ydim = y; zdim = z;
    return set_container_dimensions(x, y, z);
}

int putobj(object ob)
{
    if (ob->query_longest_dim() > query_longest_dim() ||
      ob->query_volume() > (condimz * condimy * condimz - containedvol))
	return 0;               /* check if item fits inside container */

    weight += ob->query_weight();
    containedvol += ob->query_volume();
    ob->move(this_object());
    return 1;
}

int getobj(object ob, object target)
{
    weight -= ob->query_weight();
    containedvol -= ob->query_volume();
    ob->move(target);
}

int set_solid()
{
    return solid = 1;
}

int set_closable()
{
    closable = 1;
}

int set_lockable()
{
    lockable = 1;
}


int query_solid()
{
    return solid;
}

int query_container_volume() 
{
    if (solid)
	return condimx * condimy * condimz;
    else
	return containedvol;
}

int query_lockable()
{
    return lockable;
}

int query_closable()
{
    return closable;
}
