#define DUNGPATH "/d/unterwelt/vernichtung/"
#define DUNGMASTER DUNGPATH "master/master"
#define DUNGTOPMASTER DUNGPATH "master/topmaster"
#define DUNGROOM(x) DUNGPATH "room/"+x
#define DUNGNPC(x) DUNGPATH "npc/"+x
#define DUNGOBJ(x) DUNGPATH "obj/"+x
#define DUNGMAP(x) DUNGPATH "maps/"+x
#define DUNGFUN(x) DUNGPATH "functions/"+x

#define DB DUNGPATH "master/debugger"

#define DUNGMAINT ({ "iwo" })

#define DUNGNPCMINLVL 10
#define DUNGNPCMAXLVL 100


// Special properties
#define P_CRYSTAL_COLOR "crystal_color"
#define P_DUNGLEVEL "dunglevel"
#define P_DUNG_NO_UNLOAD "dung_no_unload"
#define P_DUNG_LASTROOM "dung_lastroom"
#define P_DUNGRUNE_LAST_USED "dungrune_last_used"

#define DUNGCRYSTALCOLORS ({ "rot", "gruen", "gelb", "blau", "schwarz", \
                             "violett", "weiss", "farblos" })

// Direction and x,y,z factor
#define DUNGDIRMAP (["norden": 0; -2; 0, \
                     "nordosten": 2;-2; 0, \
                     "osten": 2; 0; 0,\
                     "suedosten": 2; 2; 0, \
                     "sueden": 0; 2; 0, \
                     "suedwesten":-2; 2; 0, \
                     "westen":-2; 0; 0, \
                     "nordwesten":-2;-2; 0, \
                     "oben": 0; 0;-2, \
                     "unten": 0; 0; 2,])
// This for integer -> direction convertation and vice versa
#define DUNGDIRARR ({ "norden", "nordosten", "osten", "suedosten", \
                      "sueden", "suedwesten", "westen", "nordwesten" })
// Each direction got a set of valid symbol
#define DUNGDIRVALIDSYM ({ "|^v", "/", "-><", "\\", "|^v", "/", "-><", "\\" })

// Global shortint
#define DUNGINTSHORT "In den Tiefen des Pandaemoniums"

// Long descriptions - selection random
#define DUNGINTLONG ({ "Die zerklufteten Felswaende scheinen Dich zu " \
                       "erdruecken. Unangenehme Waerme und die " \
                       "stickige Luft lassen Dich nichts Gutes erahnen. " \
                       "Tief aus dem Erdinneren scheinen Geraeusche zu " \
                       "dringen deren Ursprung Du garnicht ergruenden " \
                       "moechtest.", \
                       "Dir ist uebel vom Gestank und die scheinbar " \
                       "organischen Reste die den Gang pflastern wirken "\
                       "nicht gerade beruhigend auf Dich. Was auch immer "\
                       "hier hausen mag - Du moechtest ihm nicht unbedingt "\
                       "begegnen.", \
                       "Hinter zahlreichen Schatten und Ecken in den " \
                       "felsigen Waenden scheinen boesartige Wesen zu " \
                       "lauern. Bei jedem Schritt laeufst Du Gefahr einem "\
                       "Ungetuem zu begegnen dessen nekromantische " \
                       "Veranlagungen Deinem Koerper mit brachialer "\
                       "Gewalt den letzen Rest von Leben entreissen "\
                       "wollen um Deine Seele fuer immer in den "\
                       "Untiefen des Pandaemoniums zu verbannen.", \
                       "Die dunklen Gaenge scheinen sich wie Adern " \
                       "tief ins innere des Erdreichs zu ziehen. Der " \
                       "Geruch des Todes scheint aus jeder Ritze " \
                       "im Gestein zu dringen. Kalte Schauer laufen Dir " \
                       "ueber den Ruecken bei der Vorstellung welche " \
                       "unheiligen Maechte an der Erschaffung dieser " \
                       "Hoehlen beteiligt waren.", \
                       "Du tastest Dich vorsichtig weiter auf den dunklen " \
                       "Wegen die das Erdinnere durchziehen. Deine Gedanken "\
                       "spielen verrueckt bei der Vorstellung was Dich hier "\
                       "noch alles erwarten wird. Auch wenn Du ein "\
                       "stattlicher Krieger bist fuehlst Du dass Du kaum "\
                       "gegen die Dunklen Maechte die hier am Werk waren "\
                       "gewappnet bist." \
                        })


#define DUNGNPCTYPES (["ghoul": "Es scheint als fehlt der sehnigen Gestalt " \
                           "voellig die Haut. Man sieht direkt das " \
                            "sehnige Gewebe behangen mit fauligen " \
                            "Fleischresten. frueher mag dieses Wesen " \
                            "vielleicht einmal etwas Lebendiges gewesen " \
                            "sein aber jetzt wirkt es nurmehr abstossend.",\
                        "daemon": "Ein graueneregendes Wesen aus einer "\
                           "Dimension steht vor Dir, vollkommen mit unnat"\
                           "uerlichen langen Gliedmassen die in furchtbaren "\
                           "Klauen enden! Seine Haut ist vollkommen mit "\
                           "schwarzen Warzen uebersaeht!",\
                        "daemonenjaeger": "Mit wahnsinnigen Blick mustert "\
                           "Dich dieser Daemonenjaeger. Offenbar hat er "\
                           "seinen Verstand verloren, denn Speichel rinnt "\
                           "aus seinen Mundwinkeln und er brabbelt leise mit "\
                           "mit sich selbst.",\
                        "geisteraustreiber": "Dieser Geisteraustreiber wankt "\
                           "langsam auf Dich zu. Sein Blick ist vollkommen "\
                           "getruebt, seine Kleidung haengt in Fetzen "\
                           "herunter. Er scheint wahnsinnig zu sein, denn "\
                           "er streckt seine Krallen nach Dir aus, scheint "\
                           "nicht mehr zwischen Freund und Feind zu unter"\
                           "scheiden.",\
                        "knochengolem": "Aus unzaehligen zersplitterten "\
                           "Knochen zusammengesetzt steht diese Ausgeburt "\
                           "eines kranken Geistes vor Dir! Aus seinem "\
                           "Gesicht funkeln Dich zwei boese rotgluehende "\
                           "Augen an!",\
                        "seele": "Vor Dir wabbert etwas in der Luft, von dem "\
                           "Du glaubst, dass es eine verirrte Seele sein "\
                           "koennte. Du kannst eine Art Gesicht erkennen, "\
                           "dass voller Schmerz zu schreien scheint, doch "\
                           "kein Laut ist zu hoeren. Eine seltsame Aura der "\
                           "Furcht geht von diesem Wesen aus.",\
                           ])

#define DUNGHEALFUNCS ({ "HealFunc1", "HealFunc2", "HealFunc3",\
   "HealFunc4", "HealFunc5"})

#define TRAPS ({"acid", "roots", "get_blind", "poison_cloud",\
    "stalactit_drop", "cave_collapsion"})


#define DUNGRUNES ({                                                                                 \
"\n _______\n/       \\\n|   |   |\n|   |   |\n|   |   |\n|   |   |\n|  / \\  |\n\\_______/\n\n",    \
"\n _______\n/       \\\n|   |   |\n|   |   |\n|   |-- |\n|   |   |\n|   |   |\n\\_______/\n\n",     \
"\n _______\n/       \\\n|     / |\n|    /  |\n|   |   |\n|   |   |\n|   |   |\n\\_______/\n\n",     \
"\n _______\n/       \\\n|   |   |\n| \\ |   |\n|  \\|   |\n|   |   |\n|   |   |\n\_______/\n\n",    \
"\n _______\n/       \\\n|   |   |\n|   |   |\n| --|-- |\n|   |   |\n|   |   |\n\\_______/\n\n",     \
"\n _______\n/       \\\n| \\   / |\n|  \\ /  |\n|   |   |\n|  / \\  |\n| /   \\ |\n\\_______/\n\n", \
"\n _______\n/       \\\n|     / |\n|    /  |\n|   |   |\n|  /    |\n| /     |\n\\_______/\n",       \
"\n _______\n/       \\\n| \\     |\n|  \\    |\n|   |-- |\n|    \\  |\n|     \\ |\n\\_______/\n\n", \
"\n _______\n/       \\\n| ----- |\n|   |   |\n|   |   |\n|   |   |\n| ----- |\n\\_______/\n\n",     \
"\n _______\n/       \\\n| ----- |\n| |   | |\n| |   | |\n| |   | |\n| ----- |\n\\_______/\n\n",     \
"\n _______\n/       \\\n| ----- |\n|   |   |\n|   |   |\n|   |   |\n|  / \\  |\n\\_______/\n\n",    \
"\n _______\n/       \\\n| ----- |\n|       |\n| ----- |\n|       |\n| ----- |\n\\_______/\n\n",     \
"\n _______\n/       \\\n| \\     |\n|  \\    |\n|   \\   |\n|    \\  |\n| ----- |\n\\_______/\n\n", \
"\n _______\n/       \\\n| ----- |\n|    /  |\n|   -   |\n|  /    |\n| ----- |\n\\_______/\n\n",     \
"\n _______\n/       \\\n|  | |  |\n|  | |  |\n|  | |  |\n|  | |  |\n|  | |  |\n\\_______/\n\n",     \
"\n _______\n/       \\\n|   |   |\n|   |   |\n|   |   |\n| --|-- |\n|   |   |\n\\_______/\n\n",     \
 })


