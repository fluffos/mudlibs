/*
 * quest.c          generic quest system, inherited by player.c
 * 
 * coder            dazzt
 * 
 * */


/* --- -- - variables - -- --- */

// format of 'quests': ({ int completed, int active, mixed quest_specific_info })

mapping quests = ([ ]);

/* --- function prototypes --- */

int init_quests();

void begin_quest(string);
int finish_quest(string);
int is_quest_finished(string);
int is_quest_active(string);

mixed set_quest_status(string, mixed);
mixed query_quest_status(string);
string *query_all_quests();

/* --- -- - functions - -- --- */

int init_quests()
{
	quests = ([]);
	return 1;
}

void begin_quest(string qname) 
{
	if (!quests)
		quests = ([ ]);
	
	quests[qname] = ({ 0, 1, 0 });
}

int finish_quest(string qname)     
{ 
	if (quests[qname])
		return quests[qname][0] = 1; 
	else
		return 0;
}

int is_quest_finished(string qname) 
{ 
	if (quests[qname])
		return quests[qname][0]; 
	else
		return 0;
}

int is_quest_active(string qname) 
{ 
	if (quests[qname])
		return quests[qname][1]; 
	else
		return 0;
}
	
mixed set_quest_status(string qname, mixed st) { return quests[qname][2] = st; }
mixed query_quest_status(string qname)         { return quests[qname][2]; }

string *query_all_quests() 
{ 
	if (quests)
		return keys(quests); 
	else
		return 0;
}
	
	
	
