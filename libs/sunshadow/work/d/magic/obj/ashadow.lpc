// shadow double creature
#include <std.h>
#define SAVE_DIR = "/d/magic/obj/save/"
inherit "/d/magic/obj/aobject";

object thing, caster;
int mylevel;

void create(){
    ::create();
    set_name("shadow");
    set_id(({"shadow","figure","shadowy figure","summoned monster"}));
    set_long("%^RESET%^%^C244%^This %^RESET%^%^C241%^s%^C242%^h%^C243%^a%^C244%^d%^C243%^o%^C242%^w%^RESET%^%^C241%^y b%^RESET%^%^C242%^e%^C243%^i%^C242%^n%^RESET%^%^C241%^g %^RESET%^%^C244%^is at times difficult to see, even moreso in %^RESET%^%^C240%^darkness%^RESET%^%^C244%^. Its features are hard to discern, other than the %^RESET%^%^C088%^g%^C124%^l%^C160%^o%^C196%^w%^C160%^i%^C124%^n%^RESET%^%^C088%^g e%^RESET%^%^C124%^y%^C196%^e%^RESET%^%^C088%^s%^RESET%^%^C244%^ that peer forth like twin %^RESET%^%^C124%^embers %^RESET%^%^C244%^left to %^RESET%^%^C124%^b%^C196%^u%^C202%^r%^RESET%^%^C124%^n %^RESET%^%^C244%^within a bed of %^RESET%^%^C240%^dead coals%^RESET%^%^C244%^. There is something %^RESET%^%^C240%^u%^C241%^n%^C242%^s%^C243%^e%^C244%^t%^C243%^t%^C242%^l%^C241%^i%^C240%^n%^C241%^g%^C242%^l%^C243%^y %^RESET%^%^C244%^familiar about its features that you can't quite make out...%^CRST%^");
    set_short("%^RESET%^%^C244%^A %^RESET%^%^C241%^s%^C242%^h%^C243%^a%^C244%^d%^C243%^o%^C242%^w%^RESET%^%^C241%^y %^RESET%^%^C244%^figure%^RESET%^");
    set_alignment(5);
    set("magic",1);
    set_body_type("humanoid");
    set_race("shadow");
    set_size(2);
    
    set_funcs(({"my_special"}));
    set_func_chance(20);
}

void my_special(object target){
    if(!objectp(target)) return;

    tell_object(target, "%^RESET%^%^C244%^With a %^RESET%^%^C015%^menacing grin%^RESET%^%^C244%^, the %^RESET%^%^C241%^s%^C242%^h%^C243%^a%^C244%^d%^C242%^o%^C241%^w %^RESET%^%^C244%^darts toward you, its wicked claws %^RESET%^%^C088%^s%^C124%^l%^C160%^a%^C124%^s%^C088%^h%^C124%^i%^C160%^n%^C124%^g %^RESET%^%^C244%^at your own shadow, searing your %^RESET%^%^C231%^s%^C225%^o%^C195%^u%^RESET%^%^C231%^l %^RESET%^%^C244%^with the %^C051%^c%^C087%^h%^C159%^i%^C087%^l%^C051%^l %^RESET%^%^C244%^of the %^RESET%^%^C240%^void%^RESET%^%^C244%^.%^CRST%^");

    tell_room(ETO,"%^RESET%^%^C244%^With a %^RESET%^%^C015%^menacing grin%^RESET%^%^C244%^, the %^RESET%^%^C241%^s%^C242%^h%^C243%^a%^C244%^d%^C242%^o%^C241%^w darts toward "+capitalize(target->QCN)+" %^RESET%^%^C088%^s%^C124%^l%^C160%^a%^C124%^s%^C088%^h%^C124%^i%^C160%^n%^C124%^g %^RESET%^%^C244%^at their shadow with its wicked claws!%^CRST%^",target);
 
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+(mylevel*2));
    TO->remove_property("magic");
}

void die(object ob) {
    object obj;
    tell_room(ETO,"%^RESET%^%^C244%^The %^RESET%^%^C241%^s%^C242%^h%^C243%^a%^C244%^d%^C242%^o%^RESET%^%^C241%^w %^RESET%^%^C231%^s%^C189%^h%^C231%^i%^RESET%^%^C225%^m%^RESET%^%^C231%^m%^C195%^e%^C231%^r%^RESET%^%^C153%^s %^RESET%^%^C244%^and disappears%^RESET%^%^C244%^.%^CRST%^");
    if(objectp(thing)){
        if(member_array(thing,caster->query_protectors()) != -1){ 
            caster->remove_protector(thing); 
        }
        thing->move(environment(TO));

        if(sizeof(all_inventory(thing))){
            all_inventory(thing)->move(environment(thing));
        }
        thing->remove();
    }
    remove();
}

void set_mylevel(int x){
    mylevel = x;
    return;
}

