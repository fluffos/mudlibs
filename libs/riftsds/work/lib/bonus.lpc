#include <lib.h>
#include ROOMS_H

inherit LIB_ITEM;

int SetBonuses();

mapping Skills = ([]);
mapping Stats = ([]);
mapping Points = ([]);
int Duration = 15;
string bonusname;
object whom;

void create(){
    item::create();
    AddSave( ({ "Skills", "Stats", "Points", "Duration", "bonusname" }) );
    SetInvis(1);
    SetId("bonus_object");
    SetShort("bonus");
    SetLong("A bonus");
}

void init(){
    item::init();
    set_heart_beat(1);
    if(environment(this_object()) && living(environment(this_object()))) 
        SetBonuses();
}

void heart_beat(){
    if(Duration){
        Duration--;
        //tc(identify(this_object())+" Duration: "+Duration);
    }
    else {
        //tc("destructing "+identify(this_object()));
        this_object()->eventDestruct();
    }
    if(whom && environment() != whom){
        //tc("No longer on "+identify(whom)+", destructing","red");
        this_object()->eventDestruct();
    }
}

mapping SetStats(mapping arg){
    Stats = copy(arg);
    if(environment(this_object()) && living(environment(this_object())))
        SetBonuses();
    return copy(Stats);
}

mapping GetStats(){
    return copy(Stats);
}

mapping SetSkills(mapping arg){
    Skills = copy(arg);
    return copy(Skills);
}

mapping GetSkills(){
    return copy(Skills);
}

mapping SetPoints(mapping arg){
    Points = copy(arg);
    return copy(Points);
}

mapping GetPoints(){
    return copy(Points);
}

int SetBonusDuration(int i){
    Duration = i;
}

int AddBonusDuration(int i){
    Duration += i;
    if(Duration < 0) Duration = 0;
    return Duration;
}

int GetBonusDuration(){
    return Duration;
}

int SetBonuses(){
    whom = environment();
    //tc("setting bonuses","yellow");
    if(!whom || ! living(whom)) return 0;
    //tc("whom: "+identify(whom));
    if(sizeof(Stats))
        foreach(string key, int val in Stats){
            //tc(key + " " +val, "green");
            whom->AddStatBonus(key, val);
        }
    if(sizeof(Skills))
        foreach(string key, int val in Skills){
            whom->AddSkillBonus(key, val);
        }
    if(sizeof(Points))
        foreach(string key, int val in Points){
            //tc(key + " " +val, "cyan");
            switch(key){
                case "HP" : whom->AddHP(val);break;
                case "XP" : whom->AddExperiencePoints(val);break;
                case "SP" : whom->AddStaminaPoints(val);break;
                case "MP" : whom->AddPPE(val);break;
                case "poison" : whom->AddPoison(val);break;
                case "caffeine" : whom->AddCaffeine(val);break;
                case "food" : whom->AddFood(val);break;
                case "drink" : whom->AddDrink(val);break;
                default : break;
            }
        }
    return 1;
}

int RemoveBonuses(){
    if(!whom && environment()) whom = environment();
    if(!whom || !living(whom)) return 0;
    if(sizeof(Stats))
        foreach(string key, int val in Stats){
            whom->RemoveStatBonus(key);
        }
    if(sizeof(Skills))
        foreach(string key, int val in Skills){
            whom->RemoveSkillBonus(key);
        }
    return 1;
}

int eventMove(mixed dest){
    int ret;
    //tc("moving "+identify(this_object())+" from "+identify(environment()));
    if(whom && environment() == whom){
        //tc("removing bonuses from "+identify(whom),"white");
        RemoveBonuses();
        whom = 0;
    }
    ret = ::eventMove(dest);
    //tc("current location: "+identify(environment()));
    return ret;
}

int eventDestruct(){
    if(!valid_event(previous_object(), this_object())) return 0;
    this_object()->eventMove(ROOM_FURNACE);
    return ::eventDestruct();
}

string GetBonusName(){
    return bonusname;
}

string SetBonusName(string name){
    return bonusname = name;
}

mixed CanGet(object who){ return 0; }
mixed CanGive(object who){ return 0; }
mixed CanSell(object who){ return 0; }
mixed CanDrop(object who){ return 0; }
mixed CanPut(object who){ return 0; }
