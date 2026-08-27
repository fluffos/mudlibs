inherit "/obj/monster";

void setup()
 {
 set_name("dummy");
 add_alias("tester");
 set_cha(2);
 set_race("human");
 set_short("%^BOLD%^GREEN%^Dummy Tester%^RESET%^");
 add_language("common");
 set_language("common");
 set_long("Un dummy con cara de punching ball.\n");
 set_align(-500);
 set_max_hp(100000000);
 add_property("no_silence",100);
 add_action("ponerseequipo","equipate");
add_property("nodrenable",1);
 }

int adjust_hp(int i, object hp_remover,mixed type) 
{
 if(hp_remover && hp_remover != TO) 
 	{
	tell_object(hp_remover,"HACES %^BOLD%^WHITE%^"+save_variable(i)+"%^RESET%^ PVS DE DANYO.\n");
 	tell_room(this_object(),hp_remover->query_cap_name()+" hace %^BOLD%^YELLOW%^"+ save_variable(i)+" %^RESET%^Pvs de danyo.\n",hp_remover);
	}
return ::adjust_hp(i,hp_remover,type);
}

int attack_by()
 {
	return 0;
 }
void  do_death()
 {
	TO->set_hp(TO->query_max_hp()); 
 }
 int attack_ob()
 {
	return 0;
 }

int ponerseequipo()
{
//	thisobject()->init_equip();
}
