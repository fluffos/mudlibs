#include <mudlib.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int savetotxt1(object ob)
{
	string str;

	str=RANK_D->query_rank(ob)+"\n"+ob->short(1)+"\n";
	//【发呆天使】逍遥派主人「一问三不知」李逍遥(Pal)
	str=str+ob->query("combat_exp")+"\n";
	//combat_exp
	str=str+ob->query("str")+"\n"+ob->query("int")+"\n"+ob->query("con")+"\n"+ob->query("dex")+"\n"+ob->query("kar")+"\n"+ob->query("per")+"\n"+ob->query("spi")+"\n";
	//
	str=str+ob->query("potential") +"\n"+ob->query("learned_points")+"\n";
	//total pot & spend pot
	
	str=str+(string)((int)ob->query("shaqi")+"\n");
	//shaqi
	str=str+ob->query("birthday")+"\n";
	//birthday

	return write_file("/web/data/"+ob->query("id"),str,1);
}

string remove_color(string arg)
{
        if(!arg) 
                return "";
        else
        {
                arg=replace_string(arg,"$NOR$","");
                arg=replace_string(arg,"$HIR$","");
                arg=replace_string(arg,"$HIW$","");
                arg=replace_string(arg,"$HIG$","");
                arg=replace_string(arg,"$HIC$","");
                arg=replace_string(arg,"$HIB$","");
                arg=replace_string(arg,"$HIY$","");
                arg=replace_string(arg,"$HIM$","");

                arg=replace_string(arg,"$RED$","");
                arg=replace_string(arg,"$BLK$","");
                arg=replace_string(arg,"$BNK$","");
                arg=replace_string(arg,"$BLU$","");
                arg=replace_string(arg,"$MAG$","");
                arg=replace_string(arg,"$WHT$","");
                arg=replace_string(arg,"$CYN$","");
                arg=replace_string(arg,"$GRN$","");
                arg=replace_string(arg,"$YEL$","");

                arg=replace_string(arg,NOR,"");
                arg=replace_string(arg,HIR,"");
                arg=replace_string(arg,HIW,"");
                arg=replace_string(arg,HIG,"");
                arg=replace_string(arg,HIC,"");
                arg=replace_string(arg,HIB,"");
                arg=replace_string(arg,HIY,"");
                arg=replace_string(arg,HIM,"");

                arg=replace_string(arg,RED,"");
                arg=replace_string(arg,BLK,"");
                arg=replace_string(arg,BNK,"");
                arg=replace_string(arg,BLU,"");
                arg=replace_string(arg,MAG,"");
                arg=replace_string(arg,WHT,"");
                arg=replace_string(arg,CYN,"");
                arg=replace_string(arg,GRN,"");
                arg=replace_string(arg,YEL,"");
        }
        return arg;
}

mixed getout_string(mixed str)
{
	return remove_color(sprintf("%O",str));
}
int savetotxt(object ob)
{
	string str,value;
	mapping list,skills;
	mixed *klist,*skill;
	int  loop;
	list  =  (mapping)ob->query_entire_dbase();
	skills = (mapping)ob->query_skills();

	if( !list || !mapp(list) || !sizeof(list) )
		return  0;
 	klist  =  keys(list);
 	klist  =  sort_array(klist,  "sort_keys",  this_object());
 	str="<?xml version=\"1.0\" encoding=\"gb2312\" ?>";
 	str+="<user_data>\n";
 	str+="<!--data:-->\n";
	for(loop=0;  loop<sizeof(klist);  loop++)
	{
		str+="<base_data>\n";
		str+="<key>"+klist[loop]+"</key>\n";
		value=sprintf("%O",list[klist[loop]]);
		if(value[0..1]=="({")
		{
			str+="<value>mapping</value>\n";
		}
		else if(value[0..1]=="([")
		{
			str+="<value>array</value>\n";
		}
		else
		{
      str+=sprintf("<value>%s</value>\n",getout_string(list[klist[loop]]));
		}
		str+="</base_data>\n";
	}
	//先这么写着，以后要做递归
	str+="<base_data>\n<key>rank_info_rank</key>\n";
	str+="<value>"+remove_color(ob->query("rank_info/rank"))+"</value>\n";
	str+="</base_data>\n";
 	str+="<!--skills-->\n";
 	if(sizeof(skills))
 	{
 		skill = keys(skills);
		for(loop=0;  loop<sizeof(skill);  loop++)
		{
			str+="<skill>\n";
			str+="<key>"+skill[loop]+"</key>\n";
			str+=sprintf("<value>%s</value>\n",getout_string(skills[skill[loop]]));                        
			str+="</skill>\n";
		}
	}
	str+="<!--skills_mapping-->\n";
	list = (mapping)ob->query_skill_map();
	if(sizeof(list))
	{
		klist = keys(list);
		for(loop=0;loop<sizeof(klist);loop++)
		{
			str+="<skill_map>\n";
			str+="<key>"+klist[loop]+"</key>\n";
			str+=sprintf("<value>%s</value>\n",getout_string(list[klist[loop]]));
			str+="</skill_map>\n";
		}
	}
	str+="</user_data>";
	return write_file("/web/xmldata/"+ob->query("id")[0..0]+"/"+ob->query("id")+".xml",str,1);
}
