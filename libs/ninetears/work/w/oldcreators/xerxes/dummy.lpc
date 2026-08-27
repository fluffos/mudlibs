inherit "/obj/monster";
void setup()
 {
 set_name("dummy");
 set_cha(2);
 set_race("ogre");
 set_short("Dummy Tester");
 add_language("drow");
 set_language("drow");
 set_long("Un dummy con cara de punching ball.\n");
 set_align(-500);
 set_max_hp(100000000);
 add_property("no_silence",100);
 }

int adjust_hp(int i, object hp_remover,mixed type) 
{
 if(hp_remover && hp_remover != TO) 
 	{
	tell_object(hp_remover,"HACES "+save_variable(i)+" PVS DE DANYO.\n");
 	tell_room(ETO,hp_remover->query_cap_name()+" hace "+ save_variable(i)+" Pvs de danyo.\n",hp_remover);
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

