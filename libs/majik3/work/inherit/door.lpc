inherit BASE;
int id(string str)
{
    if(str==this_object()->query_name())
	return 1;
}

int locked;
int closed;
int door_strength;
int lock_diff;

string keycode;
string short_desc;
string long_desc;
string name;

void set_locked() { locked=1;}
void set_closed() { closed=1;}
void set_open() { closed=0;}
void set_unlocked() { locked=0;}
void set_door_strength(int i) { door_strength=i;}
void set_lock_difficulty(int i) { lock_diff=i;}
void set_key(string s) { keycode=s;}
void set_short(string s) { short_desc=s;}
void set_long(string s) { long_desc=s;}
void set_name(string s) { name=s;}

int query_locked() { return locked;}
int query_closed() { return closed;}
int query_door_strength() { return door_strength;}
int query_lock_difficulty() { return lock_diff;}

string query_key() { return keycode;}
string query_name() { return name;}

int fit_lock(object key)
{
    if(key->query_keycode()==keycode)
	return 1;
    return 0;
}

string short()
{
    string msg;
    msg=short_desc;
    msg+=" (";
    if(closed)
	msg+="closed)";
    else
	msg+="open)";
    return msg;
}

string long()
{
    string msg;
    msg=long_desc;
    msg+="The door is ";
    if(closed)
	msg+="closed";
    else
	msg+="open";
    msg+=" and ";
    if(locked)
	msg+="locked";
    else
	msg+="unlocked";
    msg+=".\n";
    return msg;
}

void create()
{
    this_object()->create_door();
    this_object()->reset(0);
}
void clean_up()
{
    return 0;
}
