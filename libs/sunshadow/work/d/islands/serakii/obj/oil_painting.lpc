//oil painting

#include <std.h>
inherit OBJECT;

object ob;
int i;


void create(){
    ::create();
    set_name("oil painting");
    set_id(({"oil painting","painting"}));
    set_short("oil painting");
    set_long("oil panting\n");
    set_weight(1);
    set_value(1);

    i = random(7);
    switch(i){
        case 0..2:    // ruined

            set_value(100);
            set_short("%^C095%^ru%^C058%^i%^C095%^n%^C059%^e%^C095%^d %^C101%^oil%^C095%^ p%^C247%^a%^C095%^int%^C246%^i%^C095%^ng%^CRST%^");
            set_long("%^C059%^What must have been an %^C110%^impressive %^C059%^and %^C110%^expensive %^C059%^painting has been ruined from being buried in %^C252%^rubble %^C059%^and %^C124%^blood%^C059%^. It had a fine wooden frame and was quite large. The %^C028%^colors %^C059%^have been ruined from %^C254%^dust %^C059%^and the %^C094%^frame %^C059%^has been %^C245%^burned %^C059%^and %^C066%^cracked%^C059%^. Someone might pay for this, though more as a morbid oddity than a piece of art.%^CRST%^\n");
            break;

        case 3..5:    // damaged

            set_value(5000);
            set_short("%^C109%^d%^C095%^a%^C109%^m%^C059%^a%^C109%^ged %^C101%^oil%^C109%^ p%^C094%^a%^C109%^int%^C103%^i%^C109%^ng%^CRST%^");
            set_long("%^C060%^What must have been an %^C063%^impressive %^C060%^and %^C062%^expensive %^C060%^painting has had some of its value removed from the %^C095%^extensive damage%^C060%^ it has faced. It had a %^C094%^fine wooden frame%^C060%^ and was quite large. The %^C028%^colors %^C060%^have been faded from %^C254%^dust %^C060%^and the %^C094%^frame %^C060%^has been %^C242%^singed%^C060%^. While there has been damage to the painting it still retains value as something a collector might enjoy.%^CRST%^\n");
            break;

        case 6:       // perfect

            set_value(50000);
            set_short("%^C029%^p%^C034%^r%^C028%^i%^C029%^s%^C034%^t%^C029%^ine%^C078%^ %^C101%^oil %^C029%^p%^C034%^a%^C029%^int%^C034%^i%^C029%^ng%^CRST%^");
            set_long("%^C116%^This is a very %^C045%^impressive %^C116%^and %^C045%^expensive %^C208%^oil %^C116%^painting. How it has avoided any damage while buried in %^C243%^rubble %^C116%^is beyond you. The %^C029%^colors %^C116%^of the paint are still vibrant as the day they were painted and the %^C094%^expensive wooden frame %^C116%^alone could feed a family for a year. This will fetch quite the price at the market.%^CRST%^\n");

            break;

        }
}
