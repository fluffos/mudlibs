// /include/weapon_price.h

int wp_price(object ob)
{
	int lv, price=1;

	lv=ob->query("level");

	switch (ob->query("weapon_type")) {
		case "spear" :
			price= 30+lv*10;
			break;
		case "dagger" :
			price= 20+lv*6;
			break;
		case "hammer" :
			price= 40+lv*12;
			break;
		case "blade" :
			price= 30+lv*11;
			break;
		case "wand" :
			price= 20+lv*8;
			break;
		case "fork" :
			price= 10+lv*8;
			break;
		case "staff" :
			price= 30+lv*8;
			break;
		case "sword" :
			price= 20+lv*5;
			break;  
		case "throwing" :
			price= 40+lv*9;
			break;
		case "axe" :
			price= 45+lv*11;
			break;
		case "whip" :
			price= 25+lv*9;
			break;
		default :
			price=100;
	}
	return price;
}
