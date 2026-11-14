#ifndef _H_BERSERKER_TALENTE
#define _H_BERSERKER_TALENTE

#define P_BERSERKER_BETA "berserker_beta"
#define TALENTMASTER "/gilden/berserker/master/talentmaster"

#define HAS_TALENT(x, y) call_other("/gilden/berserker/master/talentmaster", "HasTalent", x, y)

#define TALENT_TREE_FURY "Wut" // done
#define TALENT_WAR_FURY 0 // chance auf zusatzschlag im axtkampf
#define TALENT_BLOODY_RAGE 1 // mehr schaden, wenn der spieler weniger LP hat
#define TALENT_RAVING_MADNESS 2 // chance auf krtische treffer bei <50% LP erhoeht
#define TALENT_AXE_IN_BLOOD 3  // kritische treffer koennen blutende wunden verursachen
#define TALENT_BLOOD_DRINKER 4 // chance bei schweren treffern LP zu regenerieren

#define TALENT_TREE_DESTRUCTION "Zerstoerung"
#define TALENT_SHATTERING_STRIKES 5 // angriffe koennen gegner kurzzeitig debuffen (in dem knochen gebrochen oder koerperteile abgeschlagen werden) (done)
#define TALENT_RAVAGER 6 // gegner schrecken bei harten treffern zurueck (verstaerkt wenn sie schon angst haben) (done)
#define TALENT_SHIELDBREAKER 7 // angriffe ignorieren teile der gegnerischen ruestung (mehr mit mehr schwung), chance dass childe schpalten abwehren ist verringert
#define TALENT_DEADLY_PRECISION 8 // gegner, die weniger als 30% lp haben bekommen mehr schaden (done)
#define TALENT_BEHEMOTH_OF_WAR 9 // gegner toeten erhoeht kurzzeitig die max. lebenspunkte

#define TALENT_TREE_TOUGHNESS "Zaehigkeit" // done
#define TALENT_HARD_SKIN 10 // reduziert allen physischen schaden
#define TALENT_RELENTLESS 11 // bei erlittenem schaden werden MP regeneriert
#define TALENT_UNSHAKABLE_WILL 12 // zaehigkeit hilft auch gegen zauberschaden
#define TALENT_STEADFAST 13 // wenn der berserker von "unterbrechungseffekten" (blind, taub, frosch, gift, disabled attack / spells, paralyse) betroffen ist regeneriert er zaehigkeit
#define TALENT_LAST_STAND 14 // bei unter 20% LP massive defensive Boni

#define TALENT_TREE_WARFARE "Kriegskunst"
#define TALENT_PROBING_STRIKES 15 // gibt eine chance eine weitere faehigkeit billiger/besser zu machen (garantierte anwendung)
#define TALENT_PLANNED_ASSAULT 16 // erhoeht den schaden von fertigkeiten, wenn sie der reihe nach abgewechselt werden (spalten als finisher)
#define TALENT_BATTLEFIELD_AWARENESS 17 // chance gegnerischen angriffen auszuweichen, wenn sie vom fokussierten gegner kommen
#define TALENT_PRESCIENT_PLANNER 18 // der spieler plant angriffe voraus (bschlachtplan) und so lange angriffe von der liste ausgefuehrt werden sind sie garantiert und besser
#define TALENT_X 19 // don't know yet

#define MAX_TALENT_NR 15

#define BERSERKER_TALENT_NAMES ({ \
    "Kriegswut",\
    "Blutige Raserei",\
    "Tobsucht",\
    "Axt im Blut",\
    "Blutsaeufer",\
    "Zerschmetternde Schlaege",\
    "Verwuester",\
    "Schildbrecher",\
    "Toedliche Praezision",\
    "Koloss des Kriegs",\
    "Harte Haut",\
    "Unermuedlich",\
    "Unerschuetterlicher Wille",\
    "Standhaft",\
    "Letztes Gefecht",\
    "Abschaetzende Angriffe",\
    "Geplanter Ansturm",\
    "Kampfreflexe",\
    "Vorausschauende Planung",\
    "",\
})

#define BERSERKER_TALENT_TREES ([\
    TALENT_TREE_FURY: ({TALENT_WAR_FURY, TALENT_BLOODY_RAGE, TALENT_RAVING_MADNESS, TALENT_AXE_IN_BLOOD, TALENT_BLOOD_DRINKER}),\
    TALENT_TREE_DESTRUCTION: ({TALENT_SHATTERING_STRIKES, TALENT_RAVAGER, TALENT_SHIELDBREAKER, TALENT_DEADLY_PRECISION, TALENT_BEHEMOTH_OF_WAR}),\
    TALENT_TREE_TOUGHNESS: ({TALENT_HARD_SKIN, TALENT_RELENTLESS, TALENT_UNSHAKABLE_WILL, TALENT_STEADFAST, TALENT_LAST_STAND})\
])

#define P_BERSERKER_RAGE "berserker_rage"
#define P_BERSERKER_RESILIENCE "berserker_resilience"
#define P_BERSERKER_MOMENTUM "berserker_momentum"
#define P_BERSERKER_FOKUS "berserker_fokus"
#define P_BERSERKER_LAST_LAST_STAND "berserker_last_last_stand"

#define MAX_BERSERKER_RESILIENCE(x) (x->QueryProp(P_GUILD_LEVEL)*10) + (pointerp(x->QueryProp(P_TMP_DEFEND_HOOK))?x->QueryProp(P_GUILD_LEVEL)*2:0) + (objectp(present("\nberserker_willenskraft", x))?x->QueryProp(P_GUILD_LEVEL)*2:0)
#define MAX_BERSERKER_RAGE(x) x->QueryProp(P_GUILD_LEVEL)*10
#define MAX_BERSERKER_MOMENTUM(x) 100
#define MAX_BERSERKER_FOKUS(x) 100
#define BERSERKER_LAST_STAND_COOLDOWN 120

#define BERSERKER_DEBUFF_ID "\nberserker_debuff"

#define P_BERSERKER_FURY_ATTACK_MODE "berserker_fury_attack_mode"
#define P_BERSERKER_BLEEDING "berserker_bleeding"
#define P_BERSERKER_LAST_FRIGHTENED "berserker_fright"

#endif // _H_BERSERKER_TALENTE
