// /include/armor_price.h

int eq_price(object ob)
{
	int lv, price=1;

	lv=ob->query("level");

	switch (ob->query("armor_type")) {
		case "head" :
			price= 30+lv*10;
			break;
		case "necklace" :
			price= 20+lv*6;
			break;
		case "body" :
			price= 40+lv*12;
			break;
		case "cloak" :
			price= 30+lv*11;
			break;
		case "armor" :
			price= 20+lv*8;
			break;
		case "gloves" :
			price= 10+lv*8;
			break;
		case "boots" :
			price= 30+lv*8;
			break;
		case "ring" :
			price= 20+lv*5;
			break;  
		case "leggings" :
			price= 40+lv*9;
			break;
		case "shield" :
			price= 45+lv*11;
			break;
		default :
			price=100;
	}
	return price;
}
