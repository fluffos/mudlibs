#define MASTERY_D "/daemons/mastery_d"

#define ENHANCE_LIMIT 50
#define SPECIAL_LIMIT 5
#define MAX_DAMAGE 500
#define HIT_HELPER 20
#define HIT_NEEDED 60
#define BASE_DAMAGE 23
#define ENHANCE_MODIFIER 4
#define PSI_SP_NEEDED 10
#define BASE_DISRUPT 25 // must be over 20
#define TARGET_LVL_LIMIT 25
#define BASE_DEATH_CHANCE 26
#define FAIL_STUN 10
#define FAIL_STUN_AMOUNT 10 //random
#define SPECIAL_STUN_AMOUNT 10 //random
#define UNDEAD_STUN (attacker->query_skills("knowledge of mind")/5) + 10

#define PSI_IMEE_ATILTA query_sp()
#define PSI_IMEE_ATILTA_MAX query_max_sp()
#define PSI_IMEE_ATILTA_REDUCE reduce_sp(temp)

#define PSI_IMEE_DEFULTA query_hp()
#define PSI_IMEE_DEFULTA_MAX query_max_hp()
#define PSI_IMEE_DEFULTA_REDUCE hit_player(dam, "psionic")

object attacker, defender;
int att_int, att_wis, def_int, def_wis;
int att_suc, att_dam, att_hit;
int def_eva, def_blo;

string att_name, def_name;

//protos
void calc_values(object a, object d);
int calc_dam();
void write_messages(int dam);
void attack(object a,object d);


// this function should have more complicated formulas
void calc_values(object a, object d) {
  attacker = a;
  defender = d;

att_int = attacker->query_int();
  att_wis = attacker->query_wis();
  def_int = defender->query_int();
  def_wis = defender->query_wis();

  att_name = attacker->query_name();
  def_name = defender->query_name();

  att_suc = attacker->query_skills("mental force");
  att_dam = attacker->query_skills("overload brain");
  att_hit = attacker->query_skills("simultaneous thought");
  def_eva = defender->query_skills("evading thought");
  def_blo = defender->query_skills("mental block");
}

int calc_dam() {
        int hit, dam;
        // more complicated formulae needed
        hit = (att_suc+ att_int/2) + (def_wis/2 + def_eva);

        if(!this_player()->query_mentaldenial())if(hit+HIT_HELPER < random(HIT_NEEDED))return 0;

        dam = BASE_DAMAGE;
        dam += att_int*2;

        dam += att_hit*2;
        dam += att_dam*2;
        dam += this_player()->query_skills("mental strike");

        dam = dam/3*2;
        if(this_player()->query_mentaldenial()) {
                dam *= 2;
                this_player()->remove_denial();
        }
        dam -= def_wis*3;
        dam -= def_blo*2;

        if(random(att_dam+att_hit) > ENHANCE_LIMIT && !random(SPECIAL_LIMIT)) {
                tell_object(attacker, "You enhance your overload!\n");
                dam *= ENHANCE_MODIFIER;
        }

        if(dam < 1) {
                tell_object(attacker,def_name+" mentally blocks your attack!\n");
                tell_object(defender,"You mentally block "+att_name+"'s attack!\n");
                return 0;
        }

        dam /= 2;
        dam += random(dam);
    if(this_player()->query_wiz()) write(dam+"\n");
        if(dam > MAX_DAMAGE) dam = MAX_DAMAGE;

        dam += MASTERY_D->mastery("Power of the mind",attacker,defender);

        return dam;

}

// NOTE: Kirjota uudet messut
void write_messages(int dam) {

        if(dam >= MAX_DAMAGE) {
                tell_object(attacker, "You penetrate "+def_name+"'s puny resistance with awesome force and inflict a brutal mental blow to the braincore.\n");
                tell_object(defender, att_name+" penetrates your mental resistance with awesome force and brutally rips your brain!\n");
                return;
        }
        if(dam > MAX_DAMAGE * 2 / 3) {
                tell_object(attacker, "You shatter "+def_name+"'s mental stability.\n");
                tell_object(defender, att_name+"'s mental attack makes you feel very depressed.\n");
                return;
        }
        if(dam > MAX_DAMAGE /3) {
                tell_object(attacker, "You deliver a succesful mental blow on "+def_name+".\n");
                tell_object(defender, att_name+" mentally harms you!\n");
                return;
        }
        if(dam > MAX_DAMAGE /5) {
                tell_object(attacker, "You mentally attack "+def_name+".\n");
                tell_object(defender, att_name+" mentally attacks you.\n");
                return;
        }
        tell_object(attacker, "You manage to irritate "+def_name+" with your mental attack.\n");
        tell_object(defender, att_name+" inflicts a minor mental attack on you.\n");
        return;
}

int get_psi_cost() {
        int temp;

        temp = this_player()->query_level()/5; // 5
        //temp+= this_player()->query_skills("mental strike")/20; // 5
        temp+= this_player()->query_skills("mental force")/20; // 5
        temp+= this_player()->query_skills("overload brain")/20; // 5
        temp+= this_player()->query_int()/20; // 5 ?
        // 25

        temp-= this_player()->query_skills("knowledge of mind")/20; // -5
        temp-= this_player()->wis()/10; // -5 ?
        temp-= MASTERY_D->query_mastery("Power of the mind",this_player())/10;

        // 15
    temp=temp/2;
        if(temp > 50)temp = 50;
        if(temp < 5)temp = 5;

        return temp;
}



void attack(object a,object d) {

int dam,temp;

/*if(!attacker)
*/
attacker = a; //attacker ob ei ole aina declaroitu (monsu kuollut tms) ++Celtron
        //Expanded mindilla pystyy tappamaan korkeintaan limit + 7 levelisi^D monsuja
        if(d->query_level() > TARGET_LVL_LIMIT + (MASTERY_D->query_mastery("Expanded mind",a)+10)/15) {
                tell_object(attacker,d->query_name()+"'s mind is too powerful and beyond your powers!\n");
                return;
        }
    if(attacker->query_haste()) {
        write("You can't concentrade enough in mental combat because of that haste.\n");
        return;
    }

        if(d->query_undead()) {
                tell_object(attacker,"Your enemy is an undead and therefore beyond your powers!\n");
                if(!random(UNDEAD_STUN)) {
                        tell_object(attacker,"You forgot the fact that undeads doesnt have mind to affect and lost some of your mental energy!\n");
                        attacker->reduce_sp(100);
                }
                else {
                tell_object(attacker,"Luckily you are able to withdrawn your attack.\n");
                }

                return;
        }

        temp = get_psi_cost();

        if(a->PSI_IMEE_ATILTA < temp) {
                tell_object(attacker,"You dont have enough mental strength to complete this attack.\n");
                return;
        }
        a->PSI_IMEE_ATILTA_REDUCE;
        calc_values(a,d);
        dam = calc_dam();
        if(dam == 0) {
                tell_object(attacker,"You lost your mental stability for a second and fail to attack.\n");
                        /*if(!random(FAIL_STUN)) {
                        tell_object(attacker,def_name+"'s mind is too strong and you get stunned!\n");
                        attacker->set_stunned(random(FAIL_STUN_AMOUNT)+1);
                }*/

                return;
        }
        write_messages(dam);
        if(defender->PSI_IMEE_DEFULTA < dam) dam = defender->PSI_IMEE_DEFULTA;
        if(dam > (defender->PSI_IMEE_DEFULTA_MAX/2))dam = defender->PSI_IMEE_DEFULTA_MAX/2;
        if(defender->PSI_IMEE_DEFULTA >= 1) {
                defender->PSI_IMEE_DEFULTA_REDUCE;
        }

        // SPECIAL - DISRUPT
        if(defender->PSI_IMEE_DEFULTA > 1) {
                        if(defender->query_use_skill() || defender->query_spell()) {
                        temp = BASE_DISRUPT;
                        temp -= (attacker->query_skills("mental disrupt")/10); // 10
                        temp -= (attacker->query_skills("knowledge of mind")/10); //10

                        temp += (defender->query_skills("mental block")/10); //10

                        if(!random(temp)) {
                                tell_object(attacker,"You manage to disturp "+def_name+"'s concentration!\n");
                                tell_object(defender,att_name+" disturps your concentration!\n");
                                if(defender->query_use_skill())defender->query_use_skill()->interrupt_skill();
                                else if(defender->query_spell())defender->query_spell()->interrupt_spell();
                        }
                }
        }

        // target is mentally exhausted (sp < 1)
        if(defender->PSI_IMEE_DEFULTA < 1 && defender->query_npc()) {

        //pient^D stunnitunee med +level. ++Celtron
                temp = BASE_DEATH_CHANCE+defender->query_level();
                temp -= attacker->query_skills("overload brain")/20;
                if(defender->query_stun())temp -= 20;

                temp = random(temp)+1;

        // instadeath is usually too easy to abuse without strict level limits. ++Celtron
                if(!random(temp) && defender->query_level() < 25) {
                        tell_object(attacker, def_name+" is mentally exhausted and you manage to rip "+defender->query_possessive()+" brains apart!\n");
                        tell_object(defender, att_name+" totally rips apart your brains!\n");
                        defender->death();
                        return;
                }

        // let's give the mob a chance to recover from the stun, ok?
                else if(!defender->query_stun() && random(temp) < 10) {
                        tell_object(attacker, def_name+" is mentally exhausted and you manage to rip "+defender->query_possessive()+" mind apart stunning "+defender->query_objective()+" completely!\n");
                        tell_object(defender, att_name+" totally rips apart your mind!\n");
                        defender->set_stunned(random(SPECIAL_STUN_AMOUNT)+3);

                        defender->set_sp(defender->PSI_IMEE_DEFULTA/2);
                }

        }
       MASTERY_D->mastery("Expanded mind",a,d);
return;
}
