int do_study(object me, string arg)
{
	object ob;
	mapping book;
	int cost;

	if ( me->is_busy() )
		return 0;

	if ( me->is_fighting() )
		return 0;

	if ( me->is_lianing() )
		return 0;

	if ( me->is_duilianing() )
		return 0;

	if ( !me->query_jibie( "literate" ) )
		return 0;

    if ( !arg || ( !objectp(ob = present( arg, me ) ) && arg != "tong ding" )
		return 0;

    if ( arg != "tong ding" )
        return 0;		

    ob = present( "tong ding", this_object() );
    book = ob->query( "skill" );
        
    if ( !SKILL_D(book["name"])->valid_learn( me ) ) return 0; 

    cost = book["gin_cost"]*((70-(int)me->query_int()/3-(int)me->query_spi()/3));
    if ( cost <= 0 ) cost = 1;

	if ( (int)me->query("gin") < cost ) 
    {
		write("你现在过于疲倦，无法专心下来研读新知。\n");
		return 1;
	}

	message("vision", me->name() + "正专心地研读" + ob->name()
		+ "。\n", environment(me), me);
    message("vision", "你开始研读" + ob->name() + "。\n", me);
	me->receive_damage("gin", cost);

    get_gain(me, ob, book);
	return 1;
}

int get_gain(object me, object ob, mapping book)
{
	string type;
	int bonus;

	type = SKILL_D( book[ "name" ] )->query_xiuwei_type();
    
	if ( type && (int)me->query_xiuwei_by_type(type) < book["xiuwei_required"] )
    {
		write("你拿着" + ob->name() +"仔细端详，却发现很难理解上面所讲的一切。\n");
		return 1;
	}
    if ( (int)me->query_lingwu( "literate" ) < book[ "literate_required" ] )
    {
		write("你拿着" + ob->name() +"仔细研读了一下，却发现上面的文字过于艰深，也许你需要\n"
            "多学些读书识字方面的知识了。\n");
        return 1;
    }
    if ( ob->invalid_study( me ) )
        return 1;
	if ( !me->query_jibie( book[ "name" ] ) )
		me->set_jibie( book["name"], 0 );
    
    if ( me->query_jibie( book[ "name" ] ) 
        && me->query_lingwu_ratio( book[ "name" ] ) < 90 )
    {
        write( "功夫需要多加练习，才能真正掌握。\n" );
        return 1;
    }
    else
    {
        if ( me->query_jibie( book[ "name" ] ) >=  book[ "max_jibie" ] )
        {
            write ( "这口鼎上所刻的一切都都已尽被你须知，你已经无法从中学到新东西了。" );
            return 1;
        }
            if ( bonus = book[ "bonus_jibie" ] > 0 )
            me->improvve_jibie( book[ "name" ], bonus );
        else if ( bonus <= 0 )
            me->improve_jibie( book[ "name" ], random( (int)me->query_spi()/7 ) );

   		if ( book["bonus_xiuwei"] && 
		(int)me->query_xiuwei_by_type( type ) < book[ "max_xiuwei" ] )
        {
            bonus = book["bonus_xiuwei"];
  			me->improve_xiuwei( type, bonus );
        }
    }
	write(YEL"你研读有关" + to_chinese(book["name"]) + "的技巧，从中悟出了一些心得。\n"NOR);
    return 1;
}
