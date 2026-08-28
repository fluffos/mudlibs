//	/std/living/messages.c
//	from the Nightmare mudlib
//	inheritable code for all the nifty messages of motion
//	originally from the TMI distribution mudlib

int peds_gone();

string validate(string str, string *vars) {
    string foo;
    int x, tmp;

    if( !str ) return "";
    for(x=0, tmp = sizeof(vars); x<tmp; x++)
        if(!(sscanf(str, "%s"+vars[x]+"%*s", foo)))
	    return "";
    return str;
}

string query_min() {
    int tmp;
    string str;

    str = (string)this_object()->getenv("MIN");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N enters.";
    tmp = peds_gone();
    if(tmp == 1) str = "$N enters with a limp.";
    else if(tmp) str = "$N crawls in.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    return str;
}

string query_mout(string dir) {
    int tmp;
    string str;

    str = (string)this_object()->getenv("MOUT");
    str = validate( str, ({ "$N", "$D" }) );
    if( str == "" ) str = "$N leaves $D.";
    tmp = peds_gone();
    if(tmp == 1) str = "$N limps $D.";
    else if(tmp) str = "$N crawls $D.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    if (dir == "" || dir == 0) return str;
    str = substr( str, "$D", dir );
    return str;
}

string query_mmin() {
    string str;

    str = (string)this_object()->getenv("MMIN");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N appears from the shadows.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    return str;
}

string query_mmout() {
    string str;

    str = (string)this_object()->getenv("MMOUT");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N fades into the shadows.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    return str;
}

string query_mhome() {
    string str;

    str = (string)this_object()->getenv("MHOME");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N heads home.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    return str;
}

string query_mdest(object obj) {
    string str;

    str = (string)this_object()->getenv("MDEST");
    str = validate( str, ({ "$N", "$O" }) );
    if(!str || str == "") str = "$N disintegrates $O";
    str = replace_string(str, "$N", (string)this_object()->query_cap_name());
    if (obj == 0) return str;
    if( obj->query_short() )
        str = substr( str, "$O", (string)obj->query_short() );
    else
        str = substr( str, "$O", "something" );
    return str;
}

string query_mclone(object obj) {
    string str;

	str = (string)this_object()->getenv("MCLONE");
	str = validate( str, ({ "$N", "$O" }) );
	if( str == "" ) str = "$N gets creative and makes $O.";
	str = substr( str, "$N", (string)this_player()->query_cap_name() );
       if (obj == 0) return str;
	if( obj->query_short() )
		str = substr( str, "$O", (string)obj->query_short() );
	else str = substr( str, "$O", "something" );
	return str;
}

string query_mvis() {
    string str;

    str = (string)this_object()->getenv("MVIS");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N appears out of the corner of your eye.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    return str;
}

string query_minvis() {
    string str;

    str = (string)this_object()->getenv("MINVIS");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N seems to dissapear.";
    str = substr( str, "$N", (string)this_object()->query_cap_name() );
    return str;
}

int peds_gone() {
    string blah;
    string *peds;
    int i, ret, tmp;

    peds = (string *)this_object()->query_severed_limbs();
    if(!peds) return 0;
    for(i=0, tmp = sizeof(peds); i<tmp; i++) {
        ret += sscanf(peds[i], "%sfoot%*s", blah);
        ret += sscanf(peds[i], "%spaw%*s", blah);
    }
    return ret;
}
