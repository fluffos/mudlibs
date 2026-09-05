// npc: /d/city/npc/wei.c
// Jay 5/15/96

inherit NPC;

string s_skill;
string ask_special_skill();
void create()
{
        set_name("韦春芳", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "女性" );
	set("title", "丽春院老板娘");
     set("start_room","/d/city/lichunyuan");
//	set("nickname", "鹿鼎公");
        set("age", 42);
        set("long", 
            "韦春芳是当朝鹿鼎公兼红花会总舵主韦小宝他娘，虽是徐"
	    "娘半老，但风韵尤存。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
		// 特别技能指导能力
		s_skill = "loving-skill";
        set("inquiry", ([
            "name" : "老娘我就是韦春芳。",
            "韦小宝" : "那是我的乖儿子，长得就像你。",
            "丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
            "here" : "我们丽春院可是扬州城里头一份的找乐子去处。",
                s_skill       : (: ask_special_skill :),
       ]) );

        setup();
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "韦春芳得意地说道：当年老娘我标致得很，每天有好几个客人。\n",
                "韦春芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到丽春院来，老娘用大扫帚拍了出去?。\n",
                "韦春芳对你说道：你一双眼睛贼忒嘻嘻的，真像那个喇嘛！\n",
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}


string ask_special_skill()
{
	object user;
	int cur_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，我已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
					
		if (!SPECIAL_D->query_level(user, "master-con"))
			return "你先要修习"+to_chinese("master-con")+"(master-con)才能修练"+to_chinese(s_skill)+"。";
					
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句＃￥＊％的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			return "我儿子可是皇帝身边的大红人！";
		}
	}
	return "什么？";
}

int accept_object(object user, object ob)
{
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	return 0;
}


void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="无性") {
       command("say 你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，就是不伺候太监！");
       command("kick " + me->query("id"));
       message("vision", me->name() +"被韦春芳一脚踢出门外。\n",
                environment(me), ({me}));
	if(base_name(environment(this_object())) == "/d/city/lichunyuan")
	{
		me->move("/d/city/nandajie2");
                return;
	}
       message("vision", me->name() +"被人从丽春院里踢了出来，栽倒在地上，磕掉两颗门牙。\n", 
                environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say 呦，" + RANK_D->query_respect(me) 
                +"也来光顾我们丽春院啊。");
       command("say 想当年我接过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。");
    }
    if (me->query("gender")=="女性") {
       command("say 哎呀，这年月大姑娘也逛窑子，成何体同。");
       command("sigh");
       command("say 可惜我儿子不在，不然让他伺候你。");
    }
    command("say 楼上楼下的姑娘们，客人来了！");
    }
    return ;
}

