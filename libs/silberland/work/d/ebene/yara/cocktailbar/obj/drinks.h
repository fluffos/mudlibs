/*
** drinks.h  property-file fuer cocktail.c  Yara@SL
** ---
** 2005-12-13
*/

mapping drinks = ([

1:
//0 name
  "Bloody Lola";                                  
//1 alkohol
  "J";                                            
//2 wert
  200;                                            
//3 short
  "Ein Bloody Lola";                              
//4 id
  ({"lola","bloody","bloody lola"});              
//5 long
  "Das kuehle Nass in Deinen Haenden ist ein echter Bloody Lola. Er wurde im "
  "Shaker auf Eis gemixt und wirkt roetlich-orange. Eine Selleriestange "
  "steckt zur Dekoration im Glas und natuerlich fehlen auch die "
  "obligatorischen Strohhalme nicht.";                    
//6 msg-map
  ([
  "msg_trink":
    "Du greifst nach einem der beiden Strohhalme und trinkst einen Schluck von "
    "Deinem eisgekuehlten Bloody Lola.",
  "msg_room_trink":
    "fasst nach dem Strohhalm in einem eisgekuehlten Bloody Lola und trinkt "
    "einen Schluck.",
  "msg_ex":
    "Du ziehst die Strohhalme aus Deinem Bloody Lola und wirfst sie auf den "
    "Boden. Dann setzt Du Deinen Bloody Lola an Deine Lippen und trinkst ihn "
    "komplett aus.",
  "msg_room_ex":
    "wirft die Strohalme aus einem Bloody Lola weg und trinkt und trinkt und "
    "trinkt gierig den Cocktail aus.",
  "msg_nipp":
    "Du nippst an Deinem Bloody Lola und laesst dabei Deinen Blick einmal "
    "durch den Raum gleiten.",
  "msg_room_nipp":
    "nippt an einem Bloody Lola und wirft einen interessierten Blick durch "
    "den Raum.",
  "msg_schluerf":
    "Du schluerfst unueberhoerbar laut von Deinem Cocktail... ob das andere "
    "stoert, interessiert Dich nicht.",
  "msg_room_schluerf":
    "schluerft extrem laut von einem Bloody Lola. Du ueberlegst ob Du dich "
    "nicht besser weiter weg setzen sollst.",
  "msg_leer":
    "Du trinkst den Rest aus Deinem Glas und guckst etwas traurig... aber "
    "naja, Du weisst ja, wo die Quelle ist.",
  "msg_room_leer":
    "trinkt einen Bloody Lola aus."
  ]);
//7 props
  ([
  "drink": 10,
  "alcohol": 10
  ]);
//8 mixmsg
  ({"Josh beginnt einen Bloody Lola zu mixen.",
    "Josh schuettet 5cl Wodka, 1cl Zitronensaft, Tomatensaft und andere "
    "Zutaten in den Shaker auf Eis.",
    "Er mixt das Getraenk locker aus dem Handgelenk und fuellt es "
    "anschliessend in ein Longdrinkglas.",
    "Josh dekoriert den Bloody Lola mit einer Selleriestange."});
//9 details
  ([
  0: ({"nass","kuehles nass"}); "Sieht wirklich lecker und erfrischend aus.", 
  1: ({"haende","hand"}); "Du hast zwei Haende.",
  2: ({"shaker"}); "Darin wurde der Cocktail gemixt.",  
  3: ({"eis"}); "Kuehl und erfrischend.",  
  4: ({"dekoration","selleriestange","stange","sellerie"}); "Eine gruene "
       "Selleriestange dekoriert den Drink.",  
  7: ({"strohhalme","strohhalm","halme","halm"}); "Zwei einfache Strohhalme."
  ])



,



2:
//0 name
  "Tijara Libre";                                  
//1 alkohol
  "J";
//2 wert
  240;
//3 short
  "Ein Tijara Libre";
//4 id
  ({"libre","tijara","tijara libre"});
//5 long
  "Das gelbe Getraenk in Deinen Haenden ist eine Spezialitaet aus dem "
  "Dschungel, dass hauptsaechlich aus Rum und Bananen besteht. Dem "
  "Geruch nach zu urteilen, scheinen aber auch Essenzen anderer Fruechte "
  "enthalten zu sein. Im Glas steckt ein brauner Strohhalm, mit gruenen "
  "Palmblaettern aus Papier.";
//6 trink_msg
  ([
  "msg_trink":
    "Du nimmst den Palmenstrohhalm und trinkst einen Schluck von Deinem "
    "Tijara Libre, dem leichten Brennen des Rums folgt ein erfrischender "
    "Geschmack tropischer Fruechte.",
  "msg_room_trink":
    "fasst nach dem palmenfoermigen Strohhalm in einem Tijara Libre und "
    "trinkt einen Schluck.",
  "msg_ex":
    "Du entfernst den kitschigen Palmenstrohhalm aus Deinem Tijara Libre, "
    "holst Luft, setzt das Glas an und trinkst alles auf einmal aus. "
    "Der viele Rum brennt scharf in Deinem Rachen.",
  "msg_room_ex":
    "entfernt einen kitschigen Palmenstrohhalm aus einem Tijara Libre "
    "und trinkt gierig alles auf einmal aus. Das Getraenk scheint ganz "
    "schoen zu brennen.",
  "msg_nipp":
    "Du nippst an Deinem Tijara Libre und erfreust Dich an dem bananigen "
    "Geschmack.",
  "msg_room_nipp":
    "nippt an einem Tijara Libre.",
  "msg_schluerf":
    "Du schluerfst von Deinem Getraenk und machst dabei Geraeusche wie "
    "eine Tropensau... ob das andere stoert, interessiert Dich nicht.",
  "msg_room_schluerf":
    "schluerft laut wie eine Tropensau von einem Tijara Libre. "
    "Du tust so, als gehoertest Du nicht dazu.",
  "msg_leer":
    "Du trinkst den letzten Schluck Bananen-Rum-Mischung und ueberlegst, "
    "ob Du noch einen davon vertragen wuerdest.",
  "msg_room_leer":
    "trinkt einen Tijara Libre aus."
  ]);
//7 props
  ([
  "drink": 10,
  "alcohol": 15
  ]);
//8 mix-msg
  ({"Josh bereitet alles fuer einen Tijara Libre vor.",
  "Josh schuettet reichlich Rum und andere Zutaten in seinen Mixbecher "
  "und fuellt ihn dann mit Bananensaft auf.",
  "Er schuettelt den Mixer gekonnt und fuellt dann das Getraenk in ein "
  "grosses Glas.",
  "Josh dekoriert das Glas mit einem palmenstammfoermigen Strohhalm, "
  "an dem kleine gruene Palmblaetter aus Papier befestigt sind."});

//9 details
 ([
 0: ({"haende","haenden"}); "Du haeltst den Cocktail mit Deinen Haenden.",
 1: ({"spezialitaet"}); "Josh hat dieses Getraenk extra fuer "
    "so spezielle Besucher wie Dich gemixt.",
 2: ({"besucher", "du"}); "Das bist Du.",
 3: ({"getraenk"}); "Das ist bestimmt lecker.",
 4: ({"dschungel", "tijara", "plantagen", "hauptstadt"}); "Die Hauptstadt "
    "des Dschungels ist Tijara, dort sind auch die Plantagen, "
    "auf denen die Fruechte fuer dieses Getraenk angebaut werden.",
 5: ({"bananen"}); "Das sind diese gelben, gebogenen Fruechte.",
 6: ({"geruch"}); "Riech einfach mal dran!",
 7: ({"essenzen"}); "Du schmeckst auch andere Fruechte, "
    "allerdings kannst Du nicht erkennen, welche es genau sind.",
 8: ({"fruechte"}); "Die schoensten Fruechte wachsen auf Plantagen "
    "im Dschungel bei Tijara. Daher wird dieses Getraenk auch so genannt.",
 9: ({"glas", "behaelter"}); "Das Glas ist ein zylindrischer Behaelter "
    "aus einer erstarrten, siliziumhaltingen Fluessigkeit, naemlich Glas.",
 10: ({"palmblaetter", "papier", "strohhalm"}); "Der Strohhalm ist mit "
    "aus Papier nachgemachten Palmblaettern geschmueckt, damit das "
    "Getraenk auch so gut aussieht wie es schmeckt.",
 11: ({"rum", "alkohol", "zuckerrohr", "fluessigkeit"}); "Rum ist eine "
    "aus Zuckerrohr hergestellte, alkoholische Fluessigkeit."
 ])
// TODO Gerueche ???
// "riecht stark nach Rum und Bananen"

,



3:
//0 name
  "Drachenblut";                                  
//1 alkohol
  "J";                                            
//2 wert
  350;                                            
//3 short
  "Ein Drachenblut";                              
//4 id
  ({"drachenblut","blut"});
//5 long
  "Die dunkelrote Fluessigkeit in Deinem Glas koennte man wirklich "
  "fast fuer das Blut eines Drachen halten, obwohl Du gehoert hast, "
  "dass Drachenblut fast schwarz oder giftgruen sein soll. Eine "
  "Karambolescheibe und ein schwarzer Strohhalm schmuecken das Glas.";                    
//6 msg-map
  ([
  "msg_trink":
    "Du trinkst einen Schluck von Deinem Drachenblut. Das Getraenk "
    "schmeckt fruchtigsuess und ruft eine wohlige Waerme hervor.",
  "msg_room_trink":
    "trinkt einen Schluck Drachenblut.",
  "msg_ex":
    "Du stuerzt das ganze Drachenblut auf einmal hinunter. Du merkst, "
    "wie Du leicht zu schwanken beginnst.",
  "msg_room_ex":
    "stuerzt ein ganzes Glas voll Drachenblut auf einmal hinunter.",
  "msg_nipp":
    "Du nippst an Deinem Drachenblut und knabberst ein wenig an der "
    "Karambolescheibe.",
  "msg_room_nipp":
    "nippt an einem Drachenblut.",
  "msg_schluerf":
    "Du schluerfst abartig laut von Deinem Drachenblut. Die Leute um "
    "Dich herum schauen Dich an.",
  "msg_room_schluerf":
    "schluerft abartig laut von einem Drachenblut. Du tust so, als "
    "gehoertest Du nicht dazu.",
  "msg_leer":
    "Du trinkst Dein Drachenblut aus. Zum Glueck musst Du fuer das "
    "naechste keinen Drachen vorher toeten.",
  "msg_room_leer":
    "trinkt ein Drachenblut aus."
  ]);
//7 props
  ([
  "drink": 10,
  "alcohol": 13
  ]);
//8 mixmsg
  ({"Josh macht sich daran ein Drachenblut zu mixen.",
    "Josh gibt Kirschlikoer, Wodka und Grenadine in ein Glas.",
    "Josh fuellt das Glas mit Champagner und Kirschsaft auf.",
    "Den Glasrand dekoriert Josh mit einer Karambolescheibe und "
    "steckt abschliessend einen Strohhalm hinein."
  });
//9 details
  ([

  1: ({"fluessigkeit"}); "Du bist Dir sicher, dass das nicht das "
    "Blut eines Drachen ist.",
  2: ({"glas","glases"}); "Ein schlichtes Glas, das "
    "Deinen Drachenblutcocktail enthaelt.",
  3: ({"blut"}); "Das ist kein echtes Blut, es sieht nur ein wenig so aus.",
  4: ({"drachen","drache"}); "Du hoffst keinem Drachen zu begegnen um in "
    "Ruhe den Cocktail auszutrinken.",
  5: ({"drachenblutcocktail"}); "Der ist sicher lecker.",
  6: ({"karambolescheibe","scheibe"}); "Sie ist sternfoermig, deswegen wird "
    "die Karambolefrucht auch Sternfrucht genannt.",
  7: ({"karambole","karambolefrucht","sternfrucht","frucht"}); "Eine Scheibe "
    "davon schmueckt den Rand des Glases.",
  8: ({"schmuck","rand"}); "Der Rand des Glases wird von einer "
    "Karambolescheibe geschmueckt.",
  9: ({"strohhalm"}); "Ein schlichter Strohhalm dessen schwarze Farbe gut zu "
    "dem dunklen Rot des Cocktails passt.",
  10: ({"rot","dunkelrot","dunkles rot","farbe"}); "Der Cocktail hat "
    "eine dunkelrote Farbe."
  ])


,


4:
//0 name
  "Sex am Pier";                                  
//1 alkohol
  "J";                                            
//2 wert
  500;                                            
//3 short
  "Ein Sex am Pier";                              
//4 id
  ({"sex","sex am pier","pier"});
//5 long
  "Das Longdrinkglas in Deiner Hand enthaelt eine orange Fluessigkeit, "
  "die betoerend nach Pfirsich und Orange riecht. Eine Cocktailkirsche "
  "und eine Orangenscheibe schmuecken das Getraenk. Du versinkst in "
  "Traeumereien von lauen Naechten an einsamen Sandstraenden.";                    
//6 msg-map
  ([
  "msg_trink":
    "Du trinkst einen Schluck von Deinem Sex am Pier. Deine "
    "Geschmacksnerven werden von einem intensiven Pfirsich- und "
    "Orangenaroma umschmeichelt und wecken die Lust auf mehr...",
  "msg_room_trink":
    "trinkt einen Schluck Sex am Pier.",
  "msg_ex":
    "Du kippst Deinen Drink auf Ex hinunter. Hmm, ganz schoen schnell "
    "vorbei, dieses Vergnuegen...",
  "msg_room_ex":
    "kippt einen Sex am Pier in einem Zug hinunter.",
  "msg_nipp":
    "Du nippst an Deinem Sex am Pier und traeumst vor Dich hin.",
  "msg_room_nipp":
    "nippt vertraeumt an einem Sex am Pier.",
  "msg_schluerf":
    "Du schluerfst unanstaendig laut von Deinem Sex am Pier. Die "
    "Leute um Dich herum schauen Dich komisch an.",
  "msg_room_schluerf":
    "schluerft unanstaendig laut von einem Sex am Pier.",
  "msg_leer":
    "Du trinkst Deinen Sex am Pier aus. Du bekommst Lust auf mehr...",
  "msg_room_leer":
    "trinkt einen Sex am Pier aus."
  ]);
//7 props
  ([
  "drink": 20,
  "alcohol": 20
  ]);
//8 mixmsg
  ({"Josh nimmt ein Longdrinkglas aus dem Regal.",
    "Josh fuellt Wodka, Orangensaft und Moosbeerensaft in den Shaker "
    "und rundet das Ganze mit Pfirsichlikoer ab.",
    "Josh schuettelt die Mischung kraeftig durch.",
    "Josh fuellt alles in das Glas und dekoriert den Drink mit "
    "einer Orangenscheibe und einer Cocktailkirsche."});
//9 details
  ([

  1: ({""}); "",
  2: ({""}); ""

  ])


,



5:
//0 name
  "Felseninsel Eistee";                                  
//1 alkohol
  "J";                                            
//2 wert
  800;                                            
//3 short
  "Ein Felseninsel Eistee";                              
//4 id
  ({"felseninsel","tee","felseninsel eistee","eistee"});
//5 long
  "Beim Anblick der dunklen Fluessigkeit ahnst Du bereits, dass "
  "es nicht viele dieser Drinks bedarf um den Abend frueh zu beenden. "
  "Aber man lebt ja nur einmal, also weg damit.";
//6 msg-map
  ([
  "msg_trink":
    "Du nimmst einen Schluck von Deinem Felseninsel Eistee. Du erwartest "
    "ein Brennen von dem ganzen Alkohol, der Drink schmeckt aber "
    "erstaunlich mild.",
  "msg_room_trink":
    "trinkt einen Schluck Felseninsel Eistee.",
  "msg_ex":
    "Du kippst Deinen Felseninsel Eistee in einem Zug hinunter. Ob das "
    "eine gute Idee war?",
  "msg_room_ex":
    "kippt einen Felseninseleistee in einem Zug hinunter.",
  "msg_nipp":
    "Du nippst an Deinem Felseninsel Eistee. Er schmeckt suess und "
    "erfrischend.",
  "msg_room_nipp":
    "nippt an einem Felseninsel Eistee.",
  "msg_schluerf":
    "Du setzt das Glas an und nimmst laut schluerfend einen grossen "
    "Schluck von Deinem Felseninsel Eistee. Du schwankst leicht.",
  "msg_room_schluerf":
    "nimmt laut schluerfend einen grossen Schluck Felseninsel Eistee "
    "und schwankt dabei leicht.",
  "msg_leer":
    "Du trinkst Deinen Felseninsel Eistee aus und merkst, dass nicht er "
    "ganz ohne war. Ob Du noch einen vertragen kannst?",
  "msg_room_leer":
    "trinkt einen Felseninsel Eistee aus."
  ]);
//7 props
  ([
  "drink": 30,
  "alcohol": 30
  ]);
//8 mixmsg
  ({"Josh nimmt ein grosses Glas und gibt Wodka, Tequila, Rum und "
    "Cointreau hinein.",
    "Josh fuegt Zitronensaft und Orangensaft hinzu und fuellt das "
    "Glas mit Cola auf.",
    "Josh dekoriert das Glas mit einer Orangenscheibe und steckt "
    "einen Strohhalm hinein."});
//9 details
  ([
  1: ({"anblick"}); "Der Drink sieht lecker aus, aber Du ahnst, dass "
    "das nichts Gutes verheisst.",
  2: ({"gutes"}); "Du denkst lieber nicht daran, wie es Dir morgen "
    "gehen wird.",
  3: ({"abend"}); "Mit Getraenken dieser Art kann man den Abend "
    "recht frueh beenden.",
  4: ({"getraenken","getraenke","art"}); "Eins davon haeltst Du in den Haenden.",
  5: ({"haende","hand"}); "Du hast zwei davon."
  ])


,


6:
//0 name
  "Wild Fairy";                                  
//1 alkohol
  "J";                                            
//2 wert
  400;                                            
//3 short
  "Ein Wild Fairy";                              
//4 id
  ({"wild","fairy","wild fairy"});
//5 long
  "Der Cocktail in Deinen Haenden hat eine schoene roetliche Farbe und sieht "
  "sehr lecker aus. Wenn man genau hinsieht, koennte man meinen, dass die "
  "Fluessigkeit ein wenig glitzert. Das Glas schmueckt eine Orangenscheibe und "
  "ein Strohhalm, an dem eine frische Bluete befestigt ist.";
//6 msg-map
  ([
  "msg_trink":
    "Du nimmst einen Schluck von Deinem Wild Fairy und wirst erfasst von "
    "einer Welle des Geschmacks, exotisch und suess, jedoch ueberraschend "
    "erfrischend. Du fuehlst Dich leicht und befluegelt.",
  "msg_room_trink":
    "trinkt einen Schluck Wild Fairy.",
  "msg_ex":
    "Du setzt an und trinkst und trinkst, gierig nach dem einzigartigem "
    "Geschmack, doch ploetzlich ist alles vorbei. Traurig schaust Du in Dein "
    "leeres Glas.",
  "msg_room_ex":
    "trinkt gierig einen Wild Fairy aus und schaut dann traurig in das leere Glas.",
  "msg_nipp":
    "Du nippst an Deinem Wild Fairy. Der Cocktail schmeckt ausgesprochen lecker "
    "und irgendwie verursacht das Getraenk ein sanftes Prickeln auf Deinen Lippen.",
  "msg_room_nipp":
    "nippt geniessend an einem Wild Fairy.",
  "msg_schluerf":
    "Du schluerfst laut von Deinem Wild Fairy. Du merkst kaum, wie Dich die Anwesenden "
    "anstarren, so hingerissen bist Du von dem Geschmack des Cocktails. Mhmm, das "
    "Getraenk prickelt sogar lustig auf der Zunge.",
  "msg_room_schluerf":
    "schluerft laut und tief in Gedanken versunken von einem Wild Fairy. ",
  "msg_leer":
    "Wehmuetig trinkst Du den letzten Schluck Deines Wild Fairy. Die Erinnerung an den "
    "Geschmack wird schwaecher und schwaecher, Du sehnst Dich nach mehr.",
  "msg_room_leer":
    "trinkt einen Wild Fairy aus und scheint traurig darueber zu sein."
  ]);
//7 props
  ([
  "drink": 30,
  "alcohol": 40
  ]);
//8 mixmsg
  ({"Josh nimmt ein schoen geformtes Glas aus dem Regal.",
    "Josh gibt verschiedene Saefte, Grenadine, Wodka und Tequila in einen Mixbecher "
    "und rundet alles mit Zitronensaft ab.",
    "Josh verschliesst den Mixbecher und schuettelt ihn dann kraeftig.",
    "Josh fuellt das Glas auf und dekoriert es mit einer Orangenscheibe.",
    "Josh vollendet den Wild Fairy mit einem passenden Strohhalm.",
  });
//9 details
  ([
  1: ({"haende","hand"}); "Du hast zwei davon.",
  2: ({"farbe","rot","orange","roetliche farbe","orangene","orangenes",
     "roetliches""farbe"}); "Der Cocktail hat eine roetliche Farbe, leicht ins Orangene gehend.",
  3: ({"fluessigkeit"}); "Eigenartig, Dir ist, als wuerde sie glitzern, vielleicht "
    "ist da drin ja eine geheime Zutat.",
  4: ({"glitzer","glitzern"}); "Hmm, Feenstaub glitzert...",
  5: ({"feenstaub"}); "Du weisst nicht genau, ob das wirklich Feenstaub ist.",
  6: ({"strohhalm"}); "Daran ist eine helle Bluete befestigt, wirklich huebsch anzuschaun.",
  7: ({"helle bluete","frische bluete","bluete"}); "Die Bluete ist wirklich schoen und "
    "passt gut zur roten Farbe des Cocktails.",
  8: ({"geheime zutat","zutat"}); "Was koennte das sein?",
  9: ({"orangenscheibe","scheibe"}); "Eine Orangenscheibe schmueckt das Glas."
  ])


,


7:
//0 name
  "Flying Balrog";                                  
//1 alkohol
  "J";                                            
//2 wert
  650;                                            
//3 short
  "Ein Flying Balrog";                              
//4 id
  ({"flying","balrog","flying balrog"});
//5 long
  "Das schwarze Glas in Deinen Haenden enthaelt eine lavafarbene Fluessigkeit, die "
  "sogar langsam vor sich hin brodelt und blubbert. Da sich der Cocktail aber "
  "zum Glueck ganz kuehl anfuehlt, schaetzt Du das als nicht weiter gefaehrlich ein.";
//6 msg-map
  ([
  "msg_trink":
    "Du trinkst einen Schluck von Deinem Flying Balrog. Obwohl Du auf feuriges vorbereitet warst, "
    "ueberrascht Dich das scharfe Brennen doch so, dass Du Dich fast verschluckt haettest. Doch "
    "als das Brennen nachlaesst spuerst Du eine angenehme Waerme und schmeckst den doch "
    "angenehmen Geschmack des Drinks.",
  "msg_room_trink":
    "trinkt einen Schluck Flying Balrog und verschluckt sich fast daran.",
  "msg_ex":
    "Du nimmst allen Mut zusammen und trinkst Deinen Flying Balrog ohne abzusetzen aus. "
    "Das war eindeutig zuviel fuer Dich, Dich trifft es wie einen Peitschenschlag und Du "
    "haeltst Dich schnell wo fest, um nicht umzufallen.",
  "msg_room_ex":
    "trinkt selbstmoerderisch einen Flying Balrog ohne abzusetzen aus und hat fuer einen kurzen "
    "Moment Muehe auf den Beinen zu bleiben.",
  "msg_nipp":
    "Du nippst von Deinem Flying Balrog und spuerst ein scharfes Brennen, was sich bald zu "
    "einem angenehmen Geschmack entfaltet.",
  "msg_room_nipp":
    "nippt von einem Flying Balrog.",
  "msg_schluerf":
    "Du schluerfst laut von Deinem Flying Balrog und merkst sofort, dass das keine gute Idee "
    "war. Der Drink brennt so scharf, dass Du husten musst.",
  "msg_room_schluerf":
    "schluerft laut von einem Flying Balrog und muss stark husten.",
  "msg_leer":
    "Du trinkst den letzten Schluck Deines Flying Balrog, irgendwie fuehlst Du Dich arg mitgenommen.",
  "msg_room_leer":
    "trinkt einen Flying Balrog aus."
  ]);
//7 props
  ([
  "drink": 40,
  "alcohol": 80
  ]);
//8 mixmsg
  ({"Josh nimmt ein schwarzes Glas.",
    "Josh gibt einige Dir unbekannte Fluessigkeiten in einen Mixbecher.",
    "Josh fuegt Dir ebenso unbekannte Zutaten hinzu.",
    "Josh rundet mit Chilisosse ab und schuettelt dann alles kraeftig.",
    "Josh fuellt das schwarze Glas mit der Mischung und stellt es auf die Theke.",
    "Josh entzuendet ein Streicholz und haelt es ueber die Mischung. Eine kleine "
    "Flamme verpufft mit einem leise pfeifendem Geraeusch."
  });
//9 details
  ([
  1: ({"haende"}); "Du hast zwei davon.",
  2: ({"fluessigkeit","lavafarbene fluessigkeit","farbe","lava"}); "Die Fluessigkeit "
    "hat die gleiche Farbe wie Lava. Du bist gespannt, wonach sie schmeckt.",
  3: ({"glueck"}); "Zum Glueck ungefaehrlich.",
  4: ({"gefahr"}); "Keine zu sehn.",
  5: ({"brodeln","blubbern"}); "Hmm, ein bisschen skeptisch macht Dich das schon..."
  ])


,


8:
//0 name
  "Elfish Coffee";                                  
//1 alkohol
  "J";                                            
//2 wert
  400;                                            
//3 short
  "Ein Elfish Coffee";                              
//4 id
  ({"elfish","coffee","elfisch coffee"});
//5 long
  "Du siehst ein hohes Glas mit einer milchkaffeebraunen Fluessigkeit, welche von "
  "reichlich geschlagener Sahne bedeckt ist. Die Sahne ist sogar mit einem Hauch "
  "Kakao bestaeubt. Im Glas steckt ein Strohhalm.";
//6 msg-map
  ([
  "msg_trink":
    "Du geniesst einen Schluck Deines Elfish Coffees. Du schmeckst mildes "
    "Kaffeearoma und angenehme Suesse. Alkohol scheint auch darin enthalten zu sein.",
  "msg_room_trink":
    "trinkt einen Schluck Elfish Coffee.",
  "msg_ex":
    "Du trinkst Deinen Elfish Coffee in einem Zug aus. Du fuehlst Dich ploetzlich so "
    "hibbelig...",
  "msg_room_ex":
    "trinkt einen Elfish Coffee in einem Zug aus und zappelt dann hibbelig herum.",
  "msg_nipp":
    "Du nippst von Deinem Elfish Coffee und naschst etwas von der Sahne.",
  "msg_room_nipp":
    "nippt von einem Elfish Coffee und nascht etwas Sahne.",
  "msg_schluerf":
    "Du nimmst den Strohhalm zur Seite und schluerfst laut von Deinem Elfish Coffee. "
    "Du trinkst dabei hauptsaechlich Sahne ab.",
  "msg_room_schluerf":
    "schluerft ganz und gar unelfenhaft von einem Elfish Coffee.",
  "msg_leer":
    "Du trinkst Deinen Elfish Coffee aus und fuehlst Dich sogar etwas munterer. ",
  "msg_room_leer":
    "trinkt einen Elfish Coffee aus."
  ]);
//7 props
  ([
  "drink": 20,
  "alcohol": 20
  ]);
//8 mixmsg
  ({"Josh nimmt ein hohes Glas und fuellt es mit Kaffee und etwas Sahne.",
    "Josh gibt Wodka, Zuckersirup, Kaffeelikoer und andere Zutaten hinzu.",
    "Josh verruehrt alle Zutaten und schlaegt dann frische Sahne auf.",
    "Josh fuellt das Glas mit der frischen Sahne.",
    "Josh staeubt Kakao ueber die Sahne und steckt einen Strohhalm ins Glas."
  });
//9 details
  ([
  1: ({"fluessigkeit","milchkaffee","milchkaffeebraune fluessigkeit"}); "In diesem "
    "Getraenk ist Kaffee enthalten und so sieht es auch aus.",
  2: ({"sahne"}); "Das Getraenk ist mit reichlich Sahne bedeckt. Du naschst etwas davon.",
  3: ({"hauch"}); "Nur ein klein wenig.",
  4: ({"kakao"}); "Der bildet einen schoenen Kontrast zur Sahne.",
  5: ({"strohhalm"}); "Ein einfacher Strohhalm.",
  6: ({"kontrast"}); "Das sieht nett aus."
  ])


,


9:
//0 name
  "Druida Colada";                                  
//1 alkohol
  "N";                                            
//2 wert
  350;                                            
//3 short
  "Ein Druida Colada";                              
//4 id
  ({"druida","colada","druida colada"});
//5 long
  "Das grosse Cocktailglas in Deinen Haenden ist gefuellt mit einem verfuehrerisch "
  "duftendem Getraenk mit einer interessanten Farbe. Eine ganze Traube von Fruechten "
  "schmueckt den Rand des Glases, ein grosser Strohhalm vervollstaendigt alles.";
//6 msg-map
  ([
  "msg_trink":
    "Du nimmst einen Schluck von Deinem Druida Colada. Er schmeckt suess und fruchtig "
    "und ein wenig nach Kokos. Alkohol schmeckst Du darin nicht.",
  "msg_room_trink":
    "trinkt einen Schluck Druida Colada.",
  "msg_ex":
    "Als waerest Du am verdursten, trinkst Du Deinen Druida Colada in einem Zug aus. "
    "Du fuehlst Dich vollstaendig erfrischt, nur schade, dass Du nicht mehr von dem "
    "fruchtigen Geschmack hattest.",
  "msg_room_ex":
    "trinkt wie halb verdurstet einen Druida Colada in einem Zug aus "
    "und ruelpst leise.",
  "msg_nipp":
    "Du nippst von Deinem Druida Colada und geniesst den fruchtigsuessen Geschmack.",
  "msg_room_nipp":
    "nippt genuesslich von einem Druida Colada.",
  "msg_schluerf":
    "Du mampfst einige der dekorativen Fruechte und spuelst dann laut schluerfend "
    "mit Deinem Druida Colada nach.",
  "msg_room_schluerf":
    "stopft sich einige der Fruechte, die einen Druida Colada dekorieren in den Mund "
    "und spuelt dann laut schluerfend mit dem Cocktail nach.",
  "msg_leer":
    "Du trinkst den letzten Tropfen Deines Druida Colada aus und isst die "
    "verbleibenden Fruechte vom Rand des Glases auf.",
  "msg_room_leer":
    "trinkt einen Druida Colada aus."
  ]);
//7 props
  ([
  "drink": 30,
  "alcohol": 0
  ]);
//8 mixmsg
  ({"Josh nimmt ein grosses Cocktailglas und gibt viel Eis hinein.",
    "Dem Eis fuegt Josh vorsichtig verschiedene Fruchtsaefte hinzu, "
    "und anschliessend noch einige Tropfen einer geheimnisvollen Essenz.",
    "Josh fuellt das Glas mit Kokosmilch auf und steckt einen grossen "
    "Strohhalm hinein.",
    "Josh dekoriert den Druida Colada mit einer an einem Holzstaebchen "
    "befestigten Traube von Fruechten."
  });
//9 details
  ([
  1: ({"haende","hand"}); "Du hast zwei Haende.",
  2: ({"gelb","rot","lila","farbe","interessante farbe"}); "Das ist eine wirklich interessante Farbe, von "
    "gelb ueber rot bis lila, alles dabei.",
  3: ({"traube","fruechte"}); "Pfirsich-, Ananas-, Orangenstuecke bilden zusammen mit Weintrauben "
    "bilden eine recht grosse Traube. Sie wurden aufwaendig an einem Holzstaebchen befestigt "
    "und schmuecken den Rand des Glases.",
  4: ({"rand"}); "Der Rand des Cocktailglases wird von einer Traube von Fruechten geschmueckt.",
  5: ({"strohhalm"}); "Ein einfacher Strohhalm.",
  ])


]);


/*
              5:"Kyranda Sunset";     "J";  250,
              6:"Blue Paladin";       "J";  200,
              7:"Schwarzer Zombie";   "J";  550,
              9:"Frozen Xandim";      "J";  350,
              10:"Druida Colada";     "N";  260,
              11:"Drows Dream";       "J";  370,
              13:"Flying Balrog";     "J";  380,
*/
