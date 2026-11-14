#define MITHRIL "/p/std/skills/jewelry/obj/mithril"
#define RUESTUNGSBALSAM "/d/dschungel/feyaria/tijara/obj/rbalsam"
#define WAFFENBALSAM "/d/dschungel/feyaria/tijara/obj/wbalsam"
#define WATERBREATH "/d/astral/feyaria/djinnistan/obj/waterbreath"

#define DRACHENLIB "/d/gebirge/feyaria/drachen/drachen.lib"
#define MATERIALLIB "/d/dschungel/feyaria/tijara/npc/material.lib"
#define SPIELERLIB "/d/dschungel/feyaria/tijara/npc/spieler.lib"
#define MACHTLIB "/d/dschungel/feyaria/tijara/npc/elsurion_macht.lib"
#define GILDENLIB "/p/service/iwo/lib/gilden.lib"
#define ITEMDLIB "/p/daemon/itemd/libs/cain.lib"

#ifndef DRUIDEN_SPELLS
#define DRUIDEN_SPELLS "/spellbooks/druiden_spells"
#endif

#define MAGIESEIDE "/p/std/skills/sewing_tanning/obj/magieseide"

#define SCHUPPENHAUT "/d/huegelland/xorgan/westderlim/finger/armour/schuppenhaut"

#ifndef IS_ARCHSEER
#define IS_ARCHSEER(user) "/obj/erzsehermaster"->check("Erzseher", user, "", "")
#endif
