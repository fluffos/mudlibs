/* --- monsters here */
int    monstChange;
string availMonster;


get_rnd_monster( ) 
{
   int noOfMonst;
   
   noOfMonst = 16;
   
   switch( random( noOfMonst ) ) {
      case 0:  return( clone_object( "/players/patience/tree_monst/ant" ) );
      case 1:  return( clone_object( "/players/patience/tree_monst/bear" ) );
      case 2:  return( clone_object( "/players/patience/tree_monst/beetle" ) );
      case 3:  return( clone_object( "/players/patience/tree_monst/butterfly" ) );
      case 4:  return( clone_object( "/players/patience/tree_monst/caterpillar" ) );
      case 5:  return( clone_object( "/players/patience/tree_monst/eagle" ) );
      case 6:  return( clone_object( "/players/patience/tree_monst/grasshopper" ) );
      case 7:  return( clone_object( "/players/patience/tree_monst/kid" ) );
      case 8:  return( clone_object( "/players/patience/tree_monst/louse" ) );
      case 9:  return( clone_object( "/players/patience/tree_monst/pheasant" ) );
      case 10: return( clone_object( "/players/patience/tree_monst/sparrow" ) );
      case 11: return( clone_object( "/players/patience/tree_monst/swarm" ) );
      case 12: return( clone_object( "/players/patience/tree_monst/yelf-guard" ) );
      case 13: return( clone_object( "/players/patience/tree_monst/delf-guard" ) );
      case 14: return( clone_object( "/players/patience/tree_monst/elf-guard" ) );
      case 15: return( clone_object( "/players/patience/tree_monst/self-guard" ) );
      default: return; 
   }
}

set_monst_change( per )
{
   monstChange = per;
}
