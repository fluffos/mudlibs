//这是高升泰对要求升级的反应
int change_dengji()
{
    object me, ob, here;
    int score;
    
    me = this_player();
    ob = this_object();
    here = environment(ob);
    
    score = me->query("class_score/镇南王府");
    
    if( me->query("class")!="duanshi" )
    {
        command("say “取笑了，您怎么会在王府升什么级呢？”");
        return 1;
    }        
    if( me->query("title")!=RED"镇南王府卫士"NOR
     && me->query("title")!=MAG"镇南王府卫士"NOR
     && me->query("title")!=YEL"镇南王府卫士"NOR
     && me->query("title")!=CYN"大理国"+RED"武官"NOR
     && me->query("title")!=CYN"大理国"+GRN"武官"NOR
     && me->query("title")!=CYN"大理国"+WHT"武官"NOR)
    {
        command("say “你的级别不够，升级应该找管家丁的段管事。”");
        return 1;
    }        
    if((me->query("title")==RED"镇南王府卫士"NOR && score<1600)
    || (me->query("title")==MAG"镇南王府卫士"NOR && score<2400)
    || (me->query("title")==YEL"镇南王府卫士"NOR && score<3500))
    {
        command("say “只有对王爷赤胆忠心的卫士才能得到最快的提升，你看自己做得够么？”");
        return 1;
    }        
    if( here->query("short") != "小客厅")
    {
        command("say “唔，这个么……你在小客厅等我吧！”");
        return 1;
    }   
    
    if( me->query("title")==YEL"镇南王府卫士"NOR
        && me->query("family/master_id")!="gao shengtai" )
    {
	command("say 你的武功还不够。");
	return 1;
    }

    if( me->query("title")==CYN"大理国"+RED"武官"NOR
     || me->query("title")==CYN"大理国"+GRN"武官"NOR
     || me->query("title")==CYN"大理国"+WHT"武官"NOR)
    {
        command("say 现在你我已经同殿称臣，再想升就要王爷亲自点头了。");
        return 1;
    }        

	if( me->query_temp("pending/is_testing"))
	{
		command("say 你不是已经在升级了么？");
		return 1;
	}
	
    if( accept_fight(me) )
    {
        command("say “卫士的升级和家丁的不同，要比试真功夫的，刀剑无眼，可能会有性命之忧。”");
        command("say “你真的已经做好准备(ok)了吗？”");
        me->set_temp("pending/ask_ok", 1);
    }
    else
    {
        command("say 这件事以后再说吧。");
    }
    return 1;
}

int say_ok()
{
    object me, ob, here, obj, npc;
    int score, num, i;
    
    me = this_player();
    ob = this_object();
    here = environment(ob);
    
    score = me->query("class_score/镇南王府");

    if(!me->query_temp("pending/ask_ok")) return 0;
    me->delete_temp("pending/ask_ok");
    me->set_temp("pending/is_testing", 1);
    
    if(me->query("title")==RED"镇南王府卫士"NOR && score>=1600) num = 3;
    if(me->query("title")==MAG"镇南王府卫士"NOR && score>=2400) num = 2;
    if(me->query("title")==YEL"镇南王府卫士"NOR && score>=3500) num = 1;
    message_vision(GRN"\n$N对$n点一点头：“好吧，既然如此，咱们就来考校一下你的功夫吧！”\n"+
    "\n$N轻轻一击掌，一道铁闸突然落下，挡住了客厅的出口。\n"+YEL
    "\n从屏风后转出来几名卫士向$n叉手施礼道：“领教了！”各抽兵刃扑了过来。\n"NOR, ob, me);
    here->delete("exits/west");
    if (!obj=find_object("/d/menpai/duanshi/dongyuan")) 
        obj=load_object("/d/menpai/duanshi/dongyuan");
    obj->delete("exits/east");
    message("vision", GRN"\n突然“咣当”一声，一道铁闸挡住了客厅的门。\n\n"NOR, obj);
    for(i=1; i<6-num; i++)
    {
        npc = new( __DIR__+sprintf( "weishi%d", num ));
        npc->move( here );
        npc->bihua_ob( me );
        me->bihua_ob( npc );
	}
    
    call_out("check_bihua", 1, me, here, obj);
    return 0;
}
   
int check_bihua(object me, object here, object obj)
{
    remove_call_out( "check_bihua" );
    if ( me->query_temp( "finish_bihua" ) ||
         me->query_temp( "netdead" ) ||
         !living( me ) )
    {
        remove_call_out( "done_test" );
        call_out( "done_test", 1, me, here, obj );
    }
    else
    {
        call_out( "check_bihua", 2, me, here, obj );
    }
    return 1;
}

int done_test(object me, object here, object obj )
{
    object ob, *inv = all_inventory( environment(this_object()) );
    int i;

    ob = this_object();
       
    remove_call_out( "check_bihua" );
    remove_call_out( "done_test" );
    if ( !living( me ) || me->query_temp( "netdead" ))
    {
        me->revive( 0 );
        me->set_temp( "be_defeated", 1 );
    }
    for( i =0; i<sizeof(inv); i++ )
    {
        if( inv[i] != this_object() && !userp(inv[i]) )
            destruct( inv[i] );
    }
    message("vision",YEL"卫士们悄悄地转回到屏风后面去了\n\n"NOR, here );

    if ( me->query_temp("be_defeated") )
    {
        me->delete_temp("finish_bihua");
        me->delete_temp("be_defeated");
        message("vision","一阵轰隆声响过之后，铁闸门被提了起来。\n", here); 
        message("vision","一阵轰隆声响过之后，铁闸门被提了起来。\n", obj ); 
        here->set("exits/west", "/d/menpai/duanshi/dongyuan");
        obj->set("exits/east", "/d/menpai/duanshi/xiaoketing");
        message_vision(CYN"\n$N笑着对$n摇了摇头：“看来还需要多下功夫啊！”\n"NOR, ob, me);
        me->delete_temp("pending/is_testing");
    } 
    else
    {
        me->delete_temp("finish_bihua");
        remove_call_out("pass2");
        call_out("pass2", 1, me, obj, here);
    }

    return 1;
}

int pass2(object me, object obj, object here)
{
    object ob;
    int i, num, score;
    string msg;
    object * things;
    ob=this_object();
    score=me->query("class_score/镇南王府");
    
    message_vision("$N对$n点点头：“不错么，有些功夫。不过……考验还没有完噢！”\n"+RED
    "\n$N一跃而起，一掌接一掌地拍了过来！！！\n\n"NOR, ob, me);       
    // add by xli 1999.3.20
    // 加入将gao full的程序
    ob->set("kee",ob->query("max_kee"));
    ob->set("eff_kee",ob->query("max_kee"));
    ob->set("gin",ob->query("max_gin"));
    ob->set("eff_gin",ob->query("max_gin"));
    ob->set("sen",ob->query("max_sen"));
    ob->set("eff_sen",ob->query("max_sen"));
    ob->set("food",ob->max_food_capacity());
    ob->set("water",ob->max_water_capacity());
    ob->set("force",ob->query("max_force"));
    things=all_inventory(ob);
    for(i=0;i<sizeof(things);i++)
    {
    	destruct(things[i]);
    }
    carry_object(CLONE_DIR"wear/boots/wuyun_xue")->wear();
    carry_object(CLONE_DIR"wear/waist/yindai")->wear();
    carry_object(CLONE_DIR"wear/cloth/cloth5")->wear();
    carry_object(CLONE_DIR"wear/head/qingsha_jin")->wear();
    
    // end

    if(me->query("title")==RED"镇南王府卫士"NOR && score>=1600) num = 1;
    if(me->query("title")==MAG"镇南王府卫士"NOR && score>=2400) num = 2;
    if(me->query("title")==YEL"镇南王府卫士"NOR && score>=3500)
    {
        num = 3;
        set("force_factor",150);
    }
    for(i=1;i<num*2;i++)
    {
        if( me->query( "kee" ) < 0 )
        {
            message_vision("$N叹了口气：“唉！怎么这么没用……连"
            + CHINESE_D->chinese_number( i ) +"招都接不下来。”", ob);
            i=num*2;
        }
        else
        {
//调用combatd中fight_control一个过程，这里，这个0代表AT_NORMAL攻击类别
            COMBAT_D->fight_control( ob, me, 0 );
        }
    }
    remove_call_out( "wait_and_check" );
    call_out( "wait_and_check", 1, me, ob, obj, here, msg );
    return 1;
}

int wait_and_check( object me, object ob, object obj, object here, string msg )
{    
    if( ( me->query("kee")*100/(me->query("max_kee") ) < 15 ) 
    || !me->can_act() 
    || !present( me, here )    
      )
  //  || me->query( "kee" ) < 0 )
    {
        command("say “很可惜，但是想投机取巧是不行的啊，没有办法……”" );
        message("vision","一阵轰隆声响过之后，铁闸门被提了起来。\n", here); 
        message("vision","一阵轰隆声响过之后，铁闸门被提了起来。\n", obj ); 
        here->set("exits/west", "/d/menpai/duanshi/dongyuan");
        obj->set("exits/east", "/d/menpai/duanshi/xiaoketing");
        me->delete_temp("pending/is_testing");
        return 1;
    }    
    me->set("kee",me->query("max_kee")/2); 
    me->set("eff_kee",me->query("max_kee")/2);// add to protect you to die     
    message_vision( YEL"\n$N看起来对$n很是满意：“果然不同凡响，功夫很是扎实，完全可以提升一级。”\n\n",
    ob, me );
    if(me->query("title")==YEL"镇南王府卫士"NOR )
    {
        me->set("title", CYN"大理国"+RED"武官"NOR);
        msg=me->query("name")+"忠心耿耿、武功精湛，现提升为"NOR+me->query("title")+HIC"！\n";
        LOG_D->do_log(me, "你通过了高升泰对你的考验，终于被提升为"+CYN"大理国"+RED"武官"NOR+"。");
        me->save();
    }
    if(me->query("title")==MAG"镇南王府卫士"NOR )
    {
        msg = me->query("name")+"忠心耿耿、武功精湛，现提升为"+YEL"镇南王府卫士"+HIC"！\n";
        me->set("title", YEL"镇南王府卫士"NOR);
        LOG_D->do_log(me, "你通过了高升泰对你的考验，被提升为"+YEL"镇南王府卫士"GRN+"。");
        me->save();
    } 
    if(me->query("title")==RED"镇南王府卫士"NOR ) 
    {
        msg = me->query("name")+"忠心耿耿、武功精湛，现提升为"+MAG"镇南王府卫士"+HIC"！\n";
        me->set("title", MAG"镇南王府卫士"NOR);
        LOG_D->do_log(me, "你通过了高升泰对你的考验，被提升为"+MAG"镇南王府卫士"GRN+"。");
        me->save();
    } 
    command("chat " + msg );
    message("vision","一阵轰隆声响过之后，铁闸门被提了起来。\n", here); 
    message("vision","一阵轰隆声响过之后，铁闸门被提了起来。\n", obj ); 
    here->set("exits/west", "/d/menpai/duanshi/dongyuan");
    obj->set("exits/east", "/d/menpai/duanshi/xiaoketing");
    me->delete_temp("pending/is_testing");
    return 1;
}
