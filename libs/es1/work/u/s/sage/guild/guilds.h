// The defined variables for guilds.
#define GUILD_PREFIX           "/d/"
#define NEW_PLAYER_GUILD_OBJ   "/d/adventurer/adv_map"

#define CLASS_NAMES ({ "adventurer","knight","mage","healer",\
        "monk", "scholar", "thief","killer",})
#define GUILD_FILES ({ "/d/adventurer/adventurer", "/d/knight/knight",\
        "/d/mage/mage", "/d/healer/healer", "/d/monk/monk", "/d/scholar/scholar",\
        "/d/thief/thief","/u/s/sage/guild/killer",})

#define GUILD_DIR(x)           (GUILD_PREFIX + (x))
#define GUILD_MASTER(x)        (GUILD_PREFIX + (x) +"/" + (x))

// The defined variables for social guilds.
#define MAX_SOCIAL_GUILDS      4

#define SOCIAL_GUILD_PREFIX    "/d/std/social_guilds/"

#define SOCIAL_GUILD_MASTER(x) (SOCIAL_GUILD_PREFIX + (x))
