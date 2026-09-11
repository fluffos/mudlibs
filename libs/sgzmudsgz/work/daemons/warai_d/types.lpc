/* example
**	"commando":(["name" : "民兵",     		chinese name
**		     "lvl" : 1, 	  		troop level
**		     "type" : "cavalry",  		troop category
**		     "forbiden" : ({"※" }), 		terrian can not enter
**           "cost":(["gold":1, "food":1 ]) 	cost
**		     "recruit":(["gold":1, "food":1 ]) 	recruit cost
*/
#define SAVE_FILE "/data/daemons/troop_types"
#define DEFAULT_TYPE "footman"

inherit M_ACCESS;

private mapping types;

void save_data()
{
        unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
        if( !sizeof(types) )types = ([ ]);
        return;
}
mixed query_type(string type, string what)
{
	mapping troop;

	if( member_array(type, keys(types)) == -1 )type = DEFAULT_TYPE;
	troop = types[type];
	if( member_array(what, keys(troop)) == -1 )return 0; 
	else return troop[what];
}
int set_type(string type, string what, mixed value)
{
	mapping troop;
	
	if( member_array(type, keys(types)) == -1 )
		types[type] = ([ ]);
		
	troop = types[type];
	troop[what] = value;
	types[type] = troop;

	save_data();
	
	return 1;
}
mapping query_all_type()
{
	return types;
}
