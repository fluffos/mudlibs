// channeld.c 
// 03/23/96 modified by cleansword to prevent chat flooding
// 04/18/96 modified by Marz to provide specific channel blocking 
// 11/11/02 modified by mudy 考虑了名字有颜色的情况
// 01/04/04 modified by chui 保留了监听聊天的功能
// 21/09/06 modified by iszt 增加1/8的几率显示出真名，另1/8几率另一条谣言显示谁在造谣，grin

#include <ansi.h>
#include <net/dns.h>
inherit F_DBASE;
int is_logger(object ob);

mapping channels = ([
        "sys":  ([      "msg_speak": HIR "【系统】%s"+HIR"：%s\n" NOR,
                        "wiz_only": 1,
                        "prefix": HIR,
                ]),
        "wiz":  ([      "msg_speak": HIY "【巫师】%s"+HIY"：%s\n" NOR,
                        "msg_emote": HIY "【巫师】%s\n\r" NOR,
                        "wiz_only": 1,
                        "prefix": HIY,
                ]),
/**
        "es":   ([      "msg_speak": HIG "【潭际闲聊】%s：%s\n" NOR,
                                "msg_emote": HIG "【潭际闲聊】%s\n" NOR,
                                "intermud": GCHANNEL, "channel": "es",
                                                                "prefix": HIW,
                                "filter": 1 ]), //keep the channel name
                                //as "es" to be compatible with other
                                //ES2 type muds.
**/
        "hslj": ([      "msg_speak": HIR "【华山论剑】%s"+HIR"：%s\n" NOR,
                        "msg_emote": HIR "【华山论剑】%s\n\r" NOR,
                        "prefix": HIR,
                ]),                     
        "chat": ([      "msg_speak": HIC "【闲聊】%s"+HIC"：%s\n" NOR,
                        "msg_emote": HIC "【闲聊】%s\n\r" NOR,
                        "prefix": HIC,
                ]),
        "rumor":([      "msg_speak": HIM "【谣言】%s"+HIM"：%s\n" NOR,
                        "msg_emote": HIM "【谣言】%s\n\r" NOR,
                        "anonymous": "某人",
                        "prefix": HIM,
                ]),
        "act":  ([      "msg_speak": HIM "【动作】%s"+HIM" %s \n" NOR,
                        "prefix": HIM,
                ]),
        "mp":   ([      "msg_speak": GRN "【%s】%s"+GRN"：%s\n" NOR,
                        "msg_emote": GRN "【%s】%s\n\r" NOR,                   
                        "prefix": GRN,
                ]), 
         "ct":   ([      "msg_speak": HIW "【夫妻闲聊】%s"+HIW"：%s\n" NOR,
                         "msg_emote": HIW "【夫妻闲聊】%s\n\r" NOR,
                         "prefix": HIW,

                ]),
        "tt":   ([      "msg_speak": HIG "【队伍】%s"+HIG"：%s\n" NOR,
                        "msg_emote": HIG "【队伍】%s\n\r" NOR,
                        "prefix": HIG,

                ]),

        "pm":  ([      "msg_speak": HIY "【拍卖】%s"+HIY"：%s\n" NOR,
                       "msg_emote": HIY "【拍卖】%s\n\r" NOR,
                       "prefix": HIY,
                ]),
        "baowei": ([      "msg_speak": HIC "【保卫】%s"+HIC"：%s\n" NOR,
                        "msg_emote": HIC "【保卫】%s\n\r" NOR,
                        "prefix": HIC,
                ]),
        "new": ([      "msg_speak": HIG "【新手】%s"+HIG"：%s\n" NOR,
                        "msg_emote": HIG "【新手】%s\n\r" NOR,
                        "prefix": HIG,
                ]),
/**                     
        "vote":([       "msg_speak": HIM "【表决】%s %s\n" NOR,
                        "msg_emote": HIM "【表决】%s" NOR,
                        "vote_only": 1
                ]),
**/                     
]);

int block_rumor = 0;
int block_chat = 0;
int block_mp = 0;

void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *ob=({ }),lover;
        string *tuned_ch,lover_name, who,menpai;
        string temp_name, emotecmd;
        object *team;

        // check if one can write to channels
        if ((int)me->query("chblk_on") && !wizardp(me)) return 0;
                //return notify_fail("你的频道被关闭了！\n");

        if ((int)me->query("chblk_on") && wizardp(me))
        {
        //only block a wiz's rumor and chat...
                me->set("chblk_rumor", 1);
                me->set("chblk_chat", 1);
        }
        if (undefinedp(me->query("family")) && (verb=="mp"||verb=="mp*"))
                return notify_fail("你还没有加入任何门派呢！\n");
        if(verb == "mp" || verb == "mp*" )  
            menpai=me->query("family/family_name");
             
         if (verb=="hslj")
          {
            if( userp(me) && !wizardp(me))
                //return notify_fail("玩家不能使用！\n"); 
             {}
          }
                if (verb=="baowei*")
          {
            if( userp(me) && !wizardp(me) )
             return notify_fail("玩家不能使用！\n");
          }
        if (verb=="ct"||verb=="ct*")
          {
           if (undefinedp(me->query("couple")) ||  undefinedp(lover_name=me->query("couple/couple_id")) ) 
                return notify_fail("你现在还没有伴侣，要跟谁说悄悄话呢？！\n");
          if(!(lover=find_player(lover_name)))
                return notify_fail("你的伴侣目前不在线上。\n");
          }    
                        
        if ((int)me->query("chblk_rumor") && (verb == "rumor"||verb == "rumor*") )
                return notify_fail("ｏｏｐｓ！你的谣言频道被关闭了！\n");
        if ((int)me->query("chblk_chat") && (verb == "chat"||verb == "chat*") )
                return notify_fail("ｏｏｐｓ！你的聊天频道被关闭了！\n");
        // check if rumor or chat is blocked            
        if ((int)block_rumor && (verb == "rumor"||verb == "rumor*") )
                return notify_fail("遥言频道被关闭了！\n");
        if ((int)block_chat && (verb == "chat"||verb == "chat*") )
                return notify_fail("聊天频道被关闭了！\n");
        if (!arrayp(team = me->query_team()) && (verb == "tt" || verb == "tt*") )
                return notify_fail("你现在没有加入任何队伍！\n");
                //enable logger disable now

                if (is_logger(me))
                        set("logger",me);
        // Check if this is a channel emote.
        if( verb[sizeof(verb)-1] == '*' ) {
                emote = 1;
                verb = verb[0..<2];
        }
        emotecmd = arg;
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;

        if( userp(me) ) {
                if (channels[verb]["wiz_only"] && !wizardp(me))
                        return 0;

                if( arg == (string)me->query_temp("last_channel_msg") )
                                //return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");
                {
                        write("用交谈频道说话请不要重复相同的讯息。\n");
                        return 1;
                }

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

                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
                                vb = arg;
                                emote_arg = "";
                        }
                        if (me->query_temp("apply/name"))
                                temp_name = me->query_temp("apply/name")[0];
                        else
                                temp_name = me->query("name");
                        if ( verb == "rumor" && userp(me) && ( random(8) > 0 || wizardp(me) ))
                                                //if (random(10) < 5)
                                if (me->query_temp("apply/name"))
                                        me->set_temp("apply/name", ({"某人"}));
                                else
                                        me->set("name","某人");
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
                        if (me->query_temp("apply/name"))
                                me->set_temp("apply/name",({temp_name}));
                        else
                                me->set("name",temp_name);
                                                //if( !arg ) return 0;
                        if (!arg)
                        {
                                write("什么？\n");
                                return 1;
                        }
                }
        }
        else {
                // Support of channel emote
                if( emote && !channels[verb]["intermud_emote"]) {
                        string vb, emote_arg;

                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
                                vb = arg;
                                emote_arg = "";
                        }
                        if (me->query_temp("apply/name"))
                                temp_name = me->query_temp("apply/name")[0];
                        else
                                temp_name = me->query("name");
                        if ( verb == "rumor" && userp(me) && ( random(8) > 0 || wizardp(me) ) )
                                if (random(10) < 5)
                                                //if (random(10) < 5)
                                        me->set_temp("apply/name", ({"某人"}));
                                else
                                        me->set("name","某人");
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
                        if (me->query_temp("apply/name"))
                                me->set_temp("apply/name",({temp_name}));
                        else
                                me->set("name",temp_name);
                        if( !arg ) return 0;
                }
        }

        // Make the identity of speaker.

        if( channels[verb]["anonymous"] ) {
                if(random(50) > 0 || wizardp(me) || !userp(me))
                {
                        who = channels[verb]["anonymous"];
                }
                else
                        who = me->query("name");
                if (userp(me))
                do_channel( this_object(), "sys", sprintf("谣言：%s(%s)。", me->query("name"),me->query("id")));
                if (random(50) == 0 && userp(me) && !wizardp(me))
                        message("channel:rumor", HIM"【谣言】某人：我看到了！！就是"+me->query("name")+"("+capitalize(me->query("id"))+")"+"造的谣！！\n"NOR, users());


        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) )
            if (!me->query_temp("apply/name"))
                who = me->query("name") + NOR""+HIG"(" + capitalize(me->query("id")) + ")"NOR;
            else   who = me->query_temp("apply/name")[0] +NOR""+ HIG"(" + capitalize(me->query_temp("apply/id")[0]) + ")"NOR;

        // Ok, now send the message to those people listening us.
        if(verb=="mp" || verb=="mp*")
                ob = filter_array( users(), "filter_mp",this_object(),menpai); 
        else if(verb=="ct"||verb=="ct*")
        ob = ({ lover,me });
        else if(verb=="tt"||verb=="tt*")
                ob = team;
        else 
                ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
        if( !arg || arg == "" || arg == " " ) arg = "...";
        if( !stringp(arg) ) arg = "";
        arg = replace_string(arg, NOR, channels[verb]["prefix"]) + NOR;

        if( emote ) {
             // Support of old behavier of intermud emote.
             if( channels[verb]["intermud_emote"] ) arg = who + " " + arg;

                if (!stringp(arg)) arg = "";
                if(verb=="mp")
                {
                        message( "channel:" + verb,
                                sprintf( channels[verb]["msg_emote"], menpai,arg ), filter_array(ob, "filter_emotecmd", this_object(), 0));
                        message( "channel:" + verb,
                                sprintf( channels[verb]["msg_emote"], menpai,arg + "(" + emotecmd + ")"), filter_array(ob, "filter_emotecmd", this_object(), 1));
                }
                else if (!(verb == "act"))
                {
                        if ( verb != "rumor" )
                        {
                                message( "channel:" + verb,
                                        sprintf( channels[verb]["msg_emote"], arg ), filter_array(ob, "filter_emotecmd", this_object(), 0));
                                message( "channel:" + verb,
                                        sprintf( channels[verb]["msg_emote"], arg + "(" + emotecmd + ")"), filter_array(ob, "filter_emotecmd", this_object(), 1));
                        }else   message( "channel:" + verb,
                                        sprintf( channels[verb]["msg_emote"], arg ), ob);
                }  
        } else {
                if(verb=="mp")
                        message( "channel:" + verb,
                                sprintf( channels[verb]["msg_speak"], menpai,who,arg ), ob );
                else 
                        message( "channel:" + verb,
                                sprintf( channels[verb]["msg_speak"], who, arg ), ob );
        }

        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
                        {
                                                if (emote) 
                                                        channels[verb]["extra_listener"]->set("isemote",1);
                                                else
                                                        channels[verb]["extra_listener"]->delete("isemote");
                        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
                        }
        }
        
        if( !undefinedp(channels[verb]["intermud"])
        &&      base_name(me) != channels[verb]["intermud"] )
                channels[verb]["intermud"]->send_msg(
                        channels[verb]["channel"], me->query("id"), me->name(1), arg, 0,
                        channels[verb]["filter"] );
        if (verb == "rumor" && random(14) == 0 && userp(me) && !wizardp(me))
                message("channel:rumor", HIM"【谣言】某人：我看到了！！就是"+me->query("name")+HIM"("+capitalize(me->query("id"))+")造的谣！！\n"NOR, users());

        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;
        
                if( ch["wiz_only"] ) return (is_logger(ppl) || wizardp(ppl));
                //if( ch["wiz_only"] ) return wizardp(ppl);
        return 1;
}

int filter_mp(object ppl, string mp)
{
        if( !environment(ppl) ) return 0;
                if (is_logger(ppl)) return 1;
        if( undefinedp(ppl->query("family")) ) return 0;
        if( ppl->query("family/family_name" ) != mp )return 0;
        return 1;          
}

int filter_emotecmd(object ppl, int type)
{
        if( !environment(ppl) ) return 0;
                if( ppl->query("env/learn_emote")==type ) return 1;
                return 0;
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

int set_block(string channel, int d)
{
//      write("debug:  "+channel+" d="+sprintf("%d\n", d)); 
        if (channel == "rumor") block_rumor = d;
        if (channel == "chat") block_chat = d;
        return 1;
}

int is_logger(object ob)
{
        if (wizardp(ob) && ob->query("is_logger1")) return 1;
        return 0;
}

