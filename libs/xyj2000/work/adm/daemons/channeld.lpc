// cracked by vikee 2/09/2002   vikee@263.net
// channeld.c
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for
//          intermud emote.

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

// mon 6/16/99
int intermud_open=1;
void open_intermud();
void close_intermud();
int query_inter() {return intermud_open;}

// mon 8/5/99
int TOTAL=4000;
mapping msg_buf=([]);
int check_string(string arg, string who, int emote_mode);
string query_buffer() {return sprintf("%O\n",msg_buf);}

mapping channels = ([
	"sys":	([	"msg_speak": HIG "【系统】%s：%s\n" NOR, "wiz_only": 1 ]),
	"wiz":	([	"msg_speak": HIY "【巫师】%s：%s\n" NOR,
				"msg_emote": HIY "【巫师】%s\n" NOR,
				"wiz_only": 1
			]),
	"gwiz":	([	"msg_speak": GRN "【网际巫师】%s：%s\n" NOR,
				"msg_emote": GRN "【网际巫师】%s\n" NOR,
				"wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
				"filter": 1,
				"intermud_emote": 1 ]),
	"xyj":	([	"msg_speak": HIR "【西游记】%s：%s\n" NOR,
				"msg_emote": HIR "【西游记】%s\n" NOR,
				"intermud": GCHANNEL, "channel": "xyj",
				"filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
	"xx":	([	"msg_speak": HIR "【西游】%s：%s\n" NOR,
				"msg_emote": HIR "【西游】%s\n" NOR,
				"intermud": GCHANNEL, "channel": "xx",
				"filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
	"es":	([	"msg_speak": HIR "【潭际闲聊】%s：%s\n" NOR,
				"msg_emote": HIR "【潭际闲聊】%s\n" NOR,
				"intermud": GCHANNEL, "channel": "es",
				"filter": 1 ]), //keep the channel name
				//as "es" to be compatible with other
				//ES2 type muds.
        "sldh": ([      "msg_speak": HIC "【水陆大会】%s：%s\n" NOR,
                                "msg_emote": HIC "【水陆大会】%s\n" NOR,
                         ]),

	"chat":	([	"msg_speak": HIC "【闲聊】%s：%s\n" NOR,
				"msg_emote": HIC "【闲聊】%s\n" NOR,
			 ]),
	"rumor":([	"msg_speak": HIM "【谣言】%s：%s\n" NOR,
				"msg_emote": HIM "【谣言】%s\n" NOR,
				"anonymous": "某人"
			]),
]);

void create()
{
	seteuid(getuid());	// This is required to pass intermud access check.
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote,
	int allow_chat)
{
	object *ob;
	string *tuned_ch, who, arg1;
	int time,count,count1,last_chat,len;

	// Check if this is a channel emote.
        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
		emote = 1;
		verb = verb[0..<2];
	}
	
	// mon 10/29/98
	// ignore too long messages to reduce flooding.
	if(arg && strlen(arg)>240) return 0;

	if( !mapp(channels) || undefinedp(channels[verb]) )
		return 0;

	if( userp(me) && !allow_chat ) {
		if(channels[verb]["wiz_only"] && !wizardp(me) )
			return 0;

                //temporary block chat flooding.
		time=time();
		if(me->query("channel/chat_block") &&
		  (time-me->query("channel/chat_block"))<0 )
		   return notify_fail("你的交谈频道被暂时关闭了。\n");
              
	        count=me->query("channel/chat_count");
		// if the channel arg contains too many lines,
		// then count more than once. -- mon 8/16/98
		count1=sizeof(explode(" "+arg,"\n"))/3+1;
		// if arg too long, also counts more.
		count1+=sizeof(arg)/200;
		count+=count1;
		last_chat=me->query("channel/last_chat");
		if (count>2) {
		  count=0;
		  me->set("channel/last_chat",time);
		  if (time==last_chat || count1>2) {
		    me->set("channel/chat_block",time+180);
		    return notify_fail("因为一次讲话太多，你的交谈频道被暂时关闭了。\n");
		  }
	        }
		me->set("channel/chat_count",count);

		if( arg==(string)me->query_temp("last_channel_msg") )
			return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");

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
			   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
                else {
		   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
			int age=me->query("mud_age");
			// prevent login  newbie to flood channels.
			if(!wizardp(me)) {
			    if(age<3600) return notify_fail(
				    "你现在还不能使用这个频道。\n");
			    else if(age<86400) {
				if((int)me->query("sen")<30) return 
				    notify_fail
					("你现在精神不足，不能使用这个频道。\n");
				me->add("sen",-5);
			    }
			}

			// check whether repeated messages. -- mon 8/5/99
		        if(!check_string(vb+":"+id+"@"+site, 0, 1)) 
			    return 0;

			// mon 6/16/99
			if(!intermud_open) return 1;

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

	// Make the identity of speaker.

	if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me)) {
		    if((int)me->query("sen")<50) return
			notify_fail("你已经没有精神散布谣言了。\n");
		    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
		    sprintf("谣言：%s(%s)。", me->name(),me->query("id")));
		}
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
		who = me->query("name");
		if(me->query("id")) 
		  who=who+"(" + capitalize(me->query("id")) + ")";
             }

	// Ok, now send the message to those people listening us.

	ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
	if( !arg ) arg = "．．．";

	// check whether repeated messages. -- mon 8/5/99
	if( !undefinedp(channels[verb]["intermud"])) {
//          do_channel( this_object(), "sys", 
//              sprintf("%s:%d", who,emote?1:0));
	    if(!check_string(arg, who, 0)) return 0;
	    //if(!check_string(arg, who, emote?1:0)) return 0;
	}

	len=strlen(arg);
	while(len>1 && arg[len-1]=='\n')
	    arg=arg[0..((len--)-2)];
	//remove excessive return at the end. by mon 9/20/97

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

	if( emote ) {
		// Support of old behavier of intermud emote.
		if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;
	}

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}
	
	if( !undefinedp(channels[verb]["intermud"])
	&&	base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
	    int age=me->query("mud_age");

            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

	    // prevent login  newbie to flood channels.
	    if(!wizardp(me)) {
	      if(age<3600) return notify_fail(
		    "你现在还不能使用这个频道。\n");
	      else if(age<86400) {
		if((int)me->query("sen")<30) return 
		    notify_fail
			("你现在精神不足，不能使用这个频道。\n");
		me->add("sen",-5);
	      }
	    }
	    // mon 6/16/99
	    if(!intermud_open) return 1;
          }
	  channels[verb]["intermud"]->send_msg(
		channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

	if( emote ) {
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_emote"], arg1 ), ob );
	} else
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

	if( userp(me) ) {
		me->set_temp("last_channel_msg", arg);
	        //log_file("channel",me->query("id")+":"+arg+"\n");
	}
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

void open_intermud()
{
    intermud_open=1;
}

void close_intermud()
{
    intermud_open=0;
    remove_call_out("open_intermud");
    call_out("open_intermud", 36000);
}

// mon 8/5/99
int check_one_string(string str, string site)
{
    int first, last;

    if(!msg_buf || !sizeof(msg_buf) || !site) return 1;
    if(undefinedp(msg_buf[site]) || !sizeof(msg_buf[site])) return 1;

    first=strsrch(msg_buf[site], str);
    last=strsrch(msg_buf[site], str, -1);

    if(first>-1 && last>-1 && first!=last) {
	// the same sentence at least appeared twice.
//        do_channel( this_object(), "sys", 
//            sprintf("Repeated msg from %s:%s.", site, str));
	return 0;
    }

    return 1;
}

int check_string(string arg, string who, int emote_mode)
{
    int len, k;
    string str, site;

    arg=replace_string(arg,"\n","");
    arg=replace_string(arg,"|","");
    
    notify_fail("请不要在潭际频道发送重复信息，谢谢合作。\n");

    if(!who || sscanf(who, "%*s@%s)", site)!=2 || !sizeof(site)) {
	site="local_host";
    } else { // for incoming messages, remove one "who" part.
        arg=replace_string(arg,who,"",1);
        site=lower_case(site);
    }

    len=sizeof(arg);
    if(len<2) return 0;

    if(len<5 || emote_mode) {
	if(!check_one_string(arg, site)) return 0;
    } else {
	k=len/2;
	if(k>20) k=20;
	else if(k<4) k=4;
	
	switch(random(3)) {
	    case 0:
		str=arg[0..k-1]; // first 1/3
		if(!check_one_string(str, site)) return 0;
		break;
	    case 1:
		str=arg[(len-k+1)/2..(len+k-1)/2]; // middle 1/3
		if(!check_one_string(str, site)) return 0;
		break;
	    case 2:
		str=arg[(len-k)..(len-1)]; // last 1/3
		if(!check_one_string(str, site)) return 0;
		break;
	}
    }

    // ok, this is a new message. add to buffer.
    if(len<=80 || emote_mode) {
        str=arg;
    } else {
	switch (random(3)) {
	    case 0: 
		str=arg[0..79]; break;
	    case 1: 
		str=arg[(len-79)/2..(len+79)/2]; break;
	    case 2:
		str=arg[(len-80)..(len-1)]; break;
	}
    }
    
//    do_channel( this_object(), "sys", 
//        sprintf("%s:%s", who,str));
    
    if(undefinedp(msg_buf[site])) {
	msg_buf[site]=str;
    } else {
	while(sizeof(msg_buf[site])>TOTAL) {
	    if((k=strsrch(msg_buf[site],"|"))>-1) {
		msg_buf[site]=msg_buf[site][k+1..];
	    } else break;
	}
	msg_buf[site]+="|"+str;
    }
	
    return 1;
}


