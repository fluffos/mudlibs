mapping elect()
{
	int i, j, r1, r2, a1, a2;
	string s, s1, *ss, *ppl,str;
	mapping jury;
	mixed * *rank=OFFICER_D->query_nation_officer_title_all(1)-({1,10,11});

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
//	jury = ([ ]);

	foreach (string o in ppl ) {
	int r;
	r=rank[random(sizeof(rank))];
	rank-=({r});
	CHAR_D->set_char(o,"royalrank",r);
	CHAR_D->set_char(o,"is_jury",1);                
}

	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：吾皇万岁万万岁，臣有一本，启奏陛下。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝：念。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：是。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：孝灵皇帝，早弃臣民，皇帝承嗣，海内仰望。而帝年少，威仪\n"+
	             "                      不恪，难免居丧慢惰。宜择良臣，为其锦囊，辅佐朝纲，应天\n"+
	             "                      顺人，以慰生灵之望。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝羞得满脸通红，恨不得找个地缝钻进去。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝：善，如此寡人便降一诏，国舅代为宣读罢。%^RESET%^\n");
	tell(users(),"\n%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^片刻后。。。%^RESET%^\n\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：奉天承运，皇帝诏曰。寡人顺应天命，择良臣而为肱股，众卿\n"+
	             "                      听封：%^RESET%^\n\n");
	foreach (string o in ppl ) {
//	tell(users(),"                      %^H_CYAN%^赐  %^H_GREEN%^"+CHAR_D->get_char(o,"name")+"%^H_CYAN%^君  %^H_YELLOW%^"+OFFICER_D->query_rank_name(CHAR_D->get_char(o,"royalrank"))+"%^H_CYAN%^一职；%^RESET%^\n");
	str=sprintf("                      %%^H_CYAN%%^赐  %%^H_GREEN%%^%-8s%%^H_CYAN%%^君  %%^H_YELLOW%%^%-8s%%^H_CYAN%%^一职；%%^RESET%%^\n",CHAR_D->get_char(o,"name"),OFFICER_D->query_rank_name(CHAR_D->get_char(o,"royalrank")));
	tell(users(),str);
	}
	tell(users(),"\n                      %^H_CYAN%^还望众卿重振汉室洪业，为万世统！%^RESET%^\n");
	tell(users(),"                                                              %^H_CYAN%^卿此。%^RESET%^\n");

//	for(i=0; i<sizeof(ppl); i++){
//	CHAR_D->set_char(ppl[i], "rankroyal", i);
//	jury[ppl[i]] = 0;
//	}
       
//	return jury;
}