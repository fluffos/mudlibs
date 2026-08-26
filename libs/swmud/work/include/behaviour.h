/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Define/undefine the clusters below that fit how you want your monsters on the MUD
** to act. Feel free to add your own.
*/

//Have relations to other beings
#define CLUSTER_ASSOCIATION

//Ability to move and navigate 
#define CLUSTER_NAVIGATION

//Ability to find, and replace equipment with better equipment
//Ability to use healing items in case of need.
#define CLUSTER_EQUIPMENT

//Ability to fight and flee
#undef CLUSTER_COMBAT

//The pause when handling a leaf node. Recommended between 2-5.
#define LEAF_NODE_PAUSE 2

/* Do not touch anything below this point*/

#define CLUSTERS "/std/behaviour/clusters/"
#define NODE_CLASS "/std/behaviour/node_class"

#ifndef __BEHAVIOR_H__
#define __BEHAVIOR_H__

#define EVAL_NONE -1
#define EVAL_SUCCESS 1
#define EVAL_RUNNING 2
#define EVAL_FAILURE 0

// Composite nodes
#define NODE_ROOT 1
#define NODE_SEQUENCE 2
#define NODE_SELECTOR 3

// Leaf
#define NODE_LEAF 5

// Decorator nodes
#define NODE_SUCCEEDER 10
#define NODE_INVERTER 11
#define NODE_REPEAT_UNTIL_FAIL 12

// Plutchik's Wheel of Emotions
// https://en.wikipedia.org/wiki/Robert_Plutchik
#define ECSTASY 0
#define ADMIRATION 1
#define TERROR 2
#define AMAZEMENT 3
#define GRIEF 4
#define LOATHING 5
#define RAGE 6
#define VIGILANCE 7
#define EMOTION_NAMES ([0:({"serenity","joy","ecstacy"}),\
                        1:({"acceptance","trust","admiration"}),\
                        2:({"apprehension","fear","terror"}),\
                        3:({"distraction","surprise","amazement"}),\
                        4:({"pensiveness","sadness","grief"}),\
                        5:({"boredom","disgust","loathing"}),\
                        6:({"annoyance","anger","rage"}),\
                        7:({"interest","anticipation","vigilance"})])

//Attitudes towards other
#define FRIENDLY 2
#define POSITIVE 1
#define INDIFFERENT 0
#define SUSPICIOUS -1
#define HOSTILE -2

#endif /* __BEHAVIOUR_H__ */