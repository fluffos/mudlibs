/**
 * This contains all the defines for the options command and the options
 * handler.
 * @author Pinkfish
 * @started Thu Jun  8 17:59:30 PDT 2000 
 */
#ifndef __CMDS_OPTIONS_H
/** @ignore yes */
#define __CMDS_OPTIONS_H

/** An integer type. */
#define OPTIONS_TYPE_INTEGER  1
/** A string type. */
#define OPTIONS_TYPE_STRING   2
/** A boolean type. */
#define OPTIONS_TYPE_BOOLEAN  3
/** A brief/verbose type. */
#define OPTIONS_TYPE_BRIEF    4
/** A colour type. */
#define OPTIONS_TYPE_COLOUR   5
/** A dynamic group option.  This will expand out to a bunch more options. */
#define OPTIONS_TYPE_DYNAMIC_GROUP 6
/** A percentage type. */
#define OPTIONS_TYPE_PERCENTAGE 7
/** A terminal type. */
#define OPTIONS_TYPE_TERMINAL   8

/**
 * This is the path to the option handler.
 */
#define OPTION_HANDLER "/handlers/options_handler"

#endif
