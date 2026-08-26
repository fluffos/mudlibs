/**
 * The header file for use with the gossip effects.
 * @author Pinkfish
 * @see /handlers/gossip_handler.c
 * @see /std/shadows/npc/gossip.c
 */

#ifndef __GOSSIP_H
/** @ignore yes */
#define __GOSSIP_H

/**
 * This class stores the gossip data.
 * @member who who said the gossip
 * @member what what was said
 */
class gossip_data {
    string who;
    string what;
}

/**
 * The path of the gossip handler.
 * The handler keep tracks of the saved gossip.
 * @see /handlers/gossip_handler.c
 */
#define GOSSIP_H "/handlers/gossip_handler"

/** The time between accepting new gossip. */
#define GOSSIP_FREQUENCY  43200

/** The number of gossip message to save. */
#define GOSSIP_KEEP_LEVEL 60

/** The number of rumour messages to save */
#define RUMOUR_KEEP_LEVEL 20

/** Where to save the gossip information. */
#define GOSSIP_SAVE_FILE  SAVE_DIR "/gossip"

#endif
