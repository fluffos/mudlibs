#ifndef __skill__
#define __skill__

query_weapon_skill( weap )
{
   if ( !weap )                                     /* barehanded */
      return( 50 );
   else                                             /* with weapon */
      return( 90 );
}

query_dodge_skill( )
{
   return( 50 );
}

query_parry_skill( )
{
   return( 63 );
}

#endif /* __skill__ */
