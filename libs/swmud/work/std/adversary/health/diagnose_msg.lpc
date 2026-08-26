// Provides health output for adversaries based upon hit_points.c or limbs.c health modules.
// Created by Iizuka

string diagnose_msg(int x)
{
   switch(x)
   {
      case 0..10:
         return "$N $vare about to die.\n";
      case 11..25:
         return "$N $vare in very bad shape.\n";
      case 26..50:
         return "$N $vare badly wounded.\n";
      case 51..75:
         return "$N $vare wounded.\n";
      case 76..85:
         return "$N $vare lightly wounded.\n";
      case 86..95:
         return "$N $vare a bit hurt, but nothing serious.\n";
      case 96..99:
         return "$N $vare a bit roughed up.\n";
      case 100:
         return "$N $vare in perfect health.\n";
      default:
         return "$N $vare in an odd state of health.\n";
   }
}