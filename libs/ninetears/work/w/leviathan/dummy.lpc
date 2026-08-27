// By Dagda 12/02

inherit "/obj/monster";
int hpp,act,total,cont;

void setup()
{
    cont=0;
    set_name("dummy");
    set_cha(2);
    set_race("orc");
    set_short("Dummy Tester");
    set_long("Un dummy con cara de punching ball.\n");
    set_align(-500);
    set_max_hp(100000000);
    add_property("no_silence",100);
}


int adjust_hp(int i, object hp_remover, int nose) 
{
    int hp;
    if (cont++>=9)
    {
    	write("%^BOLD%^WHITE%^----- Danyo en "+cont+" golpes        :%^YELLOW%^ "+total+" Pvs.%^RESET%^\n");
    	write("%^BOLD%^WHITE%^----- Danyo promedio cada golpe : %^YELLOW%^"+(total/cont)+" Pvs.%^RESET%^\n");
    	write("%^BOLD%^WHITE%^----- Danyo promedio por turno  : %^YELLOW%^"+((total/(cont/2)))+" Pvs.%^RESET%^\n\n");
    	total=0;
    	cont=0;
    }
    hp = ::adjust_hp(i,hp_remover,nose);
	act=hpp-hp;
	tell_object(hp_remover,"%^BOLD%^RED%^("+(act)+") ");
	hpp=hp;
	total=total+act;
	return ::adjust_hp(2,hp_remover,nose);
}

void attack_by(object ob)
{
    return 0;
}
void do_death(object ob)
{
    return 0;
}
void attack_ob(object ob)
{ return 0; }

