// greeting.h writen by cry 9.25.98
void do_greet(object me)
{
	int i,level,npclevel;
    object ob=this_object();
	string *title=({
		"镇南王府见习家丁",
		"镇南王府家丁",
		BLU"镇南王府家丁"NOR,
		CYN"镇南王府家丁"NOR,
		RED"镇南王府卫士"NOR,
		MAG"镇南王府卫士"NOR,
		YEL"镇南王府卫士"NOR,
		CYN"大理国"+RED"武官"NOR,
		CYN"大理国"+GRN"武官"NOR,
		CYN"大理国"+WHT"武官"NOR,
	});
	string *npctitle=({
		"镇南王府家丁",
		BLU"镇南王府家丁"NOR,
		CYN"镇南王府家丁"NOR,
		RED"镇南王府卫士"NOR,
		MAG"镇南王府卫士"NOR,
		YEL"镇南王府卫士"NOR,
		CYN"大理国"+GRN"四大卫护"NOR,
		CYN"大理国"+RED"司马"NOR,
		CYN"大理国"+RED"司空"NOR,
		CYN"大理国"+RED"司徒"NOR,
	});

	if( environment()!=environment(me) ) return ;
	for(i=0;i<sizeof(title);i++)
		if(me->query("title")==title[i])
        {
			switch(i) 
            {
			case 0:
			case 1:
				level=0;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				level=i-1;
				break;
			case 9:
				level=10;
				break;
			}
			break;
		}

	for(i=0;i<sizeof(npctitle);i++)
		if(ob->query("title")==npctitle[i])
        {
			npclevel=i;
			break;
		}
	
	if( living(me) && level>npclevel)
	    switch(npclevel) 
        {
		case 0:
        case 1:
		case 2:
			message_vision(GRN"$N对$n拱手施礼：“小的见过上差！上差安好！”\n"NOR,
			ob, me);
			break;
        case 3:
		case 4:
        case 5:
			message_vision(YEL"$N对$n叉手施礼：“卑职见过长官！长官好！”\n"NOR,
			ob, me);
			break;
		case 6:
			message_vision(WHT"$N对$n笑道：“"+me->query("name")
                    +"大人什么时候指点一下武功！”\n"NOR, ob, me);
			break;
        case 7:
		case 8:
        case 9:
			message_vision(WHT"$N对$n笑道：“"+me->query("name")+"大人近来可好？”\n"NOR,
			ob, me);
			break;
	}
}

void welcome_visitor()
{
    if ( this_player()->query("class")!="duanshi" ||
            !can_act() || is_fighting() || 
            this_player()->query_condition("kill_dali") )
        return;
    do_greet(this_player());
}

