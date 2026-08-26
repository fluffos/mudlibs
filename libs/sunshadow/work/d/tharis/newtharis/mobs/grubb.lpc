#include <std.h>
inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("grubb");
    set_id( ({ "grubb", "Grubb","barkeep" }) );
    set_short("%^RESET%^%^C167%^Grubb%^RESET%^%^C130%^, spitmaster of the %^RESET%^%^C088%^T%^C124%^u%^C160%^r%^C196%^n%^C202%^i%^C124%^n%^RESET%^%^C088%^g S%^RESET%^%^C124%^p%^C160%^i%^RESET%^%^C088%^t%^CRST%^");
    set("aggressive", 0);
    set_level(12);
    set_long("%^RESET%^%^C130%^This %^RESET%^%^C107%^dumpy %^RESET%^%^C130%^looking little %^RESET%^%^C167%^reptile %^RESET%^%^C130%^is an enigma for his kind; where most are %^RESET%^%^C167%^s%^C174%^l%^C181%^i%^RESET%^%^C188%^g%^RESET%^%^C174%^h%^C167%^t%^RESET%^%^C130%^, %^RESET%^%^C076%^c%^C077%^u%^C078%^n%^C079%^n%^C078%^i%^C077%^n%^C076%^g%^RESET%^%^C130%^, and %^RESET%^%^C088%^m%^C124%^a%^C160%^l%^C124%^i%^C088%^c%^C124%^i%^C160%^o%^C124%^u%^C088%^s%^RESET%^%^C130%^, this little fellow is round and %^RESET%^%^C220%^j%^C226%^o%^v%^RESET%^%^C227%^i%^C226%^a%^RESET%^%^C220%^l%^RESET%^%^C130%^, garbed in what once may have been %^RESET%^%^C231%^chef's finery%^RESET%^%^C130%^. While on a normal man his %^RESET%^%^C015%^white coat %^RESET%^%^C130%^would appear %^RESET%^%^C241%^d%^C255%^a%^C250%^p%^C241%^p%^RESET%^%^C255%^e%^RESET%^%^C250%^r%^RESET%^%^C130%^, the diminutive stature of this kobold leaves it looking unquestionably tragic, as though a particularly ugly child were playing dress-up. The %^RESET%^%^C015%^hat%^RESET%^%^C130%^, likely once refined, is now %^RESET%^%^C108%^stained %^RESET%^%^C130%^and too large for the kobold, often falling over one of his beady, %^RESET%^%^C131%^incarnadine eyes%^RESET%^%^C130%^. His %^RESET%^%^C124%^bl%^C160%^oo%^RESET%^%^C124%^d%^RESET%^%^C130%^-%^RESET%^%^C088%^s%^RESET%^%^C124%^p%^C160%^a%^RESET%^%^C196%^t%^RESET%^%^C160%^t%^C124%^e%^RESET%^%^C088%^r%^RESET%^%^C124%^e%^C160%^d %^RESET%^%^C058%^apron %^RESET%^%^C130%^drags along the ground, creating a clownish aesthetic for what is normally a dangerous little beast. Happily %^RESET%^%^C230%^c%^C231%^h%^C015%^i%^RESET%^%^C231%^t%^C230%^t%^C231%^e%^RESET%^%^C015%^r%^C231%^i%^RESET%^%^C230%^n%^RESET%^%^C231%^g %^RESET%^%^C130%^away, he wields a %^RESET%^%^C249%^meat cleaver %^RESET%^%^C130%^in each hand, and his %^RESET%^%^C167%^knobby tail %^RESET%^%^C130%^undulates behind him as he moves from spit to spit, turning the %^RESET%^%^C124%^m%^C160%^e%^C196%^a%^RESET%^%^C124%^t %^RESET%^%^C130%^and carving great %^RESET%^%^C094%^chunks %^RESET%^%^C130%^from the carcasses with gusto!%^CRST%^");
    set_gender("male");
    set_alignment (1);
    set_race("kobold");
    set_hp(300);
    add_money("gold", random(200));
    set_body_type("kobold");
    set_currency("silver");
    set_menu(
        ({
	     "fire roasted nuts","tharisian dark lager","verbonese ale","traveler's meal","spit turned meat","cravnarian wine", "mushroom wine","water",
        }),
        ({ "food", "alcoholic", "alcoholic","food","food","alcoholic", "alcoholic","soft drink",}),
        ({ 30, 30, 15, 15, 20, 25, 100, 10,})
    );
    set_my_mess(
        ({
       "%^RESET%^%^C144%^You crunch the %^RESET%^%^C088%^r%^C124%^o%^C160%^a%^C196%^s%^C160%^t%^C124%^e%^RESET%^%^C088%^d %^RESET%^%^C094%^nuts %^RESET%^%^C144%^as you chew.%^CRST%^",
       "%^RESET%^%^C144%^You drink the extremely %^RESET%^%^C241%^dark lager %^RESET%^%^C144%^and feel it roll down your throat.%^CRST%^",
       "%^RESET%^%^C144%^You drink the %^RESET%^%^C136%^g%^C220%^o%^C226%^l%^C227%^d%^C220%^e%^RESET%^%^C136%^n ale %^RESET%^%^C144%^and wince at the slight bite it offers back.%^CRST%^",
       "%^RESET%^%^C144%^You eat the sparse but painfully %^RESET%^%^C078%^h%^C079%^e%^C080%^a%^C081%^l%^C080%^t%^C079%^h%^C078%^y %^RESET%^%^C144%^meal.%^CRST%^",
       "%^RESET%^%^C144%^You eat the tender well-cooked piece of %^RESET%^%^C196%^spicy meat %^RESET%^%^C144%^with %^RESET%^%^C124%^l%^C160%^u%^C196%^s%^RESET%^%^C124%^t %^RESET%^%^C144%^and %^RESET%^%^C037%^v%^C044%^i%^C051%^g%^RESET%^%^C044%^o%^C037%^r%^RESET%^%^C144%^.%^CRST%^",
       "%^RESET%^%^C144%^You throw back the %^RESET%^%^C088%^r%^C124%^e%^C088%^d t%^RESET%^%^C124%^i%^C160%^n%^C124%^t%^C088%^e%^RESET%^%^C124%^d wine%^RESET%^%^C144%^.%^CRST%^",
       "%^RESET%^%^C144%^An acquired taste, this beverage is light and %^RESET%^%^C087%^a%^C051%^i%^C045%^r%^RESET%^%^C087%^y %^RESET%^%^C144%^with a %^RESET%^%^C005%^sweet%^RESET%^%^C144%^, subtly %^RESET%^%^C094%^spiced %^RESET%^%^C144%^boquet and a faintly %^RESET%^%^C059%^f%^C102%^u%^C101%^n%^C145%^g%^RESET%^%^C102%^a%^C059%^l %^RESET%^%^C144%^aftertaste.%^CRST%^",
       "%^RESET%^%^C144%^You gulp down the lukewarm %^RESET%^%^C039%^w%^C045%^a%^C051%^t%^C045%^e%^C039%^r%^RESET%^%^C144%^. It has a distinctly %^RESET%^%^C251%^m%^C249%^i%^C252%^n%^C248%^e%^C253%^r%^C247%^a%^RESET%^%^C254%^l %^RESET%^%^C144%^taste to it.%^CRST%^",
        })
    );
    set_your_mess(
        ({
          "%^RESET%^%^C144%^crunches on some %^RESET%^%^C094%^nuts%^RESET%^%^C144%^.%^CRST%^",
	      "%^RESET%^%^C144%^pours the thick %^RESET%^%^C241%^dark brew %^RESET%^%^C144%^down their %^RESET%^%^C144%^gullet.%^CRST%^",
	      "%^RESET%^%^C144%^drinks the %^RESET%^%^C136%^g%^C220%^o%^C226%^l%^C227%^d%^C220%^e%^RESET%^%^C136%^n ale %^RESET%^%^C144%^slowly.%^CRST%^",
	      "%^RESET%^%^C144%^eats the sparse yet %^RESET%^%^C078%^h%^C079%^e%^C080%^a%^C081%^l%^C080%^t%^C079%^h%^C078%^y %^RESET%^%^C144%^looking meal.%^CRST%^",
          "%^RESET%^%^C144%^tears into the fragrant %^RESET%^%^C088%^m%^C124%^e%^C160%^a%^RESET%^%^C088%^t %^RESET%^%^C144%^fresh from the spit.%^CRST%^",
	      "%^RESET%^%^C144%^gulps down the %^RESET%^%^C088%^r%^C124%^e%^C088%^d t%^RESET%^%^C124%^i%^C160%^n%^C124%^t%^C088%^e%^RESET%^%^C124%^d wine %^RESET%^%^C144%^.%^CRST%^",
          "%^RESET%^%^C144%^inhales the delicate bouquet, their eyes closing before they sip their %^RESET%^%^C005%^drink %^RESET%^%^C144%^daintily, savouring it with evident relish!%^CRST%^",
          "%^RESET%^%^C144%^gulps down the lukewarm %^RESET%^%^C039%^w%^C045%^a%^C051%^t%^C045%^e%^C039%^r%^RESET%^%^C144%^.%^CRST%^",
        })
    );
    set_menu_short(
        ({
          "%^RESET%^%^C088%^F%^C124%^i%^C160%^r%^RESET%^%^C088%^e %^RESET%^%^C088%^r%^C124%^o%^C160%^a%^C196%^s%^C160%^t%^C124%^e%^RESET%^%^C088%^d %^RESET%^%^C094%^Nuts%^CRST%^",
	      "%^RESET%^%^C241%^Tharisian %^RESET%^%^C240%^Dark Lager%^CRST%^",
	      "%^RESET%^%^C136%^V%^C220%^e%^C226%^r%^C227%^b%^C228%^o%^C227%^n%^C226%^e%^C220%^s%^RESET%^%^C136%^e Ale%^CRST%^",
	      "%^RESET%^%^C144%^Traveler's %^RESET%^%^C078%^M%^C079%^e%^C080%^a%^RESET%^%^C078%^l%^CRST%^",
   	      "%^RESET%^%^C144%^Spit Turned %^RESET%^%^C088%^M%^C124%^e%^C160%^a%^C088%^t%^CRST%^",
	      "%^RESET%^%^C088%^C%^C124%^r%^C160%^a%^C196%^v%^C160%^n%^C124%^a%^C088%^r%^C124%^i%^C160%^a%^RESET%^%^C124%^n Wine%^CRST%^",
          "%^RESET%^%^C059%^M%^C102%^u%^C145%^s%^RESET%^%^C102%^h%^C059%^r%^RESET%^%^C102%^o%^C145%^o%^RESET%^%^C102%^m %^RESET%^%^C059%^W%^RESET%^%^C102%^i%^C145%^n%^RESET%^%^C059%^e%^CRST%^",
          "%^RESET%^%^C039%^W%^C045%^a%^C051%^t%^C045%^e%^C039%^r%^CRST%^",
        })
    );
    set_menu_long(
        ({
       "%^RESET%^%^C144%^This is a small %^RESET%^%^C015%^bowl %^RESET%^%^C144%^of various %^RESET%^%^C088%^r%^C124%^o%^C160%^a%^C196%^s%^C160%^t%^C124%^e%^RESET%^%^C088%^d %^RESET%^%^C094%^nuts %^RESET%^%^C144%^.",
       "%^RESET%^%^C144%^This is a very dark, nearly %^RESET%^%^C240%^black%^RESET%^%^C144%^, brew famous to Tharis. It is so thick it doesn't even slosh in the glass, instead seeming to %^RESET%^%^C240%^o%^C241%^o%^C242%^z%^C243%^e%^RESET%^%^C144%^.%^CRST%^",
       "%^RESET%^%^C144%^This is the %^RESET%^%^C136%^g%^C220%^o%^C226%^l%^C227%^d%^C220%^e%^RESET%^%^C136%^n ale %^RESET%^%^C144%^imported from the city of Verbobone.%^CRST%^",
       "%^RESET%^%^C144%^This is a well packaged little meal made of more nutritious stuffs like %^RESET%^%^C094%^nuts%^RESET%^%^C144%^, %^RESET%^%^C052%^b%^C053%^e%^C054%^r%^RESET%^%^C055%^r%^C054%^i%^C053%^e%^C052%^s%^RESET%^%^C144%^, and %^RESET%^%^C220%^c%^C226%^h%^C227%^e%^C228%^e%^C226%^s%^RESET%^%^C220%^e %^RESET%^%^C144%^for the active traveler.%^CRST%^",
       "%^RESET%^%^C144%^This is a grand hunk of %^RESET%^%^C136%^s%^C178%^i%^C220%^z%^C226%^z%^RESET%^%^C227%^l%^C220%^i%^C178%^n%^RESET%^%^C136%^g%^RESET%^%^C144%^, well spiced meat from the spit at the Turning Spit Tavern.%^CRST%^",
       "%^RESET%^%^C144%^This is a slender glass of imported %^RESET%^%^C124%^w%^C160%^i%^C196%^n%^RESET%^%^C124%^e %^RESET%^%^C144%^from the legendary city of Cravnari, the sister city to Tharis to the south of the mountains.%^CRST%^",
       "%^RESET%^%^C144%^Served in a perfectly %^RESET%^%^C195%^clear%^RESET%^%^C144%^, high stemmed glass with a delicately fluted bowl, this beverage appears to be rather strange; its %^RESET%^%^C005%^deep purple %^RESET%^%^C144%^coloration periodically %^RESET%^%^C231%^s%^C189%^h%^C183%^i%^C231%^m%^RESET%^%^C153%^m%^C117%^e%^RESET%^%^C231%^r%^C147%^s %^RESET%^%^C144%^as %^RESET%^%^C053%^b%^C054%^u%^C055%^b%^RESET%^%^C054%^b%^C053%^l%^C054%^e%^C055%^s %^RESET%^%^C144%^float to the surface, tickling the nose of any who inhale them.%^CRST%^",
       "%^RESET%^%^C144%^This glass of %^RESET%^%^C039%^w%^C045%^a%^C051%^t%^C045%^e%^C039%^r %^RESET%^%^C144%^isn't exactly crystal clear, tiny %^RESET%^%^C250%^m%^C253%^o%^C255%^t%^C253%^e%^RESET%^%^C250%^s %^RESET%^%^C144%^of something floating in the lukewarm liquid.%^CRST%^",
        })
    );
    set_emotes(3,({
    "%^RESET%^%^C143%^A %^RESET%^%^C241%^fly b%^RESET%^%^C242%^u%^C243%^z%^C244%^z%^C242%^e%^RESET%^%^C241%^s %^RESET%^%^C143%^near one of the %^RESET%^%^C094%^carcasses%^RESET%^%^C143%^. With a %^RESET%^%^C088%^v%^C124%^i%^C160%^c%^RESET%^%^C196%^i%^C160%^o%^C124%^u%^RESET%^%^C088%^s s%^RESET%^%^C124%^n%^RESET%^%^C160%^a%^C124%^r%^RESET%^%^C088%^l%^RESET%^%^C143%^, Grubb smacks it with the flat of one of his %^RESET%^%^C249%^cleavers%^RESET%^%^C143%^. He looks around slyly before %^RESET%^%^C174%^licking %^RESET%^%^C143%^the %^RESET%^%^C150%^g%^C149%^u%^RESET%^%^C148%^t%^RESET%^%^C150%^s %^RESET%^%^C143%^off the knife.%^CRST%^",
    "%^RESET%^%^C167%^Grubb shaves a few pieces of %^RESET%^%^C130%^rothe haunch %^RESET%^%^C167%^onto a plate, tossing it unceremoniously onto the counter. A waitress collects the order and brings it to a table of %^RESET%^%^C178%^d%^C220%^r%^C226%^u%^C227%^n%^C226%^k%^RESET%^%^C220%^e%^C178%^n s%^RESET%^%^C220%^a%^C226%^i%^C227%^l%^C226%^o%^C220%^r%^RESET%^%^C178%^s%^RESET%^%^C167%^.%^CRST%^",
    "%^RESET%^%^C136%^A %^RESET%^%^C124%^r%^C160%^o%^C196%^a%^RESET%^%^C124%^r %^RESET%^%^C136%^of %^RESET%^%^C124%^laughter %^RESET%^%^C136%^erupts from a nearby %^RESET%^%^C094%^table %^RESET%^%^C136%^after a patron %^RESET%^%^C168%^p%^C169%^i%^C170%^n%^C171%^c%^RESET%^%^C170%^h%^C169%^e%^RESET%^%^C168%^s %^RESET%^%^C136%^the rear of a nearby waitress and she returns the favor by upending his %^RESET%^%^C220%^ale %^RESET%^%^C136%^over his head, leaving him %^RESET%^%^C220%^s%^C221%^p%^C222%^u%^C223%^t%^C222%^t%^C221%^e%^C220%^r%^C221%^i%^RESET%^%^C222%^n%^C223%^g%^RESET%^%^C136%^.%^CRST%^",
    "\"%^RESET%^%^C131%^Mmm... musshroom wine issss good. Iss from the Sihe'di'Ilthquent'sss private cellarss!%^CRST%^\" %^RESET%^%^C031%^h%^C037%^i%^C038%^s%^C044%^s%^C037%^e%^RESET%^%^C031%^s %^RESET%^%^C137%^Grubb, rubbing his little %^RESET%^%^C167%^belly %^RESET%^%^C137%^and %^RESET%^%^C148%^b%^C149%^e%^C150%^l%^RESET%^%^C143%^c%^RESET%^%^C142%^h%^C150%^i%^C149%^n%^RESET%^%^C148%^g %^RESET%^%^C137%^grotesquely.%^CRST%^",}), 0);
} 

