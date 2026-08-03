#include <ansi.h>
#include <combat.h>

string* saywords=({
        "一住行窝几十年，",
        "蓬头长日走如颠。",
        "海棠亭下重阳子，",
        "莲叶舟中太乙仙。",
        "无物可离虚壳外，",
        "有人能悟未生前。",
        "出门一笑无拘碍，",
        "云在西湖月在天！",
        });
        
nosave object *npcs;
nosave int hits;
nosave string zhname;
nosave object room;

void dest_room()
{
	remove_call_out("dest_room");
	if( room )
	{
		tell_room(room,"\n\n"+zhname+"大阵“轰隆”一声，恢复了原状，诸守阵弟子纷纷散去。\n\n");
		npcs = 0;
		hits = 0;
		zhname = 0;
		destruct(room);
	}
}	

int do_back(object me)
{
	remove_call_out("do_back");
	if( me )
	{
        	me->delete("assigned_sixiang");
        	me->delete("assigned_bagua");
        	me->delete_temp("no_return");
        	if( base_name(environment())!="/d/lingtai/jingtang" )
        	{
        		tell_room(environment(),"\n"+name()+"往讲经堂方向离去。\n\n");
        		me->move("/d/lingtai/jingtang");
			tell_room(environment(),"\n"+name()+"走了过来。\n\n");
		}
	}
	call_out("dest_room",3);	
        return 1;
}

string ask_sixiang()
{
        mapping skl; 
        object fighter, me ;
        string *sname;
        int i,j;

        fighter = this_player();
        me = this_object();
        if( time()<fighter->query("family/四象_fail")+43200 )
        	return "你刚刚失败过，还是等"+CHINESE_D->chtime(fighter->query("family/四象_fail")+43200-time())+"再来。";
	if( base_name(environment())!="/d/lingtai/jingtang" )
		return 0;
	if( fighter->query("class")=="bonze" )
		return 0;	
        skl = fighter->query_skills();
        if( sizeof(skl) <= 1)
                return RANK_D->query_respect(fighter) + "功力不够，不够资格闯四象阵。";
        sname  = keys(skl);
        for(i=0; i<sizeof(skl); i++) 
        {
                if( (skl[sname[i]] < 300) || (sizeof(skl) == 0))
                	return RANK_D->query_respect(fighter) + "功力不够，不够资格闯四象阵。";
        }
        if( fighter->is_knowing("fc_sixiang") )
                return RANK_D->query_respect(fighter) + "已然闯过四象阵，可不要开这等玩笑。";
        if( fighter->query("family/family_name") 
         && fighter->query("family/family_name")!="方寸山三星洞" )
		return RANK_D->query_respect(fighter) + "不是本门中人，闯什么四象阵。";
        if(  me->query("assigned_sixiang") || me->query("assigned_bagua") )
                return RANK_D->query_respect(fighter) + "，今日已有人闯阵，你过一段时间再来吧。";
	if( room )
		dest_room();
        command("say 好吧，就随我到练功场闯阵吧！");
        me->set("assigned_sixiang", fighter->query("id"));   
        me->set_temp("no_return",1);           
        message_vision("\n云阳真人飘然向练功场方向离去。\n", fighter);
        me->move("/d/lingtai/inside2");
        tell_room(environment(me),"云阳真人说道：大家准备好了，有人闯阵！\n");
        remove_call_out("waiting");
        call_out("waiting", 1, me,fighter,300);
        return "好，好，好！好久没有人闯阵了。";
}

string ask_bagua()
{
        mapping skl; 
        object fighter, me ;
        string *sname;
        int i,j;
        fighter = this_player();
        me = this_object();
        if( time()<fighter->query("family/八卦_fail")+43200 )
        	return "你刚刚失败过，还是等"+CHINESE_D->chtime(fighter->query("family/八卦_fail")+43200-time())+"再来。";
	if( base_name(environment())!="/d/lingtai/jingtang" )
		return 0;
	if( fighter->query("class")=="bonze" )
		return 0;	
        skl = fighter->query_skills();
        if( sizeof(skl) <= 1)
                return RANK_D->query_respect(fighter) + "功力不够，不够资格闯八卦阵。";
        sname  = keys(skl);
        for(i=0; i<sizeof(skl); i++) {
                if( (skl[sname[i]] < 400) || (sizeof(skl) == 0))
                	return RANK_D->query_respect(fighter) + "功力不够，不够资格闯八卦阵。";
        }
        if( fighter->is_knowing("fc_bagua") )
		return RANK_D->query_respect(fighter) + "已然闯过八卦阵，可不要开这等玩笑。";
        if( fighter->query("family/family_name") && fighter->query("family/family_name")!="方寸山三星洞" )
		return RANK_D->query_respect(fighter) + "不是本门中人，闯什么八卦阵。";
        if(  me->query("assigned_sixiang") || me->query("assigned_bagua") )
                return RANK_D->query_respect(fighter) + "，今日已有人闯阵，你过一段时间再来吧。";
	if( room )
		dest_room();
        command("say 好吧，就随我到练功场闯阵吧！");
        me->set("assigned_bagua", fighter->query("id"));                
        me->set_temp("no_return",1);
        message_vision("\n云阳真人飘然向练功场方向离去。\n", fighter);
        me->move("/d/lingtai/inside2");
        tell_room(environment(me),"云阳真人说道：大家准备好了，有人闯阵！\n");
        remove_call_out("waiting");
        call_out("waiting", 1, me,fighter,300);
        return "好，好，好！好久没有人闯阵了。";
}

int waiting(object me,object fighter,int wait_time)
{
        remove_call_out("waiting");
	if( !me->query("assigned_bagua") && !me->query("assigned_sixiang") )
		return 1;
        if( !fighter || !living(fighter) || wait_time<=0 )
        {
                say( "云阳真人说道：看来他不会来了，真是没用的东西！\n\n");
                call_out("do_back", 0, me);  
                return 1;           
        }
	if( !present(fighter,environment()) )	
        {
                wait_time = wait_time-1;
                call_out("waiting", 1, me,fighter,wait_time);
        }
        else	call_out("preparing", 1, me, fighter);
        return 1;
}

int preparing(object me, object fighter)
{
        object npc;
        int base,i;
	remove_call_out("preparing");
	if( !me->query("assigned_bagua") && !me->query("assigned_sixiang") )
		return 1;
        if( !fighter || !living(fighter) || !present(fighter,environment()) )
        {
                say( "云阳真人说道：看来他不会来了，真是没用的东西！\n\n");
                call_out("do_back", 0, me);  
                return 1;           
        }
        
	room = clone_object("/quest/family/fc_zhen");
        if( !room )
        	return 1;
        if(me->query("assigned_sixiang"))
        {
        	zhname="四象";
        	hits = 4;
        }
        else
        {
        	zhname="八卦";    
        	hits = 8;
        }
        npcs = ({});
        for(i=0;i<hits;i++)
        {
        	npc = new(__DIR__"zhen");
        	if( !npc )
        		continue;
        	base = fighter->query_level();
        	if( zhname=="四象" )
        		base+= random(10-last_num(base));
        	else	base+= (i+1)*10+random(5);
        	npc->set_levels(base);	
        	if( npc->move(room) )
        		npcs+= ({npc});
		else 	destruct(npc);
        }
        if( sizeof(npcs)<3 )
        {
                say( "云阳真人说道：阵法有误！\n\n");
                call_out("do_back", 0, me);
                return 1;           
        }
        room->set("short",zhname+"阵");
        fighter->move(room);
	message("vision", HIY "\n云阳真人大声宣布："+zhname+"合围！\n" NOR, room);        
	message("vision", "\n只听四周响起沙沙的脚步声，诸弟子神情肃杀，手持兵刃，分成四方慢慢地围了上来，堵住了通路。\n\n", room);        
        say( HIY"云阳真人又道：准备，『"+zhname+"阵』即刻发动！\n\n"NOR);
       	call_out("fighting",  5, me, fighter);
        return 1;
}

void remove_npc()
{
	int i;
	if( !npcs || !arrayp(npcs) || sizeof(npcs)<1 )
		return;
	for(i=0;i<sizeof(npcs);i++)
	{
		if( npcs[i]->is_fighting() )
		{
			message_vision(HIW"\n$N说道：「不打了，不打了，我投降....。」\n"NOR,npcs[i]);
			npcs[i]->remove_all_killer();
			all_inventory(environment(npcs[i]))->remove_killer(npcs[i]);
			message_vision("$N摇身化作一道清风。。。\n\n",npcs[i]);
			destruct(npcs[i]);
		}
	}	
}

void zhen_return(object who)
{
	remove_call_out("zhen_return");
	if( !who )
		return;
	if( !present(who,room) )
		return;
	message("vision",who->name()+"退出了"+zhname+"大阵。\n",environment(who),({who}));
	tell_object(who,"\n\n你退出了"+zhname+"大阵。\n\n");
	who->move("/d/lingtai/inside2");
}

void zhen_fail(object who)
{
	remove_call_out("zhen_fail");
	if( !who )
		return;
	who->set("family/"+zhname+"_fail",time());
	call_out("zhen_return",1+random(3),who);	
}

void zhen_win(object who)
{
	remove_call_out("zhen_win");
	if( !who )
		return;
	if( zhname=="四象" )
		who->set_knowing("fc_sixiang",1);
	else	who->set_knowing("fc_bagua",1);
	who->delete("family/"+zhname+"_fail");
	CHANNEL_D->do_channel(this_object(),"chat","哈哈，恭喜恭喜，今日"+who->query("name")+"闯过了我方寸【"HIR+zhname+"大阵"NOR HIC"】！"NOR);
	who->add("faith",500);
	tell_object(who,HIY"【系统】你获得了500点门派贡献。\n"NOR);
	who->add("daoxing",15000);
	tell_object(who,HIY"【系统】你获得了十五年道行。\n"NOR);
	who->add("combat_exp",50000);
	tell_object(who,HIY"【系统】你获得了五万点武学经验。\n"NOR);
	who->add("potential",5000);
	tell_object(who,HIY"【系统】你获得了五千点潜能。\n"NOR);
	if( who->is_knowing("fc_sixiang")
	 && who->is_knowing("fc_bagua") )
	{
		command("chat* hao");
		who->set("shilian","fc");
		CHANNEL_D->do_channel(this_object(),"chat","哈哈，恭喜恭喜，今日"+who->query("name")+"通过了三星洞方寸山的试炼！"NOR);
		tell_object(who,"云阳真人哈哈大笑一声，对你道：恭喜恭喜，今日"+RANK_D->query_respect(who)+"通过了我方寸试炼。\n");
		tell_object(who,"云阳真人道：他日"+RANK_D->query_respect(who)+"境界提升，即可为菩提祖师亲传弟子，快哉快哉！\n");
		who->add("faith",100);
		tell_object(who,HIY"【系统】你获得了100点门派贡献。\n"NOR);
	}
	who->save();
	call_out("zhen_return",1+random(3),who);
}

int check_player(object fighter)
{
	if( !fighter || !living(fighter) 
	|| !present(fighter,room) )
		return 0;
	if( zhname=="四象" )
	{
		if( fighter->query("kee")<fighter->query("eff_kee")/2
		 || fighter->query("eff_kee")<fighter->query_maxkee()/2 )
		 	return 0;
	}
	else
	{
		if( fighter->query("kee")<fighter->query("eff_kee")/3
		 || fighter->query("eff_kee")<fighter->query_maxkee()/3 )
		 	return 0;
	}
	return 1;
}

int fighting(object me, object fighter)
{
	int i;
	string *action;
        object npc;
	remove_call_out("fighting");
	
	action = ({"leiting","pili","qiankun","wu",});
		
	if( !fighter )
	{
		remove_npc();
		say( "云阳真人摇了摇头，说道：想不到 ... 唉！\n");
		EMOTE_D->do_emote(this_object(), "sigh",0,CYN,0,0,0);
		remove_call_out("do_back");
		call_out("do_back",1+random(2),me);
		return 1;
	}
	if( !present(fighter,room) )
	{
		remove_npc();
		say( "云阳真人摇了摇头，说道：想不到 ... 唉！\n");
		command("chat* sigh "+fighter->query("id"));
		fighter->start_busy(3);
		call_out("zhen_fail",1+random(3),fighter);
		call_out("do_back",4,me);
		return 1;
	}	
	if( hits<=0 )
	{
		remove_npc();
		call_out("zhen_win",1+random(3),fighter);
		call_out("do_back",4,me);
		return 1;
	}
	i = random(5);
	if( i==0 )	
		hits = hits-1;
	if( !npcs || !arrayp(npcs) || sizeof(npcs)<1 )
	{
		remove_npc();
		say( "云阳真人摇了摇头，说道：想不到阵法崩溃 ... 唉！\n");
		call_out("zhen_return",1+random(3),fighter);
		call_out("do_back",4,me);
		return 1;
	}
	npc = npcs[random(sizeof(npcs))];
	if( random(2) )
		message_vision(HIW"\n阵中众人迅速游走，走马观花般来回穿梭，但见$N踏前一步，依阵法对$n发起攻击！\n"NOR,npc,fighter);
	else	message_vision(HIW"\n$N从阵中踏前一步，口中吟道："+saywords[random(sizeof(saywords))]+"。道罢对$n发起攻击！\n"NOR,npc,fighter);	
	npc->kill_ob(fighter);
	fighter->kill_ob(npc);
	if( !npc->command("perform "+action[random(sizeof(action))]+" on "+fighter->query("id")) )
		COMBAT_D->do_attack(npc,fighter,npc->query_temp("weapon"),TYPE_PERFORM,0,0,0,npc->query_skill("stick"));
	if( !check_player(fighter) )
	{
		remove_npc();
		say( "云阳真人摇了摇头，说道：想不到 ... 唉！\n");
		command("chat* sigh "+fighter->query("id"));
		fighter->start_busy(3);
		call_out("zhen_fail",1+random(3),fighter);
		call_out("do_back",4,me);
		return 1;
	}		
	if( i==0 || zhname!="四象" )
	{
		message_vision(HIW"$N出招之后，迅速退回原位！\n"NOR,npc);
		npc->remove_killer(fighter);
		fighter->remove_killer(npc);
//		npcs-=({npc});
//		destruct(npc);
	}
	call_out("fighting", 3+random(3), me, fighter);
	return 1;
}