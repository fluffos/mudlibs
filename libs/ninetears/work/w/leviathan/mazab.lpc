/* Maza del bien */
//Pasada a dos Manos por Paris. Dec'98
inherit "/obj/weapon";

//object defensor,atacante;

int calc_log(int i)
{
  switch (i){
    case 10000..999999999: return 5; break;
    case 3500..9999: return 4; break;
    case 1500..2499: return 3; break;
    case 600..1499: return 2; break;
    case 0..599: return 1; break;
    default: return 0; break ;
    }
 }

void setup()
{
   	set_base_weapon("mace");
   	set_name("maza del bien");
   	add_alias("maza");
   	add_plural("mazas");
   	set_short("%^BOLD%^BLUE%^Maza del Bien%^RESET%^");
   	set_main_plural("%^BOLD%^BLUE%^Mazas del Bien%^RESET%^");
   	add_alias("bien");
   	set_long("Es una gran maza, hecha de un extranyo metal, que brilla con un fulgor "
            "azulado. Segun las leyenda, esta maza es un regalo de Lummen a la sacerdotisa "
            "encargada de vigilar el templo del bien y el mal, para que la balanza no se "
            "desequilibre. Si te fijas bien, puedes ver en ella grabadas las palabras: "
            "Protege al bien y auyenta a la maldad.\n\n");
	add_property("fixed_price",1);
   	set_twohanded(2);
   	add_property("guild",({"Clerigo de Lummen"}));
}

int query_value()
{
    return 200000;
}

int set_in_use(int j)
{
    if(j==1){
        if(TP->query_align()>-10)
           {
           write("La maza brilla con una gran fulgor azul, quemandote.\n");
           return 0;
           }
         }
    return ::set_in_use(j);
}

mixed *workout_attack(string tipo,int rolls,int dice,int bonus,int seguro,int critico_s)
{
   	int att_modifier,def_modifier;
   	mixed *hap;	

   	if(defensor->query_align()<0 || atacante->query_align()>0 )
       		return ({"fumble",0});

   	att_modifier=calc_log(-atacante->query_align());
 
   	def_modifier=calc_log(defensor->query_align()); 
        if (defensor->query_player() && (def_modifier>0)) def_modifier--;
         if (defensor->query_player() && (def_modifier>0)) def_modifier--;

   	hap=::workout_attack(tipo,rolls,dice,bonus,seguro,critico_s);
   	if(hap[0]=="hit")
   	{
   		hap[1]*=(def_modifier + att_modifier)/2;
   	}
   	return hap;
}
   
   
