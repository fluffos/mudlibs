// Port Serith Bank - Descriptions by Khyron - Implemented by LoKi - 2022

#include <std.h>
#include "../../serakii.h"

inherit BANK;

string seas;

void create(){
	::create();
   	set_terrain( STONE_BUILDING );
   	set_travel( PAVED_ROAD );
	set_property( "indoors", 1 );
	set_property( "light", 3 );
   	set_name( "The First Bank of Port Serith" );
   	set_short( "%^C059%^The First %^C185%^Bank %^C059%^of %^C061%^Port Serith%^CRST%^" );
	set_long("A Bank");
	
    seas = season(time());
        switch(seas){

        case "summer":
        set_long("%^C230%^Upon walking into the %^C214%^Fi%^C221%^rst %^C228%^Ban%^C229%^k of Po%^C228%^rt S%^C221%^eri%^C214%^th%^C230%^, a sense of %^C231%^s%^C225%^e%^C219%^r%^C213%^e%^C231%^n%^C225%^i%^C219%^t%^C213%^y%^C230%^ sets in as a wave of %^C123%^c%^C159%^r%^C195%^i%^C123%^s%^C159%^p%^C123%^ %^C195%^a%^C123%^i%^C159%^r%^C230%^ washes over you. Acting as a moat between you and three %^C242%^te%^C248%^l%^C242%^l%^C246%^e%^C242%^r's d%^C253%^e%^C248%^s%^C242%^ks%^C230%^ are several %^C094%^c%^C136%^o%^C094%^f%^C136%^f%^C094%^ee t%^C136%^a%^C094%^bl%^C136%^e%^C094%^s%^C230%^, each surrounded by no less than %^C094%^t%^C052%^w%^C094%^o ch%^C052%^a%^C094%^irs%^C230%^. The teller's smiles are slight, but undoubtedly genuine, and they sort each person out with %^C220%^unr%^C214%^iva%^C220%^led eff%^C214%^ici%^C220%^enc%^C214%^y%^C230%^: the lines never seem to grow longer than two people. Off to the left is one %^C242%^l%^C249%^a%^C246%^r%^C242%^g%^C252%^e%^C242%^r d%^C247%^e%^C242%^sk%^C230%^ attended by a single employee, who seems to be busy with an eternities' worth of %^C231%^pa%^C255%^perwork%^C230%^, while simultaneously grouping %^C214%^c%^C220%^oi%^C226%^n%^C220%^s%^C230%^. Opposite the desk is a %^C245%^f%^C243%^i%^C240%^repla%^C243%^c%^C245%^e%^C230%^, which, at this time of year, houses a refreshing, if dangerously cold, %^C051%^a%^C087%^z%^C123%^u%^C159%^r%^C255%^e b%^C159%^l%^C123%^a%^C087%^z%^C051%^e%^C230%^.\n%^CRST%^");

        set_listen("default","%^C137%^You hear the %^C109%^l%^C073%^i%^C037%^g%^C073%^h%^C109%^t m%^C073%^u%^C037%^rm%^C073%^u%^C109%^r%^C137%^ of the bank's %^C103%^patrons%^C137%^, accompanied by the occasional %^C186%^clinks%^C137%^ of %^C214%^s%^C220%^hi%^C226%^f%^C249%^t%^C252%^in%^C255%^g%^C214%^ %^C130%^c%^C166%^oi%^C202%^ns%^C137%^.%^CRST%^");
        set_smell("default","%^C137%^Even inside, the air smells %^C051%^f%^C087%^r%^C123%^e%^C051%^s%^C087%^h%^C137%^ and %^C040%^a%^C046%^l%^C082%^i%^C118%^v%^C082%^e%^C137%^.%^CRST%^");

		
		set_items(([
		
		    ({"fireplace"}) : "%^C243%^Curiously, the fireplace rages with an %^C087%^a%^C123%^z%^C159%^u%^C195%^r%^C231%^e%^C255%^ %^C195%^g%^C159%^l%^C123%^o%^C087%^w%^RESET%^%^C243%^, providing a %^C123%^c%^C159%^h%^C195%^i%^C231%^l%^C123%^l%^C159%^y %^C195%^b%^C231%^a%^C123%^r%^C159%^r%^C195%^i%^C255%^e%^C123%^r%^RESET%^%^C243%^ against the %^C079%^m%^C151%^ug%^C079%^gy%^RESET%^%^C243%^ outside air. The mantle itself blends in perfectly with the %^C253%^st%^C251%^on%^C253%^e b%^C251%^lo%^C253%^cks%^RESET%^%^C243%^ and %^C238%^wo%^C241%^o%^C238%^d b%^C241%^o%^C238%^rd%^C241%^e%^C238%^r%^C241%^i%^C238%^ng%^RESET%^%^C243%^, as if its length was the base measure for everything else. Conveniently, %^C094%^t%^C124%^w%^C094%^o ch%^C124%^ai%^C094%^rs%^RESET%^%^C243%^ are set up to face it.%^CRST%^",
		
            ({"lights"}) : "%^C094%^The ceiling above is littered with large chunks of %^C229%^br%^C230%^ig%^C229%^h%^C228%^tl%^C229%^y gl%^C228%^ow%^C227%^i%^C228%^n%^C229%^g c%^C230%^r%^C231%^y%^C229%^stal%^RESET%^%^C094%^. If you hadn't taken the time to look, you probably would have mistaken the light for the %^C214%^s%^C220%^u%^C214%^n's o%^C221%^w%^C214%^n%^RESET%^%^C094%^. It isn't incredibly intense, but still bright and yellow enough to give the room a %^C220%^wa%^C227%^r%^C220%^m fe%^C227%^e%^C228%^l%^C220%^ing%^RESET%^%^C094%^.%^CRST%^",
			
			({"desks"}) : "%^C094%^Each of the tellers desks are kept in %^C007%^pristine condition%^RESET%^%^C094%^: there isn't a speck of dust to be seen, %^C254%^papers%^RESET%^%^C094%^ are sorted into their %^C028%^desig%^C034%^nat%^C028%^ed spa%^C034%^ce%^C028%^s%^RESET%^%^C094%^, and their %^C023%^q%^C030%^u%^C036%^i%^C043%^ll%^C030%^s%^RESET%^%^C094%^ rest gingerly in their %^C238%^ink b%^C241%^o%^C244%^t%^C238%^tl%^C241%^e%^C238%^s%^RESET%^%^C094%^.%^CRST%^",
			
			({"tables"}) : "%^C094%^The center of the room is occupied by clusters of %^C179%^tables%^RESET%^%^C094%^ and %^C179%^chairs%^RESET%^%^C094%^, likely to keep waiting patrons %^C225%^co%^C219%^mf%^C213%^or%^C207%^ta%^C213%^bl%^C219%^e%^RESET%^%^C094%^. If that IS the case, it explains their condition: they look like they've never been used at all. Still, they are dusted and %^C220%^well maintained%^RESET%^%^C094%^, if only to keep an %^C124%^ai%^C160%^r o%^C196%^f pr%^C160%^of%^C124%^es%^C088%^si%^C124%^on%^C160%^alis%^C124%^m%^RESET%^%^C094%^ about.%^CRST%^",
			
			({"large desk"}) : "%^C243%^Like a %^C238%^m%^C241%^o%^RESET%^%^C243%^n%^C238%^olith%^RESET%^%^C243%^ turned sideways, this desk sits %^C007%^dutifully%^RESET%^%^C243%^. The sheer %^C238%^solidarity%^RESET%^%^C243%^ of the perfect slab of %^C238%^bl%^C253%^a%^C249%^c%^C238%^k m%^C246%^a%^C238%^rble%^RESET%^%^C243%^ before you inspires the feeling of %^C195%^pe%^C159%^rm%^C123%^an%^C195%^en%^C159%^ce%^RESET%^%^C243%^: even if the world were to %^C088%^end%^RESET%^%^C243%^, you feel that it might make it through. Atop it lies both a load of %^C214%^c%^C220%^o%^C226%^i%^C255%^n%^C220%^s%^RESET%^%^C243%^, half sorted and %^C214%^gl%^C220%^it%^C226%^te%^C255%^r%^C226%^in%^C255%^g%^RESET%^%^C243%^. Accompanying the metals is an impressive stack of %^C255%^paperwork%^RESET%^%^C243%^, neatly arranged into a tower, with only a few sheets having fallen aside into a messier pile. The attendant of this desk seems substantially more %^C195%^f%^C123%^r%^C051%^a%^C225%^z%^C213%^z%^C201%^l%^C195%^e%^C123%^d%^RESET%^%^C243%^ than the other three, but you could probably forgive her for it, all things considered.%^CRST%^",
			
			({"walls"}) : "%^C007%^The walls of this establishment are truly something to look at: %^C238%^st%^C239%^ai%^C240%^ne%^C238%^d-b%^C239%^la%^C240%^ck%^C239%^ %^C238%^wo%^C239%^od%^C240%^ su%^C238%^pp%^C239%^or%^C240%^ts%^RESET%^%^C007%^ border squares of seamless %^C253%^wh%^C254%^it%^C255%^e s%^C252%^to%^C253%^ne%^RESET%^%^C007%^, a few of which are further divided into triangles. The only break in the veneer of the walls is provided by two sets of %^C230%^wi%^C229%^nd%^C230%^o%^C229%^ws%^RESET%^%^C007%^. The first is low, and allows passerby a view into the building, while the other runs much higher up, allowing a steady stream of %^C230%^na%^C229%^tu%^C228%^ra%^C229%^l%^C230%^ li%^C229%^gh%^C228%^t%^RESET%^%^C007%^ during the day.%^CRST%^",

			({"floor"}) : "%^C094%^The floor here is kept sh%^C136%^i%^C179%^n%^C136%^y%^RESET%^%^C094%^ and spot%^C136%^l%^C179%^e%^C136%^s%^RESET%^%^C094%^s, so much so that you can almost see yourself in it. The dark-oak selected for the job provides a nice contrast to the otherwise %^C220%^warm lighting%^RESET%^%^C094%^, and makes a distinct %^C007%^*clack*%^RESET%^%^C094%^ as feet come down against it.%^CRST%^",

        ]));

        set_door("double doors",TOWN"7","out",0);
        set_door_description("%^C094%^The double doors separating the bank from the rest of the world are comprised of %^C240%^he%^C088%^a%^C240%^vy ebo%^C088%^n%^C240%^y%^RESET%^%^C094%^ and %^C230%^stai%^C229%^ne%^C230%^d gl%^C229%^as%^C230%^s%^RESET%^%^C094%^, which would allow you to see inside, if the doors weren't kept open at this time of year.%^CRST%^");
		
    break;


        case "spring":
        set_long("%^C002%^Upon walking into the %^C214%^Fi%^C221%^rst %^C228%^Ban%^C229%^k of Po%^C228%^rt S%^C221%^eri%^C214%^th%^RESET%^%^C002%^, you are immediately submerged in its %^C037%^co%^C043%^zy,%^C037%^ ho%^C043%^m%^C050%^ey atm%^C043%^o%^C037%^sp%^C043%^he%^C037%^re%^RESET%^%^C002%^. Dotting the middle of the space are clusters of unoccupied %^C094%^chairs%^RESET%^%^C002%^ situated around low-lying %^C094%^c%^C136%^o%^C094%^ff%^C136%^e%^C094%^e t%^C136%^a%^C094%^bl%^C136%^e%^C094%^s%^RESET%^%^C002%^, beyond which three tellers occupy their posts. Their smiles are slight, but genuine, and they sort each person out with %^C220%^unr%^C214%^iva%^C220%^led eff%^C214%^ici%^C220%^enc%^C214%^y%^RESET%^%^C002%^: the lines never seem to grow longer than two people. Off to the left is one %^C242%^l%^C249%^a%^C246%^r%^C242%^g%^C252%^e%^C242%^r d%^C247%^e%^C242%^sk%^RESET%^%^C002%^ attended by a single employee, who seems to be busy with an eternities' worth of paperwork, while simultaneously grouping %^C214%^c%^C220%^oi%^C226%^n%^C220%^s%^RESET%^%^C002%^. Opposite the desk is a %^C245%^f%^C243%^i%^C240%^repla%^C243%^c%^C245%^e%^RESET%^%^C002%^, which, at this time of year, for the season remains unused, but well cleaned.\n%^CRST%^");

        set_listen("default","%^C137%^You hear the %^C109%^l%^C073%^i%^C037%^g%^C073%^h%^C109%^t m%^C073%^u%^C037%^rm%^C073%^u%^C109%^r%^C137%^ of the bank's %^C103%^patrons%^C137%^, accompanied by the occasional %^C186%^clinks%^C137%^ of %^C214%^s%^C220%^hi%^C226%^f%^C249%^t%^C252%^in%^C255%^g%^C214%^ %^C130%^c%^C166%^oi%^C202%^ns%^C137%^.%^CRST%^");
        set_smell("default","%^C137%^The air is filled with the smells of %^C249%^m%^C252%^et%^C255%^a%^C252%^l%^C137%^ and %^C094%^cof%^C136%^fe%^C094%^e%^C137%^.%^CRST%^");

		
		set_items(([
		
			({"fireplace"}) : "%^C243%^At this time of the year, the fireplace sits %^C238%^unused%^C243%^, but %^C250%^not uncleaned%^C243%^. %^C094%^Dry wood%^C243%^ still rests at the ready, and the %^C246%^p%^C249%^o%^C252%^k%^C255%^e%^C252%^r%^C243%^ is hung up above the mantle. The fixture itself is well integrated into the design of the wall, indicating the precision in planning behind the building. It fits perfectly with the pattern of %^C238%^wo%^C241%^o%^C238%^d%^C243%^ and %^C252%^st%^C249%^on%^C252%^e%^C243%^ around it.%^CRST%^",	
            ({"lights"}) : "%^C094%^The ceiling above is littered with large chunks of %^C229%^br%^C230%^ig%^C229%^h%^C228%^tl%^C229%^y gl%^C228%^ow%^C227%^i%^C228%^n%^C229%^g c%^C230%^r%^C231%^y%^C229%^stal%^RESET%^%^C094%^. If you hadn't taken the time to look, you probably would have mistaken the light for the %^C214%^s%^C220%^u%^C214%^n's o%^C221%^w%^C214%^n%^RESET%^%^C094%^. It isn't incredibly intense, but still bright and yellow enough to give the room a %^C220%^wa%^C227%^r%^C220%^m fe%^C227%^e%^C228%^l%^C220%^ing%^RESET%^%^C094%^.%^CRST%^",
			
			({"desks"}) : "%^C094%^Each of the tellers desks are kept in %^C007%^pristine condition%^RESET%^%^C094%^: there isn't a speck of dust to be seen, %^C254%^papers%^RESET%^%^C094%^ are sorted into their %^C028%^desig%^C034%^nat%^C028%^ed spa%^C034%^ce%^C028%^s%^RESET%^%^C094%^, and their %^C023%^q%^C030%^u%^C036%^i%^C043%^ll%^C030%^s%^RESET%^%^C094%^ rest gingerly in their %^C238%^ink b%^C241%^o%^C244%^t%^C238%^tl%^C241%^e%^C238%^s%^RESET%^%^C094%^.%^CRST%^",
			
			({"tables"}) : "%^C094%^The center of the room is occupied by clusters of %^C179%^tables%^RESET%^%^C094%^ and %^C179%^chairs%^RESET%^%^C094%^, likely to keep waiting patrons %^C225%^co%^C219%^mf%^C213%^or%^C207%^ta%^C213%^bl%^C219%^e%^RESET%^%^C094%^. If that IS the case, it explains their condition: they look like they've never been used at all. Still, they are dusted and %^C220%^well maintained%^RESET%^%^C094%^, if only to keep an %^C124%^ai%^C160%^r o%^C196%^f pr%^C160%^of%^C124%^es%^C088%^si%^C124%^on%^C160%^alis%^C124%^m%^RESET%^%^C094%^ about.%^CRST%^",
			
			({"large desk"}) : "%^C243%^Like a %^C238%^m%^C241%^o%^RESET%^%^C243%^n%^C238%^olith%^RESET%^%^C243%^ turned sideways, this desk sits %^C007%^dutifully%^RESET%^%^C243%^. The sheer %^C238%^solidarity%^RESET%^%^C243%^ of the perfect slab of %^C238%^bl%^C253%^a%^C249%^c%^C238%^k m%^C246%^a%^C238%^rble%^RESET%^%^C243%^ before you inspires the feeling of %^C195%^pe%^C159%^rm%^C123%^an%^C195%^en%^C159%^ce%^RESET%^%^C243%^: even if the world were to %^C088%^end%^RESET%^%^C243%^, you feel that it might make it through. Atop it lies both a load of %^C214%^c%^C220%^o%^C226%^i%^C255%^n%^C220%^s%^RESET%^%^C243%^, half sorted and %^C214%^gl%^C220%^it%^C226%^te%^C255%^r%^C226%^in%^C255%^g%^RESET%^%^C243%^. Accompanying the metals is an impressive stack of %^C255%^paperwork%^RESET%^%^C243%^, neatly arranged into a tower, with only a few sheets having fallen aside into a messier pile. The attendant of this desk seems substantially more %^C195%^f%^C123%^r%^C051%^a%^C225%^z%^C213%^z%^C201%^l%^C195%^e%^C123%^d%^RESET%^%^C243%^ than the other three, but you could probably forgive her for it, all things considered.%^CRST%^",
			
			({"walls"}) : "%^C007%^The walls of this establishment are truly something to look at: %^C238%^st%^C239%^ai%^C240%^ne%^C238%^d-b%^C239%^la%^C240%^ck%^C239%^ %^C238%^wo%^C239%^od%^C240%^ su%^C238%^pp%^C239%^or%^C240%^ts%^RESET%^%^C007%^ border squares of seamless %^C253%^wh%^C254%^it%^C255%^e s%^C252%^to%^C253%^ne%^RESET%^%^C007%^, a few of which are further divided into triangles. The only break in the veneer of the walls is provided by two sets of %^C230%^wi%^C229%^nd%^C230%^o%^C229%^ws%^RESET%^%^C007%^. The first is low, and allows passerby a view into the building, while the other runs much higher up, allowing a steady stream of %^C230%^na%^C229%^tu%^C228%^ra%^C229%^l%^C230%^ li%^C229%^gh%^C228%^t%^RESET%^%^C007%^ during the day.%^CRST%^",

			({"floor"}) : "%^C094%^The floor here is kept sh%^C136%^i%^C179%^n%^C136%^y%^RESET%^%^C094%^ and spot%^C136%^l%^C179%^e%^C136%^s%^RESET%^%^C094%^s, so much so that you can almost see yourself in it. The dark-oak selected for the job provides a nice contrast to the otherwise %^C220%^warm lighting%^RESET%^%^C094%^, and makes a distinct %^C007%^*clack*%^RESET%^%^C094%^ as feet come down against it.%^CRST%^",

        ]));

        set_door("double doors",TOWN"7","out",0);
        set_door_description("%^C094%^The double doors separating the bank from the rest of the world are comprised of %^C240%^he%^C088%^a%^C240%^vy ebo%^C088%^n%^C240%^y%^RESET%^%^C094%^ and %^C230%^stai%^C229%^ne%^C230%^d gl%^C229%^as%^C230%^s%^RESET%^%^C094%^, which would allow you to see inside, if the doors weren't kept open at this time of year.%^CRST%^");
		
    break;



    case "winter":
        set_long("%^C006%^Upon walking into the %^C214%^Fi%^C221%^rst %^C228%^Ban%^C229%^k of Po%^C228%^rt S%^C221%^eri%^C214%^th%^RESET%^%^C006%^, your appendages %^C123%^q%^C159%^u%^C195%^ic%^C231%^kl%^C230%^y%^C123%^ %^C229%^t%^C222%^h%^C221%^a%^C214%^w%^RESET%^%^C006%^, leaving you feeling %^C214%^r%^C220%^a%^C227%^t%^C214%^h%^C220%^e%^C227%^r%^C214%^ l%^C220%^i%^C227%^m%^C214%^b%^C220%^e%^C227%^r%^RESET%^%^C006%^. Dotting the middle of the space are clusters of unoccupied %^C094%^chairs%^RESET%^%^C006%^ situated around low-lying %^C094%^c%^C136%^o%^C094%^ff%^C136%^e%^C094%^e t%^C136%^a%^C094%^bl%^C136%^e%^C094%^s%^RESET%^%^C006%^, beyond which three tellers occupy their posts. Their smiles are slight, but genuine, and they sort each person out with %^C220%^unr%^C214%^iva%^C220%^led eff%^C214%^ici%^C220%^enc%^C214%^y%^RESET%^%^C006%^: the lines never seem to grow longer than two people. Off to the left is one %^C242%^l%^C249%^a%^C246%^r%^C242%^g%^C252%^e%^C242%^r d%^C247%^e%^C242%^sk%^RESET%^%^C006%^ attended by a single employee, who seems to be busy with an eternities' worth of paperwork, while simultaneously grouping %^C214%^c%^C220%^oi%^C226%^n%^C220%^s%^RESET%^%^C006%^. Opposite the desk is a %^C245%^f%^C243%^i%^C240%^repla%^C243%^c%^C245%^e%^RESET%^%^C006%^, which, at this time of year, contains a %^C202%^t%^C208%^a%^C214%^m%^C221%^e %^C228%^b%^C221%^l%^C214%^a%^C208%^z%^C202%^e%^RESET%^%^C006%^, dutifully warding off what %^C231%^l%^C195%^it%^C159%^t%^C123%^le%^C159%^ c%^C195%^ol%^C231%^d%^RESET%^%^C006%^ finds its way through the door.\n%^CRST%^");

        set_listen("default","%^C137%^You hear the %^C109%^l%^C073%^i%^C037%^g%^C073%^h%^C109%^t m%^C073%^u%^C037%^rm%^C073%^u%^C109%^r%^C137%^ of the bank's %^C103%^patrons%^C137%^, accompanied by the occasional %^C186%^clinks%^C137%^ of %^C214%^s%^C220%^hi%^C226%^f%^C249%^t%^C252%^in%^C255%^g%^C214%^ %^C130%^c%^C166%^oi%^C202%^ns%^C137%^.%^CRST%^");
        set_smell("default","%^C137%^You smell %^C202%^w%^C208%^o%^C214%^o%^C221%^d %^C228%^b%^C231%^u%^C228%^r%^C221%^n%^C214%^i%^C208%^n%^C202%^g%^C137%^ in the %^C245%^f%^C243%^i%^C240%^repla%^C243%^c%^C245%^e%^C137%^, and the crisp smell of %^C214%^c%^C220%^o%^C255%^i%^C220%^n%^C137%^.%^CRST%^");
		
		set_items(([
		
		
	        ({"fireplace"}) : "%^C243%^Aglow with a %^C202%^pa%^C208%^ss%^C214%^io%^C221%^na%^C214%^te%^C202%^ %^C228%^am%^C221%^be%^C214%^r h%^C208%^ue%^RESET%^%^C243%^, licks of flame %^C207%^d%^C213%^a%^C219%^n%^C225%^c%^C231%^e%^RESET%^%^C243%^ within the fireplace, providing the %^C214%^h%^C208%^e%^C214%^a%^C221%^t%^C214%^ o%^C221%^f%^C214%^ li%^C208%^f%^C214%^e%^RESET%^%^C243%^ to the air inside. Their stage was clearly designed to keep in line with the rest of the wall, perfectly occupying the space of a single panel of stone. For the audience, %^C130%^t%^C124%^w%^C130%^o in%^C124%^vit%^C130%^ing ch%^C124%^ai%^C130%^rs%^RESET%^%^C243%^ have been set up across from the mantle.%^CRST%^",
			
            ({"lights"}) : "%^C094%^The ceiling above is littered with large chunks of %^C229%^br%^C230%^ig%^C229%^h%^C228%^tl%^C229%^y gl%^C228%^ow%^C227%^i%^C228%^n%^C229%^g c%^C230%^r%^C231%^y%^C229%^stal%^RESET%^%^C094%^. If you hadn't taken the time to look, you probably would have mistaken the light for the %^C214%^s%^C220%^u%^C214%^n's o%^C221%^w%^C214%^n%^RESET%^%^C094%^. It isn't incredibly intense, but still bright and yellow enough to give the room a %^C220%^wa%^C227%^r%^C220%^m fe%^C227%^e%^C228%^l%^C220%^ing%^RESET%^%^C094%^.%^CRST%^",
			
			({"desks"}) : "%^C094%^Each of the tellers desks are kept in %^C007%^pristine condition%^RESET%^%^C094%^: there isn't a speck of dust to be seen, %^C254%^papers%^RESET%^%^C094%^ are sorted into their %^C028%^desig%^C034%^nat%^C028%^ed spa%^C034%^ce%^C028%^s%^RESET%^%^C094%^, and their %^C023%^q%^C030%^u%^C036%^i%^C043%^ll%^C030%^s%^RESET%^%^C094%^ rest gingerly in their %^C238%^ink b%^C241%^o%^C244%^t%^C238%^tl%^C241%^e%^C238%^s%^RESET%^%^C094%^.%^CRST%^",
			
			({"tables"}) : "%^C094%^The center of the room is occupied by clusters of %^C179%^tables%^RESET%^%^C094%^ and %^C179%^chairs%^RESET%^%^C094%^, likely to keep waiting patrons %^C225%^co%^C219%^mf%^C213%^or%^C207%^ta%^C213%^bl%^C219%^e%^RESET%^%^C094%^. If that IS the case, it explains their condition: they look like they've never been used at all. Still, they are dusted and %^C220%^well maintained%^RESET%^%^C094%^, if only to keep an %^C124%^ai%^C160%^r o%^C196%^f pr%^C160%^of%^C124%^es%^C088%^si%^C124%^on%^C160%^alis%^C124%^m%^RESET%^%^C094%^ about.%^CRST%^",
			
			({"large desk"}) : "%^C243%^Like a %^C238%^m%^C241%^o%^RESET%^%^C243%^n%^C238%^olith%^RESET%^%^C243%^ turned sideways, this desk sits %^C007%^dutifully%^RESET%^%^C243%^. The sheer %^C238%^solidarity%^RESET%^%^C243%^ of the perfect slab of %^C238%^bl%^C253%^a%^C249%^c%^C238%^k m%^C246%^a%^C238%^rble%^RESET%^%^C243%^ before you inspires the feeling of %^C195%^pe%^C159%^rm%^C123%^an%^C195%^en%^C159%^ce%^RESET%^%^C243%^: even if the world were to %^C088%^end%^RESET%^%^C243%^, you feel that it might make it through. Atop it lies both a load of %^C214%^c%^C220%^o%^C226%^i%^C255%^n%^C220%^s%^RESET%^%^C243%^, half sorted and %^C214%^gl%^C220%^it%^C226%^te%^C255%^r%^C226%^in%^C255%^g%^RESET%^%^C243%^. Accompanying the metals is an impressive stack of %^C255%^paperwork%^RESET%^%^C243%^, neatly arranged into a tower, with only a few sheets having fallen aside into a messier pile. The attendant of this desk seems substantially more %^C195%^f%^C123%^r%^C051%^a%^C225%^z%^C213%^z%^C201%^l%^C195%^e%^C123%^d%^RESET%^%^C243%^ than the other three, but you could probably forgive her for it, all things considered.%^CRST%^",
			
			({"walls"}) : "%^C007%^The walls of this establishment are truly something to look at: %^C238%^st%^C239%^ai%^C240%^ne%^C238%^d-b%^C239%^la%^C240%^ck%^C239%^ %^C238%^wo%^C239%^od%^C240%^ su%^C238%^pp%^C239%^or%^C240%^ts%^RESET%^%^C007%^ border squares of seamless %^C253%^wh%^C254%^it%^C255%^e s%^C252%^to%^C253%^ne%^RESET%^%^C007%^, a few of which are further divided into triangles. The only break in the veneer of the walls is provided by two sets of %^C230%^wi%^C229%^nd%^C230%^o%^C229%^ws%^RESET%^%^C007%^. The first is low, and allows passerby a view into the building, while the other runs much higher up, allowing a steady stream of %^C230%^na%^C229%^tu%^C228%^ra%^C229%^l%^C230%^ li%^C229%^gh%^C228%^t%^RESET%^%^C007%^ during the day.%^CRST%^",

			({"floor"}) : "%^C094%^The floor here is kept sh%^C136%^i%^C179%^n%^C136%^y%^RESET%^%^C094%^ and spot%^C136%^l%^C179%^e%^C136%^s%^RESET%^%^C094%^s, so much so that you can almost see yourself in it. The dark-oak selected for the job provides a nice contrast to the otherwise %^C220%^warm lighting%^RESET%^%^C094%^, and makes a distinct %^C007%^*clack*%^RESET%^%^C094%^ as feet come down against it.%^CRST%^",

        ]));

        set_door("double doors",TOWN"7","out",0);
        set_door_description("%^C094%^The double doors separating the bank from the rest of the world are comprised of %^C240%^hea%^C088%^v%^C240%^y ebo%^C088%^n%^C240%^y%^RESET%^%^C094%^ and %^C230%^stai%^C229%^ne%^C230%^d gl%^C229%^as%^C230%^s%^RESET%^%^C094%^, through which you can clearly see the outside. Thankfully, they make a good %^C243%^b%^C245%^u%^C247%^l%^C243%^wa%^C248%^r%^C243%^k%^RESET%^%^C094%^ against the %^C087%^c%^C123%^o%^C159%^l%^C195%^d%^RESET%^%^C094%^ outside.%^CRST%^");
		
    break;



    case "autumn":
        set_long("%^C002%^Upon walking into the %^C214%^Fi%^C221%^rst %^C228%^Ban%^C229%^k of Po%^C228%^rt S%^C221%^eri%^C214%^th%^RESET%^%^C002%^, you are immediately submerged in its %^C037%^co%^C043%^zy,%^C037%^ ho%^C043%^m%^C050%^ey atm%^C043%^o%^C037%^sp%^C043%^he%^C037%^re%^RESET%^%^C002%^. Dotting the middle of the space are clusters of unoccupied %^C094%^chairs%^RESET%^%^C002%^ situated around low-lying %^C094%^c%^C136%^o%^C094%^ff%^C136%^e%^C094%^e t%^C136%^a%^C094%^bl%^C136%^e%^C094%^s%^RESET%^%^C002%^, beyond which three tellers occupy their posts. Their smiles are slight, but genuine, and they sort each person out with %^C220%^unr%^C214%^iva%^C220%^led eff%^C214%^ici%^C220%^enc%^C214%^y%^RESET%^%^C002%^: the lines never seem to grow longer than two people. Off to the left is one %^C242%^l%^C249%^a%^C246%^r%^C242%^g%^C252%^e%^C242%^r d%^C247%^e%^C242%^sk%^RESET%^%^C002%^ attended by a single employee, who seems to be busy with an eternities' worth of paperwork, while simultaneously grouping %^C214%^c%^C220%^oi%^C226%^n%^C220%^s%^RESET%^%^C002%^. Opposite the desk is a %^C245%^f%^C243%^i%^C240%^repla%^C243%^c%^C245%^e%^RESET%^%^C002%^, which, at this time of year, for the season remains unused, but well cleaned.\n%^CRST%^");

        set_listen("default","%^C137%^You hear the %^C109%^l%^C073%^i%^C037%^g%^C073%^h%^C109%^t m%^C073%^u%^C037%^rm%^C073%^u%^C109%^r%^C137%^ of the bank's %^C103%^patrons%^C137%^, accompanied by the occasional %^C186%^clinks%^C137%^ of %^C214%^s%^C220%^hi%^C226%^f%^C249%^t%^C252%^in%^C255%^g%^C214%^ %^C130%^c%^C166%^oi%^C202%^ns%^C137%^.%^CRST%^");
        set_smell("default","%^C137%^The air is filled with the smells of %^C249%^m%^C252%^et%^C255%^a%^C252%^l%^C137%^ and %^C094%^cof%^C136%^fe%^C094%^e%^C137%^.%^CRST%^");

		
		set_items(([
            
			({"fireplace"}) : "%^C243%^At this time of the year, the fireplace sits %^C238%^unused%^C243%^, but %^C250%^not uncleaned%^C243%^. %^C094%^Dry wood%^C243%^ still rests at the ready, and the %^C246%^p%^C249%^o%^C252%^k%^C255%^e%^C252%^r%^C243%^ is hung up above the mantle. The fixture itself is well integrated into the design of the wall, indicating the precision in planning behind the building. It fits perfectly with the pattern of %^C238%^wo%^C241%^o%^C238%^d%^C243%^ and %^C252%^st%^C249%^on%^C252%^e%^C243%^ around it.%^CRST%^",		
			
			({"lights"}) : "%^C094%^The ceiling above is littered with large chunks of %^C229%^br%^C230%^ig%^C229%^h%^C228%^tl%^C229%^y gl%^C228%^ow%^C227%^i%^C228%^n%^C229%^g c%^C230%^r%^C231%^y%^C229%^stal%^RESET%^%^C094%^. If you hadn't taken the time to look, you probably would have mistaken the light for the %^C214%^s%^C220%^u%^C214%^n's o%^C221%^w%^C214%^n%^RESET%^%^C094%^. It isn't incredibly intense, but still bright and yellow enough to give the room a %^C220%^wa%^C227%^r%^C220%^m fe%^C227%^e%^C228%^l%^C220%^ing%^RESET%^%^C094%^.%^CRST%^",
			
			({"desks"}) : "%^C094%^Each of the tellers desks are kept in %^C007%^pristine condition%^RESET%^%^C094%^: there isn't a speck of dust to be seen, %^C254%^papers%^RESET%^%^C094%^ are sorted into their %^C028%^desig%^C034%^nat%^C028%^ed spa%^C034%^ce%^C028%^s%^RESET%^%^C094%^, and their %^C023%^q%^C030%^u%^C036%^i%^C043%^ll%^C030%^s%^RESET%^%^C094%^ rest gingerly in their %^C238%^ink b%^C241%^o%^C244%^t%^C238%^tl%^C241%^e%^C238%^s%^RESET%^%^C094%^.%^CRST%^",
			
			({"tables"}) : "%^C094%^The center of the room is occupied by clusters of %^C179%^tables%^RESET%^%^C094%^ and %^C179%^chairs%^RESET%^%^C094%^, likely to keep waiting patrons %^C225%^co%^C219%^mf%^C213%^or%^C207%^ta%^C213%^bl%^C219%^e%^RESET%^%^C094%^. If that IS the case, it explains their condition: they look like they've never been used at all. Still, they are dusted and %^C220%^well maintained%^RESET%^%^C094%^, if only to keep an %^C124%^ai%^C160%^r o%^C196%^f pr%^C160%^of%^C124%^es%^C088%^si%^C124%^on%^C160%^alis%^C124%^m%^RESET%^%^C094%^ about.%^CRST%^",
			
			({"large desk"}) : "%^C243%^Like a %^C238%^m%^C241%^o%^RESET%^%^C243%^n%^C238%^olith%^RESET%^%^C243%^ turned sideways, this desk sits %^C007%^dutifully%^RESET%^%^C243%^. The sheer %^C238%^solidarity%^RESET%^%^C243%^ of the perfect slab of %^C238%^bl%^C253%^a%^C249%^c%^C238%^k m%^C246%^a%^C238%^rble%^RESET%^%^C243%^ before you inspires the feeling of %^C195%^pe%^C159%^rm%^C123%^an%^C195%^en%^C159%^ce%^RESET%^%^C243%^: even if the world were to %^C088%^end%^RESET%^%^C243%^, you feel that it might make it through. Atop it lies both a load of %^C214%^c%^C220%^o%^C226%^i%^C255%^n%^C220%^s%^RESET%^%^C243%^, half sorted and %^C214%^gl%^C220%^it%^C226%^te%^C255%^r%^C226%^in%^C255%^g%^RESET%^%^C243%^. Accompanying the metals is an impressive stack of %^C255%^paperwork%^RESET%^%^C243%^, neatly arranged into a tower, with only a few sheets having fallen aside into a messier pile. The attendant of this desk seems substantially more %^C195%^f%^C123%^r%^C051%^a%^C225%^z%^C213%^z%^C201%^l%^C195%^e%^C123%^d%^RESET%^%^C243%^ than the other three, but you could probably forgive her for it, all things considered.%^CRST%^",
			
			({"walls"}) : "%^C007%^The walls of this establishment are truly something to look at: %^C238%^st%^C239%^ai%^C240%^ne%^C238%^d-b%^C239%^la%^C240%^ck%^C239%^ %^C238%^wo%^C239%^od%^C240%^ su%^C238%^pp%^C239%^or%^C240%^ts%^RESET%^%^C007%^ border squares of seamless %^C253%^wh%^C254%^it%^C255%^e s%^C252%^to%^C253%^ne%^RESET%^%^C007%^, a few of which are further divided into triangles. The only break in the veneer of the walls is provided by two sets of %^C230%^wi%^C229%^nd%^C230%^o%^C229%^ws%^RESET%^%^C007%^. The first is low, and allows passerby a view into the building, while the other runs much higher up, allowing a steady stream of %^C230%^na%^C229%^tu%^C228%^ra%^C229%^l%^C230%^ li%^C229%^gh%^C228%^t%^RESET%^%^C007%^ during the day.%^CRST%^",

			({"floor"}) : "%^C094%^The floor here is kept sh%^C136%^i%^C179%^n%^C136%^y%^RESET%^%^C094%^ and spot%^C136%^l%^C179%^e%^C136%^s%^RESET%^%^C094%^s, so much so that you can almost see yourself in it. The dark-oak selected for the job provides a nice contrast to the otherwise %^C220%^warm lighting%^RESET%^%^C094%^, and makes a distinct %^C007%^*clack*%^RESET%^%^C094%^ as feet come down against it.%^CRST%^",

        ]));
		
        set_door("double doors",TOWN"7","out",0);
        set_door_description("%^C094%^The double doors separating the bank from the rest of the world are comprised of %^C240%^he%^C088%^a%^C240%^vy ebo%^C088%^n%^C240%^y%^RESET%^%^C094%^ and %^C230%^stai%^C229%^ne%^C230%^d gl%^C229%^as%^C230%^s%^RESET%^%^C094%^, which would allow you to see inside, if the doors weren't kept open at this time of year.%^CRST%^");
		
    break;



    }

	set_exits(([
		"out": TOWN"7",
	]));


}



    void reset()
{
        ::reset();
        if(!present("guard"))
        {
           new(MOBS"serith_guard")->move(TO);
        }
        if(!present("teller"))
        {
           new(MOBS"felix")->move(TO);
        }		
		
}



string getBankId()
{
    return "graez";
}


