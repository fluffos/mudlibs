inherit "/obj/monster";
//#define ENV environment(this_object())
void setup()
 {
 set_name("%^BOLD%^Sirvienta%^RESET%^ personal de %^BOLD%^RED%^Leviathan%^RESET%^");
 add_alias("sirvienta");
 add_plural("sirvientas"); 
set_cha(18);
 set_race("human");
 set_short("%^BOLD%^Sirvienta%^RESET%^ personal de %^BOLD%^RED%^Leviathan%^RESET%^");
 add_language("common");
 set_language("common");
 set_long("Es una bella dama seleccionada entre las mejores, su vida esta consagrada "
	"al bien estar de su amo y senyor %^BOLD%^RED%^Leviathan.%^RESET%^\n");
 set_align(0);
 set_gender(0);
 load_chat(20,
            ({
              1,":se acerca con una bandeja llena de manjares.\n",
              1,":ofrece unos vinos de las afamadas bodegas de su senyor.\n",
              1,":se arregla las ropas discretamente.\n",
             }));
 set_max_hp(100000000);
 set_hp(100000000);
 }

int adjust_hp(int i, object hp_remover,mixed type) 
{
 if(hp_remover && hp_remover != TO) 
 	{
	tell_object(hp_remover,"No me pegue senyor! me hace danyo!\n");
// 	tell_room(ENV,hp_remover->query_cap_name()+" hace %^BOLD%^YELLOW%^"+ save_variable(i)+" %^RESET%^Pvs de danyo.\n",hp_remover);
	}
return ::adjust_hp(i,hp_remover,type);
}

int attack_by()
 {
	write ("La sirvienta corre al otro lado de la"
	" fuente para evitar el enfrentamiento.\n");
	TO->do_peace();
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

int ponme()
{
write ("Senyor aqui tiene su vermouth bien fresquito!\n");
}


int do_peace()
{
    object *ob;
    object *att;
    object *call;
    int i, s;

    ob=all_inventory(environment(this_player()));
    i=0;
    for(i=0; i<sizeof(ob); i++)
    {
        if(living(ob[i]))
        {
            att=ob[i]->query_attacker_list();
            call=ob[i]->query_call_outed();
            for(s=0; s<sizeof(att); s++)
            {
                ob[i]->stop_fight(att[s]);
                att[s]->stop_fight(ob[i]);
            }
            for(s=0; s<sizeof(call); s++)
            {
                ob[i]->stop_fight(call[s]);
                call[s]->stop_fight(ob[i]);
            }
        }
    }
    return 1;
}

