// channeld.c
#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <mudlib.h>
#include <net/macros.h>
#include <net/dns.h>
#include <localtime.h>

inherit F_DBASE;

#define ALLOW_LIST ({ })
#define SPECIAL_NPC     ({ "/adm/npc/youxun" })

#define REMOTE_Q	"/adm/daemons/network/services/remote_q.c"

string remove_addresses(string, int);
int filter_listener(object ppl, string only, object me);
string channel_filter(object me,string input);

static string msg_log;
static int log_from;

string query_msg_log() { return msg_log; }

mapping channels = ([
	"sys":  ([      "msg_speak": HIR "【系统】%s：%s"NOR"\n",
			"msg_emote": HIR "【系统】%s" NOR"\n",
			"msg_color": HIR,
			"only"     : "wiz",
			"name"     : "系统",
			"omit_log" : 1,
		]),

	"wiz":  ([      "msg_speak": HIY "【巫师】%s：%s"NOR"\n",
			"msg_emote": HIY "【巫师】%s" NOR"\n",
			"msg_color": HIY,
			"name"     : "巫师",
			"only"     : "wiz",
			"intermud" : GCHANNEL,
			"intermud_emote"   : 1,
			"intermud_channel" : "wiz",
			"omit_address": 0,
			"omit_log" : 1,
			"filter"   : (: $1["MUDLIB"] == MUDLIB_NAME :)
		]),

	"debug":([      "msg_speak": HIW "【调试】%s：%s"NOR"\n",
			"msg_emote": HIW "【调试】%s" NOR"\n",
			"msg_color": HIW,
			"name"     : "调试",
			"only"     : "wiz",
			"omit_log" : 1,
		]),

	"inter":([      "msg_speak": HIR "【同盟】%s：%s"NOR"\n",
			"msg_emote": HIR "【同盟】%s" NOR"\n",
			"msg_color": HIR,
			"only"     : "league",
			"name_raw" : 1,
			"name"     : "同盟",
			"omit_log" : 1,
		]),

	"chat": ([      "msg_speak": HIW "【闲聊】%s：%s"NOR"\n",
			"msg_emote": HIC "【闲聊】%s" NOR"\n",
			"msg_color": HIC,
			"name"     : "闲聊",
		]),

	"ic"  : ([      "msg_speak": HIC "【异域】%s：%s"NOR"\n",
			"msg_emote": HIC "【异域】%s" NOR"\n",
			"msg_color": HIC,
			"intermud" : GCHANNEL,
			"intermud_emote"   : 1,
			"intermud_channel" : "ic",
			"name"     : "异域",
			"filter"   : (: $1["MUDLIB"] == MUDLIB_NAME :)
		]),
	"kuafu": ([      "msg_speak": HIM "【跨服】%s：%s"NOR"\n",
			"msg_emote": HIM "【跨服】%s" NOR"\n",
			"msg_color": CYN,
			"name"     : "跨服",
		]),
		
	"bill": ([      "msg_speak": YEL "【交易】%s：%s"NOR"\n",
			"msg_color": YEL,
			"name"     : "交易",
			"name_raw" : 1,
			"omit_log" : 1,
		]),
		
		"cajj": ([      "msg_speak": HIY "【新闻】%s：%s"NOR"\n",
			"msg_color": YEL,
			"name"     : "新闻",
			"name_raw" : 1,
			"omit_log" : 1,
		]),

	"ultra": ([     "msg_speak": WHT "【宗师】%s：%s"NOR"\n",
			"msg_emote": WHT "【宗师】%s" NOR"\n",
			"msg_color": WHT,
			"name"     : "大宗师",
			"intermud" : GCHANNEL,
			"intermud_emote"    : 1,
			"intermud_channel"  : "rultra",
			"filter"   : (: $1["MUDLIB"] == MUDLIB_NAME :)
		]),

	"shout":([      "msg_speak": HIW "%s纵声长啸：%s"NOR"\n",
		]),

	"rumor":([      "msg_speak": HIM "【谣言】%s：%s"NOR"\n",
			"msg_emote": HIM "【谣言】%s" NOR"\n",
			"msg_color": HIM,
			"name"     : "谣言",
			"anonymous": "某人",
		]),
	"sos":  ([      "msg_speak": HIG "【求助】%s：%s"NOR"\n",
			"msg_color": HIG,
			"name_raw" : 1,
			"name"     : "求助",
		]),
	"party":([      "msg_speak": HIG "【帮派】%s：%s"NOR"\n",
			"msg_emote": HIG "【帮派】%s" NOR"\n",
			"msg_color": HIG,
			"only"     : "party",
			"name"     : "帮派",
			"omit_log" : 1,
		]),
	"family":([     "msg_speak": HIG "【同门】%s：%s"NOR"\n",
			"msg_emote": HIG "【同门】%s" NOR"\n",
			"msg_color": HIG,
			"only"     : "family",
			"name"     : "同门",
			"omit_log" : 1,
		]),
	"rultra":([     "msg_speak": WHT "【塞外宗师】%s：%s"NOR"\n",
			"msg_emote": WHT "【塞外宗师】%s" NOR"\n",
			"msg_color": WHT,
			"name"     : "塞外宗师",
			"for_listen": 1,
		]),
	"jiaoyi":([	"msg_speak": HIW "【拍卖】%s：%s"NOR"\n",
			"msg_color": HIW,
			"name"     : "拍卖场",
		]),
	"xinwen":([      "msg_speak": HIW "【新闻】%s：%s"NOR"\n",
			"msg_emote": HIW "【新闻】%s" NOR"\n",
			"msg_color": HIW,
			"name"     : "新闻",
			"anonymous": "新闻",
		]),
]);

void create()
{
	// This is required to pass intermud access check.
	seteuid(getuid());
	set("channel_id", "频道精灵");
}

// 记录频道消息的日志
void channel_log(string msg, string verb, object user)
{
	string lfn;
	mixed lt;
	int t;

	if (! mapp(channels[verb]) || ! objectp(user) || ! userp(user))
		return;

	if (channels[verb]["omit_log"])
		return;

	if (! stringp(msg_log)) msg_log = "";

	t = time();
	msg_log += sprintf(" %s(%s) on %s\n%s",
			   user->name(1), user->query("id"), log_time(), filter_color(msg));
	if (strlen(msg_log) > 8000 || t - log_from > 900)
	{
		lt = localtime(t);

		lfn = sprintf("channel/%d-%d-%d", lt[LT_YEAR],
			      lt[LT_MON] + 1, lt[LT_MDAY]);
		assure_file(LOG_DIR + lfn);
		log_file(lfn, msg_log);
		msg_log = "";
		log_from = t;
	}
}

// 接收REMOTE_Q返回来的信息并显示之
void do_remote_channel(object me, string verb, string arg)
{
	object *obs;
	string msg;

	if (undefinedp(channels[verb]) || ! userp(me))
		return;

	// Ok, I will direct send the message to those people listening us.
	obs = all_interactive();
	if (stringp(channels[verb]["only"]))
		obs = filter_array(obs, (: filter_listener :),
				   channels[verb]["only"], me);

	msg = sprintf(channels[verb]["msg_emote"], arg);
	message("channel:" + verb, msg, obs);
	channel_log(msg, verb, me);

	// 向各个站点发送EMOTE信息
	channels[verb]["intermud"]->send_msg(channels[verb]["intermud_channel"],
					     me->query("id"), me->name(1),
					     arg, 1,
					     channels[verb]["filter"]);
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
	object *obs;
	string *tuned_ch, who;
	int v,is_player;
	string imsg = 0, local;
	string msg,svip;

	string party;
	string family;
	string fname;

	// Check if this is a channel emote.
	if (sizeof(verb) > 2)
	{
		if (verb[sizeof(verb) - 1] == '*')
		{
			emote = 1;
			verb = verb[0..<2];
		}
	}

	// Check if this is a channel messsage.
	if (! mapp(channels) || undefinedp(channels[verb])) return 0;

	if (me->is_chatter())
		return notify_fail("聊天魂魄目前不能使用各种频道。\n");

	is_player = playerp(me);
	if (is_player && ! wizardp(me))
	{
		if (!me->query("born"))
			return notify_fail("你还没出生呢。。。\n");

		if (! me->query("registered"))
			return notify_fail("你必须在注册以后才能够使用各种频道。\n");

		if( strlen(arg)>60)
			return notify_fail("一句话说这么长不累么？\n");

		if (verb == "ic" && me->query("age") < 18)
			return notify_fail("你必须成年以后才能使用" + channels[verb]["name"] +  "频道。\n");
		if (verb == "jiaoyi")
			return notify_fail("你无法使用" + channels[verb]["name"] +"频道。\n");
	}

	// now we can be sure it's indeed a channel message:
	if (! stringp(arg) || arg == "" || arg == " " ) arg = "...";

	if (ultrap(me))
	{
		if (verb == "chat" && ! me->query("env/no_autoultra"))
			verb = "ultra";
	} else
		if (is_player && verb == "ultra")
			return notify_fail("等你成了大宗师再使用这个频道吧！\n");

	// player broadcasting need consume jing
	if (userp(me) && verb == "rumor" && ! objectp(present("rumor generator", me)))
		if (me->query("jing") > 200) me->add("jing", -150);
		else
		return notify_fail("你的精神不足以散播谣言！\n");

	if (userp(me) && me->ban_say(1)) return 0;

	// check if rumor or chat is blocked
	if (me->query("chblk_on"))
		return notify_fail("你的频道被关闭了！\n");

	if (userp(me))
	{
		if (time() - me->query_temp("last_use_channel") < 4)
		{
			if (me->query_temp("last_message") == arg)
				return notify_fail("不要在短期内使用频道发布重复的信息。\n");
			me->set_temp("last_message", arg);
		} else
		{
			me->set_temp("last_message", arg);
			me->set_temp("last_use_channel", time());
		}

		switch (channels[verb]["only"])
		{
		case "wiz":
			if (wiz_level(me) < 3)
				return 0;
			break;

		case "arch":
			if (wiz_level(me) < 4)
				return 0;
			break;

		case "party":
			if (! (party = me->query("banghui/name")))
				return notify_fail("你还是先加入一个帮派再说吧。\n");

			if (strlen(party) == 6)
			{
				party = party[0..1] + " " +
					party[2..3] + " " +
					party[4..5];
			}
			channels[verb]["msg_speak"] = HIG "【" + party +
						      "】%s：%s"NOR"\n";
			channels[verb]["msg_emote"] = HIG "【" + party +
						      "】%s" NOR"\n";
			break;

		case "family":
			if (! (family = me->query("family/family_name")))
				return notify_fail("你还是先加入一个门派再说吧。\n");

			if (strlen(family) == 6)
			{
				family = family[0..1] + " " +
					 family[2..3] + " " +
					 family[4..5];
			}
			channels[verb]["msg_speak"] = HIG "【" + family +
						      "】%s：%s"NOR"\n";
			channels[verb]["msg_emote"] = HIG "【" + family +
						      "】%s" NOR"\n";
			break;

		case "league":
			if (! (fname = me->query("league/league_name")))
				return notify_fail("你还是先和别人结义同盟再说吧。\n");

			switch (strlen(fname))
			{
			case 4:
				fname = "【 " + fname[0..1] + "  " + fname[2..3] + " 】";
				break;
	
			case 6:
				fname = "【 " + fname + " 】";
				break;
	
			case 8:
				fname = "【" + fname + "】";
				break;
	
			case 10:
				fname = "【" + fname[0..7] + "】";
				break;
			}
			channels[verb]["msg_speak"] = HIR + fname + "%s：%s"NOR"\n";
			channels[verb]["msg_emote"] = HIR + fname + "%s" NOR;
			break;
		}
	}

	if(userp(me)) arg = channel_filter(me,arg);

	if (verb == "shout")
	{
	    	if (! arg) return notify_fail("你想要大叫什么？\n");
	    
		if (! wizardp(me) && userp(me))
		{
			if (me->query("neili") < 500)
				return notify_fail("你的内力太差，无法喊出那么大的声音。\n");
		    
			me->add("neili", - (random(200) + 300));
		}

		msg = HIW + me->name(1) + "纵声长啸：" + arg  + NOR + "\n";
	    	shout(msg);
	    	write(HIW + "你纵声长啸：" + arg + NOR + "\n");
		channel_log(msg, verb, me);
		return 1;
	}

	// If we speaks something in this channel, then must tune it in.
	if (userp(me))
	{
		if (! pointerp(tuned_ch = me->query("channels")))
		{
			me->set("channels", ({ verb }));
			write("你打开了" + channels[verb]["name"] + "频道。\n");
		} else
		if (member_array(verb, tuned_ch) == -1)
		{
			me->set("channels", tuned_ch + ({ verb }));
			write("你打开了" + channels[verb]["name"] + "频道。\n");
		}

		if (channels[verb]["for_listen"])
		{
			write("这个频道只能用来听取别人的交谈。\n");
			return 1;
		}
	}

	// Support of channel emote
	if (emote && me->is_character())
	{
		string vb, emote_arg, mud;

		if (undefinedp(channels[verb]["msg_emote"]))
			return notify_fail("这个频道不支持表情动词。\n");

		if (sscanf(arg, "%s %s", vb, emote_arg) != 2)
		{
			vb = arg;
			emote_arg = "";
		}

		// internet channel emote
		if (channels[verb]["intermud_emote"])
		{
			if (sscanf(emote_arg, "%s@%s", emote_arg, mud) == 2 &&
			    htonn(mud) != mud_nname())
			{
				REMOTE_Q->send_remote_q(mud, verb, me->query("id"), emote_arg, vb);
				write("网路讯息已送出，请稍候。\n");
				return 1;
			}

			local = sprintf("%s(%s@%s)", me->name(1), capitalize(me->query("id")),
						     upper_case(INTERMUD_MUD_NAME));
			imsg = EMOTE_D->do_emote(me, vb, emote_arg, 3, local,
						 channels[verb]["msg_color"]);
			if (stringp(imsg))
				arg = replace_string(imsg, local, me->name());
			else
				arg = 0;
		} else
		if (verb == "rumor")
			arg = EMOTE_D->do_emote(me, vb, emote_arg, 2,
					channels[verb]["anonymous"],
					channels[verb]["msg_color"]);
		else
			arg = EMOTE_D->do_emote(me, vb, emote_arg, 1,
					0, channels[verb]["msg_color"]);
	
		if (! arg && emote == 2)
			arg = (channels[verb]["anonymous"] ? channels[verb]["anonymous"]
							   : me->name(channels[verb]["name_raw"])) +
							     vb + "\n";
	
		if (! arg)
			return 0;
	}

	// Make the identity of speaker.
	if (channels[verb]["anonymous"])
	{
		who = channels[verb]["anonymous"];
	} else
	if (is_player || ! stringp(who = me->query("channel_id")))
	{
	string descc,menpai,banghui;

	if (present("wu shuang", me))
	{
	descc = sprintf(BOLD ZJSIZE(21)+HIR"「武林至尊」"NOR,ZJSIZE(23));
	}
	else	
	if (present("dong xie", me))
	{
	descc = sprintf(BOLD HIW"「绝世无双」"NOR,ZJSIZE(25));
	}
	else 
	if (present("xi du", me))
	{
	descc = sprintf(BOLD HIR"「横贯八方」"NOR,ZJSIZE(23));
	}
	else 
	if (present("taohua zhi", me))
	{
	descc = sprintf(BOLD HIR"桃花剑神」"NOR,ZJSIZE(23));
	}
	else 
	if (present("bei gai", me))
	{
	descc = sprintf(BOLD HIG"「一代宗师」"NOR,ZJSIZE(20));
	} 	
	else
	if (present("nan di", me))
	{
	descc = sprintf(BOLD HIM"「侠骨丹心」"NOR,ZJSIZE(23));
	}
	else
	if (me->query("id")=="z110614_1")
	{
	descc = sprintf(HBYEL"%s【老魔】 "NOR,ZJSIZE(23));
	} else 
	if (me->query("dudu"))
	{
	descc = sprintf(BOLD HIR"「不管事」"NOR,ZJSIZE(23));
	}
		else
				{
				descc = "";
				}
		   if (me->query("banghui/name"))
{
      banghui = sprintf(BOLD "%s%s", ZJSIZE(23), me->query("banghui/name"));
}
	else
				{
				banghui = "";
				}
   if (me->query("family/family_name"))
{
      menpai = sprintf(HIR "%s%s", ZJSIZE(30), me->query("family/family_name"));
}
	else
				{
				menpai = "";
				}
		who = me->name(channels[verb]["name_raw"]);
		if (who == me->name(1))
			
//		else		
//		if(me->query("id")=="dudu66")
//		{
//		who = descc+channels[verb]["msg_color"]+ZJURL("cmds:look "+me->query("id"))+ZJSIZE(25)+who+NOR;	
//		}
		if(me->query("chenghao"))
		{
		who = descc+channels[verb]["msg_color"]+ZJURL("cmds:look "+me->query("id"))+ZJSIZE(25)+who+NOR+HIC"["+me->query("chenghao")+"]"NOR;
		}else
		if(me->query("title")&&me->query("chenjch"))
		{
		who = descc+channels[verb]["msg_color"]+HIW"【"+me->query("title")+HIW"】"+ZJURL("cmds:look "+me->query("id"))+ZJSIZE(25)+who+NOR+HIC""+me->query("chenjch")+""NOR;
		}else
		if(me->query("chenjch"))
		{
		who = descc+channels[verb]["msg_color"]+ZJURL("cmds:look "+me->query("id"))+ZJSIZE(25)+who+NOR+HIC""+me->query("chenjch")+""NOR;
		}else
		if(me->query("title"))
		{
		who = descc+channels[verb]["msg_color"]+HIW"【"+me->query("title")+HIW"】"+ZJURL("cmds:look "+me->query("id"))+ZJSIZE(25)+who+NOR;
		}else
		{
		who = descc+channels[verb]["msg_color"]+ZJURL("cmds:look "+me->query("id"))+ZJSIZE(25)+who+NOR;
		}
		
		if (who[0] == 27) who = NOR + who;
		who += channels[verb]["msg_color"];
	}
	// Ok, now send the message to those people listening us.
	obs = all_interactive();
	if (stringp(channels[verb]["only"]))
		obs = filter_array(obs, (: filter_listener :),
				   channels[verb]["only"], me);

	if (! arg || arg == "" || arg == " ") arg = "...";

	if (emote)
	{
		string localmsg = arg;
		string ecol = channels[verb]["msg_color"];
		if (emote == 2 && ! arg)
			arg = me->name(channels[verb]["name_raw"]) +
			      ecol + "[" + me->query("id") + "@" +
			      INTERMUD_MUD_NAME + "]" + arg + "\n";
		if (! stringp(arg)) return 0;

		if (channels[verb]["msg_emote"])
			localmsg = remove_addresses(arg, 0); // 98-1-22 14:30

		if (channels[verb]["omit_address"])
			localmsg = remove_addresses(arg, 1);
		else
		if (channels[verb]["intermud_emote"])
			localmsg = remove_addresses(arg, 0);

		if (! stringp(localmsg)) return 0;
		msg = sprintf(channels[verb]["msg_emote"],
			      sprintf(localmsg, ecol, ecol, ecol));
	} else
		msg = sprintf(channels[verb]["msg_speak"], who, arg);

	if (channels[verb]["anonymous"] && userp(me))
	{
		do_channel(this_object(), "sys",
			   sprintf("%s(%s)正在向%s频道发出信息。",
			      me->query("name"), me->query("id"), verb));
		SPECIAL_NPC->receive_report(me, verb);
	}

	message("channel:" + ((verb == "ultra") ? "chat" : verb), msg, obs);
	channel_log(msg, verb, me);

	if (! undefinedp(channels[verb]["intermud"]) && me->is_character())
	{
		channels[verb]["intermud"]->send_msg(channels[verb]["intermud_channel"],
						     me->query("id"), me->name(1),
						     imsg ? imsg : arg, emote,
						     channels[verb]["filter"]);
	}

	return 1;
}

int filter_listener(object ppl, string only, object me)
{
	// Don't bother those in the login limbo.
	if (! environment(ppl)) return 0;

	switch (only)
	{
	case "arch":
		return (wiz_level(ppl) >= 4);

	case "wiz":
		return (wiz_level(ppl) >= 3);

	case "family":
		return (ppl->query("family/family_name") == me->query("family/family_name"));

	case "party":
		return (ppl->query("banghui/name") == me->query("banghui/name"));

	case "league":
		return (ppl->query("league/league_name") == me->query("league/league_name"));
	}

	return 1;
}

string remove_addresses(string msg, int all)
{
	int i;
	mixed tmp;
	string pattern;

	if (! stringp(msg)) return msg;
	if (all)
		pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
	else
		pattern = "[(][A-Za-z]+@" + INTERMUD_MUD_NAME + "[)]";

	tmp = reg_assoc(msg, ({ pattern }), ({ 1 }));

	if (! arrayp(tmp)) return msg;
	msg = "";
	for (i = 0; i < sizeof(tmp[0]); i++)
		if (tmp[1][i] == 0) msg += tmp[0][i];
	return msg;
}

//fuck array 全部使用小写英语
string *fuck = ({
      	"fuck","你娘","你妈",
        "母狗","婊子","鸡婆","妓女",
      	"屁眼","智障","鸡巴","阴道",
      	"死妈","孤儿","废物","操你妈",
      "孙子","狗生","脑残","你妈死了",
      "强奸","弱智","艹","傻逼","狗比",
      "狗逼","妓院",
	  "嫖娼","嫖","八格牙路","日本","岛国","黄片","A片","色",
	});

//下面这两个是给Admin Call 的 以便随时更新 再做文件更新的准备

int add_fuck(string arg)
{
	if(!arg) return 0;
	fuck += ({arg});
	return 1;
}

int del_fuck(string arg)
{
	if(!arg) return 0;
	fuck -= ({arg});
	return 1;
}

//过滤
string channel_filter(object me,string input)
{
	string output;
	int i,flag=0;
	
	output = input;
	
        i = strlen(input);
        while (i--) {
                if (input[i] >= 'A' && input[i] <='Z') {input[i]+=32; continue;}
                if (input[i] >= 'a' && input[i] <='z') continue;
                if (input[i] > 128)
                {
                	if(input[i]==163 && !undefinedp(input[i+1]) )
                	{
                		if ( input[i+1]>=193 && input[i+1]<=218 )
                		{
                			input[i+1] = (int)input[i+1]-96;
                			input = input[0..i-1] + input[i+1..<1];
                		}                		
                		if ( input[i+1]>=225 && input[i+1]<=250 )
                		{
                			input[i+1] = (int)input[i+1]-(96+32);
                			input = input[0..i-1] + input[i+1..<1];
                		}                		                		
                	}
                	continue;
                }
                input = input[0..i-1] + input[i+1..<1];
        }
        
	for(i=0;i<sizeof(fuck);i++){
		if (strsrch(input, fuck[i]) >= 0)
		{
			flag=1;
			//break;
			input = replace_string(input,fuck[i],"×××");
		}
	}
	if(flag)
	{
		output = input;
		tell_object(me,BYEL+HIR"聊天中含有不文明词语，被系统过滤，并记录在案。"NOR"\n");
		me->add_temp("bad_word",1);
		//		
	}
	return output;
}

void shoutmsg(string arg)
{
	if(!arg) return;
	message("shout", HIC "【通告】" + arg + "在公开频道讲话中含有不雅言词，暂时关闭所有交谈频道，并记录在案，等候处理。"NOR"\n",users());
}
