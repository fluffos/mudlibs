// cike.h 刺客

void init()
{	
	object ob = this_player();

	::init();
	if (ob->query_temp("cike",1))
            	switch( random(3) ) {
		case 0:
			command("say 贼胆包天的刺客在这里！那里跑！");
                                    command("kill "+ob->query("id"));
			break;
		case 1:
			command("say 为王子报仇！大家上啊！");
			command("kill "+ob->query("id"));
			break;
		case 2:
			command("say 敢刺杀我家王子，格杀勿论！");
			command("kill "+ob->query("id"));
			break;
	}

}
