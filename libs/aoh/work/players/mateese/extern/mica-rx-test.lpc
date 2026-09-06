/* Testfile for regular expression id and adjective matching
 * 05/28/98 Mica@OSB
 */

string regexp1, regexp2, tstring;
int i;

string * ids, * ads;

test1() {
  // printf( "%s\n", regexp1 );
  // return regexplode( tstring, regexp1 );
   for( i = 0; i < 40000 ; i ++ ) {
   regexplode( tstring, regexp1 );
   }
}

test2() {
  //    printf( "%s\n", regexp2 );
  //   return regexplode( tstring, regexp2 );

    for( i = 0; i < 40000 ; i ++ ) {
      //      if ( member(ids, tstring ) == -1 ) {
	regexplode( tstring, regexp2 );
	//      }
    }
}

create() {
  string tx;
  // ids = ({ "spy glass", "telescope", "glass" });
  // ads = ({ "brass", "bronze", "old", "rusty", "leather", "worn", "heavy" });

  // ids = ({ "telescope" });
  // ads = ({ "bronze" });

  ids = ({ "knife", "weapon" });
  ads = ({ "long", "carved" });

  /* the standard one 
   * bugs: more than one id for the object and matching of two required 
   *       does not work, i.e. long heavy knife
   * advantage: ids like "spy glass" are handled correctly even if 
   *            "spy     glass" is tried for matching
   * disadvantage: needs norm_id to work properly, at least partially
   */
  regexp1 = gen_id_pattern( ids, ads );

  /* the spooky one
   * bugs: no bugs known till now, awaiting 'em
   * disadvantages: rather long regexp
   * advantage: doesn't need norm_id at all
   */

  /* now build the damn regexp ... */
  regexp2 = "^[ ]*";
  tx = implode( ads||({}), "|" );

  for( i = 0; i < sizeof( ads ); i++ ) {
    regexp2 = regexp2 + "(\\<" + tx + "|[ ]\\>)*[ ]*"; 
  }

  regexp2 = regexp2 + "\\<(" + implode( ids||({}), "|" ) + ")\\>[ ]*$";

  printf( "regexp1: %s\nregexp2: %s\n", regexp1, regexp2 );

  tstring = "bronze telescope";
}

/* do not know if that is a good way to compare those funs, I tried with
 * different numbers of ids and ads, short and long strings to match, string
 * which do not match at all, some that match partially, some that match full.
 * Result was that overall, specially for longer strings to match and strings
 * which are long and do not match the regexp2-version seems to be faster.
 * for short strings regexp1 has slight advantages if it hits. The condition
 * for regexp-hit is the same for both of 'em, i.e. three retvals, 0 and 2 are
 * ""
 * and regexp1 seems to be way slower if there are more than one id
 * btw, please don't ask how I found that regexp2... I HATE REGEXP! .) 
 */
