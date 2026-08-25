int s_array(int *a1, int *a2);
mapping check_set_win(int *num);

int s_array(int *a1, int *a2)
{	
	int i;
	
	if( !arrayp(a1) || !arrayp(a2) || sizeof(a1) != sizeof(a2) || sizeof(a1) == 0 || sizeof(a2) == 0 )return 0;
	for( i = 0; i < sizeof(a1); i++)if( a1[i] != a2[i] )return 0;
	return 1;
}
mapping check_set_win(int *num)
{
	int i, j, k, count;
	mixed * *zui, *peng, *cuan, *gang;
	mixed * *curren_list;	// Curren number to be checked
	mixed * *tmp_c_list;	// Tempotary check list	
	mixed * *main_list;	// Full info of array
	mixed * *tmp_m_list;	// Tempotary main list	
	mixed * tmp;
	int *curren;		// Curren *array
	int *from;
	mapping info;		// Info of one check
	
	j = 0;
	count = 0;
	main_list = ({ });
	curren_list = ({ num, });

	while( sizeof(curren_list) ){
		tmp_c_list = ({ });
		tmp_m_list = ({ });
		for( i = 0; i < sizeof(curren_list); i++){
			curren = curren_list[i];
			info = ([ ]);
			info["from"] = curren;
			if( sizeof(curren) >3 && curren[0] == curren[1] && curren[1] == curren[2] && curren[2] == curren[3] ){
				info["gang"] = curren[<sizeof(curren)-4..];
				if( sizeof(info["gang"]) )tmp_c_list = tmp_c_list + ({ info["gang"] });
				if( !sizeof(info["gang"]) ){
					j = i+1;
					info["gang"] = 1;
					count = 1;
				};	
				info["gang_d"] = ({curren[0],curren[1],curren[2],curren[3], });
			};
			if( sizeof(curren) >2 && curren[0] == curren[1] && curren[1] == curren[2] ){
				info["peng"] = curren[<sizeof(curren)-3..];
				if( sizeof(info["peng"]) )tmp_c_list = tmp_c_list + ({ info["peng"] });
				if( !sizeof(info["peng"]) ){
					j = i+1;
					info["peng"] = 1;
					count = 1;
				};
				info["peng_d"] = ({curren[0],curren[1],curren[2], });
			};
			if( sizeof(curren) >2 && member_array(curren[0]+1, curren) != -1 && member_array(curren[0]+2, curren) != -1){
				tmp = curren[<sizeof(curren)-1..];
				tmp = tmp[0..member_array(curren[0]+1,tmp)-1] + tmp[member_array(curren[0]+1,tmp)+1..];
				tmp = tmp[0..member_array(curren[0]+2,tmp)-1] + tmp[member_array(curren[0]+2,tmp)+1..];
				info["cuan"] = tmp;
				if( sizeof(info["cuan"]) )tmp_c_list = tmp_c_list + ({ info["cuan"] });
				if( !sizeof(info["cuan"]) ){
					j = i+1;
					info["cuan"] = 1;
					count = 1;
				};
				info["cuan_d"] = ({curren[0],curren[1],curren[2], });
			};
			if( sizeof(curren) >1 && curren[0] == curren[1] ){
                                info["zui"]  = curren[<sizeof(curren)-2..];
				if( sizeof(info["zui"]) )tmp_c_list = tmp_c_list + ({ info["zui"] });
                                if( !sizeof(info["zui"]) ){
                                        j = i+1;
                                        info["zui"] = 1;
                                        count = 1;
                                };
				info["zui_d"] = ({curren[0],curren[1], });
                        };
			tmp_m_list = tmp_m_list + ({ info });
			if( count == 1 )break;
		};
		curren_list = tmp_c_list;
		main_list = main_list + ({ tmp_m_list });
		if( count == 1 )break;
	};

	if( !j || j == 0 )return ([ ]);
	from = ({ });zui = ({ });peng = ({ });cuan = ({ });gang = ({ });
	count = 1;

	for( i = sizeof(main_list)-1; i >= 0; i--){
		tmp_m_list = main_list[i];
		for( k = 0; k < sizeof(tmp_m_list); k++){
			info = tmp_m_list[k];
			if( (info["zui"] == 1 && info["from"][0] == info["from"][1]) || s_array(info["zui"],from) ){
				zui = zui + ({ ({info["zui_d"]}), });
				from = info["from"];
				break;
			} else if( (info["peng"] ==1 && info["from"][0] == info["from"][1] && info["from"][1] == info["from"][2])|| s_array(info["peng"],from) ){
                                peng = peng + ({ ({info["peng_d"]}), });
				from = info["from"];
                                break;
                        } else if( (info["cuan"] ==1 && info["from"][0]+1==info["from"][1] && info["from"][1]+1==info["from"][2]) || s_array(info["cuan"],from) ){
                                cuan = cuan + ({ ({info["cuan_d"]}), });
				from = info["from"];
                                break;
                        } else if( (info["gang"] == 1 && info["from"][0] == info["from"][1] && info["from"][1] == info["from"][2] && info["from"][2]==info["from"][3]) || s_array(info["gang"],from) ){
				count = 0;	
                                gang = gang + ({ ({info["gang_d"]}), });
				from = info["from"];
                                break;
                        };		
		};
	};
	
	return (["zui":zui,"gang":gang,"cuan":cuan,"peng":peng ]);
}
