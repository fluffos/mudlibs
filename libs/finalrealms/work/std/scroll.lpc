
/*
    One shot scrolls
    For things like area spells that I DON'T want repeated
    Taniwha 1995
    Restricted to partly magical guilds only + thief by default
    Added "all" option to include fighting classes
    Raskolnikov October 1996
*/
inherit "/std/item";
#define ETP environment(this_player())
#define QN query_short()
int do_use(string str);
int query_size() { return 1; }
int valid_targets(string str);
/* Allow replacement of an existing spell */
int override = 0;
mapping guilds = ([ 
  "wizard":5,
  "drow_wizard":5,
  "wizthief":8,
  "bard":10,
  "taniwha":10,
  "hokemj":8,
  "timion":12,
  "Ducky":10,
  "Cyrcia":10,
  "Grimbrand":10,
  "wiz-war":5,
  "thief":20,
  "paladin":15,
  "antipaladin":15
]);
mapping query_guilds() { return guilds; }
mapping learnable = ([
]);
nosave int phrase;
string file;
string spellname;
string func;
int gp;
int deads;
void create() {
    ::create();
    set_holdable(1);
}

int query_scroll() { return 1; }

string  enchant_string()
{
    return "It's a scroll O.K. Some animal gave it's all for this, then "
    "there are all the octarine beetles that died providing "
    "the ink and you really don't want to know what a waste "
    "of a perfectly good virgin it is getting the spell to "
    "stick.\n\n\n"
    "Have you any idea how hard it is to find a virgin ant queen ?\n";
}
int query_enchant()
{
    return 1;
}
void set_guilds(mapping map)
{
    string *inds;
    inds = keys(map);
    if(member_array("all", inds) != -1)
    {
	guilds += ([
	  "warrior":20,
	  "fighter":20,
	  "ranger":20,
	]);
	return ;
    }
    if( !guilds) guilds = map;
    else guilds = map;
}
void set_spell(string fil,string fun,int lock,int gpuse,int dds)
{
    file = fil;
    func = fun;
    gp = gpuse;
    deads = dds;
    if(!func) func = "cast_spell";
}
void init()
{
    int i;
    add_action("do_use","scroll");
    add_action("do_help","help");
    add_action("do_xread","study");
    ::init();
}
int do_use(string str)
{
    int i,level;
    string *index,which;
    object who,guild;
    who = TP;
    level = who->query_level();
    guild = who->query_guild_name();
    if(!query_in_use())
    {
	notify_fail("You have to hold scrolls to use them!.\n");
	return 0;
    }
    if(who->query_property("BLIND"))
    {
	notify_fail("A blind person reading a scroll ?, perhaps not.\n");
	return 0;
    }
    if(sizeof(guilds))
    {
	if(!guild) 
	{
	    write("Something bad happened. no guild.\n");
	}
	if(!guilds[guild])
	{
	    write("Your guild cannot use this scroll.\n");
	    return 1;
	}
	if(level < guilds[guild])
	{
	    write("You can not use this scroll at your level.\n");
	    return 1;
	}
    }
    str = who->expand_nickname(str);
    if( valid_targets(str) )
    {
	say((string)who->query_cap_name()+" waves a "+QN+".\n");
	tell_object(who,"You wave a "+QN+" at "+str+".\n");
	call_other(file,func,str,who,1);
	who->adjust_gp(gp);
	call_out("move",0,"/room/rubbish");
    }
    return 1;
}
int do_help(string str)
{
    int i;
    if( str == "scroll")
    {
	if(TP->query_property("BLIND"))
	{
	    notify_fail("A blind person reading a scroll ?, perhaps not.\n");
	    return 0;
	}
	write(file->help());
	write("\"scroll target\" to use the scroll.\n");
	if(sizeof(learnable))
	{
	    write("\"study scroll\" to learn the spell on the scroll.\n");
	}
	return 1;
    }
    return 0;
}
int valid_targets(string str)
{
    object *olist;
    int i;
    olist = find_match(str,ETP);
    if(deads) olist += find_match(str,TP);
    if(ETP->query_property("nocast") || TP->query_property("nocast"))
    {
	write("Something blocks the magic!\n");
	return 0;
    }
    if((int)this_player()->query_pacify_spell()==1)
    {
	write("Some magic blocks you from doing that!\n");
	return 0;
    }
    if(!sizeof(olist))
    {
	write("There seems to be no "+str+" here.\n");
	return 0;
    }
    if(!deads) for( i = 0; i < sizeof(olist); i++)
	{
	    if( olist[i]->query_creator() && !this_player()->query_creator() )
	    {
		write("You reconsider blasting an immortal with the scroll.\n");
		return 0;
	    }
	    if( (!olist[i]->query_alive() &&
		!file->query_allowed_on_ghosts()  ) ||
	      olist[i]->query_pacify_shadow() )
	    {
		write("You can't target "+olist[i]->query_cap_name()+".\n");
		return 0;
	    }
	}
    return 1;
} 
void set_learnable(mapping map,string name)
{
    learnable = map;
    spellname = name;
}
int do_xread(string str)
{
    int i,level;
    string *index,which;
    object who,guild;
    if(str != "scroll")
    {
	notify_fail("Study what ?.\n");
	return 0;
    }
    who = TP;
    level = who->query_level();
    guild = who->query_guild_name();

    index = explode(file,"/");
    which = index[sizeof(index)-1];

    if(!query_in_use())
    {
	notify_fail("You aren't holding the scroll.\n");
	return 0;
    }
    if(who->query_property("BLIND"))
    {
	notify_fail("A blind person reading a scroll ?, perhaps not.\n");
	return 0;
    }
    if(!sizeof(learnable))
    {
	write("This scroll is not clear enough to learn the spell from.\n");
	return 1;
    }
    if(!learnable[guild])
    {
	write("Your guild cannot memorize this scroll.\n");
	return 1;
    }
    if(level < learnable[guild])
    {
	write("You can not memorize this scroll at your level.\n");
	return 1;
    }
    if(!override)
	if( TP->query_spell(spellname) )
	{
	    write("You already know this spell.\n");
	    return 1;
	}
    if( !TP->query_property("read_magic"))
    {
	write("You have to cast read magic before learning the spell.\n");
	TP->remove_static_property("read_magic");
	return 1;
    }
    write("You study the scroll intently and the meaning of the sigils "
      "hidden within the writing becomes suddenly clear and a blast of "
      "knowledge almost overwhelms your brain.\n"
      "The shock is so great that you will be unable to cast for some time.\n");
    say((string)TP->query_cap_name()+" studies a scroll intently.\n"
      "Suddenly "+TP->query_cap_name()+" shudders and turns pale, "
      "the scroll disintegrates under "+TP->query_possessive()+"'s shaking hands.\n"
      , ({TP}) );
    TP->add_timed_property("nocast",1,1800);
    TP->add_spell(spellname,which);
    say("The scroll crumbles into dust as the magic in it disappears.\n");
    call_out("move",0,"/room/rubbish");
    return 1;
}


