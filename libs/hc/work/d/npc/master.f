        set("inquiry", ([
                "出师": "哦....老夫向来有个规矩，凡是想拜我为师的，得接我三招不死，你想试试(accept 
test)？\n"
        ]) );

void init()
{
        ::init();
        add_action("do_accept", "accept");
}


int do_accept(string arg)
{
	object me=this_object();
	object ob=this_player();
    if( arg== "test" ) {
		say("\n"+me->name()+"点了点头，说道：很好，这是第一招....\n\n");
		COMBAT_D->do_attack(me, ob,me->query_temp("weapon"));
		call_out("do_accept2",0,me,ob);
		return 1;
	}
	return 0;

}
int do_accept2(object me,object ob)
{
	if (!me)	return 1;
	if (!ob){
		say("\n"+me->name()+"叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
		return 1;
	}
	if( (int)ob->query("qi") < 0 || !present(ob, environment(me))) {
		say("\n"+me->name()+"叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
		return 1;
	}
	say("\n"+me->name()+"说道：这是第二招....\n\n");
	COMBAT_D->do_attack(me, ob,me->query_temp("weapon"));
	call_out("do_accept3",0,me,ob);
	return 1;
}
int do_accept3(object me,object ob)
{
	if (!me)	return 1;
	if (!ob){
		say("\n"+me->name()+"「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
		return 1;
	}
	if( (int)ob->query("qi") < 0 || !present(ob, environment(me))) {
		say("\n"+me->name()+"「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
		return 1;
	}
	say("\n"+me->name()+"说道：第三招来了....\n\n");
	COMBAT_D->do_attack(me, ob,me->query_temp("weapon"));
	call_out("do_accept4",0,me,ob);
	return 1;
}
int do_accept4(object me,object ob)
{
	if (!me)	return 1;
	if (!ob){
		say("\n"+me->name()+"叹道：可惜!可惜....\n");
		return 1;
	}
	if( (int)ob->query("qi") < 0 || !present(ob, environment(me))) {
		say("\n"+me->name()+"「哼」地一声，看来"+ob->name(1)+"还要苦练十年....\n");
		return 1;
	}

}
