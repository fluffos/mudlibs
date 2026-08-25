#define MEETING_ROOM ""

void punish_min(string *ss);
void reward_all_min(mapping jury);
int check_judge(mapping jury);
string * check_ministers(mapping jury);

void punish_min(string *ss)
{
    if( !sizeof(ss) ) return;
    foreach ( string s in ss ) {
	int rep = CHAR_D->get_char(s, "reputation");
        rep = to_int(rep/10);
        if ( rep>20000 ) rep = 20000;	
        CHAR_D->set_char(s, "reputation", CHAR_D->get_char(s, "reputation")-rep);
    }
}
void reward_all_min(mapping jury)
{
    int rep;
    object o;

    if ( !sizeof(jury) ) return;
    foreach ( string s in keys(jury) ) {
 	rep = CHAR_D->get_char(s, "reputation");
	rep = to_int(rep/20);
	if ( rep>5000 ) rep = 5000;
	CHAR_D->set_char(s, "reputation", CHAR_D->get_char(s, "reputation")+rep);
	o = new("/sgdomain/obj/other/shoyu");
        if( objectp(find_body(s)) )
	    o->move(find_body(s));
        else destruct( o );
    }
}
int check_judge(mapping jury)
{
    int judge;
    foreach(string s in keys(jury) ) 	
	judge+=jury[s];
    if ( judge > 5 ) return 1;
    if ( judge <-5 ) return -1;
}
string * check_ministers(mapping jury)
{
    string *ret = ({ });
    foreach ( string s in keys(jury) ) {
	if ( !objectp(present(s, load_object(MEETING_ROOM))) )
	    ret += ({ s });
    }
    return ret;
}
