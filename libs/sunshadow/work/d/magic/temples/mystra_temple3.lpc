//Designed by Isaiah, coded by Circe 11/10/04
//cleaned and coloured by Nienne, 12/04 //
//further cleaned by Chernobog, edited by Sienna

#include <std.h>

inherit "/std/templemisc";

//global variable to show which painting is active will be zero if no paintings showing
int showing = 0;
int scene = 0;
string painting;

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Hall of Paintings");
    set_short("Hall of Paintings");
    set_long("%^MAGENTA%^This enchanted-looking hallway adds to the mystery that embodies the temple of %^BOLD%^Mystra%^RESET%^%^MAGENTA%^. To the south, there are %^BOLD%^%^BLACK%^black-streaked marble pillars%^RESET%^%^MAGENTA%^ like the main part of the temple.  They support a rather large stone overhang that goes to the outside road. The eastern and western walls are draped with %^BOLD%^curtains of thick velvet%^RESET%^%^MAGENTA%^. The ceiling is painted %^BOLD%^%^BLACK%^black%^RESET%^%^MAGENTA%^ and steeply arched in a %^BOLD%^%^BLACK%^gothic manner%^RESET%^%^MAGENTA%^. A large set of double double doors leads to the temple proper. Evenly-spaced %^BOLD%^glowing magenta balls%^RESET%^ %^MAGENTA%^float towards the top of the ceiling.  They %^BOLD%^illuminate%^RESET%^%^MAGENTA%^ the elaborate hall with a dim lighting. The most stunning feature of this hall remains the %^BOLD%^paintings%^RESET%^%^MAGENTA%^. They are life-sized and spaced several feet apart. Both sides of the hallway each have four. Under the paintings are plaques with elegant writing on them. In the center of the room sits a %^BOLD%^crystal ball%^RESET%^%^MAGENTA%^ on a pedestal.%^RESET%^\n");
    set_smell("default","The smell is crisp and clean as a high quality building should be.");
    set_listen("default","The temple is oddly quiet.");
    set_items(([
        ({"plaque","plaques"}) : "These plaques are made of brass and have elegant scripted writing engraved on them.",
        ({"door","doors","double doors"}) : "These massive double doors are each nearly 10 feet high and 5 feet wide. They are made of marble with streaks of black in them. They look very difficult to open. They open inward into the temple.",  
        ({"ball","crystal ball"}) : "This ball sits on top of a obsidian pedestal engraved with rubies and seems to have a magical aura about it.",
        "hallway" : "This hallways is long and looks mysterious with the violet light from the magic balls.",
        ({"wall","walls","east wall","west wall","eastern wall","western wall"}) : "The walls are covered with rich velvet drapes of a violet hue. Obviously, this structure was added on to the original construction.",
        "ceiling" : "The ceiling is black and slopes upward sharply with thinly cut beams which are a matching black. The flicker and glow of the violet orbs dance off the sleek surface.",
        ({"ball", "balls"}) : "The balls twinkle with a dim violet light, they cast a mysterious flicker throughout the hall.",
        "drapes" : "Part of the north end of the hallway as well as the longer east and west walls are covered in rich violet velvet drapes. The paintings have been placed on top of these drapes which are brighter and stand out more to the darkly contrasted walls.",
        "pedestal" : "The obsidian pedestal has a crystal ball sitting on it.",
        "overhang" : "The pillars hold up a large overhang that shades the entrance to the temple.",
        ({"painting", "paintings"}) : "There are a total of eight paintings in the hall. Each of them depict someone that is related of import in magic in the lands of Shadowgate, and to Mystra herself.",
        
        //Here are the short descs of the paintings
        "painting 1" : "This is a painting of an average looking female half-elf standing near a tower and holding a book. She appears to be confidently preaching to a crowd of mages. It is titled S'lore.",
        "painting 2" : "This is a tall, middle-aged looking male human. He is dressed in shining armor and sits atop a horse with a lance in one hand and a large shining shield in the other. It is titled Trevize.",
        "painting 3" : "This is a painting of a woman of mixed elven and human heritage. She has a svelte figure with honey eyes and sable hair. Her fancy dress swirls as the whip she holds in one hand spirals around her in a dance. It is titled Nicolya.",
        "painting 4" : "Two elves sit together, the male elf with his arm slung over the female's shoulder, and the female holding him around the torso with a hand. The female has rose-red short spiked hair with crisp blue eyes, and the male is wearing a mage's robe. He has green eyes and black hair. It is titled Kirin and Asalyr.",
        "painting 5" : "A female half-elf with long auburn hair stands poised and dignified in this picture. She is dressed exotically in the garb of a bard. It is titled Gwenhwyfar.",
        "painting 6" : "This painting shows an elf with hazel eyes and black hair. He wears the robes of a mage but also has sheathed blades strapped to the parted robes. Likewise, he has sheaths strapped to his wrists. It is titled Renicus.",
        "painting 7" : "This a picture of an amber-eyed, silver-haired male elf of a small build. He is dressed in a white robe that is open wearing thin armor and with a pair of crossing belts each holding a blade loosely in it. One blade is longer than the other apparently as evidenced by the different sheaths. He has his arms crossed and is looking up. It is titled Isaiah.",
        "painting 8" : "This is a painting of a perky looking female halfling. She wears what appears to be mage robes and holds a bag of components in her hand. She is lean of build and has blue eyes with red hair. She looks eager and full of life, ready for adventure. It is titled Tara."
        ]));
    //One exit to the temple one back outside
    set_exits(([
        "north" : "/d/magic/temples/mystra",
        "out"   : "/d/shadow/room/village/mainroad3"
        ]));
    set_temple("mystra");
}

void init()  {	   
    ::init(); //touching the paintings activates them 
    add_action("touch","touch");
}

int touch(string str){
    //if they try to touch the anything but the 8 paintings nothing happens
    if(str != "painting 1" && str != "painting 2" && str != "painting 3" && str != "painting 4" && str != "painting 5" && str != "painting 6" && str != "painting 7" && str != "painting 8"){
        tell_object(TP,"Touching that does nothing special.");
        return 1;
    }
    
    if(showing != 0){
        tell_object(TP,"Please let the current scene finish first.");
        return 1;
    }
    else{
        switch(str){
            case "painting 1":  showing = 1; break;
            case "painting 2":  showing = 2; break;
            case "painting 3":  showing = 3; break;
            case "painting 4":  showing = 4; break;
            case "painting 5":  showing = 5; break;
            case "painting 6":  showing = 6; break;
            case "painting 7":  showing = 7; break;
            case "painting 8":  showing = 8; break;
        }
    }
    tell_room(TO,""+TPQCN+" places a hand on the painting, and the picture seems to come to life.",TP);
    tell_object(TP,"You place your hand on the painting and it comes to life.");
    call_out("display_painting",3);
    return 1;
}

//Displays the painting to the room element by element until done
void display_painting(){
    switch(showing){
        case 1:  //first painting of slore
            painting =({
                "%^RESET%^%^CRST%^%^C255%^The painting %^C002%^s%^C004%^w%^C005%^i%^C001%^r%^C003%^l%^C011%^s%^CRST%^%^RESET%^%^C255%^ about and the paint seems to reform itself on the parchment.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The colors streak into a very large firbolg holding a %^C001%^massive hammer%^RESET%^%^C255%^ in both hands with ease. He is wearing powerful armor that barely fits his bulging muscles.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^A surprising thing happens: the firbolg in the painting swings the hammer effortlessly, crushing numerous opponents with one blow. His strength is amazing.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The image fans out, and the half-elf from the painting defiantly faces the mighty firbolg. He doesn't seem to be afraid of her, and %^C004%^towers%^RESET%^%^C255%^ in comparison to the average looking half-elven woman.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^While the firbolg is standing there, the half-elf begins casting, and her finger glows with an %^C007%^eerie light%^RESET%^%^C255%^. She touches the mighty firbolg, who %^C008%^pales%^RESET%^%^C255%^ to a sickly white.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^His soul is shown being torn from his body and whisked away to the afterlife.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The paint reforms into a completely different scene. It becomes a depiction of the earlier half-elf in a %^C008%^dimly lit room%^RESET%^%^C255%^ with other robed magic users. All of them sit at a round table and wear cowls. There are %^C004%^shady looking characters%^RESET%^, and those that glow like heroes of %^C011%^light%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The half-elf woman is shown in the guild, protecting a young elven mage. Someone sneaks in through the %^C008%^shadows%^RESET%^%^C255%^, advancing upon them.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^A drow appears and quickly strikes down the guild's leader, running her through with a sharp %^C008%^black blade%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She lays still on the ground... %^C001%^blood%^RESET%^%^C255%^ pools on the floor around her.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next it shows the half-elf looking defeated, hanging up her cowl on a board and walking down the stairs, through the library and out of the guild.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting animates itself, and the guild members appear to be talking and sharing parchments with %^C005%^runes%^RESET%^%^C255%^ written on them. One by one all of the cowled mages blur out of the picture, until only a male half-elf bearing the holy symbol of %^C009%^the storm god%^RESET%^%^C255%^ remains.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^This image holds for a long time, then %^C007%^fades%^RESET%^%^C255%^ as the colors seep away, leaving the parchment blank.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The half-elf appears again, this time not wearing the cowl. She is teaching young mages in a smaller temple, pointing them to the symbol of a goddess.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The female half-elf stays and the background changes to that of a city, where she continues to reprimand mages for their disrespect of magic.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She speaks with great authority, often shouting at times, and the young mages take it to heart.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting then slowly swirls the ink back into its original picture, that of the female half-elf holding a book while teaching, and stays that way.%^CRST%^",
                });
            break;
        case 2: //second one is trevize
            painting = ({  
                "%^RESET%^%^CRST%^%^C255%^The painting clears itself and reforms into a picture of the knight, only he is looking much younger.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^He travels along in the lands, performing the deeds of a %^C007%^true knight%^RESET%^%^C255%^. He slays orcs, gnolls and other mongrel races, and saves villagers who cannot protect themselves.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^It eventually shows him standing with other knights in the Order - the knights of old, all dressed in their best, with shining magical armor.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The paint swirls off into the frame, leaving the canvas %^C007%^blank%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Slowly, a picture of the knight's head is shown, covered in a helm so all you can see are his %^C004%^sad eyes%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^It zooms out, and the knight sets down his lance and holy symbol of Tyr, before walking away from his knighthood to become something much simpler.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^This image holds for quite a few moments of the man: once a knight, now a mere swordsman.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^After the painting holds still for a while longer, it repaints itself into the same swordsman kneeling before an altar with a large book on it. A holy symbol of Mystra is around his neck now.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next image shows him dressed again in the garb of a knight, but different; he is older and wiser than before. He sits atop a great steed and carries a powerful looking lance.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Acolytes and other adventurers gather behind him, following his leadership. His posture is good, and he looks %^C001%^proud%^RESET%^%^C255%^ to serve his goddess.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^As the magic finishes, the painting returns to its original image.%^CRST%^",
                });
            break;
        case 3: //Nicolya
            painting = ({
                "%^RESET%^%^CRST%^%^C255%^The painting starts out with the %^C003%^honey-eyed%^RESET%^%^C255%^ half-elf looking around in confusion. She spends some time in one temple, then some time in another.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^This scene repeats itself a few times until it shows her bound and gagged with some wicked people looming over her. There is shimmer as a %^C012%^magical-looking%^RESET%^%^C255%^ female figure appears and whisks the woman away from her captors.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The canvas clears and the image of the dancer comes into view, swirling around the altar with a large book on it. She dances on it while wisps of %^C014%^magic%^RESET%^%^C255%^ flit about her.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The image reforms, showing a Talossian knight raining havoc about the countryside, destroying everything in sight. Eventually he levels his lance at the temple and begins charging.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The scene on the canvas reforms to show the spell-dancer worriedly trying to make preparations to defend the temple. A male half-elf cleric and his woman are with her.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The image of the temple reshapes to show the aftermath. The female half-elf is sitting there, looking distraught, and the book that was on the altar is %^C001%^burned%^RESET%^%^C255%^ and ruined.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The woman continues in the temple, dancing and standing up for the art to those in the city.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next it shows the woman sitting close to a grim-looking human with an expression of %^C009%^madness%^RESET%^%^C255%^ in his eyes.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The human draws an axe made from %^C008%^shadows%^RESET%^%^C255%^ and runs off, going berserk, hacking with it at anything in reach.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^It then shows the woman alone, sneaking into the temple at night where she grabs some items and stealthily slips out.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She uses those items from the temple to destroy the axe of %^C008%^shadows^&RESET%^%^C255%^, a powerful relic, before leaving the temple.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Lastly, the portrait shows a close-up of her as she walks out. She looks distraught, as though she has committed a great sin against her goddess, and no longer sees herself fit to serve.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The magic spent, the image settles back into a normal painting.%^CRST%^",
                });
            break;
        case 4: //kirin & asalyr
            painting = ({
                "%^RESET%^%^CRST%^%^C255%^The painting begins with the two elves walking down a pathway out of a gated human city towards the old temple.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^They make their way into the temple, hand and hand, approaching the altar with a large book upon it.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^A priest comes out and they recite vows together at the altar, dedicating themselves to the service of a goddess. It is a very %^C001%^romantic%^RESET%^%^C255%^ picture.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The two stay together, working side by side in a lab in the next image.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The scene changes to show them adventuring together, the male elf casting powerful spells, and the female using both spells and daggers with deadly precision.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The two of them appear to complement each other very well.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting turns for the worst, though, when it shows the two elves parting ways, leaving the %^C009%^red-haired%^RESET%^%^C255%^ female alone and sad.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next image depicts her devoting herself entirely to her work. It shows her in the lab, surrounded by books and summoning circles within the %^C011%^daylight%^RESET%^%^C255%^ hours. The sun goes down and a %^C004%^blue moon%^RESET%^%^C255%^ replaces it, and she is still there studying diligently, completely committed to her work.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next image shows a great Balor attacking an elven village, and a group of adventurers standing against it. There are two elves: one a slender female with %^C012%^sapphire eyes%^RESET%^%^C255%^ and %^C008%^long sable hair%^RESET%^%^C255%^, the other a tattooed male with %^C014%^blue eyes%^RESET%^%^C255%^ and %^C003%^shoulder-length brown hair%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^With them there is a human knight with %^C004%^steel blue eyes%^RESET%^%^C255%^, an %^C003%^amber-eyed%^RESET%^%^C255%^ silver-haired elf, and a lean female woman of mixed heritage with %^C014%^sparkling azure eyes%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The gathered group of adventurers makes quick work of the powerful winged %^C009%^balor%^RESET%^%^C255%^, swords flashing and %^C011%^lightning%^RESET%^%^C255%^ striking him down from the heavens.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The red-haired female elf stumbles upon the aftermath and discovers an elven mage who lays upon the ground, burnt completely. A scorched scroll is next to him.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She picks up the scroll and examines it closely for several moments.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Her eyes open wide in shock; she gasps and tucks the scroll away.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Later, the canvas shows the red-haired elf gasp again as dark runes of evil form upon the scorched scroll.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She narrows her eyes as the evil magic reveals itself, the once-hidden runes now glowing an %^C001%^angry red%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The scroll is given to the temple and an acolyte takes it, running off to the shadows.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Color fades and reforms into the red-headed elf giving lessons of magic to other elves. The one that stands out is a male elf with %^C003%^hazel eyes%^RESET%^%^C255%^ and %^C008%^black hair%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She appears to be taking special interest in his teaching, still glancing at him while she speaks with the other elves nearby.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next it shows her alone with the same elf, who is somewhat quiet and subdued, as she teaches him how to cast spells on an open field.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The paints reform back to the original picture and stop moving around.%^CRST%^",
                });
            break;
        case 5: //gwen
            painting = ({									
                "%^RESET%^%^CRST%^%^C255%^The painting shimmers and the depicted woman's age reverses itself,%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^slowly at first,%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^she looks young, and younger%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^.  .  .  and younger.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^It stops when she's a beautiful baby girl in the arms of her mother.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The baby is taken away from her mother.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting again swirls to show a good looking young woman of mixed heritage, setting out as a bard. She keeps to the cities, and makes a name for herself as an entertainer.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next, the paints reform into her with several other half-elves, standing before a library in a bustling city. The %^C001%^auburn-haired%^RESET%^%^C255%^ woman seems pleased.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The colors re-arrange themselves to a main street, where the woman looks stricken as a building burns, along with the pile of books in front of it. People scramble around in chaos, some running from the fire, and some trying to get water to put it out.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The bard is trying to gather books from the fire. She gets her hair and clothing %^C008%^singed%^RESET%^%^C255%^ doing so, but manages to save some of the tomes and scrolls of magic from destruction.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Paint seeps back into the canvas and it shows the bard kneeling before the altar, with an older male human mage there before her.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The image reforms and it shows the bard with the same human from the last. He is holding a whip and crying out in pain. He falls to the ground and drops the wicked looking whip.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The half-elven woman picks up the whip and runs off. The painting fades.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next, the scene reforms to the bardess chained to a wall with a %^C009%^scarlet-haired%^RESET%^%^C255%^ human before her.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^He takes the whip from her and releases her.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting %^C007%^darkens%^RESET%^%^C255%^, becoming an image of a group of adventures in a cave. The half-elven bardess is with them.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^They travel downwards and a white dragon jumps out from the %^C008%^shadows%^RESET%^%^C255%^. It exhales a breath of ice, as a white whirl rushes at the group.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The whip is thrown into the dragon's chilling breath and explodes, causing the whole cave to %^C004%^shake%^RESET%^%^C255%^ in the painting.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The shaking stops and fades, leaving a blank parchment.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The original painting slowly redraws itself, color by color.%^CRST%^",
                });
            break;
        case 6: // renicus
            painting = ({
                "%^RESET%^%^CRST%^%^C255%^The %^C008%^black-haired%^RESET%^%^C255%^ elf in the painting begins to move.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^He looks to the left, then to the right.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting pans out and he beings to walk. He battles hordes of orcs, goblins, and even drow alone, taking great risks but fighting with obvious skill. He slashes with his short swords and hidden daggers, while fluidly integrating spellcraft into his fighting style.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The paint swirls away in a spiral and repaints the image of him with a %^C009%^red-haired%^RESET%^%^C255%^ female elf at night in a temple.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She smiles and talks to him, showing him scrolls and giving him lessons.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Again the painting reforms, pausing a few moments to signify time passing. It shows the male elf staring in awe at the altar of a temple. He looks surprised, as though he had just seen a ghost.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next it shows the male elf with a female elf, who has %^C011%^long golden hair%^RESET%^%^C255%^ and is very beautiful. They are holding hands.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^There is another male elf there with silver hair and %^C003%^amber eyes%^RESET%^%^C255%^, but the conversation is focused on the first two, a heated exchange between the %^C008%^black-haired%^RESET%^%^C255%^ elf and the female.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next painting shows the same %^C008%^black-haired%^RESET%^%^C255%^ elf with a seven-starred cloak, appearing quite regal and official in it. He is standing in a temple looking like a great leader.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Now that the images are finished, the paints mesh until they look like the original picture.%^CRST%^",
                });
            break;
        case 7: //isaiah
            painting = ({
                "%^RESET%^%^CRST%^%^C255%^The elf looks around from left to right as the painting animates itself.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^He looks sad, and the painting pans out.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^When the scene is fully in view, one can see the elf in a wooden house made from the living form of a tree.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^A %^C003%^honey-eyed%^RESET%^%^C255%^ female half-elf appears next to him through %^C014%^soft blue light%^RESET%^%^C255%^. She sits next to the broken elf, consoling and comforting him, her arm gently around his small shoulders.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting clears and reforms, showing the %^C003%^amber-eyed%^CRESET%^ elf watching in silence as a newly knighted human with %^C004%^steel blue eyes%^RESET%^%^C255%^ rides a horse down a main road. He is wearing shining armor, and the peasants and onlookers watch in awe.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The elf walks up to the knight and they being to speak.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The elf seems to take great hope in what the knight is saying, often nodding eagerly.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Again the painting fades and changes, showing the two going back to a temple, where a burnt book rests upon the altar. The elf kneels down and dedicates himself to the cause of Mystra with the knight standing beside him.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next picture shows two stricken elves, one the same male as before, and the other a tall beautiful female elf with %^C006%^pale blue hair%^RESET%^%^C255%^.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The pair frantically rush off down the road into the temple.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^What goes on inside isn't shown in detail.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^%^C006%^Blazing meteors%^RESET%^%^C255%^ rain down from outside to hit the temple, and the stone structure cracks and shatters with each of them.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next image shows the male elf looking very sad. He is back in his room, pouring over papers. His eyes are bloodshot, as though he hasn't rested in a long time.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^After that, there is a depiction of stout-looking dwarves rebuilding the temple, hacking away at a very large slab of marble.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The painting then shows the new temple in all its brilliance, larger and more elaborate than the last. It has an impressive dome at the top.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Another image paints itself, one of a group of adventurers: many elves, a half-elf, a human and a voadkyn. They step through a portal and reappear in the %^C001%^burning waste%^RESET%^%^C255%^ of a different dimension.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The group battles their way through the vile place, slaying the powerful female drow and the old male human who oppose them.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^They fight a great demon and kill him also, though the battle is fierce. A white-haired ranger and another old male human, identical to the first, are taken from a cell filled with instruments of torture.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Together the group drags the unconscious pair though a portal, reappearing back in the temple.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Now that the magic is finished, the painting returns to its static form.%^CRST%^",
                });
            break;
        case 8: //tara
            painting = ({
                "%^RESET%^%^CRST%^%^C255%^The painting shimmers and changes, showing the little halfling in action. She enters a gloomy chamber that hosts an evil-looking mage wearing an amulet.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^She draws daggers, one in each hand, and slashes him from many different directions.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The %^C008%^dark mage%^RESET%^%^C255%^ winces and pales after receiving some very critical looking blows.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^He casts magic at her, but she cries out and continues to attack, the magic dispersing harmlessly while she launches a strike from behind the mage.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^He falls to the ground; the corrupt user of magic lays dead at her feet.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Next, it shows the female halfling meeting with an old human in the robes of a mage. Two elves are with her. The old mage speaks, and the elves' expressions turn grim.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The halfling just smiles and shrugs it off. She jumps up and heads out, ready to tackle the task head on.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The next scene on the parchment shows the halfling with a %^C003%^brown-haired%^RESET%^%^C255%^ human who is working at a forge.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The halfling hands him some %^C007%^glittering white dust^&RESET%^%^C255%^, and he continues at his work.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^The paints swirl away to show the halfling smiling, as the old male human holds up a diamond-tipped dagger, shimmering with magical power.%^CRST%^",
                "%^RESET%^%^CRST%^%^C255%^Now that the magic is done the painting reverts back to the original picture.%^CRST%^",
                });
            break;
        default : return;
    }
    
    // display the array to the room line by line
    tell_room(TO,painting[scene]);
    scene++;
    if(sizeof(painting) == scene){
        showing = 0;
        scene = 0;
        return; //it increments after the last element so should be equal to the last element
    }
    else{
        call_out("display_painting",6);
    }
}

