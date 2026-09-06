/*
 * Name generator, imported from Multia mudlib
 */

string *sylls1,*sylls2,*jap_sylls;
string *shknames;

void init_sylls() {
    /* Just a few hundred different names...but nearly all are sensible... */
    sylls1 = ({"ar","um","ca","for","mor","gon","mel","va","var","ro",
      "el","ka","mi","ti","gan","olo","tul","zar","mir","mul",
      "be","mag","ha","ba","con","bar","mitz","tak","tris"
    });
    sylls2 = ({"nor","bar","nost","dor","han","ras","kor","lar","da","dain",
      "ric","ran","nas","rith","der","rin","kas","hir","ros","tia",
      "leg","lor","rak","tak","lak","knah","ler","teza"
    });

    /* Infinite amount of 95% sensible oriental names */
    jap_sylls = ({
      "yen","ten","wo","ya","yu","yo","ka","ki","ku","ke","ko","sa",
      "shi","su","se","so","ta","chi","tsu","te","to","na","ni","nu",
      "ne","no","ha","hi","fu","he","ho","me","mi","mu","me","mo","ya",
      "ra","ri","ru","re","ro","wa"
    });
}

/* Generate single Multian name */
string random_name() {
    string n;

    if(!sylls1 || !sylls2) init_sylls();
    n = sylls1[random(sizeof(sylls1))] + sylls2[random(sizeof(sylls2))];

    return n;
}

/* Oriental (japanese) names */
string random_oriental_name() {
    int syl,i,num;
    string name;

    if(!jap_sylls) init_sylls();
    num = random(3) + 2; name = "";
    for(i=0;i<num;i++) {
	name += jap_sylls[random(sizeof(jap_sylls))];
    }
    return name;
}

/* Orcish names */
string random_orc_name() {
    int i;
    string tmp;

    tmp = "";
    for(i=0;i<3+random(4);i++)
	tmp += ({"a","c","g","h","k","p","r","s","t","z"})[random(10)];
    return tmp;
}

/*
 * Use these only with shopkeepers!
 *
 */
string
random_shkeeper_name()
{
    if (!shknames) shknames = ({

	  /* Ukraine */
	  "Njezjin", "Tsjernigof", "Gomel", "Ossipewsk", "Gorlowka",

	  /* N. Russia */
	  "Konosja", "Weliki Oestjoeg", "Syktywkar", "Sablja",
	  "Narodnaja", "Kyzyl",

	  /* Silezie */
	  "Walbrzych", "Swidnica", "Klodzko", "Raciborz", "Gliwice",
	  "Brzeg", "Krnov", "Hradec Kralove",

	  /* Schweiz */
	  "Leuk", "Brig", "Brienz", "Thun", "Sarnen", "Burglen", "Elm",
	  "Flims", "Vals", "Schuls", "Zum Loch",

	  /* Eire */
	  "Skibbereen", "Kanturk", "Rath Luirc", "Ennistymon", "Lahinch",
	  "Kinnegad", "Lugnaquillia", "Enniscorthy", "Gweebarra",
	  "Kittamagh", "Nenagh", "Sneem", "Ballingeary", "Kilgarvan",
	  "Cahersiveen", "Glenbeigh", "Kilmihil", "Kiltamagh",
	  "Droichead Atha", "Inniscrone", "Clonegal", "Lisnaskea",
	  "Culdaff", "Dunfanaghy", "Inishbofin", "Kesh",

	  /* Turquie */
	  "Demirci", "Kalecik", "Boyabai", "Yildizeli", "Gaziantep",
	  "Siirt", "Akhalataki", "Tirebolu", "Aksaray", "Ermenak",
	  "Iskenderun", "Kadirli", "Siverek", "Pervari", "Malasgirt",
	  "Bayburt", "Ayancik", "Zonguldak", "Balya", "Tefenni",
	  "Artvin", "Kars", "Makharadze", "Malazgirt", "Midyat",
	  "Birecik", "Kirikkale", "Alaca", "Polatli", "Nallihan",

	  /* Wales */
	  "Yr Wyddgrug", "Trallwng", "Mallwyd", "Pontarfynach",
	  "Rhaeader", "Llandrindod", "Llanfair-ym-muallt",
	  "Y-Fenni", "Measteg", "Rhydaman", "Beddgelert",
	  "Curig", "Llanrwst", "Llanerchymedd", "Caergybi",

	  /* Scotland */
	  "Nairn", "Turriff", "Inverurie", "Braemar", "Lochnagar",
	  "Kerloch", "Beinn a Ghlo", "Drumnadrochit", "Morven",
	  "Uist", "Storr", "Sgurr na Ciche", "Cannich", "Gairloch",
	  "Kyleakin", "Dunvegan",

	  /* Hollandse familienamen */
	  "Feyfer", "Flugi", "Gheel", "Havic", "Haynin", "Hoboken",
	  "Imbyze", "Juyn", "Kinsky", "Massis", "Matray", "Moy",
	  "Olycan", "Sadelin", "Svaving", "Tapper", "Terwen", "Wirix",
	  "Ypey",

	  /* Skandinaviske navne */
	  "Rastegaisa", "Varjag Njarga", "Kautokeino", "Abisko",
	  "Enontekio", "Rovaniemi", "Aavasaksa", "Haparanda",
	  "Lulea", "Gellivarre", "Oulu", "Kajaani", "Fauske",

	  /* Indonesia */
	  "Djasinga", "Tjibarusa", "Tjiwidej", "Pengalengan",
	  "Bandjar", "Parbalingga", "Bojolali", "Sarangan",
	  "Ngebel", "Djombang", "Ardjawinangun", "Berbek",
	  "Papar", "Baliga", "Tjisolok", "Siboga", "Banjoewangi",
	  "Trenggalek", "Karangkobar", "Njalindoeng", "Pasawahan",
	  "Pameunpeuk", "Patjitan", "Kediri", "Pemboeang", "Tringanoe",
	  "Makin", "Tipor", "Semai", "Berhala", "Tegal", "Samoe",

	  /* Perigord */
	  "Voulgezac", "Rouffiac", "Lerignac", "Touverac", "Guizengeard",
	  "Melac", "Neuvicq", "Vanzac", "Picq", "Urignac", "Corignac",
	  "Fleac", "Lonzac", "Vergt", "Queyssac", "Liorac", "Echourgnac",
	  "Cazelon", "Eypau", "Carignan", "Monbazillac", "Jonzac",
	  "Pons", "Jumilhac", "Fenouilledes", "Laguiolet", "Saujon",
	  "Eymoutiers", "Eygurande", "Eauze", "Labouheyre",

	  /* Spmi */
	  "Ymla", "Eed-morra", "Cubask", "Nieb", "Bnowr Falr", "Telloc Cyaj",
	  "Sperc", "Noskcirdneh", "Yawolloh", "Hyeghu", "Niskal", "Trahnil",
	  "Htargcm", "Enrobwem", "Kachzi Rellim", "Regien", "Donmyar",
	  "Yelpur", "Nosnehpets", "Stewe", "Renrut", "_Zlaw", "Nosalnef",
	  "Rewuorb", "Rellenk", "Yad", "Cire Htims", "Y-crad", "Nenilukah",
	  "Erreip", "Nehpets", "Mron", "Snivek",
	  "Nhoj-lee", "Evad\'kh", "Ettaw-noj", "Tsew-mot", "Ydna-s",
	  "Falo", "Nosid-da\'r", "Ekim-p", "Rebrol-nek", "Noslo", "Yl-rednow",
	  "Mured-oog",
	  "Lez-tneg", "Ytnu-haled", "Niknar",

	  /* Suriname */
	  "Hebiwerie", "Possogroenoe", "Asidonhopo", "Manlobbi",
	  "Adjama", "Pakka Pakka", "Kabalebo", "Wonotobo",
	  "Akalapi", "Sipaliwini",

	  /* Greenland */
	  "Annootok", "Upernavik", "Angmagssalik",

	  /* N. Canada */
	  "Aklavik", "Inuvik", "Tuktoyaktuk",
	  "Chicoutimi", "Ouiatchouane", "Chibougamau",
	  "Matagami", "Kipawa", "Kinojevis",
	  "Abitibi", "Maganasipi",

	  /* Iceland */
	  "Akureyri", "Kopasker", "Budereyri", "Akranes", "Bordeyri",
	  "Holmavik",

	  /* Graah's additions */
	  "Tuko", "Kesko", "Smarket", "Alko", "Rabatti",
	  "Forum", "Stockmann", "Fazer", "Sesto", "Elanto",
	  "Anttila", "Sokos", "Gummerrus",

	  /* And, of course, last but not least, the one and only -
	    legendary */
	  "Lassi Tenhunen",
	  /* the monster of the famous adventure game Infoseikkailu! */
	});

    return shknames[random(sizeof(shknames))];
}
