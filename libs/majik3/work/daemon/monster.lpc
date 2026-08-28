/*
 * /daemon/material.c                   Material daemon for majik
 * 
 * coded by Dazzt
 * 
 * */

/*
 * Description for materials  (add more attributes as you feel necessary) :
 * 
 *   1. - Price in gold / kg
 *   2. - Weight in kg / dm3 (liter)
 *   3. - Damage resist table  (phys, fire, cold, elec .. add more, in %:s)
 *
 * */


// order of which resists appear

#define MAT_PHYS       0
#define MAT_FIRE       1
#define MAT_COLD       2
#define MAT_ELEC       3
#define MAT_ACID       4
#define MAT_DISI       5 //disintegrate
#define MAT_FALL       6 //resist vs. falling      
#define MAT_POIS       7 //poison

// "wrong material" is used if item has material not defined here

mapping materials = ([
"wrong material" : ({ 1,1.0,0,0,"organ",({ 0,0,0,0,0,0,0,0 }) }),
"platinum" : ({ 1457,21.0,0,0,"metal",({ 70,80,20,0,80,60,70,70 }) }),
"gold" : ({ 937,19.0,1,1,"metal",({ 60,50,20,0,99,55,70,70 }) }),
"lead" : ({ 10,11.0,1,3,"metal",({ 40,40,20,0,40,15,50,95 }) }),
"copper" : ({ 15,9.0,6,7,"metal",({ 50,60,20,0,80,45,35,60 }) }),
"bronze" : ({ 15,8.9,8,9,"metal",({ 60,60,20,0,25,50,35,60 }) }),
"brass" : ({ 15,8.4,5,6,"metal",({ 60,75,20,0,20,50,30,60 }) }),
"steel" : ({ 30,7.9,9,7,"metal",({ 75,80,20,0,25,70,50,60 }) }),
"iron" : ({ 15,7.8,9,8,"metal",({ 40,80,20,0,20,60,30,60 }) }),
"tin" : ({ 10,7.2,1,3,"metal",({ 30,75,20,0,20,40,30,60 }) }),
"zinc" : ({ 12,7.1,1,3,"metal",({ 30,60,20,0,80,30,20,60 }) }),
"silicon" : ({ 75,2.8,0,0,"stone",({ 10,0,20,0,0,30,20,70 }) }),
"aluminium" : ({ 20,2.7,4,4,"metal",({ 65,70,20,0,20,60,20,50 }) }),
"magnesium" : ({ 80,1.7,0,0,"metal",({ 10,0,20,0,0,30,20,70 }) }),
"molybdenum" : ({ 101,10.0,4,3,"metal",({ 75,95,5,10,45,95,25,35 }) }),
"indium" : ({ 500,7.3,0,0,"metal",({ 50,80,20,0,30,50,30,75 }) }),
"titanium" : ({ 150,4.5,1,2,"metal",({ 85,80,20,0,50,80,40,50 }) }),
"chromium" : ({ 600,5.2,4,4,"metal",({ 35,95,0,10,80,85,45,70 }) }),
"cobalt" : ({ 890,5.8,3,4,"metal",({ 90,95,10,50,30,75,35,25 }) }),
"nickel" : ({ 69,5.9,5,5,"metal",({ 85,90,10,35,75,55,35,25 }) }),
"pewter" : ({ 5,5.5,0,0,"metal",({ 50,70,10,0,25,40,35,60 }) }),
"majikium" : ({ 3413,5.0,1,0,"metal",({ 95,80,40,95,50,95,95,99 }) }),
"mithril" : ({ 1561,10.0,1,0,"metal",({ 90,80,20,0,99,90,95,99 }) }),
"adamantium" : ({ 2485,8.0,1,4,"metal",({ 99,80,20,0,40,95,90,95 }) }),
"highsteel" : ({ 250,7.2,4,6,"metal",({ 80,80,20,0,40,80,80,85 }) }),
"wood" : ({ 30,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"oak" : ({ 40,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"maple" : ({ 20,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"birch" : ({ 15,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"elm" : ({ 10,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"fir" : ({ 10,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"pine" : ({ 10,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"juniper" : ({ 45,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"burlap" : ({ 6,1.2,0,8,"cloth",({ 45,10,65,70,10,0,15,0 }) }),
"cedar" : ({ 25,0.5,2,0,"wood",({ 35,10,25,99,10,0,30,15 }) }),
"ebony" : ({ 50,0.7,1,0,"wood",({ 70,5,25,80,10,0,20,15 }) }),
"bamboo" : ({ 19,0.1,1,5,"wood",({ 55,5,20,90,15,0,10,15 }) }),
"bone" : ({ 2,1.5,1,0,"bone",({ 40,80,20,90,10,0,20,80 }) }),
"cloth" : ({ 3,0.7,0,3,"cloth",({ 30,5,50,80,10,0,15,40 }) }),
"glass" : ({ 100,2.5,2,0,"glass",({ 20,60,20,99,90,0,10,99 }) }),
"leather" : ({ 8,1.5,0,7,"cloth",({ 50,15,40,90,20,0,15,0 }) }),
"fur" : ({ 10,1.1,0,8,"cloth",({ 40,10,60,70,15,0,15,0 }) }),
"diamond" : ({ 5000,2.9,0,0,"gem",({ 99,20,20,99,99,0,30,90 }) }),
"food" : ({ 5,0.6,0,0,"organ",({ 20,0,50,70,0,10,10,30 }) }),
"wax" : ({ 15,0.7,0,0,"organ",({ 10,10,20,99,25,50,20,15 }) }),
"dragonscale" : ({ 1111,1.2,0,0,"bone",({ 50,80,10,90,5,5,95,60 }) }),
"obsidian" : ({ 1000,2.6,0,0,"glass",({ 50,99,20,99,75,0,5,99 }) }),
"crystal" : ({ 500,2.5,0,0,"glass",({ 30,95,20,99,90,0,70,99 }) }),
"basalt" : ({ 30,6.1,0,0,"stone",({ 70,99,20,99,60,0,10,99 }) }),
"granite" : ({ 5,2.7,0,0,"stone",({ 10,95,20,99,60,0,10,99 }) }),
"marble" : ({ 20,2.3,0,0,"stone",({ 20,95,20,99,60,0,10,99 }) }),
"stone" : ({ 3,2.0,2,0,"stone",({ 10,70,20,99,50,0,15,99 }) }),
"moonstone" : ({ 100,2.0,0,0,"stone",({ 60,60,20,99,55,0,60,99 }) }),
"water" : ({ 1,1.0,0,0,"organ",({ 99,0,10,20,50,0,30,10 }) }),
"ice" : ({ 1,0.9,0,0,"organ",({ 20,10,0,80,20,0,10,10 }) }),
"amber" : ({ 50,1.3,0,0,"stone",({ 40,30,20,99,10,0,60,30 }) }),
"sulphur" : ({ 40,2.1,0,0,"stone",({ 30,40,20,99,10,0,50,0 }) }),
"coal" : ({ 2,2.1,0,0,"stone",({ 10,10,20,40,10,0,30,0 }) }),
"paper" : ({ 50,0.7,0,0,"paper",({ 5,0,20,90,0,0,20,10 }) }),
"flesh" : ({ 2,0.5,0,0,"organ",({ 10,10,10,99,10,0,10,0 }) }),
"phosphorus" : ({ 99,3.8,0,0,"organ",({ 35,50,50,50,25,15,25,95 }) }),
"vegetation" : ({ 3,0.4,0,0,"organ",({ 35,10,25,99,10,0,30,10 }) }),
"hemp" : ({ 15,0.4,0,0,"organ",({ 60,0,50,90,10,80,50,15 }) }),
"vax" : ({ 5,2.0,0,0,"inorg",({ 20,20,20,20,20,20,20,20 }) }),
"clay" : ({ 3,0.1,0,0,"stone",({ 10,10,10,50,25,50,20,15 }) }),
"cotton" : ({ 22,0.6,0,4,"cloth",({ 35,5,55,75,10,0,15,5 }) }),
"silk" : ({ 88,0.1,0,9,"cloth",({ 35,5,20,85,10,5,20,5 }) }),
"ivory" : ({ 231,1.6,0,0,"bone",({ 50,75,20,90,10,10,25,40 }) }),
"pearl" : ({ 2000,1.7,0,0,"gem",({ 30,50,20,99,30,0,30,90 }) }),
"onyx" : ({ 770,3.0,1,1,"gem",({ 40,70,30,99,40,0,45,90 }) }),
"ruby" : ({ 3500,2.7,0,0,"gem",({ 70,65,20,99,75,0,35,90 }) }),
"sapphire" : ({ 2500,2.7,0,0,"gem",({ 70,65,20,99,75,0,35,90 }) }),
"garnet" : ({ 950,4.0,1,0,"gem",({ 90,75,25,99,81,60,25,75 }) }),
"amethyst" : ({ 45,3.2,0,0,"gem",({ 65,80,25,95,75,1,65,80 }) }),
"zircon" : ({ 100,3.7,0,0,"gem",({ 70,85,20,99,90,0,25,85 }) }),
"topaz" : ({ 300,4.1,0,0,"gem",({ 90,90,20,99,75,5,35,90 }) }),
"opal" : ({ 400,5.0,1,1,"gem",({ 80,90,20,99,80,5,30,90 }) }),
"bloodstone" : ({ 1350,2.3,0,0,"gem",({ 85,90,20,50,80,0,70,90 }) }),
"sunstone" : ({ 400,2.8,0,0,"gem",({ 70,85,20,99,80,0,65,85 }) }),
"aquamarine" : ({ 650,2.0,0,0,"gem",({ 75,90,15,99,90,0,20,85 }) }),
"emerald" : ({ 4500,2.0,0,0,"gem",({ 85,80,20,99,80,0,45,90 }) }),
"jade" : ({ 1550,4.5,1,0,"gem",({ 75,77,15,99,70,5,65,90 }) }),
"quartz" : ({ 200,2.5,1,1,"gem",({ 60,90,20,80,75,5,60,80 }) }),
]);

int add_material(string mat, int price, int weight, int *resists)
{
    if (materials[mat])
	return 0;

    materials[mat] = ({ price, weight, 0, 0, "stone", resists });
    return 1;
}

string *query_all_materials() 
{       
    string *s;
    s = keys(materials); 
    s -= ({ "wrong material" });
    return s;
}

string query_random_material()
{
	int i;
	string *k;
	
	k = keys(materials);
	
	i = random(sizeof(k) - 1) + 1;
	return k[i];
}

mixed query_material(string mat) { return materials[mat]; }

string query_name(string mat)       { return mat; }
int query_value(string mat)      { return materials[mat][0]; }
int query_weight(string mat)     { return materials[mat][1]; }
int query_wrar(string mat) { return materials[mat][2]; }
int query_arar(string mat) { return materials[mat][3]; }
int query_type(string mat) { return materials[mat][4]; }

int *query_resists(string mat) { return materials[mat][5]; }
