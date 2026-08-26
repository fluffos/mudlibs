// Use this file by hand, uncrustify and other tools make a mess of it
mapping class_spell_storage = ([]);


// Arrays in this storage for most classes store spells in order by level. If you miss some level, use "".
// Notable exceptions are "all" specials applied to all characters and some PRC bonus spells.
class_spell_storage =

([
"oracle":
([
    /*
    "all":
        ({"cure light wounds", "cause light wounds",
          "cure moderate wounds", "cause moderate wounds",
          "cure serious wounds", "cause serious wounds",
          "cure critical wounds", "cause critical wounds",
          "mass cure light wounds", "mass cause light wounds",
          "mass cure moderate wounds", "mass cause moderate wounds",
          "mass cure serious wounds", "mass cause serious wounds",
          "mass cure critical wounds", "mass cause critical wounds",}),
    */
    "dragon":
        ({"cause fear","levitate","resist energy","obsidian flow","fear","protection from spells","true seeing","shapechange","overwhelming presence"}),
    //"godclaw":
    //    ({"cause fear","hold person","break curse","orders wrath","seeking sword","gale fist","dictum","shield of law","imprisonment"}),
    "bones":
        ({"cause fear","false life","animate dead","boneshatter","slay living","circle of death","waves of exhaustion","horrid wilting","wail of the banshee"}),
    "battle":
        ({"true strike", "divine weapon", "keen edge", "divine power", "righteous might", "greater magic weapon", "foresight", "earthquake", "storm of vengeance"}),
    //"flame":
    //    ({"burning hands", "resist energy", "fireball", "wall of fire", "conjure elemental", "fire seeds", "fire storm", "incendiary cloud", "fiery body"}),
    //"elemental":
    //    ({"guidance", "resist energy", "elemental aura", "elemental body i", "elemental body ii", "elemental body iii", "elemental body iv", "create demiplane", "elemental swarm"}),
    //"whimsy":
    //    ({"faerie fire", "hideous laughter", "phantom steed", "confusion", "false vision", "eyebite", "project image", "irresistible dance", "weird"}),
    "heavens":
        ({"color spray", "hypnotic pattern", "daylight", "rainbow pattern", "umbral strike", "spray of shooting stars", "prismatic spray", "sunburst", "meteor swarm"}),
    "life":
        ({"celestial healing", "restoration", "remove blindness", "neutralize poison", "breath of life", "heal", "regenerate", "mass heal", "resurrection"}),
    "shadow":
        ({"blurred movement", "invisibility", "deeper darkness", "shadow necromancy", "vampiric shadow shield", "shadow alteration", "mass invisibility", "greater shadow evocation", "shades"}),
    //"solar":
    //    ({"faerie fire", "flaming sphere", "daylight", "dimension door", "solar siege shot", "sirocco", "sunbeam", "sunburst", "hellball"}),
    "spellscar":
        ({"armor", "resist energy", "dispel magic", "true form", "greater dispel magic", "globe of invulnerability", "spell turning", "spellscar", "imprisonment"}),
    //"ancestor":
    //    ({"unseen servant", "spiritual weapon", "heroism", "spiritual ally", "telekinetic push", "greater heroism","vision", "timeless body", "astral projection"}),
    "nature":
        ({"entangle", "barkskin", "charm monster", "polymorph self", "wall of thorns", "creeping doom", "animate plants", "animal shape", "shambler", "summon natures ally i", "summon natures ally ii", "summon natures ally iii", "summon natures ally iv", "summon natures ally v", "summon natures ally vi", "summon natures ally vii", "summon natures ally iix", "summon natures ally ix"}),
    //"stone":
    //    ({"stone throw", "soften earth", "meld into stone", "obsidian flow", "earth reaver", "wall of stone", "statue", "stone body", "clashing rocks"}),
    //"metal":
    //    ({"mending", "heat metal", "heart of metal", "keen edge", "greater magic weapon", "blade barrier", "statue", "silver sight", "iron body"}),
    "lunar":
        ({"garble", "dust of twilight", "rage", "moonbeam", "aspect of the wolf", "litany of madness", "lunar veil", "blood mist", "polar midnight"}),
    //"waves":
    //    ({"endure elements", "fog cloud", "water breathing", "ice storm", "conjure elemental", "pass portal", "vortex", "seamantle", "tidal surge"}),
    //"winter":
    //    ({"endure elements", "frostfield", "sleet storm", "ice storm", "cone of cold", "frost breath", "hypothermia", "ice mirror", "polar midnight"}),
]),

"sorcerer":
([
    "aberrant":
        ({"enlarge person","detect invisibility","tongues","black tentacles","prying eyes","impenetrable veil","phase door","shapechange"}),
    "abyssal":
        ({"acid splash","darkness","acid orb","fear","domination","impenetrable veil","acid fog","unholy aura", "monster summoning ix"}),
    //"accursed":
    //    ({"touch of fatigue","touch of idiocy","garble","bestow curse","ruin","eyebite","powerword blind","spellscar"}),
    "arcane":
        ({"identify","invisibility","dispel magic","dimension door","siphon magic","true seeing", "limited wish", "powerword stun","disjunction"}),
    //"astral":
    //    ({"flare","invisibility","blink","suppress wild magic","dismissal","contingency","greater teleport","antimagic field"}),
    "boreal":
        ({"enlarge person","bears endurance","rage","stoneskin","cone of cold","transformation","true strike","polar ray", "polar midnight"}),
    "celestial":
        ({"bless", "resist energy", "dispel evil", "break curse", "angelic aspect", "greater dispel magic", "sunburst", "gate"}),
    //"draconic":
    //    ({"armor","resist energy","fireball","fear","acid breath","disintegrate","protection from spells","shapechange"}),
    //"elemental":
    //    ({"burning hands","scorcher","fireball","ice storm","cone of cold","chain lightning","incendiary cloud","meteor swarm"}),
    "fey":
        ({"faerie fire","glitterdust","phantom steed","confusion","domination","eyebite","irresistible dance", "overwhelming presence"}),
    "ghoul":
        ({"chill touch","ray of enfeeblement","vampiric touch","boneshatter","teleport","circle of death","finger of death","horrid wilting"}),
    "infernal":
        ({"protection from alignment", "scorcher", "charm monster", "hold monster", "domination", "hellfire ray", "greater teleport", "powerword stun", "meteor swarm" }),
    "kobold":
        ({"reduce person","slow","polymorph","acid breath","tar pool","delayed fireball","protection from spells","greater polymorph"}),
    //"possessed":
    //    ({"sleep","blindness","displacement","phantasmal killer","false vision""eyebite","visions from within","euphoric tranquility"}),
    //"shadow":
    //    ({"touch of fatigue","alter self","phantom steed","shadowform","angelic aspect","shadow alteration","umbral strike","greater shadow evocation"}),
    "orc":
        ({"burning hands","scorcher","fireball","wall of fire","cloudkill","tar pool","delayed fireball","iron body","meteor swarm"}),
    "stormborn":
        ({"shocking grasp","lightning bolt","gust of wind","lightning arc","chain lightning","phase door","stormbolts","ride the lightning"}),
    //"undead":
    //    ({"chill touch","spectral hand","necrotic burst","animate dead","create undead","exhume corpses","finger of death","create greater undead"}),
]),

"chronicler":
([
    "all":
        ({ "doom", "spiritual ally" }),
]),

"archdruid":
([
    "all":
        ({"elemental swarm", "conjure elemental", "elemental aura"}),
]),

"psion":
([
    "egoist":
        ({"thicken skin","animal affinity","chameleon","resist death","inspiring recovery","empathic relief","lesser transformation","shadow double","shadow body","rewind age"}),
    "seer":
        ({"dissonance","seeing","hypercognition","escape detection","remote viewing","recovered information","inner eye","alter fate","psionic foresight"}),
    "shaper":
        ({"minor creation","ectoplasm","creation","wall of ectoplasm","hail of crystals","genesis","astral seed", "reality revision"}),
    "kineticist":
        ({"animate object","energy emanation","energy cone","hold person","energy current","bolt of force","reddopsi","crushing hand","tornado blast"}),
    "nomad":
        ({"dimension slide","phantom steed", "dismissal", "trace psychoport","dimensional anchor","dimensional barrier","planar portal","astral projection","planar sending"}),
    "telepath":
        ({"suggestion","charm monster","hostile empathic transfer","modify memory","mass suggestion","terrifying reality","mindnet","overwhelming presence","psychic scream"}),
]),

"warlock":
([
    "all":
        ({ "eldritch blast", "eldritch chain", "eldritch burst" }),
    "abyssal":
        ({ "diabolic grasp", "fiendish vigor", "howl of doom", "thirsting maw", "soul theft", "harrowstorm" }),
    "astral":
        ({ "awakened mind", "eye of the warlock", "frigid darkness", "thief of five fates", "dread star", "sign of ill omen" }),
    "infernal":
        ({ "scorching ray", "flames of mephasm", "soul flaying", "hellfire", "hurl through hell", "hellfire shield" }),
    "gloom":
        ({ "vampiric embrace", "curse of despair", "shadowform", "reanimate", "hungry darkness", "pull of the grave" }),
    "fey":
        ({ "mire the mind", "eyebite", "witchfire", "bewitching whispers", "mayhem", "thirsting tendrils" }),
        
]),

]);
