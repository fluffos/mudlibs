#ifndef _CLASSIFICATION_H_
#define _CLASSIFICATION_H_

// The classification for items
#define HAS_ASPECT(ob, aspect) ((objectp(ob) && ob->query_aspects())?member(ob->query_aspects(), aspect):0)

// General values
// NOTE: Do NOT use the number 0 as a C_XYZ value. We use a
// shortcut in objects that would make it seem as though a
// zero-valued property never exists. Postive and negative
// values are OK, but not zeroes.
//
// UPDATE ALERT: /daemon/material has conversion tables for
// the names of material types here. If you update this file,
// please update the daemon as well!

#define C_POISON  1
#define C_EXIT    2
#define C_RAW     3
#define C_FERTILE 4

// modifiers for tailoring materials and possibly other things
#define C_THIN    10
#define C_THICK   11
#define C_SOFT    12
#define C_RIGID   13
#define C_COARSE  14
#define C_FINE    15
#define C_DYED    16

// highly generic size classifications ;)
#define C_SMALL 20
#define C_MEDIUM 21
#define C_LARGE 22

// metals start here

#define C_METAL 10000
#define C_BRONZE 10001
#define C_LEAD 10002
#define C_TIN 10003
#define C_SILVER 10004
#define C_GOLD 10005
#define C_COPPER 10006
#define C_IRON 10007
#define C_STEEL 10008
#define C_PLATINUM 10009
#define C_WHITE_GOLD 10010
#define C_W_GOLD 10010
#define C_NICKEL 10011
#define C_BRASS 10012
#define C_HARDENED_STEEL 10013
#define C_H_STEEL 10013
#define C_MITHRIL 10014
#define C_ADAMANT 10015
#define C_PEWTER 10016
#define C_ALUMINUM 10017
#define C_ELECTRUM 10018
#define C_ORICHALCUM 10019
#define C_ZINC 10020

#define C_ORE 10100
#define C_LEADORE 101002
#define C_TINORE 101003
#define C_SILVERORE 101004
#define C_GOLDORE 101005
#define C_COPPERORE 10106
#define C_IRONORE 10107
#define C_PLATINUMORE 10109
#define C_NICKELORE 10111
#define C_MITHRILORE 10114
#define C_ADAMANTORE 10115
#define C_ALUMINUMORE 10116
#define C_ORICHALCUMORE 10119
#define C_ZINCORE 10120

// wood types start here

#define C_WOOD 10200
#define C_OAKWOOD 10201
#define C_ASHWOOD 10202
#define C_HICKORYWOOD 10203
#define C_CHESTNUTWOOD 10204
#define C_ELMWOOD 10205
#define C_POPLARWOOD 10206      // possibly wimpy enough we won't allow it
#define C_CEDARWOOD 10207
#define C_WALNUTWOOD 10208
#define C_FIRWOOD 10209         // inferior sorts of pine, really
#define C_BIRCHWOOD 10210
#define C_MAHOGANYWOOD 10211
#define C_APPLEWOOD 10212
#define C_BANANAWOOD 10213      // huh? what kind of stupid...
#define C_COCONUTWOOD 10214      // both of these are deprecated HARD
#define C_LEMONWOOD 10215
#define C_OLIVEWOOD 10216
#define C_ORANGEWOOD 10217
#define C_PINEWOOD 10218
#define C_PLUMWOOD 10219
#define C_CHERRYWOOD 10220
#define C_PECANWOOD 10221
#define C_LIMEWOOD 10222
#define C_PEACHWOOD 10223
#define C_MAPLEWOOD 10224
#define C_IRONWOOD 10225
#define C_APRICOTWOOD 10226
#define C_PEARWOOD 10227
#define C_POMEGRANATEWOOD 10228
#define C_FIGWOOD 10229
#define C_DATEWOOD 10230
#define C_PAPER 10299         // not a wood, but a wood product, yes

// cloth types start here

#define C_CLOTH 10300
#define C_THREAD 10301
#define C_TWINE 10302         // twine == 3 lengths of thread
#define C_ROPE 10303         // rope == 3 lengths of twine

#define C_WOOL 10310
#define C_COTTON 10320
#define C_LEATHER 10330
#define C_FLAX 10340         // flax == linen
#define C_LINEN 10340
#define C_COIR 10350         // coconut husk
#define C_SINEW 10360         // sinew == animal tendon
#define C_GUT 10370            // am wondering if we bother...

// gemstones

#define C_GEM 10400
#define C_AGATE 10401
#define C_AMBER 10402
#define C_AMETHYST 10403
#define C_CITRINE 10404
#define C_DIAMOND 10405
#define C_EMERALD 10406
#define C_GARNET 10407
#define C_JADE 10408
#define C_OBSIDIAN 10409
#define C_OPAL 10410
#define C_PEARL 10411
#define C_PERIDOT 10412
// QUARTZ is defined elsewhere (12001)
#define C_RUBY 10413
#define C_SAPPHIRE 10414
#define C_TOPAZ 10415
#define C_TURQUOISE 10416

// other random body part stuff starts here, eh?

#define C_PELT 10500
#define C_SCALE 10510
#define C_FEATHER 10511
#define C_CARAPACE 10520
#define C_CORPSE 10600
#define C_BONE 10610
#define C_TOOTH 10620
#define C_CLAW 10630
#define C_TAIL 10640
#define C_VENOMSAC 10650
#define C_DRAGONSCALE 10700   // these 4 are redundant now
#define C_DRAGONTOOTH 10701
#define C_DRAGONBLOOD 10702
#define C_DRAGONBONE 10703
// C_BLOOD is under drink (40112)

// creature types start here (yes, I know it's out of order)

#define C_RABBIT 50010
#define C_RAT 50011
#define C_MOUSE 50012
#define C_BEAVER 50020
#define C_DEER 50030
#define C_COW 50031
#define C_BEAR 50040
#define C_WOLF 50050
#define C_BAT 50060
#define C_LION 50070
#define C_LIZARD 50080
#define C_INSECT 50090
#define C_SCORPION 50100
#define C_SNAKE 50110
#define C_CHICKEN 50120
#define C_DUCK 50121
#define C_CRAB 50130
#define C_DRAGON 51000
#define C_UNDEAD 51010

// stone types start here

#define C_STONE 11000
#define C_METAMORPHIC 11100
#define C_SEDIMENTARY 11200
#define C_MARBLE 11201
#define C_ONYX 11202
#define C_LIMESTONE 11203
#define C_GRANITE 11204
#define C_IGNEOUS 11300
#define C_SAND 11901
#define C_GLASS 11902
#define C_COAL 11903
#define C_IVORY 11904
#define C_CRYSTAL 12000
#define C_QUARTZ 12001
#define C_FLINT 12002

// clothing types start here

#define C_CLOTHING 20000
#define C_SHOES 20100
#define C_BOOTS 20101
#define C_SLEEVES 20200
#define C_BRACERS 20300
#define C_SHIRT 20400
#define C_HEADGEAR 20500
#define C_GLOVES 20600
#define C_JERKIN 20800
#define C_PANTS 20900
#define C_SKIRT 21000
#define C_ROBE 21100
#define C_CLOAK 21200
#define C_SHIELD 22000

// weapons and weapon parts start here

#define C_WEAPON 30000
#define C_BLADE 31000
#define C_POMMEL 31001
#define C_HILT 31002
#define C_GUARD 31003
#define C_AXEHEAD 31004
#define C_PICKHEAD 31005
#define C_BOW 31006
#define C_BOWSTRING 31007
#define C_ARROWHEAD 31008
#define C_SHAFT 31009
#define C_NOCK 31010
#define C_FLETCHING 31011
#define C_CLUB 31012
#define C_CHAIN 31013
#define C_BALL 31014
#define C_HANDLE 31015
#define C_THONG 31016
#define C_STAFF 31017
#define C_BOSTAFF 31018
#define C_WAND 31019
#define C_AXE 31020
#define C_GREATAXE 31021
#define C_DAGGER 31022
#define C_DIRK 31023
#define C_SWORD 31024
#define C_RAPIER 31025
#define C_SHORTSWORD 31026
#define C_LONGSWORD 31027
#define C_GREATSWORD 31028
#define C_MACE 31029
#define C_FLAIL 31030
#define C_WHIP 31031
#define C_SPEAR 31032
#define C_PITCHFORK 31033
#define C_HAMMER 31034
#define C_KNIFE 31035
#define C_KAMA 31036
#define C_SCIMITAR 31037
#define C_PICKAXE 31038
#define C_CANE 31039

// smithing components

#define C_BUCKLE 32000
#define C_GEAR   32001
#define C_RING   32002
#define C_ROD    32003
#define C_SCREW  32004
#define C_SHEET  32005
#define C_SPIKE  32006
#define C_STUD   32007
#define C_TUBE   32008
#define C_WIRE   32009
#define C_FOIL   32010

// tools

#define C_TOOL 60000
#define C_FORGE 60010
#define C_LOOM 60020
#define C_SPINNING_WHEEL 60030
#define C_MILL 60040
#define C_KILN 60050
#define C_OVEN 60060
#define C_BLUEPRINT 60070
#define C_VAT 60080 // for dying and such
#define C_STILL 60090
#define C_SCISSORS 60100
#define C_NEEDLE 60110
#define C_PICK 60120
#define C_PLOW 60130
#define C_SAW 60140
#define C_ANVIL 60150

// foods and drinks start here

#define C_FOOD 40000
#define C_CROP 40010
#define C_LIQUID 40100
#define C_WATER 40110
#define C_MILK 400111
#define C_BLOOD 40112
#define C_POTION 40113
#define C_INK 40114
#define C_SNOW 40115

#define C_BREAD 40260
#define C_RYEBREAD 40261
#define C_WHEATBREAD 40262
#define C_FLATBREAD 40263
#define C_YEAST 40270
#define C_EGG 40280
#define C_CRACKEDEGG 40285
#define C_FLOUR 40290
#define C_DOUGH 40300
#define C_CHEESE 40310
#define C_BUTTER 40320
#define C_MEAT 41000
#define C_JERKY 41101
/*
#define C_BEEF 41001
#define C_PORK 41002
#define C_CHICKEN 41003
#define C_FISH 41004
*/
#define C_PLANT 42000
#define C_SQUASH 42001
#define C_HERB 42100
#define C_SPICE 42200
#define C_SALT 42255
#define C_SUGAR 42260
#define C_SEED 42300

#define C_VEGETABLE 42400
#define C_CARROT 42401
#define C_ONION 42402
#define C_LETTUCE 42403
#define C_TOMATO 42404
#define C_POTATO 42405
#define C_PUMPKIN 42406
#define C_SUGAR_BEET 42407
#define C_BEET 42408
#define C_GRASS 42450

#define C_FRUIT 42500
#define C_APPLE 42501
#define C_CITRUS 42550
#define C_ORANGE 42552
#define C_LEMON 42553
#define C_BANANA 42554
#define C_CHERRY 42555
#define C_COCONUT 42556
#define C_OLIVE 42557
#define C_PINECONE 42558   // not a fruit, but a tree seed
#define C_PLUM 42559
#define C_LIME 42560	// gp batch
#define C_APRICOT 42561	// gp batch
#define C_PEAR 42562	// gp batch
#define C_PEACH 42563	// gp batch
#define C_POMEGRANATE 42564	// gp batch
#define C_FIG 42563	// gp batch
#define C_DATE 42563	// gp batch

#define C_GRAIN 42700
#define C_BARLEY 42701
#define C_OATS 42702
#define C_RICE 42703
#define C_RYE 42704
#define C_WHEAT 42705
#define C_CORN 42706

#define C_GRAZE 43000   // ie, grazable for herbivorous bunny types

// mana types

#define C_FIRE_MANA 70000
#define C_ICE_MANA 70001
#define C_EARTH_MANA 70002
#define C_SPIRIT_MANA 70003
#define C_DARK_MANA 70004
#define C_WATER_MANA 70005
#define C_LIGHTNING_MANA 70006
#define C_WIND_MANA 70007
#define C_ORDER_MANA 70008
#define C_CHAOS_MANA 70009

#endif
