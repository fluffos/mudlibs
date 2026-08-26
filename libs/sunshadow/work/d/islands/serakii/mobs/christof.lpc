//Christof - barkeep for Serakii - LoKi 2021


#include <std.h>

inherit BARKEEP;

create() {
  ::create();
  set_property("no bump", 1);
  set_name("Christof Miller");
  set_id( ({ "waiter","barkeep", "christof", "Christof Miller", "christof miller" })
);
  set_short("%^C141%^Christof Miller%^CRST%^, "+
  "%^C064%^barkeep%^CRST%^");
  set("aggressive", 0);
  set_long("%^C071%^Dressed in an %^C250%^old apron%^C071%^ "+
  "and wearing simple %^C064%^peasant clothing%^C071%^, this "+
  "man presents the inn with a %^C038%^friendly %^C071%^face "+
  "and a willing ear. He looks to be in his late twenties, "+
  "and with his %^C132%^girth %^C071%^and %^C124%^red "+
  "cheeks%^C071%^ he has not allowed the %^C050%^joys %^C071%^of "+
  "life to pass him by. %^C226%^Straw colored hair%^C071%^ pokes "+
  "out from under a %^C196%^red cloth%^C071%^ he has wrapped up "+
  "around his head. Striking %^C051%^blue eyes%^C071%^ look "+
  "out past similarly %^C226%^chaotic eyebrows%^C071%^. He "+
  "wears no %^C221%^jewelry %^C071%^or ornamentation.\n%^CRST%^");
  set_gender("male");
  set_alignment(2);
  set("race", "human");
  set_level(12);
  set_hd(12,2);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_mp(random(400));
  set_max_mp(query_mp());
  add_money("copper", random(20));
  set_emotes(4, ({
      "%^C187%^A patron tries to balance an %^C029%^adventuring feast%^C187%^ in either "+
	  "arm as they navigate back to the %^C245%^games room%^C187%^. %^C141%^Christof%^C187%^ "+
	  "can be seen chuckling in the background.%^CRST%^\n",
      "%^C141%^Christof%^C147%^ pours a %^C214%^tea%^C147%^ for a professor at a "+
	  "corner table. The %^C172%^aroma%^C147%^ is calming in the %^C059%^busy inn%^C147%^.%^CRST%^\n",
      "%^C246%^A table of off duty %^C242%^militia %^C246%^quietly play a game of %^C231%^dice %^C246%^at a %^C100%^table %^C246%^in the corner%^CRST%^\n",
      "%^C251%^The%^C196%^ f%^C226%^i%^C196%^re %^C250%^in the%^C196%^ %^C245%^fireplace %^C196%^c%^C247%^r%^C196%^ack%^C247%^l%^C196%^es.%^CRST%^\n",
      "%^C140%^A %^C064%^farmer %^C140%^finishes their %^C249%^drink%^C140%^. They go over to the %^C241%^fireplace %^C140%^to place a hand on the %^C227%^plaque%^C140%^, mouthing something %^C250%^silently%^C140%^ before leaving.%^CRST%^\n",
        }),0);
  set_body_type("human");
  set_currency("gold");
  set_menu(
      ({"earl graez tea","adventuring feast","red wine", "whiskey", "dark ale", "water", "coffee", "meat platter", "bread platter", "fried fish"}),
      ({ "soft drink", "food", "alcoholic", "alcoholic", "alcoholic", "soft drink", "caffeine", "food", "food", "food"}),
      ({ 10, 50, 25, 30, 10, 1, 5, 20, 20, 25 })
  );
 
  set_my_mess(({
    "As you sip from the mug, you find your soul lift and your heart calmed as the bergamot scented tea fills you.\n",
    "%^C222%^As you bite into the %^C009%^wine poached fish%^C222%^, a world of %^C159%^mouth watering textures%^C222%^ "+
    "and %^C159%^juices%^C222%^ fill your senses, the meat is so %^C159%^tender%^C222%^ that it %^C159%^melts%^C222%^ "+
    "n your mouth, lightly seasoned with %^C015%^salt%^C222%^ and %^C008%^pepper%^C222%^ with the %^C009%^red wine "+
    "sauce%^C222%^ brushed over it, balancing with the taste of the fish.%^C007%^ %^C130%^The %^C160%^red-ish brown "+
    "stew%^C130%^ is hardy and delicious, hosting a plethora of %^C076%^fresh vegetables%^C130%^ all %^C220%^crowning%^C130%^ "+
    "a cut of %^C009%^venison%^C130%^ that has been %^C094%^seared%^C130%^ and %^C138%^braised%^C130%^ resting in the centre "+
    "of the bowl.%^C007%^ %^C040%^The salad is simple yet refreshing, %^C156%^balancing%^C040%^ the %^C155%^hardiness%^C040%^ "+
    "of the rest of the food, having %^C156%^fresh lettuce%^C040%^ and %^C156%^veggies%^C040%^ topped with a %^C015%^light "+
    "dressing%^C040%^ and %^C137%^diced pretzels%^C040%^.%^C007%^ %^C131%^The bread seated in the %^C139%^centre%^C131%^ with "+
    "a even spread of %^C160%^plum jam%^C131%^ on one slice and %^C009%^apple%^C131%^ on the other giving a %^C225%^sweet%^C131%^ "+
    "taste to finish of this %^C045%^meal%^C131%^.%^CRST%^\n",
    "%^C088%^You tip the glass back and drink the deep red wine.%^CRST%^\n",
    "%^C179%^The whiskey goes down perfectly and you feel it's warmth spread through you.%^CRST%^\n",
    "%^C095%^The ale is rich and as you drain the glass you feel like another.%^CRST%^\n",
    "%^C075%^The water is clear and refreshing.%^CRST%^\n",
    "%^C094%^The bitter coffee's warmth spreads through you.%^CRST%^\n",
    "%^C126%^The meat platter has all of the choices you'd expect.%^CRST%^\n",
    "%^C130%^The bread is plain and simple but very filling.%^CRST%^\n",
"%^C250%^You eat the %^C225%^tender %^C142%^fried fish%^C250%^. It is %^C142%^tender %^C250%^and %^C110%^filling%^C250%^.%^CRST%^",
  }));
  
  set_your_mess(({
    "sips from the fragrant tea, as they do they relax in the knowledge that they are quite the refined soul indeed.\n",
    "%^C231%^is thoroughly %^C085%^enjoying%^C231%^ thier %^C009%^meal%^C231%^ moving from dish to dish, leaning back "+
    "and %^C085%^rubbing%^C231%^ thier %^C085%^belly%^C231%^ with a satisfied %^C226%^smile%^C231%^.\n%^CRST%^",
    "%^C088%^drinks the wine with a smile.%^CRST%^\n",
    "%^C179%^downs the whiskey, licking their lips.%^CRST%^\n",
    "%^C095%^drinks the pint of ale, then looks at the glass as if pondering.%^CRST%^\n",
    "%^C075%^drinks the water.%^CRST%^\n",
    "%^C094%^drinks the coffee and stretches.%^CRST%^\n",
    "%^C126%^slowly picks apart the meat platter.%^CRST%^\n",
    "%^C130%^breaks open the bread and devours it.%^CRST%^\n",
    "%^C109%^eats the plate of %^C142%^fried fish%^C109%^ with a smile%^CRST%^.",

  }));
  
  set_menu_short(({
    "A thick ceramic mug of fragrant tea",
    "%^C086%^A%^C050%^d%^C085%^v%^C049%^e%^C084%^n%^C048%^t%^C083%^u%^C047%^ri%^C083%^n%^C048%^g%^C084%^ "+
    "f%^C049%^e%^C085%^a%^C050%^s%^C086%^t%^CRST%^",
    "%^C088%^Dark Red wine%^CRST%^",
    "%^C179%^Aged Whiskey%^CRST%^",
    "%^C095%^Dark Ale%^CRST%^",
    "%^C075%^Water%^CRST%^",
    "%^C094%^Bitter Coffee%^CRST%^",
    "%^C126%^Meat Platter%^CRST%^",
    "%^C130%^Bread Platter%^CRST%^",
    "%^C142%^fried fish%^CRST%^",

  }));
  
  set_menu_long(({
    "Served in a thick ceramic mug, this black tea looks most sublime indeed. A true lordly beverage, scented with bergamot.\n",
    "%^C242%^A large black plate of food with %^C253%^several%^C242%^ different %^C253%^dishes%^C242%^ arranged "+
    "on it. In the %^C253%^centre%^C242%^ some fresh %^C138%^baked bread%^C242%^, with a %^C158%^glistening%^C242%^ "+
    "%^C076%^salad%^C242%^ with %^C076%^fresh lettuce%^C242%^ and %^C076%^veggies%^C242%^ topped with %^C138%^crushed "+
    "pretzels%^C242%^ and %^C230%^shredded cheese%^C242%^. Just above a %^C015%^large white bowl%^C242%^ serving "+
    "a %^C130%^hardy stew%^C242%^ with a slab of %^C009%^venison%^C242%^ resting in the centre of it. Lastly a "+
    "magnificent %^C160%^wine%^C242%^ poached %^C215%^fish%^C242%^ coated with a %^C009%^red sauce%^C242%^.\n%^CRST%^",
    "This is a %^C088%^full bodied local wine%^CRST%^ in a squat glass.%^CRST%^\n",
    "The %^C179%^golden whiskey%^CRST%^ in the glass has been aged for years.%^CRST%^\n",
    "This %^C095%^simple beer%^CRST%^ is dark and served in a tall pint glass.%^CRST%^\n",
    "A simple glass of %^C075%^water%^CRST%^ in a simple glass.%^CRST%^\n",
    "The %^C094%^coffee%^CRST%^ is simple and strong, served in a clay mug.%^CRST%^\n",
    "This wooden platter has been piled with all matter of %^C126%^meats%^CRST%^. Farmer's sausage, bacon and others.%^CRST%^\n",
    "This platter is loaded up with different %^C130%^breads%^CRST%^ and butter. Perfect for any meal.%^CRST%^\n",
    "%^C225%^This simple plate is loaded with small carefully %^C214%^fried %^C225%^portions of %^C142%^fish%^CRST%^",

  }));
}
