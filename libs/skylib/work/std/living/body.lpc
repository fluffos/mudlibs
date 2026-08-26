/**
 * This contains all the code that deals with bodyparts etc. of creatures.
 * @author Sandoz, 2002.
 */

/**
 * This method returns a mapping of areas that this creature has in the
 * form of ([ area_name : ({ bodypart1, bodypart2 }) ]).
 * @return a mapping of attackable body areas
 */
mapping query_attackable_areas() {
    string my_race;

    // When we're going to have code to support bodyparts that are cut off,
    // etc., then this should also be made to remove the missing bits from
    // the mapping.
    if( my_race = TO->query_race_ob() )
        return my_race->query_attackable_areas();

    error("Invalid race object set.\n");

} /* query_attackable_areas() */
