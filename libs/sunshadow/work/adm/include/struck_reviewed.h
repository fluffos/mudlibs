// Items not defined here that return a negative or 0 value when processing a
// stuck function will be added to /log/reports/struck_damage for review, when
// they have been verified to work correctly the file path should be added here.

#define STRUCK_REVIEWED STRUCK_REVIEWED_A + STRUCK_REVIEWED_B + STRUCK_REVIEWED_C

// /d/<a-h>
#define STRUCK_REVIEWED_A ({ \
    "/d/antioch/jarmila/obj/vashapride", \
    "/d/antioch/ruins/obj/ebony_armor", \
    "/d/antioch/valley/obj/sun_shield", \
    "/d/atoyatl/tecqumin/obj/kilt", \
    "/d/atoyatl/tecqumin/obj/kilt_greater", \
    "/d/atoyatl/tecqumin/obj/poncho", \
    "/d/atoyatl/tecqumin/obj/poncho_greater", \
    "/d/attaya/obj/aut_armor", \
    "/d/attaya/obj/azure", \
    "/d/attaya/obj/shimmeringcape", \
    "/d/attaya/obj/silkdrape", \
    "/d/attaya/obj/silkvest", \
    "/d/attaya/senund/obj/darkrobe", \
    "/d/barriermnts/lothwaite/obj/ethereal_bplate", \
    "/d/barriermnts/lothwaite/obj/ethereal_bracers", \
    "/d/barriermnts/lothwaite/obj/ghostboots", \
    "/d/barriermnts/lothwaite/obj/ghostsandals", \
    "/d/barriermnts/lothwaite/obj/torc", \
    "/d/barriermnts/ruins/obj/battleguards", \
    "/d/barriermnts/ruins/obj/elbowshield", \
    "/d/barriermnts/ruins/obj/pothelmet", \
    "/d/common/obj/armour/barding", \
    "/d/dagger/derro/obj/shield", \
    "/d/dagger/derro/obj/Stormrobe", \
    "/d/dagger/marsh/tower/obj/castershoes", \
    "/d/dagger/marsh/tower/obj/shadowbracers", \
    "/d/dagger/ogres/obj/doubletflames", \
    "/d/dagger/ogres/obj/malar_studded", \
    "/d/dagger/ogres/obj/sune_studded", \
    "/d/deku/armours/brobe", \
    "/d/deku/armours/fire_robe", \
    "/d/deku/armours/priest_robe", \
    "/d/deku/armours/robe", \
    "/d/deku/fortress/obj/crimson_coif", \
    "/d/deku/hhouse/ob/azloths_blessing", \
    "/d/deku/hhouse/ob/heart_of_talos", \
    "/d/deku/hhouse/ob/lathanders_dawn", \
    "/d/deku/hhouse/ob/shroud_of_the_impaler", \
})

// /d/<i-s>
#define STRUCK_REVIEWED_B ({ \
    "/d/islands/argentrock/obj/shd_bskeletal", \
    "/d/islands/argentrock/obj/shd_glassy", \
    "/d/islands/argentrock/obj/shd_gskeletal", \
    "/d/islands/common/eldebaro/ob/ebon_reflector", \
    "/d/islands/common/eldebaro/ob/shroud_of_darkness", \
    "/d/islands/common/eldebaro/ob/stormbringer_armor", \
    "/d/islands/common/obj/e_chain", \
    "/d/islands/common/obj/harbinger", \
    "/d/islands/common/obj/new/e_chain", \
    "/d/islands/common/obj/new/flameguards", \
    "/d/islands/common/obj/new/p_mail", \
    "/d/islands/common/obj/new/shield", \
    "/d/islands/common/obj/new/shimmeringcape2", \
    "/d/islands/common/obj/new/snakebracers", \
    "/d/islands/common/obj/new/waveguards", \
    "/d/islands/common/obj/new/windguards", \
    "/d/islands/common/obj/shimmeringcape2", \
    "/d/islands/coralsea/obj/coralscape", \
    "/d/islands/dallyh/marsh/obj/frobe", \
    "/d/islands/dallyh/forest/obj/rosebodice", \
    "/d/islands/dinosaur/obj/lg_armor", \
    "/d/islands/dreams/obj/darkcassock", \
    "/d/islands/dreams/obj/moonlight_robe", \
    "/d/islands/dreams/obj/nightmare_robe", \
    "/d/islands/dreams/obj/rainbowcassock", \
    "/d/islands/dreams/obj/starrobe", \
    "/d/islands/dreams/obj/sunlight_robe", \
    "/d/islands/elf/obj/anklet", \
    "/d/islands/elf/obj/bracers", \
    "/d/islands/elf/obj/chain", \
    "/d/islands/elf/obj/scale_mail", \
    "/d/islands/elf/obj/shield", \
    "/d/islands/elf/obj/v_gloves", \
    "/d/islands/pirates/obj/newcoat", \
    "/d/islands/pirates/obj/redcoat", \
    "/d/islands/pirates/squires_trial/obj/demonskin", \
    "/d/islands/serakii/obj/dragonrobes", \
    "/d/islands/serakii/obj/hound_bracers", \
    "/d/islands/serakii/obj/hound_robe", \
    "/d/islands/serakii/obj/legion_bracers", \
    "/d/islands/serakii/obj/legion_cassock", \
    "/d/islands/serakii/obj/moon_plate", \
    "/d/laerad/lgnolls/obj/asgaardshield", \
    "/d/laerad/lgnolls/obj/gnollbarding", \
    "/d/laerad/outpost/obj/torm_leather", \
    "/d/laerad/outpost/obj/torm_shield", \
    "/d/laerad/outpost/obj/torm_scalemail", \
    "/d/magic/obj/shields/ashra", \
    "/d/magic/obj/shields/callamir", \
    "/d/magic/obj/shields/cevahir", \
    "/d/magic/obj/shields/jarmila", \
    "/d/magic/obj/shields/khyron", \
    "/d/magic/obj/shields/kismet", \
    "/d/magic/obj/shields/kreysneothosies", \
    "/d/magic/obj/shields/lord_shadow", \
    "/d/magic/obj/shields/lysara", \
    "/d/magic/obj/shields/nilith", \
    "/d/magic/obj/shields/nimnavanon", \
    "/d/magic/obj/shields/seija", \
    "/d/magic/obj/shields/the_faceless_one", \
})

// /d/<r-z>, /realms
#define STRUCK_REVIEWED_C ({ \
    "/d/shadow/room/deep_echos/obj/dpants", \
    "/d/shadow/room/farm/obj/petal_buckler", \
    "/d/shadow/room/githyanki/obj/obsidion_vambraces", \
    "/d/token_hunt/obj/high/dragonrobe", \
    "/d/token_hunt/obj/high/forgottensoul", \
    "/d/token_hunt/obj/high/nightydsp", \
    "/d/token_hunt/obj/high/wolfg", \
    "/d/token_hunt/obj/low/creepingmail", \
    "/d/token_hunt/obj/low/darkgem_shield", \
    "/d/token_hunt/obj/low/rainbowbangles", \
    "/d/token_hunt/obj/low/rubytalongaunt", \
    "/d/token_hunt/obj/mid/akaboots", \
    "/d/token_hunt/obj/mid/chainedovercoat", \
    "/d/token_hunt/obj/mid/forestarmor", \
    "/d/token_hunt/obj/mid/glitteringarmor", \
    "/d/token_hunt/obj/mid/goldenstagarmor", \
    "/d/token_hunt/obj/mid/goldenstagcloth", \
    "/d/token_hunt/obj/mid/ogregauntlets", \
    "/d/token_hunt/obj/mid/paingreaves", \
    "/d/token_hunt/obj/mid/seraphimarmor", \
    "/d/underdark/lower/dragon/obj/barrier", \
    "/d/underdark/lower/dragon/obj/shadowdancer", \
    "/d/underdark/mines/obj/dragonmask", \
    "/d/underdark/mines/obj/gnorobe", \
    "/d/underdark/ud_ruins/obj/fomorian_leather", \
    "/realms/kismet/obj/rewards/k_balurhat", \
    "/realms/kismet/obj/rewards/moontiara", \
    "/realms/kismet/obj/rewards/r_orchid", \
    "/realms/nuwisha/obj/iceaura2", \
})
