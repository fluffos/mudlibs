
string rnd_treas() {
  switch(random(20)) {
    case 0: return "/players/whisky/obj/sanct_potion";
    case 1: return "/players/kryll/obj/stones/diamond";
    case 2: return "/players/kryll/obj/stones/emerald";
    case 3..5: return "/players/whisky/obj/heal_potion";
    case 6: return "/players/whisky/obj/bark_scroll";
    case 7: return "/players/whisky/obj/cure_potion";
    case 8: return "/players/whisky/obj/hearo_potion";
    case 9: return "/players/whisky/obj/haste_potion";
    case 10: return "/players/whisky/obj/bless_potion";
    case 11: return "/players/whisky/obj/knock_scroll";
    case 12..14: return "/players/kryll/obj/stones/garnet";
    case 15: return "/players/whisky/obj/pois_scroll";
    case 16: return "/players/whisky/obj/pois_potion";
    case 17: return "/players/whisky/obj/stone_scroll";
    case 18: return "/players/llort/animals_stuff/eye";
    case 19: return "/players/whisky/obj/stone_scroll";
    case 20: return "/players/whisky/obj/res_scroll";
    case 21: return "/players/kryll/obj/stones/quartz";
    case 22: return "/players/kryll/obj/stones/ruby";
    default: return "/players/whisky/obj/freeact_scroll";
  }
}
