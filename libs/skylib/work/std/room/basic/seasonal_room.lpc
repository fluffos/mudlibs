/**
 * This is an inherit for seasonal add items and room chats.
 * To use this inherit just inherit in into
 * the room after the room inherit.
 * @example
 *
 *   inherit ROOM_OBJ;
 *   inherit SEASONAL_ROOM;
 *
 * @author Sandoz, 2002.
 */

/**
 * This method sets the long desc of the room for winter.
 * @see set_long()
 * @see set_winter_day_long()
 * @see set_winter_night_long()
 */
void set_winter_long( mixed str ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->set_long( str );
} /* set_winter_long() */

/**
 * This method sets the long desc of the room for winter days.
 * @see set_long()
 * @see set_winter_long()
 * @see set_winter_night_long()
 */
void set_winter_day_long( mixed str ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->set_day_long( str );
} /* set_winter_day_long() */

/**
 * This method sets the long desc of the room for winter nights.
 * @see set_long()
 * @see set_winter_long()
 * @see set_winter_day_long()
 */
void set_winter_night_long( mixed str ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->set_night_long( str );
} /* set_winter_night_long() */

/**
 * This method sets the long desc of the room for spring.
 * @see set_long()
 * @see set_spring_day_long()
 * @see set_spring_night_long()
 */
void set_spring_long( mixed str ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->set_long( str );
} /* set_spring_long() */

/**
 * This method sets the long desc of the room for spring days.
 * @see set_long()
 * @see set_spring_long()
 * @see set_spring_night_long()
 */
void set_spring_day_long( mixed str ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->set_day_long( str );
} /* set_spring_day_long() */

/**
 * This method sets the long desc of the room for spring nights.
 * @see set_long()
 * @see set_spring_long()
 * @see set_spring_day_long()
 */
void set_spring_night_long( mixed str ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->set_night_long( str );
} /* set_spring_night_long() */

/**
 * This method sets the long desc of the room for summer.
 * @see set_long()
 * @see set_summer_day_long()
 * @see set_summer_night_long()
 */
void set_summer_long( mixed str ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->set_long( str );
} /* set_summer_long() */

/**
 * This method sets the long desc of the room for summer days.
 * @see set_long()
 * @see set_summer_long()
 * @see set_summer_night_long()
 */
void set_summer_day_long( mixed str ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->set_day_long( str );
} /* set_summer_day_long() */

/**
 * This method sets the long desc of the room for summer nights.
 * @see set_long()
 * @see set_summer_long()
 * @see set_summer_day_long()
 */
void set_summer_night_long( mixed str ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->set_night_long( str );
} /* set_summer_night_long() */

/**
 * This method sets the long desc of the room for autumn.
 * @see set_long()
 * @see set_autumn_day_long()
 * @see set_autumn_night_long()
 */
void set_autumn_long( mixed str ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->set_long( str );
} /* set_autumn_long() */

/**
 * This method sets the long desc of the room for autumn days.
 * @see set_long()
 * @see set_autumn_long()
 * @see set_autumn_night_long()
 */
void set_autumn_day_long( mixed str ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->set_day_long( str );
} /* set_autumn_day_long() */

/**
 * This method sets the long desc of the room for autumn nights.
 * @see set_long()
 * @see set_autumn_long()
 * @see set_autumn_day_long()
 */
void set_autumn_night_long( mixed str ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->set_night_long( str );
} /* set_autumn_night_long() */

/**
 * This method adds an item to the room, that
 * is to be used during the winter only.
 * @see add_item()
 * @see add_winter_day_item()
 * @see add_winter_night_item()
 */
varargs void add_winter_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->add_item( shorts, desc, no_plural );
} /* add_winter_item() */

/**
 * This method adds a day item into the room,
 * that is to be used during the winter only.
 * @see add_item()
 * @see add_winter_item()
 * @see add_winter_night_item()
 */
varargs void add_winter_day_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->add_day_item( shorts, desc, no_plural );
} /* add_winter_day_item() */

/**
 * This method adds a night item into the room,
 * that is to be used during the winter only.
 * @see add_item()
 * @see add_winter_item()
 * @see add_winter_day_item()
 */
varargs void add_winter_night_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->add_night_item( shorts, desc, no_plural );
} /* add_winter_night_item() */

/**
 * This method adds an item to the room, that
 * is to be used during the spring only.
 * @see add_item()
 * @see add_spring_day_item()
 * @see add_spring_night_item()
 */
varargs void add_spring_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->add_item( shorts, desc, no_plural );
} /* add_spring_item() */

/**
 * This method adds a day item into the room,
 * that is to be used during the spring only.
 * @see add_item()
 * @see add_spring_item()
 * @see add_spring_night_item()
 */
varargs void add_spring_day_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->add_day_item( shorts, desc, no_plural );
} /* add_spring_day_item() */

/**
 * This method adds a night item into the room,
 * that is to be used during the spring only.
 * @see add_item()
 * @see add_spring_item()
 * @see add_spring_day_item()
 */
varargs void add_spring_night_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->add_night_item( shorts, desc, no_plural );
} /* add_spring_night_item() */

/**
 * This method adds an item to the room, that
 * is to be used during the summer only.
 * @see add_item()
 * @see add_summer_day_item()
 * @see add_summer_night_item()
 */
varargs void add_summer_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->add_item( shorts, desc, no_plural );
} /* add_summer_item() */

/**
 * This method adds a day item into the room,
 * that is to be used during the summer only.
 * @see add_item()
 * @see add_summer_item()
 * @see add_summer_night_item()
 */
varargs void add_summer_day_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->add_day_item( shorts, desc, no_plural );
} /* add_summer_day_item() */

/**
 * This method adds a night item into the room,
 * that is to be used during the summer only.
 * @see add_item()
 * @see add_summer_item()
 * @see add_summer_day_item()
 */
varargs void add_summer_night_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->add_night_item( shorts, desc, no_plural );
} /* add_summer_night_item() */

/**
 * This method adds an item to the room, that
 * is to be used during the autumn only.
 * @see add_item()
 * @see add_autumn_day_item()
 * @see add_autumn_night_item()
 */
varargs void add_autumn_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->add_item( shorts, desc, no_plural );
} /* add_autumn_item() */

/**
 * This method adds a day item into the room,
 * that is to be used during the autumn only.
 * @see add_item()
 * @see add_autumn_item()
 * @see add_autumn_night_item()
 */
varargs void add_autumn_day_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->add_day_item( shorts, desc, no_plural );
} /* add_autumn_day_item() */

/**
 * This method adds a night item into the room,
 * that is to be used during the autumn only.
 * @see add_item()
 * @see add_autumn_item()
 * @see add_autumn_day_item()
 */
varargs void add_autumn_night_item( mixed shorts, mixed desc, int no_plural ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->add_night_item( shorts, desc, no_plural );
} /* add_autumn_night_item() */

/**
 * This method adds chats to the room,
 * that are to be used only during the winter.
 * @see room_chat()
 * @see room_winter_day_chat()
 * @see room_winter_night_chat()
 */
varargs void room_winter_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->room_chat( args, chatobj );
} /* room_winter_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during winter days.
 * @see room_chat()
 * @see room_winter_chat()
 * @see room_winter_night_chat()
 */
varargs void room_winter_day_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->room_day_chat( args, chatobj );
} /* room_winter_day_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during winter nights.
 * @see room_chat()
 * @see room_winter_chat()
 * @see room_winter_day_chat()
 */
varargs void room_winter_night_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "winter" )
        TO->room_night_chat( args, chatobj );
} /* room_winter_night_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during the spring.
 * @see room_chat()
 * @see room_spring_day_chat()
 * @see room_spring_night_chat()
 */
varargs void room_spring_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->room_chat( args, chatobj );
} /* room_spring_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during spring days.
 * @see room_chat()
 * @see room_spring_chat()
 * @see room_spring_night_chat()
 */
varargs void room_spring_day_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->room_day_chat( args, chatobj );
} /* room_spring_day_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during spring nights.
 * @see room_chat()
 * @see room_spring_chat()
 * @see room_spring_day_chat()
 */
varargs void room_spring_night_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "spring" )
        TO->room_night_chat( args, chatobj );
} /* room_spring_night_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during the summer.
 * @see room_chat()
 * @see room_summer_day_chat()
 * @see room_summer_night_chat()
 */
varargs void room_summer_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->room_chat( args, chatobj );
} /* room_summer_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during summer days.
 * @see room_chat()
 * @see room_summer_chat()
 * @see room_summer_night_chat()
 */
varargs void room_summer_day_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->room_day_chat( args, chatobj );
} /* room_summer_day_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during summer nights.
 * @see room_chat()
 * @see room_summer_chat()
 * @see room_summer_day_chat()
 */
varargs void room_summer_night_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "summer" )
        TO->room_night_chat( args, chatobj );
} /* room_summer_night_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during the autumn.
 * @see room_chat()
 * @see room_autumn_day_chat()
 * @see room_autumn_night_chat()
 */
varargs void room_autumn_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->room_chat( args, chatobj );
} /* room_autumn_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during autumn days.
 * @see room_chat()
 * @see room_autumn_chat()
 * @see room_autumn_night_chat()
 */
varargs void room_autumn_day_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->room_day_chat( args, chatobj );
} /* room_autumn_day_chat() */

/**
 * This method adds chats to the room,
 * that are to be used only during autumn nights.
 * @see room_chat()
 * @see room_autumn_chat()
 * @see room_autumn_day_chat()
 */
varargs void room_autumn_night_chat( mixed args, object chatobj ) {
    if( WEATHER_H->query_season() == "autumn" )
        TO->room_night_chat( args, chatobj );
} /* room_autumn_night_chat() */
