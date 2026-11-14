
#define HAUSQUEST "Renoviere das verwahrloste Haus"
#define HAUSQUESTLOG "/log/quests/haus"

#define QDIR(x) "/d/wasser/woody/hausquest/"+x

#define QUESTOBJECT QDIR("schluessel")

#define QO_ID "\nhq_qobj"
#define Q_ITEM_ID "\nhq_item"

#define BESEN_ID "\nhq_besen"
#define TUCH_ID "\nhq_tuch"
#define NADELFADEN_ID "\nhq_nadelfaden"
#define NAGEL_ID "\nhq_nagel"
#define HAMMER_ID "\nhq_hammer"
#define KASTEN_ID "\nhq_kasten"
#define EIMER_ID "\nhq_eimer"
#define PINSEL_ID "\nhq_pinsel"
#define BILD_ID "\nhq_bild"
#define BLUMEN_ID "\nhq_blumen"
#define VASE_ID "\nhq_vase"

// Fuer den Eimer...
#define P_CONTAINS       "contains"
#define CONTAINS_NOTHING "cont_nothing"         // Gar nix
#define CONTAINS_WATER   "cont_water"           // Wasser
#define CONTAINS_COLOR   "cont_color"           // weisse Farbe
#define CONTAINS_COLOR_R "cont_color_rests"     // Farbreste...
#define CONTAINS_FLOWERS "cont_flowers"         // Blumen (Vase)

#define F_GEKEHRT       0       // Boden aufgekehrt?
#define F_SCHERBENWEG   1       // wenn nicht, wenigstens Scherben weg?
#define F_VORH_GEFL     2       // Vorhaenge geflickt?
#define F_VORH_GESCH    3       // Vorhaenge ausgeschuettelt?
#define F_FENSTER_REP   4       // Fensterladen repariert?
#define F_FENSTER_GEP   5       // Fenster geputzt?
#define F_TISCH         6       // Tisch aufgestellt?
#define F_STUEHLE       7       // Stuehle aufgestellt?
#define F_BLUMEN        8       // Blumen in Vase auf Tisch?
#define F_WAENDE        9       // Waende gestrichen?
#define F_BILD          10      // Bild aufgehaengt?
#define DO_FLAGS        10      // Anzahl der Flags fuer Aktionen

#define F_FINDET_BLUMEN 11      // Spieler findet Blumen, wenn er sucht

// Jetzt kommen die "found" Flags, also ob ein Spieler schon etwas
// gefunden hat und daher nehmen kann oder nicht...
#define F_F_BESEN       12      // Besen gefunden?
#define F_F_NAEGEL      13      // Naegel als solche identifiziert?
#define F_F_TUCH        14      // Tuch gefunden?
#define F_F_EIMER       15      // Eimer gefunden?
#define F_F_PINSEL      16      // Pinsel gefunden?
#define F_F_BILD        17      // Bild gefunden?

#define FLAGS           17      // Anzahl der Flags insgesamt

