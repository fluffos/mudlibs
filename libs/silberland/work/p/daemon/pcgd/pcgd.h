#ifndef _H_PCGD_
#define _H_PCGD_

#define PCGD_HOME "/p/daemon/pcgd/"
#define PCGD PCGD_HOME "pcgd"

#define PCG_R_BIOME_INVALID_DIR -1
#define PCG_R_MISSING_ARGS      -2
#define PCG_R_OK                 1

// options when calling the Procedural Content Generation
#define PCG_EACH_BUCKET_ONE       1 // when using buckets, select items from one bucket after the next
#define PCG_SELECT_RANDOM         2 // randomly select items (e.g. from a random bucket)
#define PCG_CONTENT_NO_SUCCESSION 4 // prevents the same content to be generated twice in a row
#define PCG_CONTENT_ONLY_ONCE     8 // every piece of content will only be used once, includey CONTENT_NO_SUCCESSION)
                                    // !! CAUTION: if there fewer total pieces of contant available than the generation
                                    // !! legth, this will in a "too long evaluation" because of an endless loop created

#define PCG_LAYOUT_LINEAR           1
#define PCG_LAYOUT_BIVARIANT_LINEAR 2

#define PCG_L_EXITS "exits"
#define PCG_L_TYPE  "type"

#define PCG_EXIT_NORTH 1
#define PCG_EXIT_EAST  2
#define PCG_EXIT_SOUTH 4
#define PCG_EXIT_WEST  8

#define MAP_NODE_START "__start__"
#define MAP_NODE_UNDEF "__undef__"
#define MAP_NODE_END   "__end__"
#define MAP_NODE_UNUSED "__unused__"

#define MAX_CYCLIC_MAP_DEPTH 5

#endif