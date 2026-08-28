#define SKILL_D "/guilds/obj/skillfun"

string_kuntoo(string skill) {
 string str1, str2, str3, str4;
 string rsk;
 rsk = skill;
 if (sscanf(skill, "%s_%s", str1, str2) == 2) { rsk = str1+" "+str2; }
 if (sscanf(skill, "%s_%s_%s", str1, str2, str3) == 3) { rsk = str1+" "+str2+" "+str3; }
 if (sscanf(skill, "%s_%s_%s_%s", str1, str2, str3, str4) == 4) { rsk = str1+" "+str2+" "+str3+" "+str4; }
 return rsk;
}

cmd_testskills() {
	string *files;
	string sk1, sk2;
	int i;
	string str;
	object pager;
	files = get_dir("/doc/skill/",1);
	str =  "+-----------------------------------------------------------------------+\n";
    str += "| Name                      | Type       | Ep  | Time | Cost            |\n";
   	str += "+-----------------------------------------------------------------------+\n";
	for(i=0;i<sizeof(files);i++) {
	if(file_size("/guilds/skills/"+files[i]+".c") != -1) {
    str += sprintf("| %-25s | %-10s | %-3d | %-4d | %-15s |\n",
    string_kuntoo(files[i]),
    call_other("/guilds/skills/"+files[i]+".c", "query_type"),
    call_other("/guilds/skills/"+files[i]+".c", "ep_cost"),
    call_other("/guilds/skills/"+files[i]+".c", "get_time"),
    SKILL_D->get_skill_cost_adjective(string_kuntoo(files[i])));
    } else { if(SKILL_D->get_skill_cost_adjective(string_kuntoo(files[i])) != "No skillcost defined") {
	str += sprintf("| %-25s | %-10s | %-3d | %-4d | %-15s |\n", string_kuntoo(files[i]),
	       "Automatic", 0, 0, SKILL_D->get_skill_cost_adjective(string_kuntoo(files[i])));
}
}
}
   	str += "+-----------------------------------------------------------------------+\n";
   	str += sprintf("| %-5d Skills |\n", sizeof(files));
   	str += "+--------------+\n";
   	pager = clone_object("/daemons/pager");
	pager->move(this_player());
	pager->page(str);
	return 1;
}
