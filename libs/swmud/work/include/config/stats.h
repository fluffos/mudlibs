/* Do not remove the headers from this file! see /USAGE for more info. */

// Automatically generated file, do not edit by hand. Use admtool.
#ifndef __STATS_H__
#define __STATS_H__

// Base value of score for all races. See 'admtool i r' for race info.
// Default: 20
// Range: 10-30
// Type integer
#define STAT_BASE_VALUE	20

// Cost for 1 stat increase at level 1.
// Default: 50 gold
// Type: string
#define STAT_TRAIN_COST "1 gold"

// Should we multiply stat increase cost by player level?
// Default: yes
// Type: boolean
#define STAT_TRAIN_SCALES_WITH_LEVEL

// Should an increase from 18 to 19 cost 19 * STAT_TRAIN_COST?
// Default: no
// Type: boolean
#define STAT_TRAIN_SCALES_WITH_STAT

// Should we further multiply the train cost with level AND this factor?
// Default: 2
// Range: 1-10
// Type: integer
#define STAT_TRAIN_SCALE 2

// Stat points handed out for increase per level
// Default: 2
// Range: 0-5
// Type: integer
#define STAT_PTS_PER_LEVEL 3

#endif