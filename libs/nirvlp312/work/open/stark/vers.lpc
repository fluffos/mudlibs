inherit "/obj/monster";

#include "/players/stark/defs.h"

void reset(int arg)
{
    int s;
    s = random(2);
    if (arg) return;
    ::reset();
    set_name("student");
    set_short((s ? "Male" : "Female") + " Student");
    set_alias(lower_case(short_desc));
    set_gender(s ? "male" : "female");
    set_level(10);
    set_hp(130+random(40));
    set_al(0);
    set_wc(13+random(2));
    set_ac(7+random(2));
    set_no_clean(1);
    set_aggressive(0);
    set_chat_chance(3);
    load_chat("The student studies over a book.\n");
    load_chat("The student looks at you and smiles.\n");
    load_chat("The student waves to friend off in the distance\n");
    set_a_chat_chance(5);
    load_a_chat("The student calls for help!\n");
    load_a_chat("The student tries to run but fails!\n");
    set_long( s ? (
"   This is a male student of Ohtori Academy.  He is wearing a black\n"+
"jacket that buttons tightly up the front.  He is wearing a matching\n"+
"pair of black pants.  He seems to be in a rush to get to somewhere.\n") : 
(
"   This is a female student of Ohtori Academy.  She wears the school's \n"+
"traditional fuku (uniform):  A white blouse with fluffy sleeves tucked \n"+
"neatly into a green and white pleated skirt, knee high socks and a big \n"+
"red bow tied at her neck.  She seems lost in thought.\n")
 );
    set_dead_ob(this_object());
}
