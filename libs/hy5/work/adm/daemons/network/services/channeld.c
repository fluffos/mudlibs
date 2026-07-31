// channeld.c 
// 3/23/96 modified by cleansword to prevent chat flooding
// 04/18/96 modified by Marz to provide specific channel blocking 

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit F_DBASE;

mapping channels = ([
	"sys":	([	"msg_speak": HIR "【系统】%s：%s\n" NOR, 
				"wiz_only": 1 ]),
	"wiz":	([	"msg_speak": HIW "【巫师】%s：%s\n" NOR,
				"msg_emote": HIW "【巫师】%s" NOR,
				"wiz_only": 1
			]),
	"chat":	([	"msg_speak": HIC "【闲聊】%s：%s\n" NOR,
				"msg_emote": HIC "【闲聊】%s" NOR,
			 ]),
	"rumor":([	"msg_speak": HIM "【谣言】%s：%s\n" NOR,
				"msg_emote": HIM "【谣言】%s" NOR,
				"anonymous": "某人"
			]),
	"music":([	"msg_speak": HIY "【歌舞】%s唱著：%s\n" NOR,
				"msg_emote": HIY "【歌舞】%s" NOR
             ]),
			
	"cctx":([	"msg_speak": HIG "【驰骋天下】%s %s\n" NOR,
				"msg_emote": HIG "【驰骋天下】%s" NOR,
			]),
	// 97-10-18 this channel add for display debug message by ken@XAJH
	
	"debug":([	"msg_speak": HIW "【调试】%s：%s\n" NOR,
			"msg_emote": HIY "【调试】%s" NOR,
			"wiz_only": 1,
		]),
	"gwiz":	([	"msg_speak": GRN "【网际巫师】%s：%s\n" NOR,
			"msg_emote": GRN "【网际巫师】%s" NOR,
			"wiz_only": 1,
			"intermud": GWIZ,
			"intermud_emote": 1,
			"channel": "CREATOR",
			"msg_color": GRN,
			"filter": 1,
			"omit_address": 0, 
		]),
	"es":	([	"msg_speak": HIG "【泥谈】%s：%s\n" NOR,
			"msg_emote": HIG "【泥谈】%s" NOR,
			"msg_color": HIG,
//			"es_only": 1,
			"intermud": GCHANNEL,
			"intermud_emote": 1,
			"channel": "es",
			"filter": 1,
			"omit_address": 0, 
		]),
]);

int block_rumor = 0;
int block_chat = 0;
int block_cctx = 0;

void create()
{
	seteuid(getuid());	// This is required to pass intermud access check.
	set("channel_id", "顺风耳");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
	object *ob;
	string *tuned_ch, who;
	int rumor;
//*********************************************************************************
	if( !userp(me) ) {
		if( sprintf("/%O", previous_object()) == GCHANNEL
			&& channels[verb]["intermud"] != GCHANNEL ) {

			log_file("channel",
				sprintf("\nfrom: %O \n"
					"who: %s\n"
					"channel: %s\n"
					"message: %s\n"
					"error: remote host want use gchannel send local channel message.\n"
					"time: %s\n",
					previous_object(),
					me->query("channel_id"),
					verb, arg, ctime(time()) ) );
			return 1;
			}
	}
//**********************************************************************************
	// check if one can write to channels
	if ((int)me->query("chblk_on") && !wizardp(me)) return 0;
//		return notify_fail("你的频道被关闭了！\n");

	if ((int)me->query("chblk_on") && wizardp(me))
	{
	//only block a wiz's rumor and chat...
		me->set("chblk_rumor", 1);
		me->set("chblk_chat", 1);
		me->set("chblk_chat", 1);
		me->set("chblk_es", 1);
		me->set("chnlk_gwiz",1);
	}
	if ((int)me->query("chblk_rumor") && (verb == "rumor"||verb == "rumor*") )
		return notify_fail("ｏｏｐｓ！你的谣言频道被关闭了！\n");
	if ((int)me->query("chblk_chat") && (verb == "chat"||verb == "chat*") )
		return notify_fail("ｏｏｐｓ！你的聊天频道被关闭了！\n");
	if ((int)me->query("chblk_cctx") && (verb == "cctx"||verb == "cctx*") )
		return notify_fail("ｏｏｐｓ！你的驰骋天下频道被关闭了！\n");
 	// check if rumor or chat is blocked		
	if ((int)block_rumor && (verb == "rumor"||verb == "rumor*") )
		return notify_fail("遥言频道被关闭了！\n");
	if ((int)block_chat && (verb == "chat"||verb == "chat*") )
		return notify_fail("聊天频道被关闭了！\n");
	if ((int)block_chat && (verb == "chat"||verb == "chat*") )
		return notify_fail("驰骋天下频道被关闭了！\n");


	//added by jungu

	if ((int)block_chat && (verb == "music"||verb == "music*") )
		return notify_fail("歌舞频道被关闭了！\n");   
	if ( verb == "music*" ) {
		if (!stringp(arg)) return 0 ;
		if ( (int) strsrch ( arg , "sing" , 1 ) == -1 )	return 0 ;    
	}
	if ( verb == "rumor*" ) rumor=1;
		
	//music ok
	// Check if this is a channel emote.
	
	if( verb[sizeof(verb)-1] == '*' ) {
		emote = 1;
		verb = verb[0..<2];
	}
	if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

	if( !mapp(channels) || undefinedp(channels[verb]) )
		return 0;

	if( userp(me) ) {
		if(channels[verb]["wiz_only"] && !wizardp(me) )
			return 0;

		if( arg==(string)me->query_temp("last_channel_msg") )
			return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");

		if( userp(me) ) 
			me->set_temp("last_channel_msg", arg);

		// If we speaks something in this channel, then must tune it in.
		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ verb }) );
		else if( member_array(verb, tuned_ch)==-1 )
			me->set("channels", tuned_ch + ({ verb }) );

		// Support of channel emote
		if( emote && !channels[verb]["intermud_emote"]) {
			string vb, emote_arg;
			if( nullp(arg) ) return 0;
			if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
				vb = arg;
				emote_arg = "";
			}
		if( channels[verb]["anonymous"] )
                           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1,1);
                else {
                   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
			if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
                        "/adm/daemons/network/services/gemote_q"->
                        send_msg(channels[verb]["channel"], me,
                        vb, id, site, channels[verb]["filter"]);
                        return 1;
                      }
                   }
                }

			if( !arg ) return 0;
		}
	}

	// player broadcasting need consume jing
	if( userp(me) && !wizardp(me) && verb == "rumor" )
		if(me->query("jing") > 50) me->add("jing", 0-random(36));
			else
		return notify_fail("你已经没力气散播谣言了！\n");

	// Make the identity of speaker.

	if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me))
	        do_channel( this_object(), "sys", sprintf("造谣者：%s。", me->name()));
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) )
		who = me->query("name") + "(" + capitalize(me->query("id")) + ")";

	// Ok, now send the message to those people listening us.

	ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
	if( !arg || arg == "" || arg == " " ) arg = "...";

	if( emote ) {
		// Support of old behavier of intermud emote.
//		if( channels[verb]["intermud_emote"] ) arg = who + " " + arg;
		if (!stringp(arg)) arg = "";
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_emote"], arg ), ob );
	} else
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_speak"], who, arg ), ob );

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}
	
	if( !undefinedp(channels[verb]["intermud"])
	&&	base_name(me) != channels[verb]["intermud"] )
		channels[verb]["intermud"]->send_msg(
			channels[verb]["channel"], me->query("id"), me->name(1), arg, 0,
			channels[verb]["filter"] );

//	if( userp(me) ) 
//		me->set_temp("last_channel_msg", arg);

	return 1;
}

int filter_listener(object ppl, mapping ch)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;
	
	if( ch["wiz_only"] ) return wizardp(ppl);
	return 1;
}

void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}
void add_relay_channel( object ob , string channel)
{
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}
int set_block(string channel, int d)
{
//	write("debug:  "+channel+" d="+sprintf("%d\n", d)); 
	if (channel == "rumor") block_rumor = d;
	if (channel == "chat") block_chat = d;
	if (channel == "cctx") block_cctx = d;
	return 1;
}

