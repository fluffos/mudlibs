// warmap.c 
// by fire on Sep 15, 1998
// used for player char to check the warmap for different areas
// modify by flee on Oct 8, 1998. add some parameters
inherit M_ANSI;
void start(string arg)
{
	int troop_id,p_id;
	string ret, para;
	object env;
	mixed tmp;
	string where;

        if(arg == ""){
                write("用法错误！");
                write("用 cmd help warmap 查看详细帮助。\n");
                return;
	};
	env = environment(this_body());
	if( !env->is_troop()) 
		para = "m";
	else {
		troop_id = env->get_id();
		if(TROOP_D->get_troop_area(troop_id) == arg|| arg == "here")	
		para = TROOP_D->get_troops( troop_id, "side");	
		else
		{
		para = "m";	
		}	
};
	if(arg == "here"){
        	while( env && !inherits(BASE_ROOM, env) ) 
                	env = environment( env );
                arg = env->get_area();
        	tmp=MAP_D->city_exist( arg );
        	if( tmp!=1) {
        		write("没有此处的地图，用map查阅目前已有的地图。\n");
                	return;
		};
	}

	// let wizard see all the troops :P
	if( wizardp( this_body()->query_id()[0] ) ) 
		para = "b";

	ret=MAP_D->preview_city(arg, para, troop_id);
        write(ret);
}
