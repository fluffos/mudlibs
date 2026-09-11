mapping elect()
{
    int i, j, r1, r2, a1, a2;
    string s, s1, *ss, *ppl;
    mapping jury;

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
    if ( sizeof(ppl)<10 ) return ([ ]);
    ppl = ppl[0..9];
    jury = ([ ]);

    for(i=0; i<sizeof(ppl); i++){
        CHAR_D->set_char(ppl[i], "rankroyal", i);
 	jury[ppl[i]] = 0;
    }
       
    return jury;
} 
