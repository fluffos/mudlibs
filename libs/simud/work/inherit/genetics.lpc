/*
 * Coded by : Zarylse
 * Date     : 2004-01-01
 */

/// Code stolen and modified from /obj/living.c's environment variable code.

#define DOMINANT   0
#define RECESSIVE  1
#define CODOMINANT 2

/// The person's genetic traits. Format: ([ <gene name> : ({ ({<trait>, <dominance}), ... }) ])
mapping genes;

/***************************************************************** QUERIES */

/** @name Queries
 */
//@{

/** Queries the value of a single gene. If \a gene contains an expression of
 * the form "gene[x]" where x is an integer, then only the x'th element of
 * \a gene will be returned, otherwise the entire array will be returned.
 * Indexing is 0 based.
 * \return 0 if \a gene does not exist, otherwise its value
 */
mixed query_gene( string gene ) {
   int i;
   if ( !genes || !gene ) return 0;

   if ( sscanf( gene, "%s[%d]", gene, i ) == 2 ) {
      if ( !genes[gene] || !pointerp(genes[gene]) ) return 0;
      if ( i < 0 || i >= sizeof(genes[gene]) ) return 0;
      return deep_copy( genes[gene][i] );
   }
   return deep_copy( genes[gene] );
}

mixed query_genes() {
   if ( !mappingp(genes) ) genes = ([ ]);
   return deep_copy( genes );
}

//@}

/******************************************************************** SETS */

/** @name Sets
 */
//@{

void add_gene( string gene, mixed val ) {
   if ( !genes ) genes = ([ ]);
   if ( !genes[gene] ) genes[gene] = ({ val });
   else genes[gene] += ({ val });
}

varargs int remove_gene( string gene, mixed val ) {
   if ( !genes ) return 0;
   if ( !val ) {
      if ( member(genes, gene) ) m_delete( genes, gene );
      else return 0;
      return 1;
   }
   else {
      if ( !pointerp(genes[gene]) ) return 0;
      if ( !intp(val) ) {
         val = member( genes[gene], val );
         if ( val < 0 ) return 0;
      }
      genes[gene] = genes[gene][..val-1] + genes[gene][val+1..];
      return 1;
   }
}

void set_genes( mapping m ) {
   if ( mappingp(m) || m == 0 )
      genes = m;
}

int set_gene( string gene, mixed val ) {
   int i;

   if ( !genes ) genes = ([ ]);
   if ( sscanf(gene, "%s[%d]", gene, i) == 2 ) {
      if ( !pointerp(genes[gene]) || i < i || i >= sizeof(genes[gene]) ) return 0;
      genes[gene][i] = val;
      return 1;
   }
   genes[gene] = val;
   return 1;
}

void set_traits() {
   string gene;
   mixed *vals;

   foreach ( gene, vals : genes ) {
      // only inherited one allele
      if ( sizeof(vals) == 1 )
         this_object()->set_trait( gene, ({vals[0][0]}) );
      // inherited two alleles, figure out phenotype
      else {
         // co-dominance
         if ( vals[0][1] == CODOMINANT && vals[1][1] == CODOMINANT )
            this_object()->set_trait( gene, ({vals[0][0], vals[1][0]}) );
         // dominance of first allele
         else if ( vals[0][1] == DOMINANT )
            this_object()->set_trait( gene, ({vals[0][0]}) );
         // dominance of second allele
         else if ( vals[1][1] == DOMINANT )
            this_object()->set_trait( gene, ({vals[1][0]}) );
         // both recessive
         else if ( vals[0][1] == RECESSIVE && vals[1][1] == RECESSIVE ) {
            // same type of recessive
            if ( vals[0][0] == vals [1][0] )
               this_object()->set_trait( gene, ({vals[0][0]}) );
            // different recessive genes, treat like co-dominance
            else
               this_object()->set_trait( gene, ({vals[0][0], vals[1][0]}) );
         }
      }
   }
}

//@}

// genetics only for first two parents right now.
// this is a nasty late-night hack. should be redone.
void on_birth( string *whos ) {
   string gene, *parent_genes;

   if ( !whos ) whos = this_object()->query_parents();
   if ( !whos ) return;

   if ( sizeof(whos) == 1 ) {
      object p1 = find_living( whos[0] );
      mapping genes1 = p1->query_genes();
      foreach ( gene : genes1 )
         set_gene( gene, ({ genes1[gene][ random(sizeof(genes1[gene])) ] }) );
      set_traits();
      return;
   }

   object p1 = find_living( whos[0] ); // parent #1
   object p2 = find_living( whos[1] ); // parent #2
   mapping genes1 = p1->query_genes();
   mapping genes2 = p2->query_genes();

   parent_genes = m_indices(genes1) & m_indices(genes2);
   foreach ( gene : parent_genes ) {
      set_gene( gene, ({ genes1[gene][ random(sizeof(genes1[gene])) ],
                         genes2[gene][ random(sizeof(genes2[gene])) ] }) );
      m_delete( genes1, gene );
      m_delete( genes2, gene );
   }

   foreach ( gene : genes1 )
      set_gene( gene, ({ genes1[gene][ random(sizeof(genes1[gene])) ] }) );
   foreach ( gene : genes2 )
      set_gene( gene, ({ genes2[gene][ random(sizeof(genes2[gene])) ] }) );

   set_traits();
}
