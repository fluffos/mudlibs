// Created by flee 03211999

void start(string arg)
{
	object who;

	who = present(arg, environment(this_body()));
	if( !who || !objectp(who) || !function_exists("do_work", who) ){
		printf("你要为谁工作？\n");
		return;
	} else {
		who->do_work( this_body() );
	};
	
	return;
}
