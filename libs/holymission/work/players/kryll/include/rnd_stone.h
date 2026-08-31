// This file picks a random gem.

nomask string rndStone() {
  switch(random(20)) {
    case 0..1: return "/players/kryll/obj/stones/emerald";
    case 3..4: return "/players/kryll/obj/stones/diamond";
    case 5..7: return "/players/kryll/obj/stones/sapphire";
    case 8..9: return "/players/kryll/obj/stones/ruby";
    case 10..12: return "/players/kryll/obj/stones/amethyst";
    case 13..16: return "/players/kryll/obj/stones/quartz";
    case 17: return "/players/kryll/obj/stones/fire_jewel";
    default: return "/players/kryll/obj/stones/garnet";
  }
}
