inherit ITEM; 

void create()
{ 
    set_name("雷达", ({"radar"}) ); 
    set_weight(1000); 
    set("unit", "台");
    set("long", "一台小型的雷达，可以发现隐身的巫师。\n");

    setup(); 
} 
 
void init()
{ 
    add_action("do_search","search");  
    add_action("do_show","chat*");
    add_action("do_show","rumor*");
    add_action("do_show","goto");
    add_action("do_show","where");
    add_action("do_show","tell");
}

int do_search(string arg)
{ 
    object *usr, me,ob;
    int i,j; 
    string str="";
 
    if (arg) return 0; 
    me=this_player(); 
    usr=users(); 
    for (i=0,j=0; i<sizeof(usr); i++) {
	ob=usr[i];
	if (!wizardp(ob)) continue;
	str+="    "+ob->name()+"("+(string)ob->query("id")+")     ";
	if (ob->query("env/invisibility")==1) str+="对玩家隐身   ";
	if (ob->query("env/invisibility")>1) str+="最高级隐身   ";
	if (ob->query("env/immortal")==1) str+="不死模式";
	str+="\n"; 
	j++; 
    }; 
    if (j==0) return notify_fail("没有巫师在线。\n"); 
    str="现在上线的巫师有：\n"+str; 
    tell_object(me, str); 
    return 1; 
}
 
int do_show1(object ob)
{
	if (objectp(ob)) {
	    if (wizardp(ob) && ob->query("env/invisibility")>1) {
		ob->set("env/invisibility",1);
		return 0;
	    };
	    if (ob->is_ghost()) {
		ob->reincarnate();
		return 0;
	    };
	};
}

int do_show(string arg)
{ 
	object ob;
	string arg1,arg2;
 
	if (!arg) return 0; 
	ob=find_player(arg);
	do_show1(ob);
	if (sscanf(arg, "%s %s",arg1, arg2)!=2) return 0;
	ob=find_player(arg1);
	do_show1(ob);
	ob=find_player(arg2);
	do_show1(ob);
	return 0;
}	
