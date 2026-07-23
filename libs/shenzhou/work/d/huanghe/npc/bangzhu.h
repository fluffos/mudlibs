//// Code of ShenZhou
//Modify by snso
// /d/huanghe/npc/bangzhu.h
// by aln  18/ 8 / 2k

void init()
{
        object ob = this_player();

        ::init();

        if( !is_fighting()
        &&  interactive(ob) ) {
                remove_call_out("checking");
                call_out("checking", 1, ob);
        }

        add_action("do_check", "exert");
        add_action("do_check", "yun");
        add_action("do_xue", "xue");
}

void checking(object ob)
{
        object me = this_object();

        if( !living(me) || is_fighting() ) return;

        if( environment() != environment(ob) ) return;

        if( ob->query_temp("bangs/fam") == query("fam") ) {
                message_vision("$N拍了拍$n的头说道：加油！长乐帮发了自有你的好处！\n", me, ob);
                return;
        }

        if( !random(2) )
                message_vision("$N双手抱拳，牛里牛气地说道：见到本帮主，难道没有任何表示吗？\n", me);
        else    message_vision("$N说道：还不赶快加入" + query("fam") + "！！！\n", me);
}

int do_check(string arg)
{
        string what, who;

        if( !arg ) return notify_fail("");

        if( arg != "play" ) {
                 if( sscanf(arg, "%s %s", what, who) != 2 )
                          return notify_fail("");

                 if( what != "play" )
                          return notify_fail("");
        }

        call_other(BANGSKILLS + "play2", "exert", this_player(), this_player());
        return 1;
}

int ask_join()
{
        object ob = this_player(), obj, situ = this_object();
        string ob_fam;
        object sf_d;
	string myfam,mypos,msg,*msg_a,nowmsg,sfn;
	int lastscore,score,i;
        

        myfam = (string)query("fam");
        if( (string)ob->query_temp("bangs/fam") == myfam ) {
                say(name() + "大怒道：" + RANK_D->query_rude(ob) + "！竟敢开帮主的玩笑！！！\n");
                return 1;
        }


        if( time() < (int)ob->query("bangs/jointime") + 600 ) {
                say(name() + "大怒道：" + RANK_D->query_rude(ob) + "，你如此反复无常岂能容身于江湖！！！\n");
                return 1;
        }

        message_vision("$N重重地拍了一下$n的肩膀，喝道：好样的！从今以后跟兄弟们有难同当！\n", this_object(), ob);

        ob->set_temp("apply/short",
                ({ HIR + myfam + "帮众 "NOR + ob->query("name")+"("+capitalize(ob->query("id"))+")" }));
        ob->delete_temp("bangs");
        ob->delete("bangs");
        ob->set_temp("bangs/fam", myfam);
        ob->set("bangs/jointime", time());

        if( obj = present("bang ling", ob) )
                destruct(obj);

        obj = new(BANGLING);
        obj->set("owner", ob->query("id"));
        obj->set("fam", myfam);
        obj->set("combat_exp", query("combat_exp"));
        obj->set("long",
"这是" + myfam + "的帮令，上面刻着「" + ob->query("name") + "」。\n");
        obj->move(ob);
        message_vision("$N把一" + obj->query("unit") + obj->name() + "扔给$n。\n", this_object(), ob);
        
        score = ob->query("clbscore");
	if ( stringp (mypos = ob->query("clbpos")) )
	{	if ( score < 200000 )
		{	ob->delete("clbpos");
                        if( strlen ( msg = read_file(POSFILE)) > 0 )
			{   
                	msg_a = explode(msg,"\n");
                	msg="";
                	nowmsg = ob->query("id")+"("+ mypos + ")";
                        for(i=0; i< sizeof(msg_a); i++)
                        	if(msg_a[i] != nowmsg) msg += ( msg_a[i]+"\n");
                        write_file(POSFILE,msg,1);
                        }
                        switch(mypos)
                        {
                        case "龙灵堂" : write_file("/d/forest/sifang/sifang1_file","",1);sfn="1";break;
                        case "狮敏堂" : write_file("/d/forest/sifang/sifang2_file","",1);sfn="2";break;
        		case "熊威堂" : write_file("/d/forest/sifang/sifang3_file","",1);sfn="3";break;
        		case "鹰迅堂" : write_file("/d/forest/sifang/sifang4_file","",1);sfn="4";break;
        		case "蛇勇堂" : write_file("/d/forest/sifang/sifang5_file","",1);sfn="5";break;
        		}
        		if ( sf_d = find_object(SF_DIR + sfn) )
        			destruct(sf_d);
        		
                        message_vision(HIM"因为表现太差，$N的"+mypos+"香主一职被撤。\n"NOR,ob);
                        command("chat 因为工作不负责任，"+ ob->name()+ "的长乐帮"+ mypos +"香主职位被撤除。\n");
		}
		else
		{	ob->set_temp("bangs/pos", mypos);
        		ob->set_temp("bangs/pos_time", uptime());
        		ob->set_temp("bangs/pos_score", score);
                        
        		ob->set_temp("apply/short",
   			({ HIR + myfam + mypos + "香主 "NOR + ob->query("name")+"("+capitalize(ob->query("id"))+")" }));
   			message_vision("$N的"+mypos+"香主一职恢复了。\n",ob);
   		}
	}

        log_file("BangJoin", sprintf("%s于%s时加入%s\n", ob->query("name"), ctime(time()), myfam));
        return 1;
}

// duty 2 teach skills

string ask_skills()
{
        object ling, me = this_player();
        int amount;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        if( (string)me->query_temp("bangs/fam") != (string)query("fam") )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";
        
        if( (amount = (int)me->query("clbscore")) < 10 )
                return RANK_D->query_rude(me) + "再加把劲，帮主才会指点你一下！";

        if( amount > 100 ) {
                me->set_temp("bangs/skills_asked", 100);
               
                me->add("clbscore",-100);
        } 
        else {
                me->set_temp("bangs/skills_asked", amount);
                me->add("clbscore",-amount);
        }

        tell_object(me, "请键入：武功的英文名字。\n");
        return "好吧。";
}

int do_xue(string arg)
{
        object me = this_player();
        string *sname;
        int i, amount, level, mylvl;

        if( !(amount = (int)me->query_temp("bangs/skills_asked")) ) {
                write("你还没征求帮主同意呢。\n");
                return 1;
        }

        if( is_fighting() ) {
                say(name() + "大怒道：" + RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！");
                return 1;
        }

        if( !arg ) {
                sname = keys(query_skills());
                write("\n" + name() + "所学过的技能：\n\n");
                for(i = 0; i < sizeof(sname); i++)
                        write(to_chinese(sname[i]) + " (" + sname[i] + ")" + "\n");
                return 1;
        }

        if( (level = (int)query_skill(arg, 1)) < 1 ) {
                say(name() + "摇了摇头道：帮主没学过。\n");
                return 1;
        }

        mylvl = (int)me->query_skill(arg, 1);
        if( level < mylvl ) {
                say(name() + "大怒道：" + RANK_D->query_rude(me) + "居然超过老子了。\n");
                return 1;
        }

        if( mylvl > 120 ) {
                say(name() + "摇了摇头道：你得去门派中正式拜师才能继续提高" + to_chinese(arg) + "。\n");
                return 1;
        }

        if( (int)me->query("jing")*2 < (int)me->query("max_jing") ) { 
                write("你先歇会儿吧。\n");
                return 1;
        }
        me->add("jing", -(int)me->query("max_jing")/2 + 10);
        me->improve_skill(arg, amount * me->query("int") / 6); 
        me->delete_temp("bangs/skills_asked");

        message_vision("$N向$n请教有关「" + to_chinese(arg) + "」的疑问。\n", me, this_object());
        tell_object(me, "你听了帮主的指导，对「" + to_chinese(arg) + "」似乎有些心得。\n");
        return 1;
}

// duty 3 died to give bangyin
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void die()
{
        object ob, corpse, killer;

        if( !living(this_object()) ) revive(1);
        clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
                ob = new(BANGYIN);
                ob->set("long", query("fam") + ob->query("name") + "。\n");
                ob->move(environment());
                message_vision(HIR"\n突然从$N衣袋中掉下一" + ob->query("unit") + ob->name() + "。\n"NOR, this_object());
                set_temp("my_killer", killer->query("id"));
                ob->set("my_killer",  killer->query("id"));
                ob->set("combat_exp", query("combat_exp"));
        }
    
        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        destruct(this_object());
}
