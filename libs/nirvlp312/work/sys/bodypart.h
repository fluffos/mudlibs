#ifndef _BODYPART_H
#define _BODYPART_H

/* change this to "" somewhen */
#define NEW_PREFIX    "new_"

#define P_BODY                  "body"
#define P_BODYPART              "bodypart"

#define BASIC_DIR               "basic/"
#define COMPLEX_DIR             "complex/"

#define BODY_OF(x)              ((x)->query_body() || (x))

/* First, the basic classes */
#define BASIC_BODYPART          BASIC_DIR "bodypart"
#define BASIC_COMPOUND_BODYPART BASIC_DIR "compound_bodypart"
#define BASIC_BODYPART_COMPOUND BASIC_DIR "bodypart_compound"
#define BASIC_WOUND             BASIC_DIR "wound"

/* Now, the complex classes (and directories) */
#define BODYPART                COMPLEX_DIR "bodypart"
#define BODY                    COMPLEX_DIR "body"
#define WOUND                   COMPLEX_DIR "wound"

#define BODYPART_DIR            BODYPART "/"
#define BODY_DIR                BODY "/"

/* here come bodypart-connections */

/* for humanoid bodies */
#define BPC_NECK                "neck"
#define BPC_SHOULDER            "shoulder"
#define BPC_LEFT_SHOULDER       "left shoulder"
#define BPC_RIGHT_SHOULDER      "right shoulder"
#define BPC_RIGHT_SHOULDERBLADE "right shoulderblade"
#define BPC_LEFT_SHOULDERBLADE  "left shoulderblade"
#define BPC_WRIST               "wrist"
#define BPC_WAIST               "waist"
#define BPC_HIP                 "hip"
#define BPC_ANKLE               "ankle"
#define BPC_FOREHEAD            "forehead"

/* additional ones for mammale */
#define BPC_FRONT               "front"
#define BPC_REAR_HIP            "rear hip"
#define BPC_MIDDLE              "middle"
#define BPC_BEHIND              "behind"
#define BPC_TAIL                "tail"

/* some connections octapods */
#define BPC_LEFT_FORE_TRACHEUS
#define BPC_RIGHT_FORE_TRACHEUS
#define BPC_LEFT_MIDFORE_TRACHEUS
#define BPC_RIGHT_MIDFORE_TRACHEUS
#define BPC_LEFT_MIDHIND_TRACHEUS
#define BPC_RIGHT_MIDHIND_TRACHEUS
#define BPC_LEFT_HIND_TRACHEUS
#define BPC_RIGHT_HIND_TRACHEUS

/* the next ones are not used, yet */
#define BPC_ELBOW               "elbow"
#define BPC_KNEE                "knee"

/* Now for some bodypart-data-types */
#define BT_SIZE                 "size"
#define BT_GRIP_SIZE            "grip_size"
#define BT_HEALTH               "health"
#define BT_TOUGHNESS            "toughness"
#define BT_COMPOUND             "compound"
#define BT_WORN                 "worn"
#define BT_HELD                 "held"
#define BT_WOUNDS               "wounds"

/* notify_reasons */
#define BP_DEACTIVATED          "deactivated"
#define BP_ACTIVATED            "activated"
#define BP_FREED                "freed"

#define G_POSITION              "<corelib#position>"
#define G_TOOL                  "<corelib#tool>"

#endif /* _BODYPART_H */

