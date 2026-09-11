// ev_npc_country.c
// this is used to control npc countrys 国师
void remove_gs(string n) {
        string p_id;
        string msg;
        p_id=COUNTRY_D->get_country(n,"gs");

        COUNTRY_D->set_country(n,"gs",0);

        msg=sprintf("%s被%s撤销%s国师职位。",
                CHAR_D->get_char(p_id,"name"),
                CHAR_D->get_char(n,"name"),
                COUNTRY_D->get_country(n,"name"));
        CHANNEL_D->deliver_tell("rumor","system",msg);
        HIS(msg);
        CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n,"name"),
                CHAR_D->get_char(p_id,"name")+"，你真让我失望。");

        return ;

}

void create_gs(string n) {
        string *ids,p_id,p_area,old_leader;
        string dis;
	 int title;
	  mixed p_grant;
	string m_area,m_nation,m_leader;

        ids=CHAR_D->check_char("nation",n);
        if(!sizeof(ids)) return;
        ids=filter_array(ids,(:CHAR_D->get_char($1,"type")==TYPE_PLAYER:));
        if(!sizeof(ids)) return;

        ids=filter_array(ids,(: CHAR_D->get_char($1,"nationcontribution")>500 :));
        if(!sizeof(ids)) return;

	p_id=ids[random(sizeof(ids))];
	p_area=CHAR_D->get_char(p_id,"area");
	if(CHAR_D->get_char(p_id,"task")) return;

	old_leader=AREA_D->get_area(p_area,"leader");
	if(CHAR_D->get_char(old_leader,"type")==TYPE_PLAYER) return;
	p_grant=CHAR_D->get_char(old_leader,"grant");
	
	if(mapp(p_grant)) {
		m_area=p_grant["area"];
		m_nation=p_grant["nation"];
		m_leader=p_grant["leader"];
		if((m_area==p_area)&&(m_nation==n)) {
			if((CHAR_D->get_char(m_leader,"area")==p_area)&&(CHAR_D->get_char(m_leader,"nation")==m_nation))
				return; // has a leader already
		}
	}

	
	title=OFFICER_D->query_area_officer_title(AREA_D->get_area(p_area,"level"),0,0)[0];

	if(stringp(old_leader)) {
		CHAR_D->set_char(old_leader,"ranklocal",R_SG);
		CHAR_D->set_char(old_leader,"grant",0);
	}
	CHAR_D->set_char(p_id,"ranklocal",title);
	CHAR_D->set_char(p_id,"grant",0);

	dis=sprintf("%s封%s为%s的%s。", CHAR_D->get_char(n,"name"),
		CHAR_D->get_char(p_id,"name"),AREA_D->get_area(p_area,"name"),
		OFFICER_D->query_rank_name(title));
	CHANNEL_D->deliver_tell("rumor","system",dis);

}
void create_gs_old(string n) {
        string *ids,p_id;
        string msg;
        ids=CHAR_D->check_char("nation",n);
        if(!sizeof(ids)) return;
        ids=filter_array(ids,(:CHAR_D->get_char($1,"type")==TYPE_PLAYER:));
        if(!sizeof(ids)) return;

        ids=sort_array(ids,(: CHAR_D->get_char($1,"nationcontribution")
                > CHAR_D->get_char($2,"nationcontribution") ? 1 : -1 :));
        if(!sizeof(ids)) return;
                p_id=ids[sizeof(ids)-1];
        if((sizeof(ids)>2)&&(random(5)==0))
                p_id=ids[sizeof(ids)-2];
        if((sizeof(ids)>3)&&(random(10)==0))
                p_id=ids[sizeof(ids)-3];

        if(CHAR_D->get_char(p_id,"nationcontribution")<1000) return; // at least 100 nc

        COUNTRY_D->set_country(n,"gs",p_id);
        COUNTRY_D->set_country(n,"gsx",200); // not too much
        msg=sprintf("%s被%s任命为%s的国师。",
                CHAR_D->get_char(p_id,"name"),
                CHAR_D->get_char(n,"name"),
                COUNTRY_D->get_country(n,"name"));
        CHANNEL_D->deliver_tell("rumor","system",msg);
        HIS(msg);
        CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n,"name"),
                CHAR_D->get_char(p_id,"name")+"，好好干，本国的兴旺就寄托在你身上了。");

        CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
                "臣肝胆涂地难报主公大恩。");

        return ;
}
void test_npc_gs(string n){
        string p_gs;
        if(CHAR_D->get_char(n,"type")!=TYPE_NPC) 
                return;
        p_gs=COUNTRY_D->get_country(n,"gs");
        if((!CHAR_D->char_exist(p_gs))||
                (CHAR_D->get_char(p_gs,"nation")!=n)) {
                create_gs(n);
                return ;
        }
        if(!COUNTRY_D->get_country(n,"gsx"))
                remove_gs(n);
}
void act() {
        string *ns,cn;
        int tmp;
        ns=COUNTRY_D->list_countries();
        foreach(string n in ns) {
                tmp=COUNTRY_D->get_country(n,"gsx"); //国师信誉
                if(tmp>0)
                        COUNTRY_D->set_country(n,"gsx",tmp-1);
        }
        cn=ns[random(sizeof(ns))];
        test_npc_gs(cn);
}
