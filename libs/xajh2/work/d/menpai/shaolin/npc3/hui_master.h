/* hui_master.h

 * create by hydra 19980514

 * 少林慧字辈master都包含的头文件，包括 

 * attemp_apprentice( object )   检查是否满足拜师条件，决定是否 

 *                               收你为徒 

 * recruit( object )             收徒，不用F_APPRENTICE里面的  

 * assign_apprentice( string,int)跟F_APPRENTICE里的一样 

 * accept_fight( object )        判断是否接受fight

 * accept_bihua( object )        判断是否接受bihua，在升级的时候有用 

 * valid_teach( object )        

 * win_bihua( object )

 */



int recruit( object dizi )

{

    mapping my_family, family;

    string my_fam,belong;

    

    if ( dizi->is_apprentice_of( this_object() ) )

        return 0;

    if ( dizi->query( "quest" ) )

        dizi->delete( "quest" );

    if ( dizi->query( "done_quest" ) )

        dizi->delete( "done_quest" );

    if ( dizi->query( "task_time" ) )

        dizi->delete( "task_time" );   

    my_family = query("family");

    my_fam = query("family/family_name");

    belong = my_family[ "belong" ];

    

    dizi->set("class_score/" + my_fam, 0 );

    family = allocate_mapping( 8 );

    family[ "master_id" ] = query( "id" );

    family[ "master_name" ] = query( "name" );

    family[ "family_name" ] = my_family[ "family_name" ];

    family[ "generation" ] = my_family[ "generation" ] + 1;

    family[ "enter_time" ] = time();

    family[ "title" ] = BLU"弟子"NOR;

    family[ "privs" ] = 0;

    family[ "belong" ] = my_family[ "belong" ];

    dizi->set( "family", family );

    dizi->set("class","bonze");

  	dizi->set("title",RED"少林寺"+belong+HIB"弟子"NOR);  

  	

    message_vision("$N决定收$n为弟子。\n\n"

        "$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",

				this_object(), dizi);  

    tell_object( dizi,sprintf("恭喜你成为%s。\n",dizi->query("title")) );					  

    FAMILY_D->remove_family_enemy( my_family["family_name"], dizi->query("id"));

    LOG_D->do_log( dizi, sprintf( "你受到%s的青睐，成为%s。",

        family["master_name"], dizi->query("title") ) );

    return 1;

}



void attempt_apprentice(object ob)

{

    object this;

    string belong,master_id;

    this = this_object();

    belong = this->query("family/belong");

	if ( (string)ob->query("gender") == "女性" )

		command("say 阿弥陀佛，女施主不要跟贫僧开玩笑。");

	else if ( ob->query("class") != "bonze" )

		command("say 未得方丈准许，贫僧不敢擅收俗家弟子。施主还是请回吧。");

	else if ( ! ob->query("lnwm/pass_muren") ) 

		command("say 莫急，莫急。你现在的功夫还欠火候，再磨练磨练吧。");

    else if ( ob->query("have_married") )

        command("say 你即已结婚，就不能列入我少林正式门墙，你还是还俗下山吧。");

    else if( master_id=ob->query("family/master_id") )

    {

        if( master_id[0..3]=="xuan" )

        {

            command("say 师弟何苦开这等玩笑。");

        }

        else

        {

            command("shake");

            command("say 你既然已经有了师傅，怎么还来拜我呢？");

        }

    }

    else

    {

        message_vision( "$N微微一笑，道：“乖徒儿，从今天起你就是"+

belong+"的弟子了。\n可别给少林丢脸呵。”\n",this,ob);

        recruit(ob);

	}

}





int accept_fight(object me)

{

	if( (string)me->query( "family/family_name")=="少林派" )

	{

        command("say 那小心了n");

        return 1;

    }

    else

		command("say 施主既然身负绝艺，贫僧佩服便是，也不必较量了。");

	

	return 0;

}



int accept_bihua( object ppl )

{

    object me;

    me = this_object();

    if( ppl->query_temp("hydra/shaolin/fight_master") != query("id") )

    {

        if( accept_fight( ppl ) )

            return 1;

        else

            return 0;

    }

    me -> set( "force"  ,query("max_force") );

    me -> set( "eff_kee",query("max_kee") );

    me -> set( "kee"    ,query("max_kee") );

    me -> set( "eff_sen",query("max_sen") );

    me -> set( "sen"    ,query("max_sen") );

    me -> set( "env/attack",75 );

    command( "say 那就接招吧！");

    return 1;

}



int valid_teach(object me, string skill)

{

    if ( me->query("family/family_name") != "少林派" )

        return 0;



    if ( !me->query("family/master_id") )

        return notify_fail(query("name")+"摇头道：“少林武功最重根基，这门功夫待你过了木人巷，成为\n本寺入室弟子再来精研也不迟。”");



    if ( me->query("family/master_id") != query("id") )

    {

        command( "? "+me->query("id") );

        command( "say 你还是找你自己的师傅去学吧。");

        return 0;

    }

    if ( me->query("shaolin/announced") )

    {

        command("say  大胆孽徒，竟然违反清规戒律，还不速去戒律院忏悔！");

        return 0;

    }    

    if ( (int) me->query("task_time")+1000 < time() )

    {

        say( this_object()->name() + "微一皱眉，说：“嗯...今天的日常洒扫作了没有？”\n");

        return 0;

    }           

    return ::valid_teach(me, skill);

}







int win_bihua( object ppl )

{

    if( ppl->query_temp("hydra/shaolin/fight_master") == query("id"))

    {

        command( "pat "+ppl->query("id") );

        command( "say 不要灰心，好好练，超过师傅是没问题的。");

        ppl ->delete_temp("hydra/shaolin/fight_master");

    }

    return 1;

}



