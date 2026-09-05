// emoted.c
// Modified by iszt@pkuxkx, 2007-03-14, fixed '\n' bug, changed “” into 「」

#include <ansi.h>

inherit F_SAVE;

mapping emote;

//      The emote mapping contains the data base of emote definitions. Each emote
//      is defined in a sub-mapping with the following structure:
//
//      myself  - the message emoter will see
//      target  - the message the target will see when targeted
//      others  - the message others will see when no argument.
//
//      The emote mapping is indexed with the emote 'pattern' instead of emote
//      verb. For example, typing "smile" without argument will cause the daemon
//      search the emote mapping with "smile" as key, and typing "smile someone"
//      will cause the daemon search the emote mapping with "smile $" pattern as
//      the key, while $ means one argument.
//
//      In the message string, the following substitutions will be applied before
//      sending the messages:
//
//      $N              - name of emoter
//      $n              - name of target
//      $P              - pronoun of emoter
//      $p              - pronoun of target
//
//      Original by Annihilator@ESII (11/09/94)
//      $C              - very close call of emoter
//      $c              - close call of target
//      $R              - respect calling of target
//      $r              - rude calling of target
//      $S              - self calling of emoter
//      $s              - self-rude calling of emoter
//      aboved added by Xiang@XKX

mixed* top_emote_list = ({});
nosave mapping emote_stat = ([]);

void update_top_emote_list(string verb);

void create()
{
	seteuid( ROOT_UID );
	if( !restore() && !mapp(emote) )
		emote = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
varargs mixed do_emote(object me, string verb, string arg, int channel_emote)
{
	string str, my_gender, target_gender, msg_postfix;
	object target;
	object *user;
	int i;

	if( !environment(me) && !me->query("channel_id") ) return 0;

	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;
	
    if(userp(me) && me->query("antirobot/deactivity") < 1 && channel_emote)
    {
        update_top_emote_list(verb);
    }
	// Determine the pattern to be searched and the target.
	if ( stringp(arg) && arg != "" ) 	
		arg=replace_string(arg," ","");
	if ( stringp(arg) && arg != "" ) {

		if (environment(me))
			target = present(arg, environment(me));
		if(!objectp(target)) {
			// If not channel emote, only search target in our environment.
			if( !channel_emote ) return 0;
			target = find_player(arg);
			if( !objectp(target) )
			{
				user = users();
				for (i = 0; i < sizeof(user); i++)
					if (user[i]->query_temp("apply/id"))
						if (user[i]->query_temp("apply/id")[0] == lower_case(arg))
						{
							target = user[i];
							break;
						}
			}
			else	if (target->query_temp("apply/name"))
					return 0;
			if( !objectp(target) )
				 return 0;
		}
		if (!me->visible(target) && !me->query("channel_id")) return 0;
		if (me->query("channel_id") && target->query("env/invisibility")) return 0;
        if (SECURITY_D->get_wiz_level(target)>1&&SECURITY_D->get_wiz_level(me)<2&&target->query("env/no_emote")) return 0;
		target_gender = target->query("gender");
		if( target==me ) {
			msg_postfix = "_self";
			target = 0;
		} else msg_postfix = "_target";
	} else msg_postfix = "";

	my_gender = me->query("gender");

	if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
		if(str[<1] == '\n') str = str[0..<2];
		str = F_NAME->replace_color(str);
		str = replace_string(str, "“", "「");
		str = replace_string(str, "”", "」");
		str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_self(my_gender));
		str = replace_string(str, "$S", RANK_D->query_self(me));
		str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
			str = replace_string(str, "$C", RANK_D->query_self_close(target));
			str = replace_string(str, "$c", RANK_D->query_close(target));
			str = replace_string(str, "$R", RANK_D->query_respect(target));
			str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote ) message("emote", CYN + str + NOR+"\n", me);
	}

	if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
		if(str[<1] == '\n') str = str[0..<2];
		str = F_NAME->replace_color(str);
		str = replace_string(str, "“", "「");
		str = replace_string(str, "”", "」");
		str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_pronoun(my_gender));
		str = replace_string(str, "$S", RANK_D->query_self(me));
		str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		str = replace_string(str, "$C", RANK_D->query_self_close(target));
		str = replace_string(str, "$c", RANK_D->query_close(target));
		str = replace_string(str, "$R", RANK_D->query_respect(target));
		str = replace_string(str, "$r", RANK_D->query_rude(target));
		str = replace_string(str, "$n", target->name());
		str = replace_string(str, "$p", gender_self(target_gender));
		if(str[<1] == '\n') str = str[0..<2];
		if( !channel_emote ) message("emote", CYN + str + NOR+"\n", target);
	}

	if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
		if(str[<1] == '\n') str = str[0..<2];
		str = F_NAME->replace_color(str);
		str = replace_string(str, "“", "「");
		str = replace_string(str, "”", "」");
		str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_pronoun(my_gender));
		str = replace_string(str, "$S", RANK_D->query_self(me));
		str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
			str = replace_string(str, "$C", RANK_D->query_self_close(target));
			str = replace_string(str, "$c", RANK_D->query_close(target));
			str = replace_string(str, "$R", RANK_D->query_respect(target));
			str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote ) 
		{
		    if(environment(me)->query("real_dark") != 1)
		    {
		        message("emote", CYN + str + NOR+"\n", environment(me), ({me, target}));
		    }
		}
		else return str;
	}

	// Let NPC know we are doing emote on him.
	if( objectp(target) ) target->relay_emote(me, verb);

	return 1;
}

int set_emote(string pattern, mapping def)
{
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) ) return emote[pattern];
	else return ([]);
}

string *query_all_emote()
{
	return keys(emote);
}

int filter_top_emote_list(mixed* inarray,string verb)
{
    if(inarray[0] == verb || inarray[1] <= 0) return 0;
    return 1;
}

int sort_top_emote_list(mixed* data1,mixed* data2)
{
    if(data1[1] < data2[1]) return -1;
    if(data1[1] > data2[1]) return 1;
    return 0;
}

void update_top_emote_list(string verb)
{
    int i;
    string tmp_emote,cur_emote;
    int tmp_number,cur_number;
    int index;

    if(!undefinedp(emote_stat[verb]))
    {
        emote_stat[verb] = emote_stat[verb] + 1;
    }
    else
    {
        emote_stat[verb] = 1;
    }

    top_emote_list = filter_array(top_emote_list,"filter_top_emote_list",this_object(),verb);
    top_emote_list += ({ ({verb,emote_stat[verb]}) });
    top_emote_list = sort_array(top_emote_list,"sort_top_emote_list",this_object());

    if(sizeof(top_emote_list) > 30)
    {
        top_emote_list[0] = ({"NA",-1});
        top_emote_list = filter_array(top_emote_list,"filter_top_emote_list",this_object(),"");
    }
}

string* query_top_emote_list()
{
    string* emotes = ({});
    int i;
    for(i=sizeof(top_emote_list)-1;i>=0;i--)
    {
        emotes += ({top_emote_list[i][0]});
    }
    return emotes;
}

mapping get_emote_stat()
{
    return emote_stat;
}

mixed* get_top_emote_list()
{
    return top_emote_list;
}