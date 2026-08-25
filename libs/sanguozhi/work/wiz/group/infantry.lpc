// Define the attack messages of this type of troop
// and give the basic damage it caused
// $G refers to the general in charge of the troop
// $g refers to the general in charge of the enermy
// $N refers to itself and $n refers to enermy troop
#include <ansi.h>
private mapping *do_attack = ({
	(["msg":HIB"步兵队分成三列，稳稳的向敌军冲去。"NOR,
	  "damage": 5,]),
        (["msg":HIY"步兵队士气高昂的冲向敌军。"NOR,
          "damage": 6,]),
        (["msg":HIG"步兵队散乱得向敌军冲去。"NOR,
          "damage": 4,]),
});
mapping query_attack(string environment)
{ 
	return do_attack[random(sizeof(do_attack))];
        
}
// Obtain the id and chinese of this type of troop
string query_id()
{
	return "infantry";
}
string query_name()
{
	return "步兵";
}
string query_type()
{
	return "infantry";
}
// Attack bonus, when attack some troop
// it is a percentage value and can be positive or negative
mapping query_special_attack()
{	

	return (["seaman":10,"cavalry":-30]);
}
// Defence bonus when attacked by some troop
mapping query_special_defence()
{	
	return (["seaman":10,"cavalry":-30]);
}
// Defence ablility of arrow attack
int query_arrow_defence(string environment, int zhenfa)
{
	return 0;
}
// Get the some basic data for combat, now it includes
// energy recover, energy lost, basic attck ability and
// basic defence ability. all the items are affect by
// three factors, enrionment, weeather and zhenfa
int query_energy_recover(string environment, int weather, int zhenfa)
{
        int cost;

        if( environment == "∧" ) cost = 7;
        else if ( environment == "～" ) cost = 4;
        else if ( environment == "．" ) cost = 7;
        else if ( environment == "＊" ) cost = 7;
        else cost = 7;

        if( weather == 0 ) cost = cost + 1;
        else if( weather == 7 ) cost = cost - 1;
        else if( weather == 8 ) cost = cost - 2;
        else cost = cost;
	
        if( zhenfa = 0 ) cost = cost - 2;
        else cost = cost - 1;
	if (cost<1) cost=1;
        return cost;
}
int query_energy_cost(string environment, int weather, int zhenfa)
{
	int cost;

	if( environment == "∧" ) cost =18;
	else if ( environment == "～" ) cost = 21;
	else if ( environment == "．" ) cost = 18;
	else if ( environment == "＊" ) cost = 18;
	else cost = 16;

	if( weather == 0 ) cost = cost - 2;
	else if( weather == 2 ) cost = cost + 1;
	else if( weather == 3 ) cost = cost + 2;
	else cost = cost;

	if( zhenfa = 0 ) cost = cost - 2;
	else cost = cost - 1;
	
	return cost;
}
int query_basic_defence(string environment, int weather, int zhenfa)
{
}
int query_basic_attack(string environment, int weather, int zhenfa)
{
}
// Give types of environments where this type of troop
// can not enter
string *query_forbiden()
{
	return ({"※", });
}
// Special abilily of the troop such as bowman can use
// bow and arrow to attack
void powerup()
{
}
// Can it be upgrated and what are the requirements ?
mapping do_upgrade()
{
	return ([
		"spearman": (["train":80, "weapon":({"chang qiang",}),]),
		"blademan": (["train":80, "weapon":({"blade",}),]),
		"shieldman": (["train":80, "weapon":({"teng pai",}),]),
	]);
}
// Troops consume money and food, more powerful
// troop needs more
mapping query_cost()
{
	return ([
		"gold": 0.4,
		"food": 1,
	]);
}
// Some type of troops can only be recruited in
// particular cities, NONE means all cities can
string *get_city()
{
	return ({ });
}
// Recruitment cost
mapping query_recruit()
{
	return ([
		"gold": 0.4,
	]);
}

