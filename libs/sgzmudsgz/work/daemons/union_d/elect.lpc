private mapping old_jury;
private string * jury;

void save_data();

string * list_old_jury()
{
    return keys(old_jury);
}
string * list_jury()
{
    return jury;
}
string * check_old_jury()
{
    if ( sizeof(old_jury) ) {
    	foreach(string s in keys(old_jury) ) {
            old_jury[s] = old_jury[s]+1;
    	}
    }
    old_jury = filter_mapping(old_jury, (: old_jury[$1]<=3 :) );
    save_data();

    return keys(old_jury);
}
void elect()
{
    int i, j, r1, r2, a1, a2;
    string s, s1, *ss, *ppl;

    ppl = filter_array(CHAR_D->list_chars(), (: CHAR_D->get_char($1,"rankroyal")!=0 :));
    map_array(ppl, (: CHAR_D->set_char($1, "rankroyal", 0 ) :) );
    ppl = filter_array(CHAR_D->list_chars(), (: CHAR_D->get_char($1,"ranknation")
	&&CHAR_D->get_char($1, "type")==1 :));

    for(i=0; i<sizeof(ppl)-1; i++){
        s = ppl[i];
        ss= ppl[i+1..];
        for(j=0; j<sizeof(ss); j++ ){
            s1 = ss[j];
            r1 = OFFICER_D->query_level(CHAR_D->get_char(s,"ranknation"));
            r2 = OFFICER_D->query_level(CHAR_D->get_char(s1,"ranknation"));
            a1 = CHAR_D->get_char(s,"literate");
	    a2 = CHAR_D->get_char(s1,"literate");
            if( r1<r2 || (r1==r2&&a1<a2) ) {
		ppl[i] = s1;
                ppl[i+1+j] = s;
                s = s1;
	    }
	}
    }
    ppl = filter_array(ppl, (: !wizardp($1) :));
    ppl = ppl - check_old_jury();
    if ( sizeof(ppl)<10 ) return;
    jury= ppl[0..9];

    for(i=0; i<sizeof(jury); i++){
        CHAR_D->set_char(jury[i], "rankroyal", i+1);
        old_jury[jury[i]] = 1;
    }

    save_data();
} 
