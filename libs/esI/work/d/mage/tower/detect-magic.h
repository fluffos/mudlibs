// This is a spell to let caster can detect magic items	by Yueh 1995/4/6

#include <mudlib.h>

#define TYPE "misc"



string *magic_name =

    ({ "fire","cold","electric","energy","mental","acid","poison","magic","evil","devine","none" });

string *magic_c_name =

    ({ "火","冰","电","能源","精神","酸","毒","魔法","邪恶","神圣","核融" });



string *magic_name1 =

    ({ "fire","cold","electric","energy","evil","none" });



string *magic_c_name1 =

    ({ "火球术","冰雹术","幻雷术","以太之箭","绞心术","核融术" });



string identify_armor(object obj, int skill)

{

	int sp_def,i;

	string msg;

	if ((obj->query("armor_class")) || (obj->query("defense_bonus"))) {

	if (obj->query("special_defense") ) {

		msg="";

		for (i=0; i<11; i++){

		sp_def=(int)obj->query("special_defense/"+magic_name[i]);

		if ( sp_def ) {

			if (random(2)==0) 

				sp_def=sp_def+(random(108- skill))/2;

			else 	sp_def=sp_def-(random(108- skill))/2;

			msg+="这个防具对"+magic_c_name[i]+"系的魔法";



			if (sp_def > 60) msg+="有著不可思议的防御增强。\n";

			else if (sp_def > 38) msg+="有著十分优良的防御增强。\n";

			else if (sp_def > 28) msg+="有著非常优良的防御增强。\n";

			else if (sp_def > 18) msg+="有著优良的防御增强。\n";

			else if (sp_def > 8) msg+="有著显著的防御增强。\n";

			else if (sp_def >= 0) msg+="有著略微的防御增强。\n";

			else if (sp_def >= -8) msg+="有著略微的防御缺陷。\n";

			else if (sp_def >= -18) msg+="有著显著的防御缺陷。\n";

			else if (sp_def >= -28) msg+="有著严重的防御缺陷。\n";

			else if (sp_def >= -38) msg+="有著十分严重的防御缺陷。\n";

			else  msg+="有著不可思议的防御缺陷。\n";

		}

		}

	return msg;

	}

	else return("这个防具没有任何魔法防御特性。\n");

	}

	else return("这个物品不是防具。\n");



}



string consider_magic(object dest, int skill)

{

	int sp_def,i;

	string msg;

	msg="";

	for (i=0; i<6; i++){

		sp_def=(int)dest->query_special_defense(magic_name1[i]);

		write(sp_def);

		if (random(2)==0) 

			sp_def=sp_def+(random(110- skill))/2;

		else 	sp_def=sp_def-(random(110- skill))/2;

		msg+="这个生物对"+magic_c_name1[i]+"的攻击";



		if (sp_def > 80) msg+="有著不可思议的防御能力。\n";

		else if (sp_def > 60) msg+="有著十分优良的防御能力。\n";

		else if (sp_def > 40) msg+="有著非常优良的防御能力。\n";

		else if (sp_def > 20) msg+="有著优良的防御能力。\n";

		else if (sp_def >= 10) msg+="有著不错的防御能力。\n";

		else if (sp_def >= 0) msg+="有著一些的防御能力。\n";

		else if (sp_def >= -10) msg+="有著很差的防御能力。\n";

		else if (sp_def >= -20) msg+="有著非常差的防御能力。\n";

		else if (sp_def >= -40) msg+="有著十分差的防御能力。\n";

		else  msg+="几乎没有防御能力。\n";

	}

	return msg;



}


