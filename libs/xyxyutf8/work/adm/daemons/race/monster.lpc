// monster.c

#include <race/monster.h>

void setup_monster(object ob)
{
	mapping my,max;
    	int  qi, shen;

	my = ob->query_entire_dbase();

	my["unit"] = "只";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "雄性";
    	if( undefinedp(my["age"]) ) my["age"] = random(80) + 15;
	if( undefinedp(my["str"]) ) my["str"] = random(11) + 10+ob->query_level();
	if( undefinedp(my["cor"]) ) my["cor"] = random(31) + 10+ob->query_level();
	if( undefinedp(my["int"]) ) my["int"] = random(31) + 10+ob->query_level();
	if( undefinedp(my["spi"]) ) my["spi"] = random(31) + 10+ob->query_level();
	if( undefinedp(my["cps"]) ) my["cps"] = random(31) + 10+ob->query_level();
	if( undefinedp(my["per"]) ) my["per"] = random(21) + 10+ob->query_level();
	if( undefinedp(my["con"]) ) my["con"] = random(31) + 10+ob->query_level();
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10+ob->query_level();
	if( !userp(ob) && undefinedp(my["daoxing"]) )
		my["daoxing"] = ob->query_max_daoxing();
	if( userp(ob) || undefinedp(my["max_gin"]) ) 
        {
        	if( ob->query_level()<9 )
        		my["max_gin"] = 100;
        	else if( ob->query_level()<39 )
        		my["max_gin"] = 300;	
        	else	my["max_gin"] = ob->query_level()*2/3;	
		if(my["max_gin"]<1) my["max_gin"]=1;//mon 1/28/98
        }
        
	qi = ob->query_con()*20+ob->query_str()+ob->query_level()*100;
	shen = ob->query_con()*50+ob->query_spi()+ob->query_level()*200;

	if( undefinedp(my["max_kee"]) || my["max_kee"]<qi )
		my["max_kee"] = qi;
	if( undefinedp(my["max_sen"]) || my["max_sen"]<shen )
		my["max_sen"] = shen;
		
	if(my["max_kee"]<1) my["max_kee"]=1;//mon 1/28/98
	if(my["max_sen"]<1) my["max_sen"]=1;//mon 1/28/98   
	ob->powerup();
	//	NOTE: monster has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

