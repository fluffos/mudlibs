int do_check_user(object ob, string strMenpai) 
{
	if(ob->query("family/family_name") != strMenpai)
	{
		return 0;
	}

	if(ob->query("combat_exp") < 100000)
	{
		return 0;
	}

    if(!ob->query("env/family_job"))
	{
		return 0;
        
	}

	return 1;
}


void get_player()
{
        object me, *list0, *list1, *list2, *list3, *list4, *list5, *list6, *list7, *list8, *list9, *list10, *list11, *list12;
        string strName, strId, strFName, strMenpai;
        int j, total, intExp, count;


        if(!query_temp("job_enable"))
        {
                write("工作终止\n");
                return;
        }

        
		count = query_temp("menpai_count");

		if(count > 12)
		{
			set_temp("menpai_count", 0);
			final_count();
			return;
		}

		strMenpai = "武当派";
        list0 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "少林派";
        list1 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "丐帮";
        list2 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "星宿派";
        list3 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "峨嵋派";
        list4 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "大理段家";
        list5 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "古墓派";
        list6 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "白驼山";
        list7 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "华山派";
        list8 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "雪山派";
        list9 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "桃花岛";
        list10 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "全真教";
        list11 = filter_array(users(), "do_check_user", this_object(), strMenpai);
		strMenpai = "昆仑派";
        list12 = filter_array(users(), "do_check_user", this_object(), strMenpai);
        
		switch(count)
        {
		case 0:
			{
				if(!sizeof(list0))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list0);

				j = random(total);
				list0[j]->short(1);
				me = list0[j];
				break;
			}
		case 1:
			{
				if(!sizeof(list1))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list1);		
				j = random(total);
				list1[j]->short(1);
				me = list1[j];

				break;
			}
		case 2:
			{
				if(!sizeof(list2))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list2);		
				j = random(total);
				list2[j]->short(1);
				me = list2[j];

				break;
			}
		case 3:
			{
				if(!sizeof(list3))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list3);		
				j = random(total);
				list3[j]->short(1);
				me = list3[j];
				break;
			}
		case 4:
			{
				if(!sizeof(list4))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list4);		
				j = random(total);
				list4[j]->short(1);
				me = list4[j];
				break;
			}
		case 5:
			{
				if(!sizeof(list5))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list5);
				j = random(total);
				list5[j]->short(1);
				me = list5[j];
				break;
			}
		case 6:
			{
				if(!sizeof(list6))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list6);		
				j = random(total);
				list6[j]->short(1);
				me = list6[j];
				break;
			}
		case 7:
			{
				if(!sizeof(list7))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list7);		
				j = random(total);
				list7[j]->short(1);
				me = list7[j];
				break;
			}
		case 8:
			{
				if(!sizeof(list8))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list8);		
				j = random(total);
				list8[j]->short(1);
				me = list8[j];
				break;
			}
		case 9:
			{
				if(!sizeof(list9))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list9);		
				j = random(total);
				list9[j]->short(1);
				me = list9[j];
				break;
			}
		case 10:
			{
				if(!sizeof(list10))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list10);		
				j = random(total);
				list10[j]->short(1);
				me = list10[j];
				break;
			}
		case 11:
			{
				if(!sizeof(list11))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list11);		
				j = random(total);
				list11[j]->short(1);
				me = list11[j];

				break;
			}
		case 12:
			{
				if(!sizeof(list12))
				{
					add_temp("menpai_count", 1);
					write(strMenpai+"无人符合规定。\n");
					get_player();
					break;
					return;
				}
				total = sizeof(list12);		
				j = random(total);
				list12[j]->short(1);
				me = list12[j];
				break;
			}
		}

	write(strMenpai+"共有"+chinese_number(j)+"人符合规定。\n");
/*        write(me->query("name")+"\n");
        write(me->query("id")+"\n");
        write(me->query("combat_exp")+"\n");
        write(me->query("family/family_name")+"\n");

        strName = me->query("name");
        strId = me->query("id");
        intExp = me->query("combat_exp");
        strFName = me->query("family/family_name");*/
	add_temp("menpai_count", 1);
	get_player();
        return;
}