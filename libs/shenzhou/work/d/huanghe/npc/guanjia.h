// Code of ShenZhou
// /d/huanghe/npc/guanjia.h
// by aln 2 / 98

string ask_job()
{
        object me = this_player(), leader, ling, ob, *obj, dest, room,obtemp;
        string myfam, *files, file, region, biaoju, ob_bang,place ,name;
        int i, temp, myexp,n,sz,highprice,lowprice,tim;
        mapping job;
        object npcroom;

        string *levels = ({
                   "0",
                "2000",
                "3500",
                "5000",
               "10000",
               "20000",
               "50000",
              "100000",
              "200000",
              "400000",
              "1000000",
              "2000000",
        });

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";  

        tim = 120 + me->query("combat_exp")/200000;
        
/*      没有道理，buwu 暂时屏蔽  
	if( objectp(leader = me->query_leader()) ) {
                if( leader != this_object() )
                         return RANK_D->query_rude(me) + "！入了帮还三心二意跟别人？！";
        }
*/

        if( !(ling = present("bang ling", me)) ) {
                ling = new(BANGLING);
                ling->set("owner", me->query("id"));
                ling->set("fam", myfam);
                ling->set("combat_exp", query("combat_exp"));
                ling->move(me);
                me->delete_temp("recovered");
                message_vision("$N把一" + ling->query("unit") + ling->name() + "扔给$n。\n", this_object(), me);
        }

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;

        temp = sizeof(levels);
        if (myexp > 4000000)
                return "阁下武功已经如此高强,不用再拿老头子我寻开心了吧.";

//      if (mapp(ling->query("job"))) 
        if( time() < (int)me->query("clb_busy_time") + BUSY_TIME )
                return RANK_D->query_rude(me) + "不是刚问过我吗？";

        me->set("clb_busy_time", time());
        for( i = temp-1; i >= 0; i-- ) 
                if( myexp >= atoi(levels[i]) ) break;

        if( i < 0 )
                return "小兄弟毫无江湖经验,还是不做为妙。";
        
        job=ling->query("job");
        
        if ( mapp(job) )
        	if (job["type"]=="买卖")
        		if (ob=present(job["good"],me))
        			destruct(ob);        		
        
        job = (BANGJOB + levels[i])->query_job();

        if( mapp(ling->query("job")) )
                ling->delete("job");
        ling->set("job", job);

        if( ob = present("caili", me) )
                destruct(ob);
                
        name = (string)me->query("name");
                
        switch(job["type"]) {
        case "寻":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return name + "，你去把" + job["name"] + "找来。";
                break;

        case "杀":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                if( (job["where"]!="") && (job["where"]!="random"))    
                {
                npcroom=find_object(job["where"]);
                if (! npcroom)      npcroom=load_object(job["where"]);
                if (npcroom)   npcroom->reset();
                }
                return name + "，你去把" + job["area"] + "的" + job["name"] + "杀了。\n" + "记得在尸体上留下我帮的印记（sign），好让江湖中人知道我们长乐帮的厉害。";
                break;

        case "摊费":
                command("nod");
                job = info_store[random(sizeof(info_store))];
                ling->set("job/name", job["name"]);
                ling->set("job/boss", job["boss"]);
                ling->set("job/place", job["place"]);
                ling->set("job/is_kill",0);
                me->delete("job/killer");
		if( (job["place"]!="") && (job["place"]!="random"))     
                { 
                	npcroom=find_object(job["place"]); 
                     	if (! npcroom)	npcroom=load_object(job["place"]); 
                     	if (npcroom)	npcroom->reset(); 
                } 
                return  name + "，" + ling->query("job/name") + "这个月还没有交摊费，快去要(collect)来！";
//                log_file("debug/clb2", sprintf("give %s qustion \n\t\tname : %s\n\t\tboss: %s \n\t\tplace : %s", me->query("id"), job["name"]+"  "+ling->query("name"), job["boss"] + "  " + ling->query("boss"), job["place"] + "  " + ling->query("place")));
                log_file("debug/clb2", me->query("id") + "######" + job["name"]+"  "+ling->query("name") + "#####" + job["boss"] + "  " + ling->query("boss") + "#####" + job["place"] + "  " + ling->query("place"));
                log_file("debug/clb2", "test\n");
                break;

        case "截镖":
                obj = filter_array(children(BIAOTOU), (: clonep :));
                if( sizeof(obj) < 10 ) {
                        ob = new(BIAOTOU);
                        ob->setskill(myexp);
                        file = biao_places[random(sizeof(biao_places))];
                        ob->move(file);
                        dest = environment(ob);            
                        message("vision",
                        ob->name() + "押着镖车走了过来。\n",
                        dest, ({ob}));
                        region = explode(file, "/")[1];
                        ling->set("job/name", ob->query("nickname"));
                        return name + "，去踩盘的弟兄们回来讲，" + 
                        ob->query("nickname") + 
                        "的镖车将经过" + 
                        region_names[region] + dest->query("short") + "。";
                } else {
                        ob = obj[random(sizeof(obj))];
                        dest = environment(ob);
                        biaoju = (string)ob->query("nickname");

                        if( !dest || !biaoju ) {
                                destruct(ob);
                                command("shake");
                                return name + "，你歇着吧，最近没有要紧的帮务。";
                        }

                        file = base_name(dest);
                        if( strsrch(file, "/d/") != 0
                        || !mapp(dest->query("exits")) ) {
                                destruct(ob);
                                command("shake");
                                return name + "，你歇着吧，最近没有要紧的帮务。";
                        }

                        command("nod");
                        region = explode(file, "/")[1];
                        ling->set("job/name", biaoju);
                        ob->setskill(myexp);
                        return name + "，去踩盘的弟兄们回来讲，" + biaoju + 
                        "的镖车将经过" + 
                        region_names[region] + dest->query("short") + "。";
                }
                break;

        case "示威":
                obj = filter_array(children(BANGZHONG), (: clonep :));
                if( !sizeof(obj) ) {
                         command("shake");
                         return name + "，你歇着吧，最近没有什么帮派对我们不敬。";
                }
                if( sizeof(obj) ) {
                obj = filter_array(obj, "is_victim", this_object(), myfam);
                if( sizeof(obj) ) {
                        sz=sizeof(obj);ob=obj[0];
                        if (me->query("combat_exp")>100000)
                        {      	for (n=1;n<sz;n++)
                        	{obtemp=obj[n];
                         	if (obtemp->query("combat_exp") > ob->query("combat_exp"))
                         		ob=obtemp;
                        	}
                        }else
                        {	for (n=1;n<sz;n++)
                        	{obtemp=obj[n];
                         	if (obtemp->query("combat_exp") < ob->query("combat_exp"))
                         		ob=obtemp;
                        	}
                        }
                        command("nod");
                        ob_bang = (string)ob->query("title");
                        me->set_temp("bangs/victim", ob_bang);
                        ling->set("job/name", ob_bang);
                        return name + "，最近" + ob_bang + "经常跟我们过不去，你去杀一个示示威！";
                }
                }
                break;

        case "送礼":
                command("nod");

                job = info_guest[random(sizeof(info_guest))];
                region = explode(job["file"], "/")[1];

                ob = new(CAILI);
                ob->set("job", job);
                ob->set("owner", me);
                ling->set("job/title", job["title"]);
                ling->set("job/area", job["area"]);
                ob->set("long",
"这是一份" + myfam + "帮主送给" + "「" + job["title"] + "」" + "的彩礼。\n");
                ob->move(me);
                message_vision("$N将一" + ob->query("unit") + ob->name() + "交给$n。\n", this_object(), me);
                message_vision(CYN"$N对$n说到：你把这份彩礼送给(song)" + job["area"] + "的" + "「" + job["title"] + "」" + "。\n"NOR,this_object(),me);
		if( (job["file"]!="") && (job["file"]!="random"))     
                { 
                	npcroom=find_object(job["file"]); 
                     	if (! npcroom)	npcroom=load_object(job["file"]); 
                     	if (npcroom)	npcroom->reset(); 
                } 
                return "这趟差事可能十分危险，如果你中途觉得不行了就放弃(giveup)，别枉送性命。";
                log_file("debug/clb2", sprintf("give %s qustiong :\n\ttype: %s\n\tling info: %O\n\t job info: %O\n", me->query("id"), job["type"], ling->query_entire_dbase(), job));
                break;

        case "买卖":
                command("nod");
                files = get_dir(BANGGOOD);
                if( !sizeof(files) ) {
                         command("shake");
                         return name + "，你歇着吧，最近没有要紧的帮务。";
                }
                file = BANGGOOD + files[random(sizeof(files))];
                ob = new(file);
                ob->move(me);
                message_vision("$N将一" + ob->query("unit") + ob->name() + "交给$n。\n", this_object(), me);
                place=info_business[random(sizeof(info_business))];
                ling->set("job/name", ob->name());
                ling->set("job/good", ob->query("id"));
                ling->set("job/place",place);
                return name + "，你把这" + ob->query("unit") + ob->name() + "拿去估价(bargain),争取卖个好价钱。";
                break;

        case "伙计":
                command("nod");
                ling->set("job/name", "伙计");
                return name + "，你去天宝阁当差吧。";
                break;
        }

        command("shake");
        return name + "，你歇着吧，最近没有要紧的帮务。";
}

void do_start(object me, object ob)
{
        ob->move(environment());
        destruct(this_object());
}

int accept_object(object who, object ob)
{
        object obj;
        int bonus, record;
        string name, chname = "";
        mapping job;
        int addscore;
        record=0;bonus=0;
        
        
        if( who->query_temp("bangs/fam") != query("fam") ) 
                return notify_fail(name() + "大怒道：大胆！想谋害本总管！！！\n");

        if( !(obj = present("bang ling", who)) )
                return notify_fail(name() + "大怒道：没有用的东西，连帮令都会搞丢？！\n");

        if( !mapp(job = obj->query("job")) )
                return notify_fail(name() + "大怒道：没有用的东西，连自己的帮务都记不住？！\n");

        addscore=obj->query("score")/5000;
        if (addscore>30) addscore=30;
        
        switch(job["type"]) {
        case "寻":
                name = ob->name();
                for(int i = 0; i < strlen(name); i++)
                        if(name[i] > 160 && name[i] < 255) 
                                chname += name[i..i];
                if( chname != job["name"] )
                        return notify_fail(name() + "大怒道：没有用的东西，连自己的帮务都记不住？！\n");
                bonus = job["bonus"]+ random(job["bonus"]);
                bonus = bonus + addscore;
                record = bonus*2 + random(bonus/2);
                log_file("BangJob", sprintf("%s于%s时找到%s得%s经验点\n", who->query("name"), ctime(time()), chname, chinese_number(record)));
                break;

        case "截镖":
                if( base_name(ob) != BIAOHUO )
                        return notify_fail(name() + "大怒道：没有用的东西，连一枝镖都搞不定！\n");
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail(name() + "大怒道：江湖中最讲究的就是信用，再欺世盗名就宰了你！\n");
                bonus=50 - ( ob->query("combat_exp") - 100000 )/10000;
                bonus = bonus + addscore;
                record = bonus * 3 - random(bonus);
                log_file("BangJob", sprintf("%s于%s时截镖得%s经验点\n", who->query("name"), ctime(time()),chinese_number(record)));
                break;  
        }

        if( record == 0 ) return notify_fail("贝海石大怒道：你给我这个干吗？\n");
        command("nod");
        obj->delete("job");

        who->add("combat_exp", record);
        who->add("shen", -random(bonus/4));
        
        message_vision(CYN"$N拍了拍$n的头，说道：干的好！继续努力以后自有大的好处给你。\n"NOR,this_object(),who);
        write(HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(record)+ "点经验值。\n"NOR);
        who->add("clbscore",bonus);

        remove_call_out("store");
        call_out("store", 1, ob);
        return 1;
}

void store(object ob)
{
        ob->move("/d/shenlong/cangku");
}

private int is_victim(object ob, string arg)
{
        string fam;

        if( !stringp(fam = ob->query("title")) ) return 0;
        if( fam == arg ) return 0;

        return 1;
}
