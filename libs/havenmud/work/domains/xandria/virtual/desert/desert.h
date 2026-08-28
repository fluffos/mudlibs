// adds spawn things to the desert.
//  thri-keen tunnels are still in desert.c
void AddSpawns(int x, int y) {
  // close desert (high mortal)
  if ((x < -20 && x > 100) || (x > 20 && x < 100)) {
    if (!random(25)) AddInventory(XANDRIA_VIRTUAL "desert/dust_devil", random(3) + 1)  // slave hunter
    // escaped slave
  }

  // mid desert (legend)
  if ((x <= -100 && x > -250) || (x >= 100 && x < 250)) {
    if (!random(25)) AddInventory(XANDRIA_VIRTUAL "desert/manticore", random(3) + 1)  // gnoll nomad
    // elf rebel (stealthy dude)
  }

  // deep desert (avatar+)
  if ((x <= -250) || (x >= 250) {
    // evil sandworm bastard
    if (!random(250)) AddInventory(XANDRIA_VIRTUAL "desert/worm", 1)  // elf prophet
    // scarab swarm
  }
  return

  }
