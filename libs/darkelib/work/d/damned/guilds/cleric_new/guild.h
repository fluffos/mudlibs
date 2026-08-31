// This is the include file for the guild system.

// I don't feel like explaining it in detail at

// the moment, but I will document it fully later.

// Zortek 960427



#define LEGAL_GUILDS ({"arch-mage","cavalier","chaotic-lord","cleric",\

 "elementalist","enchanter","fighter","mindmage","necromancer","nightblade",\

 "paladin","sword-mage","thief","tinker","war-priest"})



// Guild Domains



#define AM_DOMAIN   "/d/damned/guilds/arch-mage/"

#define CA_DOMAIN   "/d/damned/guilds/cavalier/"

#define CH_DOMAIN   "/d/damned/guilds/chaotic-lord/"

#define CL_DOMAIN   "/d/damned/guilds/cleric/"

#define EL_DOMAIN   "/d/damned/guilds/elementalist/"

#define EN_DOMAIN   "/d/damned/guilds/enchanter/"

#define FI_DOMAIN   "/d/damned/guilds/fighter/"

#define MM_DOMAIN   "/d/damned/guilds/mindmage/"

#define NE_DOMAIN   "/d/damned/guilds/necromancer/"

#define NB_DOMAIN   "/d/damned/guilds/nightblade/"

#define PA_DOMAIN   "/d/damned/guilds/paladin/"

#define SM_DOMAIN   "/d/damned/guilds/sword-mage/"

#define TH_DOMAIN   "/d/damned/guilds/thief/"

#define TI_DOMAIN   "/d/damned/guilds/tinker/"

#define WP_DOMAIN   "/d/damned/guilds/war-priests/"



// Security Bits for MY guild



#define GUILDMASTER           1

#define GUILD_BANKER          4

#define GUILD_ENFORCER        7

#define GUILD_DIPLOMAT       10

#define ALLOW_TO_JOIN        13



#define PROBATION            21

#define PUNISHED             24

#define BANISHED             27



#define ELITE_GUILD_MEMBER   41     

#define FULL_GUILD_MEMBER    44

#define NEW_GUILD_MEMBER     47



// Security Bits for OTHER guilds



#define ARCH_MAGE_GUEST     101

#define ARCH_MAGE_ALLY      104

#define ARCH_MAGE_ENEMY     107



#define CAVALIER_GUEST      111

#define CAVALIER_ALLY       114

#define CAVALIER_ENEMY      117



#define CHAOTIC_LORD_GUEST  121

#define CHAOTIC_LORD_ALLY   124

#define CHAOTIC_LORD_ENEMY  127



#define CLERIC_GUEST        131

#define CLERIC_ALLY         134

#define CLERIC_ENEMY        137



#define ELEMENTALIST_GUEST  141

#define ELEMENTALIST_ALLY   144

#define ELEMENTALIST_ENEMY  147



#define ENCHANTER_GUEST     151

#define ENCHANTER_ALLY      154

#define ENCHANTER_ENEMY     157



#define FIGHTER_GUEST       161

#define FIGHTER_ALLY        164

#define FIGHTER_ENEMY       167



#define MINDMAGE_GUEST      171

#define MINDMAGE_ALLY       174

#define MINDMAGE_ENEMY      177



#define NECROMANCER_GUEST   181

#define NECROMANCER_ALLY    184

#define NECROMANCER_ENEMY   187



#define NIGHTBLADE_GUEST    191

#define NIGHTBLADE_ALLY     194

#define NIGHTBLADE_ENEMY    197



#define PALADIN_GUEST       201

#define PALADIN_ALLY        204

#define PALADIN_ENEMY       207



#define SWORD_MAGE_GUEST    211

#define SWORD_MAGE_ALLY     214

#define SWORD_MAGE_ENEMY    217



#define THIEF_GUEST         221

#define THIEF_ALLY          224

#define THIEF_ENEMY         227



#define TINKER_GUEST        231

#define TINKER_ALLY         234

#define TINKER_ENEMY        237



#define WAR_PRIEST_GUEST    241

#define WAR_PRIEST_ALLY     244

#define WAR_PRIEST_ENEMY    247



