inherit "std/weapon";
#include <properties.h>
#include <combat.h>

create()
{ ::create();

  SetShort("a demons tail");
  SetLong("This is a demon's tail. Only demons should have these.\n");
  AddId("tail");
  AddAdjective("demon");
  SetWC(2);
  SetWeight(50);
  SetWeaponType(WT_CLUB);
  SetDamType(DT_BLUDGEON);
  Set(P_NOGIVE,"You can't give away your tail!\n");
  Set(P_NOTAKE,"You'd have to cut it off.\n");
  Set(P_NOSELL,"You can't sell your tail!\n");
  Set(P_NODROP,"You can't drop your tail, it's attached.\n");
  SetUnwieldObj(this_object());
}

int CheckUnwield() { write("You can't unwield your tail!\n"); return 0; }

// Special for race/demon.c
mixed SetOwner (object who) { return owner = who; }
