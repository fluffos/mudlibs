#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_id(({"mask","masque","jaquin's tears","ivory mask","ivory masque","tears"}));
	set_short("%^BLACK%^%^BOLD%^Jaq%^RESET%^%^MAGENTA%^u%^BLACK%^%^BOLD%^in's "+
	"T%^RESET%^%^MAGENTA%^e%^BLACK%^%^BOLD%^ars%^RESET%^");
    set_obvious_short("%^BLACK%^%^BOLD%^b%^RESET%^l%^BLACK%^%^BOLD%^ack "+
	"ivo%^RESET%^r%^BLACK%^%^BOLD%^y mas%^RESET%^q%^BLACK%^%^BOLD%^ue%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^This masque, is carved from what has the feel "+
	"and weight of %^RESET%^ivory%^BLACK%^%^BOLD%^. However unpainted, it is "+
	"jet black. Like masques worn by performers or during balls, it covers "+
	"the face entirely and ties with %^RESET%^%^MAGENTA%^purple silk "+
	"ribbons%^BLACK%^%^BOLD%^ behind the head. The front of the masque is "+
	"carved into quite possibly the %^RESET%^most sorrowsome%^BLACK%^%^BOLD%^ "+
	"woman's face you have ever seen. A single tear of %^RESET%^%^BOLD%^dia"+
	"m%^CYAN%^o%^WHITE%^nd%^BLACK%^%^BOLD%^ is insert below the right eye. "+
	"You sense there must be more to this masque then simple ivory and silk "+
	"as the more you look on it, the sadder you feel.%^RESET%^");
    set_lore("%^RED%^A twin to the iconic masque the angel Jaquin was known "+
	"for, her tears, as this masque is called was made after her lover Revan's "+
	"demise. Within this masque she placed all her sorrow and threw the mask "+
	"into the sea. It is said she waits at Revan's grave, a husk, waiting... "+
	"The masque has inspired some of the greatest bards of the land who have "+
	"held it, and several masterful tragedies can be tied to the masque "+
	"passing hands.");
    set_weight(10);
    set_value(1800);
    set_type("clothing");
    set_limbs(({"head"}));
    set_ac(0);
    set_property("enchantment",5);
    set_item_bonus("wisdom",4); 
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}

void init() {
   ::init();
   add_action("smile_func","smile");
}

int smile_func() {
     tell_object(ETO,"%^BLACK%^%^BOLD%^You find you cannot bring yourself to "+
	 "smile.%^RESET%^");
     tell_room(EETO, ""+ETOQCN+" %^BLACK%^%^BOLD%^seems to pause a moment.%^RESET%^",ETO);
    return 1;
}

int removeit() {
     tell_object(ETO,"%^BLACK%^%^BOLD%^You pull off the masque, feeling a great sadness "+
	 "lifted from you.%^RESET%^");
     tell_room(EETO,"%^BLACK%^%^BOLD%^As "+ETOQCN+" %^BLACK%^%^BOLD%^pulls off the masque, "+
	 "they seem happier.",ETO);
    return 1;
}
int wearit() {
     tell_object(ETO,"%^BLACK%^%^BOLD%^You wrap the ribbon from the masque around your head.%^RESET%^");
     tell_room(EETO,"%^BLACK%^%^BOLD%^As "+ETOQCN+" %^BLACK%^%^BOLD%^puts on the masque, they lower their head.",ETO);
    return 1;
}






