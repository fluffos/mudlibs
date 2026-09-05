// channeld.c 
// 03/23/96 modified by cleansword to prevent chat flooding
// 04/18/96 modified by Marz to provide specific channel blocking 
// 11/11/02 modified by mudy 考虑了名字有颜色的情况
// 01/04/04 modified by chui 保留了监听聊天的功能
// 2006-09-21 modified by iszt 增加1/8的几率显示出真名，另1/8几率另一条谣言显示谁在造谣，grin
// 2007-01-17 modified by iszt 优化代码，显示谁在造谣加上rumoring的影响
// 2007-03-13 modified by iszt learn_emote改为任意非零值均可

#include <ansi.h>
#include <net/dns.h>
inherit F_DBASE;
int is_logger(object ob);

//频道hslj、dasong、baowei合并到rw频道
//频道pm合并到jy频道
//频道new合并到helpme频道
//废除频道act、ct、new、zongshi
//增加频道rw（任务）、jh（江湖）、bd（本地）、qy（区域）、jy（交易）
//增加标识符npc_only，指的是那些npc专用频道
//目前在用频道列表：
// sys wiz chat rw jh bd qy qq group rumor mp tt jy helpme
mapping channels = ([
        "sys":  ([      "msg_speak": HIR "【系统】%s"+HIR": %s\n" NOR,
                        "wiz_only": 1,
                        "prefix": HIR,
                ]),
        "sys_misc":  ([      "msg_speak": HIC "【杂项】%s"+HIC": %s\n" NOR,
                        "wiz_only": 1,
                        "prefix": HIC,
                ]),
        "wiz":  ([      "msg_speak": BBLU+HIW "【巫师】%s"+BBLU+HIW": %s\n" NOR,
                        "msg_emote": BBLU+HIW "【巫师】%s\n\r" NOR,
                        "wiz_only": 1,
                        "prefix": BBLU+HIW,
                ]),
        "xingmu": ([    "msg_speak": HBBLU+HIC "【醒目】%s"HBBLU+HIC+": %s\n" NOR,
                        "msg_emote": HBBLU+HIC "【醒目】%s\n\r" NOR,
                        "using_channel":"chat",
//                        "wiz_only": 1,
                        "prefix": HBBLU+HIC,
                ]),
        "hslj": ([      "msg_speak": HIY "【任务】%s"+HIY": %s\n" NOR,
                        "msg_emote": HIY "【任务】%s\n\r" NOR,
                        "using_channel":"rw",
                        "npc_only":1,
                        "prefix": HIY,
                ]),
        "dasong": ([    "msg_speak": HIY "【任务】%s"+HIY": %s\n" NOR,
                        "msg_emote": HIY "【任务】%s\n\r" NOR,
                        "using_channel":"rw",
                        "npc_only":1,
                        "prefix": HIY,
                ]),
        "baowei": ([    "msg_speak": HIY "【任务】%s"+HIY": %s\n" NOR,
                        "msg_emote": HIY "【任务】%s\n\r" NOR,
                        "using_channel":"rw",
                        "npc_only":1,
                        "prefix": HIC,
                ]),
        "rw": ([        "msg_speak": HIY "【任务】%s"+HIY": %s\n" NOR,
                        "msg_emote": HIY "【任务】%s\n\r" NOR,
                        "npc_only":1,
                        "prefix": HIY,
                ]),
        "jh": ([        "msg_speak": HIW "【江湖】%s"+HIW": %s\n" NOR,
                        "msg_emote": HIW "【江湖】%s\n\r" NOR,
                        "npc_only":1,
                        "prefix": HIW,
                ]),
        "bd": ([        "msg_speak": HBMAG+HIG "【本地】%s"+HBMAG+HIG": %s\n" NOR,
                        "msg_emote": HBMAG+HIG "【本地】%s\n\r" NOR,
                        "prefix": HBMAG+HIG,
                ]),
        "qy": ([        "msg_speak": HBMAG+HIC "【区域】%s"+HBMAG+HIC": %s\n" NOR,
                        "msg_emote": HBMAG+HIC "【区域】%s\n\r" NOR,
                        "prefix": HBMAG+HIC,
                ]),
        "qq": ([        "msg_speak": HIW "【北侠QQ群】%s"+HIW": %s\n" NOR,
                        "msg_emote": HIW "【北侠QQ群】%s\n\r" NOR,
                        "prefix": HIW,
                ]),
        "chat": ([      "msg_speak": HIC "【闲聊】%s"+HIC": %s\n" NOR,
                        "msg_emote": HIC "【闲聊】%s\n\r" NOR,
                        "prefix": HIC,
                ]),
/*        "zongshi": ([   "msg_speak": HIC "【闲聊】"+HIC"%s"+HIC": %s\n" NOR,
                        "msg_emote": HIC "【闲聊】" + HIC"%s\n\r" NOR,
                        "using_channel":"chat",
                        "prefix": HIC,
                ]),*/
        "group": ([   "msg_speak": HIG "【%s"+HIG+"】%s"+HIG+": %s\n" NOR,
                        "msg_emote": HIG "【%s"+HIG+"】%s\n\r" NOR,
                        "prefix": HIG,
                ]),
        "rumor":([      "msg_speak": HIM "【谣言】%s"+HIM": %s\n" NOR,
                        "msg_emote": HIM "【谣言】%s\n\r" NOR,
                        "anonymous": "某人",
                        "prefix": HIM,
                ]),
/*        "act":  ([      "msg_speak": HIM "【动作】%s"+HIM" %s \n" NOR,
                        "prefix": HIM,
                ]),*/
        "mp":   ([      "msg_speak": GRN "【%s】%s"+GRN": %s\n" NOR,
                        "msg_emote": GRN "【%s】%s\n\r" NOR,                    
                        "prefix": GRN,
                ]),
/*        "ct":   ([      "msg_speak": HIW "【夫妻闲聊】%s"+HIW": %s\n" NOR,
                         "msg_emote": HIW "【夫妻闲聊】%s\n\r" NOR,
                         "prefix": HIW,
                ]),*/
        "tt":   ([      "msg_speak": HBCYN+HIY "【队伍】%s"+HBCYN+HIY": %s\n" NOR,
                        "msg_emote": HBCYN+HIY "【队伍】%s\n\r" NOR,
                        "prefix": HBCYN+HIY,
                ]),
        "pm":   ([      "msg_speak": HBGRN+HIW "【交易】%s"+HBGRN+HIW": %s\n" NOR,
                        "msg_emote": HBGRN+HIW "【交易】%s\n\r" NOR,
                        "using_channel":"jy", 
                        "npc_only":1,
                        "prefix": HBGRN+HIC,
                ]),
        "jy":   ([      "msg_speak": HBGRN+HIW "【交易】%s"+HBGRN+HIW": %s\n" NOR,
                        "msg_emote": HBGRN+HIW "【交易】%s\n\r" NOR,
                        "prefix": HBGRN+HIW,
                ]),
/*        "new": ([       "msg_speak": HIW "【求助】%s"+HIW": %s\n" NOR,
                        "msg_emote": HIW "【求助】%s\n\r" NOR,
                        "using_channel":"helpme",
                        "prefix": HIW,
                ]),*/
        "helpme": ([      "msg_speak": HIW "【求助】%s"+HIW": %s\n" NOR,
                        "msg_emote": HIW "【求助】%s\n\r" NOR,
                        "prefix": HIW,
                ]),
/**                      
        "vote":([        "msg_speak": HIM "【表决】%s %s\n" NOR,
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

//对于非玩家，增加channel_environment属性用于存放那些没有环境的对象发布本地或者区域频道的时候拥有一个发布消息的环境
//emote输入参数对于非玩家，输入-1则不进行emote检查并且按照emote格式输出你输入的中文消息（这时候arg参数应该是输出的消息而不是emote
varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *ob=({ }),lover;
        string *tuned_ch,lover_name, who,menpai,liupai,chtemp,location;
        int i, region;
        string temp_name, emotecmd;
        object *team, env;
        object IM_D;
        

        // check if one can write to channels
        if ((int)me->query("chblk_on") && !wizardp(me))
          return 0;

        if(time() - me->query_temp("last_chat_record_time") < 2 && me->query_temp("chat_count") > 6)
        {
        //关闭两分钟
          me->set_temp("last_chat_record_time",time() + 120);
          return 0;
        }
        
        if ((int)me->query("chblk_on") && wizardp(me))
        {
        //only block a wiz's rumor and chat...
          me->set("chblk_rumor", 1);
          me->set("chblk_chat", 1);
        }
        
        if (undefinedp(me->query("family")) && (verb=="mp"||verb=="mp*"))
          return notify_fail("你还没有加入任何门派呢！\n");
         
//        if(verb == "qq" || verb == "qq*" )
//          IM_D = load_object("/adm/daemons/im_d");
	//IM_D = load_object("/adm/daemons/qqbotd");          
		
        if(verb == "mp" || verb == "mp*" )
          menpai = me->query("family/family_name");

/*        if (verb=="baowei*")
        {
                if( userp(me) && !wizardp(me) )
                        return notify_fail("玩家不能使用！\n");
        }*/
        if (verb=="xingmu" || verb=="xingmu*")
        {
                if( userp(me) && !wizardp(me) )
                        return notify_fail("玩家不能使用！\n");
        }
/*        if (verb=="zongshi" || verb=="zongshi*")
        {
          if (!me->query("grandmaster"))
            return notify_fail("你还没有达到武学宗师级别，无法这样说话！\n");
        }*/
        
        if (verb=="group" || verb=="group*")
        {
          if ( GROUP_D->group_member(me)<0 )
            return notify_fail("你没有加入任何帮派，不能用帮派频道说话。\n");
			if (GROUP_D->group_name(me)&&stringp(GROUP_D->group_name(me))&&GROUP_D->group_name(me)!="")
            liupai=GROUP_D->group_name(me);
			else
			liupai="帮派";
        }
        
/*        if (verb=="dasong" || verb=="dasong*")
        {
          if (!me->query("song/pro"))
            return notify_fail("你不是大宋官员或内侍，无法使用大宋频道。\n");
        }
        
        if (verb=="ct"||verb=="ct*")
        {
                if (undefinedp(me->query("couple")) || undefinedp(lover_name=me->query("couple/couple_id")) ) 
                        return notify_fail("你现在还没有伴侣，要跟谁说悄悄话呢？！\n");
                if(!(lover=find_player(lover_name)))
                        return notify_fail("你的伴侣目前不在线上。\n");
        }*/
                        
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
        if (stringp(arg) && strwidth(arg)>180 && living(me)&&!wizardp(me))
                return notify_fail("你说话也太罗嗦了点，公共频道不要刷屏。\n");
        
        //enable logger disable now
/*        
        if (me->query("grandmaster"))
      {
        if (verb == "chat")
          verb = "zongshi";
        if (verb == "chat*")
          verb = "zongshi*";
      }
*/
        if (is_logger(me))
                set("logger",me);
        // Check if this is a channel emote.
        if( verb[sizeof(verb)-1] == '*' )
        {
                emote = 1;
                verb = verb[0..<2];
        }
        
        emotecmd = arg;
        if (!stringp(arg) || arg == "" || arg == " ")
                arg = "...";

        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;

        if (userp(me) && me->query_temp("xinfang/from")) env = load_object(me->query_temp("xinfang/from"));
        else env=environment(me);
        if (!env) env=me;
        else
        {
            while(environment(env)) env=environment(env);
        }

        if( userp(me))
        {
                if (channels[verb]["wiz_only"] && !wizardp(me))
                  return 0;
                
                if (channels[verb]["npc_only"] && !wizardp(me))
                  return 0;
                
                if ( ( verb=="qy" || verb=="bd" ) && env==me )
                  return notify_fail("你目前所处环境使用不了区域或者本地广播。\n");
                  
                if ( verb=="qy" && !env->query_region() )
                  return notify_fail("区域频道不能在该区域广播。\n");

                if( arg == (string)me->query_temp("last_channel_msg") )
                  return notify_fail("使用公共频道说话请不要重复相同的讯息。\n");
                
                if( arg == (string)me->query_temp("old_channel_msg") )
                  return notify_fail("使用公共频道说话请不要重复相同的讯息。\n");
                me->set_temp("last_channel_msg", arg);

                // If we speaks something in this channel, then must tune it in.
                if (channels[verb]["using_channel"])
                  chtemp = channels[verb]["using_channel"];
                else
                  chtemp = verb;
                
                tuned_ch = me->query("channels");
                if ( !pointerp(tuned_ch) ||
                     member_array( chtemp, tuned_ch )==-1 )
                  return notify_fail("请先打开该频道后才能使用！\n");
                
/*                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ chtemp }) );
                else if( member_array(chtemp, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ chtemp }) );*/
                // Support of channel emote
                if( emote && !channels[verb]["intermud_emote"])
                {
                        string vb, emote_arg;

                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
                        {
                                vb = arg;
                                emote_arg = "";
                        }
                        if (me->query_temp("apply/name"))
                                temp_name = me->name();
                        else
                                temp_name = me->query("name");
                        if ( verb == "rumor" && (wizardp(me) || random(8 + me->query_skill("rumoring", 1)/4) > 0) )
                                if (me->query_temp("apply/name"))
                                        me->set_temp("apply/name", ({"某人"}));
                                else
                                        me->set("name","某人");
                        else if( verb == "rumor" )
                                me->add_temp("rumor_fail", 1);

                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
                        if (me->query_temp("apply/name"))
                                me->set_temp("apply/name",({temp_name}));
                        else
                                me->set("name",temp_name);
                        if (!arg)
                        {
                                write("你要做什么动作？\n");
                                return 1;
                        }
                }
        }
        else
        {
                if ( !env || !env->isroom() )
                {
                  if ( objectp(me->query_temp("channel_environment")) )
                    env=me->query_temp("channel_environment");
                  else if ( stringp(me->query_temp("channel_environment")) )
                    env=load_object(me->query_temp("channel_environment"));
                }
                
                if ( ( verb=="qy" || verb=="bd" ) && !env )
                  return 0;
                  
                if ( verb=="qy" && !env->query_region() )
                  return 0;
                  
                // Support of channel emote
                if( emote>0 && !channels[verb]["intermud_emote"])
                {
                        string vb, emote_arg;
                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
                        {
                                vb = arg;
                                emote_arg = "";
                        }
                        if (me->query_temp("apply/name"))
                                temp_name = me->query_temp("apply/name")[0];
                        else
                                temp_name = me->query("name");
                        if(verb == "rumor")
                                me->set("name","某人");
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
                        if (me->query_temp("apply/name"))
                                me->set_temp("apply/name",({temp_name}));
                        else
                                me->set("name",temp_name);
                        if( !arg )
                                return 0;
                }
        }
        me->set_temp("old_channel_msg", arg);
        // Make the identity of speaker.

        if( channels[verb]["anonymous"] )
        {
                if (!userp(me) || wizardp(me) || random(8 + me->query_skill("rumoring", 1)/4) > 0 )
                        who = channels[verb]["anonymous"]; //不漏
                else
                {
                        who = me->query("name"); //漏
                        me->add_temp("rumor_fail", 1);
                        me->add("badrp",1);
                }
                if (userp(me))
                        do_channel( this_object(), "sys", sprintf("谣言: %s(%s)。", me->query("name"),me->query("id")));
        }
        else if( (userp(me) || !stringp(who = me->query("channel_id"))) && emote>=0 )
                if (!me->query_temp("apply/name"))
                        who = me->query("name") + NOR""+HIG"(" + capitalize(me->query("id")) + ")"NOR;
                else
                        who = me->query_temp("apply/name")[0] +NOR""+ HIG"(" + capitalize(me->query_temp("apply/id")[0]) + ")"NOR;

        // Ok, now send the message to those people listening us.
    
        if(verb=="mp" || verb=="mp*")
                ob = filter_array( users(), "filter_mp",this_object(),menpai);
        else if ( verb=="bd" || verb=="bd*" )
        {
                location=env->query_location();
                ob = filter_array( users(), "filter_location",this_object(), location );
        } 
        else if ( verb=="qy" || verb=="qy*" )
        {
                region=env->query_region();
                ob = filter_array( users(), "filter_region",this_object(), region );
        }
		else if ( verb=="rw" || verb=="rw*"||verb=="baowei" || verb=="baowei*"||verb=="dasong" || verb=="dasong*"|| verb=="jh"|| verb=="jh*" )
		{
				ob = users();
				if ((time()>1422709200&&time()<1423321200)||query("WizTest"))
				ob = filter_array( ob, (:wizardp:));
		}
/*        else if(verb=="ct"||verb=="ct*")
        ob = ({ lover,me });*/
        else if(verb=="tt"||verb=="tt*")
                ob = team;
        else if(verb=="group" || verb=="group*")
        {        
                ob = filter_array( users(), "filter_group",this_object(),me);
                if(GROUP_D->group_member(me)==0)
                {
                    arg = BBLU + arg;
                    arg = replace_string(arg, NOR, BBLU+HIW) + NOR;
                    
                }
        }
        else if(verb=="dasong" || verb=="dasong*")
        {        
                ob = filter_array(children(USER_OB), (: userp :));
                ob = filter_array(ob, (: environment :));
                ob = filter_array(ob, (: $1->query("song/pro") :) );
                
        }
        else 
                ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
        
/*废除no_listen_npc环境变量，通过开关频道来过滤消息
        if (!userp(me))
          ob = filter_array(ob, (: !$1->query("env/no_listen_npc"):) );
*/        
        if( !arg || arg == "" || arg == " " ) 
          arg = "...";
        if( !stringp(arg) ) 
          arg = "";
        
        arg = replace_string(arg, NOR, NOR+channels[verb]["prefix"]) + NOR;

        if( wizardp(me) && 
            !me->query("env/hide_wiz") && 
            verb != "rumor" && 
            verb != "rumor*") 
        {
          arg = arg+" "HIR+"㊣"NOR;
        }


        if( emote ) 
        {
                 // Support of old behavier of intermud emote.
            if (emote>0)
            {
              if( channels[verb]["intermud_emote"] ) arg = who + " " + arg;
            }
          if (!stringp(arg)) arg = "";
          if(verb=="mp")
          {
            if ( emote<0 )
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], menpai,arg ), ob );
            else
            {
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], menpai,arg ), 
                       filter_array(ob, "filter_emotecmd", this_object(), 0) );
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], menpai,arg + "(" +me->query("id")+" || "+ emotecmd + ")"), 
                       filter_array(ob, "filter_emotecmd", this_object(), 1) );
            }
          }
          else if (verb=="group")
          {
            if ( emote<0 )
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], liupai,arg ), ob );
            else
            {
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], liupai,arg ), 
                       filter_array(ob, "filter_emotecmd", this_object(), 0) );
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], liupai,arg + "(" +me->query("id")+" || "+ emotecmd + ")"), 
                       filter_array(ob, "filter_emotecmd", this_object(), 1) );
            }
          }
          else if (verb != "act")
          {
            if ( verb != "rumor" )
            {
              if (channels[verb]["using_channel"])
              {
                if ( emote<0 )
                  message( "channel:" + channels[verb]["using_channel"],
                           sprintf( channels[verb]["msg_emote"], arg ), ob );
                else
                {
                  message( "channel:" + channels[verb]["using_channel"],
                           sprintf( channels[verb]["msg_emote"], arg ), 
                           filter_array(ob, "filter_emotecmd", this_object(), 0) );
                  message( "channel:" + channels[verb]["using_channel"],
                           sprintf( channels[verb]["msg_emote"], arg + "(" +me->query("id")+" || "+ emotecmd + ")"), 
                           filter_array(ob, "filter_emotecmd", this_object(), 1));
                }
              }
              else
              {
				if ((verb == "qq" || verb == "chat") && who != "北侠QQ频道精灵")
				{
					//IM_D->process_send_msg(COLOR_D->uncolor(sprintf(channels[verb]["msg_emote"], replace_string(replace_string(arg,"Ｖ","V"),"㊣","") )));
				}
/*				if (who == "北侠QQ频道精灵") //let the qq to chat channel message echo back to qq group
                {
                  arg = arg + "（回复请用QQ频道）";
                  arg = COLOR_D->clean_color(arg);
                  arg = replace_string(arg,"Ｖ","V");
                  arg = COLOR_D->clean_color(arg);
                  arg = COLOR_D->uncolor(arg);
                  arg = replace_string(arg,"㊣","");
                  IM_D = load_object("/adm/daemons/im_d");
                  IM_D->process_send_msg(IM_D, "mud", "【闲聊】"+ COLOR_D->clean_color(replace_string(replace_string(arg,NOR,""),HIC,"")));
                } */
                if ( emote<0 )
				{
					if (who == "北侠QQ频道精灵")
					{
						arg = replace_string(arg, "(QQ群)", HIG "(QQ群)" + channels["qq"]["prefix"]);
					}
					message( "channel:" + verb,
                         sprintf( channels[verb]["msg_emote"], arg ), ob );
				}
                else
                {
                  message( "channel:" + verb,
                           sprintf( channels[verb]["msg_emote"], arg ), 
                           filter_array(ob, "filter_emotecmd", this_object(), 0));
                  message( "channel:" + verb,
                           sprintf( channels[verb]["msg_emote"], arg + "(" +me->query("id")+" || "+ emotecmd + ")"), 
                           filter_array(ob, "filter_emotecmd", this_object(), 1));
                }                                    
              }
            }else 
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_emote"], arg ), ob );
          }       
        } else {
          if(verb=="mp")
            message( "channel:" + verb,
                     sprintf( channels[verb]["msg_speak"], menpai,who,arg ), ob );
          else if (verb=="group")
            message( "channel:" + verb,
                     sprintf( channels[verb]["msg_speak"], liupai,who,arg ), ob );
          else 
          {
           if (who == "北侠QQ频道精灵")
              if (verb=="chat")
                who = "北侠QQ群";
              else  who = "";
			if ((verb == "qq" || verb == "chat") && who != "北侠QQ频道精灵")
			{
				//IM_D->process_send_msg(COLOR_D->uncolor(sprintf(channels[verb]["msg_speak"], who, replace_string(replace_string(arg,"Ｖ","V"),"㊣","") )));
			}
            
            if (channels[verb]["using_channel"])
              message( "channel:" + channels[verb]["using_channel"],
                       sprintf( channels[verb]["msg_speak"], who, arg ), ob );
            else
            {
/*              if (who == "北侠QQ群") //let the qq to chat channel message echo back to qq group
              {
                arg = COLOR_D->clean_color(arg);
                arg = replace_string(arg,"Ｖ","V");
                arg = COLOR_D->clean_color(arg);
                arg = COLOR_D->uncolor(arg);
                arg = replace_string(arg,"㊣","");
                arg = arg + "（回复请用QQ频道）";
                IM_D = load_object("/adm/daemons/im_d");
                IM_D->process_send_msg(IM_D, "mud", "【闲聊】"+who + ": " + replace_string(arg,NOR,""));
              }                        */
              message( "channel:" + verb,
                       sprintf( channels[verb]["msg_speak"], who, arg ), ob );
            } 
          }
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

        if (    (verb == "rumor" || verb == "rumor*") 
                && userp(me) && !wizardp(me)
                && random(8 + me->query_skill("rumoring", 1)/4) == 0 )
        {
          message("channel:rumor", HIM"【谣言】某人: 我看到了！！就是"+me->query("name")+"("+capitalize(me->query("id"))+")"+"造的谣！！\n"NOR, users());
          me->add_temp("rumor_fail", 1);
          me->add("badrp",1);
        }

        if (userp(me) || strsrch(file_name(me), "/clone/npc/dizi")!=-1)
        {
            if(time() - me->query_temp("last_chat_record_time") > 2)
            {
              me->set_temp("chat_count",0);
              me->set_temp("last_chat_record_time",time());
            }
            me->add_temp("chat_count",1);
        }
        else
        {
            me->set_temp("chat_count",0);
        }
        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;
        
        if( ch["wiz_only"] ) return (is_logger(ppl) || wizardp(ppl));
        return 1;
}

//过滤在一个地方的玩家
int filter_location(object ppl, string location)
{
    string from;
    object env;
    
    if ( !location ) return 0;
	if ( !(env=environment(ppl)) ) return 0;
    if ( (stringp(from=ppl->query_temp("xinfang/from"))&&(env=load_object(from))) || env=environment(ppl) ) 
    {
        if ( objectp(env) && env->query_location()==location ) return 1;
    }
    else return 0;

}

//过滤同一区域玩家
//禁止不可识别区域（也就是任务区域）玩家进行区域广播
int filter_region(object ppl, int region)
{
        object env;
        if ( !region ) return 0;
        
        if ( !(env=environment(ppl)) ) return 0;
        
        if ( env->query_region()!=region ) return 0;
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
        if( ppl->query("env/learn_emote") && type ) return 1;
        if( !ppl->query("env/learn_emote") && !type ) return 1;
        return 0;
}

int filter_group(object ppl, object speaker)
{
        string* apps;
        if( !environment(ppl) ) return 0;
        return GROUP_D->same_group(ppl,speaker);
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
//      write("debug:   "+channel+" d="+sprintf("%d\n", d)); 
        if (channel == "rumor") block_rumor = d;
        if (channel == "chat") block_chat = d;
        return 1;
}

int is_logger(object ob)
{
        if (wizardp(ob) && ob->query("is_logger1")) return 1;
        return 0;
}
