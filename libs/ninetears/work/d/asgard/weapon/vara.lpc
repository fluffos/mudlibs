//.oO JaDe Oo.  Junio'01

inherit "/obj/weapon";

void setup()
{	
	set_name("Vara del %^BOLD%^BLACK%^Avatar%^RESET%^");
	set_short("Vara del %^BOLD%^BLACK%^Avatar%^RESET%^");
	set_long("lala ia pensare algo");
	set_main_plural("Varas del %^BOLD%^BLACK%^Avatar%^RESET%^");	
	add_alias("vara del avatar");
	add_alias("vara");
        add_plural("varas");
	add_plural("varas del avatar");
        set_enchant(3);
	set_twohanded(1);
	set_weight(25);
 //       add_attack("mace","blunt",2,8,2);
//	add_property("guild",({"wizard"}));
}
void danyo()
{
int dam;	
dam=query_damage_roll();
 return ::dam +6;
}

void write_message(string happen,int damage,string str,object me,object him)
{
string yo=me->query_cap_name();
string el=him->query_cap_name();
string vara=TO->query_short();

switch(damage)
{
 case 0:

   tell_room(environment(me),yo+" no consigue golpear a "+el+".\n",({him,me}));
   tell_object(me,"No consigues golpear a "+el+".\n");
   tell_object(him,yo+" no consigue golpearte.\n");
   break;

 case 1..5:
    
   tell_room(environment(me),yo+" golpea a "+el+" con su "+vara+".\n",({him,me}));
   tell_object(me,"Golpeas a "+el+" con tu "+vara+".\n");
   tell_object(him,yo+" te golpea con su "+vara+".\n");  
   break;

 case 6..15:
    
   tell_room(environment(me),yo+" machaca el brazo de "+el+" con su "+vara+".\n",({him,me}));
   tell_object(me,"Machacas el brazo de "+el+" con tu "+vara+".\n");
   tell_object(him,yo+" machaca tu brazo con su "+vara+".\n");  
   break;

case 16..25:
    
   tell_room(environment(me),yo+" hunde su "+vara+" en el abdomen de "+el+".\n",({him,me}));
   tell_object(me,"Hundes tu "+vara+" en el abdomen de "+el+".\n");
   tell_object(him,yo+" hunde su "+vara+" en tu abdomen.\n");
   break;

 case 26..35:
    
   tell_room(environment(me),yo+" golpea con fuerza la pierna de "+el+" con su "+vara+" haciendole perder el equilibrio.\n",({him,me}));
   tell_object(me,"Golpeas con fuerza la pierna de "+el+" con tu  "+vara+" haciendole perder el equilibrio.\n");
   tell_object(him,yo+" golpea con fuerza tu pierna con su "+vara+" haciendote perder el equilibrio.\n");
   break;
 
 case 36..45:
   
   tell_room(environment(me),"Oyes crujir los huesos de "+el+" cuando "+yo+" le golpea con su    "+vara+".\n",({him,me}));
   tell_object(me,"Oyes crujir los huesos de "+el+" cuando le golpeas con tu "+vara+".\n");
   tell_object(him,"Oyes el crujido de tus huesos cuando "+yo+" te golpea con su "+vara+".\n");  
   break;

case 46..1000:
   
   tell_room(environment(me),""+yo+" golpea brutalmente a "+el+" con su "+vara+" destrozandole el rostro.\n",({him,me}));
   tell_object(me,"Golpeas brutalmente a "+el+" con tu "+vara+" destrozandole el rostro.\n");
   tell_object(him,""+yo+" te golpea brutalmente con su "+vara+" destrozandote el rostro.\n");  
   break;
}  
}
int weapon_attack(object defdr, object atckr,int damage_roll)
{
	::weapon_attack(defdr,atckr,damage_roll);
	return ::weapon_attack(defdr,atckr,damage_roll);
}
