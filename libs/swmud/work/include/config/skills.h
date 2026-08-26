/* Do not remove the headers from this file! see /USAGE for more info. */

// Automatically generated file, do not edit by hand. Use admtool.
#ifndef __SKILLS_H__
#define __SKILLS_H__

// Each skill will start at 0, and go to this number of points.
// Default: 10000
// Range: 5000-30000
// Type: integer
#define MAX_SKILL_VALUE 10000

// As a person's skill increases, the amount they learn decreases. A higher value here will mean quicker ranks at first.
// Default: 10
// Range: 3-20
// Type: integer
#define LEARNING_FACTOR 10

// The max amount of points that can be gained for learning.
// Default: 10
// Range: 10-50
// Type: integer
#define TRAINING_FACTOR 10

// The skill points learned move up the tree, divided by this number.
// Default: 2
// Range: 2-10
// Type: integer
#define PROPAGATION_FACTOR 2

// A skill value is an aggregate of all the parents. 1/N^i of parent skills aggregate into the specified skill
// Default: 3
// Range: 2-5
// Type: integer
#define AGGREGATION_FACTOR 3

// Points learned by N on failure
// Default: 1
// Range: 1-5
// Type: integer
#define SKILL_ON_FAILURE 1

// Minimum to learn on a win
// Default: 2
// Range: 2-5
// Type: integer
#define SKILL_MIN_ON_WIN 2

// Maximum points to learn on a win
// Default: 20
// Range: 10-30
// Type: integer
#define SKILL_MAX_ON_WIN 20

// Do we use training points or not
// Default: yes
// Type: boolean
#define SKILL_CONFIG_USES_TRAINING_PTS

// Use roman numerals for skill ranks - no means plain numbers.
// Default: yes
// Type: boolean
#define USE_ROMAN_NUMERALS

#endif /* __SKILLS_H__ */
