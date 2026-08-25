// by fire on aug 1999
inherit M_CHAR;
inherit LIVING;
inherit M_BLOCKEXITS;
#define MARRY_GATE "/sgdomain/area/marriage/marry_gate"
string p_boy,p_girl;
string p_boyname,p_girlname;
string p_area;
string p_step;
private mapping p_gift=([]);
int p_life;
nosave protected string *chaois=({
    "一群小孩在房子里跑着，跳着，要着喜糖，$N连说：嘘，嘘，安静。\n",
    "几个小姑娘不在一起偷偷议论什么，捂着嘴，吃吃地笑着。\n",
    "一人高喊，新娘笑了，众人哄堂大笑。\n",
    "很多人挤在门外，想看个究竟。\n",
    "又来了一高官，与众人寒暄一通，站到一边。\n",
    "一个帐房先生跑进来，在$N耳边嘀咕了些什么，$N连连点头：好，好。\n",
    "屋外爆竹霹雳啪啦响个不停，好象过年一样。\n",
    "$N身板笔直，表情严肃地走来走去。\n",
    "$N对新来的宾客不停地点头致意。\n",
    "$N对几个快腿伙计不停地吩咐着什么。\n",

});


private mixed handle_blocks( string dir )
{
        string p_id;
	if(dir!="enter") return 0;
	p_id=this_body()->query_primary_id();
	if(p_id==p_boy) {
		this_object()->targetted_action(
		"$N对$T道：新郎官，太性急了，还没拜完天地就想进洞房呀。\n\n"+
		"众人哈哈大笑。\n",this_body());
		return 0;
	}
	if(p_id==p_girl) {
		this_object()->targetted_action(
		"$N对$T道：新娘子，太性急了，还没拜完天地就想进洞房呀。\n\n"+
		"众人哈哈大笑。\n",this_body());
		return 0;
	}
        return ::handle_blocks(dir);    
}

void setup()
{
    set_name("si yi", "司仪");
    set_gender(1);
    set_in_room_desc("\n屋内挂着一个大大的：\n
%^H_RED%^               ■        ■ 
          ■■■■■■■■■■■
               ■        ■
           ■■■■■■■■■■
             ■■■    ■■■
             ■  ■    ■  ■
             ■■■    ■■■
              ◆◆      ◆◆
           ■■■■■■■■■■
             ■■■    ■■■
             ■  ■    ■  ■
             ■■■    ■■■%^RESET%^\n"+
"\n中间站著一个身着绸袍的婚礼%^H_RED%^司仪%^RESET%^(si yi)\n");

    add_ask_str("xinren","$N对$T小声道：谁结婚呀，这么排场。\n");
    add_question("xinren","xinren" );

    add_ask_str("start","$N对$T小声道：是不是可以开始了。\n");
    add_question("start","start" );

    call_out("check",10);
    add_block("enter");

    set_block_action( "$N对$T一伸手挡住去路道：里面是新人的洞房，$R不便入内。\n");
}

string long() {
	return
"一个身着绸袍的婚礼%^H_RED%^司仪%^RESET%^，正在指挥这婚礼进程。\n";
}


void finish() {
	this_object()->simple_action("$N离开了。\n");	
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}
void jh_ring() {
	object o_girl,o_boy,*os;
	object o_girlring,o_boyring;

	o_girl=find_body(p_girl);
	if(!o_girl) return;

	o_boy=find_body(p_boy);
	if(!o_boy) return;

	os=all_inventory(o_girl);
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return ;
	o_girlring=os[0];

	os=all_inventory(o_boy);
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return ;
	o_boyring=os[0];

	o_girlring->do_remove();
	o_boyring->do_remove();

	o_girlring->move(o_boy);
	o_boyring->move(o_girl);

	o_boy->targetted_action("$N把手里的$o交给$T。\n",o_girl,o_boyring);
	o_girl->targetted_action("$N把手里的$o交给$T。\n",o_boy,o_girlring);

	o_girlring->do_wear();
	o_boyring->do_wear();
	return; 
}
void big_gift() {
	object *os,o_boy,o_girl;
	object o_l;
	string msg;
	msg="汉献帝龙颜大悦，对"+p_boyname+"，"+p_girlname+"和所有参加婚礼的人赐予祝福。\n";
	tell(users(),"%^H_RED%^【婚礼】"+msg);
	os=all_inventory(this_object()->query_room());
	os=filter_array(os,(:$1->query_link():));
	if(sizeof(os)) {
		foreach(object o in os) {
			o_l=new("/sgdomain/obj/other/shoyu");
			tell(o,"你得到一"+o_l->short()+"\n");
			o_l->move(o);
		}
	}

	o_girl=find_body(p_girl);
	if(objectp(o_girl)) {
		o_l=new("/sgdomain/area/emp/dan/yyd");
		tell(o_girl,"你得到一"+o_l->short()+"\n");
		o_l->move(o_girl);
		
	}

	o_boy=find_body(p_boy);
	if(objectp(o_boy) ) {
		o_l=new("/sgdomain/area/emp/dan/csd");
		tell(o_boy,"你得到一"+o_l->short()+"\n");
		o_l->move(o_boy);
		
	}
	this_object()->simple_action("众人都得到了汉献帝的礼物，大家都很高兴。\n");
}
string get_message() {
	string ret="";
	string g_area;
	object o_lg;
	ret+="新郎：%^H_RED%^"+p_boyname+"%^RESET%^("+p_boy+") 年龄："
		+chinese_number(CHAR_D->get_char(p_boy,"age"))+"\n";
	ret+="  家居："+AREA_D->get_area(p_area,"name");
	ret+=" 国家："+COUNTRY_D->get_country(AREA_D->get_area(p_area,"nation"),"name")+"\n";
	ret+="  国家官职："+OFFICER_D->query_rank_name(CHAR_D->get_char(p_boy,"ranknation"));
	ret+=" 地方官职："+OFFICER_D->query_rank_name(CHAR_D->get_char(p_boy,"ranklocal"))+"\n";

	g_area=CHAR_D->get_char(p_girl,"area");
	ret+="新娘：%^H_GREEN%^"+p_girlname+"%^RESET%^("+p_girl+") 年龄："
		+chinese_number(CHAR_D->get_char(p_girl,"age"))+"\n";
	ret+="  家居："+AREA_D->get_area(g_area,"name");
	ret+=" 国家："+COUNTRY_D->get_country(AREA_D->get_area(g_area,"nation"),"name")+"\n";
	ret+="  国家官职："+OFFICER_D->query_rank_name(CHAR_D->get_char(p_girl,"ranknation"));
	ret+=" 地方官职："+OFFICER_D->query_rank_name(CHAR_D->get_char(p_girl,"ranklocal"))+"\n";
	
	ret+="时间："+DAY_D->query_chinese_day()+ "公元"+CHINESE_D->chinese_time(time())+"\n";

	o_lg=CHAR_D->find_char("li guan");
	if(objectp(o_lg)) {
		mapping p_gift;
		string p_id;
		int p_mnt;
		p_gift=o_lg->get_gift();
		ret+="来宾：姓    名        礼    金\n";
		if(sizeof(p_gift)) {
			foreach(p_id, p_mnt in p_gift) {
				ret+=sprintf("      %-12s      黄金%s两\n",
				FINGER_D->get_chinese_id(p_id)+"("+p_id+")",chinese_number(p_mnt));
			}
		}
	}
	return ret;
}
void the_end() {
	object o;
	object *os;

	string message;
	os=all_inventory(this_object()->query_room());
	os=filter_array(os,(:$1->query_link():));
        os->stop_busy();

	message=get_message();
	NEWS_D->system_post("marriage",p_boyname+"与"+p_girlname+"正式成婚",
  	message,  "%^YELLOW%^乔国老%^RESET%^");

	o=CHAR_D->find_char("li guan");
	if(objectp(o)) {
		o->set_step("over");
		o->finish();
	}


	finish();

}
void check() {
	string msg;
	object o_boy,o_girl,me;
	o_boy=find_body(p_boy);
	o_girl=find_body(p_girl);
	p_life++;
	remove_call_out("check");
	call_out("check",6+random(7));
	if(!stringp(p_boy)) return;
	if(!objectp(o_boy)) {
		if((time()-LAST_LOGIN_D->query_last(p_boy)[0])>600) {
			this_object()->simple_action(
			"$N奇怪地道：新郎官不见了，看来婚礼是办不成了，大伙儿回去吧。\n");
			finish();
			return;
		}
	}
	if(!objectp(o_girl)) {
		if((time()-LAST_LOGIN_D->query_last(p_girl)[0])>600) {
			this_object()->simple_action(
			"$N奇怪地道：新娘子不见了，看来婚礼是办不成了，大伙儿回去吧。\n");
			finish();
			return;
		}
	}
	me=this_object();
	switch(p_step) {
		case "begin":
			msg="司仪高声宣道："+p_boyname+"和"+p_girlname+
			        "的婚礼正式开始了，来宾请肃穆观礼。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			DELAY_D->delay_simple_action(me,"礼堂马上安静下来，大家都密切地注视着婚礼的进程。\n",2);
			p_step="btd";
			return;

		case "btd":
			msg="司仪高声宣道：一拜天地。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			DELAY_D->delay_targetted_action(o_boy,o_girl,"$N和$T对天地俯身下拜。\n",2);
			p_step="bgt";
			return;

		case "bgt":
			msg="司仪高声宣道：二拜高堂。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			DELAY_D->delay_targetted_action(o_boy,o_girl,"$N和$T对父母前辈俯身下拜。\n",2);
			p_step="db";
			return;

		case "db":
			msg="司仪高声宣道：夫妻对拜。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			DELAY_D->delay_targetted_action(o_boy,o_girl,"$N和$T面对面，相互拜倒。\n",2);
			p_step="jh";
			return;

		case "jh":
			msg="司仪高声宣道：交换结婚戒指。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			call_out("jh_ring",2);
			p_step="jf";
			return;


		case "jf":
			msg="司仪高声宣道：交纳建房费。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			DELAY_D->delay_simple_action(o_boy,"$N恭恭敬敬奉上黄金一百两。\n",2);
			p_step="gift";
			return;

		case "gift":
			msg="司仪高声宣道：接收嘉宾礼品。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			{	
				object o_lg;
				int amt=1;
				o_lg=CHAR_D->find_char("li guan");
				if(objectp(o_lg)) {
					amt=o_lg->get_gift_amount();
				}
				CHAR_D->set_char(p_girl,"gold",
					CHAR_D->get_char(p_girl,"gold")+amt);
				DELAY_D->delay_simple_action(o_girl,
					"$N恭恭敬敬收下黄金"+chinese_number(amt)+"两。\n",2);
			}
			p_step="biggift";
			return;

		case "biggift":
			msg="司仪高声宣道：接受汉献帝祝福。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			call_out("big_gift",2);

			p_step="result";
			return;


		case "result":
			msg="司仪高声宣道："+p_boyname+"和"+p_girlname+"正式结为夫妻。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
                        DELAY_D->delay_targetted_action(o_boy,o_girl,"$N和$T紧紧地拥抱在一起。
众人起哄道：新郎新娘亲一个，新郎新娘亲一个！！
$T的脸「唰」地一下红了，羞答答地低下了头，把脸埋进了$N的怀里。
$N拗不过众人的威逼利诱，捧起$T的脸，深情地吻了下去。
$T害羞地闭上了眼睛，含羞答答的脸都快比喜服还红了。
众人开始大声计时：一～～二～～三～～。。。
\n",2);
			CHAR_D->set_char(p_girl,"mar",p_boy);
			CHAR_D->set_char(p_boy,"mar",p_girl);
			CHAR_D->set_char(p_girl,"pri_mar",0);
			CHAR_D->set_char(p_boy,"pri_mar",0);

			p_step="end";
			return;

		case "end":
			msg="司仪高声宣道："+p_boyname+"和"+p_girlname+"婚礼到此结束。\n";
			tell(users(),"%^H_RED%^【婚礼】"+msg);
			me->simple_action(msg);
			call_out("the_end",2);

			p_step="";
			return;


		case "normal":
			chaois();
			return;

		default :
			return;
	}


}
int set_boygirl(string boy,string girl) {
	p_boy=boy,p_girl=girl;
	p_boyname=CHAR_D->get_char(p_boy,"name");
	p_girlname=CHAR_D->get_char(p_girl,"name");
	p_area=CHAR_D->get_char(p_boy,"area");
	p_step="normal";
	p_life=1;
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
mixed ask_start(object o_boy) {
	string p_id=o_boy->query_primary_id();
	object o_girl;
	int p_money;
	object o_boyring,o_girlring,*os;
	string p_boyring,p_girlring;
	int p_allplayer,p_hereplayer,p_requireplayer;
	mapping wear;

	if(p_step!="normal")
		return "$N对$T道：嘘，已经开始了，小心点。\n";
	if(p_id!=p_boy)
		return "$N对$T道：新郎官还没有着急，你着什么急。\n";
	o_girl=find_body(p_girl);
	if(o_girl->query_room()!=this_object()->query_room())
		return "$N对$T道：新娘子还没有来，你和谁结婚呀。\n";
	p_money=o_boy->query_all_con_money();
	if(p_money<1000000) 
		return "$N对$T道：$R一百两金子的建房费还没有准备好吧，没有房子可不能结婚。\n";

	os=all_inventory(o_girl);
	if(!sizeof(os)) 
		return "$N皱皱眉头，新娘子怎么光着身子就跑来了。\n";
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return "$N皱皱眉头，新娘子怎么还没有戴结婚戒指。\n";
	o_girlring=os[0];
	p_girlring=o_girlring->query_primary_id();

	os=all_inventory(o_boy);
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return "$N皱皱眉头，新郎官怎么还没有戴结婚戒指。\n";
	o_boyring=os[0];
	p_boyring=o_boyring->query_primary_id();

	os=all_inventory(this_object()->query_room());
	os=filter_array(os,(:$1->query_link():));
	
	p_hereplayer=sizeof(os)-2;
	p_allplayer=sizeof(users())-2;

	p_requireplayer=bmin(10,p_allplayer/3);
	if(p_hereplayer<p_requireplayer) 
		return "$N对$T道：目前共有"+chinese_number(p_allplayer)+
			"位其他玩家在线，这里只来了"+chinese_number(p_hereplayer)+
			"位嘉宾。新郎新娘还需要再去请"+chinese_number(p_requireplayer-p_hereplayer)+
			"位嘉宾观礼节。\n";
	o_boy->set_all_con_money(p_money-1000000);


	wear=CHAR_D->get_char(p_boy,"wear");
	if(!mapp(wear))	wear=([]);
	wear["hands"]=p_girlring;
	o_girlring->set_owner(p_boy);
	CHAR_D->set_char(p_boy,"wear",wear);

	wear=CHAR_D->get_char(p_girl,"wear");
	if(!mapp(wear))	wear=([]);
	wear["hands"]=p_boyring;
	o_boyring->set_owner(p_girl);
	CHAR_D->set_char(p_girl,"wear",wear);

	os->start_busy(600,"婚礼正在进行，请保持安静。\n");
	return 1;	
}
void special_answer(object who, string matt)
{
	string p_id;
	mixed ret;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "xinren" :
			this_object()->targetted_action(
				"$N对$T神秘地道：$R不知：新人乃大名鼎鼎的"+
				p_boyname+"和"+p_girlname+"呀。\n",who);
			return; 
		case "start":
			ret=ask_start(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}
			p_step="begin";
        }
}

int query_clean_up() {
	return 1; // if p_life<200 can't clean up
}
