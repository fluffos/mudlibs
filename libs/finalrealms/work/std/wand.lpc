
inherit "/std/item";

#define ETP environment(this_player())
#define QN query_short()
int do_use(string str);
int query_size() { return 1; }
int valid_targets(string str);
// Radix - May 30 1996
int personal_use = 0;
void set_personal_use() { personal_use = 1; }

int query_wand() { return 1; }

mapping guilds = ([ "wizard":5,
  "drow_wizard":5,
  "wizthief":8,
  "bard":10,
  "taniwha":10,
  "hokemj":8,
  "timion":12,
  "Cyrcia":12,
  "Grimbrand":10,
  "battlerager":25,
  "thief":20,
  "wiz-war":5,
  "drow_warrior":30,
  "fighter":30,
  "assassin":22,
  "paladin":15,
  "antipaladin":18,
   "ranger":15,
   "raisa":10,
   "shifter":30,
]);
nosave int phrase;
string file;
string func;
int lockout,gp;
int deads;

void create() {
    ::create();
    set_holdable(1);
}

string  enchant_string()
{
    int charges;
    charges = query_enchant();
    switch(charges)
    {
    case 0:
	return "Nope, nothing left in this one, it's an EX "+QN+".";
    case 1:
    case 2:
	return "Still a bit of life left in it.";
    case 3:
    case 4:
    case 5:
	return "A few shots left in it yet.";
    case 6..9:
	return "Plenty of life left in this one.";
    default:
	return "Hey this is a healthy one, good for many more.";
    }
}

int query_enchant()
{
    return query_property("charges");
}
int adjust_enchant(int i)
{
    add_property("charges",(int)query_property("charges")+i);
    return query_property("charges");
}
int set_enchant(int i)
{
    add_property("charges",i);
    return i;
}

void set_guilds(mapping map)
{
    if( !guilds) guilds = map;
    else guilds += map;
}
void set_spell(string fil,string fun,int lock,int gpuse,int dds)
{
    file = fil;
    func = fun;
    lockout = lock;
    gp = gpuse;
    deads = dds;
    if(!func) func = "cast_spell";
    if(!lockout) lockout = 500;
}
void init()
{
    int i;
    add_action("do_use","wand");
    add_action("do_help","help");
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
	notify_fail("Must be holding the wand, to use it.\n");
	return 0;
    }
    if( query_enchant() <= 0)
    {
	write("Nope, it's a dead "+QN+".\n");
	return 1;
    }
    if(sizeof(guilds))
    {
	if(!guilds[guild])
	{
	    write("Your guild cannot use this wand.\n");
    return 1;
	}
	if(level < guilds[guild])
	{
	    write("You can not use this wand at your level.\n");
	    return 1;
	}
    }
    if(query_timed_property("wand"))
    {
	write("The wand is unresponsive right now, maybe later.\n");
	return 1;
    }
    add_timed_property("wand",1,lockout);
    str = who->expand_nickname(str);
    if(valid_targets(str))
    {
	say((string)who->query_cap_name()+" waves a "+QN+".\n");
	//        if(who->query_creator())
	//            tell_object(who,"calling "+file+"->"+func+"(\""+str+"\","+who->query_cap_name()+",1);\n");
	tell_object(who,"You wave a "+QN+" at "+str+".\n");
	if(who->query_gp() > -gp)
	    call_other(file,func,str,who,1);
	who->adjust_gp(gp);
	adjust_enchant(-1);
    }
    return 1;
}

int do_help(string str)
{
    int i;
    if( str == "wand")
    {
	write(file->help());
	write("\"wand target\" to use the wand.\n");
	return 1;
    }
    return 0;
}

int valid_targets(string str)
{
    object *olist;
    int i;

    olist = find_match(str,ETP);
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
	    if( !olist[i]->query_alive() || olist[i]->query_pacify_shadow() || olist[i]->query_creator())
	    {
		write("You can't target "+olist[i]->query_cap_name()+".\n");
		return 0;
	    }
	}
	// added by Radix, so can't use wand on others but yourself
    if(personal_use && olist[0] != environment(this_object()))
    {
	write("You can't target anyone but yourself with this wand.\n");
	return 1;
    }
    return 1;
} 

