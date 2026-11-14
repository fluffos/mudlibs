/*
 * Define functions to return the proper third person pronoun based on
 * gender.
 */

#define subjective(ob) ("lib/gender"->sub(ob))
#define objective(ob) ("lib/gender"->obj(ob))
#define possessive(ob) ("lib/gender"->pos(ob))

